#include "pch.h"
#include "simplecpp.h"

using namespace simplecpp;
using namespace std;

MacroUsage::MacroUsage(const vector<string>& f, bool macroValueKnown_) : macroLocation(f), useLocation(f), macroValueKnown(macroValueKnown_) {}

IfCond::IfCond(const Location& location, const string& E, long long result) : location(location), E(E), result(result) {}

DUI::DUI() : clearIncludeCache(false), removeComments(false) {}
