#pragma once

#include <iostream>
#include <set>

#define N 10

using namespace std;

void InitSet(set<int>&);
int Average(set<int>&);
void RemoveLessAvr(set<int>&);
void ShowSet(string, const set<int>&);
void MultByMaxItem(set<int>&);