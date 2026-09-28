#include <stdio.h>

// Define the differential equation dy/dx = f(x, y)
float f(float x, float y) {
    return x + y; // Example: dy/dx = x + y
}

int main() {
    float x0, y0, xn, h, slope;
    int n, i;

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
    printf("x0 = %.4f, y0 = %.4f\n", x0, y0);

    // Euler's Method Loop
    for (i = 0; i < n; i++) {
        slope = f(x0, y0);      // Calculate the slope at the current point
        y0 = y0 + h * slope;    // Calculate the next y value
        x0 = x0 + h;            // Increment x by step size

        printf("x%d = %.4f, y%d = %.4f\n", i + 1, x0, i + 1, y0);
    }

    // Final result
    printf("\nThe approximate value of y at x = %.4f is: %.4f\n", xn, y0);

    return 0;
}

// Step 1: Start
// Step 2: Define the function f(x, y) = x + y representing the differential equation dy/dx.
// Step 3: Read the initial values x0, y0, the target value xn, and the number of steps n from the user.
// Step 4: Calculate the step size using the formula: h = (xn - x0) / n.
// Step 5: Initialize a loop counter i = 0.
// Step 6: Repeat the following steps while i < n:
//     a. Calculate the current slope: slope = f(x0, y0).
//     b. Update the value of y: y0 = y0 + h * slope.
//     c. Increment the value of x: x0 = x0 + h.
//     d. Print the values of x0 and y0 for the current iteration.
//     e. Increment the loop counter i by 1.
// Step 7: Print the final approximated value of y0 at x = xn.
// Step 8: Stop