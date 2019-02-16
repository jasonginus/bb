#pragma once
#include <algorithm>
#include <vector>
#include <map>
using std::vector;
using std::map;
#include <iterator>
using std::begin;
using std::end;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
#include "TestCountAndFind.h"

void TestCountAndFind()
{
	vector<int> v = { 2, 2, 3, 4, 3, 2, 4, 4, 4, 2, 4 };
	int const target = 2;
	auto res = count(begin(v), end(v), target);
	res = count_if(begin(v), end(v), [](auto elem) {return elem % 2 == 1; });
	
	auto itres = find(begin(v), end(v), target);
	itres++; itres++;
	auto index = distance(begin(v), itres);
	index = itres - begin(v);

	itres = find_if(begin(v), end(v), [](auto elem) { return elem % 2 == 1; });
	index = distance(begin(v), itres);



	cout << "done" << endl;
}
