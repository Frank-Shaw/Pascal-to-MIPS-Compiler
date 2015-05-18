%{
#define YYPARSER
#include "global.h"
#include "util.h"
#include "scan.h"
#define YYSTYPE TreeNode *
static int savedVal;
static TreeNode * savedTree;
extern int TraceParser;
int yyerror(char * message);
int err=0;
%}

%token PROGRAM _BEGIN _END
%token VAR INTEGER REAL CHAR STRING CONST SYS_CON SYS_TYPE TYPE
%token ARRAY OF RECORD  FUNCTION PROCEDURE READ WRITELN SYS_PROC
%token IF THEN ELSE REPEAT UNTIL WHILE DO FOR TO DOWNTO GOTO CASE
%token _AND _OR _NOT LP RP LB RB DOT COMMA COLON  SEMI
%token ASSIGN UNEQUAL EQUAL _MUL _DIV _MOD _PLUS _MINUS _GE  _GT _LE _LT _ID
%token ERROR SYS_FUNCT

%%

program : program_head  routine  DOT
	{
	 	if(TraceParser)
			printf("%d:  program\n",lineno);
		$$=$2;
		savedTree=$$;
	}
	;
program_head : PROGRAM  ID  SEMI
	{}
	;
routine : routine_head  routine_body
	{
		if(TraceParser)
			printf("%d:  routine\n",lineno);
		$$=newStmtNode(RoutineK);
		$$->child[0]=$1;
		$$->child[1]=$2;
	}
	;
sub_routine : routine_head  routine_body
	{
		if(TraceParser)
			printf("%d: sub routine\n",lineno);		
		$$=newStmtNode(RoutineK);
		$$->child[0]=$1;
		$$->child[1]=$2;
	}
	;
routine_head : label_part  const_part  type_part  var_part  routine_part
	{
		if(TraceParser)
			printf("%d: routine head\n",lineno);
		$$=newStmtNode(RHeadK);
		$$->child[0]=$2;
		$$->child[1]=$3;
		$$->child[2]=$4;
		$$->child[3]=$5;
	}
	;
label_part : {}
	;
const_part : CONST  const_expr_list  
	{
		if(TraceParser)
			printf("%d: const part\n",lineno);
		$$=$2;
	}
	|  {$$=NULL;}
	;
const_expr_list : const_expr_list  ID 	EQUAL  const_value  SEMI
	{
		if(TraceParser)
			printf("%d: const list 1\n",lineno);
		$$=newExpNode(ConstExpK);
		$$->child[0] = $2;
		$$->child[1] = $4;
		nodeInsert($1,$$);
		$$=$1;
	}
	|  ID  EQUAL  const_value  SEMI
	{
		if(TraceParser)
			printf("%d: const list 2\n",lineno);
		$$=newExpNode(ConstExpK);
		$$->child[0] = $1;
		$$->child[1] = $3;
	}
	;
const_value : INTEGER  
	{ 
		if(TraceParser)
			printf("%d: const int\n",lineno);
		$$=newExpNode(ConstIK); 
		$$->attr.ival=atoi(tokenString);
	}
	|  REAL  
	{ 
		if(TraceParser)
			printf("%d: const real\n",lineno);
		$$=newExpNode(ConstRK); 
		$$->attr.fval=atof(tokenString);
	}
	|  CHAR  
	{ 
		if(TraceParser)
			printf("%d: const char\n",lineno);
		$$=newExpNode(ConstCK); 
		$$->attr.cval=tokenString[0];
	}
	|  STRING  
	{
		if(TraceParser)
			printf("%d: const string\n",lineno);
		$$=newExpNode(ConstSK); 
		$$->attr.sval=copyString(tokenString);
	}
	;
type_part : TYPE type_decl_list  
	{
		if(TraceParser)
			printf("%d: type_part 1\n",lineno);
		$$=$2;
	}
	|  
	{
		if(TraceParser)
			printf("%d: type_part 2\n",lineno);
		$$=NULL;
	}
	;
