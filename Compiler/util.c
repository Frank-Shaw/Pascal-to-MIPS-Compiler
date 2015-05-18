#define _CRT_SECURE_NO_WARNINGS
#include "global.h"
#include "util.h"

void nodeInsert( TreeNode * node1, TreeNode * node2)
{
	TreeNode * temp;
	temp=node1;
	while(temp->sibling!=NULL)
		temp=temp->sibling;
	temp->sibling=node2;	
}

void printToken( TokenType token, const char* tokenString )
{ switch (token)
  { 
    case LT: fprintf(listing,"<\n"); break;
    case LE: fprintf(listing,"<=\n"); break;
    case EQ: fprintf(listing,"=\n"); break;
    case NE: fprintf(listing,"!=\n"); break;
    case GE: fprintf(listing,">=\n"); break;
    case GT: fprintf(listing,">\n"); break;
    case NOT: fprintf(listing,"NOT\n"); break;
    case AND: fprintf(listing,"and\n"); break;
    case MOD: fprintf(listing,"%\n"); break;
    case PLUS: fprintf(listing,"+\n"); break;
    case MINUS: fprintf(listing,"-\n"); break;
    case MUL: fprintf(listing,"*\n"); break;
    case DIV: fprintf(listing,"/\n"); break;
    case OR: fprintf(listing,"or\n"); break;

      break;
    default: /* should never happen */
      fprintf(listing,"Unknown token: %d\n",token);
  }
}


TreeNode * newStmtNode(StmtKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = StmtK;
    t->kind.stmt = kind;
    t->lineno = lineno;
  }
  return t;
}



TreeNode * newExpNode(ExpKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = ExpK;
    t->kind.exp = kind;
    t->lineno = lineno;
    t->type = Void;
  }
  return t;
}



char * copyString(char * s)
{ int n;
  char * t;
  if (s==NULL) return NULL;
  n = strlen(s)+1;
  t = malloc(n);
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else strcpy(t,s);
  return t;
}


static indentno = 0;


#define INDENT indentno+=2
#define UNINDENT indentno-=2


static void printSpaces(void)
{ int i;
  for (i=0;i<indentno;i++)
    fprintf(listing," ");
}


void printTree( TreeNode * tree )
{ 
  int i;
  INDENT;
  while (tree != NULL)
  {
    printSpaces();
    if (tree->nodekind==StmtK)
    { 
      switch (tree->kind.stmt) 
      {
        case TypeDefK:
          fprintf(listing,"TypeDefK\n");
          break;
        case DeclK:
          fprintf(listing,"DeclK\n");
          break;
        case TypeK:
		  fprintf(listing,"TypeK: %s\n",tree->attr.name);
          break;
        case ParaK:
          fprintf(listing,"ParaK\n");
          break;
        case RoutineK:
          fprintf(listing,"RoutineK\n");
          break;
        case RHeadK:
          fprintf(listing,"RHeadK\n");
          break;
        case PHeadK:
          fprintf(listing,"PHeadK\n");
          break;
        case FHeadK:
          fprintf(listing,"FHeadK\n");
          break;
        case ElemAssignK:
          fprintf(listing,"ElemAssignK, struct:\n");
          break;
        case ArrayAssignK:
          fprintf(listing,"ArrayAssignK, name:\n");
          break;
        case IfK:
          fprintf(listing,"IfK\n");
          break;
        case RepeatK:
          fprintf(listing,"RepeatK\n");
          break;
        case AssignK:
          fprintf(listing,"AssignK: \n");
          break;
        case ReadK:
          fprintf(listing,"ReadK: %s\n",tree->attr.name);
          break;
        case WhileK:
          fprintf(listing,"WhileK\n");
          break;
        case WriteK:
          fprintf(listing,"WriteK\n");
          break;
        case ForK:
          fprintf(listing,"ForK \n");
          break;
        case CaseK:
          fprintf(listing,"CaseK\n");
          break;
        case GotoK:
          fprintf(listing,"GotoK\n");
          break;
        case ProcK:
          fprintf(listing,"ProcK: \n");
          break;
        default:
          fprintf(listing,"Unknown ExpNode kind\n");
          break;
      }
    }
    else if (tree->nodekind==ExpK)
    { 
      switch (tree->kind.exp) {
		case CallK:
          fprintf(listing,"CallK\n");
          break;
		case ConstExpK:
          fprintf(listing,"ConstExpK:\n");
          break;
        case CaseExpK:
          fprintf(listing,"CaseExpK:\n");
          break;
        case ConstIK:
          fprintf(listing,"ConstIK: %d\n",tree->attr.ival);
          break;
        case ConstRK:
          fprintf(listing,"ConstRK: %f\n",tree->attr.fval);
          break;
        case ConstCK:
          fprintf(listing,"ConstCK: %c\n",tree->attr.cval);
          break;
        case ConstSK:
          fprintf(listing,"ConstSK: %s\n",tree->attr.sval);
          break;
        case UnaryK:
          fprintf(listing,"UnaryK: %d",tree->attr.ival);
          break;
        case OpK:
          fprintf(listing,"OpK: ");
          printToken(tree->attr.op,"\0");
          break;
        case ArrayK:
          fprintf(listing,"ArrayK: \n");
          break;
        case ElemK:
          fprintf(listing,"ElemK: \n");
          break;
        case IdK:
          fprintf(listing,"IdK: %s\n",tree->attr.name);
          break;
        default:
          fprintf(listing,"Unknown ExpNode kind\n");
          break;
      }
    }
    else fprintf(listing,"Unknown node kind\n");
    for (i=0;i<MAXCHILDREN;i++)
         printTree(tree->child[i]);
    tree = tree->sibling;
  }
  UNINDENT;
}