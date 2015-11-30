#pragma once
#include <Windows.h>
#include <list>

class Actor
{
private:
	std::list<DWORD> ActorArray;
public:
	Actor();
	~Actor();
	void GetActor();
	void CheckDefinedActor();
};

