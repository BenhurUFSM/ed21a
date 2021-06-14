#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <stdbool.h>

typedef int cj_t_dado;
typedef struct conjunto *conjunto;

conjunto cj_cria(void);
void cj_destroi(conjunto cj);

void cj_insere(conjunto cj, cj_t_dado dado);
void cj_remove(conjunto cj, cj_t_dado dado);
bool cj_pertence(conjunto cj, cj_t_dado dado);

conjunto cj_uniao(conjunto c1, conjunto c2);
conjunto cj_intersecao(conjunto c1, conjunto c2);

int cj_num_elem(conjunto cj);

#endif