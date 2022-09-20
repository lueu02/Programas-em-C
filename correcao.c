#include <stdio.h>
#include <stdlib.h>
 
// estrutura de dados que indica o canditado
typedef struct Concurso{
    //indica numero de questoes
    int inscricao;
    //50 numero max de questões
    char questoes[50];
    //indica o numero de questões corretas
    int corretas;
}concurso;
 
//algoritimo do quick sort
void quick(concurso vet[], int esq, int dir){
    //esc e o inicio do vetor do concurso e dir o final
    //pivo definido como inicio 
    int pivo = esq, i,j;  
    //ch variavel auxiliar para editar quando achar um valor maior
    concurso ch;   
    //percorre o vetor procurando valoraes mairores    
    for(i=esq+1;i<=dir;i++){        
        j = i;
        //identifica se ordem esta correta caso nao a Corrige                  
        if(vet[j].corretas > vet[pivo].corretas){     
            ch = vet[j];               
            while(j > pivo){           
                vet[j] = vet[j-1];      
                j--;                    
            }
            vet[j] = ch;               
            pivo++;                    
        }
    }
    if(pivo-1 >= esq){              
        quick(vet,esq,pivo-1);      
    }
    if(pivo+1 <= dir){              
        quick(vet,pivo+1,dir);      
    }
 }
 
int main(void){
    int n, m, contador, contador2;
    char gabarito[50];
    concurso *candidatos;
    
    //leitura dos canditos sendo n o numero de candidatos
    scanf("%d", &n);
    //verificação se o numero de candidatos esta correto, caso não emite mensagem de erro
    if(n>=1 && n<=1000){
        //leitura do numero de questoes sendo m o numero de questoes//caso nao emite mensagem de erro 
        scanf("%d", &m);
        //verifica o numero de questoes esta correto 
        if(m>=1 && m<=50){
            //letura do gabarito
            for(contador=0; contador<m; contador++){
                scanf("%s", &gabarito[contador]);
            }
 
            //aloca o numero de candidatos
            candidatos=(concurso*)malloc(n*sizeof(concurso));
            
            //leitura do gabarito dos canditos colocando o numero inscriçao e verificando se as questoẽs esta corretas
            for(contador=0; contador<n; contador++){
                // define a inscreção
                candidatos[contador].inscricao = (contador+1);
                //da incio a correção
                candidatos[contador].corretas=0;
                for(contador2=0; contador2<m; contador2++){
                    //leitura do gabarito do candidato
                    scanf("%s", &candidatos[contador].questoes[contador2]);
                    //verifica a resposta do candidato com o gabarito
                    if(gabarito[contador2]==candidatos[contador].questoes[contador2]){
                        candidatos[contador].corretas++;
                    }
                }
            }
            //utiliza quick sort para organizar em ordem decrescente como o vetor inicia em 0 sendo 0 um digito valido lodo n-1 para o vetor e igaul numero de digitos n
            quick(candidatos, 0, n-1);
            
            //print a inscricao e quandita de questões
            for(contador=0; contador<n; contador++){
                printf("%d %d\n", candidatos[contador].inscricao, candidatos[contador].corretas);
            }
        }
        else {
            //mensagem de erro
            printf("erro\n");
        }
    }
    else {
         //mensagem de erro
        printf("erro\n");
    }
    //remove memoria alocada
    free(candidatos);
 
 
    return 0;
}