/*
 *	Script.cpp
 *  Стартовый модуль консольного приложения.
 *  Пример реализации интерпретатора подмножества BASIC-образного
 *  языка программирования, разработанный в качестве примера
 *  лабораторной работы к курсу ЛО САПР.
 */

#include <fstream>
#include <iostream>
#include <string>
#include "stdafx.h"
#include "executor.h"


int _tmain(int argc, _TCHAR* argv[])
{
    std::system("color F0");
    // ИСПРАВЛЕНИЕ ОШИБКИ ВВОДА ПУТИ К ФАЙЛУ СО СКРИПТОМ!
    std::string path /*= "test1.txt"*/;
    std::cout << "Input script path: ";
    std::cin >> path;

    try {
        // ИСПРАВЛЕНИЕ ОШИБКИ
        std::ifstream in(path); // Создание потока ввода
        if (!in) // Если не получилось создать поток ввода
            throw "Can't open file"; // Вывод сообщенния о том, что невозможно открыть файл
        execute_script(in); // Выполнение скрипта
    }
    catch (const char* s) {
        std::cerr << std::endl << "ERROR: " << s << std::endl; // Вывод сообщенния об ошибке
    }

    return 0;
}
