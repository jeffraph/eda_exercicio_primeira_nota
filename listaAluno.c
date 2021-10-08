#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    int matricula;
    float media;
    char situacao;
    struct aluno * proximo;
}Aluno;

typedef struct {
    Aluno *inicio;
    int tam;
}Lista;

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

//procedimento para inserir no inicio

/*void inserir_no_inicio(Lista *lista, int num, float num2, char s){
    Aluno * novo = malloc(sizeof(Aluno));
    if(novo){
        novo->matricula = num;
        novo->media = num2;
        novo->situacao = s;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;      

    }else {
        printf("Erro ao alocar memoria!\n");
    }

}

//procedimento para inserir no final
void inserir_no_fim(Lista *lista, int num, float num2, char s){
    Aluno *aux, *novo = malloc(sizeof(Aluno));

        if(novo){
            novo->matricula = num;
            novo->media = num2;
            novo->situacao = s;
            novo->proximo = NULL;

            if(lista->inicio == NULL){
                lista->inicio = novo;

            }else {
                aux = lista->inicio;
                while(aux->proximo)
                    aux = aux->proximo;
                aux->proximo = novo;

            }
            lista->tam++;

        }else {
            printf("Erro ao alocar memoria!\n");
        }
    }*/

//procedimento para inserir ordenado
void inserir_ordenado(Lista *lista, int num, float num2, char s){
    Aluno *aux, *novo = malloc(sizeof(Aluno));

    if(novo){
        novo->matricula = num;
        novo->media = num2;
        novo->situacao = s;
        if(lista->inicio == NULL) {
            novo->proximo = NULL;
            lista->inicio = novo;

        }else if(novo->matricula < lista->inicio->matricula){
            novo->proximo = lista->inicio;
            lista->inicio = novo;

        }else {
            aux = lista->inicio;
            while(aux->proximo && novo->matricula > aux->proximo->matricula)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;

    }else{
       printf("Erro ao alocar memoria!\n"); 
    }
}
Aluno * buscar(Lista *lista, int num){
    Aluno *aux, *no = NULL;

    aux = lista->inicio;
    while(aux && aux->matricula != num)
        aux = aux->proximo;
    if(aux)
        no = aux;
    return no;
}

Aluno* remover(Lista *lista, int num){
    Aluno *aux, *remover = NULL;

    if(lista->inicio){
        if(lista->inicio->matricula == num) {
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->tam--;

        }else {
            aux = lista->inicio;
            while(aux->proximo && aux->proximo->matricula != num)
                aux = aux->proximo;
            if(aux->proximo) {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                lista->tam--;
            }
        }
    }

    return remover;
}

void imprimir(Lista lista) {
    Aluno *no = lista.inicio;
    printf("\n\tLista tamanho %d: \n", lista.tam);
    while(no) {
        
        printf("MATRICULA: %d  MEDIA: %.2f  SITUACAO: %c \n", no->matricula, no->media, no->situacao);
        no = no->proximo;
    }
    printf("\n\n");

}


int main() {

    int opcao, matricula;
    float media;
    char situacao;
    //No *lista = NULL;
    Lista lista;
    Aluno *removido;

    criar_lista(&lista);
    do{

        printf("\n\t0 - SAIR\n\t3 - INSERIR ORDENADO\n\t4 - BUSCAR\n\t5 - REMOVER\n\t6 - IMPRIMIR\n");
        //printf("\n\t1 - INSERIR NO INICIO\n\t2 - INSERIR NO FINAL\n");
        scanf("%d", &opcao);

        switch(opcao){
            /*case 1:
                printf("Digite a matricula, a media e a situação:\n");
                scanf("%d %f %c", &matricula, &media, &situacao);
                inserir_no_inicio(&lista, matricula, media, situacao);
                break;
            case 2:
                printf("Digite a matricula, a media e a situação:\n");
                scanf("%d %f %c", &matricula, &media, &situacao);
                inserir_no_inicio(&lista, matricula, media, situacao);
                break;*/
            case 3:
            printf("Digite a matricula, a media e a situação:\n");
                scanf("%d %f %c", &matricula, &media, &situacao);
                inserir_ordenado(&lista, matricula, media, situacao);
                break;
            case 4:
                printf("Digite uma matricula a ser buscada: ");
                scanf("%d", &matricula);
                removido = buscar(&lista, matricula);
                if(removido){
                    printf("Matricula Encontrada: %d    Media: %f     Situacao: %c\n", removido->matricula, removido->media, removido->situacao);
                   
                }else{
                    printf("Matricula nao encontrada.\n");
                }
                break;
            case 5:
                printf("Digite uma matricula a ser removida:\n");
                scanf("%d", &matricula);
                removido = remover(&lista, matricula);
                if(removido){
                    printf("Matricula removida: %d\  Media: %f     Situacao: %c\n", removido->matricula, removido->media, removido->situacao);
                    free(removido);

                }else{
                    printf("Elemento inexistente!\n");
                }
                break;
            case 6:
                imprimir(lista);
                break;
            default:
                if(opcao != 0)
                    printf("OPCAO INVALIDA!\n");
        }
    }
    while(opcao !=0);

    return 0;
}
