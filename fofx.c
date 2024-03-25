#include <stdio.h>


float f_of_x(double x) {
	return ((x * x) + (- 3 * x) + 2);
}

int main() {
	for (double x = 0;(0 <= x && x <= 3); x += 0.1) {
		printf("f(%.1f) = %.2f\n", x, f_of_x(x));
	}
	return 0;

}
