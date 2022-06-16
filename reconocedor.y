/* Este archivo contiene un reconocedor de expresiones aritm�ticas. Durante el
 * reconocimiento se construye un �rbol sint�ctico reducIDo de las expresiones
 * aritm�ticas que despu�s se interpreta al hacer un recorrIDo del mismo.

   Para compilar y ejecutar:
   flex reconocedor.lex
   bison -d reconocedor.y
   gcc lex.yy.c reconocedor.tab.c -lfl
   ./a.out

   Autor: Alberto v Ros */

%{
#include<stdlib.h>
#include<stdio.h>
#include <assert.h>

#include <string.h>


#define NOTHING -99999

double doubleVal;

int numParam = 0;

 enum SyntaxTreeNodeType {
  PROGRAM,
  PYC,
  PYC_S,
  STMT,
  ASSIGN_STMT,
  IF_STMT,
  ITER_STMT,
  CMP_STMT,
  SET,
  TO,
  EXPR,
  TERM,
  FACTOR,
  READ,
  PRINT,
  REPEAT,
  IF,
  EXPRESION,
  IFELSE,
  WHILE,
  FOR,
  STEP,
  DO,
  STMT_LST,
  PLUS,
  MINUS,
  STAR,
  FORWARD_SLASH,
  LT,
  GT,
  EQ,
  LEQ,
  GEQ,
  INTEGER_NUMBER_VALUE,
  FLOATING_POINT_NUMBER_VALUE,
  ID_VALUE,
  FUNCTION_VALUE,
  PARAMETER_VALUE,
  EXPR_LST,
  RETURN
};

char* SyntaxTreeNodeTypeName[] = {
  "PROGRAM",
  "PYC",
  "PYC_S",
  "STMT",
  "ASSIGN_STMT",
  "IF_STMT",
  "ITER_STMT",
  "CMP_STMT",
  "SET",
  "TO",
  "EXPR",
  "TERM",
  "FACTOR",
  "READ",
  "PRINT",
  "REPEAT",
  "IF",
  "EXPRESION",
  "IFELSE",
  "WHILE",
  "FOR",
  "STEP",
  "DO",
  "STMT_LST",
  "PLUS",
  "MINUS",
  "STAR",
  "FORWARD_SLASH",
  "LT",
  "GT",
  "EQ",
  "LEQ",
  "GEQ",
  "INTEGER_NUMBER_VALUE",
  "FLOATING_POINT_NUMBER_VALUE",
  "ID_VALUE",
  "FUNCTION_VALUE",
  "PARAMETER_VALUE",
  "EXPR_LST",
  "RETURN"
};


struct nodoTS {
    char * nombre;
    int type;
    union {
      int intVal;
      double doubleVal;
    }value;
    struct nodoTS * next;
};

// Definimos una estructura para hacer el árbol sintáctico reducIDo.
typedef struct asr ASR;
struct asr {
  int type;
  int parentNodeType;
  ASR *arrPtr[4];
  union {
    int intVal; /* Integer value */
    double doubleVal; /* Floating-point value */
    char *idName; /* Identifier name */
  } value;
  ASR *next;
};

struct nodoTSF {
  char * nombre;
  int returnType;
  int numParams;
  struct nodoTS * tsl;
  ASR * cuerpo;
  struct nodoTSF * next;
};




extern int yylex();
int yyerror(char const * s);
ASR * nuevoNodo(int, double, char*, int, int, ASR*,ASR*,ASR*,ASR*,ASR*);
extern char * yytext;
extern FILE *yyin;
//void findID(char * id);
struct nodoTS * insertID(char* id, int tipo);
void insertFunc(char*, int, int, struct nodoTS*, ASR*);
void insertIDFunc(struct nodoTS**, char*, int);
void printList();
void printListTsl(struct nodoTS * ptr, char * nombre);
void printListTsf();
void printTree(ASR * raiz);
void preTreePrinting(ASR * node, char * id);
struct nodoTSF * retrieveFromFunSymbolTable(char * id);
void interpreta(ASR * raiz);




struct nodoTS * head;
struct nodoTS * tslHead;
struct nodoTSF * functionSymbolTableHead;

%}

%union {
   struct nodoTS * val;
   char * nombre;
   int entero;  // Para las constantes num�ricas
   double doubleVal;
   union valor *f;
   struct asr * arbol;  // Para los apuntadores a �rbol sint�ctico
}

/* Los elementos terminales de la gram�tica. La declaraci�n de abajo se
   convierte en definici�n de constantes en el archivo calculadora.tab.h
   que hay que incluir en el archivo de flex. */



%token SUMA RESTA MULT DIV PARI PARF BGN END COLON SEMI ASSIGN EQUAL LESSER GREATER LEQUAL GEQUAL LARROW RES_FOR RES_DO RES_WHILE RES_IF THEN ELSE INT FLOAT RES_REPEAT UNTIL RES_STEP RES_PROGRAM VAR RES_READ RES_PRINT INTEGER FLOATING RES_FUN COMMA RES_RETURN
%token <nombre> ID
%type <entero> type
%type <arbol> prog stmt opt_stmts stmt_lst expr term factor expression expr_lst opt_exprs fun_decl SUMA RESTA MULT DIV PARI PARF BGN END COLON SEMI ASSIGN EQUAL LESSER GREATER LEQUAL GEQUAL LARROW RES_FOR RES_DO RES_WHILE RES_IF THEN ELSE INT FLOAT RES_REPEAT UNTIL RES_STEP RES_PROGRAM VAR RES_READ RES_PRINT
%type <val> decl oparams
%start prog

