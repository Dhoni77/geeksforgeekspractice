 //https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1

//Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.
//
//Example 1:
//
//Input:
//             10
//          /      \
//        -2        6
//       /   \     /  \
//     8     -4   7    5
//
//Output:
//            20
//          /    \
//        4        12
//       /  \     /  \
//     0     0   0    0
//
//Explanation:
//
//           (4-2+12+6)
//          /           \
//      (8-4)          (7+5)
//       /   \         /  \
//      0     0       0    0
//
//
//
//Your Task:
//You dont need to read input or print anything. Complete the function toSumTree() which takes root node as input parameter and modifies the given tree in-place.
//
//Note: If you click on Compile and Test the output will be the in-order traversal of the modified tree.
//
//
//Expected Time Complexity: O(N)
//Expected Auxiliary Space: O(height of tree)
//
//
//Constraints:
//1 ≤ N ≤ 104
 
 void sum(Node * node,int &count)
   {
       if(!node) 
       {
           return;
       }
       
       sum(node->left,count);
       sum(node->right,count);
      count+=node->data;
   }
   void toSumTree(Node *node)
   {
       // Your code here
       int count = 0;
       queue<Node*>q;
       q.push(node);
       while(!q.empty())
       {
           Node * temp = q.front();
           q.pop();
           sum(temp,count);
           temp->data = count -temp->data;
           count = 0;
           if(temp->left != NULL)q.push(temp->left);
           if(temp->right != NULL)q.push(temp->right);
       }
   }

//-------------------------------------------------------------------

 int helper(Node* node){
        if(node == NULL)
            return 0;
            
        int left = helper(node->left);
        int right = helper(node->right);
        int temp = node->data;
        
        if(left == 0 && right == 0){
            node->data = 0;
            return temp;
        }
        else {
            node->data = left + right;
            return temp + left + right;
        }
        
    }
    void toSumTree(Node *node)
    {
        // Your code here
        helper(node);
    }
    
//--------------------------------------------------------------------------

void toSumTree(Node *node)
    {  if(!node)
        return ;
        int prev1=f1(node->left,0,0);
        int prev2=f1(node->right,0,0);
        node->data=prev1+prev2;
    }
   int f1(Node *node,int prev1,int prev2){
        if(!node)
        return 0;
        prev1=f1(node->left,prev1,prev2);
        prev2=f1(node->right,prev1,prev2);
        int temp=node->data;
       node->data=prev1+prev2;
        return (temp+ node->data);
    }    