type_decl_list : type_decl_list  type_definition  
	{
		if(TraceParser)
			printf("%d: type list1\n",lineno);
		$$=$1; 
		nodeInsert($1,$2);
	}
	|  type_definition	
	{
		if(TraceParser)
			printf("%d: type list 2\n",lineno);
		$$ = $1;
	}
	;
type_definition : ID EQUAL  type_decl  SEMI
	{
		if(TraceParser)
			printf("%d: type def\n",lineno);
		$$=newStmtNode(TypeDefK); 
		$$->child[0]=$1;
		$$->child[1]=$3;
	}
	;
type_decl : simple_type_decl 	
	{
		if(TraceParser)
			printf("%d: type decl simple \n",lineno);
		$$ = $1;
	}
	|  array_type_decl	
	{
		if(TraceParser)
			printf("%d: type decl array\n",lineno);
		$$ = $1;
	}
	|  record_type_decl	
	{
		if(TraceParser)
			printf("%d: type decl record \n",lineno);
		$$ = $1;
	}
	;
array_type_decl : ARRAY  LB  simple_type_decl  RB  OF  type_decl
	{
		if(TraceParser)
			printf("%d: type array\n",lineno);
		$$ = newStmtNode(TypeK);
		$$->attr.name = "ArrayType";	
		$$->child[0]=$3;
		$$->child[1]=$6;
	}
	| ARRAY  LB  simple_type_decl  error  OF  type_decl
	{
		if(TraceParser)
			printf("%d: type array\n",lineno);
		yyerror("missing ']' ");
		$$ = newStmtNode(TypeK);
		$$->attr.name = "ArrayType";	
		$$->child[0]=$3;
		$$->child[1]=$6;
	}
	| ARRAY  error  simple_type_decl  RB  OF  type_decl
	{
		if(TraceParser)
			printf("%d: type array\n",lineno);
		yyerror("missing '[' ");
		$$ = newStmtNode(TypeK);
		$$->attr.name = "ArrayType";	
		$$->child[0]=$3;
		$$->child[1]=$6;
	}
	;
record_type_decl : RECORD  field_decl_list  _END
	{
		if(TraceParser)
			printf("%d: type record\n",lineno);
		$$ = newStmtNode(TypeK);
		$$->attr.name = "RecordType";	
		$$->child[0]=$2;
	}
	;
field_decl_list : field_decl_list  field_decl  
	{	
		if(TraceParser)
			printf("%d: field list1\n",lineno);
		$$=$1; 
		nodeInsert($1,$2);
	}
	|  field_decl 
	{
		if(TraceParser)
			printf("%d: field list2\n",lineno);
		$$=$1;
	}
	;
field_decl : name_list  COLON  type_decl  SEMI
	{
		if(TraceParser)
			printf("%d: field decl\n",lineno);
		$$=newStmtNode(DeclK);
		$$->attr.name="FieldDecl";
		$$->child[0] = $1;
		$$->child[1] = $3;
	}
	;
name_list : name_list  COMMA  ID  
	{
		if(TraceParser)
			printf("%d: name list 1\n",lineno);
		$$=$1; 
		nodeInsert($1,$3);
	}
	|  ID
	{
		if(TraceParser)
			printf("%d: name list 2\n",lineno);
		$$ = $1;
	}
	;
