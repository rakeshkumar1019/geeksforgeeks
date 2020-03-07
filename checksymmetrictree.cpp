#include<iostream>
#include<bits/stdc++.h>
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

void pre(Node* root){
  if(root){
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
  }
}

bool  getmirror(Node* root1,Node* root2){
  if(root1==NULL && root2==NULL){
    return true;
  }
  if(root1->data==root2->data && root1 && root2){
      return getmirror(root1->left,root2->right)&& getmirror(root1->right,root2->left);
  }
  return false;

}
//check if the tree is symmetric
bool checkSymmetric(Node* root){
  return getmirror(root,root);
}
int main(){
  Node * root=new Node(10);
  root->left=new Node(20);
  root->right=new Node(20);
  root->left->left=new Node(40);
  root->left->right=new Node(50);
  root->right->left=new Node(50);
  root->right->right=new Node(40);
  pre(root);
  cout<<endl;
  (checkSymmetric(root))?cout<<"symmetric"<<endl:cout<<"non symmetric"<<endl;

}
