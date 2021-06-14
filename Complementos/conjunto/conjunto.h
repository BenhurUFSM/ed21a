#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <stdbool.h>

typedef int cj_t_dado;   // tipo de dado que será armazenado no conjunto
typedef struct conjunto *conjunto;  // estrutura com implementação oculta

conjunto cj_cria(void);  // aloca, inicializa e retorna um conjunto vazio
void cj_destroi(conjunto cj);  // libera a memória de um conjunto

void cj_insere(conjunto cj, cj_t_dado dado);  // insere um dado em um conjunto
void cj_remove(conjunto cj, cj_t_dado dado);  // remove um dado de um conjunto
bool cj_pertence(conjunto cj, cj_t_dado dado);  // testa se dado está no conjunto

conjunto cj_uniao(conjunto c1, conjunto c2);  // retorna um novo conjunto com a união (deve ser destruído mais tarde)
conjunto cj_intersecao(conjunto c1, conjunto c2);  // retorna um novo conjunto com a interseção (deve ser destruído mais tarde)

int cj_num_elem(conjunto cj);  // retorna o número de itens em um conjunto

#endif
