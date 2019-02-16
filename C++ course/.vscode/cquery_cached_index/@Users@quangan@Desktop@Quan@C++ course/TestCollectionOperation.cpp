#include "TestCollectionOperation.h"
#include <algorithm>
#include <numeric>
#include <vector>
#include "Resource.h"
using namespace std;

int testCollectionOperation() {
	vector<int> v1 = { 6, 2, 1, 2, 3, 0 };
	// copy, copy_if, copy_n, copy_backward
	auto v2 = v1;
	
	vector<int> v3(v1.size());
	copy(begin(v1), end(v1), begin(v3));

	vector<int> v4(v1.size());
	copy(begin(v1), end(v1) - 1, begin(v4));

	vector<int> v5(v1.size());
	copy_if(begin(v1), end(v1), begin(v5),
		[](const int& elem) {return elem % 2 == 0; });

	vector<int> v6(v1.size());
	copy_n(begin(v1), 3, begin(v6));

	//copy(begin(v2), end(v2) - 1, begin(v2) + 1); // 3rd param is between first 2 params, should use copy backward instead
	v2 = v1;
	copy_backward(begin(v2), end(v2) - 1, end(v2));

	// Remove: erase, remove, remove_if
	v2 = v1;
	v2.erase(remove(begin(v2), end(v2), 2), end(v2));
	v2 = v1;
	v2.erase(remove_if(begin(v2), end(v2), [](const int& elem) {return elem % 2 == 0; }), end(v2));

	vector<Resource> resources(2); // enable tracepoint feature to check operation=, deconstructor
	resources[0].setResource("haha");
	resources[1].setResource("abcs");
	auto newEnd = remove_if(begin(resources), end(resources),
		[](const Resource& r) {return r.GetResource() == "haha"; });
	resources.erase(newEnd, end(resources));

	// Move
	v2.resize(10);
	v3.resize(10);
	iota(begin(v2), end(v2), 1);
	move(begin(v2), end(v2), begin(v3));
	move(begin(v2), end(v2) - 1, begin(v2) + 1);
	move_backward(begin(v3), end(v3) - 1, end(v3));

	// fill, fill_n
	v2 = vector<int>(10);
	fill(begin(v2), end(v2), 5);
	
	v3 = vector<int>(10);
	fill_n(begin(v3), 3, 5);

	// generator, generator_n
	v2 = vector<int>(10);
	//generate(begin(v2), end(v2), 4);
	//int start = 2;
	generate(begin(v2), end(v2), [start = 2]() mutable{return (start *= 2); });

	int nstart = 2;
	v3 = vector<int>(10);
	generate_n(begin(v3), 3, [&nstart](){return (nstart *= 2); });

	// Replace
	v2 = { 6, 2, 3, 2, 1, 5, 0 };
	replace(begin(v2), end(v2), 2, 4);
	replace_if(begin(v2), end(v2), [](const int& elem) {return elem % 2 == 0; }, 7);

	// Remove Duplicate
	v2 = { 1, 3, 3, 5, 5, 3 };
	auto it = unique(begin(v2), end(v2));
	v2.erase(it, end(v2));

	v2 = { 1, 3, 3, 5, 5, 3 };
	v3 = vector<int>(10);
	unique_copy(begin(v2), end(v2), begin(v3));

	// Reverse and Swapping
	iota(begin(v2), end(v2), 10);
	reverse(begin(v2), end(v2));
	reverse_copy(begin(v2), end(v2), begin(v3));
	
	v2 = { 1, 2, 3, 4 };
	v3 = { 6, 7, 8, 9 };
	iter_swap(begin(v2), begin(v3));

	// Transform V.S. for_each
	v2 = { 1, 2, 3, 4 };
	transform(begin(v2), end(v2), begin(v2), [](int elem) {return (elem *= 2); });
	v3 = { 4, 3, 2, 1 };
	v4 = vector<int>(4);
	// pair transform
	transform(begin(v2), end(v2), begin(v3), begin(v4),
		[](int elem1, int elem2) {return elem1 + elem2; });


	return 0;
}