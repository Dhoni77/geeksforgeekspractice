package BST;
//https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1#

//Given a Binary search Tree that contains positive integer values greater then 0. The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.
//
//Examples:
//
//Input :
//               8
//             /   \
//           5      9
//         /  \
//        2    7
//       /
//      1
//
//Output : Yes
//Explanation : Node "1" is the dead End because after that
//              we cant insert any element.
//
//Input :
//              8
//            /   \
//           7     10
//         /      /   \
//        2      9     13
//
//Output : Yes
//Explanation : We can't insert any element at
//              node 9.
//
//
//Input:
//The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of three lines. First line of each test case contains an integer N denoting the no of nodes of the BST . Second line of each test case consists of 'N' space separated integers denoting the elements of the BST. These elements are inserted into BST in the given order.
//
//Output:
//The output for each test case will be 1 if the BST contains a dead end else 0.
//
//
//Constraints:
//1<=T<=100
//1<=N<=200
//
//
//Example(To be used only for expected output):
//Input:
//2
//6
//8 5 9 7 2 1
//6
//8 7 10 9 13 2
//Output:
//1
//1

public class CheckDeadEndBST {
    static java.util.ArrayList<Integer> leaf=new java.util.ArrayList<>();
    static java.util.ArrayList<Integer> node=new java.util.ArrayList<>();
    static void addLN(Node p){
        if(p==null)return;
        if(p!=null)node.add(p.data);
        addLN(p.left);
        addLN(p.right);
        if(p.left == null && p.right == null)leaf.add(p.data);
    }
    public static boolean isDeadEn(Node root)
    {
        //Add your code here.
        addLN(root);
        if(node.contains(1))return true;
        for (int i=0;i<leaf.size();i++){
            int v=leaf.get(i);
            if(node.contains(v+1) && node.contains(v-1))return true;
        }
        return false;
    }


    //Time Taken 0.2
    boolean solve(Node root,int l,int h){
        if(root==null) return false;

        if(l == h) return true;

        return solve(root.left,l,root.data-1) || solve(root.right,root.data+1,h);

    }
    boolean isDeadEnd(Node root)
    {
        int low = 1;
        int high = Integer.MAX_VALUE;
        return solve(root,low,high);
    }

    //another method
    boolean deadEnd(Node root, int left, int right){
        if(root==null)return false;
        if(right-left==2){
            System.out.println("Dead end is at "+root.data);
            return true;
        }
        return deadEnd(root.left, left, root.data) || deadEnd(root.right, root.data, right);
    }
    public static void main(String[] args) {
        Node root=new Node(8);
        root.left=new Node(7);
        root.right=new Node(10);
        root.left.left=new Node(2);
        root.left.right=new Node(6);
        root.right.left=new Node(9);
        root.right.right=new Node(13);

        CheckDeadEndBST bst=new CheckDeadEndBST();
//        System.out.println(bst.isDeadEnd(root));
        System.out.println(bst.deadEnd(root, 0, Integer.MAX_VALUE));
    }
}

