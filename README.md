# Como transformar sua árvore em uma imagem PNG (AED).

Testado com C++. Provavelmente funciona com C.

|Requisitos|Download|
| --- | --- |
| Graphviz* | [Windows ](https://graphviz.gitlab.io/_pages/Download/Download_windows.html) |
>*Programa que o Ivandré recomendou.

## Passo a passo

1- Após a instalação do Graphviz, é necessário incluir na variável de ambiente PATH do Windows o seguinte diretório:

```
C:\Program Files (x86)\Graphviz2.38\bin
```

>Nota: Se não souber o que isso significa, faça uma pesquisa rápida, pois é bem simples o procedimento.

2- Baixe o arquivo "grafico.h" deste repositório e o **coloque na mesma pasta que o arquivo .c ou .cpp onde está a implementação da sua árvore.**

3- Inclua a seguinte linha no cabeçário.

```C++
#include "grafico.h"
```

>3.1 ATENÇÃO: Não crie uma estrutura de NO, a seguinte estrutura já está inclusa no arquivo e é a única que irá funcionar.

```C++
typedef struct estrutura {
  int chave;
  estrutura *esq;
  estrutura *dir;
} NO;
```

Após isso, basta incluir o seguinte código:

```C++
FILE* arquivo = fopen("NOME_DO_AQUIVO.dot", "w");

gerarArvore(RAIZ_DE_SUA_ARVORE, arquivo);

fclose(arquivo);
```

Será gerado no diretório do executável um arquivo .dot (Não utilizo CodeBlocks então não sei o diretório exato, mas são poucas pastas então será tranquilo encontrar o arquivo. Se tiver dificuldades, use a busca do Windows).

Dentro desse diretório, execute a seguinte linha no cmd.

```
dot NOME_DO_ARQUIVO.dot -Tpng -o arvore.png
```

>Nota: substitua o NOME_DO_ARQUIVO pelo aquele qual você inseriu em seu programa. 

>Atenção: Para essa parte, é imprescindível que você tenha configurado a variável de ambiente pedida acima. Se mesmo tendo configurado o Windows não encontrar o comando, feche e abra o cmd novamente, ou reinicie seu computador. Caso o erro persista, revise seus passos.

Para não precisar continuamente executar esta linha, basta criar um arquivo .bat com ela e clicar sempre que quiser usar o programa.