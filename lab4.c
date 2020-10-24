#include <stdio.h>
#include <locale.h>
int main()
{
	int  mas[9], max, index;
	bool check = 0;
	setlocale(LC_ALL, "Rus");
	printf("Введите элементы массива\n");
	for (int a = 0; a < 9; a++) {
		scanf_s("%d", &mas[a]);
		if (mas[a] > 0 && mas[a] % 2 != 0)
			check = 1;
	}
	if (!check)
	{
		printf("В массиве нет положительных нечетных элементов!");
		return 0;
	}
	max = mas[0];
	index = 0;
	for (int a = 0; a < 9; a++)
		if (mas[a] > 0 && mas[a] % 2 != 0 && mas[a] > max) {
			max = mas[a];
			index = a;
		}
	printf("Индекс наибольшего положительного нечётного элемента : [%d]", index);
	return 0;
}
