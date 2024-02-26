#ifndef FILAENCADEADA_H_INCLUDED
#define FILAENCADEADA_H_INCLUDED

typedef struct fila fila;

fila *criar ( );
void limpar (fila *f);

int inserir (fila *f, int numero);
int remover (fila *f, int *numero);
void mostrar (fila *f);
fila *intercalada (fila *a, fila *b);
int remover_negativos (fila *f);

int tamanho (fila *f);
int fila_vazia (fila *f);
int fila_cheia (fila *f);

#endif // FILAENCADEADA_H_INCLUDED
