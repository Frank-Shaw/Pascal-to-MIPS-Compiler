#include "SymTab.h"
#include "Analyze.h"

extern int TraceAnalyze;
extern int Error;
extern int errorAmt;

/* counter for variable memory locations */
static int location[MAXFUNCAMT] = {0};
int funcPath[MAXFUNCAMT] = {0};
int funcPathI = 0;
int funcAmt = 1;
int a_curFuncNum=0;

/* Procedure traverse is a generic recursive 
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc 
 * in postorder to tree pointed to by t
 */
static void traverse( TreeNode * t, void (* preProc) (TreeNode *), void (* postProc) (TreeNode *) )
{ 
	if (t != NULL)
	{ 
		preProc(t);
		{ 
			int i;
			for (i=0; i < MAXCHILDREN; i++)
			{
				traverse(t->child[i],preProc,postProc);
			}
		}
		if(t->nodekind==StmtK&&t->kind.stmt==RoutineK)
		{
			/* if leaving a function declaration */
			if(funcPathI!=0)
			{
				/* if not leaving the main function,
                    then set current symbol table to the upper one */
				a_curFuncNum=funcPath[--funcPathI]; 
				st_setCurFuncNum(a_curFuncNum);
			}
		}
		
		postProc(t);
		traverse(t->sibling,preProc,postProc);
	}
}

/* nullProc is a do-nothing procedure to 
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
static void nullProc(TreeNode * t)
{ 
	return ;
}

char tokenName[][5]={"=","~=",">=",">","<=","<","+","-","*","/","|","&","%","~"};
static void typeError(TreeNode * t, char * message)
{
	char *errObjName;
	if(t->nodekind==ExpK)
	{
		switch(t->kind.exp)
		{
		case IdK:
			errObjName=t->attr.name;
			break;

		case OpK:
			errObjName=tokenName[t->attr.op];
			break;

		default:
			errObjName="";
			break;
		}
	}
	else
	{
		//stmtK
		switch(t->kind.stmt)
		{
		case IfK:
			errObjName="if";
			break;

		case WhileK:
			errObjName="while";
			break;

		case ForK:
			errObjName="for";
			break;

		default:
			errObjName="";
			break;
		}
	}
	fprintf(listing,"Type error at line %d: \"%s\": %s.\n", t->lineno, errObjName, message);
	Error = TRUE;
	errorAmt++;
}

typedef enum
{
	TYPE,
	VAR,
	FUNC,
	CONST
}ErrorObj;

void declInsert(TreeNode *t, char *varType, ErrorObj errObj)
{
	if (st_lookup(t->attr.name) == -1)
	{
		/* not yet in table, so safely insert */
		if(errObj==FUNC)
		{
			st_insert(t->attr.name, varType, t->lineno, funcAmt++);
		}
		else
		{
			st_insert(t->attr.name, varType, t->lineno, location[a_curFuncNum]++);
		}
	}
	else
	{
		/* already in table, redefinition error */
		switch(errObj)
		{
		case TYPE:
			typeError(t, "Type redeclaration");
			break;

		case VAR:
			typeError(t, "Variable redeclaration");
			break;

		case FUNC:
			typeError(t, "Function redeclaration");
			break;

		case CONST:
			typeError(t, "Constant variable redeclaration");
			break;

		default:
			typeError(t, "Unknown redeclaration error");
			break;
		}
	}
}

int referInsert(TreeNode *t, ErrorObj errObj)
{
	if (st_lookup(t->attr.name) == -1)
	{
		/* not yet in table, variable using without definition error */
		switch(errObj)
		{
		case TYPE:
			typeError(t, "Type not defined");
			break;

		case VAR:
			typeError(t, "Variable not defined");
			break;

		case FUNC:
			typeError(t, "Function not defined");
			break;

		default:
			typeError(t, "Unknown not defined error");
			break;
		}

		return -1;
	}
	else
	{
		/* already in table, so ignore location, 
		add line number of use only */ 
		st_insert(t->attr.name, NULL, t->lineno, 0);

		return 0;
	}
}

char *referGetType(TreeNode *t)
{
	if(strcmp(t->attr.name,"IDType"))
	{
		//if it is not DIY type, 
		//the parser can ensure it is an inner type
		return t->attr.name;
	}
	else
	{
		char *type;
		if((type=st_getType(t->child[0]->attr.name))==NULL)
		{
			//if the type hasn't been decleared yet,then error
			typeError(t->child[0], "Type not defined");
			return NULL;
		}
		else
		{
			return type;
		}
	}
}

ExpKind getExpExpKind(TreeNode *t, TreeNode **idTreeNode, int needInsert)
{
	if(t->kind.exp==OpK)
	{
		getExpExpKind(t->child[0], NULL, needInsert);
		return getExpExpKind(t->child[1], idTreeNode, needInsert);
	}
	else if(t->kind.exp==UnaryK)
	{
		return getExpExpKind(t->child[0], idTreeNode, needInsert);
	}
	else if(t->kind.exp==CallK)
	{
		return getExpExpKind(t->child[0], idTreeNode, 0);
	}
	else if(t->kind.exp==ArrayK)
	{
		return getExpExpKind(t->child[0], idTreeNode, 1);
	}
	else if(t->kind.exp==IdK)
	{
		if(idTreeNode!=NULL)
		{
			*idTreeNode=t;
		}
		if(needInsert)
		{
			referInsert(t, VAR);
		}
		return IdK;
	}
	else
	{
		//constants
		return t->kind.exp;
	}
}

