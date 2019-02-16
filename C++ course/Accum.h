#pragma once
#include "Person.h"

template <class T>
class Accum
{
private:
	T total;
public:
	Accum(T start) : total(start) {}
	T operator+=(T const& t) { return total = total + t; }
	T GetTotal() const { return total; }
};


// template specialization
template <>
class Accum<Person>
{
private:
	int total;
public:
	Accum(int start) :total(start){};
	int operator+=(Person const& p) { return total = total + p.getAge(); }
	int GetTotal() const { return total; }
};
