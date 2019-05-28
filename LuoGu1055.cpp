#include <stdio.h>

#include <stdlib.h>

 

int main()

{

    int a[9], i, sum = 0, j;

    char b;

    scanf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9]);

    scanf("-%c", &b);

    for (i = 0; i < 9; i++)

    {

        sum = sum + a[i] * (i + 1);

    }

    j = sum % 11;

    if (j == 10)

    {

        if (b == 'X')

            printf("Right");

        else

        {

            printf("%d-%d%d%d-%d%d%d%d%d-X", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);

        }

    }

    else

    {

        if (b == j + 48)

            printf("Right");

        else

        {

            printf("%d-%d%d%d-%d%d%d%d%d-%d", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], j);

        }

    }

    return 0;

}
