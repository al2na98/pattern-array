#pragma once

#ifndef PATARR_H
#define PATARR_H

#include <iostream>

template <class B>
class PatArr {
private:
    B* a; // ��������� �� ������ ��������� ���� B
    int n; // ������ �������


public:
    // ������������
    PatArr(); // ����������� �� ���������
    PatArr(int N); // ����������� � ���������� ��� ������� �������
    PatArr(const PatArr& x); // ����������� �����������
    PatArr (PatArr* b, int n); //����������� � ����������(n - ����� �� - ��� � b)
    // ����������
    ~PatArr(); 

    // ����� ������
    int Size(); // ������������� � ���������� ����� ������ �������
    int CheckSize() const; // ��������� ������ �������, ����� �� �������� ������
    void Scan(int m); // ��������� ������ �� �������� ������
    void Print(int m) const; // �������� ������, ����� �� �������� ������
    int Findkey(B key); // ���� �������� ���� � �������

    // ���������� ����������
    PatArr<B> operator+(B key); // ���������� ��������� �������� � ���������
    PatArr<B>& operator+=(B key); // ���������� ��������� += ��� ���������� ��������

    PatArr<B>& operator=(const PatArr<B>& x); // ���������� ��������� ������������

    PatArr<B>& operator+=(PatArr<B> x); // ���������� ��������� += ��� �������� ���� ��������
    PatArr<B> operator+(PatArr<B> x); // ���������� ��������� + ��� �������� ���� ��������

    PatArr<B>& operator-=(B key); // ���������� ��������� -= ��� �������� ��������
    PatArr<B> operator-(B key); // ���������� ��������� - ��� �������� ������ ������� ��� ���������� ��������

    PatArr<B>& DelPosEq(int pos); // ������� ������� �� ��������� ������� �� �������� �������
    PatArr<B> DelPosNew(int pos); // ������� ����� ������ ��� �������� �� ��������� �������

    bool operator==(PatArr<B> x) const; // ���������� ��������� == ��� ��������� ��������
    bool operator!=(PatArr<B> x) const; // ���������� ��������� != ��� ��������� ��������

    int Max(); // ���������� ������������ ������� � �������
    int Min(); // ���������� ����������� ������� � �������
    void Sorting(); // ��������� ������

