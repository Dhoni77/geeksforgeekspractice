package Array;

//https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1#

//Dynamic Programming
//Input:
//n = 6
//a[] = {5,5,10,100,10,5}
//Output: 110
//Explanation: 5+100+5=110

public class sticklerThief {
    public static int FindMaxSum(int arr[], int n) {
        int val1=arr[0];
        if(n==1)return val1;
        int val2=Math.max(arr[0],arr[1]);
        if(n==2)return val2;
        int sum=0;
        for (int i=2;i<n;i++){
            sum=Math.max(arr[i]+val1,val2);
            val1=val2;
            val2=sum;
        }
        return sum;
    }

    public static void main(String[] args) {


    System.out.println(FindMaxSum(new int[]{3,10,2,6,4,1,8,5},8));
    }
}



