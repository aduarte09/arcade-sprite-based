#include <stdio.h>

int main()
{
    printf("Entre com o valor: ");
    int n;
    scanf("%d", &n);
    int i, acc=1; //Como o acc nao tinha valor de inicializa��o, foi poss�vel visualizar no debug que estava armazenado lixo nele, ou seja, foi necess�rio atribuir o valor 1 para que funcionasse.
    for (i=n; i>0; i--)
        acc = acc * i;
    printf("O valor do fatorial de %d eh %d", n, acc);
}