%precedence THEN
%precedence ELSE

%%

prog : RES_PROGRAM ID opt_decls opt_fun_decls BGN opt_stmts END  {
						   ASR *nodoRoot;
						   nodoRoot = nuevoNodo(NOTHING, NOTHING, NULL, PROGRAM, NOTHING, $6, NULL, NULL, NULL, NULL);
						   printf("\n programa valido \n\n");
						   printf("########## TABLA DE SIMBOLOS DE FUNCION main ############\n\n");
						   printList();
						    printf("########## ARBOL SINTACTICO REDUCIDO ############\n\n");
						   preTreePrinting(nodoRoot, "main");
                //printf("########## TABLA DE SIMBOLOS DE FUNCIONES ############\n\n");
                //printListTsl();
                printf("########## TABLA DE FUNCIONES ############\n\n");
                printListTsf();
                printf("########## START OF PROGRAM OUTPUT ############\n\n");
                interpreta(nodoRoot);
                printf("########## END OF PROGRAM OUTPUT ############\n\n");
						   exit(0);
						 }
;

opt_decls : decl_lst
	  | %empty

;

decl_lst : decl SEMI decl_lst
         | decl
;

decl : VAR ID COLON type  {insertID($2, $4);}
;

type : INTEGER  {$$ = INTEGER_NUMBER_VALUE;}
     | FLOATING {$$ = FLOATING_POINT_NUMBER_VALUE;}
;

// REGLAS DE LAS FUNCIONES

opt_fun_decls : fun_decls
              | %empty
;

fun_decls : fun_decls fun_decl
          | fun_decl
;
fun_decl : RES_FUN ID PARI oparams PARF COLON type opt_decls_for_function BGN opt_stmts END
                                                                                            {
                                                                                              insertFunc($2, $7, numParam, tslHead, $10);
                                                                                              numParam = 0;
                                                                                              tslHead = NULL;
                                                                                            }
        | RES_FUN ID PARI oparams PARF COLON type SEMI {
                                                        insertFunc($2, $7, numParam, tslHead, NULL);
                                                        numParam = 0;
                                                        }
;
oparams : params
        | %empty
;
params : param COMMA params {numParam++;}
       | param {numParam++;}
;

param : ID COLON type {insertIDFunc(&tslHead, $1,$3);}
;


opt_decls_for_function : decls_for_function
                       | %empty
;

decls_for_function : dec_for_function SEMI decls_for_function
                   | dec_for_function
;

dec_for_function : VAR ID COLON type {insertIDFunc(&tslHead, $2, $4);}
;



stmt : ID LARROW expr {

                          ASR *nodoID;
                          nodoID = nuevoNodo(NOTHING, NOTHING, (char *)$1, ID_VALUE, SET, NULL, NULL, NULL, NULL, NULL);
                          $$ = nuevoNodo(NOTHING, NOTHING, NULL, SET, STMT, nodoID, $3, NULL, NULL, NULL);

                       }
;
     | RES_IF expression THEN stmt {
     				                         $$ = nuevoNodo(NOTHING, NOTHING, NULL, IF, IF_STMT, $2, $4, NULL, NULL, NULL);
     				                       }
;
     | RES_FOR ID LARROW expr UNTIL expr RES_STEP expr RES_DO stmt {
     							   ASR *nodoID = nuevoNodo(NOTHING, NOTHING, (char *)$2, ID_VALUE, FOR, NULL, NULL, NULL, NULL, NULL);
     							   ASR *nodoSet = nuevoNodo(NOTHING, NOTHING, NULL, SET, FOR, nodoID, $4, NULL, NULL, NULL);
     							   ASR *nodoLt = nuevoNodo(NOTHING, NOTHING, NULL, LEQ, EXPRESION, nodoID, $6, NULL, NULL, NULL);
     							   ASR *nodoStep = nuevoNodo(NOTHING, NOTHING, NULL, PLUS, EXPR, nodoID, $8, NULL, NULL, NULL);
     							   ASR *nodoSet2 = nuevoNodo(NOTHING, NOTHING, NULL, SET, FOR, nodoID, nodoStep, NULL, NULL, NULL);
     							   $$ = nuevoNodo(NOTHING, NOTHING, NULL, FOR, ITER_STMT, nodoSet, nodoLt, nodoSet2, $10, NULL);
     							  }
;
     | RES_READ ID {
     		ASR *nodoID;
     		nodoID = nuevoNodo(NOTHING,NOTHING, (char *)$2, ID_VALUE,READ, NULL, NULL, NULL, NULL, NULL);
     		$$ = nuevoNodo(NOTHING, NOTHING, NULL, READ, STMT, nodoID, NULL, NULL, NULL, NULL);
     		}
