%{
#include "global.h"
#include "util.h"
#include "parser.tab.h"
#include "scan.h"

int lineno;
FILE *source;
FILE *listing;
char tokenString[MAXTOKENLEN+1];
int scanTrace= 0;

%}
digit [0-9]
integer {digit}+
real {integer}\.{integer}
string \'[^\']*\'
char \'[.]\'
%%
[ \t]*	{}
"\n"	{lineno++;}
"{"	{	char c;
		do{
			c = input();
			if (c == EOF) break;
			if( c== '\n') lineno++;
		}while(c != '}');			
	}
[Pp][Rr][Oo][Gg][Rr][Aa][Mm]	{return PROGRAM;}
[Bb][Ee][Gg][Ii][Nn]	{return _BEGIN;}
[Ee][Nn][Dd]	{return _END;}
[Vv][Aa][Rr]	{return VAR;}
[Ii][Nn][Tt][Ee][Gg][Ee][Rr]	{return SYS_TYPE;}
[Rr][Ee][Aa][Ll]	{return SYS_TYPE;}
[Cc][Hh][Aa][Rr]	{return SYS_TYPE;}
[Ss][Tt][Rr][Ii][Nn][Gg]	{return SYS_TYPE;}
[Tt][Yy][Pp][Ee]		{return TYPE;}
[Aa][Rr][Rr][Aa][Yy]	{return ARRAY;}
[Oo][Ff]	{return OF;}
[Rr][Ee][Cc][Oo][Rr][Dd]	{return RECORD;}
[Cc][Oo][Nn][Ss][Tt]	{return CONST;}
[Ff][Uu][Nn][Cc][Tt][Ii][Oo][Nn]	{return FUNCTION;}
[Pp][Rr][Oo][Cc][Ee][Dd][Uu][Rr][Ee]	{return PROCEDURE;}
[Rr][Ee][Aa][Dd]	{return READ;}
[Ww][Rr][Ii][Tt][Ee][Ll][Nn]	{return WRITELN;}
[Ii][Ff]	{return IF;}
[Tt][Hh][Ee][Nn]	{return THEN;}
[Ee][Ll][Ss][Ee]		{return ELSE;}
[Rr][Ee][Pp][Ee][Aa][Tt]	{return REPEAT;}
[Uu][Nn][Tt][Ii][Ll]	{return UNTIL;}
[Ww][Hh][Ii][Ll][Ee]	{return WHILE;}
[Dd][Oo]	{return DO;}
[Ff][Oo][Rr]	{return FOR;}
[Tt][Oo]		{return TO;}
[Dd][Oo][Ww][Nn][Tt][Oo]	{return DOWNTO;}
[Gg][Oo][Tt][Oo]	{return GOTO;}
[Cc][Aa][Ss][Ee]	{return CASE;}
[Aa][Nn][Dd]	{return _AND;}
[Nn][Oo][Tt]	{return _NOT;}
[Oo][Rr]	{return _OR;}
{integer}	{return INTEGER;}
{real}		{return REAL;}
{char}		{return CHAR;}	
{string}		{return STRING;}

"("	{return 	LP;}
")"	{return RP;}
"["	{return LB;}
"]"	{return RB;}
":="	{return ASSIGN;}
"="	{return EQUAL;}
"!="	{return UNEQUAL;}
"."	{return DOT;}
","	{return COMMA;}
":"	{return COLON;}
";"	{return SEMI;}
"*"	{return _MUL;}
"/"	{return _DIV;}
"%"	{return _MOD;}
"+"	{return _PLUS;}
"-"	{return _MINUS;}
">="	{return _GE;}
">"	{return _GT;}
"<="	{return _LE;}
"<"	{return _LT;}
[a-zA-Z_][a-zA-Z0-9_]*	{return _ID;}
.	{return ERROR;}


%%
int getToken(void)
{
	static int firstTime = 1;
	int currentToken;
	if(firstTime)
	{
		firstTime =  0;
		lineno++;
		source = fopen("test.p","r");
		listing = fopen("listing","w+");
		yyin = source;
		yyout = listing;
	}
	currentToken = yylex();
	strncpy(tokenString,yytext,MAXTOKENLEN);
	if(scanTrace){
		fprintf(listing,"\t%d: ",lineno);
  		printToken(currentToken,tokenString);
	}
	return currentToken;
}

#ifndef yywrap
 int yywrap() {	return 1;  }
#endif
/*
void main() {
	lineno = 0;
	traceScan = 1;
	while(getToken() != 0);
}
*/