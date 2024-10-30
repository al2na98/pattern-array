#include <locale.h>
#include <iostream>
#include "PatArr.h"
#include <stdio.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int B;
    PatArr<int> a, b, c;
    int m, m2, k;
    cout << "Введите размер 1-го массива: ";
    cin >> m; // Получаем размер от пользователя
    a.Scan(m); 
    cout << "Ваш массив (a):\n";
    a.Print(m); // Печатаем массив

    cout << "Введите размер 2-го массива: ";
    cin >> m2; // Получаем размер второго массива
    b.Scan(m2); // Заполняем второй массив
    cout << "Ваш массив (b):\n";
    b.Print(m2); // Печатаем второй массив

    a += b; // Складываем массивы
    cout << "a += b:\n";
    a.Print(a.CheckSize()); // Печатаем результат

    c = a + b; // Сложение массивов
    cout << "a + b:\n";
    c.Print(c.CheckSize()); // Печатаем результат

    cout << "Изначальный массив b:\n";
    b.Print(m2);

    b = a; // Копируем содержимое a в b
    cout << "Скопированный массив b:\n";
    b.Print(b.CheckSize()); // Печатаем b

    cout << "Введите число: ";
    cin >> k; // Получаем число от пользователя
    a += k; // Добавляем число ко всем элементам массива
    cout << "a += k:\n";
    a.Print(a.CheckSize());

    c = a + k; // Складываем массив c и число k
    cout << "a + k:\n";
    c.Print(c.CheckSize());

    cout << "Введите число для удаления: ";
    cin >> k; // Число для удаления

    a -= k; // Удаляем элемент
    cout << "a -= k:\n";
    a.Print(a.CheckSize());

    cout << "Введите число (поиск по ключу): ";
    cin >> k;
    a.Findkey(k); // Поиск по ключу

    a.Sorting(); // Сортируем массив
    cout << "Отсортированный массив:\n";
    a.Print(a.CheckSize());

    cout << "Максимум в массиве: " << a.Max() << endl;
    cout << "Минимум в массиве: " << a.Min() << endl;

    // Проверка на равенство 
    if (a == b)
        cout << "Массивы a и b равны.\n";
    else
        cout << "Массивы a и b не равны.\n";

    return 0; 
}
