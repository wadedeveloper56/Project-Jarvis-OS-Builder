@ECHO OFF
C:\projects\dumpbin\dumpbin /ALL /RAWDATA:NONE C:\projects\ProjectJarvis\bin\tools\Release\Win32\test1.dll > test2.log 
C:\projects\ProjectJarvis\bin\tools\Release\x64\PEDump --ALL C:\projects\ProjectJarvis\bin\tools\Release\Win32\test1.dll > test3.log
C:\projects\research\pedump3\Release\x64\PEDump3 /A  C:\projects\ProjectJarvis\bin\tools\Release\Win32\test1.dll > test4.log