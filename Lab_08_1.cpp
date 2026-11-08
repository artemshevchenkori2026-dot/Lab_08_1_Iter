// Lab_08_1_Iter.cpp
// Варіант 29
// Лабораторна робота № 8.1

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Перевірка наявності хоча б однієї четвірки сусідніх однакових символів
bool Include(const char* str) {
    size_t len = strlen(str);
    if (len < 4) return false;

    for (size_t i = 0; i + 3 < len; i++) {
        if (str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i + 3]) {
            return true;
        }
    }
    return false;
}

// Заміна кожної четвірки сусідніх однакових символів парою зірочок "**"
char* Change(char* str) {
    size_t len = strlen(str);
    if (len < 4) return str;

    // Створення тимчасового буфера для нового рядка
    char* tmp = new char[len + 1];
    char* t = tmp;
    tmp[0] = '\0';

    size_t i = 0;
    while (i < len) {
        if (i + 3 < len && str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i + 3]) {
            strcat(t, "**");
            t += 2;
            i += 4; // Пропускаємо оброблену четвірку символів
        }
        else {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    strcpy(str, tmp);
    delete[] tmp;
    return str;
}

int main() {
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (Include(str)) {
        cout << "String contains four consecutive identical characters." << endl;
    }
    else {
        cout << "String does not contain four consecutive identical characters." << endl;
    }

    char* dest = new char[151];
    strcpy(dest, str);
    Change(dest);

    cout << "Modified string (param) : " << dest << endl;

    delete[] dest;
    return 0;
}