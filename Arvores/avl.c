#include <stdio.h>
#include <stdlib.h>

struct No {
  int chave;
  struct No *esq;
  struct No *dir;
  int altura;
};

int maximo(int a, int b);

int altura(struct No *N) {
  if (N == NULL)
    return 0;
  return N->altura;
}

int maximo(int a, int b) {
  return (a > b) ? a : b;
}

struct No *criarNo(int chave) {
  struct No *no = (struct No *)
    malloc(sizeof(struct No));
  no->chave = chave;
  no->esq = NULL;
  no->dir = NULL;
  no->altura = 1;
  return (no);
}

struct No *rotacaoDir(struct No *y) {
  struct No *x = y->esq;
  struct No *T2 = x->dir;

  x->dir = y;
  y->esq = T2;

  y->altura = maximo(altura(y->esq), altura(y->dir)) + 1;
  x->altura = maximo(altura(x->esq), altura(x->dir)) + 1;

  return x;
}

struct No *rotacaoEsq(struct No *x) {
  struct No *y = x->dir;
  struct No *T2 = y->esq;

  y->esq = x;
  x->dir = T2;

  x->altura = maximo(altura(x->esq), altura(x->dir)) + 1;
  y->altura = maximo(altura(y->esq), altura(y->dir)) + 1;

  return y;
}

int balanceamento(struct No *N) {
  if (N == NULL)
    return 0;
  return altura(N->esq) - altura(N->dir);
}

struct No *inserirNo(struct No *no, int chave) {
  if (no == NULL)
    return (criarNo(chave));

  if (chave < no->chave)
    no->esq = inserirNo(no->esq, chave);
  else if (chave > no->chave)
    no->dir = inserirNo(no->dir, chave);
  else
    return no;

  no->altura = 1 + maximo(altura(no->esq),
               altura(no->dir));

  int balanco = balanceamento(no);
  if (balanco > 1 && chave < no->esq->chave)
    return rotacaoDir(no);

  if (balanco < -1 && chave > no->dir->chave)
    return rotacaoEsq(no);

  if (balanco > 1 && chave > no->esq->chave) {
    no->esq = rotacaoEsq(no->esq);
    return rotacaoDir(no);
  }

  if (balanco < -1 && chave < no->dir->chave) {
    no->dir = rotacaoDir(no->dir);
    return rotacaoEsq(no);
  }

  return no;
}

struct No *menorValor(struct No *no) {
  struct No *noAtual = no;

  while (noAtual->esq != NULL)
    noAtual = noAtual->esq;

  return noAtual;
}

struct No *excluirNo(struct No *raiz, int chave) {
  if (raiz == NULL)
    return raiz;

  if (chave < raiz->chave)
    raiz->esq = excluirNo(raiz->esq, chave);

  else if (chave > raiz->chave)
    raiz->dir = excluirNo(raiz->dir, chave);

  else {
    if ((raiz->esq == NULL) || (raiz->dir == NULL)) {
      struct No *aux = raiz->esq ? raiz->esq : raiz->dir;

      if (aux == NULL) {
        aux = raiz;
        raiz = NULL;
      } else
        *raiz = *aux;
      free(aux);
    } else {
      struct No *aux = menorValor(raiz->dir);

      raiz->chave = aux->chave;

      raiz->dir = excluirNo(raiz->dir, aux->chave);
    }
  }

  if (raiz == NULL)
    return raiz;

  raiz->altura = 1 + maximo(altura(raiz->esq),
               altura(raiz->dir));

  int balanco = balanceamento(raiz);
  if (balanco > 1 && balanceamento(raiz->esq) >= 0)
    return rotacaoDir(raiz);

  if (balanco > 1 && balanceamento(raiz->esq) < 0) {
    raiz->esq = rotacaoEsq(raiz->esq);
    return rotacaoDir(raiz);
  }

  if (balanco < -1 && balanceamento(raiz->dir) <= 0)
    return rotacaoEsq(raiz);

  if (balanco < -1 && balanceamento(raiz->dir) > 0) {
    raiz->dir = rotacaoDir(raiz->dir);
    return rotacaoEsq(raiz);
  }

  return raiz;
}

void imprimirPreOrdem(struct No *raiz) {
  if (raiz != NULL) {
    printf("%d ", raiz->chave);
    imprimirPreOrdem(raiz->esq);
    imprimirPreOrdem(raiz->dir);
  }
}

int main() {
  struct No *raiz = NULL;

  raiz = inserirNo(raiz, 4);
  raiz = inserirNo(raiz, 2);
  raiz = inserirNo(raiz, 9);
  raiz = inserirNo(raiz, 8);
  raiz = inserirNo(raiz, 7);
  raiz = inserirNo(raiz, 6);
  raiz = inserirNo(raiz, 5);

  imprimirPreOrdem(raiz);

  raiz = excluirNo(raiz, 6);

  printf("\n");
  imprimirPreOrdem(raiz);

  return 0;
}
