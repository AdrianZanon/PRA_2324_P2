#include <iostream>
#include <vector>

void pesval(int m, int n, int* p, int* v) {

	int** matrix = new int* [n + 1];

	for (int i = 0; i < n + 1; i++) {
		matrix[i] = new int[m + 1];
		std::cout << "\n";
		for (int j = 0; j < m + 1; j++) {
			if (i == 0 || j == 0) {
				matrix[i][j] = 0;
			}
			else {
				matrix[i][j] = -1;
			}
			std::cout << matrix[i][j] << " ";
		}
	}

	std::cout << "\n";

	for (int i = 0; i < n + 1; i++) {
		std::cout << "\n";
		for (int j = 0; j < m + 1; j++) {
			if (j == 0 || i == 0){
				matrix[i][j] == 0;
			}
			else if (p[i] > j) {
				matrix[i][j] == 0;
				matrix[i][j] = std::max(matrix[i][j], matrix[i - 1][j]);
			}
			else {
				matrix[i][j] = v[i] + matrix[i - 1][j - p[i]];
				matrix[i][j] = std::max(matrix[i][j], matrix[i - 1][j]);
			}
			std::cout << matrix[i][j] << " ";
		}
	}

	std::cout << "\n" << std::endl;

	int con;
	int arr[5]{};
	std::cin >> con;
	int valor = matrix[n][con];
	while (valor > 0) {

		if (valor == v[n] + matrix[n - 1][con - p[n]]) {
			arr[n - 1]++;
			valor -= v[n];
			con -= p[n];
			n--;
		}
		else {
			n--;
		}
	}
	std::cout << arr[0]<<" "<<arr[1]<<" "<< arr[2]<< " " << arr[3] << " " << arr[4];
	
}

int main() {
	int m = 15; // Capacidad máxima de la mochila
	int n = 3;  // Número de elementos disponibles

	int p[] = {0, 9, 6 , 5 }; // Pesos de los elementos
	int v[] = {0, 38, 40, 24 }; // Valores de los elementos

	pesval(m, n, p, v);

	return 1;
}
