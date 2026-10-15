#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 8
#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

void Print_Qsort(int list[], int pivot, int low, int high ){
    int i;
    for (int i = 0; i<MAX_SIZE; i++){
        if(list[i] == pivot) printf("\x1b[1m%-8d\x1b[0m", list[i]);
        else printf("%-8d", list[i]);
    }
    printf("\n");
    for (i = 0; i < MAX_SIZE; i++){
        if(i == low && i == high)
            printf("%-8s", "low/high");
        else if(i == low)
            printf("%-8s","low");
        else if(i == high)
            printf("%-8s", "high");
        else printf("%-8s", "");
    }
    printf("\n");
}

int partition(int list[MAX_SIZE], int left, int right){
    int pivot = list[left];
    int low = left;
    int high = right+1;
    int temp;

    while(low<high){
        do{
            low++;
        }while(low <= right && pivot > list[low]);
        do{
            high--;
        }while(pivot < list[high]);
        Print_Qsort(list, pivot, low, high);
        if (low<high) SWAP(list[low], list[high], temp);
    }
    SWAP(list[high], list[left], temp);
    Print_Qsort(list, pivot, low, high);
    return high;
}

void Quick_Sort(int list[MAX_SIZE], int left, int right, int passnum){

    if (left < right){
        passnum += 1;
        printf("PASS %d\n", passnum);
        int p = partition(list, left, right);
        Quick_Sort(list, left, p-1, passnum);
        Quick_Sort(list, p+1, right, passnum);
    }
}



int main(){
    int list[MAX_SIZE] = {67, 90, 57, 25, 84, 32, 73, 54};
    Quick_Sort(list, 0, MAX_SIZE-1, 0);
}