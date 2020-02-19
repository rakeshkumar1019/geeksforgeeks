Given a Binary Tree, find diameter of it.
+The diameter of a tree is the number of nodes on the longest path between two leaves in the tree. The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).



Input Format:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:
  
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output Format:
For each testcase, in a new line, print the diameter.

Your Task:
You need to complete the function diameter() that takes node as parameter and returns the diameter.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
1 <= Data of a node <= 100

Example:
Input:
2
1 2 3
10 20 30 40 60 

Output:
3
4

Explanation:
Testcase1: The tree is
        1
     /      \
   2        3
The diameter is of 3 length.
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
The diameter is of 4 length.

Note: The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.




===================================================================================
//creating function to count height
int height(Node * node){
    if(node==NULL){
        return 0;
    }
    int res1=height(node->left)+1;
    int res2=height(node->right)+1;
    int res=max(res1,res2);
    return res;
    
}
/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node)
{
    if(node==NULL){
        return 0;
    }
   // three possible ans 
   //left height+right height
   int opt1=height(node->left)+height(node->right)+1;
   //left diameter
   int opt2=diameter(node->left);
   //right diameter
   int opt3=diameter(node->right);
   int ans=max(opt1,max(opt2,opt3));
   return ans;
}
