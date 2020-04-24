#include <iostream>

#include "MapHelper.h"
#include "SetHelper.h"

using namespace std;


int main()
{
    // 4) ����� �������� ������� �������� ��������������� �
    // ������� �� �� ����������
    // 5) ������ ������� ��������� �� ������������ ������� ����������

    //  ������������ ������������� ���������, ���������, �����������

    // �� 2� ������, ����� ��������� ��� ������� ��� �����������(map), ����� �������� ��� ��� �������� �������� �� ��������� �� �������(��������), 
    // ��� ��������� ����� ������������ genarate_n().����� ������, � ��������.

    set<int> many;
    InitSet(many);
    ShowSet("Init items", many);
    RemoveLessAvr(many);
    ShowSet("Modified items(remove less avr)", many);
    MultByMaxItem(many);
    ShowSet("Second modified items(mult max element)", many);


    cout << endl << endl;

    map<string, int> mapping;
    InitSet(mapping);
    Show("Init items", mapping);
    RemoveLessAvr(mapping);
    Show("Modified items(remove less avr)", mapping);
    MultByMaxItem(mapping);
    Show("Second modified items(mult max element)", mapping);
    RemoveByPosition(mapping, 8);
    Show("Third modified items(remove element)", mapping);
    
    
}