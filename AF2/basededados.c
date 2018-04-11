#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "basededados.h"

// Inserir um novo aluno na BD
Alunos *inserirAluno(Alunos *listaAlunos, Alunos *aluno)
{
    Alunos *novoAluno=(Alunos *)malloc(sizeof(Alunos));
    if (novoAluno!=NULL)
    {
        novoAluno->numero=aluno->numero;
        strcpy(novoAluno->nome, aluno->nome);
        strcpy(novoAluno->pais, aluno->pais);
        novoAluno->seguinte=listaAlunos;
        return novoAluno;
    }
    return listaAlunos;
}

// Inserir alunos do ficheiro na lista
Alunos *criarListaAlunos(Alunos *listaAlunos, char *linha)
{
    char *aux;
    Alunos *novoAluno=(Alunos *)malloc(sizeof(Alunos));
    
    aux = strtok (linha, ";");
    novoAluno->numero=atoi(aux);
    aux=strtok(NULL, ";");
    strcpy(novoAluno->nome, aux);
    aux=strtok(NULL, ";");
    strcpy(novoAluno->pais, aux);
    aux=strtok(NULL, ";");
    
    listaAlunos=mostrarAlunos(listaAlunos, novoAluno);

    return listaAlunos;
}

// Ler lista de alunos existentes na BD através do ficheiro alunos.txt
Alunos *lerFicheiroAluno(Alunos *listaAlunos, char *nomeFicheiro)
{   
    char linha[MAX];
    
    FILE *fAlunos=fopen(nomeFicheiro, "r");

    if (fAlunos!=NULL)
    {
        printf("\n-- Alunos inseridos no ficheiro '%s' --\n", nomeFicheiro);
        while (!feof(fAlunos))
        {
            fgets(linha, MAX, fAlunos);
            if (strlen(linha)>2)
                criarListaAlunos(listaAlunos, linha);    
        }
    }
    else
        printf("Erro ao abrir o ficheiro");
    return listaAlunos;
    fclose(fAlunos);
    libertarListaAlunos(listaAlunos);
}

// Mostrar alunos existentes na BD
Alunos *mostrarAlunos(Alunos *listaAlunos, Alunos *aluno)
{
    if (aluno!=NULL)
    {
        printf("\n");
        printf("» Número: %d\n", aluno->numero);
        printf("» Nome: %s\n", aluno->nome);
        printf("» País: %s\n", aluno->pais);
    }
    return listaAlunos;
}

// Libertar lista de alunos
void *libertarListaAlunos(Alunos *listaAlunos)
{
    Alunos *aux;

    while (listaAlunos!=NULL)
    {
        aux=listaAlunos->seguinte;
        free(listaAlunos);
        listaAlunos=aux;
    }
    return NULL;
}

// Inserir uma nova Unidade Curricular na BD
UnidadesCurriculares *inserirUC(UnidadesCurriculares *listaUC, UnidadesCurriculares *uc)
{
    UnidadesCurriculares *novaUC=(UnidadesCurriculares *)malloc(sizeof(UnidadesCurriculares));
    if (novaUC!=NULL)
    {
        novaUC->numero=uc->numero;
        strcpy(novaUC->nome, uc->nome);
        novaUC->ano=uc->ano;
        novaUC->semestre=uc->semestre;
        novaUC->seguinte=listaUC;
        return novaUC;
    }
    return listaUC;
}

// Mostrar Unidades Curriculares existentes na BD
UnidadesCurriculares *mostrarUC(UnidadesCurriculares *listaUC)
{
    printf("\nUnidades Curriculares inseridas:\n");
    while (listaUC!=NULL)
    {
        printf("Número: %d; Nome: %s; Ano: %d; Semestre: %d;\n", listaUC->numero, listaUC->nome, listaUC->ano, listaUC->semestre);
        listaUC=listaUC->seguinte;
    }
}

// Libertar lista de Unidades Curriculares
void *libertarListaUC(UnidadesCurriculares *listaUC)
{
    UnidadesCurriculares *aux;

    while (listaUC!=NULL)
    {
        aux=listaUC->seguinte;
        free(listaUC);
        listaUC=aux;
    }
    return NULL;
}

// Inserir uma nova Inscrição na BD
Inscricoes *inserirInscricao(Inscricoes *listaInscricoes, Inscricoes *inscricao)
{
    Inscricoes *novaInscricao=(Inscricoes *)malloc(sizeof(Inscricoes));
    if (novaInscricao!=NULL)
    {
        novaInscricao->numeroAluno=inscricao->numeroAluno;
        novaInscricao->numeroUC=inscricao->numeroUC;
        novaInscricao->ano=inscricao->ano;
        novaInscricao->seguinte=listaInscricoes;
        return novaInscricao;
    }
    return listaInscricoes;
}

// Mostrar Inscrições existentes na BD
Inscricoes *mostrarInscricao(Inscricoes *listaInscricoes)
{
    printf("\nInscrições inseridas:\n");
    while (listaInscricoes!=NULL)
    {
        printf("Número Aluno: %d; Número UC: %d; Ano: %d;\n", listaInscricoes->numeroAluno, listaInscricoes->numeroUC, listaInscricoes->ano);
        listaInscricoes=listaInscricoes->seguinte;
    }
}

// Libertar lista de Inscrições
void *libertarListaInscricao(Inscricoes *listaInscricoes)
{
    Inscricoes *aux;

    while (listaInscricoes!=NULL)
    {
        aux=listaInscricoes->seguinte;
        free(listaInscricoes);
        listaInscricoes=aux;
    }
    return NULL;
}