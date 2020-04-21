#include <iostream>
#include <set>
#include <random>
#include <iterator>
#include <algorithm>

using namespace std;

#define N 10

void InitSet(set<int>&);
int Average(set<int>&);
void RemoveLessAvr(set<int>&);
void ShowSet(string, const set<int>&);
void MultByMaxItem(set<int>&);

int main()
{
    // 4) найти элементы большие среднего арифметического и
    // удалить их из контейнера
    // 5) Каждый элемент домножить на максимальный элемент контейнера

    //  использовать ассоциативный контейнер, множество, отображение

    set<int> many;
    InitSet(many);

    ShowSet("Init items", many);
    RemoveLessAvr(many);
    ShowSet("Modified items(remove less avr)", many);

    MultByMaxItem(many);
    ShowSet("Second modified items(mult max element)", many);

}

void InitSet(set<int>& many)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 100); // INT_MAX

    for (int i = 0; i < N; i++)
    {
        int item = dist(gen);
        many.insert(item);
    }
}

int Average(set<int>& many)
{
    long long sum = 0;
    for (auto item : many)
    {
        sum += item;
    }

    return (int)sum / N;
}

void RemoveLessAvr(set<int>& many)
{
    int avr = Average(many);
    cout << "Avr: " << avr << endl << endl;

    while (true)
    {
        auto iter = upper_bound(many.begin(), many.end(), avr);

        if (iter == many.end())
        {
            return;
        }
       
        many.erase(*iter);
    }
}

void ShowSet(string text, const set<int>& many)
{
    cout << text << endl;
    copy(many.begin(), many.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
}

void MultByMaxItem(set<int>& many)
{
    int max = *many.rbegin();
    auto l = many.begin();

    set<int> newMany;
    for_each(many.begin(), many.end(), [&](int item)
    {
        newMany.insert(item * max);
    });

    many = newMany;  
}