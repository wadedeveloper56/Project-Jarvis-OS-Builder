#pragma once

#include "Memory.h"

#define _ChkAlloc( cast, dest, size ) dest = (cast)AllocateMemory(size)
