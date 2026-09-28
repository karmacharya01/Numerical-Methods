// Simpson Rule
#include <stdio.h>

// Define the function to integrate: f(x) = x^2
float func(float x)
{
    return x * x;
}

int main()
{
    float a, b, h, integral;
    int n, i;

    // 1. Get user input for boundaries
    printf("Enter lower limit of integration (a): ");
    scanf("%f", &a);

    printf("Enter upper limit of integration (b): ");
    scanf("%f", &b);

    // 2. Get and validate user input for subintervals
    printf("Enter number of subintervals (n, must be a multiple of 3): ");
    scanf("%d", &n);

    if (n % 3 != 0)
    {
        printf("Error: The number of subintervals must be a multiple of 3.\n");
        return 1; // Exit the program with an error code
    }

    // 3. Calculate step size (with proper parentheses)
    h = (b - a) / n;

    // 4. Initialize sum with boundary values
    float sum = func(a) + func(b);

    // 5. Loop through internal points
    for (i = 1; i < n; i++)
    {
        // Calculate the specific x coordinate for the current step
        float x = a + i * h;

        if (i % 3 == 0)
            sum += 2 * func(x);
        else
            sum += 3 * func(x);
    }

    // 6. Apply final Simpson's 3/8 scaling
    integral = (3 * h / 8) * sum;

    // 7. Output result
    printf("\nThe integral is: %g\n", integral);

    return 0;
}

// Algorithm
// Step 1 : Start
// Step 2 : Define the function f(x) to integrate.
// Step 3 : Input lower limit (a), upper limit (b), and number of intervals.
// Step 4 : IF (n MOD 3 != 0) THEN
//                 Print "Error: The number of subintervals must be a multiple of 3."
//                 TERMINATE / EXIT PROGRAM
// Step 5 : Calculate step size: h = (b - a) / n

// Step 6 : Initialize sum with outer boundary points:
//              sum = f(a) + f(b)

// Step 7 :  FOR i = 1 TO (n - 1) DO
//                  Calculate current position: x = a + i * h
//                  IF (i MOD 3 == 0) THEN
//                      sum = sum + 2 * f(x)
//                  ELSE
//                      sum = sum + 3 * f(x)
// Step 8 :  Calculate final integrated area:
//              integral = (3 * h / 8) * sum
// Step 9 : Print integral
// Step 10 : STOP