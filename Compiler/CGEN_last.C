#define _CRT_SECURE_NO_WARNINGS

/****************************************************/
/* File: cgen.c                                     */
/* The code generator implementation                */
/* for the TINY compiler                            */
/* (generates code for the TM machine)              */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "global.h"
#include "symtab.h"
#include "code.h"
#include "cgen.h"

/* tmpOffset is the memory offset for temps
   It is decremented each time a temp is
   stored, and incremeted when loaded again
*/


/* prototype for internal recursive code generator */
static void cGen (TreeNode * tree);

int record_main = 0;

int total_fun = 0;

/* Procedure genStmt generates code at a statement node */
static void genStmt(TreeNode * tree)
{
	TreeNode * p1, * p2, * p3, * p4, * p5;
	int savedLoc1,savedLoc2,currentLoc;
	int loc, loc2 , b, j;
	int re = 0;
	char fun_name[100];
	switch (tree->kind.stmt)
	{
		case RoutineK:
			re = record_main++;
			if (TraceCode)
				emitComment("-> RoutineK");
			p1 = tree->child[0];
			cGen(p1);

			if (re == 0)
				emitCommand("local_main:");
			
			p2 = tree->child[1];
			cGen(p2);
			if (TraceCode)
				emitComment("<- RoutineK");
			break;

		case RHeadK:
			if (TraceCode)
				emitComment("-> RHeadK");
			p1 = tree->child[0];//const 
			cGen(p1);

			p2 = tree->child[1];//type
			cGen(p2);

			p3 = tree->child[2];//decl
			cGen(p3);

			p4 = tree->child[3];//routine
			cGen(p4);

			if (TraceCode)
				emitComment("<- RHeadK");
			
			break;

		case TypeDefK:
			p1 = tree->child[1];
			//cGen(p1);
			break;
			
		case DeclK:
			if (TraceCode)
				emitComment("-> DeclK");
			if (!strcmp(tree->attr.name, "ProcDecl"))
			{
				int tmpOffset = 0;


				emitCommand("j local_main");
				p1 = tree->child[0];

				p2 = tree->child[1];
				
				strcpy(fun_name, p1->child[0]->attr.name);
				
				useJalLab(fun_name);
				//set flag
 				tmpOffset = enterFuncDecl(fun_name);


				emitI("addi", $sp, $sp, tmpOffset * -4);
				//emitI("sw", $ra, $sp, (tmpOffset - 1));
				
				cGen(p2);
				//emitI("lw", $ra, $sp, (tmpOffset - 1));
				emitI("addi", $sp, $sp, tmpOffset * 4);
				leaveFuncDecl();

				tmpOffset = 0;
				//reset flag

				emitR("jr", $ra, 0, 0);
			}

			else if (!strcmp(tree->attr.name, "FuncDecl"))
			{

				int tmpOffset = 0;
				
				if (record_main == 1)
					emitCommand("j local_main");
				p1 = tree->child[0];
				
				p2 = tree->child[1];
				
				

				strcpy(fun_name, p1->child[0]->attr.name);

				useJalLab(fun_name);
				//set flag
				tmpOffset = enterFuncDecl(fun_name);
				isfunc = 1;




				emitI("addi", $sp, $sp, tmpOffset * -4);
				//emitI("sw", $ra, $sp, (tmpOffset - 1));
				
				cGen(p2);
				
				//emitI("lw", $ra, $sp, (tmpOffset - 1));
				emitI("addi", $sp, $sp, tmpOffset * 4);
				leaveFuncDecl();
				isfunc = 0;

				tmpOffset = 0;
				//reset flag

				emitR("jr", $ra, 0, 0);
			}

			break;


			if (TraceCode)
				emitComment("<- DeclK");
		case IfK:
			if(TraceCode)
					emitComment("-> if");

			p1 = tree->child[0];
			cGen(p1);//result in ac
			b = createBLab();
			emitI("beq", ac, $zero, b);//if ac == 0 that mean false jump to else


			p2 = tree->child[1];
			cGen(p2);

			j = createJLab();
			emitJ("j", j);

			useBLab(b);

			p3 = tree->child[2];
			cGen(p3);

			useJLab(j);

			if (TraceCode)
				emitComment("<- if");
			break; /* if_k */

		case RepeatK:
			if (TraceCode)
				emitComment("-> repeat") ;
			
			b = createBLab();
			useBLab(b);
			p1 = tree->child[0];
			cGen(p1);

			p2 = tree->child[1];
			cGen(p2);//judge result in ac

			emitI("beq", ac, $zero, b);


			if (TraceCode)
				emitComment("<- repeat") ;
			break; /* repeat */


		case WhileK:
			if (TraceCode)
				emitComment("-> while");
			

			j = createJLab();
			useJLab(j);

			b = createBLab();
			p1 = tree->child[0];
			cGen(p1);//judge result in ac
			emitI("beq", ac, $zero, b);

			p2 = tree->child[1];
			cGen(p2);

			emitJ("j", j);

			useBLab(b);
			


			if (TraceCode)
				emitComment("<- while");
			break;//while

		case ForK:

			if (TraceCode)
				emitComment("-> for");

			p1 = tree->child[0];
			cGen(p1);

			p2 = tree->child[1];
			//cGen(p2);
			

			j = createBLab();
			useJLab(j);
			
			
			p3 = tree->child[2];
			cGen(p3);//return in reg_temp


			int reg_loc = reg_temp;
			if (p2->attr.ival == 1)//to
			{
				loc = st_lookup(p1->child[0]->attr.name);
			
				emitI("lw", reg_temp = getTmpReg(0), $sp, loc);
				emitR("slt", reg_temp, reg_loc, reg_temp);//if reg_temp = 1 then loop_end
				b = createBLab();
				emitI("bne", reg_temp, $zero, b);


			}
			else//downto
			{
				loc = st_lookup(p1->child[0]->attr.name);
			
				emitI("lw", reg_temp = getTmpReg(0), $sp, loc);
				emitR("slt", reg_temp, reg_temp, reg_loc);//if reg_temp = 1 then loop_end
				b = createBLab();
				emitI("bne", reg_temp, $zero, b);

				

			}
			

			p4 = tree->child[3];
			cGen(p4);
			if (p2->attr.ival == 1)//to
			{
				loc = st_lookup(p1->child[0]->attr.name);
			
				emitI("lw", reg_temp = getTmpReg(0), $sp, loc);
				emitI("addi", reg_temp, reg_temp, 1);//reg_temp+=1
				emitI("sw", reg_temp, $sp, loc);
			}
			else
			{
				loc = st_lookup(p1->child[0]->attr.name);
			
				emitI("lw", reg_temp = getTmpReg(0), $sp, loc);
				emitI("subi", reg_temp, reg_temp, 1);//reg_temp-=1
				emitI("sw", reg_temp, $sp, loc);
			}

			freeReg(reg_temp);
			freeReg(reg_loc);
			
			emitJ("j", j);
			useBLab(b);

			if (TraceCode)
				emitComment("<- for");

			break;


		case GotoK:
			if (TraceCode)
				emitComment("-> goto");


			if (TraceCode)
				emitComment("<- goto");
			break;

		case AssignK:
			if (TraceCode)
				emitComment("-> assign") ;


			p1 = tree->child[0];

			p2 = tree->child[1];

			if (p2->kind.exp == IdK)
				str_count = st_lookup(p2->attr.name);
			else
				str_count = st_lookup(p1->attr.name);

			cGen(p2);//get reg_temp
			
			char * type = st_getType(p1->attr.name);

			if (!strcmp(type, "string"))
				set_char("la", reg_temp, str_count);

			/*
			if (p2->kind.exp == ConstSK)
				set_char("la", reg_temp, str_count);
				*/

			loc = st_lookup(p1->attr.name);
			
			isFloat = check_float(type);

			if (isFloat)
			{
				if (loc == 0 && isfunc)//the function var
					emitR("add.s", $v1, $zero, reg_temp);
				else
					emitR("add.s", reg_temp, $zero, reg_temp);
				emitI("s.s", reg_temp, $sp, loc);
			}
			else
			{
				if (loc == 0 && isfunc)
					emitR("add", $v1, $zero, reg_temp);
				else
					emitR("add", reg_temp, $zero, reg_temp);
				emitI("sw", reg_temp, $sp, loc);
			}

			freeReg(reg_temp);

			if (TraceCode)
				emitComment("<- assign");
		break; //assign_k


		
		case ArrayAssignK:
		if (TraceCode)
			emitComment("-> ArrayAssignK");
		p1 = tree->child[0];//name of array


		p2 = tree->child[1];//offset of array
		
		
		loc = st_lookup(p1->attr.name);
		loc += p2->attr.ival;
		p3 = tree->child[2];//exp of the array

		cGen(p3);//reg_temp is the value

		emitI("sw", reg_temp, $sp, loc);

		freeReg(reg_temp);

		if (TraceCode)
			emitComment("<- ArrayAssignK");
		break;
		

		
		case WriteK:
			if (TraceCode)
				emitComment("-> WriteK");

			p1 = tree->child[0];
			char *var_type = st_getType(p1->attr.name);
			
			if (!strcmp(var_type, "string"))
			{
				loc = st_lookup(p1->attr.name);
				
					emitI("lw", $a0, $sp, loc);

				//save $ra
				emitI("addi", $sp, $sp, -8);
				emitI("sw", $ra, $sp, 1);

				syscall("jal", "printf");
				println();

				
				emitI("lw", $ra, $sp, 1);
				emitI("addi", $sp, $sp, 8);
			}
			else
			{
				str_count = st_lookup(p1->attr.name);

				str[str_count] = malloc(sizeof(tree->attr.name) + 1);
				strcpy(str[str_count], "%d");

				set_char("la", $a0, str_count);

				loc = st_lookup(p1->attr.name);
				/*
				{
					char *Float_type = st_getType(p1->attr.name);
					isFloat = check_float(Float_type);
				}
				*/
				if (isFloat)
					emitI("l.s", $a0, $sp, loc);
				else
					emitI("lw", $a1, $sp, loc);
				
				//save $ra
				emitI("addi", $sp, $sp, -8);
				emitI("sw", $ra, $sp, 1);

				syscall("jal", "printf");
				println();


				emitI("lw", $ra, $sp, 1);
				emitI("addi", $sp, $sp, 8);

			}


			if (TraceCode)
				emitComment("<- Writek");

		break;
      
		
		case ProcK:
			if (TraceCode)
				emitComment("-> ProK");
			p1 = tree->child[0];
			strcpy(fun_name, p1->attr.name);

			int temp_loc = getTmpReg(0);//record the number of parameter

			

			p2 = tree->child[1];
			cGen(p2);	//reg_temp

			int tmpOffset = 0;

			

			tmpOffset = enterFuncDecl(fun_name);
			
			//save the ra
			emitI("addi", $sp, $sp, -4);
			emitI("sw", $ra, $sp, 0);
			emitI("addi", $sp, $sp, -4 * (tmpOffset + 1));
			


			int position = 0;
			for (temp_loc += 1; temp_loc <= reg_temp; temp_loc++, position++)
			{
				emitI("sw", temp_loc, $sp, -1 * (tmpOffset - position));
			}
			
			emitJal(fun_name);
			

			emitI("addi", $sp, $sp, 4 * (tmpOffset + 1));
			emitI("lw", $ra, $sp, 0);
			emitI("addi", $sp, $sp, 4);


			leaveFuncDecl();

			if (TraceCode)
				emitComment("<- Prok");
			break;

		default:
		break;
    }
} /* genStmt */

