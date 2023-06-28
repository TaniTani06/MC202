#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*O código recebe uma entrada cuja primeira linha é contém o número de linhas e de colunas de uma
matriz, e as linhas seguintes são os elementos dessa matriz. O código deve encontrar a distância
entre o número 3 e algum número 0, passando apenas por números 1*/

typedef struct quarter{
    int type;
    char marked;
    int d;
}quarter;



int main(void){
    int s = 0, m, n, i, first = 0, last = 1, u, v, *Q;
    quarter *V;

    scanf("%d %d\n", &n, &m);
    V = malloc(m*n*sizeof(quarter));
    Q = malloc(m*n*sizeof(int));   //talvez 2m dê problema, testar com m*n se necessario

    /*Coloca os elementos da matriz num vetor, sequencialmente.
    Os quarteirões vizinhos de i tem índices i-m, i-1, i+1 e i+m */
    for (i=0; i<m*n; i++){
        scanf("%d", &V[i].type);
        V[i].marked = 'f';
        V[i].d = -1;

        if(V[i].type == 3){
            s = i;
        }
    }


    V[s].d = 0;
    V[s].marked = 't';
    Q[first] = s;
    
    while(first != last){
        u = Q[first];
        first++;

        v = u-m;
        for(i=0; i<4; i++){
            if(v<m*n && v>=0){
                if(V[v].marked == 'f'){
                    if(V[v].type != 2){
                        V[v].d = V[u].d + 1;
                        Q[last] = v;
                        last++;
                    }
                    V[v].marked = 't';

                    if(V[v].type == 0){
                        printf("%d\n", V[v].d);
                        free(V);
                        free(Q);
                        return 0;
                    }
                }
            }
            
            if(v == u-m){
                v = u-1;
                if (u%m == 0){
                    v = u+1;
                }
            }
            else if(v == u-1){
                v = u+1;
                if (u%m == m-1){
                    v = u+m;
                }
            }
            else if(v == u+1){
                v = u+m;
            }
        }
    }
}