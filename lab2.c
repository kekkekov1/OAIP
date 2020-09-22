/* Даны два натуральных числа. Найти в каком из них больше цифр, используя функцию определения количества цифр в числе. Вывести наибольшее число*/
#include <stdio.h> 
#include <locale.h> // библиотека  локализации русских символов 

int main() {
	setlocale(LC_ALL, "Russian");

	int a, b, kol1 = 0, kol2 = 0, max;
	printf("Введите ваши числа:\n");
	printf("a = "); scanf_s("%d", &a);
	printf("b = "); scanf_s("%d", &b);


	if (a > b) max = a; else max = b;
	while (a != 0) { a /= 10; kol1++; }
	while (b != 0) { b /= 10; kol2++; }

	printf("В числе a %d цифр\n", kol1);
	printf("В числе b %d цифр\n", kol2);
	printf("Большее число = %d", max);

	return 0;
}
