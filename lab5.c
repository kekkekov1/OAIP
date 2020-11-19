#include <stdio.h>
#include <locale.h>
int main()
{
	int a1[10][10], a2[10][10], a3[10][10], a4[10][10], matr[20][20], k, l;
	int n;
	setlocale(LC_ALL, "Rus");
	printf("Введите количество столбцов и строк\n");
	scanf_s("%d", &n);
	printf("Введите элементы матрицы\n");
	for (int i = 0; i < 2 * n; i++)
		for (int j = 0; j < 2 * n; j++)
			scanf_s("%d", &matr[i][j]);
	printf("\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a1[i][j] = matr[i][j];

	for (int i = 0; i < n; i++)
		for (int j = n; j < 2 * n; j++)
			a2[i][j] = matr[i][j];

	for (int i = n; i < 2 * n; i++)
		for (int j = n; j < 2 * n; j++)
			a3[i][j] = matr[i][j];

	for (int i = n; i < 2 * n; i++)
		for (int j = 0; j < n; j++)
			a4[i][j] = matr[i][j];


	k = n;
	for (int i = 0; i < n; i++) {
		l = 0;
		for (int j = 0; j < n; j++) {
			matr[i][j] = a4[k][l];
			l++;
		}
		k++;
	}

	k = n;
	for (int i = n; i < 2 * n; i++) {
		l = n;
		for (int j = 0; j < n; j++) {
			matr[i][j] = a3[k][l];
			l++;
		}
		k++;
	}
	k = 0;
	for (int i = n; i < 2 * n; i++) {
		l = n;
		for (int j = n; j < 2 * n; j++) {
			matr[i][j] = a2[k][l];
			l++;
		}
		k++;
	}
	k = 0;
	for (int i = 0; i < n; i++) {
		l = 0;
		for (int j = n; j < 2 * n; j++) {
			matr[i][j] = a1[k][l];
			l++;
		}
		k++;
	}
	printf("Изменённая матрица:\n");
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++)
			printf("%d ", matr[i][j]);
		printf("\n");
	}
	return 0;
}



//1 1 1 1 1 2 2 2 2 2
//1 1 1 1 1 2 2 2 2 2
//1 1 1 1 1 2 2 2 2 2
//1 1 1 1 1 2 2 2 2 2
//1 1 1 1 1 2 2 2 2 2
//4 4 4 4 4 3 3 3 3 3
//4 4 4 4 4 3 3 3 3 3
//4 4 4 4 4 3 3 3 3 3
//4 4 4 4 4 3 3 3 3 3
//4 4 4 4 4 3 3 3 3 3


