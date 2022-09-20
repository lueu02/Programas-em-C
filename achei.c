#include <stdio.h> 
//esse programa recebe n numeros e m numeros e verifica se o esta em m esta em n

int main(void) {
    
    int N[100000];
    int M[1000];
    int n, m, i, i2, v=0;
    
    //escaneia n 
    scanf("%i", &n);
    //escaneia n numeros
    for(i=1; i<=n; i++) {
        scanf("%i", &N[i]);
    }
    
    //escaneia m
    scanf("%i", &m);
    
    //escaneia m numeros
    for(i2=1; i2<=m; i2++) {
        scanf("%i", &M[i2]);
    }
    
    //procura se algum do n numeros esta em m 
    for(i=1; i<=m; i++) {
        for (i2=1; i2<=n; i2++) {
            if (N[i2]==M[i]) {
                v=1;
                break;
            }
        }
        if(v==1) {
            printf("ACHEI\n");
        }
        else {
            printf("NAO ACHEI\n");
        }
        v=0;
    }
    
    return 0;
}