simple_type_decl : SYS_TYPE  
	{
		if(TraceParser)
			printf("%d: simple type decl sys\n",lineno);
		$$ = newStmtNode(TypeK);
		$$->attr.name = copyString(tokenString);	
	}
	|  ID  
	{
		if(TraceParser)
			printf("%d: simple type decl ID\n",lineno);
		$$ = newStmtNode(TypeK);
		$$->attr.name = "IDType";
		$$->child[0] = $1;	
	}
	|  LP  name_list  RP 
	{
		if(TraceParser)
			printf("%d: simple type decl ENUM\n",lineno);
		$$ = newStmtNode(TypeK);
		$$->attr.name = "EnumType";	
		$$->child[0]=$2;
	}
	|  LP  name_list  error 
	{
		if(TraceParser)
			printf("%d: simple type decl ENUM\n",lineno);
		yyerror("missing ')' ");
		$$ = newStmtNode(TypeK);
		$$->attr.name = "EnumType";	
		$$->child[0]=$2;
	}
	|  error  name_list  RP 
	{
		if(TraceParser)
			printf("%d: simple type decl ENUM\n",lineno);
		yyerror("missing '(' ");
		$$ = newStmtNode(TypeK);
		$$->attr.name = "EnumType";	
		$$->child[0]=$2;
	}
	|  const_value  DOT DOT  const_value  
	{
		if(TraceParser)
			printf("%d: simple type decl range 1\n",lineno);
		$$ = newStmtNode(TypeK);
		$$->attr.name = "RangeType";	
		$$->child[0]=$1;
		$$->child[1]=$4;
	}
	|  _MINUS  const_value  DOT DOT  const_value
	{
		if(TraceParser)
			printf("%d: simple type decl range 2\n",lineno);
		$$ = newStmtNode(TypeK);
		$$->attr.name = "RangeType2";	
		$$->child[0]=$2;
		$$->child[1]=$5;
	}
	|  _MINUS  const_value  DOT DOT  _MINUS  const_value
	{
		if(TraceParser)
			printf("%d: simple type decl range 3\n",lineno);
		$$ = newStmtNode(TypeK);
		$$->attr.name = "RangeType3";	
		$$->child[0]=$2;
		$$->child[1]=$5;
	}
	|  ID   DOT DOT  ID
	{
		if(TraceParser)
			printf("%d: simple type decl range 4\n",lineno);
		$$ = newStmtNode(TypeK);
		$$->attr.name = "RangeType4";	
		$$->child[0]=$1;
		$$->child[1]=$4;
	}
	;
var_part : VAR  var_decl_list  
	{
		if(TraceParser)
			printf("%d: var part1\n",lineno);
		$$=$2;
	}
	|  {
		if(TraceParser)
			printf("%d: var part 2\n",lineno);
		$$=NULL;
	}
	;
var_decl_list :  var_decl_list  var_decl  
	{
		if(TraceParser)
			printf("%d: var decl list1\n",lineno);
		$$=$1; 
		nodeInsert($1,$2);
	}
	|  var_decl 
	{
		if(TraceParser)
			printf("%d: var decl list2\n",lineno);
		$$=$1;
	}
	;
var_decl :  name_list  COLON  type_decl  SEMI
	{
		if(TraceParser)
			printf("%d: var decl \n",lineno);
		$$=newStmtNode(DeclK);
		$$->attr.name="ValDecl";
		$$->child[0] = $1;
		$$->child[1] = $3;
	}
	;
routine_part:  routine_part  function_decl  
	{
		if(TraceParser)
			printf("%d: routine part 1\n",lineno);
		$$=$1; 
		nodeInsert($1,$2);
	}
	|  routine_part  procedure_decl
	{
		if(TraceParser)
			printf("%d: routine part 2\n",lineno);
		$$=$1; 
		nodeInsert($1,$2);
	}
	|  function_decl  { 
		if(TraceParser)
			printf("%d: routine part 3\n",lineno);
		$$=$1; 
	}
	|  procedure_decl { 
		if(TraceParser)
			printf("%d: routine part 4\n",lineno);
		$$=$1;
	 }
	| {
		if(TraceParser)
			printf("%d: routine part 5 \n",lineno);
		$$=NULL;
	}
	;
function_decl : function_head  SEMI  sub_routine  SEMI
	{
		if(TraceParser)
			printf("%d: func decl \n",lineno);
		$$=newStmtNode(DeclK);
		$$->attr.name="FuncDecl";
		$$->child[0] = $1;
		$$->child[1] = $3;
	}
	;
function_head :  FUNCTION  ID   parameters  COLON  simple_type_decl 
	{
		if(TraceParser)
			printf("%d: func head \n",lineno);
		$$=newStmtNode(FHeadK);
		$$->child[0] = $2;
		$$->child[1] = $3;
		$$->child[2] = $5;
	}
	;
