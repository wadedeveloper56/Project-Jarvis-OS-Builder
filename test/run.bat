@ECHO ON
MKDIR bin
MKDIR bin\windows
MKDIR bin\windows\x86
MKDIR bin\windows\x64
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\JWcc -b 64 -o bin\windows\x64\test1.asm test1.c > bin\windows\x64\test1.c.log
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\JWasm -coff -Fl=bin\windows\x64\test1.lst -Sa -Fobin\windows\x64\test1.obj test1.asm
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\JWasm -coff -Fl=bin\windows\x64\c064.lst -Sa -Fobin\windows\x64\c064.obj c064.asm
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\pedump -a bin\windows\x64\test1.obj > bin\windows\x64\test1.asm.log
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\pedump -a bin\windows\x64\c064.obj > bin\windows\x64\c064.asm.log

C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\JWcc -b 32 -o bin\windows\x86\test1.asm test1.c > bin\windows\x86\test1.c.log
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\JWasm -coff -Fl=bin\windows\x86\test1.lst -Sa -Fobin\windows\x86\test1.obj test1.asm
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\JWasm -coff -Fl=bin\windows\x86\c032.lst -Sa -Fobin\windows\x86\c032.obj c032.asm
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\pedump -a bin\windows\x86\test1.obj > bin\windows\x86\test1.asm.log
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\pedump -a bin\windows\x86\c032.obj > bin\windows\x86\c032.asm.log
