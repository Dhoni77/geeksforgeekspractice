package BST;
//https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1

//Given a Binary Tree, check if all leaves are at same level or not.
//
//Example 1:
//
//Input:
//            1
//          /   \
//         2     3
//
//Output: 1
//
//Explanation:
//Leaves 2 and 3 are at same level.
//
//Example 2:
//
//Input:
//            10
//          /    \
//        20      30
//       /  \
//     10    15
//
//Output: 0
//
//Explanation:
//Leaves 10, 15 and 30 are not at same level.
//
//
//Your Task:
//You dont need to read input or print anything. Complete the function check() which takes root node as input parameter and returns true/false depending on whether all the leaf nodes are at the same level or not.
//
//
//Expected Time Complexity: O(N)
//Expected Auxiliary Space: O(height of tree)
//
//
//Constraints:
//1 ≤ N ≤ 10^3

public class LeafAtSameLevel {
    boolean sameLevel=true;
    boolean check(Node root){
        height(root);
        return sameLevel;
    }

    int height(Node p){
        if(p==null) return 0;
        int lh=height(p.left);
        int rh=height(p.right);
        if(lh!=0 && rh!=0 && lh!=rh){	 // extra condition in height fn
            sameLevel=false;
        }
        return Math.max(lh,rh)+1;
    }
}