;
     | RES_IF expression THEN stmt ELSE stmt {
     					                                  $$ = nuevoNodo(NOTHING,NOTHING,NULL, IFELSE , IF_STMT , $2,$4,$6, NULL, NULL);
     					                               }
;
     | RES_WHILE PARI expression PARF stmt
     					{
     					 $$ = nuevoNodo(NOTHING,NOTHING,NULL,WHILE, ITER_STMT, $3, $5, NULL, NULL, NULL);
     					 }
;
     | RES_REPEAT stmt UNTIL PARI expression PARF {
     						 $$ = nuevoNodo(NOTHING, NOTHING, NULL, REPEAT, ITER_STMT, $2, $5, NULL, NULL, NULL);
     						}
;
     | RES_PRINT expr {
     		   $$ = nuevoNodo(NOTHING, NOTHING, NULL, PRINT, STMT, $2, NULL, NULL, NULL, NULL);
     		   }
;
     | RES_RETURN expr {
           $$ = nuevoNodo(NOTHING, NOTHING, NULL, RETURN, STMT, $2, NULL, NULL, NULL, NULL);
     }
     | BGN opt_stmts END {$$ = $2;}
;

opt_stmts : stmt_lst {$$ = $1;}
          | %empty {$$ = NULL;}
;
stmt_lst : stmt SEMI stmt_lst {$$ = nuevoNodo(NOTHING,NOTHING,NULL,PYC, STMT_LST, $1,$3, NULL, NULL, NULL);}
         | stmt {$$ = nuevoNodo(NOTHING,NOTHING,NULL,PYC_S, STMT_LST, $1, NULL, NULL, NULL, NULL);}
;

expr : expr SUMA term  {$$ = nuevoNodo(NOTHING, NOTHING, NULL, PLUS, EXPR, $1, $3, NULL, NULL, NULL);}
     | expr RESTA term  {$$ = nuevoNodo(NOTHING, NOTHING, NULL, MINUS, EXPR, $1, $3, NULL, NULL, NULL);}
     | term {$$ = $1;}
;

term : term MULT factor {$$ = nuevoNodo(NOTHING, NOTHING, NULL, STAR, EXPR, $1, $3, NULL, NULL, NULL);}
     | term DIV factor {$$ = nuevoNodo(NOTHING, NOTHING, NULL, FORWARD_SLASH, EXPR, $1, $3, NULL, NULL, NULL);}
     | factor {$$ = $1;}
;

// modificada para diferenciar entre enteros y flotantes
factor : PARI expr PARF {$$ = $2;}
       | ID   {$$ = nuevoNodo(NOTHING, NOTHING, (char*)$1, ID_VALUE, FACTOR, NULL, NULL, NULL, NULL, NULL);}
       | INT  {$$ = nuevoNodo((int)$1, NOTHING, NULL, INTEGER_NUMBER_VALUE, TERM, NULL, NULL, NULL, NULL, NULL);}
       | FLOAT {$$ = nuevoNodo(NOTHING, doubleVal, NULL, FLOATING_POINT_NUMBER_VALUE, TERM, NULL, NULL, NULL, NULL, NULL);}
       | ID PARI opt_exprs PARF {$$ = nuevoNodo(NOTHING, NOTHING, (char *)$1, FUNCTION_VALUE, TERM, $3, NULL, NULL, NULL, NULL);}
;
opt_exprs : expr_lst
          {
            $$ = $1;
          }
          | %empty
          {
            $$ = NULL;
          }
;

expr_lst : expr_lst COMMA expr
          {
            $$ = nuevoNodo(NOTHING, NOTHING, NULL, PARAMETER_VALUE, EXPR_LST, $3, $1, NULL, NULL, NULL);
          }
          | expr
          {
            $$ = nuevoNodo(NOTHING, NOTHING, NULL, PARAMETER_VALUE, EXPR_LST, $1, NULL, NULL, NULL, NULL);
          }

expression : expr LESSER expr {$$ = nuevoNodo(NOTHING, NOTHING, NULL, LT, EXPRESION, $1, $3, NULL, NULL, NULL);}
           | expr GREATER expr {$$ = nuevoNodo(NOTHING, NOTHING, NULL, GT, EXPRESION, $1, $3, NULL, NULL, NULL);}
           | expr EQUAL expr {$$ = nuevoNodo(NOTHING, NOTHING, NULL, EQ, EXPRESION, $1, $3, NULL, NULL, NULL);}
           | expr LEQUAL expr {$$ = nuevoNodo(NOTHING, NOTHING, NULL, LEQ, EXPRESION, $1, $3, NULL, NULL, NULL);}
           | expr GEQUAL expr {$$ = nuevoNodo(NOTHING, NOTHING, NULL, GEQ, EXPRESION, $1, $3, NULL, NULL, NULL);}
;



%%



int yyerror(char const * s) {
  fprintf(stderr, "%s,%s\n", s,yytext);
}

void main(int argc, char * argv[]) {

  if(argc < 2) {
   printf("Error, falta nombre de archivo\n");
   exit(1);
  }

  yyin = fopen(argv[1], "r");

  if(yyin == NULL) {
    printf("Error, archivo no existe\n");
    exit(1);
  }

  yyparse();
}

