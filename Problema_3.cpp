#include <map>
#include <vector>

#define max(a, b) (((a > b))? (a) : (b));

/*	Dado um conjunto de números de tamanho n, construa a maior sequência possível
	que satisfaça a condição Fn+2 = Fn+1 + Fn, com F0 e F1 arbitrários, e dê o
	tamanho dessa sequência.*/

int main() {
	int n;						// número de elementos na sequencia
	int elem[1200];				// elementos na sequência
	std::map<int, int> mapa;	// numero de vezes que cada número aparece na sequencia
	int seq = 0;				// maior sequência encontrada

	/*	Valores de entrada. */
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &elem[i]);
		mapa[elem[i]]++;
	}

	/*	Se houver mais de um zero, é possível construir uma sequência válida composta
		apenas de zeros. */
	if (mapa[0] > 1)
		seq = mapa[0];

	/*	Solução força bruta: escolhe um par de elementos, tenta montar uma sequência
		Fibonaccica com eles, guarda o tamanho da maior sequência formada em 'seq'. */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				int x = elem[i], y = elem[j];

				// Caso dos zeros já tratado acima
				if (x == 0 && y == 0)
					continue;

				/*	Tenta construir uma sequência Fibonaccica a partir do x e y. */
				
				std::vector<int> v; // sequencia Fibonaccica encontrada
				//	Primeiro, busca o primeiro elemento Fn = x no mapa
				while (mapa.find(x) != mapa.end() && mapa[x]) {
					//	Se for encontrado, é retirado do mapa e colocado em v.
					mapa[x]--;
					v.push_back(x);

					/*	A variável 'x' então recebe o próximo valor a ser procurado (Fn+1 = y),
						e a variável 'y' recebe o valor seguinte (Fn+2 = Fn+1 + Fn) */	
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