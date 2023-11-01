%{
#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.c"

void yyerror(const char *s);
int yylex();
int yywrap();
int search(char *name);

int ic_idx=0;
int tc_idx=0;
int temp_var=0;
int temp_r=1;
int label=0;
int is_for=0;
char buff[100];
char rbuff[100];
char errors[10][100];
char reserved[10][10] = {"int", "float", "char", "void", "if", "else", "for", "main", "return", "include"};
char icg[100][100];
char tcg[100][100];
struct regVar {
    char name[120];
    int rNumber;
} regVars[120];
    
double arResults[1000];

%}

%union { struct var_name {
            char name[120];
            int rNumber;
            struct node* nd;
        } nd_obj;

        struct var_name2 {
            char name[100];
            struct node* nd;
            char type[5];
        } nd_obj2;

        struct var_name3 {
            char name[100];
            struct node* nd;
            char if_body[5];
            char else_body[5];
        } nd_obj3;

    }

%token VOID
%token    <nd_obj>          AUTO                BREAK               CASE                CHAR                CONST               CONTINUE
%token    <nd_obj>          DEFAULT             DO                  DOUBLE              ELSE                ENUM                EXTERN
%token    <nd_obj>          FLOAT               FOR                 GOTO                IF                  INLINE              INT
%token    <nd_obj>          LONG                REGISTER            RESTRICT            RETURN              SHORT               SIGNED
%token    <nd_obj>          SIZEOF              STATIC              STRUCT              SWITCH              TYPEDEF             UNION
%token    <nd_obj>          UNSIGNED            VOLATILE            WHILE               _ALIGNAS            _ALIGNOF
%token    <nd_obj>          _ATOMIC             _BOOL               _COMPLEX            _GENERIC            _IMAGINARY          _NORETURN
%token    <nd_obj>          _STATIC_ASSERT      _THREAD_LOCAL       IDENTIFIER          NUMBER              INCLUDE             LP
%token    <nd_obj>          RP                  COMMA               LETTICE             DLETTICE            LC                  RC
%token    <nd_obj>          LB                  RB                  DOT                 AND                 STAR                PLUS
%token    <nd_obj>          MINUS               TILDA               NOT                 DIV                 MOD                 LT
%token    <nd_obj>          MT                  XOR                 OR                  QUESTION            COLON               SEMICOLON
%token    <nd_obj>          ASSIGN              DCOLON              ARROW               ICREMENT            DECREMENT           DLT
%token    <nd_obj>          DMT                 LE                  GE                  EQ                  NE                  DAND
%token    <nd_obj>          DOR                 MULTASSIGN          DIVASSIGN           MODASSIGN           PLUSASSIGN          MINUSASSIGN
%token    <nd_obj>          DLTASSIGN           DMTASSIGN           ANDASSIGN           XORASSIGN           ORASSIGN            COMMENT
%token    <nd_obj>          STR                 CHARACTER
%type     <nd_obj3>         condition
%type     <nd_obj2>         init value statement p_stetament //e_statement t_statement f_statement
%type     <nd_obj>          headers main body return datatype  arithmetic_bin_sign compare_bin_sign program else logic_bin_sign op_statement arithmetic_unar_sign
%%

program: headers main_function
;

headers: headers headers
| INCLUDE
|
;

main_function: main LP RP LC body return RC
;

return: RETURN statement SEMICOLON {
    int t = search($2.name);
    if(t != -1){
        sprintf(tcg[tc_idx++], "MOV R%d R%d\n", temp_r++, t);
    }else{
        sprintf(tcg[tc_idx++], "MOV R%d %s\n", temp_r++, $2.name);
    }
    sprintf(tcg[tc_idx++], "RET R%d\n", temp_r-1);
    
    if(t != -1){
        sprintf(tcg[tc_idx++], "\nResult: %lf\n", arResults[t-1]);
    }else{
        sprintf(tcg[tc_idx++], "\nResult: %s\n", $2.name);
    }
    
    
}
|
;

main: datatype IDENTIFIER
;

datatype: INT
| LONG
| FLOAT
| SHORT
| VOID
| CHAR
;

body: body body
| op_statement SEMICOLON
| op_if_else
| op_loop
| LC body RC
|
;

