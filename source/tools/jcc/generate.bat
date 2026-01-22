@ECHO ON
..\..\..\external\flex-bison\win_bison -d -v c11ansi.y
..\..\..\external\flex-bison\win_flex --yylineno c11ansi.l