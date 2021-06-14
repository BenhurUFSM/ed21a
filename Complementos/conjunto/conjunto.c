#include "conjunto.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX 100

// a estrutura oculta
// o conjunto está implementado commo um vetor de tamanho fixo e o número atual de elementos
// FIXME: remover o limite de tamanho, com alocação (e realocação) dinâmica do vetor
struct conjunto {
  cj_t_dado itens[MAX];
  int n_itens;
};

conjunto cj_cria(void)
{
  conjunto cj = malloc(sizeof(*cj));
  cj->n_itens = 0;
  return cj;
}

void cj_destroi(conjunto cj)
{
  free(cj);
}

// funcao auxiliar para imprimir um conjunto
// só funciona se o tipo de item for compativel com %d
static void cj_imprime(conjunto cj)
{
  for (int i=0; i<cj->n_itens; i++) {
    printf("%d ", cj->itens[i]);
  }
  printf("\n");
}

// função auxiliar para encontrar um item no conjunto e retornar sua posição (ou -1)
// só funciona se o tipo do item puder ser comparado com ==
static int cj_acha(conjunto cj, cj_t_dado dado)
{
  for (int i=0; i<cj->n_itens; i++) {
    if (cj->itens[i] == dado) {
      return i;
    }
  }
  return -1;
}

void cj_insere(conjunto cj, cj_t_dado dado)
{
  if (cj_pertence(cj, dado)) return;
  if (cj->n_itens == MAX) return;
  cj->itens[cj->n_itens++] = dado;
}

void cj_remove(conjunto cj, cj_t_dado dado)
{
  int pos = cj_acha(cj, dado);
  if (pos != -1) {
    if (pos != cj->n_itens-1) {
      // move o último item para a posicao do item removido
      cj->itens[pos] = cj->itens[cj->n_itens-1];
    }
    cj->n_itens--; // tinha um bug aqui, esta linha estava depois do '}', removia mesmo o que não existia!
  }
}

bool cj_pertence(conjunto cj, cj_t_dado dado)
{
  int pos = cj_acha(cj, dado);
  return pos != -1;
}

conjunto cj_uniao(conjunto c1, conjunto c2)
{
  conjunto u = cj_cria();
  // insere os itens dos dois conjuntos no resultado, um item não é inserido quando já existe,
  // então não serão criadas duplicatas.
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
  // insere os itens de c1 que pertencem a c2
  for (int i=0; i<c1->n_itens; i++) {
    if (cj_pertence(c2, c1->itens[i])) {
      cj_insere(u, c1->itens[i]);
    }
  }
  return u;
}

int cj_num_elem(conjunto cj)
{
  return cj->n_itens;
}
