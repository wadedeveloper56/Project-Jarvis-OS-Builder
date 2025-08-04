C:\projects\ProjectJarvis\bin\Release\x64\Compiler -b 32 -o test1.asm test1.c > test1.c.log
C:\projects\ProjectJarvis\bin\Release\x64\Assembler -f obj -l test1.lst test1.asm
C:\projects\ProjectJarvis\bin\Release\x64\DumpObj -d -t -r -l=test1.obj.lst test1.obj > test1.obj.log

