 /* Este archivo contiene un reconocedor de expresiones aritm�ticas. Durante el
 * reconocimiento se construye un �rbol sint�ctico reducIDo de las expresiones
 * aritm�ticas que despu�s se interpreta al hacer un recorrIDo del mismo.

   Para compilar y ejecutar:
   flex reconocedor.lex
   bison -d reconocedor.y
   gcc lex.yy.c reconocedor.tab.c -lfl
   ./a.out

   Autores:
   Miguel Ángel Herrera Islas - A01732934
   Andrés Guevara Mastretta - A01733186
 */

%{
     #include<stdlib.h>
     #include<stdio.h>
     #include <assert.h>
     #include <string.h>

     #define NOTHING -99999
     double doubleVal;
     int numParam = 0;
     int funcRunning = 0;
     char * currentFuncName;

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
         }
         value;
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
         }
         value;
         ASR *next;
     };

     struct nodoTSF {
         char * nombre;
         int returnType;
         int numParams;
         struct nodoTS * tsl;
         ASR * cuerpo;
         union {
             int intVal;
             double doubleVal;
         }
         value;
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
    int entero;
    double doubleVal;
    union valor *f;
    struct asr * arbol;
}




%token SUMA RESTA MULT DIV PARI PARF BGN END COLON SEMI ASSIGN EQUAL LESSER GREATER LEQUAL GEQUAL LARROW RES_FOR RES_DO RES_WHILE RES_IF THEN ELSE INT FLOAT RES_REPEAT UNTIL RES_STEP RES_PROGRAM VAR RES_READ RES_PRINT INTEGER FLOATING RES_FUN COMMA RES_RETURN RES_MINUS
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

