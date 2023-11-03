%{
#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.c"

void yyerror(const char *s);
int yylex();
int yywrap();
int search(char *name);
struct node* mknode(char *name);
void printtreewrap(struct node*);
void printtree(struct node *);
char *treeToJsonWrap(struct node *tree);
cJSON *treeToJson(struct node *tree);

struct node *head;
struct node {
    int cNum;
    char name[120];
    struct node* children[30];
};

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
%token    <nd_obj>          STR                 CHARACTER           VOID
%type     <nd_obj3>         condition
%type     <nd_obj2>         init value statement p_stetament
%type     <nd_obj>          headers main return datatype arithmetic_bin_sign compare_bin_sign program else logic_bin_sign op_statement arithmetic_unar_sign
%type     <nd_obj>          main_function op_loop for_loop while_loop do_while_loop body op_if_else logic_unar_sign assign_sign
%%

program: headers main_function {
    $$.nd = mknode("program");
    head = $$.nd;
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
}
;

headers: headers headers {
    $$.nd = mknode("headers");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
}
| INCLUDE {
    $$.nd = mknode("headers");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
}
| {
    $$.nd = mknode("headers");
    struct node *node = mknode("NULL");
    $$.nd->children[$$.nd->cNum++] = node;
}
;

main_function: main LP RP LC body return RC {
    $$.nd = mknode("main_function");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $2.nd = mknode($2.name);
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $3.nd = mknode($3.name);
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    $4.nd = mknode($4.name);
    $$.nd->children[$$.nd->cNum++] = $4.nd;
    $$.nd->children[$$.nd->cNum++] = $5.nd;
    $$.nd->children[$$.nd->cNum++] = $6.nd;
    $7.nd = mknode($7.name);
    $$.nd->children[$$.nd->cNum++] = $7.nd;
}
;

return: RETURN statement SEMICOLON {
    $$.nd = mknode("return");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $3.nd = mknode($3.name);
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    
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
| {
    $$.nd = mknode("return");
    struct node *node = mknode("NULL");
    $$.nd->children[$$.nd->cNum++] = node;
}
;

main: datatype IDENTIFIER {
    $$.nd = mknode("main");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $2.nd = mknode($2.name);
    $$.nd->children[$$.nd->cNum++] = $2.nd;
}
;

datatype: INT { $$.nd = mknode("datatype"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| LONG { $$.nd = mknode("datatype"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| FLOAT { $$.nd = mknode("datatype"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| SHORT { $$.nd = mknode("datatype"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| VOID { $$.nd = mknode("datatype"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| CHAR { $$.nd = mknode("datatype"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
;

body: body body {
    $$.nd = mknode("body");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
}
| op_statement SEMICOLON {
    $$.nd = mknode("body");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $2.nd = mknode($2.name);
    $$.nd->children[$$.nd->cNum++] = $2.nd;
}
| op_if_else {
    $$.nd = mknode("body");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
}
| op_loop {
    $$.nd = mknode("body");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
}
| LC body RC  {
    $$.nd = mknode("body");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $3.nd = mknode($3.name);
    $$.nd->children[$$.nd->cNum++] = $3.nd;
}
| {
    $$.nd = mknode("body");
    struct node *node = mknode("NULL");
    $$.nd->children[$$.nd->cNum++] = node;
}
;

op_if_else: IF { is_for = 0; } LP condition RP { sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.if_body); sprintf(tcg[tc_idx++], "\n%s:\n", $4.if_body); } LC body RC { sprintf(icg[ic_idx++], "JUMP to L%d\n", label); sprintf(tcg[tc_idx++], "JMP L%d\n", label); sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.else_body); sprintf(tcg[tc_idx++], "\n%s:\n", $4.else_body); } else {
    sprintf(icg[ic_idx++], "\nLABEL L%d:\n", label++); sprintf(tcg[tc_idx++], "\nL%d:\n", label-1);
    
    $$.nd = mknode("op_if_else");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $3.nd = mknode($3.name);
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    $$.nd->children[$$.nd->cNum++] = $4.nd;
    $5.nd = mknode($5.name);
    $$.nd->children[$$.nd->cNum++] = $5.nd;
    $7.nd = mknode($7.name);
    $$.nd->children[$$.nd->cNum++] = $7.nd;
    $$.nd->children[$$.nd->cNum++] = $8.nd;
    $9.nd = mknode($9.name);
    $$.nd->children[$$.nd->cNum++] = $9.nd;
    $$.nd->children[$$.nd->cNum++] = $11.nd;
}
;

else: ELSE op_if_else {
    $$.nd = mknode("else");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
}
| ELSE LC body RC {
    $$.nd = mknode("else");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $2.nd = mknode($2.name);
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    $4.nd = mknode($4.name);
    $$.nd->children[$$.nd->cNum++] = $4.nd;
}
| {
    $$.nd = mknode("headers");
    struct node *node = mknode("NULL");
    $$.nd->children[$$.nd->cNum++] = node;
}
;

condition: statement compare_bin_sign statement {
    $$.nd = mknode("condition");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    
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
    $$.nd = mknode("condition");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    
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
| logic_unar_sign condition {
    $$.nd = mknode("condition");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
}
| LP condition RP {
    $$.nd = mknode("condition");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $3.nd = mknode($3.name);
    $$.nd->children[$$.nd->cNum++] = $3.nd;
}
;

op_loop: for_loop { $$.nd = mknode("op_loop"); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| while_loop { $$.nd = mknode("op_loop"); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| do_while_loop { $$.nd = mknode("op_loop"); $$.nd->children[$$.nd->cNum++] = $1.nd; }
;

for_loop: FOR { is_for = 1; } LP op_statement SEMICOLON condition SEMICOLON statement RP LC body RC {
    $$.nd = mknode("for_loop");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $3.nd = mknode($3.name);
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    $$.nd->children[$$.nd->cNum++] = $4.nd;
    $5.nd = mknode($5.name);
    $$.nd->children[$$.nd->cNum++] = $5.nd;
    $$.nd->children[$$.nd->cNum++] = $6.nd;
    $7.nd = mknode($7.name);
    $$.nd->children[$$.nd->cNum++] = $7.nd;
    $$.nd->children[$$.nd->cNum++] = $8.nd;
    $9.nd = mknode($9.name);
    $$.nd->children[$$.nd->cNum++] = $9.nd;
    $10.nd = mknode($10.name);
    $$.nd->children[$$.nd->cNum++] = $10.nd;
    $$.nd->children[$$.nd->cNum++] = $11.nd;
    $12.nd = mknode($12.name);
    $$.nd->children[$$.nd->cNum++] = $12.nd;
    
    sprintf(icg[ic_idx++], buff);
    sprintf(icg[ic_idx++], "JUMP to %s\n", $6.if_body);
    sprintf(icg[ic_idx++], "\nLABEL %s:\n", $6.else_body);
    sprintf(tcg[tc_idx++], rbuff);
    sprintf(tcg[tc_idx++], "JMP %s\n", $6.if_body);
    sprintf(tcg[tc_idx++], "\n%s:\n", $6.else_body);
}
;

while_loop: WHILE { is_for = 1; } LP condition RP LC body RC {
    $$.nd = mknode("while_loop");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $3.nd = mknode($3.name);
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    $$.nd->children[$$.nd->cNum++] = $4.nd;
    $5.nd = mknode($5.name);
    $$.nd->children[$$.nd->cNum++] = $5.nd;
    $6.nd = mknode($6.name);
    $$.nd->children[$$.nd->cNum++] = $6.nd;
    $$.nd->children[$$.nd->cNum++] = $7.nd;
    $8.nd = mknode($8.name);
    $$.nd->children[$$.nd->cNum++] = $8.nd;
    
    sprintf(icg[ic_idx++], "JUMP to %s\n", $4.if_body);
    sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.else_body);
    sprintf(tcg[tc_idx++], "JMP %s\n", $4.if_body);
    sprintf(tcg[tc_idx++], "\n%s:\n", $4.else_body);
}
;

do_while_loop: DO LC body RC WHILE LP condition RP SEMICOLON {
    $$.nd = mknode("do_while_loop");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $2.nd = mknode($2.name);
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    $4.nd = mknode($4.name);
    $$.nd->children[$$.nd->cNum++] = $4.nd;
    $5.nd = mknode($5.name);
    $$.nd->children[$$.nd->cNum++] = $5.nd;
    $6.nd = mknode($6.name);
    $$.nd->children[$$.nd->cNum++] = $6.nd;
    $$.nd->children[$$.nd->cNum++] = $7.nd;
    $8.nd = mknode($8.name);
    $$.nd->children[$$.nd->cNum++] = $8.nd;
    $9.nd = mknode($9.name);
    $$.nd->children[$$.nd->cNum++] = $9.nd;
}
;

op_statement: datatype IDENTIFIER init {
    $$.nd = mknode("op_statement");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $2.nd = mknode($2.name);
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    
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
    $$.nd = mknode("op_statement");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    
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
    $$.nd = mknode("op_statement");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    
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
    $$.nd = mknode("op_statement");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    
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
| LP op_statement RP {
    $$.nd = mknode("op_statement");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $3.nd = mknode($3.name);
    $$.nd->children[$$.nd->cNum++] = $3.nd;
}
| CONTINUE {
    $$.nd = mknode("op_statement");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
}
| BREAK {
    $$.nd = mknode("op_statement");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
}
| IDENTIFIER LP STR RP {
    $$.nd = mknode("op_statement");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $2.nd = mknode($2.name);
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $3.nd = mknode($3.name);
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    $4.nd = mknode($4.name);
    $$.nd->children[$$.nd->cNum++] = $4.nd;
    
    sprintf(tcg[tc_idx++], "CALL %s\n", $1.name);
}
| IDENTIFIER LP STR COMMA AND IDENTIFIER RP {
    $$.nd = mknode("op_statement");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $2.nd = mknode($2.name);
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $3.nd = mknode($3.name);
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    $4.nd = mknode($4.name);
    $$.nd->children[$$.nd->cNum++] = $4.nd;
    $5.nd = mknode($5.name);
    $$.nd->children[$$.nd->cNum++] = $5.nd;
    $6.nd = mknode($6.name);
    $$.nd->children[$$.nd->cNum++] = $6.nd;
    $7.nd = mknode($7.name);
    $$.nd->children[$$.nd->cNum++] = $7.nd;
    
    sprintf(tcg[tc_idx++], "CALL %s\n", $1.name);
}
;

init: ASSIGN statement {
    $$.nd = mknode("init");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    
    sprintf($$.type, $2.type);
    strcpy($$.name, $2.name);
}
| { 
    $$.nd = mknode("init");
    struct node *node = mknode("NULL");
    $$.nd->children[$$.nd->cNum++] = node;
    
    sprintf($$.type, "null");
    strcpy($$.name, "NULL"); }
;

value: NUMBER { $$.nd = mknode("value"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| STR { $$.nd = mknode("value"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| CHARACTER { $$.nd = mknode("value"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
;

statement: p_stetament { $$.nd = mknode("statement"); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| statement PLUS statement {
    $$.nd = mknode("statement");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $2.nd = mknode($2.name);
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    
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
    $$.nd = mknode("statement");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $2.nd = mknode($2.name);
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    
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

p_stetament: value { strcpy($$.name, $1.name); sprintf($$.type, $1.type); $$.nd = mknode("p_stetament"); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| IDENTIFIER { $$.nd = mknode("p_stetament"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| p_stetament STAR p_stetament {
    $$.nd = mknode("p_stetament");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $2.nd = mknode($2.name);
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    
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
    $$.nd = mknode("p_stetament");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $2.nd = mknode($2.name);
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    
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
    $$.nd = mknode("p_stetament");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $2.nd = mknode($2.name);
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $$.nd->children[$$.nd->cNum++] = $3.nd;
    
    sprintf($$.name, "t%d", temp_var);
    temp_var++;
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
}
| arithmetic_unar_sign p_stetament {
    $$.nd = mknode("p_stetament");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    
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
    $$.nd = mknode("p_stetament");
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    
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
| LP p_stetament RP {
    $$.nd = mknode("p_stetament");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $3.nd = mknode($3.name);
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    
    strcpy($$.name, $2.name);
    sprintf($$.type, $2.type);
}
| LP p_stetament PLUS p_stetament RP {
    $$.nd = mknode("p_stetament");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $3.nd = mknode($3.name);
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $$.nd->children[$$.nd->cNum++] = $4.nd;
    $5.nd = mknode($5.name);
    $$.nd->children[$$.nd->cNum++] = $5.nd;
    
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
    $$.nd = mknode("p_stetament");
    $1.nd = mknode($1.name);
    $$.nd->children[$$.nd->cNum++] = $1.nd;
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $3.nd = mknode($3.name);
    $$.nd->children[$$.nd->cNum++] = $2.nd;
    $$.nd->children[$$.nd->cNum++] = $4.nd;
    $5.nd = mknode($5.name);
    $$.nd->children[$$.nd->cNum++] = $5.nd;
    
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

arithmetic_bin_sign: PLUS { $$.nd = mknode("arithmetic_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| MINUS { $$.nd = mknode("arithmetic_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| DIV { $$.nd = mknode("arithmetic_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| MOD { $$.nd = mknode("arithmetic_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| STAR { $$.nd = mknode("arithmetic_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
;

arithmetic_unar_sign: ICREMENT { $$.nd = mknode("arithmetic_unar_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| DECREMENT { $$.nd = mknode("arithmetic_unar_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
;

compare_bin_sign: LE { $$.nd = mknode("compare_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| GE { $$.nd = mknode("compare_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| EQ { $$.nd = mknode("compare_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| NE { $$.nd = mknode("compare_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| DAND { $$.nd = mknode("compare_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| DOR { $$.nd = mknode("compare_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| LT { $$.nd = mknode("compare_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| MT { $$.nd = mknode("compare_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
;

logic_bin_sign: AND { $$.nd = mknode("logic_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| OR { $$.nd = mknode("logic_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| XOR { $$.nd = mknode("logic_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| DAND { $$.nd = mknode("logic_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| DOR { $$.nd = mknode("logic_bin_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
;

logic_unar_sign: NOT { $$.nd = mknode("logic_unar_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
;

assign_sign: LE { $$.nd = mknode("assign_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| GE { $$.nd = mknode("assign_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| EQ { $$.nd = mknode("assign_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| NE { $$.nd = mknode("assign_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| MULTASSIGN { $$.nd = mknode("assign_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| DIVASSIGN { $$.nd = mknode("assign_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| MODASSIGN { $$.nd = mknode("assign_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| PLUSASSIGN { $$.nd = mknode("assign_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| MINUSASSIGN { $$.nd = mknode("assign_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| DLTASSIGN { $$.nd = mknode("assign_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| DMTASSIGN { $$.nd = mknode("assign_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| ANDASSIGN { $$.nd = mknode("assign_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| XORASSIGN { $$.nd = mknode("assign_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| ORASSIGN { $$.nd = mknode("assign_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
| ASSIGN { $$.nd = mknode("assign_sign"); $1.nd = mknode($1.name); $$.nd->children[$$.nd->cNum++] = $1.nd; }
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
    printf("\n\nTarget code:\n\n");
    for(int i=0; i<tc_idx; i++){
        printf("%s", tcg[i]);
    }
    printf("\n\n");
    
    printtreewrap(head);
    
    char *str = treeToJsonWrap(head);
    FILE *fp = fopen("tree.json", "w+");
    if (fp != NULL)
    {
        fputs(str, fp);
        fclose(fp);
    }
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
    
struct node* mknode(char *name) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->name, name);
    newnode->cNum = 0;
    return(newnode);
}
void printtreewrap(struct node* tree) {
    //printf("\n\nTree: \n\n");
    printtree(tree);
    //printf("\n\n");
}
void printtree(struct node *tree) {
    //printf("%s(%d), ", tree->name, tree->cNum);
    for(int i = 0; i < tree->cNum; i++){
        if(tree->children[i]){
            printtree(tree->children[i]);
        }
    }
}

char *treeToJsonWrap(struct node *tree)
{
    cJSON *monitor = treeToJson(tree);
    char *string = NULL;
    string = cJSON_Print(monitor);
    cJSON_Delete(monitor);
    return string;
}
    
cJSON *treeToJson(struct node *tree)
{
    cJSON *node = cJSON_CreateObject();
    cJSON *children = NULL;
    cJSON_AddStringToObject(node, "name", tree->name);
    if(tree->cNum > 0){
        children = cJSON_AddArrayToObject(node, "children");
        for(int i = 0; i < tree->cNum; i++){
            cJSON *child = treeToJson(tree->children[i]);
            cJSON_AddItemToArray(children, child);
        }
    }
    return node;
}

