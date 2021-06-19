/**
* @file modAlphaCipher.h
* @author Мещеряков В.А.
* @version 1.0
* @brief Описание класса modAlphaCipher
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <vector>
#include <string>
#include <map>
#include <locale>
#include "Error.h"
using namespace std;
/**  @brief  Класс, который предназначен для зашифрования и расшифрования сообщений методом Гронсвельда
* @details Работает только с русскоязычными сообщениями
* */
class modAlphaCipher
{
private:

    wstring numAlpha =L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///< Возможный алфавит для сообщений
    map <char,int> alphaNum; ///< Ассоциативный массив "номер по символу"
    vector <int> key; ///< Атрибут для ключа
    /**@brief Преобразование строки типа wstring в вектор(чисел)
     * @param s - строка для преобразования в вектор (чисел)
     * @return вектор чисел
     **/
    vector<int> convert(const wstring& s);
    /**@brief Преобразование вектора (чисел) в строку типа wstring
    * @param v - вектор(чисел) для преобразования в строку по индексам атрибута numAlpha
    * @return строка текста типа wstring
    **/
    wstring convert(const vector<int>& v);
    /**@brief Метод валидации ключа
    * @param  ws - ключ в виде строки, который нужно проверить на наличие ошибок
    * @details Письменные буквы алфавита в строке ключа переводятся в прописные
    * @throw Error, если ключ является пустым или в нём присутствуют запрещающие символы
    * @return Ключ в виде строки типа wstring, который успешно прошёл валидацию
    **/
    wstring getValidKey(const wstring & ws);
    /**@brief Метод валидации строки для зашифрования или расшифрования
    * @param  ws - строка для шифрования или расшифрования, которую нужно проверить на наличие ошибок
    * @details Письменные буквы алфавита в строке переводятся в прописные
    * @throw Error, если строка является пустой или в ней присутствуют запрещающие символы
    * @return строка типа wstring, которая успешно прошла валидацию
    **/
    wstring getValidOpenCipherText(const wstring & ws);

public:
    /// @brief Запрещающий конструктор без параметров
    modAlphaCipher()=delete;
    /** @brief Конструктор с параметром
     * @param skey - ключ в виде строки типа wstring
     */
    modAlphaCipher(const wstring& skey);
    /**@brief Метод для зашифрования русскоязычных сообщений методом Гронсфельда
     * @param open_text - строка, которую нужно зашифровать
     * @return зашифрованная строка типа wstring
     */
    wstring encrypt(const wstring& open_text);
    /**@brief Метод для расшифрования русскоязычных сообщений методом Гронсфельда
     * @param cipher_text - строка, которую нужно расшифровать
     * @return расшифровання строка типа wstring
     */
    wstring decrypt(const wstring& cipher_text);
};
