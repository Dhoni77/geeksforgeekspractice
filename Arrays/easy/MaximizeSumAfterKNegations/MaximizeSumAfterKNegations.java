package Array;

import java.util.PriorityQueue;

//https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1

//N = 10, K = 5
//arr[] = {5, -2, 5, -4, 5, -12, 5, 5, 5, 20}
//Output:
//68

//Explanation:
//Here  we have k=5 so we turn -2, -4, -12 to
//2, 4, and 12 respectively. Since we have
//performed 3 operations so k is now 2. To get
//maximum sum of array we can turn positive
//turned 2 into negative and then positive
//again so k is 0. Now sum is
//5+5+4+5+12+5+5+5+20+2 = 68

public class MaximizeSumAfterKNegations {
    public static long maximizeSum(long a[], int n, int k)
    {
        // Your code goes here
    PriorityQueue<Long> pq=new PriorityQueue<>();
    long sum=0;
    for (long i:a){
        pq.add(i);
    }

    while (k-- > 0){
        long num=pq.poll();
        long sign=-num;
        pq.add(sign);
    }

    while (!pq.isEmpty()){
        sum+=pq.poll();
    }
    return sum;
    }
    public static void main(String[] args) {
        long arr[]={1, 2, -3, 4, 5};
        int n=arr.length;
        int k=1;
        System.out.println(maximizeSum(arr, n, k));
    }
}

