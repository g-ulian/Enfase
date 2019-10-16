#include <iostream>
#include <cstdio>
#include <cstdlib>

/* Calcula o cansaço acumulado por um amigo ao andar um determinado numero de passos*/
int custo(int passos_dados) {
	int x = 0;
	for (int i = 1; i <= passos_dados; i++)
		x += i;
	return x;
}

int main(void) {
	int X1, X2, cansaco_minimo;
	scanf_s("%d %d", &X1, &X2);
	int distancia = abs(X2 - X1);

	/*	O cansaço mínimo é atingido quando cada amigo dá um número igual de passos, 
		sempre em direção ao outro amigo, percorrendo metade da distância. O custo
		então é o dobro do custo para se percorrer metade da distância. Se a distância
		for um valor ímpar, então o custo do passo final é adicionado separadamente.*/
	if (distancia % 2)
		cansaco_minimo = (2 * custo(distancia / 2)) + (1 + (distancia / 2));
	else
		cansaco_minimo = (2 * custo(distancia / 2));

	printf("%d\n", cansaco_minimo);
	return 0;
}