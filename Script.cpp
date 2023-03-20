/*
 *	Script.cpp
 *  ��������� ������ ����������� ����������.
 *  ������ ���������� �������������� ������������ BASIC-���������
 *  ����� ����������������, ������������� � �������� �������
 *  ������������ ������ � ����� �� ����.
 */

#include <fstream>
#include <iostream>
#include <string>
#include "stdafx.h"
#include "executor.h"


int _tmain(int argc, _TCHAR* argv[])
{
    std::system("color F0");
    // ����������� ������ ����� ���� � ����� �� ��������!
    std::string path /*= "test1.txt"*/;
    std::cout << "Input script path: ";
    std::cin >> path;

    try {
        // ����������� ������
        std::ifstream in(path); // �������� ������ �����
        if (!in) // ���� �� ���������� ������� ����� �����
            throw "Can't open file"; // ����� ���������� � ���, ��� ���������� ������� ����
        execute_script(in); // ���������� �������
    }
    catch (const char* s) {
        std::cerr << std::endl << "ERROR: " << s << std::endl; // ����� ���������� �� ������
    }

    return 0;
}
