//https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1

//Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level.
//
//Example 1:
//
//Input :
//        1
//      /   \
//     3     2
//
//Output: 3 2 1
//Explanation:
//Traversing level 1 : 3 2
//Traversing level 0 : 1
//
//Example 2:
//
//Input :
//       10
//      /  \
//     20   30
//    / \
//   40  60
//
//Output: 40 60 20 30 10
//Explanation:
//Traversing level 2 : 40 60
//Traversing level 1 : 20 30
//Traversing level 0 : 10
//
//
//Your Task:
//You dont need to read input or print anything. Complete the function reverseLevelOrder() which takes the root of the tree as input parameter and returns a list containing the reverse level order traversal of the given tree.
//
//
//Expected Time Complexity: O(N)
//Expected Auxiliary Space: O(N)
//
//
//Constraints:
//1 ≤ N ≤ 10^4

vector<int> reverseLevelOrder(Node *root){
// code here
//Your code here
vector<int>ans;
queue<Node*>q;
q.push(root);
q.push(NULL);
while(!q.empty()){
Node *temp=q.front();
q.pop();
if(temp!=NULL){
ans.push_back(temp->data);
if(temp->right)
q.push(temp->right);
if(temp->left)
q.push(temp->left);
}
else if(!q.empty()){
q.push(NULL);
}
}
reverse(ans.begin(),ans.end());
return ans;


//---------------------------------------------------------------

vector <int>ans;
   if(!root) return ans;
   
   queue<Node*>q;
   q.push(root);
   while(!q.empty())
   {
       Node *t= q.front();
       ans.push_back(t->data);
       
       if(t->right) q.push(t->right);
       if(t->left)  q.push(t->left);
       q.pop();
   }
   reverse(ans.begin(),ans.end());
