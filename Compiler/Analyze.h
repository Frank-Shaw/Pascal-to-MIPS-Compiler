#ifndef _ANALYZE_H_
#define _ANALYZE_H_

#include"global.h"

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode *);
int enterFuncDecl(char *funcName);
int leaveFuncDecl(void);
int getFuncAmt(void);

#endif