op_if_else: IF { is_for = 0; } LP condition RP { sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.if_body); sprintf(tcg[tc_idx++], "\n%s:\n", $4.if_body); } LC body RC { sprintf(icg[ic_idx++], "JUMP to L%d\n", label); sprintf(tcg[tc_idx++], "JMP L%d\n", label); sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.else_body); sprintf(tcg[tc_idx++], "\n%s:\n", $4.else_body); } else {
    sprintf(icg[ic_idx++], "\nLABEL L%d:\n", label++); sprintf(tcg[tc_idx++], "\nL%d:\n", label-1);
}
;

else: ELSE op_if_else
| ELSE LC body RC
|
;

condition: statement compare_bin_sign statement {
    if(is_for) {
        sprintf($$.if_body, "L%d", label++);
        sprintf(tcg[tc_idx++], "\n%s:\n", $$.if_body);
        sprintf(icg[ic_idx++], "\nLABEL %s:\n", $$.if_body);
        sprintf(icg[ic_idx++], "\nif NOT (%s %s %s) GOTO L%d\n", $1.name, $2.name, $3.name, label);
        sprintf($$.else_body, "L%d", label++);
        int t1 = search($1.name);
        if(t1 != -1){
            int t2 = search($3.name);
            if(t2 != -1){
                sprintf(tcg[tc_idx++], "CMP R%d R%d\n", t1, t2);
            }else{
                sprintf(tcg[tc_idx++], "CMP R%d %s\n", t1, $3.name);
            }
        }else{
            int t2 = search($3.name);
            if(t2 != -1){
                sprintf(tcg[tc_idx++], "CMP R%d R%d\n", temp_r++, t2);
            }else{
                sprintf(tcg[tc_idx++], "CMP R%d %s\n", temp_r++, $3.name);
            }
        }
        if(!strcmp($2.name, "<")){
            sprintf(tcg[tc_idx++], "JGE L%d\n", label-1);
        }else if(!strcmp($2.name, "<=")){
            sprintf(tcg[tc_idx++], "JG L%d\n", label-1);
        }else if(!strcmp($2.name, ">")){
            sprintf(tcg[tc_idx++], "JLE L%d\n", label-1);
        }else if(!strcmp($2.name, ">=")){
            sprintf(tcg[tc_idx++], "JL L%d\n", label-1);
        }
    }
    else {
        sprintf(icg[ic_idx++], "\nif (%s %s %s) GOTO L%d else GOTO L%d\n", $1.name, $2.name, $3.name, label, label+1);
        sprintf($$.if_body, "L%d", label++);
        sprintf($$.else_body, "L%d", label++);
        int t1 = search($1.name);
        if(t1 != -1){
            int t2 = search($3.name);
            if(t2 != -1){
                sprintf(tcg[tc_idx++], "CMP R%d R%d\n", t1, t2);
            }else{
                sprintf(tcg[tc_idx++], "CMP R%d %s\n", t1, $3.name);
            }
        }else{
            int t2 = search($3.name);
            if(t2 != -1){
                sprintf(tcg[tc_idx++], "CMP R%d R%d\n", temp_r++, t2);
            }else{
                sprintf(tcg[tc_idx++], "CMP R%d %s\n", temp_r++, $3.name);
            }
        }
        if(!strcmp($2.name, "<")){
            sprintf(tcg[tc_idx++], "JGE L%d\n", label-1);
        }else if(!strcmp($2.name, "<=")){
            sprintf(tcg[tc_idx++], "JG L%d\n", label-1);
        }else if(!strcmp($2.name, ">")){
            sprintf(tcg[tc_idx++], "JLE L%d\n", label-1);
        }else if(!strcmp($2.name, ">=")){
            sprintf(tcg[tc_idx++], "JL L%d\n", label-1);
        }
    }
}
| condition logic_bin_sign condition {
    if(is_for) {
        sprintf($$.if_body, "L%d", label++);
        sprintf(icg[ic_idx++], "\nLABEL %s:\n", $$.if_body);
        sprintf(icg[ic_idx++], "\nif NOT (%s %s %s) GOTO L%d\n", $1.name, $2.name, $3.name, label);
        sprintf($$.else_body, "L%d", label++);
    }
    else {
        sprintf(icg[ic_idx++], "\nif (%s %s %s) GOTO L%d else GOTO L%d\n", $1.name, $2.name, $3.name, label, label+1);
        sprintf($$.if_body, "L%d", label++);
        sprintf($$.else_body, "L%d", label++);
        int t1 = search($1.name);
        if(t1 != -1){
            int t2 = search($3.name);
            if(t2 != -1){
                sprintf(tcg[tc_idx++], "CMP R%d R%d\n", t1, t2);
            }else{
                sprintf(tcg[tc_idx++], "CMP R%d %s\n", t1, $3.name);
            }
        }else{
            int t2 = search($3.name);
            if(t2 != -1){
                sprintf(tcg[tc_idx++], "CMP R%d R%d\n", temp_r++, t2);
            }else{
                sprintf(tcg[tc_idx++], "CMP R%d %s\n", temp_r++, $3.name);
            }
        }
        if(!strcmp($2.name, "<")){
            sprintf(tcg[tc_idx++], "JGE L%d\n", label-1);
        }else if(!strcmp($2.name, "<=")){
            sprintf(tcg[tc_idx++], "JG L%d\n", label-1);
        }else if(!strcmp($2.name, ">")){
            sprintf(tcg[tc_idx++], "JLE L%d\n", label-1);
        }else if(!strcmp($2.name, ">=")){
            sprintf(tcg[tc_idx++], "JL L%d\n", label-1);
        }
    }
}
| logic_unar_sign condition
| LP condition RP
;