procedure_decl :  procedure_head  SEMI  sub_routine  SEMI
	{
		if(TraceParser)
			printf("%d: proc decl \n",lineno);
		$$=newStmtNode(DeclK);
		$$->attr.name="ProcDecl";
		$$->child[0] = $1;
		$$->child[1] = $3;
	}
	;
procedure_head :  PROCEDURE ID  parameters 
	{
		if(TraceParser)
			printf("%d: proc head \n",lineno);
		$$=newStmtNode(PHeadK);
		$$->child[0] = $2;
		$$->child[1] = $3;
	}
	;
parameters : LP  para_decl_list  RP  
	{ 
		if(TraceParser)
			printf("%d: para 1 \n",lineno);
		$$=$2;
	}
	|LP  para_decl_list  error  
	{ 
		if(TraceParser)
			printf("%d: para 1 \n",lineno);
		yyerror("missing ')' ");
		$$=$2;
	}
	|error para_decl_list  RP  
	{ 
		if(TraceParser)
			printf("%d: para 1 \n",lineno);
		yyerror("missing '(' ");
		$$=$2;
	}
	|  { 
		if(TraceParser)
			printf("%d: para 2 \n",lineno);
		$$=NULL;
	}
	;
para_decl_list : para_decl_list  SEMI  para_type_list
	{ 
		if(TraceParser)
			printf("%d: para decl list 1 \n",lineno);
		$$=$1; 
		nodeInsert($1,$3);
	}
	| para_type_list
	{ 
		if(TraceParser)
			printf("%d: para decl list 2 \n",lineno);
		$$=$1; 
	}
	;
para_type_list : var_para_list COLON  simple_type_decl  
	{
		if(TraceParser)
			printf("%d: para type list \n",lineno);
		$$ = newStmtNode(ParaK);
		$$->child[0]=$1;
		$$->child[1]=$3;
	}
	;
var_para_list : VAR  name_list {
		if(TraceParser)
			printf("%d: var para  list 1\n",lineno);
		$$ = $2;
	}
	| name_list	
	{
		if(TraceParser)
			printf("%d: var para  list 2 \n",lineno);
		$$ = $1;
	}
	;
routine_body : compound_stmt {
		if(TraceParser)
			printf("%d: routine body \n",lineno);
		$$ = $1;
	}
	;
stmt_list : stmt_list  stmt SEMI 
	{
		if(TraceParser)
			printf("%d: stmt list 1 \n",lineno);
		$$=$1; 
		nodeInsert($1,$2);
	}
	|  stmt SEMI  {
		if(TraceParser)
			printf("%d: stmt list 2 \n",lineno);
		$$=$1;
	}	
	| {$$ = NULL;}
	;
stmt : INTEGER {savedVal=atoi(tokenString);} COLON  non_label_stmt  
	{
		if(TraceParser)
			printf("%d: stmt label \n",lineno);
		$$=$4; 
		$$->attr.ival=savedVal;
	}
	|  non_label_stmt   {
		if(TraceParser)
			printf("%d: stmt non label \n",lineno);
		$$=$1;
	}
	;
non_label_stmt : assign_stmt {$$=$1;}
	| proc_stmt {$$=$1;}
	| compound_stmt {$$=$1;}
	| if_stmt {$$=$1;}
	| repeat_stmt {$$=$1;}
	| while_stmt {$$=$1;}
	| for_stmt {$$=$1;}
	| case_stmt {$$=$1;}
	| goto_stmt{$$=$1;}
	|error {yyerror("incorrect statement");  $$=NULL;}
	;

