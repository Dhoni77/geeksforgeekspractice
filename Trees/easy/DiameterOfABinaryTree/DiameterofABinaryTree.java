package BST;

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


class A{
    int a=0;
}
public class diameter {
    int max = 0;

    // Function to return the diameter of a Binary Tree.
    static int diameter(Node root) {
        // Your code here
        A ans = new A();
        height(root, ans);
        return 1 + ans.a;

    }

    static int height(Node p, A ans) {
        if (p == null) return 0;
        int lh = height(p.left, ans);
        int rh = height(p.right, ans);
        ans.a = Math.max(ans.a, lh + rh);
        return 1 + Math.max(lh, rh);
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.left.left = new Node(7);
        root.left.right = new Node(5);
        System.out.println(diameter(root));
    }


    //-----------------------------------------------------------------------------------------
    int height(Node root) {
        return root == null ? -1 : Math.max(height(root.left), height(root.right)) + 1;
    }

    int diameter_(Node root) {

        if (root == null)
            return 0;

        int lr = diameter_(root.left);
        int rr = diameter_(root.right);

        int lh = height(root.left);
        int rh = height(root.right);

        return Math.max(lh + rh + 2, Math.max(lr, rr));
    }

    int diameterr(Node root) {
        return diameter_(root) + 1;
    }

}
