//https://practice.geeksforgeeks.org/problems/check-for-bst/1

//Test Case    
//    1 1 1 1 1 N 1 1 1 1 1
//    op:0
    
//Given the root of a binary tree. Check whether it is a BST or not.
//Note: We are considering that BSTs can not contain duplicate Nodes.
//A BST is defined as follows:
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.
//
//
//Example 1:
//
//Input:
//   2
// /    \
//1      3
//Output: 1
//Explanation:
//The left subtree of root node contains node
//with key lesser than the root node’s key and
//the right subtree of root node contains node
//with key greater than the root node’s key.
//Hence, the tree is a BST.

//Example 2:
//
//Input:
//  2
//   \
//    7
//     \
//      6
//       \
//        5
//         \
//          9
//           \
//            2
//             \
//              6
//Output: 0
//Explanation:
//Since the node with value 7 has right subtree
//nodes with keys less than 7, this is not a BST.
//Your Task:
//You don't need to read input or print anything. Your task is to complete the function isBST() which takes the root of the tree as a parameter and returns true if the given binary tree is BST, else returns false.
//
//Expected Time Complexity: O(N).
//Expected Auxiliary Space: O(Height of the BST).
//
//Constraints:
//0 <= Number of edges <= 100000



    bool isBST(Node* root, int min = INT_MIN, int max = INT_MAX)
    {
        // Your code here
        if(root == NULL){
            return true;
        }
        if(root -> data < min || root -> data > max){
            return false;
        }
        bool isLeftOkay = isBST(root -> left, min, root -> data - 1);
        bool isRightOkay = isBST(root -> right, root -> data, max);

        return isLeftOkay && isRightOkay;
    }