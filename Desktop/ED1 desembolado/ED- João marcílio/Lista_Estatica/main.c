/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Aluno
 *
 * Created on 23 de Maio de 2022, 16:18
 */

#include<stdio.h>
#include<stdlib.h>
#include "listaestatica.h"

typedef struct lista Lista;
int main(int argc, char** argv) {
    Lista lista;
    criarLista(&lista);
    insereItem(&lista, 5);
    insereItem(&lista, 10);
    insereItem(&lista, 15);
    removerElemento(&lista, 1);
    imprimeLista(&lista);
    return (EXIT_SUCCESS);
}

