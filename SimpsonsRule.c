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
    printf("Enter number of subintervals (n, must be an EVEN number): ");
    scanf("%d", &n);

    if (n % 2 != 0) 
    {
        printf("Error: The number of subintervals must be an even number.\n");
        return 1; // Exit program
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
        
        if (i % 2 != 0) 
            sum += 4 * func(x); // Odd indices multiplied by 4
        else 
            sum += 2 * func(x); // Even indices multiplied by 2
    }

    // 6. Apply final Simpson's 1/3 scaling
    integral = (h / 3) * sum;

    // 7. Output result
    printf("\nThe integral is: %g\n", integral);

    return 0;
}


Step 1 : Start
Step 2 : Define the function func(x) = x * x.
Step 3 : Read user inputs for lower limit (a), upper limit (b), and number of intervals (n).
Step 4 : Check if n is even (n % 2 != 0). display an error message and Stop.
Step 5 : Calculate the step size: h = (b - a) / n.
Step 6 : Initialize total area sum with boundaries: sum = func(a) + func(b).
Step 7 : Loop an index i from 1 to n - 1:
            Calculate current coordinate: x = a + i * h.
            If i is odd (i % 2 != 0), then sum = sum + 4 * func(x).
            Else (i is even), then sum = sum + 2 * func(x).
Step 8 : Calculate the final integration value: integral = (h / 3) * sum.
Step 9 : Print the final calculated integral value.
Step 10 : Stop