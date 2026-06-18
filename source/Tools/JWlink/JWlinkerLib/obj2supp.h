#pragma once

#define MAX_ADDEND_SIZE ( 2 * sizeof( uint32_t ) )
#define GET_S16( P )    (*(int16_t *)(P))
#define FIX_POINTER_MASK ( FIX_BASE | FIX_HIGH | FIX_OFFSET_MASK )

void ResetObj2Supp();