/* La funci�n nuevoNodo crea un nuevo nodo para un �rbol sint�ctico reducIDo.
   Los par�metros son el tipo de nodo (operaci�n u operando), el valor que
   representa qu� operando se est� usando o el valor del n�mero en cuesti�n y
   los apuntadores a los sub�rboles correspondientes.
*/




void printList() {
	 struct nodoTS * ptr = head;

	printf("\n[ ");

	while(ptr != NULL) {
	 if(ptr->type == INTEGER_NUMBER_VALUE) printf("(%s, int, %d) ",ptr->nombre, ptr->value.intVal);
	 else if(ptr->type == FLOATING_POINT_NUMBER_VALUE) printf("(%s, float, %.2f) ", ptr->nombre, ptr->value.doubleVal);
	 ptr = ptr->next;
	}

	printf(" ] \n\n");

}

void printListTsl(struct nodoTS * ptr, char * nombre) {
  struct nodoTS * pointer = ptr;
  printf("#################### TABLA DE SIMBOLOS DE LA FUNCION %s #########################\n\n", nombre);
  printf("\n[ ");

	while(ptr != NULL) {
	 if(ptr->type == INTEGER_NUMBER_VALUE) printf("(%s, int, %d) ",ptr->nombre, ptr->value.intVal);
	 else if(ptr->type == FLOATING_POINT_NUMBER_VALUE) printf("(%s, float, %.2f) ", ptr->nombre, ptr->value.doubleVal);
	 ptr = ptr->next;
	}

	printf(" ] \n\n");
  printf("#################### FINAL DE LA TABLA DE SIMBOLO DE LA FUNCION %s  #########################\n\n", nombre);
}

void printListTsf() {

  struct nodoTSF * ptr = functionSymbolTableHead;



	while(ptr != NULL) {
    printf("\n[ ");
	 if(ptr->returnType == INTEGER_NUMBER_VALUE) printf("(%s, # params: %d, return type: int) ",ptr->nombre, ptr->numParams);
	 else if(ptr->returnType == FLOATING_POINT_NUMBER_VALUE) printf("(%s, # params: %d, return type: float) ", ptr->nombre, ptr->numParams);
   printf(" ] \n\n");
   printListTsl(ptr->tsl, ptr->nombre);
   preTreePrinting(ptr->cuerpo, ptr->nombre);
	 ptr = ptr->next;
	}


}

ASR * nuevoNodo(int iVal, double dVal, char* idName, int type, int parentNodeType, ASR * ptr1, ASR * ptr2, ASR * ptr3, ASR * ptr4, ASR * nextNode) {

   ASR * newNodePtr = (ASR *) malloc(sizeof(ASR));
   newNodePtr->type = type;
   newNodePtr->parentNodeType = parentNodeType;

   newNodePtr->arrPtr[0] = ptr1;
   newNodePtr->arrPtr[1] = ptr2;
   newNodePtr->arrPtr[2] = ptr3;
   newNodePtr->arrPtr[3] = ptr4;

   newNodePtr->next = nextNode;

   //printf("%p\n",ptr1);
   // Assign the values. They could be equal to NOTHING.
   if(type == INTEGER_NUMBER_VALUE){

     newNodePtr->value.intVal = iVal;
   }
   else if(type == FLOATING_POINT_NUMBER_VALUE){

     newNodePtr->value.doubleVal = dVal;
   }
   else if(type == ID_VALUE){

     // Malloc for the identifier's name
     newNodePtr->value.idName = (char *) malloc(strlen(idName) + 1);
     strcpy (newNodePtr->value.idName, idName);
   }
   else if(type == FUNCTION_VALUE){

     newNodePtr->value.idName = (char *) malloc(strlen(idName) + 1);
     strcpy (newNodePtr->value.idName, idName);
   }
   return newNodePtr;
}

struct nodoTS * insertID(char * id, int tipo) {

	struct nodoTS * link = (struct nodoTS *) malloc(sizeof(struct nodoTS));

	link->type = tipo;
	link->value.intVal = 0;
	link->nombre = id;
	link->next = head;
	head = link;

}

void insertFunc(char * id, int returnType, int numParams, struct nodoTS * tsl, ASR * cuerpo){
  struct nodoTSF * newFunc = (struct nodoTSF *) malloc(sizeof(struct nodoTSF));

  newFunc->nombre = id;
  newFunc->returnType = returnType;
  newFunc->numParams = numParams;
  newFunc->tsl = tsl;
  newFunc->cuerpo = cuerpo;

  newFunc->next = functionSymbolTableHead;
  functionSymbolTableHead = newFunc;

}

void insertIDFunc(struct nodoTS** tslHead, char * id, int tipo){
  struct nodoTS * newNode = (struct nodoTS *) malloc(sizeof(struct nodoTS));

  newNode->type = tipo;
  newNode->value.intVal = 0;
  newNode->nombre = id;
  newNode->next = (struct nodoTS*)(*tslHead);
  *tslHead = newNode;

}

struct nodoTSF* retrieveFromFunSymbolTable(char * nombre){
  struct nodoTSF *currPtr = functionSymbolTableHead;

