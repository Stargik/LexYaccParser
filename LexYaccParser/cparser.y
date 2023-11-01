%{
#include "lex.yy.c"

void yyerror(const char *s);
int yylex();
int yywrap();

void printtree(struct node*);
void printInorder(struct node *);
struct node* mknode(struct node *left, struct node *right, char *token);

struct dataType {
    char * id_name;
    char * data_type;
    char * type;
    int line_no;
} symbolTable[40];
int count=0;
int q;
char type[10];
extern int countn;
struct node *head;
struct node {
    struct node *left;
    struct node *right;
    char *token;
};
%}

%union {
    struct var_name {
        char name[100];
        struct node* nd;
    } nd_obj;
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
%type     <nd_obj>          program             headers             functions           function            func_signature      func_body

%%
    
program: headers functions
;

headers: headers headers
| INCLUDE { $$.nd = mknode(NULL, NULL, $1.name); }
|
;

functions: functions functions {
    $$.nd = mknode($1.nd, $2.nd, "functions");
    }
| function {
    $$.nd = mknode($1.nd, NULL, "functions");
    }
;

function: func_signature LC func_body RC {
    $3.nd = mknode(NULL, NULL, "func_body");
    $$.nd = mknode($1.nd, $3.nd, "function");
    }
;

func_signature: datatype IDENTIFIER LP parametrs RP {
    $2.nd = mknode(NULL, NULL, $2.name);
    $$.nd = mknode($2.nd, NULL, "func_signature");
    }
;

datatype: INT
| LONG
| FLOAT
| SHORT
| VOID
| CHAR
;

parametrs: parametrs_list
|
;

parametrs_list: datatype IDENTIFIER COMMA parametrs_list
| datatype IDENTIFIER
;

func_body: operation return
| operation
;

operation: statement SEMICOLON
| exp_condition
| exp_loop
| LC operation RC
| operation operation
|
;

return: RETURN value SEMICOLON
| RETURN SEMICOLON
;

value: NUMBER
| IDENTIFIER
| STR
| CHARACTER
| value op_bin_sign value
| op_unar_sign value
| value op_unar_sign
| LP value RP
;

op_bin_sign: AND
| STAR
| PLUS
| MINUS
| TILDA
| NOT
| DIV
| MOD
| LT
| MT
| XOR
| OR
| compare_bin_sign
;

op_unar_sign: ICREMENT
| DECREMENT
;

statement: datatype IDENTIFIER assign_sign value
| IDENTIFIER assign_sign value
| value op_bin_sign value
| op_unar_sign value
| value op_unar_sign
| CONTINUE
| BREAK
| IDENTIFIER LP STR RP
| IDENTIFIER LP STR COMMA AND IDENTIFIER RP
| datatype IDENTIFIER
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

exp_condition: IF LP condition RP LC operation RC else
;

else: ELSE exp_condition
| ELSE LC operation RC
|
;

condition: value compare_bin_sign value
| compare_unar_sign condition
| LP condition RP
| value
;

compare_bin_sign: LE
| GE
| EQ
| NE
| DAND
| DOR
;

compare_unar_sign: NOT
;

exp_loop: for_loop
| while_loop
| do_while_loop


for_loop: FOR LP assign_statements SEMICOLON condition SEMICOLON statement RP LC operation RC

while_loop: WHILE LP condition RP LC operation RC
;

do_while_loop: DO LC operation RC WHILE LP condition RP SEMICOLON
;

assign_statements: assign_list
|
;

assign_list: datatype IDENTIFIER assign_sign value COMMA assign_list
| datatype IDENTIFIER assign_sign value




%%

int main() {
    yyparse();
    printf("\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
    printtree(head);
    printf("\n\n");
}
    
struct node* mknode(struct node *left, struct node *right, char *token) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    char *newstr = (char *)malloc(strlen(token)+1);
    strcpy(newstr, token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    return(newnode);
}
void printtree(struct node* tree) {
    printf("\n\n Inorder traversal of the Parse Tree: \n\n");
    printInorder(tree);
    printf("\n\n");
}
void printInorder(struct node *tree) {
    int i;
    if (tree->left) {
        printInorder(tree->left);
    }
    printf("%s, ", tree->token);
    if (tree->right) {
        printInorder(tree->right);
    }
}


void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}

