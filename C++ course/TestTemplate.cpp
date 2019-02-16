#include "Accum.h"
#include "Person.h"
#include <iostream>
#include "TestTemplate.h"
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void TestTemplate(){

	Accum<int> integers(0);
	integers += 9;
	integers += 10;
	cout << integers.GetTotal() << endl;

	Accum<string> strings("");
	strings += "haha";
	strings += " hehe";
	cout << strings.GetTotal() << endl;

	Accum<Person> start(0);

	Person p1("Quan", "Gan", 111);
	Person p2("Tian", "Cai", 222);
	start += p1;
	start += p2;
	cout << "total: " << start.GetTotal() << endl;
}