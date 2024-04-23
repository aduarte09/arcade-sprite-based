#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Registro Registro;

typedef struct No *Apontador;

typedef Apontador tipoDicionario;

int altura(Apontador *p) {
  if (*p == NULL) {
    return -1;
  } else {
    int alturaEsq = altura(&((*p)->esq));
    int alturaDir = altura(&((*p)->dir));
    return (alturaEsq > alturaDir) ? alturaEsq + 1 : alturaDir + 1;
  }
}

void antecessor(Apontador q, Apontador *r) {
  if ((*r)->dir != NULL) {
    antecessor(q, &(*r)->dir);
    return;
  }
  q->r = (*r)->r;
  *r = (*r)->esq;
  free(q);
}

void criacao(Apontador *Dicionario) { *Dicionario = NULL; }

void insercao(Registro x, Apontador *p) {
  if (*p == NULL) {
    *p = (Apontador)malloc(sizeof(struct No)); // Corrigido aqui
    (*p)->r = x;
    (*p)->esq = NULL;
    (*p)->dir = NULL;
    return;
  }
  if (x.chave < (*p)->r.chave) {
    insercao(x, &(*p)->esq);
    return;
  }
  if (x.chave > (*p)->r.chave) {
    insercao(x, &(*p)->dir);
    return;
  } else {
    printf("Erro: Registro ja existe na arvore \n");
    return;
  }
}

void remocao(Registro x, Apontador *p) {
  Apontador aux;
  if (*p == NULL) {
    printf("Erro: Registro nao esta na arvore \n");
    return;
  }
  if (x.chave < (*p)->r.chave) {
    remocao(x, &(*p)->esq);
    return;
  }
  if (x.chave > (*p)->r.chave) {
    remocao(x, &(*p)->dir);
    return;
  }
  if ((*p)->esq != NULL) {
    antecessor(*p, &(*p)->esq);
    return;
  }
  aux = *p;
  *p = (*p)->dir;
  free(aux);
}

Registro pesquisa(Registro *x, Apontador *p) {
  Registro r;
  r.chave = -1;
  if (*p == NULL) {
    return r;
  }
  if (x->chave < (*p)->r.chave) {
    return pesquisa(x, &(*p)->esq);
  }
  if (x->chave > (*p)->r.chave) {
    return pesquisa(x, &(*p)->dir);
  }
  return (*p)->r;
}

// percursos
// percursos
void central(Apontador *p) {
  if (*p == NULL)
    return;
  central(&((*p)->esq));
  printf("%f\n", (*p)->r.chave);
  central(&((*p)->dir));
}

Apontador *menor(Apontador p) {

  if (p == NULL) {
    return NULL; // Árvore binária vazia, retorna -1.
  }

  Apontador menor;

  while (p->esq != NULL) {
    p = p->esq;
  }
  return &p;
}

Apontador *maior(Apontador p) {

  if (p == NULL) {
    return NULL; // Árvore binária vazia, retorna -1.
  }

  Apontador maior;

  while (p->dir != NULL) {
    p = p->dir;
  }
  return &p;
}

void pre_fixado(Apontador *p) {
  if (*p != NULL) {
    printf("%f ", (*p)->r.chave);
    pre_fixado(&((*p)->esq));
    pre_fixado(&((*p)->dir));
  }
}

void pos_fixado(Apontador *p) {
  if (*p != NULL) {
    pos_fixado(&((*p)->esq));
    pos_fixado(&((*p)->dir));
    printf("%f ", (*p)->r.chave);
  }
}
