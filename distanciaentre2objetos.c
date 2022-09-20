#include <stdio.h>


//este programa recebe distancia 2 velocidades uma em sentido e outro no sentido contrario e calcula o ponto onde os objetos se cruzam e o tempo
int main (void){
    double distancia;
    double velc1, velc2;
    double tempo, encontro;
    
    //recebe distancia entre os 2 objetos
    scanf("%lf", &distancia);
    //verifica se a distancia e um valor maior que 0
    if(distancia>0){
        //recebe a velocidade do primeiro objetos
        scanf("%lf", &velc1);
        //verifica se a velocidade do primeiro objeto e maior que 0 e um valor maior que 0
        if(velc1>0) {
            //recebe a velocidade do segundo objeto            
            scanf("%lf", &velc2);
             //verifica se a velocidade do segundo objeto o e maior que 0 e um valor maior que 0
            if(velc2>0){
                //calcula o tempo
                tempo=distancia/(velc1+velc2);
                //calcula a distancia
                encontro=velc1*tempo;
 
                printf("%.2lf\n", tempo);
                printf("%.1lf\n", encontro);
            }
            else {
                printf("erro\n");
            }
        }
        else{
            printf("erro\n");
        }
 
    }
    else {
        printf("erro\n");
    }
 
 
    return 0;
}