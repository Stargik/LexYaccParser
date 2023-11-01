%{
    #include "y.tab.h"
    int countn=0;
%}

%option yylineno

alpha [a-zA-Z]
digit [0-9]
unary "++"|"--"

identifier [a-zA-Z_][0-9a-zA-Z_]*
exponent_part [eE][-+]?[0-9]+
fractional_constant ([0-9]*"."[0-9]+)|([0-9]+".")
floating_constant (({fractional_constant}{exponent_part}?)|([0-9]+{exponent_part}))[FfLl]?
integer_suffix ([uU]?[lL]?)|([lL][uU])
decimal_constant [1-9][0-9]*{integer_suffix}
octal_constant "0"[0-7]*{integer_suffix}
hex_constant "0"[xX][0-9a-fA-F]+{integer_suffix}

%%

auto                        { strcpy(yylval.nd_obj.name,(yytext)); return AUTO; }
break                       { strcpy(yylval.nd_obj.name,(yytext)); return BREAK; }
case                        { strcpy(yylval.nd_obj.name,(yytext)); return CASE; }
char                        { strcpy(yylval.nd_obj.name,(yytext)); return CHAR; }
const                       { strcpy(yylval.nd_obj.name,(yytext)); return CONST; }
continue                    { strcpy(yylval.nd_obj.name,(yytext)); return CONTINUE; }
default                     { strcpy(yylval.nd_obj.name,(yytext)); return DEFAULT; }
do                          { strcpy(yylval.nd_obj.name,(yytext)); return DO; }
double                      { strcpy(yylval.nd_obj.name,(yytext)); return DOUBLE; }
else                        { strcpy(yylval.nd_obj.name,(yytext)); return ELSE; }
enum                        { strcpy(yylval.nd_obj.name,(yytext)); return ENUM; }
extern                      { strcpy(yylval.nd_obj.name,(yytext)); return EXTERN; }
float                       { strcpy(yylval.nd_obj.name,(yytext)); return FLOAT; }
for                         { strcpy(yylval.nd_obj.name,(yytext)); return FOR; }
goto                        { strcpy(yylval.nd_obj.name,(yytext)); return GOTO; }
if                          { strcpy(yylval.nd_obj.name,(yytext)); return IF; }
inline                      { strcpy(yylval.nd_obj.name,(yytext)); return INLINE; }
int                         { strcpy(yylval.nd_obj.name,(yytext)); return INT; }
long                        { strcpy(yylval.nd_obj.name,(yytext)); return LONG; }
register                    { strcpy(yylval.nd_obj.name,(yytext)); return REGISTER; }
restrict                    { strcpy(yylval.nd_obj.name,(yytext)); return RESTRICT; }
return                      { strcpy(yylval.nd_obj.name,(yytext)); return RETURN; }
short                       { strcpy(yylval.nd_obj.name,(yytext)); return SHORT; }
signed                      { strcpy(yylval.nd_obj.name,(yytext)); return SIGNED; }
sizeof                      { strcpy(yylval.nd_obj.name,(yytext)); return SIZEOF; }
static                      { strcpy(yylval.nd_obj.name,(yytext)); return STATIC; }
struct                      { strcpy(yylval.nd_obj.name,(yytext)); return STRUCT; }
switch                      { strcpy(yylval.nd_obj.name,(yytext)); return SWITCH; }
typedef                     { strcpy(yylval.nd_obj.name,(yytext)); return TYPEDEF; }
union                       { strcpy(yylval.nd_obj.name,(yytext)); return UNION; }
unsigned                    { strcpy(yylval.nd_obj.name,(yytext)); return UNSIGNED; }
void                        { strcpy(yylval.nd_obj.name,(yytext)); return VOID; }
volatile                    { strcpy(yylval.nd_obj.name,(yytext)); return VOLATILE; }
while                       { strcpy(yylval.nd_obj.name,(yytext)); return WHILE; }
_Alignas                    { strcpy(yylval.nd_obj.name,(yytext)); return _ALIGNAS; }
_Alignof                    { strcpy(yylval.nd_obj.name,(yytext)); return _ALIGNOF; }
_Atomic                     { strcpy(yylval.nd_obj.name,(yytext)); return _ATOMIC; }
_Bool                       { strcpy(yylval.nd_obj.name,(yytext)); return _BOOL; }
_Complex                    { strcpy(yylval.nd_obj.name,(yytext)); return _COMPLEX; }
_Generic                    { strcpy(yylval.nd_obj.name,(yytext)); return _GENERIC; }
_Imaginary                  { strcpy(yylval.nd_obj.name,(yytext)); return _IMAGINARY; }
_Noreturn                   { strcpy(yylval.nd_obj.name,(yytext)); return _NORETURN; }
_Static_assert              { strcpy(yylval.nd_obj.name,(yytext)); return _STATIC_ASSERT; }
_Thread_locaL               { strcpy(yylval.nd_obj.name,(yytext)); return _THREAD_LOCAL; }
{identifier}                { strcpy(yylval.nd_obj.name,(yytext)); return IDENTIFIER;}
{decimal_constant}          { strcpy(yylval.nd_obj.name,(yytext)); return NUMBER; }
{octal_constant}            { strcpy(yylval.nd_obj.name,(yytext)); return NUMBER; }
{hex_constant}              { strcpy(yylval.nd_obj.name,(yytext)); return NUMBER; }
{floating_constant}         { strcpy(yylval.nd_obj.name,(yytext)); return NUMBER; }
^"#include"[ ]*<.+\.h>      { strcpy(yylval.nd_obj.name,(yytext)); return INCLUDE; }
"("                         { strcpy(yylval.nd_obj.name,(yytext)); return LP; }
")"                         { strcpy(yylval.nd_obj.name,(yytext)); return RP; }
","                         { strcpy(yylval.nd_obj.name,(yytext)); return COMMA; }
"#"                         { strcpy(yylval.nd_obj.name,(yytext)); return LETTICE; }
"##"                        { strcpy(yylval.nd_obj.name,(yytext)); return DLETTICE; }
"{"                         { strcpy(yylval.nd_obj.name,(yytext)); return LC; }
"}"                         { strcpy(yylval.nd_obj.name,(yytext)); return RC; }
"["                         { strcpy(yylval.nd_obj.name,(yytext)); return LB; }
"]"                         { strcpy(yylval.nd_obj.name,(yytext)); return RB; }
"."                         { strcpy(yylval.nd_obj.name,(yytext)); return DOT; }
"&"                         { strcpy(yylval.nd_obj.name,(yytext)); return AND; }
"*"                         { strcpy(yylval.nd_obj.name,(yytext)); return STAR; }
"+"                         { strcpy(yylval.nd_obj.name,(yytext)); return PLUS; }
"-"                         { strcpy(yylval.nd_obj.name,(yytext)); return MINUS; }
"~"                         { strcpy(yylval.nd_obj.name,(yytext)); return TILDA; }
"!"                         { strcpy(yylval.nd_obj.name,(yytext)); return NOT; }
"/"                         { strcpy(yylval.nd_obj.name,(yytext)); return DIV; }
"%"                         { strcpy(yylval.nd_obj.name,(yytext)); return MOD; }
"<"                         { strcpy(yylval.nd_obj.name,(yytext)); return LT; }
">"                         { strcpy(yylval.nd_obj.name,(yytext)); return MT; }
"^"                         { strcpy(yylval.nd_obj.name,(yytext)); return XOR; }
"|"                         { strcpy(yylval.nd_obj.name,(yytext)); return OR; }
"?"                         { strcpy(yylval.nd_obj.name,(yytext)); return QUESTION; }
":"                         { strcpy(yylval.nd_obj.name,(yytext)); return COLON; }
";"                         { strcpy(yylval.nd_obj.name,(yytext)); return SEMICOLON; }
"="                         { strcpy(yylval.nd_obj.name,(yytext)); return ASSIGN; }
"::"                        { strcpy(yylval.nd_obj.name,(yytext)); return DCOLON; }
"->"                        { strcpy(yylval.nd_obj.name,(yytext)); return ARROW; }
"++"                        { strcpy(yylval.nd_obj.name,(yytext)); return ICREMENT; }
"--"                        { strcpy(yylval.nd_obj.name,(yytext)); return DECREMENT; }
"<<"                        { strcpy(yylval.nd_obj.name,(yytext)); return DLT; }
">>"                        { strcpy(yylval.nd_obj.name,(yytext)); return DMT; }
"<="                        { strcpy(yylval.nd_obj.name,(yytext)); return LE; }
">="                        { strcpy(yylval.nd_obj.name,(yytext)); return GE; }
"=="                        { strcpy(yylval.nd_obj.name,(yytext)); return EQ; }
"!="                        { strcpy(yylval.nd_obj.name,(yytext)); return NE; }
"&&"                        { strcpy(yylval.nd_obj.name,(yytext)); return DAND; }
"||"                        { strcpy(yylval.nd_obj.name,(yytext)); return DOR; }
"*="                        { strcpy(yylval.nd_obj.name,(yytext)); return MULTASSIGN; }
"/="                        { strcpy(yylval.nd_obj.name,(yytext)); return DIVASSIGN; }
"%="                        { strcpy(yylval.nd_obj.name,(yytext)); return MODASSIGN; }
"+="                        { strcpy(yylval.nd_obj.name,(yytext)); return PLUSASSIGN; }
"-="                        { strcpy(yylval.nd_obj.name,(yytext)); return MINUSASSIGN; }
"<<="                       { strcpy(yylval.nd_obj.name,(yytext)); return DLTASSIGN; }
">>="                       { strcpy(yylval.nd_obj.name,(yytext)); return DMTASSIGN; }
"&="                        { strcpy(yylval.nd_obj.name,(yytext)); return ANDASSIGN; }
"^="                        { strcpy(yylval.nd_obj.name,(yytext)); return XORASSIGN; }
"|="                        { strcpy(yylval.nd_obj.name,(yytext)); return ORASSIGN; }
\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; }
[ \t]*                      { ; }
[\n]                        { countn++; }
.                           { strcpy(yylval.nd_obj.name,(yytext)); return *yytext; }
["].*["]                    { strcpy(yylval.nd_obj.name,(yytext)); return STR; }
['].[']                     { strcpy(yylval.nd_obj.name,(yytext)); return CHARACTER; }

%%

int yywrap() {
    return 1;
}