/* Procedure genExp generates code at an expression node */
static void genExp( TreeNode * tree)
{
	int loc;
	TreeNode * p1, * p2;
	char fun_name[100];
	switch (tree->kind.exp)
	{
		case ConstIK:
			if (TraceCode)
				emitComment("-> ConstIK");
			
			emitI("ori", reg_temp = getTmpReg(0), $zero, tree->attr.ival);
			isFloat = 0;
			if (TraceCode)
				emitComment("<- ConstIK");
			break;
		case ConstRK:
			if (TraceCode)
				emitComment("-> ConstRK");

			emitI("ori", reg_temp = getTmpReg(1), $zero, tree->attr.fval);
			isFloat = 1;

			if (TraceCode)
				emitComment("<- ConstRK");
			break;


		case ConstSK:
			if (TraceCode)
				emitComment("-> ConstSK");
			reg_temp = getTmpReg(0);

			str[str_count] = malloc(sizeof(tree->attr.name) + 1);
			strcpy(str[str_count], tree->attr.name);
			str[str_count] += 1;
			str[str_count][strlen(str[str_count])-1] = '\0';

			//emitI("ori", reg_temp = getTmpReg(0), $zero, tree->attr.sval);
			if (TraceCode)
				emitComment("<- ConstSK");
			break;

			/*
			emitI("sw", reg_temp, $sp, loc);

			freeReg(reg_temp);

			if (TraceCode)
				emitComment("<- Const") ;
			*/


		case ConstExpK:
			if (TraceCode)
				emitComment("-> ConstExpK");
			
			p1 = tree->child[0];
			cGen(p1);

			str_count = st_lookup(p1->attr.name);
			
			p2 = tree->child[1];
			cGen(p2);

			char * type = st_getType(p1->attr.name);
			
			if (!strcmp(type, "string"))
				set_char("la", reg_temp, str_count);
			/*
			if (p2->kind.exp == ConstSK)
				set_char("la", reg_temp, str_count);
				*/
			
				
			loc = st_lookup(p1->attr.name);
			if (!strcmp(type, "integer"))
			{
				emitR("add", reg_temp, $zero, reg_temp);
				emitI("sw", reg_temp, $sp, loc);
			}
			if (!strcmp(type, "real"))
			{
				emitR("add.s", reg_temp, $zero, reg_temp);
				emitI("s.s", reg_temp, $sp, loc);
			}
			freeReg(reg_temp);

			if (TraceCode)
				emitComment("<- ConstExpK");
			break;



		case ArrayK:
		if (TraceCode)
			emitComment("-> ArrayexpK");

		p1 = tree->child[0];

		

		p2 = tree->child[1];

		cGen(p2);//get the reg_temp value

		loc = st_lookup(p1->attr.name);

		int reg_loc = reg_temp;
		reg_temp = getTmpReg(0);
		emitR("sll", reg_temp, reg_loc, 2);
		emitR("add", $sp, $sp, reg_temp);
		
		emitI("lw", reg_loc, $sp, loc);
		emitR("sub", $sp, $sp, reg_temp);
		freeReg(reg_temp);

		reg_temp = reg_loc;
		
		
		//reg_temp to use for assgin

		if (TraceCode)
			emitComment("<- ArrayexpK");



			break;

		case IdK:
			if (TraceCode)
				emitComment("-> IdK");

			loc = st_lookup(tree->attr.name);
			{
				char *Float_type = st_getType(tree->attr.name);
				isFloat = check_float(Float_type);
			}
			if (isFloat)
				emitI("l.s", reg_temp = getTmpReg(isFloat), $sp, loc);
			else
				emitI("lw", reg_temp = getTmpReg(isFloat), $sp, loc);
			

			if (TraceCode)
				emitComment("<- IdK");
			break; //IdK



		case OpK :
			if (TraceCode)
				emitComment("-> Op") ;
			/* accumulator */
			int temp1;

			/* 2nd accumulator */
			int temp2;
			p1 = tree->child[0];

			cGen(p1);//get temp1
			temp1 = reg_temp;
			

			p2 = tree->child[1];
			
			cGen(p2);//get temp2
			temp2 = reg_temp;



			switch(tree->attr.op)
			{
				

				case EQ:
					emitR("sub", ac, temp1, temp2);//if ac == 0 means equal
					emitI("xori", ac, ac, -1);//if ac == 1 means equal
					break;
				case NE:
					emitR("sub", ac, temp1, temp2);//if ac == 0 means equal
					break;
				case GE://temp1 >= temp2
					emitR("slt", ac, temp1, temp2);//temp1 < temp2 ac = 1
					emitI("xori", ac, ac, -1);//if temp1 >= temp2 ac = 1
					break;
				case GT://temp1 > temp2
					emitR("slt", ac, temp2, temp1);//temp1 < temp2 ac = 1
					
					break;
				case LE://temp1 <= temp2
					emitR("slt", ac, temp2, temp1);//temp1 > temp2 ac = 1
					emitI("xori", ac, ac, -1);//if temp1 <= temp2 ac = 1
					break;
				case LT://temp1 < temp2
					emitR("slt", ac, temp1, temp2);//temp1 < temp2 ac = 1

					break;
				case PLUS:
					if (isFloat)
						emitR("add.s", reg_temp = getTmpReg(1), temp1, temp2);
					else
						emitR("add", reg_temp = getTmpReg(0), temp1, temp2);
					break;
				case MINUS:
					if (isFloat)
						emitR("sub.s", reg_temp = getTmpReg(1), temp1, temp2);
					else
						emitR("sub", reg_temp = getTmpReg(0), temp1, temp2);
					break;
				case MUL:
					if (isFloat)
						emitR("mul.s", reg_temp = getTmpReg(1), temp1, temp2);
					else
						emitR("mul", reg_temp = getTmpReg(0), temp1, temp2);
					break;
				case DIV:
					if (isFloat)
						emitR("div.s", reg_temp = getTmpReg(1), temp1, temp2);
					else
						emitR("div", reg_temp = getTmpReg(0), temp1, temp2);
					break;
				case OR:
					emitR("or", reg_temp = getTmpReg(0), temp1, temp2);
					break;
				case AND:
					emitR("and", reg_temp = getTmpReg(0), temp1, temp2);
					break;
				case MOD:
					emitR("rem", reg_temp = getTmpReg(0), temp1, temp2);
					break;
				case NOT:
					emitI("xori", reg_temp = getTmpReg(0), temp1, -1);
					break;
			}


			freeReg(temp1);
			freeReg(temp2);
			
			if (TraceCode)
				emitComment("<- Op") ;
			break; //OpK

		case CallK:
			if (TraceCode)
				emitComment("-> CallK");
			p1 = tree->child[0];

			strcpy(fun_name, p1->attr.name);

			int temp_loc = getTmpReg(0);//record the number of parameter



			p2 = tree->child[1];
			cGen(p2);	//reg_temp



			int tmpOffset = 0;

			tmpOffset = enterFuncDecl(fun_name);

			//save the ra
			emitI("addi", $sp, $sp, -4);
			emitI("sw", $ra, $sp, 0);
			emitI("addi", $sp, $sp, -4 * (tmpOffset + 1));

			if (temp_loc + 1 == reg_temp)//must be function
			{

				int position = 1;
				for (temp_loc += 1; temp_loc <= reg_temp; temp_loc++, position++)
				{
					emitI("sw", temp_loc, $sp, -1 * (tmpOffset - position));
				}
			}
			else//for procedure
			{

				int position = 1;
				for (temp_loc += 1; temp_loc <= reg_temp; temp_loc++, position++)
				{
					emitI("sw", temp_loc, $sp, -1 * (tmpOffset - position));
				}
			}
			
			

			emitJal(fun_name);

			emitI("addi", $sp, $sp, 4 * (tmpOffset + 1));
			emitI("sw", $ra, $sp, 0);
			emitI("addi", $sp, $sp, 4);
			
			

			leaveFuncDecl();

			if (isFloat)
				emitR("add.s", reg_temp = getTmpReg(isFloat), $zero, $v1);
			else
				emitR("add", reg_temp = getTmpReg(isFloat), $zero, $v1);


			if (TraceCode)
				emitComment("<- CallK");
			break;


		default:
		break;
  }
} /* genExp */

