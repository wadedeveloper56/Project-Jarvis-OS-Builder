#include "FunctionDefinition.h"

using namespace WadeSpace;
using namespace std;

FunctionDefinition::FunctionDefinition(DeclarationSpecifiers& ds, Declarator& dec, vector<Declaration>& dl, BaseStatement& bs) :ds(ds), dec(dec), dl(dl), bs(bs) {}
FunctionDefinition::FunctionDefinition(DeclarationSpecifiers& ds, Declarator& dec, BaseStatement& bs) :ds(ds), dec(dec), dl(nullopt), bs(bs) {}
FunctionDefinition::FunctionDefinition(Declarator& dec, vector<Declaration>& dl, BaseStatement& bs) :ds(nullopt), dec(dec), dl(dl), bs(bs) {}
FunctionDefinition::FunctionDefinition(Declarator& dec, BaseStatement& bs) :ds(nullopt), dec(dec), dl(nullopt), bs(bs) {}
FunctionDefinition::FunctionDefinition() :ds(nullopt), dec(nullopt), dl(nullopt), bs(nullopt) {}
FunctionDefinition::~FunctionDefinition() {}