int checkVarTypes2(ExpKind expKind1, ExpKind expKind2, TreeNode **idTreeNode)
{
	char *type1, *type2;
	if(expKind1==IdK)
	{
		type1=st_getType(idTreeNode[0]->attr.name);
		switch(expKind2)
		{
		case ConstIK:
			if(type1&&strcmp(type1,"integer"))
			{
				return -1;
			}
			break;
					
		case ConstRK:
			if(type1&&strcmp(type1,"real"))
			{
				return -1;
			}
			break;
						
		case ConstCK:
			if(type1&&strcmp(type1,"char"))
			{
				return -1;
			}
			break;

		case ConstSK:
			if(type1&&strcmp(type1,"string"))
			{
				return -1;
			}
			break;
					
		case IdK:
			type2=st_getType(idTreeNode[1]->attr.name);
			if(type1&&type2&&strcmp(type1, type2))
			{
				return -1;
			}
			break;

		default:
			return -1;
		}
	}
	else if(expKind2==IdK)
	{
		type2=st_getType(idTreeNode[1]->attr.name);
		switch(expKind1)
		{
		case ConstIK:
			if(type2&&strcmp(type2,"integer"))
			{
				return -1;
			}
			break;
					
		case ConstRK:
			if(type2&&strcmp(type2,"real"))
			{
				return -1;
			}
			break;
						
		case ConstCK:
			if(type2&&strcmp(type2,"char"))
			{
				return -1;
			}
			break;

		case ConstSK:
			if(type2&&strcmp(type2,"string"))
			{
				return -1;
			}
			break;

		default:
			return -1;
		}
	}
	else
	{
		if(expKind1!=expKind2)
		{
			return -1;
		}
	}

	return 0;
}

void checkCondExp(TreeNode *t, TreeNode *expNode)
{
	switch(expNode->kind.exp)
	{
	case OpK:	
		//variable declaration checking:
		getExpExpKind(expNode->child[0], NULL, 1);
		getExpExpKind(expNode->child[1], NULL, 1);

		//check wether the expression is boolean
		//EQ,NE,GE, GT,LE,LT,PLUS,MINUS,MUL,DIV,OR,AND,MOD,NOT
		switch(expNode->attr.op)
		{
		case EQ:
		case NE:
		case GE:
		case GT:
		case LE:
		case LT:
			
		case OR:
		case AND:
		case NOT:
			break;
			
		default:
			typeError(t, "Type of conditional expression is not boolean");
			break;
		}
		break;

	default:
		typeError(t, "Type of conditional expression is not boolean");
		break;
	}
}

/* Procedure insertNode inserts 
 * identifiers stored in t into 
 * the symbol table 
 */
