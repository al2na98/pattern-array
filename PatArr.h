#pragma once

#ifndef PATARR_H
#define PATARR_H

#include <iostream>

template <class B>
class PatArr {
private:
    B* a; // Указатель на массив элементов типа B
    int n; // Размер массива


public:
    // Конструкторы
    PatArr(); // Конструктор по умолчанию
    PatArr(int N); // Конструктор с параметром для задания размера
    PatArr(const PatArr& x); // Конструктор копирования
    PatArr (PatArr* b, int n); //конструктор с аргументом(n - число эл - тов в b)
    // Деструктор
    ~PatArr(); 

    // Члены класса
    int Size(); // Устанавливает и возвращает новый размер массива
    int CheckSize() const; // Проверяем размер массива, метод не изменяет объект
    void Scan(int m); // Считывает массив из входного потока
    void Print(int m) const; // Печатает массив, метод не изменяет объект
    int Findkey(B key); // Ищет заданный ключ в массиве

    // Перегрузка операторов
    PatArr<B> operator+(B key); // Перегрузка оператора сложения с элементом
    PatArr<B>& operator+=(B key); // Перегрузка оператора += для добавления элемента

    PatArr<B>& operator=(const PatArr<B>& x); // Перегрузка оператора присваивания

    PatArr<B>& operator+=(PatArr<B> x); // Перегрузка оператора += для сложения двух массивов
    PatArr<B> operator+(PatArr<B> x); // Перегрузка оператора + для сложения двух массивов

    PatArr<B>& operator-=(B key); // Перегрузка оператора -= для удаления элемента
    PatArr<B> operator-(B key); // Перегрузка оператора - для создания нового массива без указанного элемента

    PatArr<B>& DelPosEq(int pos); // Удаляет элемент по указанной позиции из текущего массива
    PatArr<B> DelPosNew(int pos); // Создает новый массив без элемента по указанной позиции

    bool operator==(PatArr<B> x) const; // Перегрузка оператора == для сравнения массивов
    bool operator!=(PatArr<B> x) const; // Перегрузка оператора != для сравнения массивов

    int Max(); // Возвращает максимальный элемент в массиве
    int Min(); // Возвращает минимальный элемент в массиве
    void Sorting(); // Сортирует массив

    B operator[](int index) const; // Перегрузка оператора [] для доступа к элементам массива (константная версия)
    B Get(int index) const; // Метод для получения элемента по индексу (константная версия)
    void Set(int index, B value); // Метод для установки значения элемента по индексу
    friend std::ostream& operator<<(std::ostream& r, const PatArr<B>& x) {
        for (const auto& elem : x.a) {
            r << "[" << elem << "]";
        }
        return r;
    }

    friend std::istream& operator>>(std::istream& r, PatArr<B>& x) {
        for (auto& elem : x.a) {
            r >> elem;
        }
        return r;
    }
};

// Реализацию методов
template <class B>
PatArr<B>::PatArr() {
    n = 10; 
    a = new B[n]; // Выделяем память для массива
    for (int i = 0; i < n; i++) {
        a[i] = 0; 
    }
}

template <class B>
PatArr<B>::PatArr(int N) {
    n = N; 
    a = new B[n]; // Выделяем память для массива
    for (int i = 0; i < n; i++) {
        a[i] = 0; 
    }
}

template <class B>
PatArr<B>::PatArr(const PatArr& x) {
    n = x.n; // Копируем размер массива
    a = new B[n]; // Выделяем память для нового массива
    for (int i = 0; i < n; i++) {
        a[i] = x.a[i]; // Копируем элементы из исходного массива
    }
}

template<class B>
PatArr<B>::PatArr(PatArr* b, int n)
{
    if (b == nullptr || n <= 0) {
        throw std::invalid_argument("Указатель на массив не должен быть нулевым, и размер должен быть положительным.");
    }

    // Устанавливаем размер вектора на n
    a.resize(n);

    // Копируем элементы из переданного массива
    for (int i = 0; i < n; ++i) {
        a[i] = b->Get(i); // Используем метод Get для доступа к элементам
    }
}

template <class B>
PatArr<B>::~PatArr() {
    delete[] a; // Освобождаем память, занятую массивом
}

template <class B>
int PatArr<B>::Size() {
    std::cin >> n; // Считываем новый размер массива
    return n;
}

