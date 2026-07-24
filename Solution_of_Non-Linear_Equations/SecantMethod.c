#include <stdio.h>
#include <math.h>

float Equation(float x)
{
    return x * x - 10;
}

int main()
{
    float X0, X1, X2, tolerableError, error;
    int maxIteration, count = 1;

    printf("Enter first initial value (X0): ");
    scanf("%f", &X0);

    printf("Enter second initial value (X1): ");
    scanf("%f", &X1);

    printf("Enter the tolerable error: ");
    scanf("%f", &tolerableError);

    printf("Enter the maximum iterations: ");
    scanf("%d", &maxIteration);

    printf("\n--- Iterations ---\n");
    do
    {
    
        if (fabs(Equation(X1) - Equation(X0)) < 0.000001)
        {
            printf("Error: Division by zero encountered. Method fails.\n");
            exit(1);
        }

        // Secant Formula
        X2 = X1 - (Equation(X1) * (X1 - X0)) / (Equation(X1) - Equation(X0));

        printf("Iteration %d : X = %.6f\n", count, X2);

        error = fabs(X2 - X1); 

    
        X0 = X1;
        X1 = X2;
        count++;

    } while (error > tolerableError && count <= maxIteration);

    printf("\nApproximate Root = %.6f\n", X2);

    return 0;
}

// Algorithm

// Step 1 : START
// Step 2 : Define the function for given Equation.
// Step 3 : Input initial valuse of X0 and X1, tolerable error, and maximum iterations.
// Step 4 : while (error > tolerableError && count <= maxIteration)
//              Check Division by Zero: If Equation(X1) - Equation(X0) < 0.000001, print an error message and terminate the program.
//              Calculate the X2 = X1 - (Equation(X1) * (X1 - X0)) / (Equation(X1) - Equation(X0))
//              Print the current iteration number and the value of X2.
//              Calculate Error: Set error = fabs(X2 - X1).
//              Update Values: Assign X0 = X1 and X1 = X2.
//              Increment the iteration counter count by 1.
// Step 5 : Print the final approximate root.
// Step 6 : STOP