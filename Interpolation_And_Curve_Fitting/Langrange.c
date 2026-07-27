#include <stdio.h>

int main()
{
    float x[100], y[100];
    int size, i, j;
    float sum = 0, product, whenValue;

    printf("Enter the number of data points: ");
    scanf("%d", &size);

    printf("\nEnter x values:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%f", &x[i]);
    }

    printf("\nEnter y values:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%f", &y[i]);
    }

    printf("\nEnter the value of x to interpolate: ");
    scanf("%f", &whenValue);

    for (i = 0; i < size; i++)
    {
        product = 1;

        for (j = 0; j < size; j++)
        {
            if (i != j)
            {
                product *= (whenValue - x[j]) / (x[i] - x[j]);
            }
        }

        sum += product * y[i];
    }

    printf("\nInterpolated value at x = %.2f is %.2f\n", whenValue, sum);

    return 0;
}

// Algorithm

// Step 1 : START
// Step 2 : Initalize sum =0
// Step 3 : Input the data sets of x ,y and value of x to find y
// Step 4 : for i = 0;i<n;
//             Initalize product = 1
//             for j = 0; j < n
//                 if i != j
//                     product *= (a - x[j]) / (x[i] - x[j]);
//             sum += product * y[i];
// Step 5 : Display the value
// Step 6 : STOP

