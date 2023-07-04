#include "the6.h"
// Don't add any additional includes

/*
  N: Number of racers
  updates: Updates you have heard
*/
std::pair<bool, std::vector<int>>
race(int N,std::vector<int> arr[],int on[]){
    std::pair<bool, std::vector<int>> arrr;
    std::queue<int> q;
    std::vector<int> ar;
    for(int i=0;i<N;i++){
        if(on[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr=q.front();
        ar.push_back(curr);
        q.pop();
        for(int node:arr[curr]){
            if(--on[node]==0){
                q.push(node);
            }
        }
    }
    arrr.first=true;
    arrr.second=ar;
    return arrr;
}
bool DFS(std::pair<bool, std::vector<int>> &arrr,std::vector<int> arr[],int v, bool vis[], bool *bbbb){
     if(vis[v] == false)
    {
        
        vis[v] = true;
        bbbb[v] = true;
        for(int node:arr[v])
        {
            if ( !vis[node] && DFS(arrr,arr,node, vis, bbbb) ){
                (arrr).second.push_back(node);
                return true;
            }
            else if (bbbb[node]){
                (arrr).second.push_back(node);
                return true;
            }
        }

    }
    bbbb[v] = false;  
    return false;
}

bool isdag(std::pair<bool, std::vector<int>> &arrr,int n,std::vector<int> arr[]){
    bool *vis = new bool[n];
    bool *bbbb = new bool[n];
    for(int i = 0; i < n; i++)
    {
        vis[i] = false;
        bbbb[i] = false;
    }
    for(int i = 0; i < n; i++)
        if (DFS(arrr,arr,i, vis, bbbb))
            return true;

    return false;
}
std::vector<int>
execute(std::pair<bool, std::vector<int>> arrr){
    std::vector<int> ar3;
    std::vector<int> ar4;
    int x;
    ar3.push_back(arrr.second[0]);
    x=arrr.second[0];
    for(long unsigned int i=1;i<arrr.second.size();i++){
        ar3.push_back(arrr.second[i]);
        if(arrr.second[i]==x){
            i=arrr.second.size();
            
        }
        
    }
    for(long unsigned int i=ar3.size()-1;i>0;i--){
        ar4.push_back(ar3[i]);
        
        
    }
    ar4.push_back(arrr.second[0]);
    return ar4;
}
std::pair<bool, std::vector<int>>
RaceResult(int N, std::vector<std::pair<int, int>> updates) {
    std::pair<bool, std::vector<int>> arrr;
    std::vector<int> ar;
    int on[100000];
    std::vector<int> arr[N+1];
    int i,n;
    n=updates.size();
    for(i=0;i<n;i++){
        arr[updates[i].first].push_back(updates[i].second);
        on[updates[i].second]++;
    }
    if(!isdag(arrr,N,arr)){
        arrr=race(N,arr,on);
    }
    else{
        isdag(arrr,N,arr);
        arrr.second=execute(arrr);
    }
    
  return arrr; // This is a dummy return value. YOU SHOULD CHANGE THIS!
}
