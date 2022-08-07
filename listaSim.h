#include <stdlib.h>
#define typeDado int

typedef struct no{
	typeDado *dado;
    struct no *prox;
}listaSimples;

listaSimples * criaListaSim();

void liberaListaSim(listaSimples *ls);

int listaSimpVazia(typeDado *a);

listaSimples * criaListaSim();

void inserirListaSim(listaSimples** ls, typeDado *dado);

void removerListaSim(listaSimples** ls, typeDado *dado);
