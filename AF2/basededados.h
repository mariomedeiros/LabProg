#ifndef BASEDEDADOS_H
#define BASEDEDADOS_H
#define MAX 100

// Struct ALUNOS
typedef struct sAlunos
{
    int numero;
    char nome[MAX];
    char pais[MAX];
    struct sAlunos *seguinte;
} Alunos;

// Struct UNIDADES CURRICULARES
typedef struct sUnidadesCurriculares
{
    int numero;
    char nome[MAX];
    int ano;
    int semestre;
    struct sUnidadesCurriculares *seguinte;
} UnidadesCurriculares;

// Struct INSCRIÇÕES
typedef struct sInscricoes
{
    int numeroAluno;
    int numeroUC;
    int ano;
    struct sInscricoes *seguinte;
} Inscricoes;

// Declaração das funções do aluno
Alunos *criarListaAlunos(Alunos *listaAlunos, char *linha);
Alunos *mostrarAlunos(Alunos *listaAlunos, Alunos *aluno);
void *libertarListaAlunos(Alunos *listaAlunos);
Alunos *lerFicheiroAluno(Alunos *listaAlunos, char *nomeFicheiro);
Alunos *inserirAluno(Alunos *listaAlunos, Alunos *aluno);

// Declaração das funções da unidade curricular
UnidadesCurriculares *inserirUC(UnidadesCurriculares *listaUC, UnidadesCurriculares *uc);
UnidadesCurriculares *mostrarUC(UnidadesCurriculares *listaUC);
void *libertarListaUC(UnidadesCurriculares *listaUC);

// Declaração das funções da inscrição
Inscricoes *inserirInscricao(Inscricoes *listaInscricoes, Inscricoes *inscricao);
Inscricoes *mostrarInscricao(Inscricoes *listaInscricoes);
void *libertarListaInscricao(Inscricoes *listaInscricoes);

#endif