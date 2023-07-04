#include "the1.h"
void sillySorthelper(int* arr,int local, long &comparison, long & swap, int size,int & number){
    number++;
	if(size==2){
	    comparison++;
	    if(arr[local]>arr[local+1]){
	        int a;
	        a=arr[local];
	        arr[local]=arr[local+1];
	        arr[local+1]=a;
	        swap++;
	    }
	}
	if(size>=4){
	    sillySorthelper(arr,local,comparison,swap,size/2,number);
	    sillySorthelper(arr,local+size/4,comparison,swap,size/2,number);
	    sillySorthelper(arr,local+size/2,comparison,swap,size/2,number);
	    sillySorthelper(arr,local,comparison,swap,size/2,number);
	    sillySorthelper(arr,local+size/4,comparison,swap,size/2,number);
	    sillySorthelper(arr,local,comparison,swap,size/2,number);
	}
}
void merge(int qodd, int qeven, int size){
    
}
void crossMergeSorthelper(int *arr,int local, long & comparison, int size){
    if(size==2){
	    
	    if(arr[0]>arr[1]){
	        int a;
	        a=arr[0];
	        arr[0]=arr[1];
	        arr[1]=a;
	        comparison++;
	    }
	}
	if(size>=4){
	    int i;
	    int q1[size/4],q2[size/4],q3[size/4],q4[size/4];
	    for(i=0;i<size;i++){
	        if(i<size/4){
	            q1[i]=arr[i];
	            
	        }
	        if(size/4<=i<size/2){
	            q2[i-size/4]=arr[i];
	        }
	        if(size/2<=i<3*size/4){
	            q3[i-size/2]=arr[i];
	        }
	        if(3*size/4<=i<size){
	            q4[i-3*size/4]=arr[i];
	        }
            	        
	    }
	    	}
}
int sillySort(int* arr, long & comparison, long & swap, int size) 
{   
    int num_of_calls;
    int number=0;
    int local;
    local =0;
    sillySorthelper(arr,local,comparison,swap,size,number);
    num_of_calls=number;
	return num_of_calls;
}
int crossMergeSort(int *arr, long & comparison, int size)
{
	
	int num_of_calls=1;
	int local=0;
	crossMergeSorthelper(arr,local,comparison,size);
	
	return num_of_calls;
	
}