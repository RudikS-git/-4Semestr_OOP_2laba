#include "MapHelper.h"
#include <random>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

void InitSet(map<string, int>& many)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 100); // INT_MAX

    generate_n(inserter(many, many.begin()), N, [&]()
        {
            int value = dist(gen);

            string key;
            while (true)
            {
                key = (const char*)GenerateString();

                if (many.find(key) == many.end())
                break;

                delete (key.c_str());
            }

                return make_pair(key, value);
        });
}

char* GenerateString()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 25); // INT_MAX

    char* str = new char[N];
    for (int i = 0; i < N - 1; i++)
    {
        str[i] = (char)(65 + dist(gen));
    }

    str[N - 1] = '\0';

    return str;
}

int Average(map<string, int>& many)
{
    long long sum = 0;
    for (auto item : many)
    {
        sum += item.second;
    }

    return (int)sum / N;
}

void RemoveLessAvr(map<string, int>& many)
{
    int avr = Average(many);
    cout << "Avr: " << avr << endl << endl;


    while (true)
    {
        auto iter = upper_bound(many.begin(), many.end(), avr, [&](int value, const pair<const string, int>& item)
            {
                if (value > item.second)
                {
                    return true;
                }
                
                return false;
            });

        if (iter == many.end())
        {
            return;
        }

        many.erase(iter->first);

    }
}

void Show(string text, const map<string, int>& many)
{
    cout << text << endl;

    for_each(many.begin(), many.end(), [&](const pair<const string, int>& item) 
        {
            cout << item.first << " " << item.second << endl;
        });

    cout << endl << endl;
}

void MultByMaxItem(map<string, int>& many)
{
    auto it = max_element(many.begin(), many.end(), [&](const pair<const string, int>& firstItem, const pair<const string, int>& secondItem)
        {
            if (firstItem.second < secondItem.second)
                return true;
            return false;
        });
    
    int max = it->second;

    for_each(many.begin(), many.end(), [&] (const pair<const string, int> & item)
       {
          //  many.insert(make_pair(item.first, item.second * max));
            many[item.first] = item.second * max;
       });

}

bool RemoveByPosition(map<string, int>& many, int position)
{
   
    int dist = distance(many.begin(), many.end());
    if (dist <= position)
        return false;


    auto it = many.begin();
    for (int i = 0; i < position - 1; i++)
    {
        it++;
    }

    many.erase(it);

    return true;
}