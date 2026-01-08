#pragma once
class Flag
{
	int flag;
public:
	Flag();
	Flag(int value);
	~Flag();
	int getFlag();
	Flag& operator|=(int mask);
	Flag& operator&=(int mask);
	int operator&(const Flag& other) const;
	int operator&(int other) const;
};

