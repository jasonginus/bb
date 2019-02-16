#include "TestReferencesPointers.h"
#include "Person.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void TestReferencesPointers(){
	// References
	int a = 4;
	int &ra = a;
	cout << "ra: " << ra << endl;
	ra = 5;
	cout << "after change, a: " << a << endl;

	Person p("Quan", "Gan", 111);
	Person& rp = p;
	cout << "Before change: " << p.getName() << endl;
	rp.setAge(222);
	cout << "After change: " << p.getName() << endl;

	// Pointers
	int* pA = &a;
	cout << "before chagne, pA: " << *pA << endl;
	*pA = 22;
	cout << "after change, a: " << a << endl;
	cout << "after change, rA: " << ra << endl;
	cout << "after change, pA: " << *pA << endl;

	Person* pP = &p;
	cout << "Before change: pP: " << pP->getName() << endl;
	(*pP).setAge(333);
	cout << "After change: p: " << p.getName() << endl;
	cout << "After change: rP: " << rp.getName() << endl;
	cout << "After change: pP: " << pP->getName() << endl;
}