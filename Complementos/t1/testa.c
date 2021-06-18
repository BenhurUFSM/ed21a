// testadata2.c -- programa (incompleto) para testar o TAD data
#include <stdio.h>
#include "data.h"

void imprime_data(data d)
{
    printf("%02d/%02d/%04d", dt_dia(d), dt_mes(d), dt_ano(d));
}

int main()
{
    data natal;
    data hoje;
    natal = dt_cria(25, 12, 2021);
    hoje = dt_cria(7, 6, 2021);
    int falta = dt_dias_entre_datas(hoje, natal);
    data natal2 = dt_soma_data(hoje, falta);
    printf("hoje é ");
    imprime_data(hoje);
    printf(", faltam %d dias pro natal (que este ano será dia ", falta);
    imprime_data(natal2);
    printf(")\n");
    dt_destroi(natal);
    dt_destroi(natal2);
    dt_destroi(hoje);

    data d1;
    d1 = dt_cria(1, 1, 2000);
    for (int i=-366; i<=366; i++) {
       data d2 = dt_soma_data(d1, i);
       int ded = dt_dias_entre_datas(d1, d2);
       imprime_data(d1);
       printf(" %+03d dias = ", i);
       imprime_data(d2);
       printf(" %d-feira", dt_dia_semana(d2));
       if (ded != i) {
          printf(" erro, %d deveria ser %d", ded, i);
       }
       printf("\n");
       dt_destroi(d2);
    }
    dt_destroi(d1);
    return 0;
}