  while(currPtr != NULL){
    assert(currPtr->nombre);

    if(strcmp(currPtr->nombre, nombre) == 0)
      return currPtr;

      currPtr = currPtr->next;
  }

  return NULL;
}

struct nodoTS* auxRetrieveFromSymbolTable(char const *symbolName, struct nodoTS* symbolTableHead){

  struct nodoTS *currPtr = symbolTableHead;

  // Traverse the linked list and compare the name of the current symbol
  // with the name of the symbol that you're looking for.
  while(currPtr != NULL){

    assert(currPtr->nombre);

    if(strcmp(currPtr->nombre, symbolName) == 0)
      return currPtr;

    currPtr = currPtr->next;
  }

  // If the symbol was not found in the function's symbol table, it must be looked for
  // in the symbol table of the main function.
  // handleError(ERROR_CODE_SYMBOL_NOT_FOUND, ERROR_MESSAGE_SYMBOL_NOT_FOUND);
  return NULL;
}

struct nodoTS* retrieveFromSymbolTable(char const *symbolName){

  struct nodoTS *currPtr = NULL;



  // If a function is being executed but the symbol was not found in the function's
  // symbol table or if no function is being executed, then look for the symbol in
  // the main function's symbol table.
  if(!currPtr)
    currPtr = auxRetrieveFromSymbolTable(symbolName, head);



  return currPtr;
}

void setIntValueToSymbol(char const *symbolName, int newIntegerValue){

  struct nodoTS *symbolPtr = retrieveFromSymbolTable(symbolName);

  if(symbolPtr != NULL){

    // Check that the symbol does in fact store an integer
    if(symbolPtr->type == INTEGER_NUMBER_VALUE){

      symbolPtr->value.intVal = newIntegerValue;
    }
    else{

      // Error out and exit!
      printf("error");
    }
  }
  else{

    // Error out and exit!
    printf("error");
  }
}

void setDoubleValueToSymbol(char const *symbolName, double newDoubleValue){

  struct nodoTS *symbolPtr = retrieveFromSymbolTable(symbolName);

  if(symbolPtr != NULL){

    // Check that the symbol does in fact store a double
    if(symbolPtr->type == FLOATING_POINT_NUMBER_VALUE){

      symbolPtr->value.doubleVal = newDoubleValue;
    }
    else{

      // Error out and exit!
      printf("error");
    }
  }
}




int computeSubTreeNodeTypeCount(int nodeType, ASR * node){

  if(node == NULL)
    return 0;

  int count = 0;

  // In case it is a constant
  if(node->type == nodeType){

    count++;
  }

  // In case it is an ID
  else if(node->type == ID_VALUE){

    struct nodoTS * currIdNode = retrieveFromSymbolTable(node->value.idName);

    if(currIdNode->type == nodeType)
      count++;
  }

  int i = 0;
  for(i = 0; i < 4; i++){

    count += computeSubTreeNodeTypeCount(nodeType, node->arrPtr[i]);
  }

  return count;
}

int exprIsTypeConsistent(ASR * exprNode){

  // Count the number of subtree nodes of both data type
  // If the expression is type-consistent, then one of those counts
  // will be zero
  int intSubTreeNodeCount = computeSubTreeNodeTypeCount(INTEGER_NUMBER_VALUE, exprNode);
  int doubleSubTreeNodeCount = computeSubTreeNodeTypeCount(FLOATING_POINT_NUMBER_VALUE, exprNode);

  // printTree(exprNode);
  // printf("intSubTreeNodeCount: %d; doubleSubTreeNodeCount: %d\n", intSubTreeNodeCount, doubleSubTreeNodeCount);

  if(intSubTreeNodeCount > 0 && doubleSubTreeNodeCount == 0)
    return INTEGER_NUMBER_VALUE;

  else if(intSubTreeNodeCount == 0 && doubleSubTreeNodeCount > 0)
    return FLOATING_POINT_NUMBER_VALUE;

  // If the control gets here, there is a mistake: types are inconsistent
  // Error out and exit!
  //handleError(ERROR_CODE_DATA_TYPE_MISMATCH, ERROR_MESSAGE_DATA_TYPE_MISMATCH);

  return 0;
}

int isIntegerExpr(ASR * exprNode){

  return exprIsTypeConsistent(exprNode) == INTEGER_NUMBER_VALUE;
}

int isFloatingPointExpr(ASR * exprNode){

  return exprIsTypeConsistent(exprNode) == FLOATING_POINT_NUMBER_VALUE;
}