op_loop: for_loop
| while_loop
| do_while_loop
;

for_loop: FOR { is_for = 1; } LP op_statement SEMICOLON condition SEMICOLON statement RP LC body RC {
    sprintf(icg[ic_idx++], buff);
    sprintf(icg[ic_idx++], "JUMP to %s\n", $6.if_body);
    sprintf(icg[ic_idx++], "\nLABEL %s:\n", $6.else_body);
    sprintf(tcg[tc_idx++], rbuff);
    sprintf(tcg[tc_idx++], "JMP %s\n", $6.if_body);
    sprintf(tcg[tc_idx++], "\n%s:\n", $6.else_body);
}
;

while_loop: WHILE { is_for = 1; } LP condition RP LC body RC {
    sprintf(icg[ic_idx++], "JUMP to %s\n", $4.if_body);
    sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.else_body);
    sprintf(tcg[tc_idx++], "JMP %s\n", $4.if_body);
    sprintf(tcg[tc_idx++], "\n%s:\n", $4.else_body);
}
;

do_while_loop: DO LC body RC WHILE LP condition RP SEMICOLON
;

op_statement: datatype IDENTIFIER init {
    sprintf(icg[ic_idx++], "%s = %s\n", $2.name, $3.name);
    $2.rNumber = temp_r;
    strcpy(regVars[temp_r-1].name, $2.name);
    regVars[temp_r-1].rNumber = temp_r;
    int t0 = search($3.name);
    if(t0 != -1){
        arResults[temp_r-1] = arResults[t0-1];
    }else{
        char *ptr;
        arResults[temp_r-1] = strtod($3.name, &ptr);
    }
    //sprintf(tcg[tc_idx++], "%lf\n", arResults[temp_r-1]);
    if(strcmp($3.name, "NULL")){
        int t = search($3.name);
        if(t != -1){
            sprintf(tcg[tc_idx++], "MOV R%d R%d\n", temp_r++, t);
        }else{
            sprintf(tcg[tc_idx++], "MOV R%d %s\n", temp_r++, $3.name);
        }
    }else{
        temp_r++;
    }
}
| IDENTIFIER assign_sign statement { 
    sprintf(icg[ic_idx++], "%s = %s\n", $1.name, $3.name);
    int t = search($1.name);
    if(t != -1){
        int t2 = search($3.name);
        if(t2 != -1){
            arResults[t-1] = arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "MOV R%d R%d\n", t, t2);
        }else{
            char *ptr;
            arResults[t-1] = strtod($3.name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "MOV R%d %s\n", t, $3.name);
        }
    }
}
| arithmetic_unar_sign statement {
    if(!strcmp($1.name, "++")) {
        sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, $2.name, $2.name, temp_var++);
        int t0 = search($2.name);
        if(t0 != -1){
            sprintf(rbuff, "ADD R%d 1\n", t0);
            arResults[t0-1]++;
        }
    }
    else {
        sprintf(buff, "t%d = %s - 1\n%s = t%d\n", temp_var, $2.name, $2.name, temp_var++);
        int t0 = search($2.name);
        if(t0 != -1){
            sprintf(rbuff, "SUB R%d 1\n", t0);
            arResults[t0-1]--;
        }
    }
}
| statement arithmetic_unar_sign {
    if(!strcmp($2.name, "++")) {
        sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, $1.name, $1.name, temp_var++);
        int t0 = search($1.name);
        if(t0 != -1){
            sprintf(rbuff, "ADD R%d 1\n", t0);
            arResults[t0-1]++;
        }
    }
    else {
        sprintf(buff, "t%d = %s - 1\n%s = t%d\n", temp_var, $1.name, $1.name, temp_var++);
        int t0 = search($1.name);
        if(t0 != -1){
            sprintf(rbuff, "SUB R%d 1\n", t0);
            arResults[t0-1]--;
        }
    }
}
| LP op_statement RP
| CONTINUE
| BREAK
| IDENTIFIER LP STR RP { sprintf(tcg[tc_idx++], "CALL %s\n", $1.name); }
| IDENTIFIER LP STR COMMA AND IDENTIFIER RP { sprintf(tcg[tc_idx++], "CALL %s\n", $1.name); }
;

