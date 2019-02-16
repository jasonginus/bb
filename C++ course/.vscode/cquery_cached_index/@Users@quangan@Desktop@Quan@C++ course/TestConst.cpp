#include "TestConst.h"
#include "Person.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

//int DoubleIt(int& x) {  will not working cause 10 is const & int
//	return x * 2;
//}

int DoubleIt(int const& x) {
	return x * 2;
}

void TestConst(){
	int ci = 7;
	int const & rci = ci;
	//int & rci3 = 10; not valid
	//rci += 1;  not valid
	int const i = 8;
	//int& ri = i; not valid
	int const & rci2 = i;
	//int const & const rci3 = ci;

	// int& const i = value; <==> int& i

	int j = 10;
	int doubleJ = DoubleIt(j);
	int doubleTen = DoubleIt(10);

	Person Quan("Quan", "Gan", 123);
	Quan.setAge(222);
	Person const& cQuan = Quan;
	int age = cQuan.getAge();
	//cQuan.setAge(333); cannot call non const function

	// Pointers
	int* const cpi = &ci;
	//cpi = &i; can not change address
	*cpi = 20;

	int const * cpi2 = &ci;
	cpi2 = &i;
	//*cpi2 = 33; // cannot change the value of target

	int const * const cpi3 = &ci; // cannot change address or value of target
	//cpi3 = &i; 
	//*cpi3 = 22;
	cout << *cpi3;
}