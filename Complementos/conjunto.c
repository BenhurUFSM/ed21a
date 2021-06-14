#include "conjunto.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX 100

struct conjunto {
  cj_t_dado itens[MAX];
  int n_itens;
};

conjunto cj_cria(void)
{
  conjunto cj = malloc(sizeof *cj);
  cj->n_itens = 0;
  return cj;
}

void cj_destroi(conjunto cj)
{
  free(cj);
}

static void cj_imprime(conjunto cj)
{
  for (int i=0; i<cj->n_itens; i++) {
    printf("%d ", cj->itens[i]);
  }
  printf("\n");
}

static int cj_acha(conjunto cj, cj_t_dado dado)
{
  //printf("acha %d\n", dado);
  //cj_imprime(cj);
  for (int i=0; i<cj->n_itens; i++) {
    if (cj->itens[i] == dado) {
      //printf("%d\n", i);
      return i;
    }
  }
  //printf("%d\n", -1);
  return -1;
}
void cj_insere(conjunto cj, cj_t_dado dado)
{
  //printf("insere %d %d\n", dado, cj_pertence(cj, dado));
  if (cj_pertence(cj, dado)) return;
  if (cj->n_itens == MAX) return;
  cj->itens[cj->n_itens++] = dado;
  //cj_imprime(cj);
  //printf("fim do insere\n");
}

void cj_remove(conjunto cj, cj_t_dado dado)
{
  int pos = cj_acha(cj, dado);
  if (pos != -1) {
    if (pos != cj->n_itens-1) {
      cj->itens[pos] = cj->itens[cj->n_itens-1];
    }
  }
  cj->n_itens--;
}

bool cj_pertence(conjunto cj, cj_t_dado dado)
{
  int pos = cj_acha(cj, dado);
  return pos != -1;
}

conjunto cj_uniao(conjunto c1, conjunto c2)
{
  conjunto u = cj_cria();
  for (int i=0; i<c1->n_itens; i++) {
    cj_insere(u, c1->itens[i]);
  }
  for (int i=0; i<c2->n_itens; i++) {
    cj_insere(u, c2->itens[i]);
  }
  return u;
}
conjunto cj_intersecao(conjunto c1, conjunto c2)
{
  conjunto u = cj_cria();
  for (int i=0; i<c1->n_itens; i++) {
    if (cj_pertence(c2, c1->itens[i])) {
      cj_insere(u, c1->itens[i]);
    }
  }
  //printf("intersecao\n");
  //cj_imprime(c1);
  //cj_imprime(c2);
  //cj_imprime(u);
  return u;
}

int cj_num_elem(conjunto cj)
{
  return cj->n_itens;
}
