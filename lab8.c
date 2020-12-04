/*
Дан текст. 
Строки текста содержат символьную и цифровую информацию. 
Слова могут состоять только из букв или только из цифр. 
Выполнить конкатенацию нецифровых слов, причем слова меньше четырех символов удалить. 
Найти сумму всех чисел в строке и записать ее в конец новой строки.
*/

/*----------------Примеры ввода----------------------*/
//   hhhhh 1111 jj 1111. kkkk kk 3333.
//   yyyyy yy  yy y y 4 5 6 6 oooooo 1111 kkk kk kk 3333.   i o i ppppp oo i uuuuuu 9999  jjjjjj j 1111    .
//   yyyyy yy  yy56oooooo 1111 kkk kk kk 3333   .  i ppppp oo6738y r4ifn y84f u7  8888   7h 1111 .kkk kk kk 3333.   uuuuuu 9999  jjjjjj j 1111    .
//   tttt.oooo.pppp 9999 1111 1
/*----------------Примеры вывода---------------------*/
//hhhhh2222.kkkk3333.
//yyyyyoooooo4444.pppppuuuuuujjjjjj11110.
//yyyyy4444.ppppp9999.3333.uuuuuujjjjjj11110.
//tttt.oooo.pppp11110
/*---------------------------------------------------*/

#include<stdlib.h>
#include<stdio.h>
#include<locale.h>

void delete_spaces(char*, int*, int);
void delete_word(int, int, char*);
int pow(int, int);
int dec(char*, int, int);
void add_word(int, int, char*, char*, int);
bool check_word(char*, int, int);

