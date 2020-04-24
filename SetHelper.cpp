#include "SetHelper.h"
#include <random>
#include <algorithm>
#include <iterator>

using namespace std;

void InitSet(set<int>& many)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 100); // INT_MAX

    generate_n(inserter(many, many.begin()), N, [&]() {return dist(gen); });
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