// data.h
// interface do TAD data, que representa uma data do calendario gregoriano.

// proteção contra inserção múltipla
#ifndef _DATA_H_
#define _DATA_H_

// o tipo de dados principal, data, definido como um ponteiro para uma estrutura (struct data) não declarada aqui
typedef struct data *data;

// API que implementa as operações definidas para "data"

// criação de uma data 
// recebe dia, mês, ano
// retorna um ponteiro para a data criada
// retorna NULL se a data for inválida ou faltar memória
// a data retornada deve ser destruída com dt_destroi após o uso
data dt_cria(int d, int m, int a);

// destruição de uma data
// recebe um ponteiro para uma data
// libera a memória que esteja utilizando
void dt_destroi(data d);

// obtenção do dia de uma data, recebe uma data, retorna o dia (1 a 31)
int dt_dia(data d);
// obtenção do mês de uma data, recebe uma data, retorna o mês (1 a 12)
int dt_mes(data d);
// obtenção do ano de uma data, recebe uma data, retorna o ano (1582 a 9999)
int dt_ano(data d);
// obtenção do dia da semana, recebe uma data, retorna o dia da semana (1=domingo, 2=segunda .. 7=sábado)
int dt_dia_semana(data d);

// dias entre datas
// recebe duas datas
// retorna o número de dias da primeira até a segunda (pode ser negativo)
int dt_dias_entre_datas(data d1, data d2);

// soma de datas
// recebe uma data e um número de dias (que pode ser negativo)
// retorna a data que é tantos dias após a data fornecida.
// a data retornada deve ser destruída com dt_destroi após o uso
data dt_soma_data(data d, int dias);

#endif
