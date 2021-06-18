// data2.c -- implementacao do TAD data usando dias desde 2000
#include "data.h"
#include <stdbool.h>
#include <stdlib.h>

// declaração da estrutura "oculta"
struct data {
    int d2000;
};

// inclui funções auxiliares comuns às duas implementações
#include "aux_data.c"

data dt_cria(int d, int m, int a)
{
    data dt;
    if (!dt_data_ok(d, m, a)) {
      return NULL;
    }
    dt = malloc(sizeof(struct data));
    if (dt != NULL) {
        // volta para o inicio do ano
        dt->d2000 = dias_desde_inicio_do_ano(d, m, a);
        // agora vamos pro ano 2000!
        while (a < 2000) {
          dt->d2000 -= dias_no_ano(a);
          a++;
        }
        while (a > 2000) {
          a--;
          dt->d2000 += dias_no_ano(a);
        }
    }
    return dt;
}

void dt_destroi(data d)
{
    free(d);
}

// calcula d, m, a a partir de dias apos 2000
static void dma_2000(int d2000, int *pd, int *pm, int *pa)
{
  // estamos a tantos dias de janeiro de 2000
  int dia = d2000, mes = 1, ano = 2000;
  // ajusta o ano
  while (dia < 0) {          // estamos antes de "ano"
    ano--;                   // mudamos a ref para o início do ano anterior
    dia += dias_no_ano(ano); // aumentou o no de dias desde a referência
  }
  while (dia > dias_no_ano(ano)-1) { // estamos depois do fim de "ano"
    dia -= dias_no_ano(ano); // retira os dias desse ano, vamos pro próximo
    ano++;                   // a referência agora é o ano seguinte
  }
  // ajusta o mes
  while (dia > dias_no_mes(mes, ano)-1) { // ops, estamos depois do fim do mês
    dia -= dias_no_mes(mes, ano);
    mes++;
  }
  *pd = dia+1;
  *pm = mes;
  *pa = ano;
}

int dt_dia(data dt)
{
    int d, m, a;
    dma_2000(dt->d2000, &d, &m, &a);
    return d;
}

int dt_mes(data dt)
{
    int d, m, a;
    dma_2000(dt->d2000, &d, &m, &a);
    return m;
}

int dt_ano(data dt)
{
    int d, m, a;
    dma_2000(dt->d2000, &d, &m, &a);
    return a;
}

int dt_dia_semana(data d)
{
    // 1/1/2000 (dia 0) foi sábado
    // o calculo vai ser assim:
    // data     d2000   %7  +7
    // 25/12/1999  -7    0   7
    // 26/12/1999  -6   -6   1
    // ...
    // 30/12/1999  -2   -2   5
    // 31/12/1999  -1   -1   6
    // 01/01/2000   0    0   7
    // 02/01/2000   1    1
    // 03/01/2000   2    2
    // ...
    // 08/01/2000   7    0   7
    int r = d->d2000 % 7;
    if (r<1) r += 7;  // para sábado ser 7, e corrigir os negativos
    return r;
}

int dt_dias_entre_datas(data d1, data d2)
{
    return d2->d2000 - d1->d2000;
}

data dt_soma_data(data d, int dias)
{
    data dt = malloc(sizeof(struct data));
    if (dt != NULL) {
        dt->d2000 = d->d2000 + dias;
    }
    return dt;
}