template <class B>
int PatArr<B>::CheckSize() const {
    return n;
}

template <class B>
void PatArr<B>::Scan(int m) {
    std::cout << "Введите массив :" << std::endl; 
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }
}

template <class B>
void PatArr<B>::Print(int m) const {
    for (int i = 0; i < m; i++) {
        std::cout << "[" << a[i] << "]";
    }
    std::cout << std::endl << std::endl; 
}


template<class B>
int PatArr<B>::Findkey(B key)
{
    // Проходим по всем элементам массива
    for (int i = 0; i < n; i++)
    {
        // Проверяем, равен ли текущий элемент искомому
        if (a[i] == key)
        {
            std::cout << "Элемент находится на " << i << "-ой позиции" << std::endl;
            return i;
        }
    }
    std::cout << "В массиве отсутствует данный элемент" << std::endl; 
    return -1; // Возвращаем -1, если элемент не найден
}

template <class B>
PatArr<B> PatArr<B>::operator+(B key) {
    // Создаем временный массив для нового размера
    int* r = new int[n + 1];
    for (int i = 0; i < n; i++) {
        r[i] = a[i]; // Копируем существующие элементы в новый массив
    }
    r[n] = key; // Добавляем новый элемент в конец массива
    n++; 

    PatArr b(n); // Создаем новый объект PatArr
    for (int i = 0; i < n; i++) {
        b.a[i] = r[i]; // Копируем элементы из временного массива в новый объект
    }
    delete[] r; 
    return b; 
}

template <class B>
PatArr<B>& PatArr<B>::operator+=(B key) {
    // Создаем временный массив для нового размера
    int* r = new int[n + 1];
    for (int i = 0; i < n; i++) {
        r[i] = a[i]; // Копируем существующие элементы в новый массив
    }
    r[n] = key; // Добавляем новый элемент в конец массива

    delete[] a; 
    a = r; 
    n += 1;

    return *this;
}

template <class B>
PatArr<B>& PatArr<B>::operator=(const PatArr<B>& x) {
    // Проверяем, не присваиваем ли мы самому себе
    if (this != &x) {
        delete[] a;
        n = x.n; // Копируем количество элементов
        a = new B[n]; 
        for (int i = 0; i < n; i++) {
            a[i] = x.a[i]; // Копируем элементы из другого массива
        }
    }
    return *this;
}

template <class B>
PatArr<B>& PatArr<B>::operator+=(PatArr<B> x) {
    // Создаем временный массив для комбинированного размера
    int* r = new int[n + x.n];
    for (int i = 0; i < n; i++) {
        r[i] = a[i]; // Копируем существующие элементы
    }
    for (int i = n; i < (n + x.n); i++) {
        r[i] = x.a[i - n]; // Копируем элементы из другого массива
    }

    delete[] a;
    a = r; // Перенаправляем указатель на новый массив
    n += x.n; 
    return *this; 
}

template <class B>
PatArr<B> PatArr<B>::operator+(PatArr<B> x) {
    // Создаем новый размер для комбинированного массива
    int n2 = n + x.n;
    int* r = new int[n2];
    for (int i = 0; i < n; i++) {
        r[i] = a[i]; // Копируем существующие элементы
    }
    for (int i = n; i < n2; i++) {
        r[i] = x.a[i - n]; // Копируем элементы из другого массива
    }

    PatArr b(n2); // Создаем новый объект PatArr с новым размером
    for (int i = 0; i < n2; i++) {
        b.a[i] = r[i]; // Копируем элементы из временного массива в новый объект
    }
    delete[] r; 
    return b; 
}

template <class B>
PatArr<B>& PatArr<B>::operator-=(B key) {
    int* r = new int[n - 1]; // Создаем новый массив для хранения элементов, отличных от key
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != key) { // Если элемент не равен key, добавляем его в новый массив
            r[j++] = a[i];
        }
    }
    delete[] a; 
    a = r; // Указываем на новый массив
    n = j; // Обновляем размер массива

    return *this; 
}

template <class B>
PatArr<B> PatArr<B>::operator-(B key) {
    int* r = new int[n - 1]; // Создаем новый временный массив
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != key) { // Если элемент не равен key, добавляем его в новый массив
            r[j++] = a[i];
        }
    }

    PatArr b(n - 1); // Создаем новый объект массива с уменьшенным размером
    for (int i = 0; i < n - 1; i++) {
        b.a[i] = r[i]; // Копируем элементы во вновь созданный массив
    }
    delete[] r; 
    return b;
}

