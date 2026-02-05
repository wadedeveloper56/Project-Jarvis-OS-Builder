@ECHO ON
REM C:\projects\"OS Dev"\ProjectJarvis\bin\Release\x64\Compiler --help
C:\projects\OSDev\ProjectJarvis\bin\tools\Release\x64\JWcc -b 32 -o test1.asm test1.c > test1.c.log
C:\projects\OSDev\ProjectJarvis\bin\tools\Release\x64\JWasm -coff -Fl=test1.lst test1.asm
C:\projects\OSDev\ProjectJarvis\bin\tools\Release\x64\pedump -a test1.obj > test1.asm.log
REM C:\projects\"OS Dev"\ProjectJarvis\bin\Release\x64\Linker --help

