#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
//#define NDEBUG
#include<assert.h>
using namespace std;

int binarySearch(int *arr, int start, int end, int target){
    //assert(start >= end);
    int mid = (start + end)>>1;
    if (target == arr[mid])
        return mid;
    //produce the special situation, dead cycle
    if (end == mid+1)
        if (arr[end] == target)
            return end;
        else
            return -1;
    if (target < arr[mid])
        end = mid;
    if (target > arr[mid])
        start = mid;
    return binarySearch(arr, start, end, target);
}

int binarySearch_iterator(int *arr, int start, int end, int target){
    int mid = (start + end)>>1;
    while(target != arr[mid]){
        if (target < arr[mid])
            end = mid;
        if (target > arr[mid])
            start = mid;
        mid = (start + end)>>1;
        if (mid+1 == end)
            if (arr[end] == target)
                return end;
            else
                return -1;
    }
    return mid;
}

int main(){
    int arg[3] = {1,2,3};
    int index = binarySearch(arg, 0, 2, 3);
    int index1 = binarySearch_iterator(arg, 0, 2, 3);
    cout<<index<<endl;
    cout<<index1<<endl;
    return 1;
}
