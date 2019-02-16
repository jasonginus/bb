#include "Resource.h"

int Resource::objCount = 0;

Resource::Resource()
{
	objCount++;
}

Resource::Resource(const Resource & r)
{
	this->msg = r.msg;
	objCount++;
}

Resource& Resource::operator=(const Resource & r)
{
	msg = r.msg;
	return *this;
}

Resource::~Resource()
{
	std::cout << "deconstring resource " + msg << std::endl;
	objCount--;
}

void Resource::setResource(std::string msg)
{
	this->msg = msg;
}
