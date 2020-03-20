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
   
   int distance(int src,int d,int size){
     bool* visited=new bool[size+1];
     int* dist=new int[size+1];
     for(int i=0;i<=size;i++){
       visited[i]=false;
       dist[i]=0;
     }
     queue<int>q;
     q.push(src);
     visited[src]=true;
     while(!q.empty()){
       int parent=q.front();
       q.pop();
       for(auto x:AdjacentList[parent]){
         if(!visited[x]){
           q.push(x);
           visited[x]=true;
           dist[x]=dist[parent]+1;
         }
       }

     }
     return dist[d];

   }

   void path(int src,int d,int size){
     bool* visited=new bool[size+1];
     int* par=new int[size+1];
     for(int i=0;i<=size;i++){
       visited[i]=false;
       par[i]=-1;
     }
     queue<int> q;
     q.push(src);
     visited[src]=true;
     while(!q.empty()){
       int parent=q.front();
       q.pop();
       for(auto x:AdjacentList[parent]){
         if(!visited[x]){
           par[x]=parent;
           q.push(x);
           visited[x]=true;
         }
       }
     }
     cout<<d<<" ";
     while(d!=-1){
       d=par[d];
       cout<<d<<" ";
     }



   }


};
int main(){
  Graph g(50);
   int moves[50];
   for(int i=0;i<50;i++){
     moves[i]=0;
   }
    moves[2] = 13; 
    moves[5] = 2; 
    moves[9] = 18; 
    moves[18] = 11;
    moves[17] = -13; 
    moves[20] = -14; 
    moves[24] = -8; 
    moves[25] = -10; 
     moves[32] = -2; 
    moves[34] = -22; 
    
    for(int u=0;u<36;u++){
      for(int dice=1;dice<=6;dice++){
        int v=u+dice+moves[u+dice];
        g.addEdge(u,v,false);
      }
    }

   cout<<"using bfs for dist and path in snake ladder game"<<endl;
   cout<<"here -1 means root(parent node parent)"<<endl;
    cout<<g.distance(1,36,50)<<endl;
    g.path(1,36,50);
    
   return 0;

}