static void insertNode( TreeNode * t)
{
	switch (t->nodekind)
	{ 
	case StmtK:
		switch (t->kind.stmt)
		{ 
			TreeNode *expNode;

		case DeclK:
			if(t->child[0]->nodekind==StmtK)
			{
				if(t->child[0]->kind.stmt==PHeadK)
				{
					declInsert(t->child[0]->child[0], "procedure", FUNC);
					a_curFuncNum=funcAmt-1;
					st_setCurFuncNum(a_curFuncNum);
					funcPath[++funcPathI]=a_curFuncNum;
				}
				else if(t->child[0]->kind.stmt==FHeadK)
				{
					declInsert(t->child[0]->child[0], referGetType(t->child[0]->child[2]), FUNC);
					a_curFuncNum=funcAmt-1;
					st_setCurFuncNum(a_curFuncNum);
					declInsert(t->child[0]->child[0], referGetType(t->child[0]->child[2]), VAR);
					funcPath[++funcPathI]=a_curFuncNum;
				}
			}
			//if it is not a variable declaration, then break
			if(!(t->child[0]->nodekind==ExpK&&t->child[0]->kind.exp==IdK))
			{
				break;
			}
		case ParaK:
			{
				char *varType=referGetType(t->child[1]);
				TreeNode *temp;

				if(!strcmp(varType, "ArrayType"))
				{
					int offsetPlus=t->child[1]->child[0]->child[1]->attr.ival-t->child[1]->child[0]->child[0]->attr.ival;
					varType=referGetType(t->child[1]->child[1]);
					for(temp=t->child[0]; temp!=NULL; temp=temp->sibling)
					{
						declInsert(temp, varType, VAR);
					}
					location[a_curFuncNum]+=offsetPlus;
				}
				else
				{
					for(temp=t->child[0]; temp!=NULL; temp=temp->sibling)
					{
						declInsert(temp, varType, VAR);
					}
				}
			}
			break;
 
		case TypeDefK:
			declInsert(t->child[0], referGetType(t->child[1]), TYPE);
			break;

		case AssignK:
			{
				TreeNode *idTreeNode[2]={NULL, NULL};
				ExpKind expKind1=getExpExpKind(t->child[0], idTreeNode, 1);
				ExpKind expKind2=getExpExpKind(t->child[1], idTreeNode+1, 1);
				if(!(expKind1==IdK&&idTreeNode[0]==NULL||expKind2==IdK&&idTreeNode[1]==NULL))
				{
					//if there's variables then they are all defined:
					if(checkVarTypes2(expKind1, expKind2, idTreeNode))
					{
						typeError(t->child[0],"Assigned with different type variable");
					}
				}
			}
			break;

		case RepeatK:
			checkCondExp(t, t->child[1]);
			break;
			 
		case WhileK:
			checkCondExp(t, t->child[0]);
			break;

		case IfK:
			checkCondExp(t, t->child[0]);
			break;

		case ForK:
			if(t->child[0]!=NULL&&t->child[0]->nodekind==StmtK&&t->child[0]->kind.stmt==AssignK)
			{
				TreeNode *idTreeNode[2]={NULL, NULL};
				ExpKind expKind1=getExpExpKind(t->child[0]->child[1], idTreeNode, 0); 
				ExpKind expKind2=getExpExpKind(t->child[2], idTreeNode+1, 1);
				if(!(expKind1==IdK&&idTreeNode[0]==NULL||expKind2==IdK&&idTreeNode[1]==NULL))
				{
					//if there's variables then they are all defined:
					if(checkVarTypes2(expKind1, expKind2, idTreeNode))
					{
						typeError(t,"Start and end marks types not matched");
					}
				}
			}
			break;

		//procedure call:
		case ProcK:
			//check declaration
			if(!referInsert(t->child[0], FUNC))
			{
				//!!! if declared, then check type
			}
			break;

		case WriteK:
			{
				TreeNode *idTreeNode[1];
				if(getExpExpKind(t->child[0], idTreeNode, 1)==IdK&&st_getType(idTreeNode[0]->attr.name)=="boolean")
				{
					typeError(t->child[0], "Boolean type can't be parameter of function write");
				}
			}
			break;
        
		default:
			break;
		}
		break;
    
	case ExpK:
		switch (t->kind.exp)
		{ 
		case ConstExpK:
			{
				ExpKind expKind=getExpExpKind(t->child[1], NULL, 0);
				switch(expKind)
				{
					//the parser can ensure expKind must be const
				case ConstIK:
					declInsert(t->child[0], "integer", CONST);
					break;

				case ConstRK:
					declInsert(t->child[0], "real", CONST);
					break;

				case ConstCK:
					declInsert(t->child[0], "char", CONST);
					break;

				case ConstSK:
					declInsert(t->child[0], "string", CONST);
					break;
				}
			}
			break;

		case OpK:
			{
				TreeNode *idTreeNode[2]={NULL, NULL};
				ExpKind expKind1=getExpExpKind(t->child[0], idTreeNode, 0);
				ExpKind expKind2=getExpExpKind(t->child[1], idTreeNode+1, 0);
				if(!(expKind1==IdK&&idTreeNode[0]==NULL||expKind2==IdK&&idTreeNode[1]==NULL))
				{
					//if there's variables then they are all defined:
					if(checkVarTypes2(expKind1, expKind2, idTreeNode))
					{
						typeError(t,"Operand types not matched");
					}
				}
			}
			break;

		//function call:
		case CallK:
			//check declaration
			if(!referInsert(t->child[0], FUNC))
			{
				//!!! if declared, then check type
			}
			break;
        
		default:
			break;
		}
		break;

	default:
		break;
	}
}

void initSymTab(void)
{
	st_insert("integer", "integer", -1, -1);
	st_insert("boolean", "boolean", -1, -1);
	st_insert("string", "string", -1, -1);
	st_insert("real", "real", -1, -1);
}

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)
{
	initSymTab();
	traverse(syntaxTree,insertNode,nullProc);
	if (TraceAnalyze)
	{ 
		int funcI;
		for(funcI=0;funcI<MAXFUNCAMT;funcI++)
		{
			if(location[funcI]==0)
			{
				continue;
			}
			fprintf(listing,"\nSymbol table %d:\n\n", funcI);
			st_setCurFuncNum(funcI);
			printSymTab(listing);
		}
	}
	a_curFuncNum=0;
	st_setCurFuncNum(0);
}

int enterFuncDecl(char *funcName)
{
	printf("in %d table, search %s, result %d\n", a_curFuncNum, funcName, st_lookup(funcName));
	a_curFuncNum=st_lookup(funcName);
	st_setCurFuncNum(a_curFuncNum);
	funcPath[++funcPathI]=a_curFuncNum;
	return location[a_curFuncNum];
}

int leaveFuncDecl(void)
{
	if(funcPathI!=0)
	{
		a_curFuncNum=funcPath[--funcPathI]; 
		st_setCurFuncNum(a_curFuncNum);
	}
	return location[a_curFuncNum];
}

int getFuncAmt(void)
{
	return funcAmt;
}