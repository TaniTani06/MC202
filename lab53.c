#include <stdio.h>

int num;
int freq;
char car;
int i;
char null;

int main() {
    while(1){
    scanf("%c %d %c %d %c %c %c", &null, &num, &null, &freq, &null, &car, &null);
    printf("%d |", num);
    for (i=0; i<freq; i++)
        printf("%c", car);
    printf(" %d\n", freq);
    }
}