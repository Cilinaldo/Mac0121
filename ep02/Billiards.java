/******************************************************************************
 *
 * MAC0121 ALGORITMOS E ESTRUTURAS DE DADOS I
 * Aluno: Cilinaldo da Silva
 * Numero USP: 8031013
 * Tarefa: EP01
 * Data: 05/09/2021
 * 
 *
 * DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESTE PROGRAMA.  TODAS AS 
 * PARTES DO PROGRAMA, EXCETO AS QUE SÃO BASEADAS EM MATERIAL FORNECIDO  
 * PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE SEDGEWICK & WAYNE, 
 * FORAM DESENVOLVIDAS POR MIM.  DECLARO TAMBÉM QUE SOU RESPONSÁVEL POR TODAS 
 * AS CÓPIAS DESTE PROGRAMA E QUE NÃO DISTRIBUÍ NEM FACILITEI A DISTRIBUIÇÃO
 * DE CÓPIAS DESTA PROGRAMA.
 *
 *
 ******************************************************************************/


public class Billiards {
    public static void main(String[] args) {
        double rx = 0;
        double ry = 0;
        double vx = 0;
  	double vy = 0;
        double dt = 0.5;
        double mass = 1.0;
        double drag = 0.05;    
        double resistanceStrength = -0.01;
	double radius = 0.03;
        
        // inicializa a mesa
        StdDraw.setPenColor(StdDraw.BLACK);
        StdDraw.enableDoubleBuffering();
        StdDraw.setScale(-1, +1);

        // faz a animação
        while (true) {
                
            // Limpa as forças
            double fx = 0;
            double fy = 0;
            
            // calcula o quadrado  distancia
            double dx = StdDraw.mouseX() - rx;
            double dy = StdDraw.mouseY() - ry;
	    double dist = dx*dx + dy*dy;

	    // se o mouse está pressionado o corpo ganha velocidade inversamente 
	    // proporcional ao quadrado distância
            if (StdDraw.isMousePressed()) {
                 vx += dx*resistanceStrength/dist;
                 vy += dy*resistanceStrength/dist;
            }

            // a força é
            fx += resistanceStrength * vx - drag * vx;
            fy += resistanceStrength * vy - drag * vy;
                      
	    // "segura" a bola dentro da mesa
            if (Math.abs(rx + vx * dt) > 1.0 - radius) vx = -vx;
	    if (Math.abs(ry + vy * dt) > 1.0 - radius) vy = -vy;
            
            // euler step: achando a próxima velocidade e posição
            vx += fx * dt / mass;
            vy += fy * dt / mass;
            rx += vx * dt; 
            ry += vy * dt; 
            
            
            
            StdDraw.clear();
            
            // desenha a bolinha
            StdDraw.filledCircle(rx, ry, radius);
            StdDraw.show();
            StdDraw.pause(10);
        }
    }
}
