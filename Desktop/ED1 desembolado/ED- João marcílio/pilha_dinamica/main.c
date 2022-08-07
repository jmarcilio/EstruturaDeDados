/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Aluno
 *
 * Created on 4 de Julho de 2022, 16:09
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct no{
    float info;
    struct no* prox;
}NoLista;

typedef struct pilha{
    NoLista* prim;
}Pilha;

Pilha* criapilha(){
    Pilha *p = malloc(sizeof(Pilha));
    
    p->prim = NULL;
    return p;
}

float estavazia(Pilha* p){
    return(p->prim == NULL);
}

void push(Pilha* p, float v){
    NoLista* n = malloc(sizeof(NoLista));
    
    if(n!=NULL){
        n->info = v;
        n-> prox = p->prim;
        p->prim = n;
        
        
    }else{
        printf("Não foi possivel alocar espaço.");
        exit(1);
    }
}

void imprimePilha(Pilha* p){
    if(!estavazia(p)){
        NoLista *x;
        for(x = p->prim; x!=NULL; x=x->prox)
            printf("%.2f\n", x->info);
}

else
    printf("Pilha vazia!\n");

}

float pop(Pilha *p){
    if(!estavazia(p)){
        NoLista *x = p->prim;
        float v = x->info;
        p->prim = x->prox;
        free(x);
        return v;
    }
    else{
        printf("Pilha vazia");
        exit(1);
    }
}

void libera(Pilha *p){
    if(!estavazia(p)){
        NoLista *x, *temp;
        for(x = p->prim; x!=NULL; x=temp){
            temp = x->prox;
            free(x);
            
        }
        free(p);
        // fdazer na main : p = criapilha;
    }
}

int main(int argc, char** argv) {
    Pilha pilha;
    Pilha *p = criapilha();
    push(&pilha, 5);
    push(&pilha, 15);
    push(&pilha, 25);
    
    imprimePilha(&pilha);
    return (EXIT_SUCCESS);
}

