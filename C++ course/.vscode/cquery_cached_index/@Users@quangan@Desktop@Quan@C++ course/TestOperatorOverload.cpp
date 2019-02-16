#include "Person.h"
#include "TestOperatorOverload.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::to_string;
#include <string>



void TestOperatorOverload() {
	Person p1 = Person("Quan", "Gan", 24);
	Person p2 = Person("Kavin", "Adam", 43);

	cout << p1.getName() << " is";
	if (p1 < p2) {
		cout << " smaller";
	}
	else {
		cout << " larger";
	}
	cout << " than " << p2.getName() << endl;

	p2.setAge(13);
	cout << p1.getName() << " is";
	if (p1 < p2) {
		cout << " smaller";
	}
	else {
		cout << " larger";
	}
	cout << " than " << p2.getName() << endl;

	int age = 43;
	cout << p1.getName() << " is";
	if (p1 < 43) {
		cout << " smaller";
	}
	else {
		cout << " larger";
	}
	cout << " than " << to_string(age) << endl;

	age = 22;
	cout << p1.getName() << " is";
	if (p1 < 43) {
		cout << " smaller";
	}
	else {
		cout << " larger";
	}
	cout << " than " << to_string(age) << endl;

	int i = 1;
	if (i = 2) {
		cout << "haha";
	}
}