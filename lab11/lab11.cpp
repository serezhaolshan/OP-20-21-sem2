#include <stdio.h>
#include <conio.h>

int minimal(int* array, int size)
{
    int l, r, k;

    if (size == 1) return *array;

    l = minimal(array, k = size >> 1);
    r = minimal(array + k, size - k);

    return l < r ? l : r;
}

void main(void)
{
    int i;
    int a[10];

    for (i = 0; i < 10; i++)
    {
        printf("Vvedite znachenie elemnte %d massiva a: ", i);
        scanf("%d", &a[i]);
    }
    printf("Minimalnoe znachenie massiva = %d", minimal(a, 10));
    getch();
}