int func_exprInt(ASR * exprIntNode){

  // If we enter an EXPR node, we must at least one term.
  assert(exprIntNode != NULL);

  if(exprIntNode->type == PLUS){

    return func_exprInt(exprIntNode->arrPtr[0])
      + func_exprInt(exprIntNode->arrPtr[1]);
  }
  else if(exprIntNode->type == MINUS){

    return func_exprInt(exprIntNode->arrPtr[0])
      - func_exprInt(exprIntNode->arrPtr[1]);
  }
  else if(exprIntNode->type == STAR){

    return func_exprInt(exprIntNode->arrPtr[0])
      * func_exprInt(exprIntNode->arrPtr[1]);
  }
  else if(exprIntNode->type == FORWARD_SLASH){

    return func_exprInt(exprIntNode->arrPtr[0])
      / func_exprInt(exprIntNode->arrPtr[1]);
  }

  assert(exprIntNode->type == INTEGER_NUMBER_VALUE
    || exprIntNode->type == ID_VALUE
    || exprIntNode->type == FUNCTION_VALUE);

  int valToReturn = 0;

  if(exprIntNode->type == INTEGER_NUMBER_VALUE){

    valToReturn = exprIntNode->value.intVal;
  }
  else if(exprIntNode->type == ID_VALUE){

    struct nodoTS * currNode = retrieveFromSymbolTable(exprIntNode->value.idName);
    assert(currNode->type == INTEGER_NUMBER_VALUE);
    //printSymbolTableNode(currNode);
    valToReturn = currNode->value.intVal;
  }
  /*else if(exprIntNode->type == FUNCTION_VALUE){

    (exprIntNode);
    // As we know that this is a function, then we know that this symbol must exist in the symbol table
    // of the main function, so directly call the auxiliary method that looks in that specific symbol table.
    struct SymbolTableNode* currFunc = auxRetrieveFromSymbolTable(exprIntNode->value.idName, mainFunctionSymbolTableHead);
    assert(currFunc->returnType == INTEGER_NUMBER_VALUE);
    // valToReturn = currFunc->value.intVal;
    valToReturn = ptrFunctionCallStackTop->value.intVal;
    popFunctionCallToStack();
  }*/

  return valToReturn;
}

double func_exprDouble(ASR * exprDoubleNode){
  // If we enter an EXPR node, we must at least one term.
  assert(exprDoubleNode != NULL);

  if(exprDoubleNode->type == PLUS){

    return func_exprDouble(exprDoubleNode->arrPtr[0])
      + func_exprDouble(exprDoubleNode->arrPtr[1]);
  }
  else if(exprDoubleNode->type == MINUS){

    return func_exprDouble(exprDoubleNode->arrPtr[0])
      - func_exprDouble(exprDoubleNode->arrPtr[1]);
  }
  else if(exprDoubleNode->type == STAR){

    return func_exprDouble(exprDoubleNode->arrPtr[0])
      * func_exprDouble(exprDoubleNode->arrPtr[1]);
  }
  else if(exprDoubleNode->type == FORWARD_SLASH){

    return func_exprDouble(exprDoubleNode->arrPtr[0])
      / func_exprDouble(exprDoubleNode->arrPtr[1]);
  }

  assert(exprDoubleNode->type == ID_VALUE
    || exprDoubleNode-> type == FLOATING_POINT_NUMBER_VALUE
    || exprDoubleNode-> type == FUNCTION_VALUE);

  // handleError(ERROR_CODE_DATA_TYPE_MISMATCH, ERROR_MESSAGE_DATA_TYPE_MISMATCH);

  double valToReturn = 0;

  if(exprDoubleNode->type == FLOATING_POINT_NUMBER_VALUE){
    valToReturn = exprDoubleNode->value.doubleVal;
  }
  else if(exprDoubleNode->type == ID_VALUE){

    struct nodoTS * currNode = retrieveFromSymbolTable(exprDoubleNode->value.idName);
    assert(currNode->type == FLOATING_POINT_NUMBER_VALUE);
    //printSymbolTableNode(currNode);
    valToReturn = currNode->value.doubleVal;
  }
  /*else if(exprDoubleNode-> type == FUNCTION_VALUE){

    func_func(exprDoubleNode);
    // As we know that this is a function, then we know that this symbol must exist in the symbol table
    // of the main function, so directly call the auxiliary method that looks in that specific symbol table.
    struct SymbolTableNode* currFunc = auxRetrieveFromSymbolTable(exprDoubleNode->value.idName, mainFunctionSymbolTableHead);
    assert(currFunc->returnType == FLOATING_POINT_NUMBER_VALUE);
    // valToReturn = currFunc->value.doubleVal;
    valToReturn = ptrFunctionCallStackTop->value.doubleVal;
    popFunctionCallToStack();
  }*/

  return valToReturn;
}


