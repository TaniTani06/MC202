#include<stdio.h>

int main(){

int HP_ryu;
int HP_ken;
int golpe;
int golpes_ryu = 0;
int golpes_ken = 0;

scanf("%d %d", &HP_ryu, &HP_ken);

while(1){
    scanf("%d", &golpe);
    if(golpe>0){
        golpes_ryu += 1;
        HP_ken -= golpe;
        if (HP_ken<0){
            HP_ken = 0;
        }
        printf("RYU APLICOU UM GOLPE: %d\n", golpe);
    }
    else{
        golpes_ken += 1;
        HP_ryu += golpe;
        if (HP_ryu<0){
            HP_ryu = 0;
        }
        printf("KEN APLICOU UM GOLPE: %d\n", -golpe);
    }
    printf("HP RYU = %d\nHP KEN = %d\n", HP_ryu, HP_ken);
    if (HP_ryu==0){
        printf("LUTADOR VENCEDOR: KEN\n");
        break;
    }
    if (HP_ken==0){
        printf("LUTADOR VENCEDOR: RYU\n");
        break;
    }
    }

printf("GOLPES RYU = %d\nGOLPES KEN = %d\n", golpes_ryu, golpes_ken);
}