init: ASSIGN statement { sprintf($$.type, $2.type); strcpy($$.name, $2.name); }
| { sprintf($$.type, "null"); strcpy($$.name, "NULL"); }
;

value: NUMBER
| STR
| CHARACTER
;

statement: p_stetament
| statement PLUS statement {
    sprintf($$.name, "t%d", temp_var);
    temp_var++;
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
    strcpy(regVars[temp_r-1].name, $$.name);
    regVars[temp_r-1].rNumber = temp_r;
    int t0 = search($1.name);
    if(t0 != -1){
        sprintf(tcg[tc_idx++], "MOV R%d R%d\n", temp_r++, t0);
        int t = search($$.name);
        if(t != -1){
            arResults[t-1] = arResults[t0-1];
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }else{
        sprintf(tcg[tc_idx++], "MOV R%d %s\n", temp_r++, $1.name);
        int t = search($$.name);
        if(t != -1){
            char *ptr;
            arResults[t-1] = strtod($1.name, &ptr);
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }
    int t = search($$.name);
    if(t != -1){
        int t2 = search($3.name);
        if(t2 != -1){
            arResults[t-1] = arResults[t-1] + arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "ADD R%d R%d\n", t, t2);
        }else{
            char *ptr;
            arResults[t-1] = arResults[t-1] + strtod($3.name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "ADD R%d %s\n", t, $3.name);
        }
    }else{
        int t2 = search($3.name);
        if(t2 != -1){
            sprintf(tcg[tc_idx++], "ADD R%d R%d\n", temp_r++, t2);
        }else{
            sprintf(tcg[tc_idx++], "ADD R%d %s\n", temp_r++, $3.name);
        }
    }
}
| statement MINUS statement {
    sprintf($$.name, "t%d", temp_var);
    temp_var++;
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
    strcpy(regVars[temp_r-1].name, $$.name);
    regVars[temp_r-1].rNumber = temp_r;
    int t0 = search($1.name);
    if(t0 != -1){
        sprintf(tcg[tc_idx++], "MOV R%d R%d\n", temp_r++, t0);
        int t = search($$.name);
        if(t != -1){
            arResults[t-1] = arResults[t0-1];
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }else{
        sprintf(tcg[tc_idx++], "MOV R%d %s\n", temp_r++, $1.name);
        int t = search($$.name);
        if(t != -1){
            char *ptr;
            arResults[t-1] = strtod($1.name, &ptr);
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }
    int t = search($$.name);
    if(t != -1){
        int t2 = search($3.name);
        if(t2 != -1){
            arResults[t-1] = arResults[t-1] - arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "SUB R%d R%d\n", t, t2);
        }else{
            char *ptr;
            arResults[t-1] = arResults[t-1] - strtod($3.name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "SUB R%d %s\n", t, $3.name);
        }
    }else{
        int t2 = search($3.name);
        if(t2 != -1){
            arResults[t-1] = arResults[t-1] - arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "SUB R%d R%d\n", temp_r++, t2);
        }else{
            char *ptr;
            arResults[t-1] = arResults[t-1] - strtod($3.name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "SUB R%d %s\n", temp_r++, $3.name);
        }
    }
}
;

p_stetament: value { strcpy($$.name, $1.name); sprintf($$.type, $1.type); }
| IDENTIFIER
| p_stetament STAR p_stetament {
    sprintf($$.name, "t%d", temp_var);
    temp_var++;
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
    strcpy(regVars[temp_r-1].name, $$.name);
    regVars[temp_r-1].rNumber = temp_r;
    int t0 = search($1.name);
    if(t0 != -1){
        sprintf(tcg[tc_idx++], "MOV R%d R%d\n", temp_r++, t0);
        int t = search($$.name);
        if(t != -1){
            arResults[t-1] = arResults[t0-1];
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }else{
        sprintf(tcg[tc_idx++], "MOV R%d %s\n", temp_r++, $1.name);
        int t = search($$.name);
        if(t != -1){
            char *ptr;
            arResults[t-1] = strtod($1.name, &ptr);
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }
    int t = search($$.name);
    if(t != -1){
        int t2 = search($3.name);
        if(t2 != -1){
            arResults[t-1] = arResults[t-1] * arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "MULT R%d R%d\n", t, t2);
        }else{
            char *ptr;
            arResults[t-1] = arResults[t-1] * strtod($3.name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "MULT R%d %s\n", t, $3.name);
        }
    }else{
        int t2 = search($3.name);
        if(t2 != -1){
            sprintf(tcg[tc_idx++], "MULT R%d R%d\n", temp_r++, t2);
        }else{
            sprintf(tcg[tc_idx++], "MULT R%d %s\n", temp_r++, $3.name);
        }
    }
}
| p_stetament DIV p_stetament {
    sprintf($$.name, "t%d", temp_var);
    temp_var++;
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
    strcpy(regVars[temp_r-1].name, $$.name);
    regVars[temp_r-1].rNumber = temp_r;
    int t0 = search($1.name);
    if(t0 != -1){
        sprintf(tcg[tc_idx++], "MOV R%d R%d\n", temp_r++, t0);
        int t = search($$.name);
        if(t != -1){
            arResults[t-1] = arResults[t0-1];
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }else{
        sprintf(tcg[tc_idx++], "MOV R%d %s\n", temp_r++, $1.name);
        int t = search($$.name);
        if(t != -1){
            char *ptr;
            arResults[t-1] = strtod($1.name, &ptr);
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }
    int t = search($$.name);
    if(t != -1){
        int t2 = search($3.name);
        if(t2 != -1){
            arResults[t-1] = arResults[t-1] / arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "DIV R%d R%d\n", t, t2);
        }else{
            char *ptr;
            arResults[t-1] = arResults[t-1] / strtod($3.name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "DIV R%d %s\n", t, $3.name);
        }
    }else{
        int t2 = search($3.name);
        if(t2 != -1){
            sprintf(tcg[tc_idx++], "DIV R%d R%d\n", temp_r++, t2);
        }else{
            sprintf(tcg[tc_idx++], "DIV R%d %s\n", temp_r++, $3.name);
        }
    }
}
| p_stetament MOD p_stetament {
    sprintf($$.name, "t%d", temp_var);
    temp_var++;
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
}
| arithmetic_unar_sign p_stetament {
    if(!strcmp($2.name, "++")) {
        sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, $2.name, $2.name, temp_var++);
        int t0 = search($1.name);
        if(t0 != -1){
            sprintf(rbuff, "ADD R%d 1\n", t0);
            arResults[t0-1]++;
        }
    }
    else {
        sprintf(buff, "t%d = %s - 1\n%s = t%d\n", temp_var, $2.name, $2.name, temp_var++);
        int t0 = search($2.name);
        if(t0 != -1){
            sprintf(rbuff, "SUB R%d 1\n", t0);
            arResults[t0-1]--;
        }
    }
}
| p_stetament arithmetic_unar_sign {
    if(!strcmp($2.name, "++")) {
        sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, $1.name, $1.name, temp_var++);
        int t0 = search($1.name);
        if(t0 != -1){
            sprintf(rbuff, "ADD R%d 1\n", t0);
            arResults[t0-1]++;
        }
    }
    else {
        sprintf(buff, "t%d = %s - 1\n%s = t%d\n", temp_var, $1.name, $1.name, temp_var++);
        int t0 = search($1.name);
        if(t0 != -1){
            sprintf(rbuff, "SUB R%d 1\n", t0);
            arResults[t0-1]--;
        }
    }
}
| LP p_stetament RP { strcpy($$.name, $2.name); sprintf($$.type, $2.type); }
| LP p_stetament PLUS p_stetament RP {
    sprintf($$.name, "t%d", temp_var);
    temp_var++;
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $2.name, $3.name, $4.name);
    strcpy(regVars[temp_r-1].name, $$.name);
    regVars[temp_r-1].rNumber = temp_r;
    int t0 = search($2.name);
    if(t0 != -1){
        sprintf(tcg[tc_idx++], "MOV R%d R%d\n", temp_r++, t0);
        int t = search($$.name);
        if(t != -1){
            arResults[t-1] = arResults[t0-1];
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }else{
        sprintf(tcg[tc_idx++], "MOV R%d %s\n", temp_r++, $2.name);
        int t = search($$.name);
        if(t != -1){
            char *ptr;
            arResults[t-1] = strtod($1.name, &ptr);
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }
    int t = search($$.name);
    if(t != -1){
        int t2 = search($4.name);
        if(t2 != -1){
            arResults[t-1] = arResults[t-1] + arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "ADD R%d R%d\n", t, t2);
        }else{
            char *ptr;
            arResults[t-1] = arResults[t-1] + strtod($4.name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "ADD R%d %s\n", t, $4.name);
        }
    }else{
        int t2 = search($4.name);
        if(t2 != -1){
            sprintf(tcg[tc_idx++], "ADD R%d R%d\n", temp_r++, t2);
        }else{
            sprintf(tcg[tc_idx++], "ADD R%d %s\n", temp_r++, $4.name);
        }
    }
}
| LP p_stetament MINUS p_stetament RP {
    sprintf($$.name, "t%d", temp_var);
    temp_var++;
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $2.name, $3.name, $4.name);
    strcpy(regVars[temp_r-1].name, $$.name);
    regVars[temp_r-1].rNumber = temp_r;
    int t0 = search($2.name);
    if(t0 != -1){
        sprintf(tcg[tc_idx++], "MOV R%d R%d\n", temp_r++, t0);
        int t = search($$.name);
        if(t != -1){
            arResults[t-1] = arResults[t0-1];
        }
        //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
    }else{
        sprintf(tcg[tc_idx++], "MOV R%d %s\n", temp_r++, $2.name);
    }
    int t = search($$.name);
    if(t != -1){
        int t2 = search($4.name);
        if(t2 != -1){
            arResults[t-1] = arResults[t-1] - arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "SUB R%d R%d\n", t, t2);
        }else{
            char *ptr;
            arResults[t-1] = arResults[t-1] - strtod($4.name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "SUB R%d %s\n", t, $4.name);
        }
    }else{
        int t2 = search($4.name);
        if(t2 != -1){
            arResults[t-1] = arResults[t-1] - arResults[t2-1];
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "SUB R%d R%d\n", temp_r++, t2);
        }else{
            char *ptr;
            arResults[t-1] = arResults[t-1] - strtod($3.name, &ptr);
            //sprintf(tcg[tc_idx++], "%lf\n", arResults[t-1]);
            sprintf(tcg[tc_idx++], "SUB R%d %s\n", temp_r++, $4.name);
        }
    }
}
;

arithmetic_bin_sign: PLUS
| MINUS
| DIV
| MOD
| STAR
;

arithmetic_unar_sign: ICREMENT
| DECREMENT
;

compare_bin_sign: LE
| GE
| EQ
| NE
| DAND
| DOR
| LT
| MT
;

logic_bin_sign: AND
| OR
| XOR
| DAND
| DOR
;

logic_unar_sign: NOT
;

assign_sign: LE
| GE
| EQ
| NE
| MULTASSIGN
| DIVASSIGN
| MODASSIGN
| PLUSASSIGN
| MINUSASSIGN
| DLTASSIGN
| DMTASSIGN
| ANDASSIGN
| XORASSIGN
| ORASSIGN
| ASSIGN
;

%%

int main() {
    yyparse();
    /*
     printf("\n\n");
     for(int i=0; i<ic_idx; i++){
        printf("%s", icg[i]);
    }
    */
    printf("\n\n");
    for(int i=0; i<tc_idx; i++){
        printf("%s", tcg[i]);
    }
    printf("\n\n");
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}

int search(char *name) {
    int i;
    for(i=0; i<temp_r-1; i++) {
        if(strcmp(regVars[i].name, name)==0) {
            return i+1;
            break;
        }
    }
    return -1;
}
