#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main(int argc, char *argv[]) {

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);
    double solution_numerator = 0;
    double solution_denominator = 0;
    double solution = 0;
    double negative_solution_numerator = 0;
    double negative_solution_denominator = 0;
    double negative_solution = 0;

    double discriminant = ( (b*b) - (4*a*c));
    /* printf("%f\n", discriminant); */
    /*printf("%f %f %f", a, b, c);*/

    if (discriminant < 0) {
        /* No solution */
        printf("Ei ratkaisua\n");
    }

    if (discriminant == 0) {
        /* One solution */
        solution = (-b / (2*a));
        printf("%.3f\n", solution);

    }

    if (discriminant > 0) {
        /* Two solutions */

        solution_numerator = -b + sqrt((b*b)-4*a*c);
        solution_denominator = 2*a;
        solution = solution_numerator / solution_denominator;

        negative_solution_numerator = -b - sqrt((b*b)-4*a*c);
        negative_solution_denominator = 2*a;
        negative_solution = negative_solution_numerator / negative_solution_denominator;

        printf("%.3f %.3f\n", negative_solution, solution);
        if (solution > 100) {
            printf("%f %f %f\n", a, b, c);
            printf("%f", sqrt(discriminant));
        }

    }











return 0;
}