assign_stmt : ID  ASSIGN  expression
	{
		if(TraceParser)
			printf("%d: assign id \n",lineno);
		$$ = newStmtNode(AssignK);
		$$->child[0] = $1;
		$$->child[1] = $3;
	}
	| ID   LB expression RB ASSIGN expression
	{	
		if(TraceParser)
			printf("%d: assign array \n",lineno);
		$$ = newStmtNode(ArrayAssignK);
		$$->child[0] = $1;
	 	$$->child[1] = $3;
	 	$$->child[2] = $6;
	}
	| ID   LB expression error ASSIGN expression
	{	
		if(TraceParser)
			printf("%d: assign array \n",lineno);
		yyerror("missing ']' ");
		$$ = newStmtNode(ArrayAssignK);
		$$->child[0] = $1;
	 	$$->child[1] = $3;
	 	$$->child[2] = $6;
	}
	| ID   error expression RB ASSIGN expression
	{	
		if(TraceParser)
			printf("%d: assign array \n",lineno);
		yyerror("missing '[' ");
		$$ = newStmtNode(ArrayAssignK);
		$$->child[0] = $1;
	 	$$->child[1] = $3;
	 	$$->child[2] = $6;
	}
	| ID  DOT  ID  	ASSIGN  expression
	{
		if(TraceParser)
			printf("%d: assign elem \n",lineno);
		$$ = newStmtNode(ElemAssignK);
		$$->child[0] = $1;
	 	$$->child[1] = $3;
	 	$$->child[2] = $5;
	 }
	;
proc_stmt : ID
	{
		if(TraceParser)
			printf("%d: ProcK no args \n",lineno);
		$$ = newStmtNode(ProcK);
		$$->child[0]=$1;
	}
	|  ID LP  args_list  RP
	{
		if(TraceParser)
			printf("%d: ProcK with args \n",lineno);
		$$ = newStmtNode(ProcK);
		$$->child[0] = $1;
		$$->child[1] = $3;
	}
	|  ID LP  args_list  error
	{
		if(TraceParser)
			printf("%d: ProcK with args \n",lineno);
		yyerror("missing ')' ");
		$$ = newStmtNode(ProcK);
		$$->child[0] = $1;
		$$->child[1] = $3;
	}
	|  ID error  args_list  RP
	{
		if(TraceParser)
			printf("%d: ProcK with args \n",lineno);
		yyerror("missing '(' ");
		$$ = newStmtNode(ProcK);
		$$->child[0] = $1;
		$$->child[1] = $3;
	}
	|  SYS_PROC
	{
		if(TraceParser)
			printf("%d: ProcK sys \n",lineno);
		$$ = newStmtNode(ProcK);
		$$->attr.name="sProc";
	}
	|  SYS_PROC  LP  expression_list  RP
	{
		if(TraceParser)
			printf("%d: ProcK sys args \n",lineno);
		$$ = newStmtNode(ProcK);
		$$->attr.name="Proc";
		$$->child[0] = $3;
	}
	|  WRITELN  LP  factor  RP
	{
		if(TraceParser)
			printf("%d: WriteK \n",lineno);
		$$ = newStmtNode(WriteK);
		$$->attr.name="writeln";
		$$->child[0] = $3;
	}
	|WRITELN  LP  factor  error
	{
		if(TraceParser)
			printf("%d: WriteK \n",lineno);
		yyerror("missing ')' ");
		$$ = newStmtNode(WriteK);
		$$->attr.name="writeln";
		$$->child[0] = $3;
	}
	|WRITELN  error  factor  RP
	{
		if(TraceParser)
			printf("%d: WriteK \n",lineno);
		yyerror("missing '(' ");
		$$ = newStmtNode(WriteK);
		$$->attr.name="writeln";
		$$->child[0] = $3;
	}
	|  READ  LP  factor  RP
	{
		if(TraceParser)
			printf("%d: ReadK \n",lineno);
		$$ = newStmtNode(ReadK);
		$$->attr.name="read";
		$$->child[0] = $3;
	}
	|  READ  LP  factor  error
	{
		if(TraceParser)
			printf("%d: ReadK \n",lineno);
		yyerror("missing ')' ");
		$$ = newStmtNode(ReadK);
		$$->attr.name="read";
		$$->child[0] = $3;
	}
	|  READ  error  factor  RP
	{
		if(TraceParser)
			printf("%d: ReadK \n",lineno);
		yyerror("missing '(' ");
		$$ = newStmtNode(ReadK);
		$$->attr.name="read";
		$$->child[0] = $3;
	}
	;
compound_stmt : _BEGIN  stmt_list  _END 
	{$$=$2;}
	;
