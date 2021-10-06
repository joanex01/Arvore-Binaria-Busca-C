#ifndef ARVBUSCA_H
#define ARVBUSCA_H


struct arvno ArvNo;
struct arv Arv;
static void imprime (ArvNo* r);
void abb_imprime (Arv* a);
static ArvNo* busca (ArvNo* r, int v);
ArvNo* abb_busca (Arv* a, int v);
Arv* abb_cria (void );
static ArvNo* insere (ArvNo* r, int v);
void abb_insere (Arv* a, int v);
static ArvNo* retira (ArvNo* r, int v);
void abb_retira (Arv* a, int v);


#endif