    B operator[](int index) const; // ���������� ��������� [] ��� ������� � ��������� ������� (����������� ������)
    B Get(int index) const; // ����� ��� ��������� �������� �� ������� (����������� ������)
    void Set(int index, B value); // ����� ��� ��������� �������� �������� �� �������
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

// ���������� �������
template <class B>
PatArr<B>::PatArr() {
    n = 10; 
    a = new B[n]; // �������� ������ ��� �������
    for (int i = 0; i < n; i++) {
        a[i] = 0; 
    }
}

template <class B>
PatArr<B>::PatArr(int N) {
    n = N; 
    a = new B[n]; // �������� ������ ��� �������
    for (int i = 0; i < n; i++) {
        a[i] = 0; 
    }
}

template <class B>
PatArr<B>::PatArr(const PatArr& x) {
    n = x.n; // �������� ������ �������
    a = new B[n]; // �������� ������ ��� ������ �������
    for (int i = 0; i < n; i++) {
        a[i] = x.a[i]; // �������� �������� �� ��������� �������
    }
}

template<class B>
PatArr<B>::PatArr(PatArr* b, int n)
{
    if (b == nullptr || n <= 0) {
        throw std::invalid_argument("��������� �� ������ �� ������ ���� �������, � ������ ������ ���� �������������.");
    }

    // ������������� ������ ������� �� n
    a.resize(n);

    // �������� �������� �� ����������� �������
    for (int i = 0; i < n; ++i) {
        a[i] = b->Get(i); // ���������� ����� Get ��� ������� � ���������
    }
}

template <class B>
PatArr<B>::~PatArr() {
    delete[] a; // ����������� ������, ������� ��������
}

template <class B>
int PatArr<B>::Size() {
    std::cin >> n; // ��������� ����� ������ �������
    return n;
}

template <class B>
int PatArr<B>::CheckSize() const {
    return n;
}

template <class B>
void PatArr<B>::Scan(int m) {
    std::cout << "������� ������ :" << std::endl; 
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
    // �������� �� ���� ��������� �������
    for (int i = 0; i < n; i++)
    {
        // ���������, ����� �� ������� ������� ��������
        if (a[i] == key)
        {
            std::cout << "������� ��������� �� " << i << "-�� �������" << std::endl;
            return i;
        }
    }
    std::cout << "� ������� ����������� ������ �������" << std::endl; 
    return -1; // ���������� -1, ���� ������� �� ������
}

template <class B>
PatArr<B> PatArr<B>::operator+(B key) {
    // ������� ��������� ������ ��� ������ �������
    int* r = new int[n + 1];
    for (int i = 0; i < n; i++) {
        r[i] = a[i]; // �������� ������������ �������� � ����� ������
    }
    r[n] = key; // ��������� ����� ������� � ����� �������
    n++; 

    PatArr b(n); // ������� ����� ������ PatArr
    for (int i = 0; i < n; i++) {
        b.a[i] = r[i]; // �������� �������� �� ���������� ������� � ����� ������
    }
    delete[] r; 
    return b; 
}

template <class B>
PatArr<B>& PatArr<B>::operator+=(B key) {
    // ������� ��������� ������ ��� ������ �������
    int* r = new int[n + 1];
    for (int i = 0; i < n; i++) {
        r[i] = a[i]; // �������� ������������ �������� � ����� ������
    }
    r[n] = key; // ��������� ����� ������� � ����� �������

    delete[] a; 
    a = r; 
    n += 1;

    return *this;
}

template <class B>
PatArr<B>& PatArr<B>::operator=(const PatArr<B>& x) {
    // ���������, �� ����������� �� �� ������ ����
    if (this != &x) {
        delete[] a;
        n = x.n; // �������� ���������� ���������
        a = new B[n]; 
        for (int i = 0; i < n; i++) {
            a[i] = x.a[i]; // �������� �������� �� ������� �������
        }
    }
    return *this;
}

template <class B>
PatArr<B>& PatArr<B>::operator+=(PatArr<B> x) {
    // ������� ��������� ������ ��� ���������������� �������
    int* r = new int[n + x.n];
    for (int i = 0; i < n; i++) {
        r[i] = a[i]; // �������� ������������ ��������
    }
    for (int i = n; i < (n + x.n); i++) {
        r[i] = x.a[i - n]; // �������� �������� �� ������� �������
    }

    delete[] a;
    a = r; // �������������� ��������� �� ����� ������
    n += x.n; 
    return *this; 
}

template <class B>
PatArr<B> PatArr<B>::operator+(PatArr<B> x) {
    // ������� ����� ������ ��� ���������������� �������
    int n2 = n + x.n;
    int* r = new int[n2];
    for (int i = 0; i < n; i++) {
        r[i] = a[i]; // �������� ������������ ��������
    }
    for (int i = n; i < n2; i++) {
        r[i] = x.a[i - n]; // �������� �������� �� ������� �������
    }

    PatArr b(n2); // ������� ����� ������ PatArr � ����� ��������
    for (int i = 0; i < n2; i++) {
        b.a[i] = r[i]; // �������� �������� �� ���������� ������� � ����� ������
    }
    delete[] r; 
    return b; 
}

template <class B>
PatArr<B>& PatArr<B>::operator-=(B key) {
    int* r = new int[n - 1]; // ������� ����� ������ ��� �������� ���������, �������� �� key
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != key) { // ���� ������� �� ����� key, ��������� ��� � ����� ������
            r[j++] = a[i];
        }
    }
    delete[] a; 
    a = r; // ��������� �� ����� ������
    n = j; // ��������� ������ �������

    return *this; 
}

template <class B>
PatArr<B> PatArr<B>::operator-(B key) {
    int* r = new int[n - 1]; // ������� ����� ��������� ������
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != key) { // ���� ������� �� ����� key, ��������� ��� � ����� ������
            r[j++] = a[i];
        }
    }

    PatArr b(n - 1); // ������� ����� ������ ������� � ����������� ��������
    for (int i = 0; i < n - 1; i++) {
        b.a[i] = r[i]; // �������� �������� �� ����� ��������� ������
    }
    delete[] r; 
    return b;
}

