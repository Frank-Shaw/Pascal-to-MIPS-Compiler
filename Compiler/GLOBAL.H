#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

extern int lineno;
extern FILE* source; /* source code text file */
extern FILE* listing; /* listing output text file */

typedef enum
{
	EQ, NE, GE, GT, LE, LT, PLUS, MINUS, MUL, DIV, OR, AND, MOD, NOT,
} TokenType;


/***********   Syntax tree for parsing ************/
typedef enum { StmtK, ExpK } NodeKind;
typedef enum {
	TypeDefK, DeclK, TypeK, ParaK, RoutineK, PHeadK, FHeadK, RHeadK,
	ElemAssignK, ArrayAssignK, IfK, RepeatK, WhileK, ForK, CaseK, GotoK, AssignK, ReadK, WriteK, ProcK
} StmtKind;
typedef enum { CallK, ConstExpK, CaseExpK, OpK, ConstIK, ConstRK, ConstCK, ConstSK, IdK, ElemK, ArrayK, UnaryK } ExpKind;
typedef enum { Void, Integer, Boolean } ExpType;
#define MAXCHILDREN 5

typedef struct treeNode
{
	struct treeNode * child[MAXCHILDREN];
	struct treeNode * sibling;
	int lineno;
	NodeKind nodekind;
	union { StmtKind stmt; ExpKind exp; } kind;
	union {
		TokenType op;
		int ival;
		float fval;
		char cval;
		char * sval;
		char * name;
	} attr;
	ExpType type; /* for type checking of exps */
} TreeNode;

#endif

/* TraceCode = TRUE causes comments to be written
* to the TM code file as code is generated
*/
extern int TraceCode;
