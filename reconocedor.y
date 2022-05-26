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

union valor {
 int i;
 float f;
 char * id;
 }v;
 
struct nodoTS {
    char * nombre;
    unsigned char stipo;
    /* int = 0
    float = 1*/
    int vint;
    float vfloat;
    struct nodoTS * next;
};
// Definimos una estructura para hacer el árbol sintáctico reducIDo.
typedef struct asr ASR;
struct asr {
   unsigned char tipo; 
   /* Indica si es: 
   0 = instrucción, 
   1 = constante, 
   2 = operación, 
   3 = relación, 
   4 = variable*/
   char * stipo; 
   /*Indica el tipo de instrucción: 
   0 = begin, 
   1 = end, 
   2 = read, 
   3 = print, 
   4 = if, 
   5 = then, 
   6 = else, 
   7 = for, 
   8 = do, 
   9 = while, 
   a = repeat, 
   b = until, 
   c = step. 
   d = no_es_instrucción*/
   // Indica si una variable es float o int
   // Si es un número es el valor del número. Si no, es la operación.
   unsigned char tipovalor; // Indica si una variable es de tipo 0 = int, 1 = float o 2 = no_es_variable
   int vint;
   float vfloat; 
   ASR * p1; // La subexpresión a la izquierda
   ASR * p2; // La subexpresión a la derecha
   ASR * p3; // apuntador al nodo correspondiente en la tabla de símbolos
};




extern int yylex();
int yyerror(char const * s);
ASR * nuevoNodo(unsigned char,  char * , unsigned char, int, float, ASR *, ASR *, ASR *);
extern char * yytext;
extern FILE *yyin;
void findID(char * id);
struct nodoTS * insertID(char* id, int tipo);
void printList();
void recorre(ASR * raiz, int level);
void printTabs(int level);
void read(ASR * root);


struct nodoTS * head = NULL;
struct nodoTS * current = NULL;
%}

%union {
   struct nodoTS * val;
   char * nombre;
   int entero;  // Para las constantes num�ricas
   float flotante;
   union valor *f;
   struct asr * arbol;  // Para los apuntadores a �rbol sint�ctico
}

/* Los elementos terminales de la gram�tica. La declaraci�n de abajo se
   convierte en definici�n de constantes en el archivo calculadora.tab.h
   que hay que incluir en el archivo de flex. */
   


%token SUMA RESTA MULT DIV PARI PARF BGN END COLON SEMI ASSIGN EQUAL LESSER GREATER LEQUAL GEQUAL LARROW FOR DO WHILE IF THEN ELSE INT FLOAT REPEAT UNTIL STEP PROGRAM VAR READ PRINT INTEGER FLOATING
%token <nombre> ID
%type <entero> type
%type <arbol> prog opt_decls decl_lst stmt opt_stmts stmt_lst expr term factor expression
%type <val> decl
%start prog

%precedence THEN
%precedence ELSE

%%

prog : PROGRAM ID opt_decls BGN opt_stmts END  {printf("\n programa valido \n"); printList(); recorre($5, 0); exit(0);}
;

opt_decls : decl_lst {printf("\n Se ha encontrado un enunciado");}
	  | %empty {$$ = NULL;}
          
;

decl_lst : decl SEMI decl_lst {printf("\n Se ha encontrado mas de una declaracion");}
         | decl {printf("\n Se ha encontrado una sola declaracion");}
;

decl : VAR ID COLON type  {$$ = insertID($2, $4);}
;

type : INTEGER  {$$ = INTEGER;}
     | FLOATING {$$ = FLOATING;}
;

stmt : ID LARROW expr {
			
			ASR *nodoID;
			nodoID = nuevoNodo(1, $1, '2', 0, 0.0, NULL, NULL, NULL);
			$$ = nuevoNodo(0, "ASSIGN", '2', 0, 0.0, nodoID, $3, NULL);
	
		       } 
     | IF expression THEN stmt {
     				  $$ = nuevoNodo(0, "IF", '2', 0, 0.0, $2, $4, NULL);
     				}
     | FOR ID LARROW expr UNTIL expr STEP expr DO stmt 
     | READ ID {
     		ASR *nodoID;
     		nodoID = nuevoNodo(0,$2, '2', 0,0.0, NULL, NULL, NULL);	
     		$$ = nuevoNodo(0, "READ", '2', 0, 0.0, nodoID, NULL, NULL);
     		}
     | IF expression THEN stmt ELSE stmt 
     | WHILE PARI expression PARF stmt
     | REPEAT stmt UNTIL PARI expression PARF 
     | PRINT expr {
     		   $$ = nuevoNodo(0, "PRINT", '2', 0, 0.0, $2, NULL, NULL);
     		   }
     | BGN opt_stmts END 
;

opt_stmts : stmt_lst {$$ = $1;}
          | %empty {$$ = NULL;}
;
stmt_lst : stmt SEMI stmt_lst {$$ = nuevoNodo(0,"PYC",'2',0, 0.0, $1,$3, NULL);}
         | stmt {$$ = nuevoNodo(0,"PYC_S",'2',0, 0.0, $1, NULL, NULL);}
