#include <iostream>
#include <cstdio>
#include <cstdlib>

/* Calcula o cansa�o acumulado por um amigo ao andar um determinado numero de passos*/
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

	/*	O cansa�o m�nimo � atingido quando cada amigo d� um n�mero igual de passos, 
		sempre em dire��o ao outro amigo, percorrendo metade da dist�ncia. O custo
		ent�o � o dobro do custo para se percorrer metade da dist�ncia. Se a dist�ncia
		for um valor �mpar, ent�o o custo do passo final � adicionado separadamente.*/
	if (distancia % 2)
		cansaco_minimo = (2 * custo(distancia / 2)) + (1 + (distancia / 2));
	else
		cansaco_minimo = (2 * custo(distancia / 2));

	printf("%d\n", cansaco_minimo);
	return 0;
}