template <class B>
PatArr<B>& PatArr<B>::DelPosEq(int pos) {
    if (pos < 0 || pos >= n) {
        return *this; // Если индекс некорректен, возвращаем текущий объект
    }

    int* r = new int[n - 1]; 
    for (int i = 0; i < pos; i++) {
        r[i] = a[i]; // Копируем элементы до позиции удаления
    }
    for (int i = pos; i < n - 1; i++) {
        r[i] = a[i + 1]; // Копируем оставшиеся элементы, пропуская удаляемый
    }

    delete[] a;
    a = r; // Указываем на новый массив
    n--; 

    return *this; 
}

template <class B>
PatArr<B> PatArr<B>::DelPosNew(int pos) {
    if (pos < 0 || pos >= n) {
        return *this; // Если индекс некорректен, возвращаем текущий объект
    }

    int* r = new int[n - 1]; // Создаем новый временный массив размером на 1 меньше
    for (int i = 0; i < pos; i++) {
        r[i] = a[i]; // Копируем элементы до позиции удаления
    }
    for (int i = pos; i < n - 1; i++) {
        r[i] = a[i + 1]; // Копируем оставшиеся элементы, пропуская удаляемый
    }

    PatArr b(n - 1); // Создаем новый объект массива с уменьшенным размером
    for (int i = 0; i < n - 1; i++) {
        b.a[i] = r[i]; // Копируем элементы в новый массив
    }
    delete[] r; 
    return b; 
}

template <class B>
bool PatArr<B>::operator==(PatArr<B> x) const {
    if (n != x.n) { // Сравниваем размеры массивов
        return false; 
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != x.a[i]) { // Сравниваем элементы массивов
            return false; 
        }
    }
    std::cout << "Массивы равны" << std::endl; 
    return true; // Если все элементы равны, массивы равны
}

template <class B>
bool PatArr<B>::operator!=(PatArr<B> x) const {
    return !(*this == x);
}


template<class B>
int PatArr<B>::Max() {
    if (n == 0) throw std::runtime_error("Массив пуст"); // Проверяем, не пуст ли массив

    B maxVal = a[0]; // Инициализируем максимальное значение первым элементом
    for (int i = 1; i < n; i++) {
        if (a[i] > maxVal) {
            maxVal = a[i]; // Находим максимальный элемент
        }
    }
    return maxVal; // Возвращаем максимальное значение
}

template<class B>
int PatArr<B>::Min() {
    if (n == 0) throw std::runtime_error("Массив пуст"); // Проверяем, не пуст ли массив

    B minVal = a[0]; // Инициализируем минимальное значение первым элементом
    for (int i = 1; i < n; i++) {
        if (a[i] < minVal) {
            minVal = a[i]; // Находим минимальный элемент
        }
    }
    return minVal; // Возвращаем минимальное значение
}

template<class B>
void PatArr<B>::Sorting() {
    // Сортировка массива методом пузырька 
    int tmp;
    for (int i = 0; i < n; i++) {
        tmp = a[i];
        for (int j = i; j < n; j++)
            if (tmp > a[j]) {
                // Обмен элементов
                tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
    }
    // Выводим отсортированный массив
    for (int i = 0; i < n; i++) {
        std::cout << "[" << a[i] << "]";
    }
}

template <class B>
B PatArr<B>::operator[](int index) const {
    // Проверка на выход за границы массива
    if (index < 0 || index >= n) {
        std::cout << "Ошибка: индекс за пределами диапазона!" << std::endl;
        return 0; // Или выбросить исключение
    }
    return a[index];
}

template <class B>
B PatArr<B>::Get(int index) const {
    // Проверка на выход за границы массива
    if (index < 0 || index >= n) {
        std::cout << "Ошибка: индекс за пределами диапазона!" << std::endl;
        return 0; 
    }
    return a[index];
}

template <class B>
void PatArr<B>::Set(int index, B value) {
    if (index < 0 || index >= a.size()) {
        throw std::out_of_range("Индекс за пределами диапазона!");
    }
    a[index] = value;
}
#endif
