package BST;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

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

class Node
{
    int data;
    Node left, right;
    public Node(int data)
    {
        this.data = data;
        left = right = null;
    }
}
public class rightView {
    public int max=0;
    ArrayList<Integer> rightView(Node node) {
        ArrayList<Integer> ans=new ArrayList<Integer>();
        rightView(node,ans,1);
        return ans;
    }

    void rightView(Node node,ArrayList<Integer>ans,int level)
    {
        if(node == null)
            return;

        if(max<level)
        {
            ans.add(node.data);
            max=level;
        }
        rightView(node.right,ans,level+1);
        rightView(node.left,ans,level+1);
    }
     static void printRightView(Node root) {
         if (root == null)
             return;

             Queue<Node> queue = new LinkedList<>();
             queue.add(root);

         while (!queue.isEmpty()) {
             // number of nodes at current level
             int n = queue.size();

             // Traverse all nodes of current level
             for (int i = 0; i < n; i++) {
                 Node temp = queue.poll();

                 // Print the right most element at
                 // the level
                 if (i == n-1)
                     System.out.print(temp.data + " ");

                 // Add left node to queue
                 if (temp.left != null)
                     queue.add(temp.left);

                 // Add right node to queue
                 if (temp.right != null)
                     queue.add(temp.right);
             }
         }
     }
    public static void main(String[] args) {
        Node root=new Node(1);
        root.left=new Node(2);
        root.left.left=new Node(4);
        root.left.left.left=new Node(9);
        root.left.left.right=new Node(8);
        root.left.right=new Node(5);
        root.right=new Node(3);
        root.right.left=new Node(6);
        root.right.right=new Node(7);
        rightView r = new rightView();
        r.rightView(root);
    }

}