if_stmt : IF  expression  THEN  stmt  else_clause
	{
		if(TraceParser)
			printf("%d: if stmt \n",lineno);
		$$=newStmtNode(IfK);
		$$->child[0] = $2;
		$$->child[1] = $4;
		$$->child[2] = $5;
	}
	;
else_clause : ELSE stmt 
	{
		if(TraceParser)
			printf("%d: else stmt \n",lineno);
		$$=$2;
	}
	|  { if(TraceParser)
			printf("%d: no else \n",lineno);$$=NULL;}
	;
repeat_stmt : REPEAT  stmt_list  UNTIL  expression
	{
		if(TraceParser)
			printf("%d: repeat stmt \n",lineno);
		$$=newStmtNode(RepeatK);
		$$->child[0] = $2;
		$$->child[1] = $4;
	}
	;
while_stmt : WHILE  expression  DO stmt
	{
		if(TraceParser)
			printf("%d: while stmt \n",lineno);
		$$=newStmtNode(WhileK);
		$$->child[0] = $2;
		$$->child[1] = $4;
	}
	;
for_stmt : FOR  ID  ASSIGN  expression  direction  expression  DO stmt
	{
		if(TraceParser)
			printf("%d: for stmt \n",lineno);
		$$=newStmtNode(ForK);
		$$->child[0] =newStmtNode(AssignK);
		$$->child[0] ->child[0]=$2;
		$$->child[0] ->child[1]=$4;
		$$->child[1] = $5;
		$$->child[2] = $6;
		$$->child[3] = $8;
	}
	;
direction : TO 
	{
		if(TraceParser)
			printf("%d: direct to \n",lineno);
		$$=newStmtNode(ForK);
		$$->attr.ival=1;
	}
	| DOWNTO 
	{	
		if(TraceParser)
			printf("%d: direct downto \n",lineno);
		$$=newStmtNode(ForK);
		$$->attr.ival=0;
	}
	;
case_stmt : CASE expression OF case_expr_list  _END
	{
		/*
		$$=newStmtNode(CaseK);
		$$->child[0] = $2;
		$$->child[1] = $4;
		*/
		TreeNode * tmp;
		TreeNode * tmp2;
		TreeNode * iter;
		if(TraceParser)
			printf("%d: case stmt \n",lineno);
		iter=$4;
		$$=newStmtNode(IfK);
		tmp=newExpNode(OpK);
		tmp->attr.op = EQ;
		tmp->child[0]=$2;
		tmp->child[1]=iter->child[0];
		$$->child[0]=tmp;
		$$->child[1]=iter->child[1];
		tmp2=$$;
		while((iter=iter->sibling)!=NULL)
		{
			tmp2->child[2]=newStmtNode(IfK);
			tmp2=tmp2->child[2];
			tmp=newExpNode(OpK);
			tmp->attr.op = EQ;
			tmp->child[0]=$2;
			tmp->child[1]=iter->child[0];
			tmp2->child[0]=tmp;
			tmp2->child[1]=iter->child[1];
		}
	}
	;
case_expr_list : case_expr_list  case_expr  
	{
		if(TraceParser)
			printf("%d: case exp list 1 \n",lineno);
		$$=$1; 
		nodeInsert($1,$2);
	}
	|  case_expr { if(TraceParser)
			printf("%d: case exp list 2 \n",lineno);$$=$1;}
	;
case_expr : const_value  COLON  stmt  SEMI
	{
		if(TraceParser)
			printf("%d: case expr const \n",lineno);
		$$=newExpNode(CaseExpK);
		$$->child[0]=$1;
		$$->child[1]=$3;
	}
	|  ID  COLON  stmt  SEMI	
	{
		if(TraceParser)
			printf("%d: case expr id \n",lineno);
		$$=newExpNode(CaseExpK);
		$$->child[0]=$1;
		$$->child[1]=$3;
	}
	;
goto_stmt : GOTO  INTEGER
	{
		if(TraceParser)
			printf("%d: goto stmt \n",lineno);
		$$=newStmtNode(GotoK);
		$$->attr.ival=atoi(tokenString);
	}
	;
