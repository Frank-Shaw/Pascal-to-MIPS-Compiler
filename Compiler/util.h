#ifndef _UTIL_H_
#define _UTIL_H_
#include "global.h"

void printToken( TokenType , const char* );

TreeNode * newStmtNode(StmtKind );

TreeNode * newExpNode(ExpKind );

char * copyString( char * );

void printTree( TreeNode * );
void nodeInsert( TreeNode *, TreeNode *);

#endif