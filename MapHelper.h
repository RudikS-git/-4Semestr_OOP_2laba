#pragma once

#include <iostream>
#include <map>

#define N 10

using namespace std;

void InitSet(map<string, int>&);
int Average(map<string, int>&);
void RemoveLessAvr(map<string, int>&);
void Show(string, const map<string, int>&);
void MultByMaxItem(map<string, int>&);
char* GenerateString();
bool RemoveByPosition(map<string, int>&, int);

