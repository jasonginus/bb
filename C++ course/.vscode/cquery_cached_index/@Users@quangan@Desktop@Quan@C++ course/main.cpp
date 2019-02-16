// main.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include "TestOperatorOverload.h"
#include "TestTemplate.h"
#include "TestReferencesPointers.h"
#include "TestConst.h"
#include "TestSmartPointer.h"
#include "TestCountAndFind.h"
#include "TestSorting.h"
#include "TestCompareAndAccumulate.h"
#include "TestCollectionOperation.h"
#include "TestIterator.h"
#include "TestUsefulOperation.h"
#include "TestMoveSemantics.h"
using namespace std;

int main()
{
	TestOperatorOverload();
	TestTemplate();
	TestReferencesPointers();
	TestConst();
	TestSmartPointer();
	TestCountAndFind();
	TestSorting();
	testCompareAndAccumulate();
	testCollectionOperation();
	testIterator();
	testUsefulOperation();
	testMoveSemantics();
	return 0;
}

