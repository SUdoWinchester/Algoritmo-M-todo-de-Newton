#include <stdio.h>
#include <math.h>

double f(double x) {
	return pow(M_E, x) - 4 * pow(x, 2);
}

double fd(double x) {
	return pow(M_E, x) - 8 * x;
}

double modulo(double x) {
	if(x < 0)
		return x * -1;
	else
		return x;
}

void main() {
	double x0, x1, fi, fx, fxLinha, raiz;
	int k, it;

	printf("Entre com o X0:\n");
	scanf("%lf", &x0);
	printf("Entre com a precisao\n");
	scanf("%lf", &fi);
	printf("Numero maximo de interacoes\n");
	scanf("%d", &it);

	fx = f(x0);

	if(modulo(fx) > fi) {
		k = 1;
		fxLinha = fd(x0);
		x1 = x0 - (fx/fxLinha);
		fx = f(x1);

		while(modulo(fx) > fi && modulo(x1 - x0) > fi && k <= it) {
			k++;
			x0 = x1;
			fxLinha = fd(x0);
			x1 = x0 - (fx/fxLinha);
			fx = f(x1);
		}
		raiz = x1;
	} else {
		raiz = x0;
	}

	printf("\n\nRaiz = %lf\n", raiz);
	printf("Numero de interacoes = %d\n", k);
}