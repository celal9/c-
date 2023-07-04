#include "the4.h"

int max(int a, int b)
{
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int recursive_sln(int i, int*& arr, int &number_of_calls){ //direct recursive
    number_of_calls+=1;
    int x,y;
    if(i==0){
        return arr[0];
    }
    if(i==1){
        return max(arr[0],arr[1]);
    }
    if(i==2){
        return max(arr[2],max(arr[0],arr[1]));
    }
    x= recursive_sln(i-3,arr,number_of_calls)+arr[i];
    y= recursive_sln(i-1,arr,number_of_calls);
    return max(x,y); 
}



int memoization_sln(int i, int*& arr, int*& mem){ //memoization
    int x,y;
    if(i==0){
        mem[i]=arr[0];
        return arr[0];
    }
    if(i==1){
        mem[0]=arr[0];
        mem[i]=max(arr[0],arr[1]);
        return max(arr[0],arr[1]);
        
    }
    if(i==2){
        mem[0]=arr[0];
        mem[1]=max(arr[0],arr[1]);
        mem[i]=max(arr[2],max(arr[0],arr[1]));
        return max(arr[2],max(arr[0],arr[1]));
    }
    if((i>=3) && (mem[i-2]==-1))
        x=memoization_sln(i-3,arr,mem)+arr[i];
    else
        x=mem[i-3]+arr[i];
    if((i>=3) && (mem[i-1]==-1))
        y=memoization_sln(i-1,arr,mem);
    else
        y=mem[i-1];
    mem[i]=max(x,y);
    return mem[i]; // this is a dummy return value. YOU SHOULD CHANGE THIS!
}



int dp_sln(int size, int*& arr, int*& mem){ //dynamic programming
    
    int k=3;
    mem[0] = max(0, arr[0]);
    int i = 1;
    while (i < k) {
        mem[i] = max(mem[i - 1], arr[i]);
        i++;
    }
    i = k;
    while (i < size) {
        mem[i] = max(mem[i - 1], arr[i] + mem[i - k]);
        i++;
    }
    return mem[size - 1];

    
}

