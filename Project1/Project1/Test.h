
#ifndef TEST_H
#define TEST_H

#pragma once

#include<map>

typedef void(*ptf)();

class Test
{
public:
	Test(){}
	virtual ~Test(){}

	void Register(int id,ptf v);
	void Use(int id);

private:

	std::map<int, ptf> mList;
};





#endif // !TEST_H
