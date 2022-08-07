#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *prox;
}NoLista;

typedef struct lista{
    NoLista *head;
    NoLista *tail;

}Lista;

void criarLista(Lista *l){
    l->head = malloc(sizeof(NoLista));
    l->tail = malloc(sizeof(NoLista));;
    
    l->head->prox = l->tail;
    l->tail->prox = NULL;
    
}

int estaVazia(Lista *l){
        return l->head ->prox = l->tail;
}

void insereInicio(Lista *l, int v){
    NoLista *n = (NoLista*)malloc(sizeof(NoLista));
    if(n != NULL){
        n->info = v;
        l->head = n;
        l->tail = n->prox;
    
        if(estaVazia(l))
            l->head = l->tail = n;
        
        n ++;
    }else
        printf("Não foi possível alocar espaço.");
    
}

void inserirFinal(Lista *l, int v){

}

void imprimeLista(Lista *l){
    if(!estaVazia(l)){
        
    }
}

void removeElemento(Lista *l, int v){

}

void libera(Lista *l){

}
int main(int argc, char** argv) {
    Lista lista;
    
    criarLista(&lista);
    insereInicio(&lista, 12);
    imprimeLista(&lista);
}