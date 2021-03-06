﻿/*4.1 (3). С клавиатуры вводится многострочный текст. Оставить в тексте
только первые вхождения каждой буквы, остальные – удалить.
Вывести слова полученного текста, которые начинаются и
заканчиваются одной и той же буквой. */

#include <iostream>
#include <stdio.h>

using namespace std;

void strSort(char str[], const int size);
void strShow(char str[], int size);

int main()
{
    const int size = 100;
    char str[size];

    gets_s(str);

    strSort(str, size);

    printf("%s \n", str);

    strShow(str, size);

    return 0;
}

//функция удалени слов с одинаковыми буквами в начале
void strSort(char str[], const int size)
{
    char dummy;
    int spaceNum;

    //цикл идет по каждой букве строки
    for (int y = 0; y < size; y++)
    {
        if (str[y] == '\0')
        {
            break;
        }
        else if (str[y] != ' ')
        {
            //если буква в начале слова или в начале строки, то запоминаем ее
            if ((y == 0) || ((str[y - 1] == ' ') && (y != 0)))
            {
                dummy = str[y];
            }

            //начиная с позиции, где мы нашли подходящую букву, идем по строке 
            //в поисках слова, начинающегося с такой же буквы
            for (int i = y; i < size; i++)
            {
                //идем по слову, подсчитывя кол-во букв в нем
                for (int j = i; j < size; j++)
                {
                    if ((str[j] == ' '))
                    {
                        //идем по слову, заменяя все буквы на пробел
                        if (str[j + 1] == dummy)
                        {
                            for (int k = j + 1; ; k++)
                            {
                                if (str[k] != ' ')
                                {
                                    str[k] = ' ';
                                }
                                else
                                {
                                    i += k - 1;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

//ф-ция вывод слов с одинаковыми буквами в конце и в начале
void strShow(char str[], int size)
{
    char dummy;

    //цик идет по каждой букве строки
    for (int y = 0; y < size; y++)
    {
        if (str[y] == '\0')
        {
            break;
        }
        //запоминаем букву
        else if (str[y] != ' ')
        {
            dummy = str[y];
            //идем по слову
            for (int i = y; i < size; i++)
            {
                for (int j = i + 1; j < size; j++)
                {
                    //если это последняя буква и она равна записанной ранее букве
                    //выводим его
                    if ((str[j] == dummy) && (str[j + 1] == ' '))
                    {
                        for (int k = i; k < j + 1; k++)
                        {
                            printf("%c", str[k]);
                        }
                        printf("\n");
                    }
                    else if (str[j] == ' ')
                    {
                        i += j;
                        break;
                    }
                }
            }
        }
    }
}