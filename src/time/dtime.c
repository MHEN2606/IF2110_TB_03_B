#include <stdio.h>
#include "time.h"

int main()
{
    TIME t,temp;
    int num;
    createTime(&t,12,12,12);
    printf("========================\n");
    printf("Waktu menunjukkan : ");
    displayTime(t);
    printf("Dalam format lain : ");
    displayTimeTitik(t);
    printf("Dalam detik : %d",timeToSecond(t));
    printf("\nDalam menit : %d",timeToMinute(t));
    printf("\nMasukkan waktu dalam detik : ");
    scanf("%d",&num);
    temp = secondToTime(num);
    printf("Dalam waktu menjadi : ");
    displayTime(temp);
    printf("Waktu ditambah 1 jam\n");
    temp = addTime(&temp, 3600);
    displayTime(temp);
    printf("Waktu dikurang 1 jam\n");
    temp = reduceTime(&temp, 3600);
    displayTime(temp);
    printf("========================\n");
    return 0;
}