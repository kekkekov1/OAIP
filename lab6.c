#pragma warning (disable : 4996) //отключение спецификатора предупреждения
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	int n;
	int* matr;
	setlocale(LC_ALL, "Rus");
	printf("Введите длину квадрата :\n");
	scanf("%d", &n);
	printf("\n");
	matr = (int*)malloc(n * n * sizeof(int));
	printf("Введите элементы квадрата :\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", (matr + n * i + j));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) {
				if ((*(matr + n * i + j) == *(matr + n * i + k)) && (j != k)) {
					printf("Квадрат не является латинским");
					return 0;
				}
				if ((*(matr + n * i + j) == *(matr + n * k + j)) && (i != k)) {
					printf("Квадрат не является латинским");
					return 0;
				}
			}
	printf("Квадрат является латинским!!!!)))))))");
	return 0;
}
