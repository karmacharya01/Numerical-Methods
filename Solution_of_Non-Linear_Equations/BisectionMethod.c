#include <stdio.h>
#include <math.h>

float Equation(float x)
{
    return pow(x, 2) - 10; // Equation goes here
}

int main()
{
    float a, b, error, midpoint = 0;
    int i = 1, maxIteration;

    while (1)
    {
        printf("Enter the value of a: ");
        scanf(" %f", &a);

        printf("Enter the value of b: ");
        scanf(" %f", &b);

        if (Equation(a) * Equation(b) < 0)
            break;
 
        printf("The root doesn't lie within this interval.\n");
    }

    printf("Enter the tolerable error: ");
    scanf("%f", &error);

    printf("Enter the maximum iterations: ");
    scanf("%d", &maxIteration);

    while ((fabs(b - a) / 2 >= error) && (i <= maxIteration))
    {
        midpoint = (a + b) / 2;

        printf("Iteration %d : %.6f\n", i, midpoint);

        if (Equation(a) * Equation(midpoint) < 0)
            b = midpoint;
        else
            a = midpoint;

        i++;
    }

    printf("\nThe approximate root is %.6f\n", midpoint);

    return 0;
}


// Algorithm

// Step 1 : START
// Step 2 : Define the function for given Equation.
// Step 3 : Input interval bounds a and b , tolerable error, and maximum iterations.
// Step 4 : If (Equation(a) times Equation(b) >= 0, display "The root doesn't lie within this interval" and repeat Step 3.
// Step 5 : Calcualte the midpoint ((a+b)/2)
// Step 6 : Print the current iteration number and the midpoint
// Step 7 : if (Equation(a) * Equation(midpoint) < 0) set b = midpoint Otherwise a = midpoint
// Step 8 : Repeat the step 5 to 7 while ((fabs(b - a) / 2 >= error) && (i <= maxIteration))
// Step 9 : Print the final approximate root.
// Step 10 : STOP