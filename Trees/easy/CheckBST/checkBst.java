package BST;

import java.util.ArrayList;

public class checkBst {

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

    //Function to check whether a Binary Tree is BST or not.
    ArrayList<Integer> a= new ArrayList<>();
    void inorder(Node root){
        if(root==null)return;
        inorder(root.left);
        a.add(root.data);
        inorder(root.right);
    }

    boolean isBST(Node root)
    {
        // code here.
        inorder(root);
        for(int i=0;i<a.size()-1;i++){
            if(a.get(i)>=a.get(i+1))return false;
        }
        return true;

    }

}

//JAVA Solutions - Morris Inorder Traversal (Iterative Solution)
//
//
//
//NOTE ; We know that if a binary tree is a BST only if its Inoder traversal gives us sorted Array.
//
//
//
//     USING Space - O(n) and Time Complexity - O(n)
//
Node getRMN(Node node, Node curr) {

        while(node.right != null && node.right != curr)

            node = node.right;

        return node;

    }



    ArrayList<Integer> MorrisTraversal(Node root) {

        ArrayList<Integer> ans = new ArrayList<>();

        Node curr = root;

        while(curr != null) {

            Node leftNode = curr.left;

            if(leftNode == null) {

                ans.add(curr.data);

                curr = curr.right;

            } else {

                Node rightMost = getRMN(leftNode, curr);

                if(rightMost.right == null) {

                    rightMost.right = curr;

                    curr = curr.left;

                } else {

                    rightMost.right = null;

                    ans.add(curr.data);

                    curr = curr.right;

                }

            }

        }

        return ans;

    }



    boolean isBST_01(Node root) {

        ArrayList<Integer> morris = MorrisTraversal(root);

        for(int i = 1; i < morris.size(); i++) {

            int prev = morris.get(i - 1), curr = morris.get(i);

            if(prev >= curr)

                return false;

        }

        return true;

    }

//=============================================
//
//
//
//      2. Without Space - Optimal Solution
//
//           Time - O(n) and Space - O(1)
//
//
//
//NOTE : In this we maintain two pointers to check simultaneously that if prev < curr (equality of values will results us false)
//
//
//
Node getRMN(Node node, Node curr) {
       while(node.right != null && node.right != curr)
           node = node.right;
       return node;
   }


  boolean MorrisTraversalBST(Node root) {
       Node curr = root, prev = null;
       while(curr != null) {
           Node leftNode = curr.left;
           if(leftNode == null) {
               if(prev != null && prev.data >= curr.data)
                   return false;
               prev = curr;
               curr = curr.right;
           } else {
               Node rightMostNode = getRMN(leftNode, curr);
               if(rightMostNode.right == null) {
                   rightMostNode.right = curr;
                   curr = curr.left;
               } else {
                   rightMostNode.right = null;
                   if (prev != null && prev.data >= curr.data)
                       return false;

                   prev = curr;
                   curr = curr.right;
               }
           }
       }
       return true;
   }


   boolean isBST(Node root) {
       if(root == null)
           return true;
       return MorrisTraversalBST(root);
   }