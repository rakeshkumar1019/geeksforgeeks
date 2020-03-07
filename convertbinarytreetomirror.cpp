#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Node{
  public:
Node* left;
Node* right;
int data;
Node(int data){
  this->data=data;
  Node* left=NULL;
  Node* right=NULL;
}
};
void  pre(Node* root){
  if(root){
    cout<<root->data<<" ";
     pre(root->left);
     pre(root->right);
  }
}
void convertMirror(Node* root){
if(root==NULL){
  return;
}
convertMirror(root->left);
convertMirror(root->right);
Node* temp=root->left;
root->left=root->right;
root->right=temp;
}
int main(){
  Node* root=new Node(10);
  root->left=new Node(20);
  root->right=new Node(30);
  root->left->left=new Node(40);
  root->left->right=new Node(50);
  root->right->left=new Node(60);
  root->right->right=new Node(70);
  pre(root);
  cout<<endl;
  convertMirror(root);
  cout<<endl;
  pre(root);
}
