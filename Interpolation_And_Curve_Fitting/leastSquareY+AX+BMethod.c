#include <stdio.h>
#include <math.h>

int main()
{
    int x[100], y[100];
    int size, i, check;
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    float a, b, whenValue, value;

    printf("Enter the number of data points: ");
    scanf("%d", &size);

    printf("Enter x values:\n");
    for (i = 0; i < size; i++)
        scanf("%d", &x[i]);

    printf("Enter y values:\n");
    for (i = 0; i < size; i++)
        scanf("%d", &y[i]);

    printf("Do you wamt to find Equation or Value. \nType 1 for equation and 2 for value : ");
    scanf("%d", &check);

    if (check == 2)
    {
        printf("Enter the value of x to interpolate: ");
        scanf("%f", &whenValue);
    }

    for (i = 0; i < size; i++)
    {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += pow(x[i], 2);
    }

    b = ((size * sumXY) - (sumX * sumY)) /
        ((size * sumX2) - pow(sumX, 2));

    a = (sumY / size) - b * (sumX / size);

    if (check == 2)
    {
        value = a + b * whenValue;
        printf("Value of Y = %.3f\n", value);
    }
    else
    {
        printf("Regression Equation:\n");
        printf("Y = %.3f + %.3fX\n", a, b);
    }

    return 0;
}

// Algorithm

// Step 1 : START
// Step 2 : Initialize sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0
// Step 3 : Input the data sets of x ,y and value of x to find y
// Step 4 : for i = 0;i<n;
//               sumX += x[i];
//               sumY += y[i];
//               sumXY += x[i] * y[i];
//               sumX2 += pow(x[i], 2);
// Step 5 : Calculate  b = ((size * sumXY) - (sumX * sumY)) / ((size * sumX2) - pow(sumX, 2));
// Step 6 : Calculate  a = (sumY / size) - b * (sumX / size);
// Step 7 : Display the value
// Step 8 : STOP