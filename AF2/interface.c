#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "interface.h"
#include "basededados.h"

// ----- # declaração das variáveis globais -----

Alunos *listaAlunos;
Alunos aluno;
UnidadesCurriculares *listaUC;
UnidadesCurriculares uc;
Inscricoes *listaInscricoes;
Inscricoes inscricao;

// ----- # -----

// ----- # funções para interfaces -----

// ----- funções interface principal -----
void interfacePrincipal()
{
    int opSubMenu;
    do
    {
        printf("\n»» Gestão de alunos, unidades curriculares e inscrições\n\n");
        printf("1 > Alunos\n");
        printf("2 > Unidades Curriculares\n");
        printf("3 > Inscrições\n");
        printf("0 > Sair\n");
        printf("\nOpção: ");
        scanf("%d", &opSubMenu);
        switch (opSubMenu)
        {
            case 1:
                interfaceAlunos();
                break;
            case 2:
                interfaceUC();
                break;
            case 3:
                interfaceInscricoes();
                break;
            case 0:
                break;
            default:
                printf("\nOpção Inválida. Escolha outra opção\n");
        }
    } while (opSubMenu>0);
}

// ----- funções interface principal dos alunos -----
void interfaceAlunos()
{
    int op;
    do
    {
        printf("\n»» Gestão de alunos\n\n");
        printf("1 > Consultar lista de alunos\n");
        printf("2 > Inserir novo aluno\n");
        printf("3 > Alterar aluno\n");
        printf("4 > Apagar aluno\n");
        printf("9 > Voltar ao menu anterior\n");
        printf("0 > Sair\n");
        printf("\nOpção: ");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                listaAlunos = lerFicheiroAluno(listaAlunos, "alunos.txt");
                break;
            case 2:
                interfaceInserirNovoAluno();
                break;
            case 3:
                break;
            case 4:
                break;
            case 9:
                interfacePrincipal();
                break;
            case 0:
                break;
            default:
                printf("\nOpção Inválida. Escolha outra opção\n");
        }
    } while (op>0);
}

// ----- funções interface inserir novos alunos -----
void interfaceInserirNovoAluno()
{
    printf("\nNúmero de estudante: ");
    scanf("%d", &aluno.numero);
    printf("Nome (primeiro e último): ");
    scanf("%s", aluno.nome);
    printf("País de residência: ");
    scanf("%s", aluno.pais);

    FILE *fAlunos=fopen("alunos.txt", "a");
    listaAlunos = inserirAluno(listaAlunos, &aluno);
    fprintf(fAlunos, "%d;%s;%s;\n", aluno.numero, aluno.nome, aluno.pais);
    fclose(fAlunos);
    printf("\nNovo aluno inserido.\n");
}

// ----- funções interface principal das unidades curriculares -----
void interfaceUC()
{
    int op;
    do
    {
        printf("\n»» Gestão de Unidades Curriculares\n\n");
        printf("1 > Consultar lista de Unidades Curriculares\n");
        printf("2 > Inserir nova Unidade Curricular\n");
        printf("3 > Alterar Unidade Curricular\n");
        printf("4 > Apagar UNidade Curricular\n");
        printf("9 > Voltar ao menu anterior\n");
        printf("0 > Sair\n");
        printf("\nOpção: ");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                listaUC = lerFicheiroUC(listaUC, "uc.txt");
                break;
            case 2:
                interfaceInserirNovaUC();
                break;
            case 3:
                break;
            case 4:
                break;
            case 9:
                interfacePrincipal();
                break;
            case 0:
                break;
            default:
                printf("\nOpção Inválida. Escolha outra opção\n");
        }
    } while (op>0);
}

// ----- funções interface inserir novas unidades curriculares -----
void interfaceInserirNovaUC()
{
    printf("\nNúmero da Unidade Curricular: ");
    scanf("%d", &uc.numero);
    printf("Nome da Unidade Curricular: ");
    scanf("%s", uc.nome);
    printf("Ano: ");
    scanf("%d", &uc.ano);
    printf("Semestre: ");
    scanf("%d", &uc.semestre);

    FILE *fUC=fopen("uc.txt", "a");
    listaUC = inserirUC(listaUC, &uc);
    fprintf(fUC, "%d;%s;%d;%d;\n", uc.numero, uc.nome, uc.ano, uc.semestre);
    fclose(fUC);
    printf("\nNova Unidade Curricular inserida.\n");
}

// ----- funções interface principal das inscrições -----
void interfaceInscricoes()
{
    int op;
    do
    {
        printf("\n»» Gestão de inscrições\n\n");
        printf("1 > Consultar lista de inscrições\n");
        printf("2 > Inserir nova inscrição\n");
        printf("3 > Alterar inscrição\n");
        printf("4 > Apagar inscrição\n");
        printf("9 > Voltar ao menu anterior\n");
        printf("0 > Sair\n");
        printf("\nOpção: ");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                listaInscricoes = lerFicheiroInscricao(listaInscricoes, "inscricoes.txt");
                break;
            case 2:
                interfaceInserirNovaInscricao();
                break;
            case 3:
                break;
            case 4:
                break;
            case 9:
                interfacePrincipal();
                break;
            case 0:
                break;
            default:
                printf("\nOpção Inválida. Escolha outra opção\n");
        }
    } while (op>0);
}

// ----- funções interface inserir novas inscrições -----
void interfaceInserirNovaInscricao()
{
    printf("\nNúmero de aluno: ");
    scanf("%d", &inscricao.numeroAluno);
    printf("Nome da Unidade Curricular: ");
    scanf("%d", &inscricao.numeroUC);
    printf("Ano: ");
    scanf("%d", &inscricao.ano);

    FILE *fInscricoes=fopen("inscricoes.txt", "a");
    listaInscricoes = inserirInscricao(listaInscricoes, &inscricao);
    fprintf(fInscricoes, "%d;%d;%d;\n", inscricao.numeroAluno, inscricao.numeroAluno, inscricao.ano);
    fclose(fInscricoes);
    printf("\nNova inscrição inserida.\n");
}

// ----- # -----