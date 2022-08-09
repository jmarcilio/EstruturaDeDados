#include "aluno.h"
#include "listaDupla.h"

int main(){
int id;
listaDupla **a = criaListaDupla();

    int continuar=1;

    do
    {
        printf("\n\tEscolha a opção desejada:\n\n");
        printf("1 - Inserir um novo aluno\n");
        printf("2 - Alterar dados de um aluno\n");
        printf("3 - Remover um aluno\n");
        printf("4 - Imprimir a lista de alunos\n");
        printf("5 - Inserir relação de amizade\n");
        printf("6 - Remover relação de maizade\n");
        printf("7 - Imprimir amigos de um aluno\n");
        printf("8 -  imprimir a lista de aunos por curso\n");
        printf("9 - Sair\n");

        scanf("%d", &continuar);
        system("cls || clear");

        switch(continuar)
        {
            case 1:
                Aluno * temp = leAluno();
                inserirListaDupla(*a, temp);
            break;

            case 2:
                alterarNome(id);
                alteraCurso(id);
            break;

            case 3:
                removeAluno(*a);
                break;

            case 4:
                imprimeAluno(*a);
                break;

            case 5:
                inserirListaSim(*a,id);  
                break;

            case 6:
                removeAmigo(*a,id);
                break;

            case 7:
                imprimeAmigos(*a);
                break;

            case 8:
                retornaCurso(a);
                break;         

            case 9:
                break;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(continuar);
}