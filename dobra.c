#include <stdio.h>
#include <stdlib.h>
#include "unistd.h"
#include <time.h>

//Metodo da Dobra recursivo
//Numero usado nos exemplos: 813459
int dobra(int end){
  if(end >= 1000000){printf("O numero tem mais de 6 digitos!!\n"); return -1;}
  if(end<100 && end>9) return end;//Caso base: numero de dois digitos(menor que 100 e maior que 9).

  int fold = end/100;//tira os dois ultimos digitos(8134)

  int ultimo = end%10;//pega o ultimo digito(9)
  int penultimo =(end%100)/10;//pega o penultimo digito(5)

  int somar = (fold/100) * 100;//tira os ultimos dois digitos do numero novo(8100)
  int proximaParte = fold - somar;//pega os dois ultimos digitos do numero novo(34)

  int proxUltimo = proximaParte%10;//pega o ultimo digito(4)
  int proxPenultimo = proximaParte/10;//pega o penultimo digito(3)

  int ultpenult = (ultimo + proxPenultimo)%10;//soma os valores e ignora o "vai um"(9+3 = 12 %10 = 2)
  int penultult = (penultimo + proxUltimo)%10;//soma os valores e ignora o "vai um"(5+4 = 9 % 10 = 9)

  int novoEnd = somar + (ultpenult * 10) + penultult;//soma e gera o novo numero apos a dobra(8129)
  dobra(novoEnd);//chama a função de novo :)
}

int main(){
  srand(time(NULL));
  int end =0;
  int i = 0;
  while(i <= 12){
    int endBefore = rand()%1000000;
    end = dobra(endBefore);
    if(end<0){printf("Saindo do programa\n"); return 0;}
    printf("O endereco era %d e se tornou %d\n",endBefore, end);
    i++;
  }
  return 0;
}