expression_list : expression_list  COMMA  expression  
	{
		if(TraceParser)
			printf("%d: exp list 1 \n",lineno);
		$$=$1; 
		nodeInsert($1,$3);
	}
	|  expression {if(TraceParser)
			printf("%d: exp list 2 \n",lineno);$$=$1;}
	;
expression : expression  _GE  expr  
	{
		if(TraceParser)
			printf("%d: exp ge \n",lineno);
		$$ = newExpNode(OpK);
		$$->child[0] = $1;
		$$->child[1] = $3;
		$$->attr.op = GE;
	}
	|  expression  _GT  expr  
	{
		if(TraceParser)
			printf("%d: exp gt \n",lineno);
		$$ = newExpNode(OpK);
	 	$$->child[0] = $1;
	 	$$->child[1] = $3;
		$$->attr.op = GT;
	}
	|  expression  _LE  expr
	{
		if(TraceParser)
			printf("%d: exp le \n",lineno);
		$$ = newExpNode(OpK);
		$$->child[0] = $1;
		$$->child[1] = $3;
		$$->attr.op = LE;
	}
	|  expression  _LT  expr  
	{
		if(TraceParser)
			printf("%d: exp lt\n",lineno);
		$$ = newExpNode(OpK);
		$$->child[0] = $1;
		$$->child[1] = $3;
		$$->attr.op = LT;
	}
	|  expression  EQUAL  expr  
	{
		if(TraceParser)
			printf("%d: exp eq \n",lineno);
		$$ = newExpNode(OpK);
		$$->child[0] = $1;
		$$->child[1] = $3;
		$$->attr.op = EQ;
	}
	|  expression  UNEQUAL  expr  
	{
		if(TraceParser)
			printf("%d: exp ne \n",lineno);
		$$ = newExpNode(OpK);
		$$->child[0] = $1;
		$$->child[1] = $3;
		$$->attr.op = NE;
	}
	|  expr {
		if(TraceParser)
			printf("%d: one expr \n",lineno);
		$$=$1;
	}
	;
expr : 	expr  _PLUS  term  
	{ 
		if(TraceParser)
			printf("%d: expr plus \n",lineno);
		$$=newExpNode(OpK);
		$$->child[0] = $1;
		$$->child[1] = $3;
		$$->attr.op = PLUS;
	}
	|  expr  _MINUS  term  
	{ 
		if(TraceParser)
			printf("%d: expr minus \n",lineno);
		$$=newExpNode(OpK);
		$$->child[0] = $1;
		$$->child[1] = $3;
		$$->attr.op = MINUS;
	}
	|  expr  _OR  term  
	{ 
		if(TraceParser)
			printf("%d: expr or \n",lineno);
		$$=newExpNode(OpK);
		$$->child[0] = $1;
		$$->child[1] = $3;
		$$->attr.op = OR;
	}
	|  term {
		if(TraceParser)
			printf("%d: expr term \n",lineno);
		$$=$1;
	}
	;
term : 	term  _MUL  factor  
	{ 
		if(TraceParser)
			printf("%d: term mul \n",lineno);
		$$=newExpNode(OpK);
		$$->child[0] = $1;
		$$->child[1] = $3;
		$$->attr.op = MUL;
	}
	|  term  _DIV  factor  
	{ 
		if(TraceParser)
			printf("%d: term div \n",lineno);
		$$=newExpNode(OpK);
		$$->child[0] = $1;
		$$->child[1] = $3;
		$$->attr.op = DIV;
	}
	|  term  _MOD  factor 
	{ 
		if(TraceParser)
			printf("%d: term mod \n",lineno);
		$$=newExpNode(OpK);
		$$->child[0] = $1;
		$$->child[1] = $3;
		$$->attr.op = MOD;
	}
 	|  term  _AND  factor  
 	{ 
 		if(TraceParser)
			printf("%d: term and \n",lineno);
		$$=newExpNode(OpK);
		$$->child[0] = $1;
		$$->child[1] = $3;
		$$->attr.op = AND;
	}
 	|  factor {if(TraceParser)
			printf("%d: term factor \n",lineno);$$=$1;}
 	;
