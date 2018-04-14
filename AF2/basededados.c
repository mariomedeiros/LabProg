#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "basededados.h"

// ----- # funções para alunos -----

// ----- função para inserir um novo aluno na base de dados -----
Alunos *inserirAluno(Alunos *listaAlunos, Alunos *aluno)
{
    Alunos *novoAluno = (Alunos *)malloc(sizeof(Alunos));
    if (novoAluno != NULL)
    {
        novoAluno->numero = aluno->numero;
        strcpy(novoAluno->nome, aluno->nome);
        strcpy(novoAluno->pais, aluno->pais);
        novoAluno->seguinte = listaAlunos;
        return novoAluno;
    }
    return listaAlunos;
}

// ----- função para criar lista com alunos existentes no ficheiro -----
Alunos *criarListaAlunos(Alunos *listaAlunos, char *linha)
{
    char *aux;
    Alunos *novoAluno = (Alunos *)malloc(sizeof(Alunos));

    aux = strtok(linha, ";");
    novoAluno->numero = atoi(aux);
    aux = strtok(NULL, ";");
    strcpy(novoAluno->nome, aux);
    aux = strtok(NULL, ";");
    strcpy(novoAluno->pais, aux);
    aux = strtok(NULL, ";");

    listaAlunos = mostrarAlunos(listaAlunos, novoAluno);

    return listaAlunos;
}

// ----- função para ler lista de alunos existentes no ficheiro -----
Alunos *lerFicheiroAluno(Alunos *listaAlunos, char *nomeFicheiro)
{
    char linha[MAX];

    FILE *fAlunos = fopen(nomeFicheiro, "r");

    if (fAlunos != NULL)
    {
        printf("\n-- Alunos inseridos no ficheiro '%s' --\n", nomeFicheiro);
        while (!feof(fAlunos))
        {
            fgets(linha, MAX, fAlunos);
            if (strlen(linha) > 2)
                criarListaAlunos(listaAlunos, linha);
        }
    }
    else
        printf("Erro ao abrir o ficheiro");
    return listaAlunos;
    fclose(fAlunos);
    libertarListaAlunos(listaAlunos);
}

// ----- função para mostrar lista com alunos existentes no ficheiro -----
Alunos *mostrarAlunos(Alunos *listaAlunos, Alunos *aluno)
{

    if (aluno != NULL)
    {
        printf("\n> Numero  :  %d\n", aluno->numero);
        printf("> Nome    :  %s\n", aluno->nome);
        printf("> Pais    :  %s\n", aluno->pais);
    }
    return listaAlunos;
}

// ----- função para libertar memória criada para a lista de alunos -----
void *libertarListaAlunos(Alunos *listaAlunos)
{
    Alunos *aux;

    while (listaAlunos != NULL)
    {
        aux = listaAlunos->seguinte;
        free(listaAlunos);
        listaAlunos = aux;
    }
    return NULL;
}

// ----- # -----

// ----- # funções para unidades curriculares -----

// ----- função para inserir uma nova unidade curricular na base de dados -----
UnidadesCurriculares *inserirUC(UnidadesCurriculares *listaUC, UnidadesCurriculares *uc)
{
    UnidadesCurriculares *novaUC = (UnidadesCurriculares *)malloc(sizeof(UnidadesCurriculares));
    if (novaUC != NULL)
    {
        novaUC->numero = uc->numero;
        strcpy(novaUC->nome, uc->nome);
        novaUC->ano = uc->ano;
        novaUC->semestre = uc->semestre;
        novaUC->seguinte = listaUC;
        return novaUC;
    }
    return listaUC;
}

// ----- função para criar lista com unidades curriculares existentes no ficheiro -----
UnidadesCurriculares *criarListaUC(UnidadesCurriculares *listaUC, char *linha)
{
    char *aux;
    UnidadesCurriculares *novaUC = (UnidadesCurriculares *)malloc(sizeof(UnidadesCurriculares));

    aux = strtok(linha, ";");
    novaUC->numero = atoi(aux);
    aux = strtok(NULL, ";");
    strcpy(novaUC->nome, aux);
    aux = strtok(NULL, ";");
    novaUC->ano = atoi(aux);
    aux = strtok(NULL, ";");
    novaUC->semestre = atoi(aux);
    aux = strtok(NULL, ";");

    listaUC = mostrarUC(listaUC, novaUC);

    return listaUC;
}

