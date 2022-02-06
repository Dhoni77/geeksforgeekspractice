package BST;

import java.util.ArrayList;
import java.util.Collections;

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

//https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1#

public class BinaryTreeToBST {
    ArrayList<Integer> arr=new ArrayList<>();
    int i=0;
    Node binaryTreeToBST(Node root)
    {
        // Your code here
        //Add elements to list using inorder traversal
        inorder(root);
        //sort the list
        Collections.sort(arr);
        //Finally insert elements into tree in inorder manner and we can obtain a binary search tree!
        bTreeToBst(root);
        return root;
    }
    void inorder(Node root){
        if(root==null)return;
        inorder(root.left);
        arr.add(root.data);
        inorder(root.right);
    }

    void bTreeToBst(Node root){
        if(root==null)return;
        bTreeToBst(root.left);
        root.data=arr.get(i++);
        bTreeToBst(root.right);
    }
}
