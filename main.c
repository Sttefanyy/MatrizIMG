/* 
Insira uma descrição do problema
*/
#include <stdio.h>
#include "libs/libbmp.h"
#include "libs/imghelpers.h"

int main(){
  bmp_img img;
  char filename[] = "lenna.bmp";
  printf("\n");
  IMG_TAM t = pegarTamanho(filename);
  int l = t.qtdLinhas,c = t.qtdColunas;
  int R[l][c];
  int G[l][c];
  int B[l][c];
  carregaImagem(t,R,G,B,filename);
  
 int resultR[l][c];
 int resultG[l][c];
 int resultB[l][c];


    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            resultR[i][j] = 0;
            resultG[i][j] = 0;
            resultB[i][j] = 0;
        }
    }

   for (int i = 20; i < l - 20; i++) {
        for (int j = 20; j < c - 20; j++) {
           if (i < j) {
                resultR[i][j] = R[i][j] + 70;
                resultG[i][j] = G[i][j] + 70;
                resultB[i][j] = B[i][j] + 70;
            }else{
            resultR[i][j] = R[i][j];
            resultG[i][j] = G[i][j];
            resultB[i][j] = B[i][j];
           }
        }
    }

  char filename2[] = "saida.bmp";
  printf("\n");
  IMG_TAM t2 = pegarTamanho(filename2);
  int l2 = t2.qtdLinhas,c2 = t2.qtdColunas;
  int R2[l2][c2];
  int G2[l2][c2];
  int B2[l2][c2];
  carregaImagem(t2,R2,G2,B2,filename2);
  
 int resultR2[l2][c2];
 int resultG2[l2][c2];
 int resultB2[l2][c2];

  for (int i = 0; i < l2; i++) {
        for (int j = 0; j < c2; j++) {
            resultR2[i][j] = R2[i][c2 - 1 - j];
            resultG2[i][j] = G2[i][c2 - 1 - j];
            resultB2[i][j] = B2[i][c2 - 1 - j];
        }
    }
   salvaImagem(t2,resultR2,resultG2,resultB2,"saidainvertida.bmp");
   mostrarNoReplit("saida_invertida.bmp");
  
  return 0;
}