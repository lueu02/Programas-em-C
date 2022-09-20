#include <stdio.h>


//esta função verifica se o numero e primo se sim retorna 1 e se nao retorna 0
int primos (int n) {
    int c, p=0;
    
    for(c=1; c<=n/2; c++){
        if(n%c==0) {
            p++;
        }
        if(p>1) {
            return 0;
        }
    }
    return 1;
}
 
//este programa recebe o um numero n e calcular os n primeros numeros primos sendo 0 < n < 1000 
int main(void){
    int c=0, n, c2=1;
    int total=0;
    
    //escaneia o numero e aponto no resulta para variavel n
    scanf("%d", &n);
    
    //verifica se 0 < n < 1000 
    if(n>0 && n<1000){
        while(c<n) {
            //contador para verificar se primo
            c2++;
            if(primos(c2)==1){
                total+=c2;
                //quando acha um numero primo aumento outro contador c para conta numero de primos encontrados
                c++;
            }
 
        }
        
        //imprime valor total da soma dos primos
        printf("%d\n", total);
    }
    else {
        printf("erro\n");
    }
 
    return 0;
}