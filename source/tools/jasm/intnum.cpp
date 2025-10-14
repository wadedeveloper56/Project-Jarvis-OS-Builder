#include "jasm.h"

/* static bitvect used for conversions */
static wordptr conv_bv;
/* static bitvects used for computation */
static wordptr result, spare, op1static, op2static;
static BitVector_from_Dec_static_data* from_dec_data;

void yasm_intnum_initialize(void)
{
    conv_bv = BitVector_Create(BITVECT_NATIVE_SIZE, FALSE);
    result = BitVector_Create(BITVECT_NATIVE_SIZE, FALSE);
    spare = BitVector_Create(BITVECT_NATIVE_SIZE, FALSE);
    op1static = BitVector_Create(BITVECT_NATIVE_SIZE, FALSE);
    op2static = BitVector_Create(BITVECT_NATIVE_SIZE, FALSE);
    from_dec_data = BitVector_from_Dec_static_Boot(BITVECT_NATIVE_SIZE);
}