#include<iostream>
//#define NDEBUG
#include<assert.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int choose_pivot(int i, int j){
    return (i+j)/2;
}

int quickSort(int arr[], int low, int high){
    assert(low < high);
    int mid = choose_pivot(low, high);
    int pivot = arr[mid];
    int small=0, big=0;

    for(int i=low; i<mid; i++){
        if (arr[i] < arr[mid]) i++;
        small = i;
    }
    for(int j=high; j>mid; j--){
        if (arr[j] > arr[mid]) j--;
        big = i;
    }
    swap(&arr[small], &arr[big]);
}

int binarySearch(int * arr, int len, int target){
    
}

int main(){
    int arg[10] = {43, 23, 5, 7, 12, 87, 12, 209, 324, 10};
    int a = 10;
    int b = 4;
    swap(&a, &b);
    cout<<choose_pivot(5,9);
    cout<<a<<" "<<b<<endl;
    cout<<"asdfas"<<endl;
    return 1;
}
