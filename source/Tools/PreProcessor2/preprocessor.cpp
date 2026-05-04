#include "pch.h"
#include "preprocessor.h"

using namespace std;
using namespace WadeSpace::PreProcessor;

bool sameline(const Token* tok1, const Token* tok2)
{
    return tok1 && tok2 && tok1->location.sameline(tok2->location);
}
