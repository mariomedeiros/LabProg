#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "basededados.h"

int main()
{
    Alunos *listaAlunos=NULL;
    Alunos aluno;
    UnidadesCurriculares *listaUC=NULL;
    UnidadesCurriculares uc;
    Inscricoes *listaInscricoes=NULL;
    Inscricoes inscricao;
    char opcao;

    //listaAlunos = lerFicheiroAluno(listaAlunos, "alunos.txt");
    printf("\n");

    printf("Pretende inserir novo aluno? (s/n)\n");
    scanf("%c", &opcao);

    if (opcao=='s')
    {
        printf("Número: ");
        scanf("%d", &aluno.numero);
        printf("Nome: ");
        scanf("%s", aluno.nome);FILE *f=fopen("alunos.txt", "a");
        printf("País: ");
        scanf("%s", aluno.pais);

        FILE *f=fopen("alunos.txt", "a");
        listaAlunos = inserirAluno(listaAlunos, &aluno);
        fprintf(f, "%d;%s;%s;\n", aluno.numero, aluno.nome, aluno.pais);
        fclose(f);
        printf("\nNovo aluno inserido.\n");
        printf("\nDeseja ler novamente o ficheiro? (s/n)");
        scanf("%c", &opcao);

        if (opcao=='s')
            listaAlunos = lerFicheiroAluno(listaAlunos, "alunos.txt");
    }


    return 0;
}