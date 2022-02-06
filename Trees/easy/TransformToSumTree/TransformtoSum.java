package BST;

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

public class TransformtoSum {
    Node root=null;

        int sumTree(Node root){
            if(root==null) return 0;

            int leftSum= sumTree(root.left);
            int rightSum=sumTree(root.right);

            int x=root.data;
            int tsum=leftSum+rightSum;
            root.data=tsum;
            return tsum+x;
        }

        public void toSumTree(Node root){
            sumTree(root);
        }

    public static void main(String[] args) {
        TransformtoSum t = new TransformtoSum();
        t.root=new Node(10);
        t.root.left=new Node(-2);
        t.root.right=new Node(6);
        t.root.left.left=new Node(8);
        t.root.left.right=new Node(-4);
        t.root.right.left=new Node(7);
        t.root.right.right=new Node(5);
        t.toSumTree(t.root);
    }
}
