/*

 Este programa recebe uma string exp com uma expressão aritmética
 com operadores (A, B, etc), '+', '-', '*', '/', '(' e ')' e imprime
 a expressão correspondente na notação poxfixa.


Exemplo:
 A + B * C                          -----> A B C * +
 A * (B + C) / D - E                -----> A B C + * D / E -
 (A + B) * (C - D) + (F - G) / H    -----> A B + C D - * F G - H / +

*/


#include <stdio.h>
#include <string.h>
#include "pilha.h"
#define MAX 100

int prec (char c) {
    if (c == '(') {
        return 0;
    }
    if (c == '+' || c == '-') {
        return 1;
    }
    return 2;
}

int operador (char c) {
    return (c == '(' || c == ')' || c == '+' ||
            c == '-' || c == '*' || c == '/');
}


void posfixa (char exp[]) {
   pilha * pilhaOp = criaPilha(strlen(exp));
   char ctopo;
   int i;
   for (i = 0; exp[i] != '\0'; i++) {
       if (exp[i] == ' ') {
           continue;
       }
       else {
           if (!operador(exp[i])) {
               printf("%c", exp[i]);
           }
           else if (exp[i] == '('){
               empilha (pilhaOp, exp[i]);
	   }
	   else if (exp[i] == ')') {
               ctopo = desempilha (pilhaOp);
	       while (ctopo != '(') {
                   printf("%c", ctopo);
	           ctopo = desempilha (pilhaOp);
	       }
	   }
	   else {
               while (!pilhaVazia(pilhaOp) && prec(topoDaPilha(pilhaOp)) >= prec(exp[i])) {
                   ctopo = desempilha (pilhaOp);
		   printf("%c", ctopo);
	       }
	       empilha (pilhaOp, exp[i]);
	   }
       }
   }
   while (!pilhaVazia(pilhaOp)) {
       ctopo = desempilha (pilhaOp);
       printf("%c", ctopo);
   }
   printf("\n");
}


int main() {
    char seq[MAX];
    printf("Digite a sequência: ");
    scanf("%[^\n]", seq);
    posfixa(seq);
    return 0;
}


