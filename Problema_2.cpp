#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

#define matrix std::vector<std::string>

/*	Verifica se o jogador 'c' tem uma combinação vencedora no tabuleiro 'm' */
bool vencedor(char c, matrix m) {
	if (m[0][0] == c && m[1][0] == c && m[2][0] == c) return true;
	if (m[0][1] == c && m[1][1] == c && m[2][1] == c) return true;
	if (m[0][2] == c && m[1][2] == c && m[2][2] == c) return true;
	if (m[0][0] == c && m[1][1] == c && m[2][2] == c) return true;
	if (m[0][2] == c && m[1][1] == c && m[2][0] == c) return true;
	if (m[0][0] == c && m[0][1] == c && m[0][2] == c) return true;
	if (m[1][0] == c && m[1][1] == c && m[1][2] == c) return true;
	if (m[2][0] == c && m[2][1] == c && m[2][2] == c) return true;
	return false;
}

int main() {
	matrix board;		//	Tabuleiro
	int nX = 0, nO = 0;	//	Número de X e 0 no jogo

	// Recebe a entrada e conta o número de Xs e 0s
	for (int i = 0; i < 3; i++) {
		std::string s;
		getline(std::cin, s);
		board.push_back(s);
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 'X') nX++;
			else if (board[i][j] == '0') nO++;
		}
	}
	/* Um tabuleiro é inválido quando:
		If 1 - O número de cruzes é menor que o número de círculos, ou maior que
		número de círculos + 1.
		If 2 e 3 - Há um vencedor, mas o número de cruzes ou círculos é diferente
		do esperado num fluxo normal de jogo.
		If 4 - Há mais de um vencedor. 
	   Se o tabuleiro é válido, podemos verificar:
		If 5 - Se o primeiro venceu.
		If 6 - Se o segundo venceu.
	   Se não há vencedor, podemos verificar:
		If 7 - Se o tabuleiro está cheio (empate).
		If 8 - Se o número de Xs e 0s é igual (vez do X).
		if 9 - Se o número de Xs é igual ao número de 0s + 1 (vez do 0).	*/
	if (nX < nO || nX > nO + 1)
		printf("invalido\n");
	else if (vencedor('X', board) && nX != nO + 1)
		printf("invalido\n");
	else if (vencedor('0', board) && nX != nO)
		printf("invalido\n");
	else if (vencedor('X', board) && vencedor('0', board))
		printf("invalido\n");
	else if (vencedor('X', board) && nX == nO + 1)
		printf("primeiro_venceu\n");
	else if (vencedor('0', board) && nX == nO)
		printf("segundo_venceu\n");
	else if (nX == 5 && nO == 4)
		printf("empate");
	else if (nX == nO)
		printf("primeiro");
	else if (nX == nO + 1)
		printf("segundo");

	return 0;
}

