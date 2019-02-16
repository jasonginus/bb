#include "TestSorting.h"
#include <vector>
using std::vector;
#include <algorithm>
#include "Person.h"
#include <random>


int TestSorting()
{
	vector<int> v = { 3, 2, 5, -9, 4, 0, -2, -2 };
	auto v2 = v; // deep copy by default
	vector<Person> p = {
		{"Kavin", "Adam", 2000},
		{"Jason", "Ben", 2000},
		{"Quan", "Gan", 1000},
		{"Frank", "Mike", 2000},
	};

	// sort
	sort(begin(v2), end(v2));

	// sort with lambda
	sort(
		begin(v2),
		end(v2),
		[](int e1, int e2) { return e1 > e2; }
	);

	// stable sort: sorting multiple times
	sort(
		begin(p),
		end(p),
		[](Person p1, Person p2) { return p1.getLastName() < p2.getLastName(); }
	);
	stable_sort(
		begin(p),
		end(p),
		[](Person p1, Person p2) { return p1.getAge() < p2.getAge(); }
	);

	// is sorted
	auto res = is_sorted(begin(v2), end(v2));
	res = is_sorted(
		begin(v2),
		end(v2),
		[](int e1, int e2) { return e1 > e2; }
	);

	// max, min, find, upper/lower bound
	sort(begin(v2), end(v2));
	auto i = NULL;
	if(is_sorted(begin(v2), end(v2)))
	{
		i = *std::upper_bound(
			begin(v2),
			end(v2),
			4
		);
		i = *std::lower_bound(
			begin(v2),
			end(v2),
			0
		);
	}
	i = *std::max_element(begin(v), end(v));
	i = *std::min_element(begin(v), end(v));
	i = *std::find(begin(v), end(v), 4);

	// shuffle
	std::random_device rd;
	std::mt19937 generator(rd());
	std::shuffle(
		begin(v2),
		end(v2),
		generator
	);

	// partial sort
	std::partial_sort(
		begin(v2),
		begin(v2)+3,
		end(v2)
	);

	// is sorted until: return iterator
	i = *std::is_sorted_until(begin(v2), end(v2));
	
	// partial sort copy: copy first n elements, after sorting, into new vector
	vector<int> v3(4);
	std::partial_sort_copy(
		begin(v),
		end(v),
		begin(v3),
		end(v3)
	);

	// nth element: do one-time partition based on place not value
	v2 = { 1, 5, 4, 2, 9, 7, 3, 8, 2 };
	i = *(begin(v2) + 4);
	std::nth_element(
		begin(v2),
		begin(v2)+4,
		end(v2)
	);
	i = *(begin(v2) + 4);

	return 0;
}
