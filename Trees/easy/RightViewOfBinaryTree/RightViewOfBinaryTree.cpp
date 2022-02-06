//https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

//Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.
//
//Right view of following tree is 1 3 7 8.
//
//          1
//       /     \
//     2        3
//   /   \      /    \
//  4     5   6    7
//    \
//     8
//
//Example 1:
//
//Input:
//       1
//    /    \
//   3      2
//Output: 1 2
//
//Example 2:
//
//Input:
//     10
//    /   \
//  20     30
// /   \
//40  60
//Output: 10 30 60
//
//Your Task:
//Just complete the function rightView() that takes node as parameter and returns the right view as a list.
//
//Expected Time Complexity: O(N).
//Expected Auxiliary Space: O(Height of the Tree).
//
//Constraints:
//1 ≤ Number of nodes ≤ 105
//1 ≤ Data of a node ≤ 105

 vector<int> rightView(Node *root)
    {
       // Your Code here
           vector<int> v;
           queue<Node*> q;
           if(root==NULL){
           return v;
            }
       q.push(root);
       while(!q.empty()){
           int size=q.size();
           for(int i=0;i<size;i++){
                      Node* newnode=q.front();
                      q.pop();
               if(newnode->left){
                   q.push(newnode->left);
               }
               if(newnode->right){
                   q.push(newnode->right);
               }
               if(i==size-1){
                   v.push_back(newnode->data);
               }
           }
       }
       return v;
    }
    
    
//----------------------------------------------------------------------

vector<int> v;
    int maxlevel = -1;
    int currlevel = 0;
    vector<int> rightView(Node *root)
    {
        if(root == NULL)
            return v;
        if(currlevel > maxlevel){
            v.push_back(root->data);
            maxlevel = currlevel;
        }
        currlevel++;
        rightView(root->right);
        rightView(root->left);
        currlevel--;
        return v;
            
    }
    
    
//----------------------------------------------------------------------------

 vector<int> rightView(Node *root)
   {
      // Your Code here
      vector<int> result;
      traverse(root,result,0);
       return result;
   }
   
   void traverse(Node* root, vector<int>& m,int level){
       if(root == nullptr) return;
       if(m.size()==level) m.push_back(root->data);
       if(root->right != nullptr) traverse(root->right, m,level+1);
       if(root->left != nullptr) traverse(root->left,m,level+1);
   }        