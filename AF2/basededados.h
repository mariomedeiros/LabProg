#ifndef BASEDEDADOS_H
#define BASEDEDADOS_H
#define MAX 100 // tamanho máximo para string

// ----- # estruturas -----

typedef struct sAlunos
{
    int numero;
    char nome[MAX];
    char pais[MAX];
    struct sAlunos *seguinte;
} Alunos;

typedef struct sUnidadesCurriculares
{
    int numero;
    char nome[MAX];
    int ano;
    int semestre;
    struct sUnidadesCurriculares *seguinte;
} UnidadesCurriculares;

typedef struct sInscricoes
{
    int numeroAluno;
    int numeroUC;
    int ano;
    struct sInscricoes *seguinte;
} Inscricoes;

// ----- # -----

// ----- # declaração das funções -----

// funções para alunos
Alunos *criarListaAlunos(Alunos *listaAlunos, char *linha);
Alunos *mostrarAlunos(Alunos *listaAlunos, Alunos *aluno);
Alunos *lerFicheiroAluno(Alunos *listaAlunos, char *nomeFicheiro);
Alunos *inserirAluno(Alunos *listaAlunos, Alunos *aluno);
void *libertarListaAlunos(Alunos *listaAlunos);

// funções para unidades curriculares
UnidadesCurriculares *inserirUC(UnidadesCurriculares *listaUC, UnidadesCurriculares *uc);
UnidadesCurriculares *criarListaUC(UnidadesCurriculares *listaUC, char *linha);
UnidadesCurriculares *lerFicheiroUC(UnidadesCurriculares *listaUC, char *nomeFicheiro);
UnidadesCurriculares *mostrarUC(UnidadesCurriculares *listaUC, UnidadesCurriculares *uc);
void *libertarListaUC(UnidadesCurriculares *listaUC);

// funções para inscrições
Inscricoes *inserirInscricao(Inscricoes *listaInscricoes, Inscricoes *inscricao);
Inscricoes *criarListaInscricao(Inscricoes *listaInscricoes, char *linha);
Inscricoes *lerFicheiroInscricao(Inscricoes *listaInscricoes, char *nomeFicheiro);
Inscricoes *mostrarInscricoes(Inscricoes *listaInscricoes, Inscricoes *inscricao);
void *libertarListaInscricao(Inscricoes *listaInscricoes);

// ----- # -----

#endif