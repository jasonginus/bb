#pragma once
#include <string>
#include <iostream>
using std::cout;
using std::endl;
class ResourceDefault
{
  public:
	ResourceDefault(std::string msg) : msg(msg)
	{
		cout << "constructing " << msg << endl;
	};
	ResourceDefault(const ResourceDefault &rd)
	{
		cout << "copying " << rd.getName() << endl;
		msg = rd.getName();
	};
	~ResourceDefault()
	{
		cout << "destructing " << msg << endl;
	};
	ResourceDefault(ResourceDefault &rd)
	{
		cout << "move constructing " << rd.msg << endl;
		this->msg = std::move(rd.msg);
	};
	ResourceDefault &operator=(ResourceDefault &rd)
	{
		cout << "move assignment " << rd.msg << endl;
		if (this != &rd)
		{
			msg = std::move(rd.getName());
			rd.msg.clear();
		}
		return *this;
	}
	void setMsg(std::string msg)
	{
		this->msg = msg;
	}
	std::string getName() const { return msg; };

  private:
	std::string msg;
};