factor : PARI expr PARF {$$ = $2;}
       | ID   {$$ = nuevoNodo(NOTHING, NOTHING, (char*)$1, ID_VALUE, FACTOR, NULL, NULL, NULL, NULL, NULL);}
       | INT  {$$ = nuevoNodo((int)$1, NOTHING, NULL, INTEGER_NUMBER_VALUE, TERM, NULL, NULL, NULL, NULL, NULL);}
       | RES_MINUS INT {$$ = nuevoNodo((int)$2*-1, NOTHING, NULL, INTEGER_NUMBER_VALUE, TERM, NULL, NULL, NULL, NULL, NULL);}
       | FLOAT {$$ = nuevoNodo(NOTHING, doubleVal, NULL, FLOATING_POINT_NUMBER_VALUE, TERM, NULL, NULL, NULL, NULL, NULL);}
       | RES_MINUS FLOAT  {$$ = nuevoNodo(NOTHING, doubleVal*-1.0, NULL, FLOATING_POINT_NUMBER_VALUE, TERM, NULL, NULL, NULL, NULL, NULL);}
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

    if(type == INTEGER_NUMBER_VALUE) {
        newNodePtr->value.intVal = iVal;
    }
    else if(type == FLOATING_POINT_NUMBER_VALUE) {

        newNodePtr->value.doubleVal = dVal;
    }
    else if(type == ID_VALUE) {
        newNodePtr->value.idName = (char *) malloc(strlen(idName) + 1);
        strcpy (newNodePtr->value.idName, idName);
    }
    else if(type == FUNCTION_VALUE) {
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

void insertFunc(char * id, int returnType, int numParams, struct nodoTS * tsl, ASR * cuerpo) {
    struct nodoTSF * newFunc = (struct nodoTSF *) malloc(sizeof(struct nodoTSF));

    newFunc->nombre = id;
    newFunc->returnType = returnType;
    newFunc->numParams = numParams;
    newFunc->tsl = tsl;
    newFunc->cuerpo = cuerpo;

    newFunc->next = functionSymbolTableHead;
    functionSymbolTableHead = newFunc;
}

void insertIDFunc(struct nodoTS** tslHead, char * id, int tipo) {
    struct nodoTS * newNode = (struct nodoTS *) malloc(sizeof(struct nodoTS));

    newNode->type = tipo;
    newNode->value.intVal = 0;
    newNode->nombre = id;
    newNode->next = (struct nodoTS*)(*tslHead);
    *tslHead = newNode;
}

struct nodoTSF* retrieveFromFunSymbolTable(char * nombre) {
    struct nodoTSF *currPtr = functionSymbolTableHead;

    while(currPtr != NULL) {
        assert(currPtr->nombre);
        if(strcmp(currPtr->nombre, nombre) == 0)
        return currPtr;
        currPtr = currPtr->next;
    }

    return NULL;
}

struct nodoTS* auxRetrieveFromSymbolTable(char const *symbolName, struct nodoTS* symbolTableHead) {
    struct nodoTS *currPtr = symbolTableHead;

    while(currPtr != NULL) {
        assert(currPtr->nombre);
        if(strcmp(currPtr->nombre, symbolName) == 0)
        return currPtr;
        currPtr = currPtr->next;
    }

    return NULL;
}

struct nodoTS * retrieveFromTsl(char * simboloActual, struct nodoTS* headTsl) {
    struct nodoTS* currPtr = headTsl;

    while(currPtr != NULL ) {
        assert(currPtr->nombre);
        if(strcmp(currPtr->nombre, simboloActual) == 0)
        return currPtr;
        currPtr = currPtr->next;
    }

    return NULL;
}

struct nodoTS* retrieveFromSymbolTable(char const *symbolName) {
    struct nodoTS *currPtr = NULL;

    if(!currPtr)
        currPtr = auxRetrieveFromSymbolTable(symbolName, head);

    return currPtr;
}

void setIntValueToSymbolFunc(char * symbolName, int newIntegerValue, char * name) {
    struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(name);
    struct nodoTS *symbolPtr = retrieveFromTsl(symbolName, currIdFunc->tsl);

    if(symbolPtr != NULL) {
        if(symbolPtr->type == INTEGER_NUMBER_VALUE) {
            symbolPtr->value.intVal = newIntegerValue;
        }
        else {
            printf("error");
        }
    }
    else {
        printf("error");
    }
}

void setIntValueToSymbol(char const *symbolName, int newIntegerValue) {
    struct nodoTS *symbolPtr = retrieveFromSymbolTable(symbolName);

    if(symbolPtr != NULL) {
        if(symbolPtr->type == INTEGER_NUMBER_VALUE) {

            symbolPtr->value.intVal = newIntegerValue;
        }
        else {
            printf("error");
        }
    }
    else {
        printf("error");
    }
}

void setDoubleValueToSymbolFunc(char * symbolName, double newDoubleValue, char * name) {
    struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(name);
    struct nodoTS *symbolPtr = retrieveFromTsl(symbolName, currIdFunc->tsl);

    if(symbolPtr != NULL) {
        if(symbolPtr->type == FLOATING_POINT_NUMBER_VALUE) {
            symbolPtr->value.doubleVal = newDoubleValue;
        }
        else {
            printf("error");
        }
    }
}

void setDoubleValueToSymbol(char const *symbolName, double newDoubleValue) {
    struct nodoTS *symbolPtr = retrieveFromSymbolTable(symbolName);

    if(symbolPtr != NULL){
        if(symbolPtr->type == FLOATING_POINT_NUMBER_VALUE) {
            symbolPtr->value.doubleVal = newDoubleValue;
        }
        else {
            printf("error");
        }
    }
}

int computeSubTreeNodeTypeCount(int nodeType, ASR * node) {
    if(node == NULL) return 0;

    int count = 0;
    if(node->type == nodeType) {
        count++;
    }

    // In case it is an ID
    else if(node->type == ID_VALUE) {
        struct nodoTS * currIdNode = retrieveFromSymbolTable(node->value.idName);
        if(currIdNode->type == nodeType) count++;
    }

    int i = 0;
    for(i = 0; i < 4; i++) {
        count += computeSubTreeNodeTypeCount(nodeType, node->arrPtr[i]);
    }

    return count;
}

int computeSubTreeNodeTypeCountFunc(int nodeType, ASR * node, char * name) {
    if(node == NULL) return 0;
    int count = 0;

    if(node->type == nodeType) {
        count++;
    }

    else if(node->type == ID_VALUE) {
        struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(name);
        struct nodoTS * currIdNode = retrieveFromTsl(node->value.idName, currIdFunc->tsl);
        if(currIdNode->type == nodeType) count++;
    }

    int i = 0;
    for(i = 0; i < 4; i++) {
        count += computeSubTreeNodeTypeCountFunc(nodeType, node->arrPtr[i], name);
    }

    return count;
}

int exprIsTypeConsistent(ASR * exprNode) {
    int intSubTreeNodeCount = computeSubTreeNodeTypeCount(INTEGER_NUMBER_VALUE, exprNode);
    int doubleSubTreeNodeCount = computeSubTreeNodeTypeCount(FLOATING_POINT_NUMBER_VALUE, exprNode);

    if(intSubTreeNodeCount > 0 && doubleSubTreeNodeCount == 0)
        return INTEGER_NUMBER_VALUE;

    else if(intSubTreeNodeCount == 0 && doubleSubTreeNodeCount > 0)
        return FLOATING_POINT_NUMBER_VALUE;

    return 0;
}

int exprIsTypeConsistentFunc(ASR * exprNode, char * name) {
    int intSubTreeNodeCount = computeSubTreeNodeTypeCountFunc(INTEGER_NUMBER_VALUE, exprNode, name);
    int doubleSubTreeNodeCount = computeSubTreeNodeTypeCountFunc(FLOATING_POINT_NUMBER_VALUE, exprNode, name);

    if(intSubTreeNodeCount > 0 && doubleSubTreeNodeCount == 0)
        return INTEGER_NUMBER_VALUE;

    else if(intSubTreeNodeCount == 0 && doubleSubTreeNodeCount > 0)
        return FLOATING_POINT_NUMBER_VALUE;

    return 0;
}

int isIntegerExprFunc(ASR * exprNode, char * name) {
    return exprIsTypeConsistentFunc(exprNode, name) == INTEGER_NUMBER_VALUE;
}

int isIntegerExpr(ASR * exprNode) {
    return exprIsTypeConsistent(exprNode) == INTEGER_NUMBER_VALUE;
}

int isFloatingPointExprFunc(ASR * exprNode, char * name) {
    return exprIsTypeConsistentFunc(exprNode, name) == FLOATING_POINT_NUMBER_VALUE;
}

int isFloatingPointExpr(ASR * exprNode) {
    return exprIsTypeConsistent(exprNode) == FLOATING_POINT_NUMBER_VALUE;
}


int func_exprIntFunc(ASR * exprIntNode, char * name) {
    assert(exprIntNode != NULL);

    if(exprIntNode->type == PLUS) {
        return func_exprIntFunc(exprIntNode->arrPtr[0], name)
        + func_exprIntFunc(exprIntNode->arrPtr[1], name);
    }
    else if(exprIntNode->type == MINUS) {
        return func_exprIntFunc(exprIntNode->arrPtr[0], name)
        - func_exprIntFunc(exprIntNode->arrPtr[1], name);
    }
    else if(exprIntNode->type == STAR) {
        return func_exprIntFunc(exprIntNode->arrPtr[0], name)
        * func_exprIntFunc(exprIntNode->arrPtr[1], name);
    }
    else if(exprIntNode->type == FORWARD_SLASH) {
        return func_exprIntFunc(exprIntNode->arrPtr[0], name)
        / func_exprIntFunc(exprIntNode->arrPtr[1], name);
    }

    assert(exprIntNode->type == INTEGER_NUMBER_VALUE
        || exprIntNode->type == ID_VALUE
        || exprIntNode->type == FUNCTION_VALUE);

    int valToReturn = 0;

    if(exprIntNode->type == INTEGER_NUMBER_VALUE) {
        valToReturn = exprIntNode->value.intVal;
    }
    else if(exprIntNode->type == ID_VALUE) {
        struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(name);
        struct nodoTS * currNode = retrieveFromTsl(exprIntNode->value.idName, currIdFunc->tsl);
        assert(currNode->type == INTEGER_NUMBER_VALUE);
        valToReturn = currNode->value.intVal;
    }

    return valToReturn;
}

int func_exprInt(ASR * exprIntNode) {
    assert(exprIntNode != NULL);

    if(exprIntNode->type == PLUS) {
        return func_exprInt(exprIntNode->arrPtr[0])
        + func_exprInt(exprIntNode->arrPtr[1]);
    }
    else if(exprIntNode->type == MINUS){
        return func_exprInt(exprIntNode->arrPtr[0])
        - func_exprInt(exprIntNode->arrPtr[1]);
    }
    else if(exprIntNode->type == STAR) {
        return func_exprInt(exprIntNode->arrPtr[0])
        * func_exprInt(exprIntNode->arrPtr[1]);
    }
    else if(exprIntNode->type == FORWARD_SLASH) {
        return func_exprInt(exprIntNode->arrPtr[0])
        / func_exprInt(exprIntNode->arrPtr[1]);
    }

    assert(exprIntNode->type == INTEGER_NUMBER_VALUE
        || exprIntNode->type == ID_VALUE
        || exprIntNode->type == FUNCTION_VALUE);

    int valToReturn = 0;

    if(exprIntNode->type == INTEGER_NUMBER_VALUE) {
        valToReturn = exprIntNode->value.intVal;
    }
    else if(exprIntNode->type == ID_VALUE) {
        struct nodoTS * currNode = retrieveFromSymbolTable(exprIntNode->value.idName);
        assert(currNode->type == INTEGER_NUMBER_VALUE);
        valToReturn = currNode->value.intVal;
    }

    return valToReturn;
}

double func_exprDoubleFunc(ASR * exprDoubleNode, char * name) {
    // If we enter an EXPR node, we must at least one term.
    assert(exprDoubleNode != NULL);

    if(exprDoubleNode->type == PLUS) {
        return func_exprDoubleFunc(exprDoubleNode->arrPtr[0], name)
        + func_exprDoubleFunc(exprDoubleNode->arrPtr[1], name);
    }
    else if(exprDoubleNode->type == MINUS) {
        return func_exprDoubleFunc(exprDoubleNode->arrPtr[0], name)
        - func_exprDoubleFunc(exprDoubleNode->arrPtr[1], name);
    }
    else if(exprDoubleNode->type == STAR) {
        return func_exprDoubleFunc(exprDoubleNode->arrPtr[0], name)
        * func_exprDoubleFunc(exprDoubleNode->arrPtr[1], name);
    }
    else if(exprDoubleNode->type == FORWARD_SLASH) {
        return func_exprDoubleFunc(exprDoubleNode->arrPtr[0], name)
        / func_exprDoubleFunc(exprDoubleNode->arrPtr[1], name);
    }

    assert(exprDoubleNode->type == ID_VALUE
        || exprDoubleNode-> type == FLOATING_POINT_NUMBER_VALUE
        || exprDoubleNode-> type == FUNCTION_VALUE);

    double valToReturn = 0;

    if(exprDoubleNode->type == FLOATING_POINT_NUMBER_VALUE) {
        valToReturn = exprDoubleNode->value.doubleVal;
    }
    else if(exprDoubleNode->type == ID_VALUE) {
        struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(name);
        struct nodoTS * currNode = retrieveFromTsl(exprDoubleNode->value.idName, currIdFunc->tsl);
        assert(currNode->type == FLOATING_POINT_NUMBER_VALUE);
        valToReturn = currNode->value.doubleVal;
    }

    return valToReturn;
}



double func_exprDouble(ASR * exprDoubleNode) {
    assert(exprDoubleNode != NULL);

    if(exprDoubleNode->type == PLUS) {
        return func_exprDouble(exprDoubleNode->arrPtr[0])
        + func_exprDouble(exprDoubleNode->arrPtr[1]);
    }
    else if(exprDoubleNode->type == MINUS) {
        return func_exprDouble(exprDoubleNode->arrPtr[0])
        - func_exprDouble(exprDoubleNode->arrPtr[1]);
    }
    else if(exprDoubleNode->type == STAR) {
        return func_exprDouble(exprDoubleNode->arrPtr[0])
        * func_exprDouble(exprDoubleNode->arrPtr[1]);
    }
    else if(exprDoubleNode->type == FORWARD_SLASH) {
        return func_exprDouble(exprDoubleNode->arrPtr[0])
        / func_exprDouble(exprDoubleNode->arrPtr[1]);
    }

    assert(exprDoubleNode->type == ID_VALUE
        || exprDoubleNode-> type == FLOATING_POINT_NUMBER_VALUE
        || exprDoubleNode-> type == FUNCTION_VALUE);

    double valToReturn = 0;

    if(exprDoubleNode->type == FLOATING_POINT_NUMBER_VALUE) {
        valToReturn = exprDoubleNode->value.doubleVal;
    }
    else if(exprDoubleNode->type == ID_VALUE) {

        struct nodoTS * currNode = retrieveFromSymbolTable(exprDoubleNode->value.idName);
        assert(currNode->type == FLOATING_POINT_NUMBER_VALUE);
        valToReturn = currNode->value.doubleVal;
    }

    return valToReturn;
}


int func_expressionFunc(ASR* nodeExpr) {
    assert(nodeExpr->arrPtr[0] != NULL);
    assert(nodeExpr->arrPtr[1] != NULL);

    if(isIntegerExprFunc(nodeExpr->arrPtr[0], currentFuncName)) {
        assert(isIntegerExpr(nodeExpr->arrPtr[1]));
        int intExpresionLeftSide = func_exprIntFunc(nodeExpr->arrPtr[0], currentFuncName);
        int intExpresionRightSide = func_exprIntFunc(nodeExpr->arrPtr[1], currentFuncName);

        switch(nodeExpr->type) {
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
    else {
        assert(isFloatingPointExprFunc(nodeExpr->arrPtr[0], currentFuncName));
        assert(isFloatingPointExprFunc(nodeExpr->arrPtr[1], currentFuncName));

        double doubleExpresionLeftSide = func_exprDoubleFunc(nodeExpr->arrPtr[0], currentFuncName);
        int doubleExpresionRightSide = func_exprDoubleFunc(nodeExpr->arrPtr[1], currentFuncName);

        switch(nodeExpr->type) {
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

    assert(NULL);
    return -1;
}


int func_expression(ASR* nodeExpr) {
    assert(nodeExpr->arrPtr[0] != NULL);
    assert(nodeExpr->arrPtr[1] != NULL);

    if(isIntegerExpr(nodeExpr->arrPtr[0])) {
        assert(isIntegerExpr(nodeExpr->arrPtr[1]));
        int intExpresionLeftSide = func_exprInt(nodeExpr->arrPtr[0]);
        int intExpresionRightSide = func_exprInt(nodeExpr->arrPtr[1]);

        switch(nodeExpr->type) {
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
    else {
        assert(isFloatingPointExpr(nodeExpr->arrPtr[0]));
        assert(isFloatingPointExpr(nodeExpr->arrPtr[1]));

        double doubleExpresionLeftSide = func_exprDouble(nodeExpr->arrPtr[0]);
        int doubleExpresionRightSide = func_exprDouble(nodeExpr->arrPtr[1]);

        switch(nodeExpr->type) {
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

    assert(NULL);
    return -1;
}

int readInt() {
    int intVal = -1;
    printf("escribe tu entero: ");
    int scanfReturnValue = scanf("%d", &intVal);
    assert(scanfReturnValue > 0);
    return intVal;
}

double readDouble() {
    double doubleVal = -1.0;
    printf("Escribe tu numero de punto flotante: ");
    int scanfReturnValue = scanf("%lf", &doubleVal);
    assert(scanfReturnValue > 0);
    return doubleVal;
}

void printNodeType(int type, char* label) {
    // If our names array contains an entry for this type
    if(type >= 0 && type < sizeof(SyntaxTreeNodeTypeName)) {
        printf("%s: %s\n", label, SyntaxTreeNodeTypeName[type]);
    }
    else {
        printf("%s: %d\n", label, type);
    }
}

void preTreePrinting(ASR* node, char* nombre) {
    printf("###################### INICIO ARBOL SINTACTICO REDUCIDO DE LA FUNCION %s #####################\n\n", nombre);
    printTree(node);
    printf("###################### FIN ARBOL SINTACTICO REDUCIDO DE LA FUNCION %s #####################\n\n", nombre);
}

void printTree(ASR * node) {
    if(node == NULL) return;

    printNodeType(node->type, "type");
    printNodeType(node->parentNodeType, "parentNodeType");

    if(node->type == INTEGER_NUMBER_VALUE) {
        printf("Node value = %d\n", node->value.intVal);
    }
    else if(node->type == ID_VALUE) {
        printf("Node value = %s\n", node->value.idName);
    }
    else if(node->type == FLOATING_POINT_NUMBER_VALUE) {
        printf("Node value = %f\n", node->value.doubleVal);
    }
    else if(node->type == FUNCTION_VALUE) {
        printf("Node value = %s\n", node->value.idName);
    }

    int i = 0;
    printf("\n");

    for(i = 0; i < 4; i++)
        printTree(node->arrPtr[i]);
}

int traverseTree(ASR * node, int c) {
    if(!node) return 0;
    int count = 0;

    if(c <= 1)
        count += (node->type == PARAMETER_VALUE);

    for(int i = 0; i < 4; i++){
        count += traverseTree(node->arrPtr[i], c + (node->type == PARAMETER_VALUE));
    }

    return count;
}

void obtainType(struct nodoTS * tsl) {
    struct nodoTS * ptr = tsl;

    while(ptr != NULL) {
        if(ptr->type == INTEGER_NUMBER_VALUE) printf("(int, %d) ",ptr->value.intVal);
        else if(ptr->type == FLOATING_POINT_NUMBER_VALUE) printf("(float, %.2f) ", ptr->value.doubleVal);

        ptr = ptr->next;
    }
}

ASR * getNextPassedParameter(ASR ** ptrPtrFuncNodeSubStree) {
    assert(*ptrPtrFuncNodeSubStree);
    ASR * ptrNextPassedParameter = NULL;

    if((*ptrPtrFuncNodeSubStree)->type == FUNCTION_VALUE) {
        assert((*ptrPtrFuncNodeSubStree)->arrPtr[0]);
        ptrNextPassedParameter = (*ptrPtrFuncNodeSubStree)->arrPtr[0]->arrPtr[0];
    }
    else {
        assert((*ptrPtrFuncNodeSubStree)->type == PARAMETER_VALUE);
        ptrNextPassedParameter = (*ptrPtrFuncNodeSubStree)->arrPtr[0];
    }

    (*ptrPtrFuncNodeSubStree) = (*ptrPtrFuncNodeSubStree)->arrPtr[0]->arrPtr[1];
    assert(ptrNextPassedParameter);
    return ptrNextPassedParameter;
}

int tslLength(struct nodoTS * tsl) {
    struct nodoTS * ptr = tsl;
    int tslL = 0;

    while(ptr != NULL) {
        tslL++;
        ptr = ptr->next;
    }

    return tslL;
}

void moveTslForward(struct nodoTS ** ptrPtrTslHead, int moves) {
    for(int i = 0; i < moves; i++) {
        *ptrPtrTslHead = (*ptrPtrTslHead)->next;
    }
}

void func_func(ASR * nodeFunc) {
    struct nodoTSF * currFunc = retrieveFromFunSymbolTable(nodeFunc->value.idName);
    currentFuncName = nodeFunc->value.idName;
    assert(currFunc != NULL);
    int formalParams = currFunc->numParams;
    int amountOfParamsPassed = traverseTree(nodeFunc, 0);
    assert(formalParams == amountOfParamsPassed);
    int functionSymbolTableLength = tslLength(currFunc->tsl);
    struct nodoTS * currParamPassed = NULL;
    ASR* ptrFuncNodeSubTree = nodeFunc;
    ASR * paramsPassed = NULL;
    currParamPassed = currFunc->tsl;
    moveTslForward(&currParamPassed, functionSymbolTableLength - formalParams);

    for(int i = 0; i < amountOfParamsPassed; i++) {
        paramsPassed = getNextPassedParameter(&ptrFuncNodeSubTree);
        assert(paramsPassed);
        assert(currParamPassed);

        assert(isIntegerExpr(paramsPassed) && currParamPassed->type == INTEGER_NUMBER_VALUE);

        currParamPassed = currParamPassed->next;
    }

    struct nodoTS * currParamValues = NULL;
    ASR* ptrFuncNodeTree = nodeFunc;
    ASR * paramsValue = NULL;

    currParamValues = currFunc->tsl;
    moveTslForward(&currParamValues, functionSymbolTableLength - formalParams);
    for(int i = 0; i < amountOfParamsPassed; i++) {
        paramsPassed = getNextPassedParameter(&ptrFuncNodeTree);

        if(currParamValues->type == INTEGER_NUMBER_VALUE) {
            currParamValues->value.intVal = func_exprInt(paramsPassed);
        }
        else if(currParamValues->type = FLOATING_POINT_NUMBER_VALUE) {
            currParamValues->value.doubleVal = func_exprDouble(paramsPassed);
        }

        currParamValues = currParamValues->next;
    }

    struct nodoTSF * funcSymbol = retrieveFromFunSymbolTable(nodeFunc->value.idName);
    funcRunning = 1;
    interpreta(funcSymbol->cuerpo);
}

void func_read(ASR * nodeRead) {
    assert(nodeRead->arrPtr[0] != NULL);
    if(funcRunning == 0) {
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
    } else if(funcRunning == 1) {

        struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(currentFuncName);
        struct nodoTS * currNode = retrieveFromTsl(nodeRead->arrPtr[0]->value.idName, currIdFunc->tsl);

        int valueToSet;
        double doubleValueToSet;

        switch (currNode->type) {
            case INTEGER_NUMBER_VALUE:
            valueToSet = readInt();
            setIntValueToSymbolFunc(currNode->nombre,valueToSet, currentFuncName);
            assert(valueToSet == currNode->value.intVal);
            break;
            case FLOATING_POINT_NUMBER_VALUE:
            doubleValueToSet = readDouble();
            setDoubleValueToSymbolFunc(currNode->nombre, doubleValueToSet, currentFuncName);
            assert(doubleValueToSet == currNode->value.doubleVal);
            break;
        }
    }
}

void func_print(ASR * printNode) {
    assert(printNode->arrPtr[0] != NULL);

    if(printNode->arrPtr[0]->type == INTEGER_NUMBER_VALUE) {
        printf("%d\n", printNode->arrPtr[0]->value.intVal);
    }
    else if(printNode->arrPtr[0]->type == FLOATING_POINT_NUMBER_VALUE) {
        printf("%.2f\n", printNode->arrPtr[0]->value.doubleVal);
    } else if(printNode->arrPtr[0]->parentNodeType == EXPR
        || printNode->arrPtr[0]->parentNodeType == TERM
        || printNode->arrPtr[0]->parentNodeType == FACTOR) {

        if(printNode->arrPtr[0]->type == FUNCTION_VALUE) {
            func_func(printNode->arrPtr[0]);
            struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(currentFuncName);

            if(currIdFunc->returnType == INTEGER_NUMBER_VALUE) {
                printf("%d\n", currIdFunc->value.intVal);
            } else {
                assert(currIdFunc->returnType == FLOATING_POINT_NUMBER_VALUE);
                printf("%lf\n", currIdFunc->value.doubleVal);
            }
        } else {
            if(funcRunning == 0) {
                if(isIntegerExpr(printNode->arrPtr[0])) {
                    printf("%d\n", func_exprInt(printNode->arrPtr[0]));
                }
                else {
                    assert(isFloatingPointExpr(printNode->arrPtr[0]));
                    printf("%lf\n", func_exprDouble(printNode->arrPtr[0]));
                }
            } else if(funcRunning == 1) {
                if(isIntegerExprFunc(printNode->arrPtr[0], currentFuncName)){
                    printf("%d\n", func_exprIntFunc(printNode->arrPtr[0], currentFuncName));
                } else {
                    assert(isFloatingPointExprFunc(printNode->arrPtr[0], currentFuncName));
                    printf("%lf\n", func_exprDoubleFunc(printNode->arrPtr[0], currentFuncName));
                }
            }
        }
    }
}

void func_assign(ASR * setNode) {
    assert(setNode->arrPtr[0] != NULL);
    assert(setNode->arrPtr[1] != NULL);

    if(funcRunning == 0){
        struct nodoTS * currNode = retrieveFromSymbolTable(setNode->arrPtr[0]->value.idName);
        assert(currNode != NULL);
        int exprValueToSet;
        double exprDoubleValueToSet;

        if(setNode->arrPtr[1]->type != FUNCTION_VALUE) {
            switch(currNode->type) {
                case INTEGER_NUMBER_VALUE:
                    exprValueToSet = func_exprInt(setNode->arrPtr[1]);
                    setIntValueToSymbol(currNode->nombre, exprValueToSet);
                    assert(exprValueToSet == currNode->value.intVal);
                    break;
                case FLOATING_POINT_NUMBER_VALUE:
                    exprDoubleValueToSet = func_exprDouble(setNode->arrPtr[1]);
                    setDoubleValueToSymbol(currNode->nombre, exprDoubleValueToSet);
                    assert(exprDoubleValueToSet == currNode->value.doubleVal);
                    break;
            }
        } else if(setNode->arrPtr[1]->type == FUNCTION_VALUE) {
            switch (currNode->type) {
                case INTEGER_NUMBER_VALUE:
                func_func(setNode->arrPtr[1]);
                struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(currentFuncName);
                assert(currIdFunc->returnType == INTEGER_NUMBER_VALUE);
                exprValueToSet = currIdFunc->value.intVal;
                setIntValueToSymbol(currNode->nombre, exprValueToSet);
                assert(exprValueToSet == currNode->value.intVal);
                break;

                case FLOATING_POINT_NUMBER_VALUE:
                func_func(setNode->arrPtr[1]);
                struct nodoTSF * currIdFunc2 = retrieveFromFunSymbolTable(currentFuncName);
                assert(currIdFunc2->returnType == FLOATING_POINT_NUMBER_VALUE);
                exprDoubleValueToSet = currIdFunc2->value.doubleVal;
                setDoubleValueToSymbol(currNode->nombre, exprDoubleValueToSet);
                assert(exprDoubleValueToSet == currNode->value.doubleVal);
                break;
            }
        }
    } else if(funcRunning == 1) {
        struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(currentFuncName);
        struct nodoTS * currNode = retrieveFromTsl(setNode->arrPtr[0]->value.idName, currIdFunc->tsl);
        assert(currNode != NULL);
        int exprValueToSet;
        double exprDoubleValueToSet;

        switch(currNode->type) {
            case INTEGER_NUMBER_VALUE:
                exprValueToSet = func_exprIntFunc(setNode->arrPtr[1], currentFuncName);
                setIntValueToSymbolFunc(currNode->nombre, exprValueToSet, currentFuncName);
                assert(exprValueToSet == currNode->value.intVal);
                break;
            case FLOATING_POINT_NUMBER_VALUE:
                exprDoubleValueToSet = func_exprDoubleFunc(setNode->arrPtr[1], currentFuncName);
                setDoubleValueToSymbolFunc(currNode->nombre, exprDoubleValueToSet, currentFuncName);
                assert(exprDoubleValueToSet == currNode->value.doubleVal);
                break;
        }
    }
}

void func_if(ASR * nodeIf) {
    assert(nodeIf->arrPtr[0] != NULL);
    if(funcRunning == 0) {
        if(func_expression(nodeIf->arrPtr[0])) {
            if(nodeIf->arrPtr[1] != NULL) {
                interpreta(nodeIf->arrPtr[1]);
            }
        }
    } else if(funcRunning == 1) {
        if(func_expressionFunc(nodeIf->arrPtr[0])) {
            if(nodeIf->arrPtr[1] != NULL) {
                interpreta(nodeIf->arrPtr[1]);
            }
        }
    }
}

void func_ifElse(ASR * nodeIfElse) {
    assert(nodeIfElse->arrPtr[0] != NULL);
    if(funcRunning == 0) {
        if(func_expression(nodeIfElse->arrPtr[0])) {
            interpreta(nodeIfElse->arrPtr[1]);
        } else {
            interpreta(nodeIfElse->arrPtr[2]);
        }
    } else if(funcRunning == 1) {
        if(func_expressionFunc(nodeIfElse->arrPtr[0])) {
            interpreta(nodeIfElse->arrPtr[1]);
        } else {
            interpreta(nodeIfElse->arrPtr[2]);
        }
    }
}

void func_while(ASR * nodeWhile) {
    assert(nodeWhile->arrPtr[0] != NULL);
    if(funcRunning == 0) {
        while(func_expression(nodeWhile->arrPtr[0])) {
            interpreta(nodeWhile->arrPtr[1]);
        }
    } else if(funcRunning == 1) {
        while(func_expressionFunc(nodeWhile->arrPtr[0])) {
            interpreta(nodeWhile->arrPtr[1]);
        }
    }
}

void func_for(ASR * nodeFor) {

    assert(nodeFor->arrPtr[0] != NULL);
    assert(nodeFor->arrPtr[1] != NULL);
    assert(nodeFor->arrPtr[2] != NULL);

    if(funcRunning == 0) {
        func_assign(nodeFor->arrPtr[0]);

        while(func_expression(nodeFor->arrPtr[1])) {
            interpreta(nodeFor->arrPtr[3]);
            func_assign(nodeFor->arrPtr[2]);
        }
    } else if(funcRunning == 1) {
        func_assign(nodeFor->arrPtr[0]);
        while(func_expressionFunc(nodeFor->arrPtr[1])) {
            interpreta(nodeFor->arrPtr[3]);
            func_assign(nodeFor->arrPtr[2]);
        }
    }
}

void func_repeat(ASR * nodeRepeat) {
    assert(nodeRepeat->arrPtr[1] != NULL);
    if(funcRunning == 0) {
        do {
            interpreta(nodeRepeat->arrPtr[0]);
        } while(func_expression(nodeRepeat->arrPtr[1]));
    } else if(funcRunning == 1) {
        do {
            interpreta(nodeRepeat->arrPtr[0]);
        } while(func_expressionFunc(nodeRepeat->arrPtr[1]));
    }
}

void func_return(ASR * nodeReturn) {
    assert(nodeReturn->arrPtr[0] != NULL);
    struct nodoTSF * currIdFunc = retrieveFromFunSymbolTable(currentFuncName);

    if (nodeReturn->arrPtr[0]->type == INTEGER_NUMBER_VALUE) {
        assert(currIdFunc->returnType == INTEGER_NUMBER_VALUE);
        currIdFunc->value.intVal = nodeReturn->arrPtr[0]->value.intVal;
    } else if(nodeReturn->arrPtr[0]->type == FLOATING_POINT_NUMBER_VALUE) {
        assert(currIdFunc->returnType == FLOATING_POINT_NUMBER_VALUE);
        currIdFunc->value.doubleVal = nodeReturn->arrPtr[0]->value.doubleVal;
    } else if(nodeReturn->arrPtr[0]->parentNodeType == EXPR
        || nodeReturn->arrPtr[0]->parentNodeType == TERM
        || nodeReturn->arrPtr[0]->parentNodeType == FACTOR) {
        if(isIntegerExprFunc(nodeReturn->arrPtr[0], currentFuncName)) {
            assert(currIdFunc->returnType == INTEGER_NUMBER_VALUE);
            currIdFunc->value.intVal = func_exprIntFunc(nodeReturn->arrPtr[0], currentFuncName);
        } else {
            assert(isFloatingPointExprFunc(nodeReturn->arrPtr[0], currentFuncName));
            assert(currIdFunc->returnType == FLOATING_POINT_NUMBER_VALUE);
            currIdFunc->value.doubleVal = func_exprDoubleFunc(nodeReturn->arrPtr[0], currentFuncName);
        }
    }

    funcRunning = 0;
}

void interpreta(ASR * node) {
    if(node == NULL)
    return;

    switch (node->type) {
        case PROGRAM:
        break;

        case PYC:
        break;

        case PYC_S:
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

        case RETURN:
        func_return(node);
        break;
    }

    if(node->type != IF &&
        node->type != IFELSE &&
        node->type != WHILE &&
        node->type != FOR) {

        int i;
        for(i = 0; i < 4; i++)
        interpreta(node->arrPtr[i]);
    }
}
