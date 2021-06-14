#include <stdio.h>
#include "conjunto.h"

conjunto le_conjunto_de_arquivo(FILE *arq)
{
  // retorna um conjunto lido de um arquivo já aberto
  // o conjunto termina quando não conseguir converter a entrada em int
  // (FIXME: um tanto gambiarrento)
  conjunto cj = cj_cria();
  int n;
  while (fscanf(arq, "%d", &n) == 1) {
    cj_insere(cj, n);
  }
  return cj;
}
conjunto le_conjunto(char *nome)
{
  // retorna um conjunto lido do início de um arquivo com nome dado
  FILE *arq;
  arq = fopen(nome, "r");
  conjunto cj = le_conjunto_de_arquivo(arq);
  fclose(arq);
  return cj;
}

conjunto proxima_aposta(FILE *arq)
{
  // lê o próximo conjunto de um arquivo
  // (FIXME: gambiarra, os conjuntos são separados por '.', terminam por 'F')
  int c = fgetc(arq);
  if (c == 'F') {
    return NULL;
  }
  if (c != '.') {
    ungetc(c, arq);
  }
  return le_conjunto_de_arquivo(arq);
}

int main(void) {
  conjunto sorteio;
  conjunto aposta;
  sorteio = le_conjunto("sorteio");

  FILE *apostas = fopen("apostas", "r");
  while ((aposta = proxima_aposta(apostas)) != NULL) {
    conjunto inter = cj_intersecao(aposta, sorteio);
    int n = cj_num_elem(inter);
    printf("%d\n", n);
    if (n == 4) {
      printf("aposta com quadra\n");
    } else if (n == 5) {
      printf("aposta com quina\n");
    } else if (n == 6) {
      printf("aposta com sena\n");
    } else {
      printf("aposta perdedora\n");
    }
  }
}
