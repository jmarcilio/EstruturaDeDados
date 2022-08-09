#include "listaSim.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno Aluno;

Aluno *leAluno();

void alterarNome(Aluno* a);

void alterarCurso(Aluno* a);

char *retornaCurso(Aluno* a);

void imprimeAluno(Aluno* a);

void removeAluno(Aluno* a);

void liberaLista(listaSimples* ls);