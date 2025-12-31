#include "pch.h"
#include "Linker.h"

int main(int argc, char** argv)
{
    Linker* linker = new Linker();
    linker->mainLine();
    delete linker;
    return 0;
}
