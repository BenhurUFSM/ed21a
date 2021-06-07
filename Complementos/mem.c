// mem.c
//
// implementacao de funções para auxilio simples a alocacao de memoria

#include "mem.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
  void *ptr; // regiao alocada
  int nbytes; // tamanho da regiao
  char *f_aloca; // funcao onde foi alocada
  int l_aloca;  // linha onde foi alocada
  char *f_libera; // funcao onde foi liberada
  int l_libera; // linha onde foi liberada
} aloc_t;

#define MAX_ALOCACOES 100000 // numero maximo de alocacoes rastreadas

aloc_t alocacoes[MAX_ALOCACOES]; // tabela com todas as alocacoes
int n_aloc = 0; // número de alocações registradas
int n_libera = 0; // número de liberações registradas

void guarda_ptr(void *ptr, int nbytes, char *funcao, int linha)
{
  if (n_aloc >= MAX_ALOCACOES) {
    printf("estourou capacidade do registrador de alocações.\n");
    return;
  }
  alocacoes[n_aloc].ptr = ptr;
  alocacoes[n_aloc].nbytes = nbytes;
  alocacoes[n_aloc].f_aloca = funcao;
  alocacoes[n_aloc].l_aloca = linha;
  alocacoes[n_aloc].f_libera = NULL;
  alocacoes[n_aloc].l_libera = 0;
  n_aloc++;
}

aloc_t *acha_ptr(void *ptr)
{
  for (int i=n_aloc-1; i>=0; i--) {
    if (alocacoes[i].ptr == ptr) return &alocacoes[i];
  }
  return NULL;
}

void libera_ptr(aloc_t *reg, char *funcao, int linha)
{
  reg->f_libera = funcao;
  reg->l_libera = linha;
  n_libera++;
}

void *m_aloca_mesmo(int nbytes, char *funcao, int linha)
{
  void *ptr = malloc(nbytes);
  if (ptr != NULL) {
    guarda_ptr(ptr, nbytes, funcao, linha);
  }
  return ptr;
}

void *m_realoca_mesmo(void *ptr, int nbytes, char *funcao, int linha)
{
  m_verif(ptr);
  aloc_t *reg = acha_ptr(ptr);
  if (reg != NULL) {
    libera_ptr(reg, funcao, linha);
  } else {
    printf("tentativa de realocar ponteiro não alocado\n");
    printf("funcao %s, linha %d\n", funcao, linha);
  }
  void *nptr = realloc(ptr, nbytes);
  if (nptr != NULL) {
    guarda_ptr(nptr, nbytes, funcao, linha);
  }
  return nptr;
}

void m_libera_mesmo(void *ptr, char *funcao, int linha)
{
  m_verif(ptr);
  aloc_t *reg = acha_ptr(ptr);
  if (reg != NULL) {
    libera_ptr(reg, funcao, linha);
    free(ptr);  // comenta esta linha para não liberar de verdade a memoria
  } else {
    printf("tentativa de liberar ponteiro não alocado\n");
    printf("funcao %s, linha %d\n", funcao, linha);
  }
}

// use para verificar se ptr é uma regiao que foi alocada com m_aloca e
// ainda nao liberada
bool m_verif(void *ptr)
{
  if (ptr == NULL) {
    printf("uso de ptr NULL\n");
    return false;
  }
  aloc_t *reg = acha_ptr(ptr);
  if (reg == NULL) {
    printf("uso de ptr nao alocado\n");
    return false;
  }
  if (reg->f_libera != NULL) {
    printf("uso de ptr ja liberado (na funcao %s, linha %d)\n",
      reg->f_libera, reg->l_libera);
    return false;
  }
  return true;
}

// chame esta funcao para imprimir um relatorio resumido de alocacoes
void m_relat(void)
{
  printf("Total de alocações: %d  total de liberações: %d\n", 
         n_aloc, n_libera);
}

// chame esta funcao para um relatorio mais completo
void m_relatorio_grande(void)
{
  m_relat();
  printf("Alocações:\n");
  for (int i=0; i<n_aloc; i++) {
    if (i%20 == 0) {
      printf("    id nbytes              alocado em             liberado em\n");
    }
    printf("%6d%7d%19s:%04d", i, alocacoes[i].nbytes,
        alocacoes[i].f_aloca, alocacoes[i].l_aloca);
    if (alocacoes[i].f_libera == NULL) {
      printf("%24s\n", "NAO LIBERADO");
    } else {
      printf("%19s:%04d\n", alocacoes[i].f_libera, alocacoes[i].l_libera);
    }
  }
}
