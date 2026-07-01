#include "pch.h"
#include "Orl2.h"
#include "orl.h"
#include "Memory.h"
#include "debug.h"

orl_funcs ORLFuncs = { nullptr, nullptr, AllocateMemory, FreeMemory };

Orl::Orl()
{
	ORLHandle = ORLInit(&ORLFuncs);
}

Orl::~Orl()
{
	DEBUG((DBG_OLD, "Orl destructor\n"));
	ORLFini(ORLHandle);
}	
