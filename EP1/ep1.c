/*###############################
 * AUTOR: Cilinaldo da Silva    #
 * NÚMERO USP: 8031013          #
 * DISCIPLINA: MAC0121          #
 * ##############################
 */






#include <stdio.h>
#include <stdlib.h>


/*     PARAMÊTROS DA ASSINATURA
 * nome: o caminho completo do arquivo a ser manipulado.
 *     VALOR DE RETORNO
 * FILE *: um ponteiro para o arquivo a ser lido manipulado. */
FILE* pega_arquivo(char * nome);


/*     PARAMÊTROS DA ASSINATURA
 * nome: o caminho completo do arquivo a ser manipulado.
 *     VALOR DE RETORNO
 * int: quantidade de caracteres do arquivo. */
int pega_tamanho_arquivo(char * nome);


/*     PARAMÊTROS DA ASSINATURA
 * tamanho: quantidade de caracteres do arquivo que será lido.
 * nome: o caminho completo do arquivo a ser manipulado.
 * texto: vetor de caracteres quer guardará os caracteres lido. */
void le_arquivo(int tamanho, char * nome, char * texto);


/*     PARAMÊTROS DA ASSINATURA
 * texto: vetor de caracteres a ser impresso na saída padrão.
 * tamanho: tamanho do vetor de caracter que será impresso. */
void imprime_texto(char * texto, int tamanho);


/*     PARAMÊTROS DA ASSINATURA
 * tamanho: quantidade de caracteres do arquivo que foi lido.
 * texto: vetor dos aracteres lidos do arquivo. 
 *     VALOR DE RETORNO
 * int: valor que representa o tamanho do vetor com caracteres criptografados. */
int tamanho_atualizado(int tamanho, char * texto);


/*     PARAMÊTROS DA ASSINATURA
 * texto: vetor dos aracteres lidos do arquivo.
 * tamanho: quantidade de caracteres do arquivo que foi lido.
 * novo_texto: vetor de caracteres, com os caracteres especiais criptografados. */
void retira_caracteres_especiais(char * texto, int tamanho, char * novo_texto);


/*    PARAMÊTROS DA ASSINATURA
 * x: o caracter a ser criptografado.
 * d: o 'tamanho' do deslocamento que ocorrerá para o caracter.
 * min: o valor int que o menor char de uma sequência ordenada de char assume.
 * max: o valor int que o maior char de uma sequencia ordenada de char assume.
 *    VALOR DE RETORNO
 * char: caracter criptografado*/
char criptografa_caracter(char x, int d, int min, int max);


/*    PARAMÊTROS DA ASSINATURA
 * x: o caracter maiúsculo a ser criptografado.
 * d: o 'tamanho' do deslocamento que ocorrerá para o caracter.
 *    VALOR DE RETORNO
 * char: caracter criptografado*/
char criptografa_maiuscula(char x, int d);


/*    PARAMÊTROS DA ASSINATURA
 * x: o caracter minúsculo a ser criptografado.
 * d: o 'tamanho' do deslocamento que ocorrerá para o caracter.
 *    VALOR DE RETORNO
 * char: caracter criptografado*/
char criptografa_minuscula(char x, int d);

/*    PARAMÊTROS DA ASSINATURA
 * texto: vetor a ser criptografado, ja com os caracteres especiais criptografados.
 * tamanho: tamanho do vetor.
 * d1: o 'tamanho' do deslocamento letras maiúsculas.
 * d2: o 'tamanho' do deslocamento letras minúsculas. */
void criptografa_texto(char * texto, int tamanho, int d1, int d2);




int main() {
	char nome[80]; /* recebe o nome externo do arquivo a ser lido */
	int tamanho, novo_tamanho, d1, d2;
	char * texto;
	char * novo_texto;
	if (scanf ("%s%d%d", nome, &d1, &d2) > 0) {
		tamanho = pega_tamanho_arquivo(nome);
		texto = malloc (tamanho * sizeof (char));
		le_arquivo(tamanho, nome, texto);
		novo_tamanho = tamanho_atualizado(tamanho, texto);
		novo_texto = malloc (novo_tamanho * sizeof (char));
		retira_caracteres_especiais(texto, tamanho, novo_texto);
		criptografa_texto(novo_texto, novo_tamanho, d1, d2);
		imprime_texto(novo_texto, novo_tamanho);

		

		free(texto);
		free(novo_texto);
		return 0;
	}
	else {
		printf ("Erro na estrada de dados para o nome do arquivo\n");
		exit(EXIT_FAILURE);
	}
}


