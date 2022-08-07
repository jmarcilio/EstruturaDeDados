/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listaestatica.h
 * Author: Aluno
 *
 * Created on 23 de Maio de 2022, 17:43
 */

#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H
#define MAX 10

typedef struct lista{
    int itens[MAX];
    int n;
}Lista;

void removerElemento(Lista *l, int i);
void insereItem(Lista *l, int v);
int estaVazia(Lista *l);
void criarLista(Lista *l);


#endif /* LISTAESTATICA_H */

