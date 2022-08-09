#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#define typeDado Aluno

typedef struct no listaDupla;

int listaDuplaVazia(listaDupla ** a);

listaDupla * criaListaDupla();

void liberaListaDupla(listaDupla *ls);

void inserirListaDupla(listaDupla ** ld, typeDado *dado);

void removeListaDupla(listaDupla** ld, typeDado *dado);