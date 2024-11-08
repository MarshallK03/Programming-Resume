#pragma once
using namespace std;
#include <vector>
#include <iostream>
template <typename Item_Type>

//declaration for recursive function to find the last occurence of a target in a vector
int linear_search(const vector<Item_Type>& items, const Item_Type& target, size_t pos_first);