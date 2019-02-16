#include "TestCompareAndAccumulate.h"
#include <vector>
using std::vector;
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

int testCompareAndAccumulate()
{
	// equal & mismatch
	vector<int> v1 = { 1, 2, 3, 4, 5 };
	vector<int> v2 = { 1, 2, 0, 4, 5 };
	auto res = std::equal(begin(v1), end(v1), begin(v2), end(v2));
	auto i = std::mismatch(begin(v1), end(v1), begin(v2));
	auto value = *(i.first);
	value = *(i.second);

	// accumulate: default behavior related to operator+
	int i2 = std::accumulate(begin(v1), end(v1), 0);

	// accumulate with lambda
	i2 = std::accumulate(
		begin(v1),
		end(v1),
		0,
		[](int total, const int& elem) {
		if (elem % 2 == 0) {
			return total + elem;
		}
		else {
			return total;
		}
	}
	);

	// accumulate for string
	vector<string> s = { "apple", "banana", "pear" };
	string out = accumulate(
		begin(s),
		end(s),
		string{ "Words: " },
		[](const string& total, const string& elem) {
		return total + " " + elem;
	}
	);

	out = accumulate(
		begin(v1),
		end(v1),
		string{ "Numbers: " },
		[](const string& total, const int elem) {
		return total + " " + to_string(elem);
	}
	);

	// for auto
	for (auto& i : v1) {
		i++;
	}

	// for_each
	for_each(begin(v1), end(v1), [](int& i) { i *= 2; });

	return 0;
}
