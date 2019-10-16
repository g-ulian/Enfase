#include <map>
#include <vector>

#define max(a, b) (((a > b))? (a) : (b));

/*	Dado um conjunto de n�meros de tamanho n, construa a maior sequ�ncia poss�vel
	que satisfa�a a condi��o Fn+2 = Fn+1 + Fn, com F0 e F1 arbitr�rios, e d� o
	tamanho dessa sequ�ncia.*/

int main() {
	int n;						// n�mero de elementos na sequencia
	int elem[1200];				// elementos na sequ�ncia
	std::map<int, int> mapa;	// numero de vezes que cada n�mero aparece na sequencia
	int seq = 0;				// maior sequ�ncia encontrada

	/*	Valores de entrada. */
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &elem[i]);
		mapa[elem[i]]++;
	}

	/*	Se houver mais de um zero, � poss�vel construir uma sequ�ncia v�lida composta
		apenas de zeros. */
	if (mapa[0] > 1)
		seq = mapa[0];

	/*	Solu��o for�a bruta: escolhe um par de elementos, tenta montar uma sequ�ncia
		Fibonaccica com eles, guarda o tamanho da maior sequ�ncia formada em 'seq'. */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				int x = elem[i], y = elem[j];

				// Caso dos zeros j� tratado acima
				if (x == 0 && y == 0)
					continue;

				/*	Tenta construir uma sequ�ncia Fibonaccica a partir do x e y. */
				
				std::vector<int> v; // sequencia Fibonaccica encontrada
				//	Primeiro, busca o primeiro elemento Fn = x no mapa
				while (mapa.find(x) != mapa.end() && mapa[x]) {
					//	Se for encontrado, � retirado do mapa e colocado em v.
					mapa[x]--;
					v.push_back(x);

					/*	A vari�vel 'x' ent�o recebe o pr�ximo valor a ser procurado (Fn+1 = y),
						e a vari�vel 'y' recebe o valor seguinte (Fn+2 = Fn+1 + Fn) */	
					int aux = y;
					y += x;
					x = aux;
				}

				seq = max(seq, v.size());

				// Restaura elementos retirados do mapa
				for (int k = 0; k < v.size(); k++)
					mapa[v[k]]++;
			}
		}
	}
	printf("%d\n", seq);

	return 0;
}