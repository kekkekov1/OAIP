/*
Даны натуральное число n и символы  s1,…,sn.
Удалить из каждой группы идущих подряд цифр, в которой более двух цифр и которой предшествует точка,
все цифры, начиная с третьей. (например, ab+0.1973-1.1 преобразуется в ab+0.19-1.1).
*/


/*----------------Примеры ввода----------------------*/
//13
//ab+0.1973-1.1
//20
//hgj+-\.2547983+121510.258
/*----------------Примеры вывода---------------------*/
//ab+0.19-1.1
//hgj+-\.25+121510.25
/*---------------------------------------------------*/
#pragma warning(disable:4996)
#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
#include<Windows.h>

void delete_word(int, int, char*);

int main()
{

    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("Введите количество символов:\n");
    int i, index, length, spaces;
    char buffer;

    int n;
    scanf("%d", &n);
    getchar();

    /*-------------------Выделение памяти для строки---------------*/
    char* stroka;
    int size = 0;   // Размер массива - 1, т.е. ячейка, в которой мы что-то присваиваем
    stroka = (char*)malloc((n + 1) * sizeof(char));
    /*------------------------------------------------------*/

    printf("Введите символовы:\n");

    /*-----------------------Ввод символов---------------------------*/
    i = 0;
    do {
        buffer = getchar();
        if (buffer == '\n') break;
        stroka[i] = buffer;
        i++;
    } while (1);
    stroka[n] = '\0';
    /*---------------------------------------------------------------*/



    /*---Проходим по строке и удаляем все цифры из каждой группы идущих подряд цифр,------*/
    /*--------------в которой более двух цифр и которой предшествует точка----------------*/
    i = 1;
    while (stroka[i] != '\0')
    {

        //hgj+-\.2547983+121510.258
        index = i; length = 0;
        while (stroka[i] >= '0' && stroka[i] <= '9' && stroka[i] != '\0') { length++; i++; }
        if (stroka[index - 1] == '.' && length > 2)
        {
            index += 2;
            length -= 2;
            delete_word(index, length, stroka);
            n -= length;
            stroka = (char*)realloc(stroka, n * sizeof(char));
            stroka[n] = '\0';
            if (index < n)i = index; else i = n;
        }
        else i++;
    }
    /*-------------------------------------------------------------------------------------*/

    /*----Выводим конечную строку------*/
    printf("\n%s", stroka);
    /*---------------------------------*/

    return 0;
}

void delete_word(int index, int length, char* stroka) {
    int i = index;
    while (stroka[i] != '\0')
    {
        stroka[i] = stroka[i + length];
        i++;
    }
    stroka[i] = stroka[i + length];
}
