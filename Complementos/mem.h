#ifndef _mem_h_
#define _mem_h_

// Conjunto de funções simples para auxiliar na depuração na alocação de memória
// Use-as no lugar de malloc, realloc e free
//                                             ed21a, ufsm

#include <stdbool.h>

// funcoes auxiliares -- nao use
void *m_aloca_mesmo(int nbytes, char *funcao, int linha);
void *m_realoca_mesmo(void *ptr, int nbytes, char *funcao, int linha);
void m_libera_mesmo(void *ptr, char *funcao, int linha);

// m_aloca -- use em vez de malloc.
// ela vai coletar as informacoes de alocacao
#define m_aloca(nbytes) m_aloca_mesmo(nbytes, (char *)__func__, __LINE__)

// m_realoca -- use em vez de realloc.
// ela vai coletar as informacoes de alocacao
#define m_realoca(ptr, nbytes) m_realoca_mesmo(ptr, nbytes, (char *)__func__, __LINE__)

// m_libera -- use em vez de free.
// ela vai coletar informacoes de alocacao
#define m_libera(ptr) m_libera_mesmo(ptr, (char *)__func__, __LINE__)

// use para verificar se ptr é uma regiao que foi alocada com m_aloca e
// aind nao liberada
bool m_verif(void *ptr);

// chame esta funcao para iimprimir um relatorio resumido de alocacoes
void m_relat(void);

// chame esta funcao para um relatorio mais completo
void m_relatorio_grande(void);

#endif // _mem_h_
