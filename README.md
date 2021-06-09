# ed21a - Estruturas de dados
turmas SI1 e CC2, primeiro semestre 2021\
ELC1066 DLSC/CT/UFSM\
professor: Benhur Stein 
([benhur+ed21a@inf.ufsm.br](mailto:benhur%2bed21a@inf.ufsm.br))\
segundas e quartas, 10h30


## Desenvolvimento da disciplina

Os canais de comunicação entre o professor e os alunos são esta página (<https://github.com/BenhurUFSM/ed21a>), o servidor discord (<https://discord.gg/nBKdMSBAVj>) e e-mail para [benhur+ed21a@inf.ufsm.br](mailto:benhur%2bed21a@inf.ufsm.br).
Outros canais que eventualmente sejam criados serão comunicados aqui.

Todos os alunos **devem** enviar um e-mail inicial para o professor para confirmar o seu endereço de e-mail, e **devem** se inscrever no servidor discord.

O e-mail pode ser usado para o envio de perguntas, exercícios, reclamações, sugestões, críticas e o que mais for, durante todo o período em que durar a disciplina.

Esta página concentrará os assuntos vistos em aula, a descrição de exercícios e trabalhos, avaliações, etc. Ela estará sendo aumentada/atualizada durante todo o semestre. Ela é o canal mais oficial de informações sobre a disciplina.

A disciplina será desenvolvida de uma forma bastante prática, a principal forma de avaliação dos alunos será através de exercícios, principalmente o desenvolvimento de pequenos programas de computador, a serem enviados para o professor. No final do semestre, deve ser desenvolvido um trabalho final um pouco mais complexo.

##  Encontros síncronos

Encontros realizados com uso do discord, nos horários oficiais da disciplina.

|    N |   data | assunto
| ---: | :----: | :--------
|    1 |  19mai | introdução
|    2 |  24mai | revisão de C
|    3 |  26mai | [revisão de C (cont)](https://github.com/BenhurUFSM/ed21a/blob/main/Assuntos/03.md)
|    4 |  31mai | resolução dos exercícios da 03 (a [página](https://github.com/BenhurUFSM/ed21a/blob/main/Assuntos/03.md) foi alterada).
|    5 |   2jun | cont. da revisão dos exercícios; tipos abstratos de dados ([TAD](https://github.com/BenhurUFSM/ed21a/blob/main/Assuntos/05.md))
|    6 |   7jun | exemplo de implementação em C do TAD [data](https://github.com/BenhurUFSM/ed21a/blob/main/Assuntos/06.md)
|    - |   9jun | jacaré (mas fiz uma [pagininha](https://github.com/BenhurUFSM/ed21a/blob/main/Assuntos/t1.md) sobre o t1)

## Exercícios (revisão de C)

1. Os nomes dos alunos na planilha da disciplina estão em maiúsculas, e eu gostaria que ficassem em minúsculas, que é mais bonito e ocupa menos espaço (visualmente). Selecionando todos os nomes e ctrl-c, ctrl-v em um editor de textos, tem-se os nomes, um por linha, em um arquivo. Faça um programa que lê esse arquivo, converte tudo para minúsculas, grava o resultado em outro arquivo.
   A conversão deve manter a primeira letra de cada palavra em maiúscula, exceto em "de", "dos" etc.
   O arquivo deve ser lido completamente para um vetor de linhas, depois alterado, depois os dados devem ser gravados.
   Cada linha pode ser um vetor de `char` de tamanho constante (o maior nome tem 34 caracteres, acho).
   O vetor de pode ser de tamanho constante (temos 26 alunos).
   O programa deve ser dividido em funções. Deve ter no mínimo uma função para converter uma string (recebe um `char *` e altera a string), uma função para ler o arquivo (recebe o nome do arquivo a ler e o vetor a preencher), uma função para gravar o arquivo resultado.
2. Altere o programa para incluir alocação dinâmica do vetor. Implemente uma função que recebe o nome de um arquivo e retorna o número de linhas que ele contém.
3. Altere o programa para fazer a alocação dinâmica das strings. O vetor agora será um vetor de `char *`; cada string deve ser alocada com o tamanho exato necessário. Sugiro fazer uma função que recebe um `FILE *` de um arquivo aberto, lê uma linha desse arquivo, aloca memória do tamanho certo para essa linha, copia a linha para essa memória, retorna o `char *` dessa região de memória.

## Exercícios e trabalhos

|     N |    prazo | assunto
| ----: | -------: | :-----------
|    t1 | 9jun10h | ver [aula 3](https://github.com/BenhurUFSM/ed21a/blob/main/Assuntos/03.md)
|    t2 | 16jun10h | ver [aula 6](https://github.com/BenhurUFSM/ed21a/blob/main/Assuntos/06.md)


## Ementa

Ver [aqui](https://www.ufsm.br/ementario/disciplinas/elc1066/).

## Bibliografia

Os livros abaixo estão disponíveis no [minha biblioteca](https://www.ufsm.br/orgaos-suplementares/biblioteca/e-books-2/), acessível aos alunos da UFSM.

Estruturas de Dados e Seus Algoritmos - Jayme Szwarcfiter e Lilian Markenzon

Estruturas de Dados - Nina Edelweiss e Renata Galante

Estruturas de Dados em C, Uma Abordagem Didática - Sílvio Pereira


<!--
## Material Auxiliar
-->

## Avaliações etc

Veja a [planilha](https://docs.google.com/spreadsheets/d/1nILaDGpw5bubqg4wCa-9ujhaFy-4n7DXm3zr6samI_0/edit?usp=sharing)
