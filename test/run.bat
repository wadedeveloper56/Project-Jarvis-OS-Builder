@ECHO ON
REM SET LIB32=C:\PROGRA~1\MICROS~2\18\Insiders\VC\Tools\MSVC\14.51.36231\lib\x86\uwp\msvcrt.lib"
REM SET LIB64=C:\PROGRA~1\MICROS~2\18\Insiders\VC\Tools\MSVC\14.51.36231\lib\x64\uwp\msvcrt.lib"
SET LIB32=C:\PROGRA~2\WI3CF2~1\10\Lib\10.0.26100.0\um\x86\shell32.lib"
SET LIB64=C:\PROGRA~2\WI3CF2~1\10\Lib\10.0.26100.0\um\x64\shell32.lib"
SET KLIB32=C:\PROGRA~2\WI3CF2~1\10\Lib\10.0.26100.0\um\x86\kernel32.lib"
SET KLIB64=C:\PROGRA~2\WI3CF2~1\10\Lib\10.0.26100.0\um\x64\kernel32.lib"
MKDIR bin
MKDIR bin\windows
MKDIR bin\windows\x86
MKDIR bin\windows\x64
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\JWcc -b 64 -o bin\windows\x64\test1.asm test1.c > bin\windows\x64\test1.c.log
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\JWasm -coff -Fl=bin\windows\x64\test1.lst -Sa -Fobin\windows\x64\test1.obj test1.asm
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\JWasm -coff -Fl=bin\windows\x64\c064.lst -Sa -Fobin\windows\x64\c064.obj c064.asm
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\Win32\JWlinkOld format win pe option map=bin\windows\x64\test1.map file bin\windows\x64\test1.obj, bin\windows\x64\c064.obj lib %LIB64%,%KLIB64%  name bin\windows\x64\test1.exe
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\pedump -a bin\windows\x64\test1.obj > bin\windows\x64\test1.asm.log
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\pedump -a bin\windows\x64\c064.obj > bin\windows\x64\c064.asm.log

C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\JWcc -b 32 -o bin\windows\x86\test1.asm test1.c > bin\windows\x86\test1.c.log
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\JWasm -coff -Fl=bin\windows\x86\test1.lst -Sa -Fobin\windows\x86\test1.obj test1.asm
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\JWasm -coff -Fl=bin\windows\x86\c032.lst -Sa -Fobin\windows\x86\c032.obj c032.asm
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\Win32\JWlinkOld format win pe option map=bin\windows\x86\test1.map file bin\windows\x86\test1.obj, bin\windows\x86\c032.obj lib %LIB32%,%KLIB32%  name bin\windows\x86\test1.exe
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\pedump -a bin\windows\x86\test1.obj > bin\windows\x86\test1.asm.log
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\pedump -a bin\windows\x86\c032.obj > bin\windows\x86\c032.asm.log

C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\x64\JWasm -win64 win64_1.asm
C:\projects\OSDev\ProjectJarvis\bin\tools\Debug\WIn32\JWlinkOld  format win pe ru win file win64_1.obj op start=main