template <class B>
PatArr<B>& PatArr<B>::DelPosEq(int pos) {
    if (pos < 0 || pos >= n) {
        return *this; // ���� ������ �����������, ���������� ������� ������
    }

    int* r = new int[n - 1]; 
    for (int i = 0; i < pos; i++) {
        r[i] = a[i]; // �������� �������� �� ������� ��������
    }
    for (int i = pos; i < n - 1; i++) {
        r[i] = a[i + 1]; // �������� ���������� ��������, ��������� ���������
    }

    delete[] a;
    a = r; // ��������� �� ����� ������
    n--; 

    return *this; 
}

template <class B>
PatArr<B> PatArr<B>::DelPosNew(int pos) {
    if (pos < 0 || pos >= n) {
        return *this; // ���� ������ �����������, ���������� ������� ������
    }

    int* r = new int[n - 1]; // ������� ����� ��������� ������ �������� �� 1 ������
    for (int i = 0; i < pos; i++) {
        r[i] = a[i]; // �������� �������� �� ������� ��������
    }
    for (int i = pos; i < n - 1; i++) {
        r[i] = a[i + 1]; // �������� ���������� ��������, ��������� ���������
    }

    PatArr b(n - 1); // ������� ����� ������ ������� � ����������� ��������
    for (int i = 0; i < n - 1; i++) {
        b.a[i] = r[i]; // �������� �������� � ����� ������
    }
    delete[] r; 
    return b; 
}

template <class B>
bool PatArr<B>::operator==(PatArr<B> x) const {
    if (n != x.n) { // ���������� ������� ��������
        return false; 
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != x.a[i]) { // ���������� �������� ��������
            return false; 
        }
    }
    std::cout << "������� �����" << std::endl; 
    return true; // ���� ��� �������� �����, ������� �����
}

template <class B>
bool PatArr<B>::operator!=(PatArr<B> x) const {
    return !(*this == x);
}


template<class B>
int PatArr<B>::Max() {
    if (n == 0) throw std::runtime_error("������ ����"); // ���������, �� ���� �� ������

    B maxVal = a[0]; // �������������� ������������ �������� ������ ���������
    for (int i = 1; i < n; i++) {
        if (a[i] > maxVal) {
            maxVal = a[i]; // ������� ������������ �������
        }
    }
    return maxVal; // ���������� ������������ ��������
}

template<class B>
int PatArr<B>::Min() {
    if (n == 0) throw std::runtime_error("������ ����"); // ���������, �� ���� �� ������

    B minVal = a[0]; // �������������� ����������� �������� ������ ���������
    for (int i = 1; i < n; i++) {
        if (a[i] < minVal) {
            minVal = a[i]; // ������� ����������� �������
        }
    }
    return minVal; // ���������� ����������� ��������
}

template<class B>
void PatArr<B>::Sorting() {
    // ���������� ������� ������� �������� 
    int tmp;
    for (int i = 0; i < n; i++) {
        tmp = a[i];
        for (int j = i; j < n; j++)
            if (tmp > a[j]) {
                // ����� ���������
                tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
    }
    // ������� ��������������� ������
    for (int i = 0; i < n; i++) {
        std::cout << "[" << a[i] << "]";
    }
}

template <class B>
B PatArr<B>::operator[](int index) const {
    // �������� �� ����� �� ������� �������
    if (index < 0 || index >= n) {
        std::cout << "������: ������ �� ��������� ���������!" << std::endl;
        return 0; // ��� ��������� ����������
    }
    return a[index];
}

template <class B>
B PatArr<B>::Get(int index) const {
    // �������� �� ����� �� ������� �������
    if (index < 0 || index >= n) {
        std::cout << "������: ������ �� ��������� ���������!" << std::endl;
        return 0; 
    }
    return a[index];
}

template <class B>
void PatArr<B>::Set(int index, B value) {
    if (index < 0 || index >= a.size()) {
        throw std::out_of_range("������ �� ��������� ���������!");
    }
    a[index] = value;
}
#endif