;

expr : expr SUMA term  {$$ = nuevoNodo('2', "+", '2', 0, 0.0, $1, $3, NULL);}
     | expr RESTA term  {$$ = nuevoNodo('2', "-", '2', 0, 0.0, $1, $3, NULL);}
     | term {$$ = $1;}
;

term : term MULT factor {$$ = nuevoNodo('2', "*", '2', 0, 0.0, $1, $3, NULL);}
     | term DIV factor {$$ = nuevoNodo('2', "/", '2', 0, 0.0, $1, $3, NULL);}
     | factor {$$ = $1;}
;

// modificada para diferenciar entre enteros y flotantes
factor : PARI expr PARF  
       | ID   {$$ = nuevoNodo(1, $1, 1, 0, 0.0, NULL, NULL, NULL);}      
       | INT  {$$ = nuevoNodo(1, "INT", 1, yylval.entero, 0.0, NULL, NULL, NULL);}      
       | FLOAT {$$ = nuevoNodo(1, "FLOAT", 1, 0, yylval.flotante, NULL, NULL, NULL);}
;

expression : expr LESSER expr {$$ = nuevoNodo(3, "<", '2', 0, 0.0, $1, $3, NULL);}
           | expr GREATER expr {$$ = nuevoNodo(3, ">", '2', 0, 0.0, $1, $3, NULL);}
           | expr EQUAL expr {$$ = nuevoNodo(3, "=", '2', 0, 0.0, $1, $3, NULL);}
           | expr LEQUAL expr {$$ = nuevoNodo(3, ">=", '2', 0, 0.0, $1, $3, NULL);}
           | expr GEQUAL expr {$$ = nuevoNodo(3, "<=", '2', 0, 0.0, $1, $3, NULL);}
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


/*program algo
var x: int;
var y: int
begin 
x <- 5;
y <- 4;
return x + y;
end
*/


void printList() {
	 struct nodoTS * ptr = head;
	
	printf("\n[ ");
	
	while(ptr != NULL) {
	 if(ptr->stipo == '0') printf("(%s, int, %d) ",ptr->nombre, ptr->vint);
	 else if(ptr->stipo == '1') printf("(%s, float, %.2f) ", ptr->nombre, ptr->vfloat);
	 ptr = ptr->next;
	}
	
	printf(" ] \n");

}

ASR * nuevoNodo(unsigned char tipo,  char * stipo, unsigned char tipovalor, int vint, float vfloat, ASR * p1, ASR * p2, ASR * p3) {

   ASR * aux = (ASR *) malloc(sizeof(ASR));
   aux -> tipo = tipo;
   aux -> stipo = stipo;
   aux -> tipovalor = tipovalor;
   aux -> vint = vint;
   aux -> vfloat = vfloat;
   aux -> p1 = p1;
   aux -> p2 = p2;
   aux -> p3 = p3;
   return aux;
}

struct nodoTS * insertID(char * id, int tipo) {

	struct nodoTS * link = (struct nodoTS *) malloc(sizeof(struct nodoTS));
	
	if(tipo == INTEGER) {
	link->stipo = '0';
	} else if(tipo == FLOATING) {
	link->stipo = '1';
	}
	link->vint = 0;
	link->vfloat = 0.0;
	link->nombre = id;
	link->next = head;
	head = link;

}


void findID(char * id){
	printf("\n este es el id %s", id);
  	struct nodoTS * current = head;
	printf("soy v %.2f ", v.f);
	char * str = "false";
	while(current != NULL) {
          printf("\n este es el nombre %s", current->nombre); 
	  if(strcmp(current->nombre, id) == 0) {
	     str = "true";
	  }
	  
	  current = current->next;
	  
	  }
	  
	  printf("\n %s", str);
	  
	 
}



/* La funci�n recorre es el int�rprtete en este caso. Simplemente recorre
   el �rbol en postorden para obtener los valores correspondientes.
*/

void printTabs(int count){
   //printf("entre a printTab");
   for(int i = 0; i < count; i++){
   	putchar('\t');
   
   }
}

void recorre(ASR * raiz, int level) {

      if (raiz != NULL){  
      	recorre(raiz -> p1, level+1);
      	recorre(raiz -> p2, level+1);
      	recorre(raiz -> p3, level+1);
      	printTabs(level);
      	
      	if(raiz->stipo == "READ"){
      	   read(raiz);
      	 }
      	  
      	if(strcmp(raiz->stipo, "INT") == 0){
      	  printf("Valor int: %d\n", raiz->vint);
      	
      	} else if(strcmp(raiz->stipo, "FLOAT") == 0) {
          printf("Valor float: %.2f\n", raiz->vfloat);
      	} else {
      	    printf("Nodo: %s\n", raiz->stipo);
      	  }
      	  
      	
      	  
      }
      
      
      
      
 }
 
 
 void read(ASR * raiz){
 	printf("entre a read \n");
 
 
 }

