//this program is for vertical level ordered tree  traversal
//complexity O(nlogn)
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<map>
using namespace std;
class Node{
public:
int data;
Node* left;
Node* right;
Node(int data){
  this->data=data;
  Node* left=NULL;
  Node* right=NULL;
}
};
void preorderedTraversal(Node* root){
  if(root){
    cout<<root->data<<" ";
    preorderedTraversal(root->left);
    preorderedTraversal(root->right);
  }
}
void getverticalTreaversal(Node* root,int root_distance,map<int ,vector<int >>& ma){

  if(root==NULL){
    return ;
  }
  ma[root_distance].push_back(root->data);
  getverticalTreaversal(root->left,root_distance-1,ma);
  getverticalTreaversal(root->right,root_distance+1,ma);

}
void verticalOrderedTreeTraversal(Node* root){
//map of key=distance and value= list of node(some node may have some key so list) 
map<int,vector<int>>ma;
int root_distance=0;
getverticalTreaversal(root,root_distance,ma);
//map itrator to print
map< int,vector<int> > :: iterator it;
for(it=ma.begin();it!=ma.end();it++){
for(int i=0;i<it->second.size();i++){
  cout<<it->second[i]<<" ";
}
// cout<<endl;
}

}
int main(){
  Node* root=new Node(10);
  root->left=new Node(20);
  root->right=new Node(30);
  root->left->left=new Node(40);
  root->left->right=new Node(50);
  root->right->left=new Node(60);
  root->right->right=new Node(70);
  root->right->right->left=new Node(80);
  root->right->right->right=new Node(90);
  preorderedTraversal(root);
  cout<<endl;
  verticalOrderedTreeTraversal(root);

}
