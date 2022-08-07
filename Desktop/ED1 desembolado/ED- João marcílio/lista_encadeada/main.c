/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Aluno
 *
 * Created on 30 de Maio de 2022, 16:12
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct noLista{
    int info;
    struct NoLista *prox;
}NoLista;
/*
 * 
 */

NoLista* criarLista(){
    return NULL;
    
}


void inserirElemento(NoLista **l, int v){
    NoLista  *novoNo;
    novoNo = (NoLista*)malloc(sizeof(NoLista));
    
    if(novoNo == NULL){
        //n -> info = v
        //p = *l;
    }
}

void imprimeLista(NoLista** l){
    if(!estaVazia(l)){
        NoLista *p;
    for(p = *l; p != NULL; p=p->prox)
        printf("%d ", p->info);
    printf("\n");
}

else
    printf("Lista vazia!\n");

}


NoLista* busca(NoLista ** l, int v){
    NoLista *p;
    for(p = *l; p!=NULL; p= p->prox){
        if(p -> info == v)
            return p;
    }
    return NULL;
}



void removerItem(NoLista **l,int v){
    NoLista *p, *ant = NULL;
    for(p =*l; p!=NULL && p->info != v; p = p->prox){
        ant = p;
    }
    if(ant == NULL)
        *l = p->prox;
    else{
        ant->prox = p->prox;
        
    }
    free(p);
}

int estaVazia(NoLista** l){
    return (*l==NULL);
}

void libera(NoLista **l, NoLista *temp){
    if(!estaVazia(l)){
        for(NoLista *p = *l; p != NULL; p = temp){
            temp= p->prox;
            free(p);
        }
    }
    *l = NULL;
}

void insereOrdenado(NoLista **l, int v){
    NoLista *p, *ant = NULL;
    NoLista *n = (NoLista*)malloc(sizeof(NoLista));
    if(n!= NULL){
        n->info = v;
        p = *l;
    }
    while(p!= NULL && p->info < v){
        ant = p;
        p = p->prox;
    }
    if(ant == NULL){ // Insere no início
        n->prox = p;
        *l = n;
    }
    else{
        ant -> prox = n;
        n->prox = p;
    }
            
}

int quantidadeElementos(NoLista **l){
    int cont = 0;
    
    if(!estaVazia(l)){
        for(NoLista *p = *l; p!=NULL; p = p -> prox){
            cont ++;
        }
        return cont;
    }
    else
        return cont;
}

NoLista* ultimo(NoLista **l){
    if(!estaVazia(l)){
        for(NoLista *p = *l; p!=NULL; p = p->prox){ // ou jeito 2: for(noLista *p = *l; p->prox !=null; p = p->prox)
            if(p->prox == NULL)                     //               return p;
                return p;
        }
    }
    return NULL;
}

int main(int argc, char** argv) {
    NoLista lista;
    int x;
    
    criarLista();
    //inserirElemento(&lista, 2);
    insereOrdenado(&lista, 2);
    insereOrdenado(&lista, 4);
    insereOrdenado(&lista, 6);
    insereOrdenado(&lista, 8);
    insereOrdenado(&lista, 10);
    
    imprimeLista(&lista);
    
    
    printf("%d\n",quantidadeElementos(&lista));
    //printf("%p", busca(&lista, 2));

    return (EXIT_SUCCESS);
}

