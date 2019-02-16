#include "TestMoveSemantics.h"
#include "ResourceDefault.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::vector;


ResourceDefault modifyResource(ResourceDefault r, string newMsg) {
	r.setMsg(newMsg);
	return r;
}

int testMoveSemantics()
{
	ResourceDefault q = ResourceDefault( "Quan Gan" );
	ResourceDefault r = modifyResource(q, "Kevin Adam"); // copy first and them move
	return 0;
}
