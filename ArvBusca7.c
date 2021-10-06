#include "ArvBusca7.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int contfolhas_maiores=0, soma=0, nivel=-1;  //Inteiros utilizados na questao

struct arvno {

    int info;

    ArvNo* esq;

    ArvNo* dir;

};

struct arv{
    ArvNo* raiz;
};

static void libera (ArvNo* r)

{

	if (r != NULL) {

		libera(r-> esq); /* l i b e r a a s ae */

		libera(r-> dir); /* l i b e r a a sad */

		free(r); /* l i b e r a o n� r a i z */

	}

}

void arv_libera (Arv* a)

{

		libera(a-> raiz); /* l i b e r a h i e r a r q u i a de n�s */

		free(a); /* l i b e r a r a i z */

}


static void imprime (ArvNo* r){

    if (r != NULL) {

        imprime(r-> esq);

        printf("% d \n",r-> info);

        imprime(r-> dir);

    }

}

void abb_imprime (Arv* a){

    return imprime(a-> raiz);

}

static ArvNo* busca (ArvNo* r, int v){

    if (r == NULL) return NULL;

    else if (r-> info > v) return busca (r->esq , v);

    else if (r-> info < v) return busca (r->dir, v);

    else return r;

}

ArvNo* abb_busca (Arv* a, int v){

    return busca(a->raiz ,v);

}

Arv* abb_cria (void ){

    Arv* a = (Arv*) malloc(sizeof (Arv));

    a-> raiz = NULL;

    return a;

}

static ArvNo* insere (ArvNo* r, int v){

    if (r== NULL) {

        r = (ArvNo*) malloc(sizeof (ArvNo ));

        r-> info = v;

        r-> esq = r-> dir = NULL;

    }

    else if (v < r-> info) r-> esq = insere(r->esq ,v);

    else r-> dir = insere(r->dir,v);

    return r;

}

void abb_insere (Arv* a, int v){

    a-> raiz = insere(a->raiz ,v);

}

static ArvNo* retira (ArvNo* r, int v){

    if (r == NULL) return NULL;

    else if (r-> info > v) r-> esq = retira(r->esq , v);

    else if (r-> info < v) r-> dir = retira(r->dir, v);

    else if (r-> esq == NULL && r-> dir == NULL) {

        free (r);

        r = NULL;

    }



    else if (r-> esq == NULL) {

        ArvNo* t = r;

        r = r-> dir;

        free (t);

    }

    else if (r-> dir == NULL) {

        ArvNo* t = r;

        r = r-> esq;

        free (t);

    }

    else{

        ArvNo* f = r-> esq;

        while (f-> dir != NULL) {

            f = f-> dir;

        }

        r-> info = f-> info; 

        f-> info = v;

        r-> esq = retira(r->esq ,v);

    }



    return r;

}

void abb_retira (Arv* a, int v){

    a-> raiz = retira(a->raiz ,v);

}

int somaNo_xy(ArvNo* r, int x, int y){  //Funcao que soma os valores dos nos entre x e y
    if(r==NULL) return 0;  //Condicao de parada da iteracao
    if(x>r->info && r->info>y) soma+=r->info;  //Se estiver entre x e y, adiciona a soma
    if(r->info>=x) somaNo_xy(r->esq, x, y);  //Se for maior ou igual a x, percorre a esquerda
    else if(r->info<=y) somaNo_xy(r->dir, x, y);  //Se for menor ou igual a y, percorre a direita
    else{  //Se estiver entre os dois, percorre a direita e esquerda
        somaNo_xy(r->esq, x, y);
        somaNo_xy(r->dir, x, y);
    }
    return soma;  //Retorna o inteiro soma
}

int soma_xy (Arv*a, int x, int y){  //Funcao que soma os elementos da arvore que estao entre x e y
    int s=somaNo_xy(a->raiz, x, y);  //Armazena o valor retornado em s
    soma=0;  //Reseta a variavel global
    return s;  

}

