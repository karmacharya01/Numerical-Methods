#include <stdio.h>
#include <math.h>

float Equation(float x)
{
    return pow(x, 2) - 10;
}

float Derivative(float x)
{
    return 2 * x;
}

int main()
{
    float X0, X1, tolerableError, error;
    int maxIteration, count = 1;

    printf("Enter the initial value of X0: ");
    scanf("%f", &X0);

    printf("Enter the tolerable error: ");
    scanf("%f", &tolerableError);

    printf("Enter the maximum iterations: ");
    scanf("%d", &maxIteration);

    printf("\n--- Iterations ---\n");
    do
    {
        // Adjustment 1: Check for zero derivative to prevent division by zero
        if (Derivative(X0) == 0.0)
        {
            printf("Error: Derivative is zero. No solution found.\n");
            exit(1);
        }

        X1 = X0 - Equation(X0) / Derivative(X0);

        printf("Iteration %d : X = %.6f\n", count, X1);

        error = fabs(X1 - X0); // Adjustment 2: Standard absolute error calculation

        X0 = X1;
        count++;
    } while (fabs(error) > tolerableError && count <= maxIteration);

    printf("\nApproximate Root = %.6f\n", X1);

    return 0;
}

// Step 1 : START
// Step 2 : Define the function for given Equation and its Derivatives.
// Step 3 : Input initial value of X0, tolerable error, and maximum iterations.
// Step 4 : Initialize the counter count = 1.
// Step 5 : Check if the derivative at X0 is zero. If Derivative (X0) = 0, print an error message and stop.
// Step 6 : Calcualte the X1 = X0 - Equation(X0) / Derivative(X0)
// Step 7 : Print the current iteration number and the value of X1
// Step 8 : Calculate the relative error using the formula: error = fabs(X1 - X0)
// Step 9 : Update the previous guess by setting X0 = X1, and increment the iteration counter by 1
// Step 10 : If |error| > tolerableError and count <= maxIteration, loop back to Step 4
// Step 11 : Print the final approximate root.
// Step 12 : STOP