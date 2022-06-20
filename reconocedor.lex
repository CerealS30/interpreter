/* Archivo con el reconocedor l�xico para la calculadora
Comandos:
flex calculadora.lex
bison -d calculadora.y
gcc lex.yy.c calculadora.tab.c -lfl
./a.out
*/

%{
#include<stdlib.h>
#include<math.h>
  /* Se incluye el archivo generado por bison para tener las definiciones
     de los tokens */
#include "reconocedor.tab.h"

int numlinea = 1;
double doubleVal;
//int yylval;
//float yyfloat;
%}

ENTERO [0-9]+
FLOTANTE [0-9]*"."[0-9]+
ID [A-Za-z$_][A-Za-z0-9$_]*

%%

{ENTERO} {yylval.entero = atoi(yytext); return INT; /* Convierte el NUM a n�mero entero*/}
{FLOTANTE} {doubleVal = atof(yytext); return FLOAT; /* Convierte el NUM a n�mero de punto flotante */}
program {return RES_PROGRAM;}
"+" {return SUMA;}
"-" {return RESTA;}
"*" {return MULT;}
"/" {return DIV;}
"(" {return PARI;}
")" {return PARF;}
":" {return COLON;}
";" {return SEMI;}
"," {return COMMA;}
"~" {return RES_MINUS;}
"=" {return EQUAL;}
"<" {return LESSER;}
">" {return GREATER;}
"<=" {return LEQUAL;}
">=" {return GEQUAL;}
"<-" {return LARROW;}
fun {return RES_FUN;}
for {return RES_FOR;}
do {return RES_DO;}
while {return RES_WHILE;}
if {return RES_IF;}
then {return THEN;}
else {return ELSE;}
"int" {return INTEGER;}
"float" {return FLOATING;}
repeat {return RES_REPEAT;}
until {return UNTIL;}
begin {return BGN;}
end {return END;}
step {return RES_STEP;}
var {return VAR;}
read {return RES_READ;}
print {return RES_PRINT;}
return {return RES_RETURN;}
{ID} {yylval.nombre = (char *) calloc(strlen(yytext) + 1, sizeof(char)); strcpy(yylval.nombre, yytext); return ID;}
[\n] {numlinea++;}
[ \t] { }
. {return -1;}

%%
