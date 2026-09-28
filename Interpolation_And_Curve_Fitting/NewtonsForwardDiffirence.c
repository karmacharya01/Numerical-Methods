#include <stdio.h>

int main()
{
    int x[100], y[100];
    int size, i, j;
    float sum, product = 1, whenValue, h, s;

    printf("Enter the number of data points: ");
    scanf("%d", &size);

    printf("Enter x values:\n");
    for (i = 0; i < size; i++)
        scanf("%d", &x[i]);

    printf("Enter y values:\n");
    for (i = 0; i < size; i++)
        scanf("%d", &y[i]);

    printf("Enter the value of x to interpolate: ");
    scanf("%f", &whenValue);

    h = x[1] - x[0];
    s = (whenValue - x[0]) / h;

    sum = y[0];

    for (i = 1; i < size; i++)
    {
        for (j = 0; j < size - i; j++)
        {
            y[j] = y[j + 1] - y[j];
        }

        product *= s / i;
        s--;
        sum += product * y[0];
    }

    printf("\nInterpolated value y(%.2f) = %.4f\n", whenValue, sum);

    return 0;
}

// Algorithm

// Step 1 : START
// Step 2 : Initalize sum =0, product = 1
// Step 3 : Input the data sets of x ,y and value of x to find y
// Step 4 : find the uniform diffirence between 2 points of x. for eg(x[1] - x[0];)
//          and s = (a - x[0]) / h;
// Step 5 : for i = 1;i<n;
//             for j = 0; j < n
//                  y[j] = y[j + 1] - y[j];
//             product *= s / i;
//             s--;
//             sum += product * y[0];
// Step 6 : Display the value
// Step 7 : STOP