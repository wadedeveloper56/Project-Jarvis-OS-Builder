#include "DirectDeclaratorProxy.h"

using namespace WadeSpace;
using namespace std;

DirectDeclaratorProxy::DirectDeclaratorProxy(DirectDeclarator* directDeclarator) : directDeclarator(directDeclarator)
{
}

DirectDeclaratorProxy::~DirectDeclaratorProxy()
{
}

bool DirectDeclaratorProxy::hasDirectDeclarator() const { return directDeclarator; }
DirectDeclarator* DirectDeclaratorProxy::getDirectDeclarator() const { return directDeclarator; }
