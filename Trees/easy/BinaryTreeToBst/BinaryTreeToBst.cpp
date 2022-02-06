

//https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1#

//Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
//
//
//Example 1:
//
//Input:
//      1
//    /   \
//   2     3
//Output: 1 2 3
//
//Example 2:
//
//Input:
//          1
//       /    \
//     2       3
//   /
// 4
//Output: 1 2 3 4
//Explanation:
//The converted BST will be
//
//        3
//      /   \
//    2     4
//  /
// 1
//
//
//Your Task:
//You don't need to read input or print anything. Your task is to complete the function binaryTreeToBST() which takes the root of the Binary tree as input and returns the root of the BST. The driver code will print inorder traversal of the converted BST.
//
//
//Expected Time Complexity: O(NLogN).
//Expected Auxiliary Space: O(N).
//
//
//Constraints:
//1 <= Number of nodes <= 1000





Node*BST(Node* root,vector<int>ans,int&j){
       if(root==NULL)return(NULL);
       BST(root->left,ans,j);
       root->data=ans[j++];
       BST(root->right,ans,j);
       return root;
   }
   Node *binaryTreeToBST (Node *root)
   {
       //Your code goes here
       vector<int>ans;
       queue<Node*>q;
       q.push(root);
       while(!q.empty()){
           int c=q.size();
           while(c-->0){
               Node*t=q.front();
               q.pop();
               ans.push_back(t->data);
               if(t->left!=NULL)q.push(t->left);
               if(t->right!=NULL)q.push(t->right);
           }
       }
       sort(ans.begin(),ans.end());
       int j=0;
      return BST(root,ans,j);
   }
   

//-------------------------------------------------------------------------------------------

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).

TO SOLVE THE PROBLEM YOU CAN FOLLOW THE FOLLOWING APPROACH:

Use the property of the inorder traversal of BST
Take a vector/array store the inorder of the BT in it
Sort the vector/array
The sorted data is nothing but the inorder traversal of BST
Generate the BST from its inorder traversal by simply just replacing the values of the tree with the new values of inorder of BST
CODE:

void inorder_of_tree(Node* root,vector<int>&v){
       if(!root) return;
       inorder_of_tree(root->left,v);
       v.push_back(root->data);
       inorder_of_tree(root->right,v);
   }
  void inorder_bst(Node* root,vector<int>v,int &i){
       if(!root) return;
       inorder_bst(root->left,v,i);
       root->data=v[i++];
       inorder_bst(root->right,v,i);
       // return root;
   }
   Node *binaryTreeToBST (Node *root)
   {
       //Your code goes here
       vector<int>v;
       int i=0;
       inorder_of_tree(root,v);
       sort(v.begin(),v.end());
       inorder_bst(root,v,i);
       return root;
   }	   