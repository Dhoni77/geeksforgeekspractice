//https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

//Example 1:
//
//Input:
//       1
//     /  \
//    2    3
//Output: 3
//
//Example 2:
//
//Input:
//         10
//        /   \
//      20    30
//    /   \ 
//   40   60
//Output: 4
//
//Your Task:
//You need to complete the function diameter() that takes root as parameter and returns the diameter.
//
//Expected Time Complexity: O(N).
//Expected Auxiliary Space: O(Height of the Tree).
//
//Constraints:
//1 <= Number of nodes <= 10000
//1 <= Data of a node <= 1000

int res = 0;
    int checkHeight(Node* root)
    {
        if(!root)return 0;
        int left = checkHeight(root->left);
        int right = checkHeight(root->right);
        int temp = 1+left+right;
        res = max(temp,res);
        return (1+max(left,right));
    }
    int diameter(Node* root) 
    {
        checkHeight(root);
        return res;
    }
    
    
//--------------------------------------------------------------------------------------------------

pair<int,int> helper(Node* root){
       
       if(!root){
           pair<int,int> p;
           p.first=0;            //height
           p.second=0;           //diameter
           return p;
       }
       
       pair<int,int> l=helper(root->left);
       pair<int,int> r=helper(root->right);
       
       int lh=l.first,ld=l.second;
       int rh=r.first,rd=r.second;
       
       int fh=max(lh,rh)+1;
       int fd=max(lh+rh+1, max(ld,rd) );
       
       pair<int,int> ans;
       ans.first=fh;
       ans.second=fd;
       return ans;
           
   }
   
   int diameter(Node* root) {
       // Your code here
       pair<int,int> p=helper(root);
       return p.second;
   }
   
//---------------------------------------------------------
int  height(Node* root, int &diamterofbt){
        if(!root){
            return 0;
        }
        int lh=height(root->left,diamterofbt);
        int rh=height(root->right,diamterofbt);
        
         int temp= 1 + max(lh,rh);
         int ans=max(temp,lh+rh+1);
         diamterofbt=max(diamterofbt,ans);
         return temp;
    }
   
   int diameter(Node* root) {
        int diamterofbt=0;
        height(root,diamterofbt);
        return diamterofbt;
   }
   
//--------------------------------------------------------------------

//Tweak the height code with a reference max diameter which just updates the diameter should it be maximum than the current diameter.

 

//we already know how to find height. Now what is diameter, its nothing  but the sum of left height, right height,1 …WHY 1??? because we can't just leave the current node, that's why. The whole code is just the height code with the little difference being the updation of diameter

 

//CODE IMPLEMENTATION:-

 

int helper(Node* root, int &max_dia){
        if(root==nullptr){
            return 0;
        }
        int lh=helper(root->left,res);
        int rh=helper(root->right,res);
        int height=1+max(lh,rh);
        max_dia=max(max_dia,1+lh+rh);
        return height;
}

int diameter(Node* root) {
        int res=0;
        helper(root,res);
        return res;
}   
     