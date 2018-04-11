#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "interface.h"
#include "basededados.h"

Alunos *listaAlunos;
Alunos aluno;

// Interface para o menu
void interfacePrincipal()
{
    int opSubMenu;
    do
    {
        printf("\n»» Gestão de alunos, unidades curriculares e inscrições ««\n\n");
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
                //interfaceUC();
                break;
            case 3:
                //interfaceInscricoes();
                break;
            case 0:
                break;
            default:
                printf("\nOpção Inválida. Escolha outra opção\n");
        }
    } while (opSubMenu>0);
}

void interfaceAlunos()
{
    int op;
    do
    {
        printf("\n»» Gestão de alunos ««\n\n");
        printf("1 > Consultar lista de alunos\n");
        printf("2 > Interir novo aluno\n");
        printf("3 > Alterar aluno\n");
        printf("4 > Apagar aluno\n");
        printf("9 > Voltar ao menu anterior\n");
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
            case 0:
                break;
            default:
                printf("\nOpção Inválida. Escolha outra opção\n");
        }
    } while (op>0);
}

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