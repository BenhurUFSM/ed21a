## Prova final -- ed21a -- 9set2021

Você deve desenvolver, na linguagem C, as funções descritas abaixo.
O arquivo contendo as funções (e eventuais auxiliares) deve ser enviado por e-mail para `benhur+ed21a@inf.ufsm.br` antes das 10h30min.
O arquivo deve ter um comentário no início, identificando o autor.
Você deve permanecer conectado no discord, no canal individual, durante o tempo da prova.
Pode usar o canal geral de texto para chamar a atenção do professor.

Será avaliada, além da correção da solução, a organização do código.

A avaliação pode ser complementada por uma prova oral individual, em horário a combinar.

* * *

Joãozinho está desenvolvendo algoritmos para manipular sequências genéticas, armazenadas em uma árvore binária.
Em determinado experimento, ele necessita saber a profundidade na árvore onde se encontra a sequência com o maior número de genes.
Para isso, ele escreveu a função abaixo:
```c
   int prof_maior(no *arvore)
   {
     sequencia *maior = maior_sequencia(arvore);
     return profundidade_sequencia(arvore, maior);
   }
```
Infelizmente, ele está sem tempo para desenvolver as funções `maior_sequencia` e `profundidade_sequencia`, e pediu sua ajuda. Ele tem grande apreço pelo código que ele desenvolve, e não topa que a função dele seja alterada.

A árvore binária dele está baseada no tipo `no`, declarado como abaixo:
```c
   typedef struct s_no no;
   struct s_no {
     sequencia *seq; // valor armazenado neste no da arvore
     no *dir;        // ponteiro para o no contendo o filho direito (ou NULL)
     no *esq;        // ponteiro para o no contendo o filho esquerdo (ou NULL)
   };

   int compara_sequencias(sequencia *seq1, sequencia *seq2);
```

A função `maior_sequencia` deve retornar a maior sequência armazenada em algum nó da árvore. 
A função deve retornar `NULL` se a árvore estiver vazia.
Os nós na árvore não estão organizados em nenhuma ordem útil para essa busca.
Duas sequências podem ser comparadas com a função `compara_sequencias` (que já existe), que recebe duas sequências e retorna um inteiro com valor `1` se a primeira sequência for maior que a segunda, `2` se a segunda for maior que a primeira e `0` se forem iguais.
Sabe-se que não existem sequências iguais na árvore.

A função `profundidade_sequencia` retorna a profundidade na árvore do nó onde se encontra determinada sequência (ou `-1` se a sequência não existir na árvore).
A profundidade de um nó em uma árvore é a distância entre a raiz e esse nó.
A profundidade da raiz é 0; a profundidade dos filhos da raiz é 1; os netos da raiz têm profundidade 2 e assim por diante.
A mesma função `compara_sequencias` deve ser usada para decidir se a sequência em um nó é igual à procurada.

Para facilitar a sua vida, mas sem querer abrir os segredos do seu código, Joãozinho forneceu os arquivos abaixo, que contêm implementação *fake* mas funcional das funções que ele já desenvolveu. Esses arquivos não devem ser alterados.
Nessa implementação, se está usando strings no lugar de sequências.
Suas funções não devem levar isso em consideração, o tipo `sequencia` deve ser considerado opaco, você não pode acessar o valor referenciado por um `sequencia *`.

```c
   /* boneco.h */
   #ifndef BONECO_H
   #define BONECO_H

   typedef char sequencia;

   typedef struct s_no no;
   struct s_no {
     sequencia *seq; // valor armazenado neste no da arvore
     no *dir;        // ponteiro para o no contendo o filho direito (ou NULL)
     no *esq;        // ponteiro para o no contendo o filho esquerdo (ou NULL)
   };

   no *cria_no(sequencia *s, no *d, no *e);
   void imp_arv(no *a, int off);

   // funcoes existentes
   int compara_sequencias(sequencia *seq1, sequencia *seq2);
   int prof_maior(no *arvore);

   // funcoes a implementar
   sequencia *maior_sequencia(no *arv);
   int profundidade_sequencia(no *arv, sequencia *seq);

   #endif // BONECO_H
```

```c
   /* boneco.c */
   #include <string.h>
   #include <stdio.h>
   #include <assert.h>
   #include <stdlib.h>
   #include "boneco.h"

   no *cria_no(sequencia *s, no *d, no *e)
   {
     no *n = malloc(sizeof(*n));
     assert(n != NULL);
 
     n->seq = strdup(s);
     n->dir = d;
     n->esq = e;
 
     return n;
   }

   void imp_arv(no *a, int o)
   {
     if (a == NULL) {
       printf("%*s-\n", o, "");
       return;
     }
     printf("%*s%s\n", o, "", a->seq);
     imp_arv(a->esq, o+2);
     imp_arv(a->dir, o+2);
   }

   int compara_sequencias(sequencia *seq1, sequencia *seq2)
   {
     int l1, l2;
     l1 = strlen(seq1);
     l2 = strlen(seq2);
     if (l1 == l2) return 0;
     if (l1 > l2) return 1;
     return 2;
   }

   int prof_maior(no *arvore)
   {
     sequencia *maior = maior_sequencia(arvore);
     return profundidade_sequencia(arvore, maior);
   }
```

Uma possível função principal, para testar as funções está abaixo. Ela deve encontrar a altura 2.

```c
   /* main.c */

   #include <stdio.h>
   #include "boneco.h"

   int main()
   {
     no *arv;

     arv = cria_no("gat",
             cria_no("atac",
               cria_no("a",
                 NULL,
                 cria_no("ca", NULL, NULL)),
               cria_no("gattaca",
                 cria_no("tacat", NULL, NULL),
                 NULL)),
             cria_no("cataca", NULL, NULL));

     imp_arv(arv, 0);
     printf("\n\nprofundidade: %d\n", prof_maior(arv));
     return 0;
   }

   // so pra poder compilar
   sequencia *maior_sequencia(no *arv)
   {
     return NULL;
   }
   int profundidade_sequencia(no *arv, sequencia *seq)
   {
     return 0;
   }
```