/* Pega a representação int que um char possui, segundo a tabela ascii,
 * e realiza o deslocamento.
 * A lógica para fazer isto é simples, parecida com a utilizada para inscrever um angulo qualquer
 * dentro da primeira volta do circulo trigonomêtrico, ou seja de 0 a 360 graus, aqui
 * usamos também  o resto da divisão. 
 * Nossa 'circunferência' vai de min a max. */
char criptografa_caracter(char x, int d, int min, int max) {
        int mod;

        mod = d%26;

	/* verifica se para a última 'volta' foi excedido o valor máximo
	 * Caso afirmativo: pega so o que excedeu com relação ao máximo
	 * e subtrai um, este será o novo caracter.
	 * Caso negativo: pega somente a soma a partir de x e já cai no caracter novo */
        if (x+mod > max) {
                mod = x+mod-max; 
                mod = min+mod-1;
        }
        else {
                mod = x+mod;
        }
        return mod;
}

char criptografa_maiuscula(char x, int d) {
        return criptografa_caracter(x, d, 65, 90);
}

char criptografa_minuscula(char x, int d) {
        return criptografa_caracter(x, d, 97, 122);
}

void criptografa_texto(char * texto, int tamanho, int d1, int d2) {
        int i;
        for (i = 0; i < tamanho; i++) {
                if (texto[i] >=65 && texto[i] <= 90) { /* [65,...,90] é a representação ascii dos caracteres maiúsculos de 'A' a 'Z' */
                        texto[i] = criptografa_maiuscula(texto[i], d1);
                }
                else if (texto[i] >=97 && texto[i] <= 122) { /* [97,...,122] é a representação ascii dos caracteres maiúsculos de 'a' a 'z' */
                        texto[i] = criptografa_minuscula(texto[i], d2);
                }
        }
}

void retira_caracteres_especiais(char * texto, int tamanho, char * novo_texto) {
        int indice, aux;

        aux = 0;
        for (indice = 0; indice < tamanho; indice++) {
                if (texto[indice] == ' ') {
                        continue;
                }
                else if (texto[indice] == ',') {
                        novo_texto[aux++] = 'v';
                        novo_texto[aux++] = 'r';
                }
                else if (texto[indice] == '.') {
                        novo_texto[aux++] = 'p';
                        novo_texto[aux++] = 't';
                }
                else if (texto[indice] == ':') {
                        novo_texto[aux++] = 'd';
                        novo_texto[aux++] = 'p';
                }
                else if (texto[indice] == '!') {
                        novo_texto[aux++] = 'e';
                        novo_texto[aux++] = 'x';
                }
                else if (texto[indice] == '?') {
                        novo_texto[aux++] = 'i';
                        novo_texto[aux++] = 'n';
                }
                else if (texto[indice] == '\n') {
                        novo_texto[aux++] = 'n';
                        novo_texto[aux++] = 'l';
                }
                else {
                        novo_texto[aux] = texto[indice];
                        aux++;
                }

        }
}

int tamanho_atualizado(int tamanho, char *texto) {
        int indice, novo_tamanho = tamanho;

        for (indice = 0; indice < tamanho; indice++) {
                if (texto[indice] == ' ') {
                        novo_tamanho--;
                }
                else if (texto[indice] == ',') {
                        novo_tamanho++;
                }
                else if (texto[indice] == '.') {
                        novo_tamanho++;
                }
                else if (texto[indice] == ':') {
                        novo_tamanho++;
                }
                else if (texto[indice] == '!') {
                        novo_tamanho++;
                }
                else if (texto[indice] == '?') {
                        novo_tamanho++;
                }
                else if (texto[indice] == '\n') {
                        novo_tamanho++;
                }
        }
        return novo_tamanho;
}

void le_arquivo(int tamanho, char * nome, char * texto)  {
        FILE * arq;
        int tam = 0;

        arq = pega_arquivo(nome);

        while (!feof (arq)) {
                if(fscanf (arq, "%c", &texto[tam]) > 0) {
                        tam++;
                }
        }

        fclose(arq);
}

void imprime_texto(char * texto, int tamanho) {
        int tam;
        for (tam = 0; tam < tamanho; tam++) {
                printf ("%c", texto[tam]);
        }
        printf ("\n");
}

FILE* pega_arquivo(char * nome) {
        FILE * arq;
        arq = fopen (nome, "r"); /* abre o arquivo com o nome lido para leitura "r" */
        if (arq == NULL) {
                printf ("Não encontrei o arquivo %s\n", nome);
                exit(EXIT_FAILURE);
        }
        return arq;
}


int pega_tamanho_arquivo(char * nome) {
        FILE * arq;
        int tamanho = 0;
        char c;
        arq = pega_arquivo(nome);


        for (c = getc(arq); c != EOF; c = getc(arq)) {
                tamanho = tamanho + 1;
        }

        fclose(arq);

        return tamanho;
}

