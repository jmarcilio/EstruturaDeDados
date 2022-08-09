#include<stdio.h>
#include "listaSim.h"

typedef struct no{
	typeDado *dado;
    struct no *prox;
}listaSimples;

listaSimples * criaListaSim(){
    return NULL;
}

int estaVazia(typeDado **a){
    return(*a == NULL);
}

void inserir(listaSimples** ls, typeDado *dado){
    listaSimples * no = malloc(sizeof(listaSimples));
    if(no != NULL){
        no -> dado = dado;
        no ->prox = *ls;
        *ls = no;
    }else{
        printf("Não foi possivel alocar espaço!");
    }
}

void removerElemento(listaSimples **ls, typeDado * dado){
    listaSimples * aux, * ant = NULL;
    for( aux = *ls ; aux!=NULL && aux -> dado!= dado ; aux = aux -> prox ){
        	ant = aux;
        }
	if(ant == NULL){
     		*ls = aux -> prox;
            
        }else{
     		ant -> prox = aux -> prox;
        }
	free(aux);
}

void imprimeLista(listaSimples** ls){
    if(!estaVazia(ls)){
        listaSimples * aux;
        for(aux = *ls ; aux != NULL ; aux = aux -> prox){
             printf("%s\n", aux -> dado);
        }
    }else{
        printf("Não foi possivel imprimir a lista de amigos!");
    }
}

void liberaLista(listaSimples **ls){
    listaSimples * aux;
    if( *ls != NULL){
        for(aux = *ls; aux != NULL ; aux = aux ->prox){
            removerElemento(*ls, aux -> dado);
        }
        *ls = aux;
        free(ls);

    }else{
        printf("Erro ao liberar lista!");
    }
}