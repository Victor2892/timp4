/**
* @file Error.h
* @author Мещеряков В.А.
* @version 1.0
* @brief Описание класса Error
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <stdexcept>
#include <string>
using namespace std;
    /// @brief  Класс для обработки ошибок.
    /// Класс является наследником класса обработки исключений с названием invalid_argument
class Error : public invalid_argument
{
public:
    /// @brief Запрещающий конструктор без параметров
    Error() = delete;
    /** @brief Конструктор с параметром
     * @param what_arg - строка, которая хранит описание ошибки
     * @details Параметр конструктора перегружается конструктором базового класса с названием invalid_argument
     * */
    explicit Error(const string & what_arg) : invalid_argument(what_arg) {};
};
