#include "the2.h"
//You may write your own helper functions here


int partition_quickSort_class(unsigned short* arr, long& swap, double& avg_dist, double& max_dist, int first, int last, int arrsize, int size) {
    unsigned short x = arr[last];
    int i = first - 1;
    int a;
    for (int j = 0; j < arrsize-2; j++) {
        if (arr[first+j] >= x) {
            i++;
            a = arr[i];
            arr[i] = arr[first+j];
            arr[first+j] = a;
            swap++;
        }
    }
    a = arr[i + 1];
    arr[i + 1] = arr[last];
    arr[last] = a;
    swap++;
    return i + 1-first;
}
void quickSort_class(unsigned short* arr, long& swap, double& avg_dist, double& max_dist, int first, int last, int arrsize, int size) {
    int p;
    if (arrsize > 1) {
        p = partition_quickSort_class(arr, swap, avg_dist, max_dist, first, last, arrsize, size);
        quickSort_class(arr, swap, avg_dist, max_dist, first, first + p , p, size);
        quickSort_class(arr, swap, avg_dist, max_dist, first + p+1, last, arrsize-p-1, size);
    }
}
int partition_quickSort_Hoare(unsigned short* arr, long &swap, double & avg_dist, double & max_dist,int first,int last,int arrsize, int size){
 
    int i=first-1;
    int j =arrsize;
    
}
void quickSort_Hoare(unsigned short* arr, long &swap, double & avg_dist, double & max_dist,int first,int last,int arrsize, int size){
    int p;
    if (arrsize > 1) {
        p=partition_quickSort_Hoare(arr, swap, avg_dist,max_dist,first,last,arrsize,size);
        quickSort_Hoare(arr,swap,avg_dist,max_dist,first,first+p-1,p,size);
        quickSort_Hoare(arr,swap,avg_dist,max_dist,first+p,last,arrsize-p-1,size);
    }
}
void quickSort(unsigned short* arr, long &swap, double & avg_dist, double & max_dist, bool hoare, int size)
{
    if(hoare==false){
        quickSort_class(arr,swap,avg_dist,max_dist,0,size-1,size,size);
    }
    if(hoare==true){
        quickSort_class(arr,swap,avg_dist,max_dist,0,size-1,size,size);
    }
    
}






void partition_quickSort33(unsigned short* arr, long& swap, long& comparison, int size, int& L, int& R, int first, int last, int arrsize) {
    int i = first;
    int j = first;
    int p = arrsize - 1;
    unsigned short a;
    while (i < p) {
        comparison++;
        if (arr[i] > arr[last]) {
            a = arr[i];
            arr[i] = arr[j];
            arr[j] = a;
            i++;
            j++;
            swap++;
        }
        else if (arr[i] == arr[last]) {
            
            p--;
            a = arr[i];
            arr[i] = arr[p];
            arr[p] = a;
            swap++;
        }
        else {
            
            i++;
        }
    }
    int m;
    if (p - j < arrsize - p) {
        
        m = p - j;
    }
    else {
        m = arrsize - p;
    }
    for (int v = 0; v < m; v++) {
        comparison++;
        a = arr[j + v];
        arr[j + v] = arr[arrsize - m + v];
        arr[arrsize - m + v] = a;
        swap++;
    }
    L = j;
    R =p - j;

}
void quickSort33(unsigned short* arr, long& swap, long& comparison, int size, int first, int last, int arrsize) {
    int L;
    int R;
    if (arrsize > 1) {
        partition_quickSort33(arr, swap, comparison, size, L, R, first, last, arrsize);
        quickSort33(arr, swap, comparison, size, first, first + L-1 , L);
        quickSort33(arr, swap, comparison, size, last - R-1, last, R);
    }
}
void quickSort3(unsigned short* arr, long& swap, long& comparison, int size) {
    quickSort33(arr, swap, comparison, size, 0, size - 1, size);
}