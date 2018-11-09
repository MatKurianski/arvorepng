// NOTA:

// O código não me pertence, embora eu o tenha modificado para deixá-lo mais 
// legível para qualquer interessado em estudá-lo.

// Se caiu aqui e não sabe o que está fazendo, sugiro que apenas feche este arquivo e leia
// as instruções no README.

// Ass: Matheus A. Kurianski

#include <stdio.h>

typedef struct estrutura {
  int chave;
  estrutura *esq;
  estrutura *dir;
} NO;

void NullPointer(int chave, int nullcount, FILE* stream) {
  fprintf(stream, "    null%d [shape=point];\n", nullcount);
  fprintf(stream, "    %d -> null%d;\n", chave, nullcount);
}

void createNode(NO* arvore, FILE* stream) {
  static int nullcount = 0;

  if (arvore->esq) {
    fprintf(stream, "    %d -> %d;\n", arvore->chave, arvore->esq->chave);
    createNode(arvore->esq, stream);
  } else NullPointer(arvore->chave, nullcount++, stream);

  if (arvore->dir) {
    fprintf(stream, "    %d -> %d;\n", arvore->chave, arvore->dir->chave);
    createNode(arvore->dir, stream);
  } else NullPointer(arvore->chave, nullcount++, stream);
}

void gerarArvore(NO* tree, FILE* stream) {
  fprintf(stream, "digraph BST {\n");
  fprintf(stream, "    node [fontname=\"Arial\" shape=\"doublecircle\"];\n");

  if (!tree) fprintf(stream, "\n");
  else if (!tree->dir && !tree->esq) fprintf(stream, "    %d;\n", tree->chave);
  else createNode(tree, stream);

  fprintf(stream, "}\n");
}