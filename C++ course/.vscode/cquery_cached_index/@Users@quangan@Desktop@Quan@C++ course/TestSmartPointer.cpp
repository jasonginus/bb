#include "TestSmartPointer.h"
#include "Person.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::to_string;
#include <string>
#include <memory>
using std::shared_ptr;
using std::make_shared;

void TestSmartPointer() {
	Person p("Quan", "Gan", 23);
	shared_ptr<Person> pp = make_shared<Person>(p);
	shared_ptr<Person> pp1(pp);
	{
		shared_ptr<Person> pp3 = pp;
	}
	cout << pp->getName() << endl;

	{
		shared_ptr<Person> pp2 = make_shared<Person>("Quan", "Gan", 23);
		pp2->AddResource();
		cout << pp2->GetResource() << endl;
	}
}