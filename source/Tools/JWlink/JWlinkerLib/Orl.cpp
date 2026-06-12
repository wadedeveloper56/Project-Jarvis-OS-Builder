#include "pch.h"
#include "Orl2.h"
#include "orl.h"
#include "Memory.h"

orl_funcs ORLFuncs = { nullptr, nullptr, AllocateMemory, FreeMemory };

Orl::Orl()
{
	ORLHandle = ORLInit(&ORLFuncs);
}

Orl::~Orl()
{
	ORLFini(ORLHandle);
}	
