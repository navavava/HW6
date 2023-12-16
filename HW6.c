#include <stdio.h>
#include <math.h>

int solver(float a, float b, float c, float *root1, float *root2);
int main()
{
    float a, b, c, root1, root2;

    int n;
    printf("enter the first coefficient:\n");
    scanf("%f", &a);
    printf("enter the second coefficient:\n");
    scanf("%f", &b);
    printf("enter the constant:\n");
    scanf("%f", &c);

    if (a || b)
    {

        n = solver(a, b, c, &root1, &root2);
        if (n == 2)
        {
            printf("first root:\n%f\nsecond root:\n%f\n", root1, root2);
        }
        else if (n == 1)
        {
            printf("root:\n%f", root1);
        }
    }
    else
    {
        printf("error! uncalculable coefficients.");
    }

    return 0;
}

int solver(float a, float b, float c, float *root1, float *root2)
{
    float delta = (b * b) - 4 * a * c;
    int n;
    if (a)
    {

        *root1 = (-b + sqrt(delta)) / 2 * a;
        *root2 = (-b - sqrt(delta)) / 2 * a;

        if (delta > 0)
        {
            n = 2;
            printf("there are 2 roots\n");
        }
        else if (delta == 0)
        {
            n = 1;
            printf("there is one root\n");
        }
        else
        {
            n = 0;
            printf("there are no real roots\n");
        }
    }
    else
    {
        n = 1;
        printf("there is one root\n");
        *root1 = (-c / b);
    }
    return n;
}