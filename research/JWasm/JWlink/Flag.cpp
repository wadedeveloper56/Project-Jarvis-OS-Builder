#include "pch.h"
#include "Flag.h"

Flag::Flag()
{
	flag = 0;
}

Flag::Flag(int value)
{
	flag = value;
}

Flag::~Flag()
{
}

int Flag::getFlag() 
{
	return flag;
}

Flag& Flag::operator|=(int mask)
{
	this->flag |= mask;
	return *this;
}

Flag& Flag::operator&=(int mask)
{
	this->flag &= mask;
	return *this;
}

int Flag::operator&(const Flag& other) const
{
	return Flag(this->flag & other.flag).getFlag();
}

int Flag::operator&(int other) const
{
	return Flag(this->flag & other).getFlag();
}

