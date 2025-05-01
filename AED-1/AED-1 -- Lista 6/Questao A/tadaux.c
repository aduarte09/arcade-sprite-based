#include "tadstring.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct manipulastring
{
    char *str;
};
typedef manipulastring manipulastring;

manipulastring *criar()
{
    manipulastring *s = (manipulastring *)malloc(sizeof(manipulastring)); /*voc� n�o pode usar s.str porque s � um ponteiro para manipulastring
                                                                            e n�o um objeto da estrutura manipulastring. Para acessar membros de
                                                                            uma estrutura atrav�s de um ponteiro, voc� deve usar a seta ->.*/
    if (s != NULL)
    {
        s->str = (char *)calloc(100, sizeof(char));
    }
    return s;
}

void associa(manipulastring *s)
{
    int i, tamanho = 0;
    printf("\nDigite uma string: ");

    setbuf(stdin,NULL);
    fgets(s->str, 100, stdin);
    s->str[strcspn(s->str, "\n")] = '\0';

    for (i = 0; s->str[i] != '\0'; i++)
    {
        tamanho++;
    }

    s->str = (char*) realloc (s->str, tamanho * sizeof(char));
}

int calculatamanho(manipulastring *s)
{
    int i, cont = 0;

    for (i = 0; s->str[i] != '\0'; i++)
    {
        cont++;
    }

    return cont;
}

int contagem(manipulastring *s, char c)
{
    int i, cont = 0;

    for (i = 0; s->str[i] != '\0'; i++)
    {
        if(s->str[i] == c)
        {
            cont++;
        }
    }
    return cont;
}

void exibe(manipulastring *s)
{
    printf("\nA string digitada eh: %s", s->str);
}

