#define _CRT_SECURE_NO_WARNINGS

#include"global.h"
#include"parser.tab.h"
#include"util.h"
#include"Analyze.h"
#include"CGEN.h"



int TraceAnalyze = TRUE;
int Error = FALSE;
int TraceParser=TRUE;
int errorAmt = 0;
extern TreeNode* parse(void);
int TraceCode = FALSE;
FILE *codefile;



int main()
{
	TreeNode* root;
	char *codename = "1.txt";
	root= parse();
	printTree(root);
	puts("Parse tree OK!");
	
	buildSymtab(root);
	puts("Symbol table built.");
	if(Error)
	{
		printf("%d error(s) occurred in type checking.\n", errorAmt);
	}
	else
	{
		puts("Type checking OK!");
	}
	codefile = fopen(codename, "w+");
	if (codefile == NULL)
	{
		printf("Open file error!\n");
		return -1;
	}
	codeGen(root, codename);

	system("pause");
	return 0;
}