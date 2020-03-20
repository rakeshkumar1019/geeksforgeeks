#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<map>
#include<vector>
using namespace std;

class Graph{
  public:
  int v;
    vector<int>* AdjacentList;
  Graph(int v){
    int V=v;
    AdjacentList=new vector<int>[V];
  }
  void addEdge(int u,int v,bool bidir=true){
    AdjacentList[u].push_back(v);
    if(bidir){
       AdjacentList[v].push_back(u);
    }
  }
  void BFSHelper(int src,bool* visited,int v){
    queue<int> q;
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
      int index=q.front();
      cout<<index<<" ";
      q.pop();
      for(auto x:AdjacentList[index]){
        if(!visited[x]){
        q.push(x);
        visited[x]=true;
        }
      }
    }
  }

  void BFS(int v1){
    bool* visited=new bool[v1+1];
    for(int i=0;i<=v1;i++){
      visited[i]=false;
    }
    for(int i=1;i<=v1;i++){
      if(!visited[i]){
        BFSHelper(i,visited,v1);
        cout<<endl;
      }
    }

    
  }
  void DFSHelper(int src,bool* visited,int v1){
   stack<int> s;
   s.push(src);
   while(!s.empty()){
     int index=s.top();
     s.pop();
     if(!visited[index]){
         cout<<index<<" ";
         visited[index]=true;
     }
     for(auto x:AdjacentList[index]){
       if(!visited[x]){
         s.push(x);
       }
     }
     
   } 

  }
  
  void DFS(int v1){
    bool* visited=new bool[v1+1];
    for(int i=0;i<=v1;i++){
      visited[i]=false;
    }

    for(int i=1;i<=v1;i++){
      if(!visited[i]){
        DFSHelper(i,visited,v1);
        cout<<endl;
      }
    }
  }


};
int main(){
  Graph g(12); 
    g.addEdge(1, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 4); 
    g.addEdge(2, 5); 
    g.addEdge(3, 5); 
    g.addEdge(4, 6);
    g.addEdge(4, 5);
    g.addEdge(5, 6); 
      //  g.addEdge(6, 7); 
    g.addEdge(7, 8); 
    g.addEdge(7, 9); 
    g.addEdge(9, 8); 
    g.BFS(9);
    g.DFS(9);
}
