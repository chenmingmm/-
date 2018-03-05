#include"Test.h"

void Test::Register(int id, ptf v)
{
	mList[id] = v;
}

void Test::Use(int id)
{
	auto iter = mList.find(id);
	if (iter!=mList.end())
	{
		iter->second();
	}
}
