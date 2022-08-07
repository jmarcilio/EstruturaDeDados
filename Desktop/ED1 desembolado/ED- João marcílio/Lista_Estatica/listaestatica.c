#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/*
 * 
 */
typedef struct lista{
    int itens[MAX];
    int n;
}Lista;

void criarLista(Lista *l){
    l -> n = 0;
}

int estaVazia(Lista *l){
    return (l -> n == 0);
    //Outro Jeito
    //if l -> n == 0
        //return 1;
    //else
        //return 0;
}

int estaCheia(Lista *l){
    return l -> n == MAX;
}

void insereItem(Lista *l, int v){
    if(!estaCheia(l)){ //como já estou dentro de uma funçao com ponteiro, então só usa l e não &l
        l -> itens[l->n] = v; // ou l -> itens[l->n++]
        l -> n++;
    }
    else{
        printf("A lista está cheia!");
    }
    //ou
    //if(estaCheia(l) == 1
    //  
}

void imprimeLista(Lista *l){
    if(!estaVazia(l)){
        for(int i = 0; i < l ->n; i++){
            printf("%d \n", l ->itens[i]);
            
        }
    }
    else{
        printf("A lista está Vazia!");
    }
}

void removerElemento(Lista *l, int i){
    if(i > l->n || i < 0){
        printf("Posição inválida!");
    }
    else{      
        for(int x = 0; x < l->n; x++){
            //l->itens[i] = NULL; DESCOBRI A TROCA DE VALOR EM POSIÇÃO
            l->itens[x-1] = l->itens[x];
            
    }
        l -> n--;
    
    }
}