factor : ID  
	{
		if(TraceParser)
			printf("%d: factor id \n",lineno);
		$$ = $1;
	}
	|  ID   LP  args_list  RP  
	{
		if(TraceParser)
			printf("%d: factor call \n",lineno);
		$$ = newExpNode(CallK);
		$$->child[0] = $1;
		$$->child[1] = $3;
	}
	|  ID   LP  args_list  error  
	{
		if(TraceParser)
			printf("%d: factor call \n",lineno);
		yyerror("missing ')' ");
		$$ = newExpNode(CallK);
		$$->child[0] = $1;
		$$->child[1] = $3;
	}
	|  ID   error  args_list  RP  
	{
		if(TraceParser)
			printf("%d: factor call \n",lineno);
		yyerror("missing '(' ");
		$$ = newExpNode(CallK);
		$$->child[0] = $1;
		$$->child[1] = $3;
	}
	|  SYS_FUNCT	{}
	|  SYS_FUNCT  LP  args_list  RP  {}
	|  const_value  { 
		if(TraceParser)
			printf("%d: factor const  \n",lineno);
		$$=$1;
	}
	|  LP  expression  RP  	{ if(TraceParser)
			printf("%d: factor exp \n",lineno);$$ = $2;}
	|  _NOT  factor  	
	{
		if(TraceParser)
			printf("%d: factor not \n",lineno);
		$$=newExpNode(UnaryK);
		$$->attr.ival=0;  // ~
		$$->child[0]=$2;
	}
	|  _MINUS  factor	
	{
		if(TraceParser)
			printf("%d: factor minus \n",lineno);
		$$=newExpNode(UnaryK);
		$$->attr.ival=1;  // -
		$$->child[0]=$2;
	}  
	|  ID  LB  expression  RB 	
	{
		if(TraceParser)
			printf("%d: factor array \n",lineno);
		$$=newExpNode(ArrayK);
		$$->child[0]=$1;
		$$->child[1]=$3;
	}
	|  ID  LB  expression  error	
	{
		if(TraceParser)
			printf("%d: factor array \n",lineno);
		yyerror("missing ']' ");
		$$=newExpNode(ArrayK);
		$$->child[0]=$1;
		$$->child[1]=$3;
	}
	|  ID  error  expression  RB	
	{
		if(TraceParser)
			printf("%d: factor array \n",lineno);
		yyerror("missing '[' ");
		$$=newExpNode(ArrayK);
		$$->child[0]=$1;
		$$->child[1]=$3;
	}
	|  ID   DOT  ID 	
	{
		if(TraceParser)
			printf("%d: factor element \n",lineno);
		$$=newExpNode(ElemK);
		$$->child[0]=$1;
		$$->child[1]=$3;
	}
	;
args_list : args_list  COMMA  expression  
	{
		if(TraceParser)
			printf("%d: args list 1 \n",lineno);
		$$=$1; 
		nodeInsert($1,$3);
	}
	|  expression 
	{
		if(TraceParser)
			printf("%d: args list 2 \n",lineno);
		$$=$1;
	}
ID 	: _ID
	{
		$$ = newExpNode(IdK);
		$$->attr.name = copyString(tokenString);	
		$$->lineno=lineno;	
	}
	|ERROR 
	{
		if(TraceParser)
			printf("%d: ERROR TOKEN \n",lineno);
		$$=NULL;
		yyerror("illegal token");
	}
	;
 
%%

int yyerror(char * message)
{
	printf("error %d",lineno);
	fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
	fprintf(listing,"Current token: ");
	printToken(yychar,tokenString);
	err=1;
	return 0;
}

/* yylex calls getToken to make Yacc/Bison output*/

static int yylex(void)
{
	return getToken(); 
}

TreeNode * parse(void)
{	
	yyparse();
	if(!err)
		return savedTree;
	else
		return NULL;
}

/*
void main()
{
	TreeNode* root;
	root= parse();
	printTree(root);
	if(TraceParser)
			printf("OK");
}
*/