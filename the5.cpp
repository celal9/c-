#include "the5.h"
// do not add extra libraries here

/*
W: the width of the field
L: the length of the field
partitions: 2D Boolean array for partitions, if a partition of w x l exists then partitions[x][y] is true.
numberOfCalls/numberOfIterations: method specific control parameter
*/

int recursiveMethod(int W, int L, bool** partitions, int* numberOfCalls){
	int i,b,b1,b2,x=0,z,y;
	(*numberOfCalls)++;
	if(partitions[W][L]==true)
	    return 0;
	else{
	b=W*L;
	b1=W*L;
	b2=W*L;
	for(i=1;i<=W/2;i++){
	    y=recursiveMethod(W-i,L,partitions,numberOfCalls)+recursiveMethod(i,L,partitions,numberOfCalls);
	    if(b1>y)
	        b1=y;
	}
	for(i=1;i<=L/2;i++){
	    z=recursiveMethod(W,L-i,partitions,numberOfCalls)+recursiveMethod(W,i,partitions,numberOfCalls);
	    if(b1>z)
	        b2=z;
	}
	b=std::min(b,std::min(b1,b2));
	}
	return b; 
}
int memMethod(int W, int L, bool** partitions, int* numberOfCalls,int**& mem){
    int i,b,b1,b2,x=0,z,y;
	(*numberOfCalls)++;
	if(partitions[W][L]==true)
	    return 0;
	else if(mem[W][L]!=-1){
	    return mem[W][L];
	}
	else{
	b=W*L;
	b1=W*L;
	b2=W*L;
	for(i=1;i<=W/2;i++){
	        y=memMethod(W-i,L,partitions,numberOfCalls,mem)+memMethod(i,L,partitions,numberOfCalls,mem);
	        if(b1>y)
	            b1=y;
	    
	}
	for(i=1;i<=L/2;i++){   
	        z=memMethod(W,L-i,partitions,numberOfCalls,mem)+memMethod(W,i,partitions,numberOfCalls,mem);
	        if(b1>z)
	            b2=z;
	}
	mem[W][L]=std::min(b,std::min(b1,b2));
	}
	return mem[W][L];
}
int memoizationMethod(int W, int L, bool** partitions, int* numberOfCalls){
    	(*numberOfCalls)++;

    int** mem = new int*[W+1];
	for(int i = 0; i < W+1; i++){
		mem[i] = new int[L+1];
		for (int j = 0; j < L+1; j++){
			mem[i][j] = -1;
		}
	}
	return memMethod(W,L,partitions,numberOfCalls,mem); 
}

int bottomUpMethod(int W, int L, bool** partitions, int* numberOfIterations){
    int a,i,b1,b2,b3;
    int** mem = new int*[W+1];
	for(int i = 0; i < W+1; i++){
		mem[i] = new int[L+1];
		for (int j = 0; j < L+1; j++){
			mem[i][j] = W*L;
		}
	}
	for(int i=1;i<=W;i++){
	    for(int a=1;a<=L;a++){
	        
            (*numberOfIterations)++;
	        if(partitions[i][a]==true){
                b1=0;
                (*numberOfIterations)=(*numberOfIterations)-2;
	        }
            for(int y=1;y<=W/2;y++){
                (*numberOfIterations)++;
            }
            for(int z=1;z<=L/2;z++){
                (*numberOfIterations)++;
            }
        }
    }

	
	
	return 0;
}





















