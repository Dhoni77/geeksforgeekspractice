package BST;

import java.util.ArrayList;
//https://practice.geeksforgeeks.org/problems/median-of-bst/1#

//Given a Binary Search Tree of size N, find the Median of its Node values.
//
//Example 1:
//
//Input:
//       6
//     /   \
//   3      8
// /  \    /  \
//1    4  7    9
//Output: 6
//Explanation: Inorder of Given BST will be:
//1, 3, 4, 6, 7, 8, 9. So, here median will 6.
//
//
//Example 2:
//
//Input:
//       6
//     /   \
//   3      8
// /   \    /
//1    4   7
//Output: 5
//Explanation:Inorder of Given BST will be:
//1, 3, 4, 6, 7, 8. So, here median will
//(4 + 6)/2 = 10/2 = 5.
//
//
//
//Your Task:
//You don't need to read input or print anything. Your task is to complete the function findMedian() which takes the root of the Binary Search Tree as input and returns the Median of Node values in the given BST.
//Median of the BST is:
//
//    If number of nodes are even: then median = (N/2 th node + (N/2)+1 th node)/2
//    If number of nodes are odd : then median = (N+1)/2th node.
//
//
//Expected Time Complexity: O(N).
//Expected Auxiliary Space: O(Height of the Tree).
//
//
//Constraints:
//1<=N<=1000
//
//

public class MedianOfBst {
    ArrayList<Node> arr=new ArrayList<>();
     void add(Node p){
        if (p==null)return;
         add(p.left);
        arr.add(new Node(p.data));
        add(p.right);
    }
    public void findMedian(Node root)
    {
        // code here.
       add(root);
       int size=arr.size();
       if(size%2==0){
           int sum= arr.get((size/2)-1).data+arr.get((size/2)).data;
           System.out.println(sum);
           float ans=sum/2;
           System.out.println(ans);
       }else {
           System.out.println(arr.get(size/2).data);
       }
    }

    public static void main(String[] args) {
        Node root=new Node(8);
        root.left=new Node(7);
        root.right=new Node(10);
        root.left.left=new Node(2);
        root.left.right=new Node(6);
        root.right.left=new Node(9);
//        root.right.right=new Node(13);
        MedianOfBst median=new MedianOfBst();
        median.findMedian(root);
    }
}

//efficient algorithm would be morris inorder traversal