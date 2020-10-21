/*###############################
 * AUTOR: Cilinaldo da Silva    #
 * NÚMERO USP: 8031013          #
 * DISCIPLINA: MAC0121          #
 * ##############################
 */



#include <stdio.h>
#include <stdlib.h>

/*     ESTA FUNÇÃO RECEBE COMO ARGUMENTOS
 * nome: o caminho completo do arquivo a ser lido.
 * d1: o 'tamanho' do deslocamento letras maiúsculas
 * d2: o 'tamanho' do deslocamento letras minúsculas. */
void le_arquivo(char * nome, int d1, int d2);


/*     PARAMÊTROS DA ASSINATURA
 * nome: o caminho completo do arquivo a ser manipulado.
 *     VALOR DE RETORNO
 * FILE *: um ponteiro para o arquivo a ser lido manipulado. */
FILE* pega_arquivo(char * nome);


/*    PARAMÊTROS DA ASSINATURA
 * x: o caracter a ser criptografado.
 * d1: o 'tamanho' do deslocamento letras maiúsculas.
 * d2: o 'tamanho' do deslocamento letras minúsculas. */
void criptografa_caracter(char x, int d1, int d2);


/*    PARAMÊTROS DA ASSINATURA
 * x: o caracter a ser criptografado.
 * d: o 'tamanho' do deslocamento que ocorrerá para o caracter.
 * min: o valor int que o menor char de uma sequência ordenada de char assume.
 * max: o valor int que o maior char de uma sequencia ordenada de char assume. 
 *    VALOR DE RETORNO
 * char: caracter criptografado*/
char criptografa(char x, int d, int min, int max);


/*    PARAMÊTROS DA ASSINATURA
 * x: o caracter maiúsculo a ser criptografado.
 * d: o 'tamanho' do deslocamento que ocorrerá para o caracter.
 *    VALOR DE RETORNO
 * char: caracter criptografado*/
char criptografa_minuscula(char x, int d);


/*    PARAMÊTROS DA ASSINATURA
 * x: o caracter minúsculo a ser criptografado.
 * d: o 'tamanho' do deslocamento que ocorrerá para o caracter.
 *    VALOR DE RETORNO
 * char: caracter criptografado*/
char criptografa_maiuscula(char x, int d);



int main() {
	char nome[80]; /* recebe o nome externo do arquivo a ser lido */
	int d1, d2; /* recebem os valores de deslocamento para letras maiúsculas e minúsculas, respectivamente*/

	if (scanf ("%s%d%d", nome, &d1, &d2) > 0) {
		le_arquivo(nome, d1, d2);  
		return 0;
	}
	else {
		printf ("Erro na estrada de dados para o nome do arquivo\n");
		exit(EXIT_FAILURE);
	}
}

char criptografa_maiuscula(char x, int d) {
        return criptografa(x, d, 65, 90); 
}

char criptografa_minuscula(char x, int d) {
        return criptografa(x, d, 97, 122);
}


char criptografa(char x, int d, int min, int max) {
	int mod;

	mod = d%26;

        if (x+mod > max) {
                mod = x+mod-max;
                mod = min+mod-1;
        }
        else {
                mod = x+mod;
        }
        return mod;
}


void criptografa_caracter(char x, int d1, int d2) {

	if (x >=65 && x <= 90) 
		printf ("%c", criptografa_maiuscula(x, d1));
        else if (x >=97 && x <= 122)
        	printf ("%c", criptografa_minuscula(x, d2));
        else if (x == ',') {
                printf ("v");
                printf ("r");
	}
        else if (x == '.') {
                printf ("p");
                printf ("t");

        }
        else if (x == ':') {
                printf ("d");
                printf ("p");
        }
        else if (x == '!') {
                printf ("e");
                printf ("x");

        }
        else if (x == '?') {
                printf ("i");
                printf ("n");
        }
        else if (x == '\n') {
                printf ("n");
                printf ("l");
        }        
}


FILE* pega_arquivo(char * nome) {
        FILE * arq;
        arq = fopen (nome, "r"); 
        if (arq == NULL) {
                printf ("Não encontrei o arquivo %s\n", nome);
                exit(EXIT_FAILURE);
        }
        return arq;
}


void le_arquivo(char * nome, int d1, int d2) {
        FILE * arq;
        char c;
	int tam;

        arq = pega_arquivo(nome);

	tam = 0;
	while (!feof (arq)) {
		if (fscanf (arq, "%c", &c) > 0) {
			criptografa_caracter(c, d1, d2);
			tam++;
		}
	}
        printf ("\n");

        fclose(arq);
}

