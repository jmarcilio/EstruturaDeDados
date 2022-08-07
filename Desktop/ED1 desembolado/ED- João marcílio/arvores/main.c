/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Aluno
 *
 * Created on 13 de Julho de 2022, 11:28
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct arvore{
    char info;
    struct arvore* esq;
    struct arvore* dir;
}Arvore;

Arvore* criarArvoreVazia(){
    return NULL;
}

Arvore* criarArvore(char c, Arvore* sae, Arvore* sad){
    Arvore *novo = malloc(sizeof(Arvore));
    if(novo != NULL){
        novo-> info = c;
        novo -> esq = sae;
        novo -> dir = sad;
        return novo;
    }
    else
        printf("Não foi posível alocar espaço!");
}

int estaVazia(Arvore* arv){
    return(arv == NULL);
}

int pertenceArvore(Arvore* arv, char c){
    if(estaVazia(arv)){
        return 0;
    }
    else{
        if(c == arv->info)
            return 1;
        else
            return(pertenceArvore(arv->esq, c) || pertenceArvore(arv->dir, c));
    }
}

void imprimeArvore(Arvore* arv){
    printf("<");
    if(!estaVazia(arv)){
        printf("%c", arv -> info);
        imprimeArvore(arv -> esq);
        imprimeArvore(arv -> dir);
    }
    printf(">");
}

Arvore* liberarArvore(Arvore* arv){
    if(!estaVazia(arv)){
        liberarArvore(arv->esq);
        liberarArvore(arv->dir);
        free(arv);
    }
        return NULL;
    
}

int quantidadeNos(Arvore *arv){
    int h, n;
    if(!estaVazia(arv)){
        return 1 + quantidadeNos(arv-> esq) + quantidadeNos(arv -> dir);
    }
    else{
        return 0;
    }
}


int main(int argc, char** argv) {
    Arvore* arv = criarArvoreVazia();
    Arvore *a_d = criarArvore('d', criarArvoreVazia() , criarArvoreVazia());
    Arvore *a_e = criarArvore('e', criarArvoreVazia() , criarArvoreVazia());
    Arvore *a_f = criarArvore('f', criarArvoreVazia() , criarArvoreVazia());
    Arvore *a_b = criarArvore('b', criarArvoreVazia() , a_d);
    Arvore *a_c = criarArvore('c', a_e , a_f);
    Arvore *a = criarArvore('a', a_b, a_c);
    a->esq ->esq = criarArvore('g', NULL, NULL); // colocando g na árvore
    imprimeArvore(a);
    printf("\n%d", pertenceArvore(a, 'a'));
    printf("\n%d", quantidadeNos(a)); // tem que retornar 7
    liberarArvore(a->esq);
    //imprimeArvore(a);
    return (EXIT_SUCCESS);
}

// se arv for NULL, h = -1
// se a arv não tiver nenhuma raiz h=0
// o Ultimo nível corresponde a altura da árvore
// O numero de nós em uma árvore cheia em cada nível é 2^n n é o nível que estamos calculando; 2^h+1 - 1

