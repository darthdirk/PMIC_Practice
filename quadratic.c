#include <stdio.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    double real;
    double imag;
} Complex;


int32_t calculate_discriminant(int16_t a, int16_t b, int16_t c) {
    return ((b * b)+(-4 * (a) * (c)));
} 

void calculate_real_roots(int16_t a, int16_t b, int16_t c, double* root0, double* root1) {
    double discriminant = calculate_discriminant(a, b, c);
    double sqrtDiscriminant = sqrt(discriminant);

    *root0 = ((-b + sqrtDiscriminant) / (2.0 * a));
    *root1 = ((-b - sqrtDiscriminant) / (2.0 * a));
}

double calculate_real_root(int16_t a, int16_t b) {
    return (-b / (2.0 * a));

}

void calculate_complex_roots(int16_t a, int16_t b, int16_t c, Complex* root0, Complex* root1) {
    double discriminant = ((double)(b * b)+(-4 * (a) * (c)));
    double realPart = (-b / (2.0 * a));
    double imagPart = (sqrt(-discriminant) / (2.0 * a));

    root0->real = realPart;
    root0->imag = imagPart;
    root1->real = realPart;
    root1->imag = -imagPart;
}

int main() {
    int16_t a, b, c;
    printf("Enter three coefficients with a space as a seperator a, b, c: ");
    scanf("%hd %hd %hd", &a, &b, &c);

    int32_t discriminant = calculate_discriminant(a, b, c);

    if (discriminant > 0){
        printf("The discriminant has two real roots!\n Discriminant: %d\n", discriminant);
        double root0, root1;
        calculate_real_roots(a, b, c, &root0, &root1);
        printf("Real root0: %f\nReal root1: %f\n", root0, root1);

    } else if (discriminant == 0) {
        printf("The discriminant has a single real root!\n Discriminant: %d\n", discriminant);
        double root = calculate_real_root(a, b);
        printf("Real root: %f\n", root);

    } else if (discriminant < 0) {
        printf("The discriminant has two complex roots!\n Discriminant: %d\n", discriminant);
        Complex root0, root1;
        calculate_complex_roots(a, b, c, &root0, &root1);
        printf("Complex root0: %f + %fi\n", root0.real, root0.imag);
        printf("Complex root1: %f + %fi\n", root1.real, root1.imag); 
    } else {
        printf ("bad calculation");

    }
    return 0;
}