#include "listaSim.h"
#include <stdio.h>


int id = 1;

typedef struct aluno{
	int id;
	char nome[30];
    char curso[30];
	listaSimples *amigos;
}Aluno;


Aluno * leAluno();

void alterarNome(Aluno* a);

void alterarCurso(Aluno* a);

char* retornaCurso(Aluno* a);

void imprimeAluno(Aluno* a);

void removeAluno(Aluno* a);

void liberaLista( listaSimples * ls );

void insereAmigo(Aluno** a,typeDado *dado);
