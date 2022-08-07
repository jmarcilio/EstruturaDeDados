/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Aluno
 *
 * Created on 5 de Julho de 2022, 16:11
 */

#include <stdio.h>
#include <stdlib.h>
#define N 10
/*
 * 
 */
typedef struct fila{
    float info[N];
    int n;
    int inicio;
    
}Fila;

Fila* criarFila(){
    Fila *f = malloc(sizeof(Fila));
    f -> n = 0;
    f->inicio = 0;
    return f;
}

Fila* estaVazia(Fila* f){
    if(f->n == 0)
        return 1;
    else
        return 0;
}

Fila* estaCheia(Fila *f){
    if(f->n == N)
        return 1;
    else
        return 0;
}

void inserir(Fila *f, float v){
    if(!estaCheia(f)){
        int fim = (f->inicio + f->n) % N;
        f->info[fim] = v;
        f ->n++;
    }
    else{
        printf("Fila cheia");
    }
}

void imprimeFila(Fila *f){
    if(!estaVazia(f)){
        int x  = f->inicio;
        for(int i = 0; i<f->n; i++){
            printf("%.2f\n", f->info[x]);
            x  = (x+1) % N;
        }
    }
    else
        printf("Fila Vazia");
        
}

float remover(Fila *f){
    if(!estaVazia(f)){
        float v = f->info[f->inicio];
        f->n--;
        f->inicio = (f->inicio + 1) %N;
        return v;
    }
    else
        printf("Fila Vazia");
}

void liberarFila(Fila *f){
    free(f);
}
int main(int argc, char** argv) {
    Fila fila;
    
    criarFila();
    inserir(&fila, 5);
    inserir(&fila, 15);
    inserir(&fila, 25);
    inserir(&fila, 35);
    imprimeFila(&fila);
    remover(&fila);
    imprimeFila(&fila);
    liberarFila(&fila);
    return (EXIT_SUCCESS);
}

