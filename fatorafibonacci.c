#include <stdio.h>
//este programa acha o n-esimo de fibonacci e o imprime logo apos e fatora o resultado e imprime a fatoração


// acha o n-esimo resultado do fibonacci e retorna o mesmo
int fi(int n) {
    int c=0, c1=1, c2=1, c3;
    for(c=0; c<n-1; c++){
        c3=c1+c2;
        c1=c2;
        c2=c3;
    }
    printf("%d\n", c3);
    return c3;
}   

// fatora a entrada e imprime 
void fatoracao(int f){
    int c=0, c2=2;
    while(f!=1) {
        //verifica se e o primeiro fatoração se sim e se verifica se o numera e divisivel por c2 e imprime sem espaço
        if(f%c2==0  && c==0) {
            printf("%d", c2);
            c=1;
            f=f/c2;
        }
         //verifica se e o demais numeros fatoração se sim e se verifica se o numera e divisivel por c2 e imprime com espaço
        else if(f%c2==0  && c==1) {
            printf(" %d", c2);
            f=f/c2;
        }
        //caso o numero não seja divisivel pelo mesmo aumenta o c2 para um maior
        else {
            c2++;
        }
    }
    printf("\n");

}

//executa o codigo
int main(void) {
    int f, n;
    //escaneia o numero e aponta pra n
    scanf("%d", &n);
    if(n>=3 && n<=100) {
        f=fi(n);
        fatoracao(f);
    }

    else {
        printf("erro\n");
    }
    return 0;
}