int main()
{

    setlocale(LC_ALL, "rus");
    printf("Введите текст:\n");
    int i = 0, index, length, spaces;
    char buffer;


    /*-------------------Выделение памяти для строк---------------*/
    char* stroka;
    int size = 0;   // Размер массива - 1, т.е. ячейка, в которой мы что-то присваиваем
    stroka = (char*)malloc(1 * sizeof(char));
    /*------------------------------------------------------*/


    /*-----------------------Ввод строк---------------------------*/
    do {
        buffer = getchar();
        if (buffer == '\n') break;
        stroka[size] = buffer;
        size++;
        stroka = (char*)realloc(stroka, (size + 1) * sizeof(char));
    } while (1);
    stroka[size] = '\0';
    /*------------------------------------------------------------------*/


    /*----------------Удаление всех повторяющихся пробелов---------------------*/
    spaces = 0;
    delete_spaces(stroka, &spaces, 1);
    size -= spaces;
    stroka = (char*)realloc(stroka, size * sizeof(char));
    stroka[size] = '\0';
    /*-------------------------------------------------------------------------*/


    /*------------Выделяем память для массива суммы чисел каждого предложения----------------*/
    int* sum;
    sum = (int*)calloc(1, sizeof(int));
    int size_sum = 0;
    /*---------------------------------------------------------------------------------------*/


    /*---Проходим по строке и 1) Удаляем все слова меньше 4 символов и слова состоящие не только из цифр или букв-----*/
    /*------------------------2) Конвертируем символы чисел в целочисленный тип и считаем сумму-----------------------*/
    while (stroka[i] != '\0')
    {
        index = i; length = 0, spaces = 0;
        while (stroka[i] != ' ' && stroka[i] != '\0' && stroka[i] != '.') { length++; i++; }
        bool check = 0;
        if (stroka[i] == '.' || stroka[i] == '\0') check = 1;
        bool checked_word = check_word(stroka, length, index);
        if ((!checked_word) || (length < 4 && length != 0) || (stroka[index] >= '0' && stroka[index] <= '9'))
        {
            if (checked_word && length >= 4 && stroka[index] >= '0' && stroka[index] <= '9')
                sum[size_sum] += dec(stroka, length, index);
            delete_word(index, length, stroka);
            size -= length;
            delete_spaces(stroka, &spaces, 1);
            size -= spaces;
            stroka = (char*)realloc(stroka, size * sizeof(char));
            stroka[size] = '\0';
            if (index < size)i = index; else i = size;
        }
        else i++;
        if (check)
        {
            size_sum++;
            sum = (int*)realloc(sum, (size_sum + 1) * sizeof(int));
            sum[size_sum] = 0;
        }
    }
    /*---------------------------------------------------------------------------------------------------------------------------------------*/


    /*----------------Делаем конкатенацию нецифровых слов, т.е. соединяем все слова, удалив все пробелы---------------------*/
    spaces = 0;
    delete_spaces(stroka, &spaces, 0);
    size -= spaces;
    stroka = (char*)realloc(stroka, size * sizeof(char));
    stroka[size] = '\0';
    /*----------------------------------------------------------------------------------------------------------------------*/


    /*----------------Выделяем память под массив, в котором будем хранить символьное представлени сумм (ПЕРЕВЕРНУТЫЕ!)---------------------*/
    char** buf;
    int size_buf = 0;
    buf = (char**)malloc(size_sum * sizeof(char*));
    for (int i = 0; i < size_sum; i++)
        buf[i] = (char*)malloc(1 * sizeof(char));
    /*------------------------------------------------------------------------------------------------------------------------------------------*/
    
    
    /*----------------Конвертируем целочисленное представление сумм в символьное и сохраняем каждое число словом---------------------*/
    int symbol, chislo;
    i = 0;
    while (i < size_sum)
    {
        int kol = 0;
        while (sum[i] != 0)
        {
            symbol = sum[i] % 10;
            sum[i] /= 10;
            buf[i][size_buf] = (char)(symbol + 48);
            size_buf++;
            buf[i] = (char*)realloc(buf[i], (size_buf + 1) * sizeof(char));
            kol++;
        }
        sum[i] = kol;
        buf[i][size_buf] = '\0';
        size_buf = 0;
        i++;
    }
    /*------------------------------------------------------------------------------------------------------------------------------*/

    
    /*----------------Вставляем сумму чисел в конец строки---------------------*/
    for (int i = 0, j = 0; stroka[i-1] != '\0';)
    {
        if (stroka[i] == '.' || stroka[i] == '\0')
        {
            if (sum[j] == 0) { i++; j++; continue; }
            size += sum[j];
            stroka = (char*)realloc(stroka, size * sizeof(char));
            stroka[size] = '\0';
            add_word(i, sum[j], stroka, buf[j], size);
            i += sum[j];
            j++;
        }
        i++;
    }
    /*------------------------------------------------------------------------*/


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

void add_word(int index, int length, char* stroka, char* word, int size) {
    int i = size - 1, j;
    while (i >= index + length)
    {
        stroka[i] = stroka[i - length];
        i--;
    }
    i = index, j = length - 1;
    while (j > -1)
    {
        stroka[i] = word[j];
        j--; i++;
    }
}

void delete_spaces(char* stroka, int* spaces, int trivial) {
    int i = 0;
    while (stroka[i] != '\0')
        if ((stroka[i] == ' ' && i == 0) || (stroka[i] == ' ' && (stroka[i + trivial] == ' ' || stroka[i + trivial] == '\0' || stroka[i + trivial] == '.'))) {
            int j = i;
            while (stroka[j] != '\0') {
                stroka[j] = stroka[j + 1];
                j++;
            }
            (*spaces)++;
        }
        else i++;
}

int pow(int a, int n)
{
    int ans = 1;
    for (int i = 0; i < n; i++) ans *= a;
    return ans;
}

int dec(char* stroka, int length, int index)
{
    length--;
    int ans = 0;
    while (length >= 0)
    {
        ans += ((int)stroka[index] - 48)* pow(10, length);
        index++; 
        length--;
    }
    return ans;
}

bool check_word(char* stroka, int length, int index)
{
    int l = length - 1;
    int kol = 0;
    while (l >= 0)
    {
        if (stroka[index] >= '0' && stroka[index] <= '9')kol++;
        index++;
        l--;
    }
    if (kol == length || kol == 0) return 1; else return 0;
}
