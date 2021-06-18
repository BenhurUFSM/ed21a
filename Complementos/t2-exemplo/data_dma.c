// data.c -- implementacao do TAD data usando dia, mes, ano
#include "data.h"
#include <stdbool.h>
#include <stdlib.h>

// declaração da estrutura "oculta"
struct data {
    int dia;
    int mes;
    int ano;
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
        dt->dia = d;
        dt->mes = m;
        dt->ano = a;
    }
    return dt;
}

void dt_destroi(data d)
{
    free(d);
}

int dt_dia(data d)
{
    return d->dia;
}

int dt_mes(data d)
{
    return d->mes;
}

int dt_ano(data d)
{
    return d->ano;
}

int dt_dia_semana(data d)
{
    struct data d1 = {1, 1, 1900}; // segunda
    int nd = dt_dias_entre_datas(&d1, d);
    int r = nd % 7;
    r = r+2; // para ser segunda quando o resto for 0
    if (r>7) r -= 7;  // para domingo ser 1
    return r;
}

// incrementa um dia na data
static void amanha(data d)
{
  d->dia++;
  if (d->dia > dias_no_mes(d->mes, d->ano)) {
    d->dia = 1;
    d->mes++;
    if (d->mes > 12) {
      d->mes=1;
      d->ano++;
    }
  }
}

// decrementa um dia da data
static void ontem(data d)
{
  d->dia--;
  if (d->dia < 1) {
    d->mes--;
    if (d->mes < 1) {
      d->mes=12;
      d->ano--;
    }
    d->dia = dias_no_mes(d->mes, d->ano);
  }
}

// retorna negativo se d1<d2, 0 se ==, positivo se d1>d2
static int dt_compara(data d1, data d2)
{
  if (d1->ano != d2->ano) return d1->ano - d2->ano;
  if (d1->mes != d2->mes) return d1->mes - d2->mes;
  return d1->dia - d2->dia;
}

int dt_dias_entre_datas(data d1, data d2)
{
    // inicia em d1, viaja no tempo até d2, contando os dias
    int dias = 0;
    data dt = dt_cria(d1->dia, d1->mes, d1->ano);
    while (dt_compara(dt, d2) < 0) {
      amanha(dt);
      dias++;
    }
    while (dt_compara(dt, d2) > 0) {
      ontem(dt);
      dias--;
    }
    dt_destroi(dt);
    return dias;
}

data dt_soma_data(data d, int dias)
{
    // inicia com a data d, viaja no tempo tantos dias, pro passado ou pro futuro
    data dt = dt_cria(d->dia, d->mes, d->ano);
    while (dias < 0) {
      ontem(dt);
      dias++;
    }
    while (dias > 0) {
      amanha(dt);
      dias--;
    }
    return dt;
}
