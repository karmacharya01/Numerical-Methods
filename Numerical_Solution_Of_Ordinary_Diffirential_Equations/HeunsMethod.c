// Heun's Method
#include <stdio.h>

float f(float x, float y)
{
    return -x / y; // Differential equation: dy/dx = -x/y
}

int main()
{
    float x0, y0, xn, h, m1, m2;
    int n;

    // User inputs
    printf("Enter initial value of x (x0): ");
    scanf("%f", &x0);

    printf("Enter initial value of y (y0): ");
    scanf("%f", &y0);

    printf("Enter the value of x at which y is required (xn): ");
    scanf("%f", &xn);

    printf("Enter the number of steps (n): ");
    scanf("%d", &n);

    // Calculate step size
    h = (xn - x0) / n;

    printf("\n--- Calculation Steps ---\n");
    while (x0 < xn)
    {
        printf("y(%g) = %f\n", x0, y0);
        m1 = f(x0, y0);              // Slope at the beginning of interval
        m2 = f(x0 + h, y0 + h * m1); // Estimated slope at the end of interval
        y0 += (h / 2.0) * (m1 + m2); // Update y using average slope
        x0 += h;                     // Move to next x
    }
    printf("y(%g) = %f\n", x0, y0); // Final result

    return 0;
}
// Algorithm

// Step 1: Start
// Step 2: Define the function f(x, y) = -x / y representing the differential equation dy/dx.
// Step 3: Read the initial values x0, y0, the target value xn, and the number of steps n from the user.
// Step 4: Calculate the step size using the formula: h = (xn - x0) / n.
// Step 5: Repeat the following steps while x0 < xn:
//     a. Print the current values of x0 and y0.
//     b. Calculate the initial slope: m1 = f(x0, y0).
//     c. Calculate the predictor slope: m2 = f(x0 + h, y0 + h * m1).
//     d. Update the value of y using the average of both slopes: y0 = y0 + (h / 2) * (m1 + m2).
//     e. Increment the value of x by the step size: x0 = x0 + h.
// Step 6: Print the final calculated value of y0 at x = xn.
// Step 7: Stop