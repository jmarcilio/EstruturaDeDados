#include "listaDupla.h"

typedef struct no{
	typeDado *dado;
    struct no *prox;
    struct no *ant;
}listaDupla;

listaDupla * criaListaDupla(){
    return NULL;
}

int listaDuplaVazia(listaDupla **ld){
    return(*ld == NULL);
}

void liberaListaDupla(listaDupla *ls){

}

void inserirListaDupla(listaDupla ** ld,  typeDado * a){
    listaDupla * l = malloc(sizeof(listaDupla));
    if(l != NULL){  
         l -> dado = a;
         l -> prox = *ld;
         l -> ant = NULL;
         *ld = l;
    }else{
        printf("Não foi possível inserir um novo aluno!");
    }
}

void removeListaDupla( listaDupla ** ld, typeDado * a ){
    listaDupla * l, *ant = NULL;
    for( l = *ld ; l != NULL && l -> dado != a ; l = l -> prox);

    if(l -> ant == NULL){
        *ld = l -> prox;
        (*ld)-> ant =  l -> ant;
    }else{
        l -> ant -> prox = l -> prox;
        l -> prox -> ant = l -> ant;
    }
    free(l);       
}

