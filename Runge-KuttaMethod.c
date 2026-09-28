// RK4 Method
#include <stdio.h>

float f(float x, float y)
{
    return x * x + y * y; // Differential equation: dy/dx = x^2 + y^2
}

int main()
{
    float x0, y0, xn, h, m1, m2, m3, m4;
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
        
        // Calculate the four RK4 increments
        m1 = f(x0, y0);
        m2 = f(x0 + h / 2.0, y0 + (h / 2.0) * m1);
        m3 = f(x0 + h / 2.0, y0 + (h / 2.0) * m2);
        m4 = f(x0 + h, y0 + h * m3);
        
        // Update y using the weighted average of the slopes
        y0 += (h / 6.0) * (m1 + 2 * m2 + 2 * m3 + m4);
        
        // Increment x by the step size
        x0 += h;
    }
    printf("y(%g) = %f\n", x0, y0); // Final result

    return 0;
}

// Algorithm

// Step 1: Start
// Step 2: Define the function f(x, y) = xx + yy representing the differential equation dy/dx.
// Step 3: Read the initial values x0, y0, the target value xn, and the number of steps n from the user.
// Step 4: Calculate the step size using the formula: h = (xn - x0) / n.
// Step 5: Repeat the following steps while x0 < xn:
//     a. Print the current values of x0 and y0.
//     b. Calculate the first slope increment: m1 = f(x0, y0).
//     c. Calculate the second slope increment: m2 = f(x0 + h / 2, y0 + h / 2 * m1).
//     d. Calculate the third slope increment: m3 = f(x0 + h / 2, y0 + h / 2 * m2).
//     e. Calculate the fourth slope increment: m4 = f(x0 + h, y0 + h * m3).
//     f. Update the value of y using the weighted average formula: y0 = y0 + (h / 6) * (m1 + 2m2 + 2m3 + m4).
//     g. Increment the value of x by the step size: x0 = x0 + h.
// Step 6: Print the final calculated value of y0 at x = xn.
// Step 7: Stop