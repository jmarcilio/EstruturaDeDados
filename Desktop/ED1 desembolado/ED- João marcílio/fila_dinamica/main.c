/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Aluno
 *
 * Created on 11 de Julho de 2022, 16:11
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct nolista{
    float info;
    struct nolista* prox;
}NoLista;

typedef struct fila{
    NoLista *ini;
    NoLista *fim;
}Fila;


Fila* criarFila(){
    Fila * f = malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
    
}

int estaVazia(Fila *f){
    return(f->ini == NULL);
}

void inserir(Fila* f, float v){
    NoLista *n = malloc(sizeof(NoLista));
    
    if(n != NULL){
        n->info = v;
        n->prox = NULL;
        
        if(!estaVazia(f)){
            f->ini = n;
            f->fim = n;
        }
        else{
            f->fim->prox = n;
            f->fim = n;
                   
        }
    }
    else{
        printf("Não foi possivel alocar espaço.");
        exit(1);
    }
}

void imprimeFila(Fila* f){
    if(!estaVazia(f)){
        for(NoLista* p = f->ini; p!=NULL; p= p->prox){
            printf("%.2f\n", p->info);
        }
    }else{
        printf("Fila Vazia");
    }
}

float remover(Fila *f){
    if(!estaVazia(f)){
        NoLista *p = f->ini;
        float v = p->info;
        f->ini = p->prox;
        if(f->ini == NULL)
            f->fim = NULL;
        free(p);
        return v;
        
    }
}

void liberarFila(Fila* f){
    if(!estaVazia(f)){
        NoLista *p, *temp;
        for(p = f->ini; p!=NULL; p = temp){
            temp = p->prox;
            free(p);
    }
        free(f);
}
}

int main(int argc, char** argv) {
    //Fila* fila;
    
    Fila* f = criarFila();
    inserir(&f, 5);
    inserir(&f, 15);
    inserir(&f, 25);
    imprimeFila(&f);
    liberarFila(&f);
    return (EXIT_SUCCESS);
}