/* Procedure cGen recursively generates code by
 * tree traversal
 */
static void cGen(TreeNode * tree)
{
	if (tree != NULL)
	{
		switch (tree->nodekind)
		{
			case StmtK:
				genStmt(tree);
			break;
			case ExpK:
				genExp(tree);
			break;
			default:
			break;
		}
		cGen(tree->sibling);
	}
}

/**********************************************/
/* the primary function of the code generator */
/**********************************************/
/* Procedure codeGen generates code to a code
 * file by traversal of the syntax tree. The
 * second parameter (codefile) the file name
 * of the code file, and is used to print the
 * file name as a comment in the code file
 */
void codeGen(TreeNode * syntaxTree, char * codefile)
{
	char * s = malloc(strlen(codefile)+7);
	//generate the file head
	strcpy(s,"File: ");
	strcat(s,codefile);
	emitComment("Pascal Compilation to MIPS Code");
	emitComment(s);
	
	/* generate standard prelude */
	emitComment("Standard prelude:");
	
	emitComment("This Compiler is written by Frank_Shaw:");

	emitComment("End of standard prelude.");
	
	total_fun = getFuncAmt();

	/* generate code for TINY program */
	cGen(syntaxTree);
	
	//int j = createJLab();
	//useJLab(j);
	//emitJ("j", j);
	emitComment("End of execution.");

	

	/* data */
	emitComment(".data");
	emitCommand("compiler_enter:\n\t.ascii\t\"\\n\"");
	

	print(str);
	/* finish */

	emitComment("End of data.");

	
}

