#pragma once
#include <iostream>

using namespace std;

class ThereIsNoSuchElement : public std::exception
{
public:

	const char* what() const override
	{
		return "There is no such element";
	}

};

class NoSpaceInQueue : public std::exception
{
public :

	const char* what() const override
	{
		return "There is no space in the queue";
	}
};

