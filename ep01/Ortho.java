/******************************************************************************
 *
 * MAC0121 ALGORITMOS E ESTRUTURAS DE DADOS I
 * Aluno: Cilinaldo da Silva
 * Numero USP: 8031013
 * Tarefa: EP01
 * Data: 29/08/2021
 * 
 *
 * DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESTE PROGRAMA.  TODAS AS 
 * PARTES DO PROGRAMA, EXCETO AS QUE SÃO BASEADAS EM MATERIAL FORNECIDO  
 * PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE SEDGEWICK & WAYNE, 
 * FORAM DESENVOLVIDAS POR MIM.  DECLARO TAMBÉM QUE SOU RESPONSÁVEL POR TODAS 
 * AS CÓPIAS DESTE PROGRAMA E QUE NÃO DISTRIBUÍ NEM FACILITEI A DISTRIBUIÇÃO
 * DE CÓPIAS DESTA PROGRAMA.
 *
 ******************************************************************************/
    

class Ortho {

	public static boolean busca_binaria(String palavra, String[] dicionario) {
		int inicio = 0;         //Posição inicial do vetor.
    		int meio = 0;          //Posição do meio do vetor.
		int fim = dicionario.length - 1;  //Posição final do vetor.
    
		/* Enquanto a posição do inicio for menor ou igual a posição do fim,
		procura o valor de x dentro do vetor. */
    		while(inicio <= fim) {
      			meio = (fim + inicio) / 2; //Encontra o meio do vetor.

			int compara = palavra.compareTo(dicionario[meio]);
      
      			/* Se compara == 0  as strings são iguais. */
			if(compara == 0) {	
        			return true;
      			}
			/* Se compara < 0, implica palavra < dicionario[meio], então o novo vetor considerado
			 * será aquele que fim = meio -1*/
			if(compara < 0) {
        			fim = meio - 1;
      			}	
			else {
        		/* Caso contrário será considerado o novo fetor o vetor com inicio =  meio + 1. */
        			inicio = meio + 1;
      			}
		}
		return false;
	}

	public static String[] words(String s) {
		String r = "çÇáéíóúýÁÉÍÓÚÝàèìòùÀÈÌÒÙãõñäëïöüÿÄËÏÖÜÃÕÑâêîôûÂÊÎÔÛ";
		s = s.replaceAll("[^A-Za-z" + r + "\\s]", " ");
		s = s.trim();
		String[] w = s.split("\\s+");
		return w;
    	}


	public static void main(String[] args) {
		/*lê o dicionario*/
		String arquivo = args[0];		
		In in = new In(arquivo);
		String[] dicionario = in.readAllStrings();

		/*lê o texto*/
		String s = StdIn.readAll();
		String[] texto = words(s);
		
		for (String palavra : texto) {
			boolean existe = busca_binaria(palavra, dicionario);
			if (!existe) { // verifica se a plavra escrita no mesmo formato que está escrita existe
				existe = busca_binaria(palavra.toLowerCase(), dicionario);
				if (!existe) { // considera toda em minísculo
					existe = busca_binaria(palavra.toUpperCase(), dicionario);
					if (!existe) { // considera toda em maíusculo
						String p_captalize = palavra.substring(1, palavra.length());
						String letra_inicial = palavra.substring(0, 1);
						p_captalize = letra_inicial.toUpperCase() + p_captalize;
						existe = busca_binaria(p_captalize, dicionario);
						if (!existe) { // considera a primeira letra sendo maíuscula existe, independente das demais
							p_captalize = palavra.substring(1, palavra.length());
							letra_inicial = palavra.substring(0, 1);
							p_captalize = letra_inicial.toUpperCase() + p_captalize.toLowerCase();
							existe = busca_binaria(p_captalize, dicionario);
						       	if (!existe) { // considera somente a primeira letra sendo maíuscula
								StdOut.println(palavra);
							}
						}
					}
				}
			}
		}
	}

}
