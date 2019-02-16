#include "TestIterator.h"
#include <array>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;


int testIterator()
{
	// Insert iterator
	vector<int> v1;
	fill_n(back_inserter(v1), 5, 3);
	generate_n(back_inserter(v1), 8,
		[n = 0]()mutable{ return ++n; });

	deque<int> d1;
	fill_n(back_inserter(d1), 5, 3);
	generate_n(front_inserter(d1), 8,
		[n = 0]()mutable{ return ++n; });

	vector<int> v2;
	copy(begin(v1), end(v1), back_inserter(v2));
	copy_if(begin(v1), end(v1), back_inserter(v2),
		[](const int elem) {return elem % 2 == 0; });

	vector<int> v3;
	transform(begin(v1), end(v1), back_inserter(v3),
		[](const int elem) {return elem % 2 == 0; });

	v3.clear();
	unique_copy(begin(v1), end(v1), back_inserter(v3));

	string setence = "Today is Monday";
	string reverse;
	reverse_copy(begin(setence), end(setence), back_inserter(reverse));

	// Reverse iterator
	vector<int> v5;
	copy(rbegin(v1), rend(v1), back_inserter(v5));

	// Iterator Arithmetic
	v2 = { 1, 2, 3, 4, 5, 6, 7, 8, 3, 9 };
	auto three = find(begin(v2), end(v2), 3);
	three++;
	auto rthree = find(rbegin(v2), rend(v2), 3);
	rthree++;
	rthree += 1;

	three = find(begin(v2), end(v2), 3);
	bool firstHalf = (three - begin(v2)) < (end(v2) - three);
	auto nine = find(begin(v2), end(v2), 9);
	firstHalf = (nine - begin(v2)) < (end(v2) - nine);

	// Const iterator
	array<const int, 5> ca = { 1, 2, 3, 4, 5 };
	auto it = begin(ca);
	it++;
	//*it = 2;

	auto it2 = begin(v1);
	it2++;
	*it2 = 3;

	auto cit = cbegin(v1);
	cit++;
	//*cit = 3;
	return 0;
}
