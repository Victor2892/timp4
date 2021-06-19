#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <locale>
#include <codecvt>
using namespace std;
int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    int e = 1;
    wstring r;
    wstring wstr,wK;
    cout << "Добро пожаловать в программу!" << endl;
    cout << "1 - операция шифрования русскоязычных сообщений методом Гронсвельда.\n";
    cout << "2 - операция расшифрования русскоязычных сообщений методом Гронсвельда.\n";
    cout << "exit - завершить работу программы.\n";
    cout << "Результат работы операции выводится строкой прописных букв русского алфавита.\n";
    while (e != 2) {
        cout << "Укажите операцию: ";
        wcin >> r;
        if (r == L"1") {
            cout << "Введите строку для шифрования: ";
            wcin.get();
            getline(wcin, wstr);
            cout << "Введите ключ: ";
            getline(wcin,wK);
            try {
                modAlphaCipher e(wK);
                wstring result = e.encrypt(wstr);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                cout<<codec.to_bytes(result)<<endl;
            } catch (const Error & e) {
                cout << "Ошибка: " << e.what() << endl;
            }
        } 
       if (r == L"2") {
            cout << "Введите строку для расшифрования: ";
            wcin.get();
            getline(wcin,wstr);
            cout << "Введите ключ: ";
            getline(wcin,wK);
            try {
                modAlphaCipher d(wK);
                wstring result = d.decrypt(wstr);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                cout<<codec.to_bytes(result)<<endl;
            } catch (const Error & e) {
                cout << "Ошибка: " <<  e.what() << endl;
            }
        }  
        if (r == L"exit") {
            cout << "До новых встреч!" << endl;
            e = 2;
            break;
        }

    }
    return 0;
}
