C:\projects\ProjectJarvis\bin\Release\x64\Compiler -b 32 -o test1.asm test1.c > test1.c.log
C:\projects\ProjectJarvis\bin\Release\x64\Assembler -f win32 -l test1.lst test1.asm
C:\projects\ProjectJarvis\bin\Release\x64\Assembler -f win32 -l startup32.lst startup32.asm
C:\projects\ProjectJarvis\bin\Release\x64\DumpObj -d -t -r -l=test1.obj.lst test1.obj > test1.obj.log
C:\projects\ProjectJarvis\bin\Release\x64\DumpObj -d -t -r -l=startup32.obj.lst startup32.obj > startup32.obj.log
link  -nodefaultlib -subsystem:console -entry:_start startup32.obj test1.obj kernel32.lib
