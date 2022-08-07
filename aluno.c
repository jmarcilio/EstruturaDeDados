#include "aluno.h"


Aluno *leAluno(){
  char nome[30];
  char curso[30];
  Aluno *novo = malloc(sizeof(Aluno));

  novo->amigos = NULL;

  printf("Qual o nome do aluno? \n");
  scanf("%[^\n]", nome);
  fflush(stdin);
  strcpy(novo->nome, nome);

  printf("Qual o curso do aluno? \n");
  scanf("%[^\n]", curso);
  fflush(stdin);
  strcpy(novo->curso, curso);
  novo->id = id;
  id++;
  return novo;
}

void alterarNome(Aluno *a){
    int mat;
    char nome[30];
    printf("Informe o id para alterar o nome do aluno:");
    scanf("%d", &mat);
    if(a->id != mat){
        printf("Informe o novo nome do aluno:");
        scanf("%[^\n]", nome);
        fflush(stdin);
        strcpy(a->nome, nome);
    }
}

void alterarCurso(Aluno *a){
    char curso[30];
    int mat;
    printf("Informe o id para alterar o nome do aluno:");
    scanf("%d", &mat);
    if(a->id != mat){
        printf("Informe o novo nome do curso: \n");
        scanf(" %[^\n]", curso);
        fflush(stdin);
        strcpy(a->curso, curso);
    }
}

char* retornaCurso(Aluno* a){    
    return(a->curso);      
}

void imprimeAluno(Aluno* a){
    printf("%s\n%s",a->nome, a->curso);          
}

void removeAluno(Aluno* a){
    if(a != NULL){
        liberaLista(a->amigos);
        free(a);
    }
}

void liberaLista(listaSimples *ls){
    free(ls);
}