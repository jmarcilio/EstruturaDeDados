/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Aluno
 *
 * Created on 12 de Julho de 2022, 16:31
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    FILE* arq = fopen("entrada.txt", "r");
    
    if(arq != NULL){
        printf("Arquivo aberto com sucesso!\n");
        
        char nome[80];
        //printf("Digite seu nome: \n");
        //scanf("%[^\n]", nome);
        
        //fprintf(arq, "%s", nome);
        
            for(int i = 0; i != EOF; i++){
                if(nome == '\n')
                    printf(arq, "%s", i);
            }
        
        int x = fclose(arq);
        

        if(x == 0){
            printf("\nO arquivo foi fechado com sucesso.\n");
        }
        
    }else{
        printf("Não foi possível abrir o arquivo.\n");
        
    }
    
    // int x = fscanf(arq, "%d %[^\n]\n", &i, &nome)
    return (EXIT_SUCCESS);
}

//while(fgetc(arq, "%c", &c) == 1)
//char c;
//while((c = fgetc(arq)) != EOF) 
//            printf("%c", c);