// ----- função para ler lista de unidades curriculares existentes no ficheiro -----
UnidadesCurriculares *lerFicheiroUC(UnidadesCurriculares *listaUC, char *nomeFicheiro)
{
    char linha[MAX];

    FILE *fUC = fopen(nomeFicheiro, "r");

    if (fUC != NULL)
    {
        printf("\n-- Unidades Curriculares inseridas no ficheiro '%s' --\n", nomeFicheiro);
        while (!feof(fUC))
        {
            fgets(linha, MAX, fUC);
            if (strlen(linha) > 2)
                criarListaUC(listaUC, linha);
        }
    }
    else
        printf("Erro ao abrir o ficheiro");
    return listaUC;
    fclose(fUC);
    libertarListaUC(listaUC);
}

// ----- função para mostrar lista com unidades curriculares existentes no ficheiro -----
UnidadesCurriculares *mostrarUC(UnidadesCurriculares *listaUC, UnidadesCurriculares *uc)
{
    if (uc != NULL)
    {
        printf("\n");
        printf("> Numero    :  %d\n", uc->numero);
        printf("> Nome      :  %s\n", uc->nome);
        printf("> Ano       :  %d\n", uc->ano);
        printf("> Semestre  :  %d\n", uc->semestre);
    }
    return listaUC;
}

// ----- função para libertar memória criada para a lista de unidades curriculares -----
void *libertarListaUC(UnidadesCurriculares *listaUC)
{
    UnidadesCurriculares *aux;

    while (listaUC != NULL)
    {
        aux = listaUC->seguinte;
        free(listaUC);
        listaUC = aux;
    }
    return NULL;
}

// ----- # -----

// ----- # funções para inscrições -----

// ----- função para inserir uma nova inscrição na base de dados -----
Inscricoes *inserirInscricao(Inscricoes *listaInscricoes, Inscricoes *inscricao)
{
    Inscricoes *novaInscricao = (Inscricoes *)malloc(sizeof(Inscricoes));
    if (novaInscricao != NULL)
    {
        novaInscricao->numeroAluno = inscricao->numeroAluno;
        novaInscricao->numeroUC = inscricao->numeroUC;
        novaInscricao->ano = inscricao->ano;
        novaInscricao->seguinte = listaInscricoes;
        return novaInscricao;
    }
    return listaInscricoes;
}

// ----- função para criar lista com inscrições existentes no ficheiro -----
Inscricoes *criarListaInscricao(Inscricoes *listaInscricoes, char *linha)
{
    char *aux;
    Inscricoes *novaInscricao = (Inscricoes *)malloc(sizeof(Inscricoes));

    aux = strtok(linha, ";");
    novaInscricao->numeroAluno = atoi(aux);
    aux = strtok(NULL, ";");
    novaInscricao->numeroUC = atoi(aux);
    aux = strtok(NULL, ";");
    novaInscricao->ano = atoi(aux);
    aux = strtok(NULL, ";");

    listaInscricoes = mostrarInscricoes(listaInscricoes, novaInscricao);

    return listaInscricoes;
}

// ----- função para ler lista de inscrições existentes no ficheiro -----
Inscricoes *lerFicheiroInscricao(Inscricoes *listaInscricoes, char *nomeFicheiro)
{
    char linha[MAX];

    FILE *fInscricoes = fopen(nomeFicheiro, "r");

    if (fInscricoes != NULL)
    {
        printf("\n-- Unidades Curriculares inseridas no ficheiro '%s' --\n", nomeFicheiro);
        while (!feof(fInscricoes))
        {
            fgets(linha, MAX, fInscricoes);
            if (strlen(linha) > 2)
                criarListaInscricao(listaInscricoes, linha);
        }
    }
    else
        printf("Erro ao abrir o ficheiro");
    return listaInscricoes;
    fclose(fInscricoes);
    libertarListaInscricao(listaInscricoes);
}

// ----- função para mostrar lista com inscrições existentes no ficheiro -----
Inscricoes *mostrarInscricoes(Inscricoes *listaInscricoes, Inscricoes *inscricao)
{
    if (inscricao != NULL)
    {
        printf("\n");
        printf("> Numero aluno  :  %d\n", inscricao->numeroAluno);
        printf("> Numero UC     :  %d\n", inscricao->numeroUC);
        printf("> Ano           :  %d\n", inscricao->ano);
    }
    return listaInscricoes;
}

// ----- função para libertar memória criada para a lista de inscrições -----
void *libertarListaInscricao(Inscricoes *listaInscricoes)
{
    Inscricoes *aux;

    while (listaInscricoes != NULL)
    {
        aux = listaInscricoes->seguinte;
        free(listaInscricoes);
        listaInscricoes = aux;
    }
    return NULL;
}

// ----- # -----