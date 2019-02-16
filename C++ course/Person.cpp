#include "Person.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

Person::Person(
	string firstName,
	string lastName,
	int age) :
	firstName(firstName),
	lastName(lastName),
	age(age) {}

void Person::AddResource() {
	pr.reset();
	pr = std::make_shared<Resource>("My Resource is " + getName());
}

bool Person::operator<(const Person& p) const {
	return age < p.getAge();
}

bool Person::operator<(int age) const {
	return this->age < age;
}

bool operator<(int age, const Person& p) {
	return age < p.getAge();
}