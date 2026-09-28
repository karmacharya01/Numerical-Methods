#include <stdio.h>

int main()
{
    int x[100], y[100];
    int size, i, j;
    float sum = 0, product, whenValue;

    printf("Enter the number of data points: ");
    scanf("%d", &size);

    printf("\nEnter x values:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    printf("\nEnter y values:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &y[i]);
    }

    printf("\nEnter the value of x to interpolate: ");
    scanf("%f", &whenValue);

    for (i = 1; i < size; i++)
    {
        for (j = 0; j < size - i; j++)
        {
            y[j] = (y[j + 1] - y[j]) / (x[j + i] - x[j]);
        }
        product *= (whenValue - x[i - 1]);
        sum += y[0] * product;
    }
    printf("Answer:%f", sum);
    return 0;
}

// Algorithm

// Step 1 : START
// Step 2 : Initalize sum =0, product = 1
// Step 3 : Input the data sets of x ,y and value of x to find y
// Step 4 : for i = 1;i<n;
//             for j = 0; j < n
//                 y[j] = (y[j + 1] - y[j]) / (x[j + i] - x[j]);
//             product *= (a - x[i - 1]);
//             sum += y[0] * product;
// Step 5 : Display the value
// Step 6 : STOP