#ifndef _SYMTAB_H_
#define _SYMTAB_H_

#include<stdio.h>

#define MAXFUNCAMT 100

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert( char * name, char *varType, int lineno, int loc );

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( char * name );
char *st_getType(char *name);

void st_setCurFuncNum(int funcNum);

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing);

#endif