int func_expression(ASR* nodeExpr){

  // If we enter an EXPRESION node, we must have two 'expr' terms
  assert(nodeExpr->arrPtr[0] != NULL);
  assert(nodeExpr->arrPtr[1] != NULL);

  if(isIntegerExpr(nodeExpr->arrPtr[0])){

    // Assert that the second 'expr' term also contains an integer expression
    assert(isIntegerExpr(nodeExpr->arrPtr[1]));
    //printNodeType(nodeExpr->type, "hola");
    int intExpresionLeftSide = func_exprInt(nodeExpr->arrPtr[0]);
    int intExpresionRightSide = func_exprInt(nodeExpr->arrPtr[1]);

    switch(nodeExpr->type){

      case LT:
        return intExpresionLeftSide < intExpresionRightSide;

      case GT:
        return intExpresionLeftSide > intExpresionRightSide;

      case EQ:
        return intExpresionLeftSide == intExpresionRightSide;

      case LEQ:
        return intExpresionLeftSide <= intExpresionRightSide;

      case GEQ:
        return intExpresionLeftSide >= intExpresionRightSide;
    }
  }
  else{

    assert(isFloatingPointExpr(nodeExpr->arrPtr[0]));

    // Assert that the second 'expr' term also contains an floating-point expression
    assert(isFloatingPointExpr(nodeExpr->arrPtr[1]));

    double doubleExpresionLeftSide = func_exprDouble(nodeExpr->arrPtr[0]);
    int doubleExpresionRightSide = func_exprDouble(nodeExpr->arrPtr[1]);

    switch(nodeExpr->type){

      case LT:
        return doubleExpresionLeftSide < doubleExpresionRightSide;

      case GT:
        return doubleExpresionLeftSide > doubleExpresionRightSide;

      case EQ:
        return doubleExpresionLeftSide == doubleExpresionRightSide;

      case LEQ:
        return doubleExpresionLeftSide <= doubleExpresionRightSide;

      case GEQ:
        return doubleExpresionLeftSide >= doubleExpresionRightSide;
    }
  }

  // Control should never reach this part of the function.
  assert(NULL);
  return -1;
}

int readInt(){

  int intVal = -1;
  printf("escribe tu entero: ");
  int scanfReturnValue = scanf("%d", &intVal);
  assert(scanfReturnValue > 0);
  return intVal;
}


double readDouble(){

  double doubleVal = -1.0;
  printf("Escribe tu numero de punto flotante: ");
  int scanfReturnValue = scanf("%lf", &doubleVal);

  assert(scanfReturnValue > 0);
  return doubleVal;
}


/* La funci�n recorre es el int�rprtete en este caso. Simplemente recorre
   el �rbol en postorden para obtener los valores correspondientes.
*/

void printNodeType(int type, char* label){

  // If our names array contains an entry for this type
  if(type >= 0 && type < sizeof(SyntaxTreeNodeTypeName)){

    printf("%s: %s\n", label, SyntaxTreeNodeTypeName[type]);
  }
  else{

    printf("%s: %d\n", label, type);
  }
}

void preTreePrinting(ASR* node, char* nombre){
  printf("###################### INICIO ARBOL SINTACTICO REDUCIDO DE LA FUNCION %s #####################\n\n", nombre);
  printTree(node);
  printf("###################### FIN ARBOL SINTACTICO REDUCIDO DE LA FUNCION %s #####################\n\n", nombre);

}

void printTree(ASR * node){

  if(node == NULL)
    return;

  printNodeType(node->type, "type");
//printf("address = %p\n", node);
  printNodeType(node->parentNodeType, "parentNodeType");

  if(node->type == INTEGER_NUMBER_VALUE){

    printf("Node value = %d\n", node->value.intVal);
  }

  else if(node->type == ID_VALUE){

    printf("Node value = %s\n", node->value.idName);
  }

  else if(node->type == FLOATING_POINT_NUMBER_VALUE){

    printf("Node value = %f\n", node->value.doubleVal);
  }
  else if(node->type == FUNCTION_VALUE){
    printf("Node value = %s\n", node->value.idName);
  }

  // Print the addresses of the current node's children
  int i = 0;
/*
  for(i = 0; i < 4; i++)
    printf("ptr #%d: %p\n", i + 1, node->arrPtr[i]);
*/

  printf("\n");

  // Now call the printing of the current node's children
  for(i = 0; i < 4; i++)
    printTree(node->arrPtr[i]);
}

int traverseTree(ASR * node, int count){
  if(node->arrPtr[0] == NULL){
    return count;
  }
}


void func_func(ASR * nodeFunc){
  struct nodoTSF * currFunc = retrieveFromFunSymbolTable(nodeFunc->value.idName);
  int count = 0;
  assert(currFunc != NULL);

  printf("# params: ", currFunc->numParams);

  traverseTree(nodeFunc, 0);

}

void func_read(ASR * nodeRead){
  assert(nodeRead->arrPtr[0] != NULL);

  struct nodoTS * currNode = retrieveFromSymbolTable(nodeRead->arrPtr[0]->value.idName);

  int valueToSet;
  double doubleValueToSet;

  switch (currNode->type) {
    case INTEGER_NUMBER_VALUE:
    valueToSet = readInt();
    setIntValueToSymbol(currNode->nombre,valueToSet);
    assert(valueToSet == currNode->value.intVal);

    break;
    case FLOATING_POINT_NUMBER_VALUE:
    doubleValueToSet = readDouble();
    setDoubleValueToSymbol(currNode->nombre, doubleValueToSet);
    assert(doubleValueToSet == currNode->value.doubleVal);
    break;
  }

}

