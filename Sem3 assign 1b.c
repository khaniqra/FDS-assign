//Pass two parameters to function as start and end and display all prime numbers between two intervals

#include <stdio.h>

int prime(int a, int b);
int main()
{
    int a,b;
    printf("Prime numbers!!\n");
    printf("Enter start number:");
    scanf("%d", &a);
    printf("Enter end number:");
    scanf("%d", &b);
    printf("Prime no between %d and %d are : \n",a,b);
    prime(a, b);
    return 0;
}

int prime(int a, int b)
{

    for (int i = a ; i <= b; i++)
    {
        int flag = 0;
        for (int j = 2; j <= (i / 2); j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}

