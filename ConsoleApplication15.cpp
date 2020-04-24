#include <iostream>

#include "MapHelper.h"
#include "SetHelper.h"

using namespace std;


int main()
{
    // 4) найти элементы большие среднего арифметического и
    // удалить их из контейнера
    // 5) Каждый элемент домножить на максимальный элемент контейнера

    //  использовать ассоциативный контейнер, множество, отображение

    // По 2й работе, нужно выполнить еще задание для отображения(map), также добавить код для удаления элемента из множества по позиции(значению), 
    // для генерации лучше использовать genarate_n().Внеси правки, и оповести.

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