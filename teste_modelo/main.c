#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "strux.h"

/** Conta o numero de reviews que um utilizador tem
 *
 * @param items     apontador para a lista de items
 * @param nitems    numero de items na lista
 * @param id        identificador do user a pesquisar
 * @return          numero de reviews
 */
int contaReviews(struct item *items, int nitems,int id){
    int counter = 0;
    for ( int i= 0; i < nitems; i++ ) {
        for ( int j = 0; j < items[i].n_reviews; j++ ) {
            if ( items[i].reviews[j].user->id == id ) {
                counter ++;
            }
        }
    }
    return counter;
}



/** Adiciona uma nova review a um item. Devolve 1 qem case de sucesso e 0 em caso contrario
 *
 * @param items     apontador para a lista de items
 * @param nitems    numero de items da lista
 * @param users     apontador para lista de utilizadores
 * @param nusers    numero de utilizadores da lista
 * @param idItem    identificador do item que recebe a review
 * @param idUser    identificador do utilizador que faz a review
 * @param texto     texto a incluir na nova review
 * @param score     score da nova review
 * @return          1 em caso de sucesso, 0 caso contrario
 */
int addReview(struct item* items, unsigned int nitems, struct utilizador* users,
        unsigned int nusers, int idItem, int idUser, char *texto, unsigned short score){

    int i = 0, j = 0;

    //verificar presença do item
    while(items[i].id != idItem ){
        if(i = nitems){return 0;}
        i++;
    }

    //verificar preseça do user
    while(users[j].id != idUser ){
        if(j = nusers){return 0;}
        j++;
    }

    //remoçao da review mais antiga
    if(items[idItem].n_reviews == MAX_REV){
        for (int x = 0; x < items[idItem].n_reviews; x++) {
            items[idItem].reviews[x] = items[idItem].reviews[x + 1];
        }
        --(items[idItem].n_reviews);
    }

    //atribuição de valores
    items[idItem].reviews[j].user = &users[j];
    items[idItem].reviews[j].score = score;
    strcpy(items[idItem].reviews[j].texto, texto);
    ++(items[idItem].n_reviews);

    return 1;
}

void leItem(struct item *item){
    //TODO: Complete inputs
}

//TODO: Check if it works
int leItems(struct item **items, int *nitems, int n){
    struct item *temp;
    if(!(*items)){
        temp = realloc(*items, sizeof(struct item) * ((*nitems) + n));
        if(!temp){
            printf("Erro de alocação.");
        }else{
            *items = temp;
            *nitems += n;
            for(int i = (*nitems); i < (*nitems) + n; i++){ leItem(items[i]);}
        }
    }else{
        *items = (struct item *) malloc(sizeof(struct item) * n);
        if(!(*items)){
            printf("Erro de alocação.");
        }else{
            *nitems += n;
            for(int i = 0; i < n; i++){ leItem(items[i]);}
        }
    }
}

int main() {

    //arrays
    struct utilizador* users = NULL;
    struct item* items = NULL;

    //base vars
    int idUser, idItem, nusers, nitems, id, nRevs, score, i = 0;
    bool flagUserCR = false;
    char *string;

    //1ª exercicio do teste modelo
    for(int i = 0; 9 < nusers; i++){if(users[i].id == id){flagUserCR = true;} i++;}   //update: now searches to check if user exists
    if(flagUserCR){nRevs = contaReviews(items, nitems, id);}
    else{printf("O utilizador não existe.\n");}

    //2ª exercicio do teste modelo

    //inputs
    printf("Qual o string a incluir na review: ");
    scanf("%s", string);
    printf("\nQual o score a dar á review: ");
    scanf("%d", &score);

    //funçao para addicionar review
    if(addReview(items, nitems, users, nusers, idItem, idUser, string, score)){
        printf("ERRO AO ADICIONAR REVIEW\n");
    }else{ printf("Review adicionada com sucesso.\n"); }

    //3º exercício do teste modelo

    return (EXIT_SUCCESS);
}