#include <stdio.h>
 
//este programa calcula a rendimento  de acordo com os anos
int main(void) {
    double valor, taxa, taxaad;
    int anos, c;
    double bruto=0, j;
    
    //escaneia o valor digitado pelo usuario e aponta para a variavel valor
    scanf("%lf", &valor);
    //verifica se valor e um numero valido
    if(valor>0) {
        //escaneia o numero de anos e aponta o valor para variavel anos
        scanf("%d", &anos);
        //verifica se anos e um valor valido
        if(anos>0){
            //escaneia a porcentagen taxa de juros
            scanf("%lf", &taxa);
            
            //verifica se a taxa esta entre 0% a 100%
            if(taxa>0 && taxa<100) {
                //escaneneia a taxa a administrativa do banco 
                scanf("%lf", &taxaad);
                //verifica se a taxa administrativa esta entre 0% a 100%
                if(taxaad>0 && taxaad<100) {
                    //calcula e imprime o o valar que esta na conta de acordo com tempo
                    for(c=1; c<=anos; c++) {
                        bruto=(valor*taxa)/100;
                        j=(bruto*taxaad)/100;
                        valor=valor+bruto-j;
 
                        printf("%.2lf\n", valor);
                    }
                }
                
                else {
                    printf("erro\n");
                }
            }
           
            else {
                printf("erro\n");
            }
        }
       
        else {
            printf("erro\n");
        }
    }
    else {
        printf("erro\n");
    }
}