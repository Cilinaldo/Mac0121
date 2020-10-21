/* 

Faça uma função 

int bemformada (char seq[]); 

que recebe uma sequência com parêntesis, colchetes e chaves e 
decida se é bem formada: 

() é bem formada
() { () [ () {} ] [] } é bem formada
[ ( ] ) não é bem formada
( { } ) ] não é bem formada
[ ( { } ) não é bem formada

*/

#include <stdio.h>
#include <string.h> 
#include "pilha.h"
#define MAX 1000

int ehAbre (char c) {
  return (c == '(' || c == '[' || c == '{');
} 
int ehFecha (char c) {
  return (c == ')' || c == ']' || c == '}');
}
int combina (char a, char b){
  return ((a == '(' && b == ')') || (a == ')' && b == '(') ||
	  (a == '[' && b == ']') || (a == ']' && b == '[') ||
	  (a == '{' && b == '}') || (a == '}' && b == '{'));
} 

int bemformada (char seq[]) {
  pilha * p = criaPilha (strlen(seq));
  int i, ok = 1;
  char c; 
  for (i = 0; seq[i] != '\0' && ok; i ++){
    if (ehAbre (seq[i]))
      empilha (p, seq[i]);
    else if (ehFecha(seq[i])) {
      if (!pilhaVazia (p)){
	c = desempilha(p); 
	if (!combina (c, seq[i]))
	  ok = 0;
      }
      else
	ok = 0;
    }
  }
  if (!pilhaVazia (p))
    ok = 0;
  destroiPilha (p); 
  return ok;
}


int main () {
  char seq[MAX];
  printf("Digite a sequência: ");
  scanf ("%[^\n]", seq);
  if (bemformada (seq))
    printf ("Bem formada\n");
  else
    printf ("Não é bem formada\n");
  return 0;
} 
  
