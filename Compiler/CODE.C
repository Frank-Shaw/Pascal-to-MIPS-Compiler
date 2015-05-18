#include <stdlib.h>
#include <stdio.h>
#include "global.h"
#include "code.h"

#define _CRT_SECURE_NO_WARNINGS

extern FILE *codefile;

int code_sp = 0;

int JLab = 0;

int BLab = 0;

int JalLab = 0;

static char* regFile[] = {
	"$zero",
	"$at",
	"$v0",
	"$v1",
	"$a0",
	"$a1",
	"$a2",
	"$a3",
	"$t0",
	"$t1",
	"$t2",
	"$t3",
	"$t4",
	"$t5",
	"$t6",
	"$t7",
	"$s0",
	"$s1",
	"$s2",
	"$s3",
	"$s4",
	"$s5",
	"$s6",
	"$s7",
	"$t8",
	"$t9",
	"$k0",
	"$k1",
	"$gp",
	"$sp",
	"$fp",
	"$ra",
	
	"$f0",
	"$f1",
	"$f2",
	"$f3",
	"$f4",
	"$f5",
	"$f6",
	"$f7",
	"$f8",
	"$f9",
	"$f10",
	"$f11",
	"$f12",
	"$f13",
	"$f14",
	"$f15",
	"$f16",
	"$f17",
	"$f18",
	"$f19",
	"$f20",
	"$f21",
	"$f22",
	"$f23",
	"$f24",
	"$f25",
	"$f26",
	"$f27",
	"$f28",
	"$f29",
	"$f30",
	"$f31",
};
int reg[64];	//0 to 31 is for int register, and 32 to 63 is for float register

void resetAllreg() {
	int i;
	for(i = 0; i < 64; i++) 
		reg[i] = 0;
}

void useReg(int i) {
	if (i < 0 || i > 31) return;
	reg[i] = 1;
}
void freeReg(int i) {		
	if (i < 0 || i > 63) return;
	reg[i] = 0;
}

int getTmpReg(int F) 
{
	int i;
	if (F)
		return getFloatReg();
	for(i = 8; i < 24; i++) {
		if (reg[i] == 0) {
			reg[i] = 1;
			printf("use reg %s",regFile[i]);
			return i;
		}
	}
	return -1;
}

int getFloatReg() {
	int i;
	for(i = 32; i <64; i++) {
		if (reg[i] == 0) {
			reg[i] = 1;
			printf("use reg %s",regFile[i]);
			return i;
		}
	}
	return -1;	
}

void emitR(char* op, int dst, int src1, int src2 ) {
	if(!strcmp(op,"jr"))
		fprintf(codefile, "%s %s\n", op, regFile[dst]);	//jr
	else if (!strcmp(op, "sll") || !strcmp(op, "srl"))
		fprintf(codefile, "%s %s, %s, %d\n", op, regFile[dst], regFile[src1], src2);	//R-type
	else
		fprintf(codefile, "%s %s, %s, %s\n", op, regFile[dst], regFile[src1], regFile[src2]);	//R-type
		
}

void emitI(char* op, int dst, int src, float imm)
{
	
	if (!(strcmp(op, "sw") && strcmp(op, "lw")))
		fprintf(codefile, "%s %s, %.0f(%s)\n", op, regFile[dst], imm*4, regFile[src]);	//sw|lw-type

	else if (!(strcmp(op, "beq") && strcmp(op, "bne")))
		fprintf(codefile, "%s %s, %s, BLab%.0f\n", op, regFile[dst], regFile[src], imm);	//beq|bne-type
	else
	{
		if (isFloat)
			fprintf(codefile, "%s %s, %s, %f\n", op, regFile[dst], regFile[src], imm);	//I-type
		else
			fprintf(codefile, "%s %s, %s, %.0f\n", op, regFile[dst], regFile[src], imm);	//I-type

	}
		
	
}

void emitJ(char* op, int imm){
	fprintf(codefile,"%s JLab%d\n",op, imm);	//J-type
}

void emitJal(char * name){
	fprintf(codefile, "jal fun_%s\n", name);	//J-type
}

void emitComment(char * c)
{
	if (TraceCode) fprintf(codefile, "# %s\n", c);
}


void syscall(char * op, char * lab)
{
		fprintf(codefile, "%s %s\n", op, lab);
}


void emitCommand(char * c)
{
	fprintf(codefile, "%s\n", c);
}

void set_char(char * op, int dst, int lab)
{
	fprintf(codefile, "%s %s, str%d\n", op, regFile[dst], lab);
}



int createBLab(void)
{
	return BLab++;
}

void useBLab(int flag)
{
	fprintf(codefile, "BLab%d:\n", flag);
}

int createJLab(void)
{
	return JLab++;
}

void useJLab(int flag)
{
	fprintf(codefile, "JLab%d:\n", flag);
}



void useJalLab(char* name)
{
	fprintf(codefile, "fun_%s:\n", name);
}

void print(char * p[])
{
	int i;
	for (i = 0; i < 100; i++)
	{
		if (p[i] != NULL)
		fprintf(codefile, "str%d:\n\t.ascii\t\"%s\"\n", i, p[i]);
	}
}

void println()
{
	fprintf(codefile, "la $a0,compiler_enter\njal printf\n");
}



int check_float(char *c)
{
	return !strcmp(c, "real");
}