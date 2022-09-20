#include <stdlib.h>
#include <stdio.h>

//esse programa recebe notas n alunos com media de (prova1+prova2+prova3+prova4)/4 e imprime a media

/*
Um professor realizou quatro avaliações com seus alunos durante o semestre letivo. Ele
resolve que a média final de cada aluno será calculada por meio de média ponderada caso as notas
do aluno sejam distintas. Neste caso, a maior nota do aluno terá peso 4, a segunda maior nota
terá peso igual a 3, a terceira maior nota terá peso 2 e a quarta maior nota terá peso 1. Caso não
seja possível determinar uma nota maior entre todas e nem uma nota menor entre todas, então
todas as provas terão pelo 2,5. Caso seja possível determinar uma nota maior entre todas, mas
não uma nota menor entre todas, então a nota maior terá peso 4 e as demais notas peso 2. Caso
seja possível determinar uma nota menor entre todas, mas não uma nota maior entre todas, então
a nota menor terá peso 1 e as demais notas peso 3. Elabore um programa em C que receba o
número de alunos da turma e para cada aluno a sua matrícula e as quatro notas das suas avaliações
e calcule e exiba a média final de cada aluno, a média aritmética geral da turma, a maior média da
turma e a menor média da turma

O número de alunos da turma deve ser valor inteiro, maior do que zero e menor ou igual a 50

A nota de cada uma das quatro avaliações do aluno deve ser valor real, maior ou igual a 0 e menor do que 10,0, e ter uma precisão de uma casa decimal

As saídas do programa (média final do aluno, média geral da turma, maior média de turma e menor média da turma) devem ser valores reais com precisão de uma casa decimal
A primeira saída exibida será a média final do primeiro aluno, a segunda saída será a média final do segundo aluno e assim sucessivamente até o aluno n
Após a exibição das médias finais de cada aluno deve ser exibida a maior média final da turma e em seguida a menor média final da turma 

modelo de entrada 
5
9.0 5.0 3.0 7.0
5.0 5.0 3.0 4.0
6.0 6.0 7.0 7.0
7.0 8.0 5.0 5.0
6.0 6.0 6.0 6.0 

saida para o modelo 
7.0
4.5
6.5
6.6
6.0
6.1
7.0
4.5 


*/

//essa função faz alocação dinamica de um ponteiro de ponteiro criando uma matriz n x 4
float **aloca(float **a, int n) {
    int c;

    a=(float**)malloc(n*sizeof(float*));
    
    for(c=0; c<n; c++) {
        a[c]=(float*)malloc(4*sizeof(float));
    }
    return a;
}

//essa função deixa a memoria alocada disponivel para uso de outro programas
float **desaloca(float **a, int n){
    int c;
    for(c=0; c<n; c++){
        free(a[c]);
    }
    free(a);
    return a;
}

int main (void) {
    float **notas;
    int n, c, c2, c3;
    float media, b;
    float maior, menor, mm, mn;
    float total=0;
    float maiorg=0, menorg=10;

    //escaneria o numero de alunos
    scanf("%d", &n);
    
    //numero de alunos entre 0 < n < 50
    if(n>0 && n<=50) {
        //aloca as notas
        notas=aloca(notas, n);
        //faz o escaner das notas dos alunos
        for(c=0 ; c<n; c++){
            for(c2=0; c2<4; c2++){
                scanf("%f", &notas[c][c2]);
                //verifica se as notas estao 0<= n <=10, caso nao fecha o programa com mensagem de erro
                if(notas[c][c2]>=10 || notas[c][c2]<=0){
                    notas=desaloca(notas, n);
                    printf("erro\n");
                    exit(0);
                }
            }
        }
        //organiza as notas de cada aluno da maior para menor
        for(c=0; c<n; c++){
            for(c2=0; c2<4; c2++){
                for(c3=c2+1; c3<4; c3++){
                    if(notas[c][c2]<notas[c][c3]){
                        b=notas[c][c2];
                        notas[c][c2]=notas[c][c3];
                        notas[c][c3]=b;
                    }
                }
            }
        }


        for(c=0; c<n; c++) {
            maior=0;
            menor=10;
            mm=mn=0;
            for(c2=0; c2<4; c2++) {
                if(notas[c][c2]>maior){
                    maior=notas[c][c2];
                }
                if(notas[c][c2]<menor){
                    menor=notas[c][c2];
                }
            }
            //verica quntidade de notas maiores e menores 
            for(c3=0; c3<4; c3++){
                if(notas[c][c3]==menor){
                    mn++;
                }
                if(notas[c][c3]==maior) {
                    mm++;
                }
            }            
            //verifica as media de acordo com o comentario no inicio do programa
            if(mm==1 && mn==1) {
                media=((notas[c][0]*4)+(notas[c][1]*3)+(notas[c][2]*2)+(notas[c][3]))/10;
                printf("%.1f\n", media);
            }
            
            if((mm==4 && mn==4) || (mm==2 && mn==2)){
                media=((notas[c][0]*2.5)+(notas[c][1]*2.5)+(notas[c][2]*2.5)+(notas[c][3]*2.5))/10;
                printf("%.1f\n", media);
            }
            
            if(mm==1 && mn>1) {
                media=((notas[c][0]*4)+(notas[c][1]*2)+(notas[c][2]*2)+(notas[c][3]*2))/10;
                printf("%.1f\n", media);
            }
            
            if(mm>1 && mn==1) {
                media=((notas[c][0]*3)+(notas[c][1]*3)+(notas[c][2]*3)+(notas[c][3]*1))/10;
                printf("%.1f\n", media);
            }
            //soma todas as medias
            total+=media;

            if(maiorg<=media){
                maiorg=media;
            }  
            if(menorg>=media){
                menorg=media;
            }  

        }
        //Media geral da turma
        printf("%.1f\n", total/n);
        //Maior media da turma
        printf("%.1f\n", maiorg);
        //Menor media da turma
        printf("%.1f\n", menorg);

        notas=desaloca(notas, n);
    }
    else {
        printf("erro\n");
    }

    return 0;

}