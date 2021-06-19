#include "Cipher.h"

void Cipher::getValidKey(const string & k)
{
    if (k.empty()) {
        throw CipherError("вы ввели пустой ключ. Ключ должен быть натуральным числом.");
    }

    if (k.find_first_of("-0123456789") == string::npos) {
        throw CipherError("вы ввели недопустимый ключ. Ключ должен быть натуральным числом.");
    }

    int res = stoi(k);
    if (res <= 0) {
        throw CipherError("вы ввели некорректный ключ. Ключ должен быть натуральным числом.");
    }
}
void Cipher::getValidOpenCipherText( wstring & ws)
{
    if (ws.empty())
        throw CipherError("вы ввели пустую строку.");
}


Cipher::Cipher(const string k )
{
    getValidKey(k);
    int kNumber= stoi(k);
    key = kNumber;
}

wstring Cipher::encrypt(wstring str) 
{
    getValidOpenCipherText(str);
    const int dlina = str.length();
    int count_stroki = ((dlina-1)/key)+1;
    int ind = 0;
    wchar_t matr[count_stroki][key];

    for (int i = 0; i < count_stroki; i++) {
        for (int j = 0; j < key; j++ ) {
            if (ind < dlina) {
                matr[i][j] = str[ind];
                ind++;
            } else {
                matr[i][j] =' ';
            }
        }
    }

    ind=0;
    str.clear();
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < count_stroki; j++ ) {
            if (ind <= dlina) {
                str = str + matr[j][i];
            }
            ind++;
        }
    }
    str[ind] = '\0';
    return str;
}

wstring Cipher::decrypt(wstring str)
{
    getValidOpenCipherText(str);
    const int dlina = str.length();
    int count_stroki = ((dlina-1)/key)+1;
    int ind = 0;
    wchar_t matr[count_stroki][key];

    for (int i = 0; i < key; i++) {
        for (int j = 0; j < count_stroki; j++ ) {
            if (ind < dlina) {
                matr[j][i] = str[ind];
                ind++;
            } else {
                matr[j][i] = ' ';
                ind++;
            }
        }
    }
    ind = 0;
    str.clear();
    for(int i = 0; i < count_stroki; i++) {
        for (int j = 0; j< key; j++) {
            if (ind < dlina) {
                str = str + matr[i][j];
            }
            ind++;
        }
    }
    str[ind] = '\0';
    return str;
}
