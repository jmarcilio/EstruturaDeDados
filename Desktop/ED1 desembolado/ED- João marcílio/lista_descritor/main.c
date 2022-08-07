/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Aluno
 *
 * Created on 31 de Maio de 2022, 16:45
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

//Lista com descritor - agora o que representa a minha lista é um descritor e não mais um ponteiro 
//prim = ponteiro pro primeiro nó ; n = número de elementos da lista; ult= ponteiro pro ultimo no
// campos info e prox

typedef struct no{
    int info;
    struct no* prox;
}NoLista;

typedef struct descritor{
    NoLista *prim, *ult;
    int n;
}Descritor;

void criarLista(Descritor *l){ // cria lista vazia - agora o que representa a minha lista é um descritor e não mais um ponteiro  por isso é só *l
    l->prim = NULL; // ou  l->prim = l->ult = NULL pois no C a atribuição começa da direita pra esquerda
    l->ult = NULL;
    l->n = 0;
}

int estaVazia(Descritor *l){
    return l->n == 0;
    
    
        
}

void insereInicio(Descritor *l, int v){ // aloca espaco, preenche o campo info e prox, e aloca na lista
    
    NoLista *n = (NoLista*)malloc(sizeof(NoLista));
    if(n!= NULL){
        n->info = v;
        n->prox = l->prim;
        l->prim = n;
        
        if(estaVazia(l))
            l->ult = n;
        
    
        l->n ++;
    }
        else
            printf("Não foi possível alocar espaço.");
}

void insereFim(Descritor *l, int v){
    NoLista *n = (NoLista*)malloc(sizeof(NoLista));
    if(n!= NULL){
        n->info = v;
        n->prox = NULL;
        
        if(estaVazia(l))
            l->prim = n;
        else
            l->ult->prox = n;
        l->ult = n;
        l ->n++;
    }
    else
        printf("Não foi possível alocar espaço.");
}
void imprimeLista(Descritor *l){
    if(!estaVazia(l)){
        for(NoLista *p = l->prim; p != NULL; p = p->prox){
            printf("%d ", p->info);
            
        }
        printf("\n");
    
    }
    else
        printf("A lista está vazia!\n");
}

void libera(Descritor *l){
    NoLista *temp;
    for(NoLista *p = l->prim; p !=NULL; p = temp){
        temp = p->prox;
        free(p);
        
    }
    l->prim = l->ult = NULL;
    l->n = 0;
}

void removerItem(Descritor *l, int v){
    NoLista *ant = NULL;
    NoLista *p;
    for(p = l->prim; p!=NULL && p->info !=v; p = p->prox)
        ant = p;
        
        if(p==NULL)
            printf("Elemento não encontrado"); 
        else{
            if(ant==NULL)
                l->prim = p->prox;
             
            if(l->prim == NULL)   
                l->ult = NULL; 
            else{
                if(p==l->ult)
                    l->ult = ant;
                ant->prox = p->prox;
            }
            free(p);
            l->n --;
        }
    
    }


int main(int argc, char** argv) {
    Descritor lista;
    criarLista(&lista);
    
    //insereInicio(&lista, 2);
    //insereInicio(&lista, 4);
    //insereInicio(&lista, 6);
    //insereInicio(&lista, 8);
    
   
    insereFim(&lista, 4);
    insereFim(&lista, 6);
    insereFim(&lista, 8);
    insereFim(&lista, 10);

    
    removerItem(&lista, 6);
    imprimeLista(&lista);
    
    libera(&lista);
    
    return (EXIT_SUCCESS);
}

