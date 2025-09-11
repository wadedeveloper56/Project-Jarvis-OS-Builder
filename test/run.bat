@ECHO OFF
C:\projects\ProjectJarvis\bin\Release\x64\Compiler --help
C:\projects\ProjectJarvis\bin\Release\x64\Compiler -b 32 -o test1.asm test1.c > test1.c.log
C:\projects\ProjectJarvis\bin\Release\x64\Assembler -f win32 -l test1.lst test1.asm
C:\projects\ProjectJarvis\bin\Release\x64\Linker --help

