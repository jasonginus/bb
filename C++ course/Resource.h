#pragma once
#include<string>
#include<iostream>

class Resource{
private:
	std::string msg;
	static int objCount;
public:
	Resource();
	Resource(const Resource& r);
	Resource(std::string msg){ this->msg = msg; };
	Resource& operator=(const Resource& r);
	~Resource();
	std::string GetResource() const { return msg; };
	void setResource(std::string msg);
};