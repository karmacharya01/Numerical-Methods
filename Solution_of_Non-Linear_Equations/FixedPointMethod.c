#include <stdio.h>
#include <math.h>

float Equation(float x)
{
    return x * x - 10;
}

float Derivative(float x)
{
    return 2 * x;
}

int main()
{
    float X0, X1, tolerableError, error;
    int maxIteration, count = 0;

    printf("Enter the initial value of X0: ");
    scanf("%f", &X0);

    printf("Enter the tolerable error: ");
    scanf("%f", &tolerableError);

    printf("Enter the maximum iterations: ");
    scanf("%d", &maxIteration);

    do
    {
        X1 = X0 - Equation(X0) / Derivative(X0);

        printf("Iteration %d : X = %.6f\n", count, X1);

        error = fabs((X1 - X0) / X1);

        X0 = X1;
        count++;

    } while (fabs(error) > tolerableError && count <= maxIteration);

    printf("\nApproximate Root = %.6f\n", X1);

    return 0;
}

// Algorithm

// Step 1 : START
// Step 2 : Define the function for given Equation and its Derivatives.
// Step 3 : Input initial value of X0, tolerable error, and maximum iterations.
// Step 4 : Calcualte the X1 = X0 - Equation(X0) / Derivative(X0)
// Step 5 : Print the current iteration number and the midpoint
// Step 6 : Calculate the relative error using the formula: error = fabs((X1 - X0) / X1);
// Step 7 : Update the previous guess by setting X0 = X1, and increment the iteration counter by 1
// Step 8 : If |error| > tolerableError and count <= maxIteration, loop back to Step 4
// Step 9 : Print the final approximate root.
// Step 10 : STOP