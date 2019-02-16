#pragma once
#include <string>
#include <iostream>
#include "Resource.h"
#include <memory>

class Person
{
private:
	std::string firstName;
	std::string lastName;
	int age;
	std::shared_ptr<Resource> pr;
public:
	Person(
		std::string firstName,
		std::string lastName,
		int age
		);

	std::string getName() const {
		return "My name is " + firstName + " " + lastName +
			" with age " + std::to_string(age);
	};
	std::string getLastName() const { return lastName; }
	int getAge() const { return age; };
	void setAge(int age) { age = age; };
	void AddResource();
	std::string GetResource() const { return pr->GetResource(); }
	bool operator<(const Person& p) const;
	bool operator<(int age) const;
};

bool operator<(int age, const Person& p); 