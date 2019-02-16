#include "TestUsefulOperation.h"
#include <random>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int testUsefulOperation()
{
	// init random 1 to 8 vector
	vector<int> v1;
	generate_n(back_inserter(v1), 8, [n = 0]() mutable { return (n += 1); });
	random_device rd;
	mt19937 g(rd());
	shuffle(begin(v1), end(v1), g);

	// partial_sort_copy --> top_n
	vector<int> v2(4);
	partial_sort_copy(begin(v1), end(v1), begin(v2), end(v2));

	// rotate --> move_within_collection
	iota(begin(v1), end(v1), 1);
	auto four = find(begin(v1), end(v1), 4);
	auto two = find(begin(v1), end(v1), 2);
	rotate(two, four, four + 1); 
	// move 4 ahead of 2: 1, 2, 3, 4, 5, 6, 7, 8 --> 1, 4, 2, 3, 5, 6, 7, 8

	// swap, iter_swap, swap_ranges
	iota(begin(v1), end(v1), 1);
	iota(begin(v2), end(v2), 10);
	swap(v1[1], v1[2]);
	swap(*begin(v1), *begin(v2));
	iter_swap(begin(v1), begin(v2));
	swap_ranges(begin(v1), begin(v1) + 2, begin(v2));

	// stable_partition --> gather
	v1 = { 1, 2, 3, 4, 5, 6, 7, 8 };
	stable_partition(begin(v1), end(v1), [](int elem) { return elem % 2 == 1; });
	two = find(begin(v1), end(v1), 2);
	rotate(
		begin(v1),
		two,
		two + 1
	);
	/*
	1*	1	2
	2	3	1
	3*	5	3
	4	7	5
	5*	2	7
	6	4	4
	7*	6	6
	8	8	8
	*/
	return 0;
}