void func_print(ASR * printNode){
  assert(printNode->arrPtr[0] != NULL);

  if(printNode->arrPtr[0]->type == INTEGER_NUMBER_VALUE){

    printf("%d\n", printNode->arrPtr[0]->value.intVal);
  }
  else if(printNode->arrPtr[0]->type == FLOATING_POINT_NUMBER_VALUE){
    printf("%.2f\n", printNode->arrPtr[0]->value.doubleVal);
  } else if(printNode->arrPtr[0]->parentNodeType == EXPR
    || printNode->arrPtr[0]->parentNodeType == TERM
    || printNode->arrPtr[0]->parentNodeType == FACTOR){


    /*  if(printNode->arrPtr[0]->type == FUNCTION_VALUE){

      func_func(printNode->arrPtr[0]);
      // As we know that this is a function, then we know that this symbol must exist in the symbol table
      // of the main function, so directly call the auxiliary method that looks in that specific symbol table.
      struct SymbolTableNode* currFunc = auxRetrieveFromSymbolTable(printNode->arrPtr[0]->value.idName, mainFunctionSymbolTableHead);

      if(currFunc->returnType == INTEGER_NUMBER_VALUE){

        // printf("%d\n", currFunc->value.intVal);
        printf("%d\n", ptrFunctionCallStackTop->value.intVal);
      }
      else{

        assert(currFunc->returnType == FLOATING_POINT_NUMBER_VALUE);
        // printf("%lf\n", currFunc->value.doubleVal);
        printf("%lf\n", ptrFunctionCallStackTop->value.doubleVal);
      }

      popFunctionCallToStack();
    }
    else{*/
      if(isIntegerExpr(printNode->arrPtr[0])){

        printf("%d\n", func_exprInt(printNode->arrPtr[0]));
      }
      else{

        assert(isFloatingPointExpr(printNode->arrPtr[0]));
        printf("%lf\n", func_exprDouble(printNode->arrPtr[0]));
      }
    }
  }
//}

  void func_assign(ASR * setNode){

    // Each set statement must contain both the corresponding
    // id and the desired value
    assert(setNode->arrPtr[0] != NULL);
    assert(setNode->arrPtr[1] != NULL);

    // printf("symbol to retrieve: %s\n", setNode->arrPtr[0]->value.idName);
    struct nodoTS * currNode = retrieveFromSymbolTable(setNode->arrPtr[0]->value.idName);

    assert(currNode != NULL);

    int exprValueToSet;
    double exprDoubleValueToSet;

    switch(currNode->type){

      case INTEGER_NUMBER_VALUE:
        exprValueToSet = func_exprInt(setNode->arrPtr[1]);
        setIntValueToSymbol(currNode->nombre, exprValueToSet);
        //printSymbolTableNode(currNode);
        assert(exprValueToSet == currNode->value.intVal);
        break;

      case FLOATING_POINT_NUMBER_VALUE:
        exprDoubleValueToSet = func_exprDouble(setNode->arrPtr[1]);
        setDoubleValueToSymbol(currNode->nombre, exprDoubleValueToSet);
        //printSymbolTableNode(currNode);
        assert(exprDoubleValueToSet == currNode->value.doubleVal);
        break;

    }
  }




  void func_if(ASR * nodeIf){

    assert(nodeIf->arrPtr[0] != NULL);

    if(func_expression(nodeIf->arrPtr[0])){
      if(nodeIf->arrPtr[1] != NULL){
        interpreta(nodeIf->arrPtr[1]);
      }
    }
  }

  void func_ifElse(ASR * nodeIfElse){

    assert(nodeIfElse->arrPtr[0] != NULL);

    if(func_expression(nodeIfElse->arrPtr[0])){
      interpreta(nodeIfElse->arrPtr[1]);
    } else {
      interpreta(nodeIfElse->arrPtr[2]);
    }
  }

  void func_while(ASR * nodeWhile){
    assert(nodeWhile->arrPtr[0] != NULL);

    while(func_expression(nodeWhile->arrPtr[0])){
      interpreta(nodeWhile->arrPtr[1]);
    }
  }

  void func_for(ASR * nodeFor){

    assert(nodeFor->arrPtr[0] != NULL);
    assert(nodeFor->arrPtr[1] != NULL);
    assert(nodeFor->arrPtr[2] != NULL);

    func_assign(nodeFor->arrPtr[0]);

    while(func_expression(nodeFor->arrPtr[1])){
      interpreta(nodeFor->arrPtr[3]);
      func_assign(nodeFor->arrPtr[2]);
    }
  }
 //preguntarle al profe a que se refefiere con el REPEAT

  void func_repeat(ASR * nodeRepeat){
    //assert(nodeRepeat->arrPtr[0] != NULL);
    assert(nodeRepeat->arrPtr[1] != NULL);

    do {
      interpreta(nodeRepeat->arrPtr[0]);
    } while(func_expression(nodeRepeat->arrPtr[1]));
  }

 void interpreta(ASR * node){

   if(node == NULL)
   return;

   switch (node->type) {
     case PROGRAM:
     break;

     case PRINT:
     func_print(node);
     break;

     case READ:
     func_read(node);
     break;

     case SET:
     func_assign(node);
     break;

     case IF:
     func_if(node);
     break;

     case IFELSE:
     func_ifElse(node);
     break;

     case WHILE:
     func_while(node);
     break;

     case FOR:
     func_for(node);
     break;

     case REPEAT:
     func_repeat(node);
     break;
   }


   if(node->type != IF
    && node->type != IFELSE
    && node->type != WHILE
    && node->type != FOR){

    int i;
    for(i = 0; i < 4; i++)
      interpreta(node->arrPtr[i]);
    }
 }
