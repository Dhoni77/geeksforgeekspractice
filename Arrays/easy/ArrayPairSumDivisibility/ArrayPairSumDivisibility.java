package Array;

//https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1#

public class canPair {

//Input : arr = [9, 5, 7, 3], k = 6
//Output: True
//Explanation: {(9, 3), (5, 7)} is a
//possible solution. 9 + 3 = 12 is divisible
//by 6 and 7 + 5 = 12 is also divisible by 6.
//
//Example 2:
//
//Input : arr = [2, 4, 1, 3], k = 4
//Output: False
//Explanation: There is no possible solution.

//input arr[1,1,9,15], k=9
//output: false

    public boolean canPair(int[] nums, int k) {
        // Code here
        int rem[]=new int[k];
        for(int i=0;i<nums.length;i++){
            rem[nums[i]%k]++;
        }

        if(rem[0]%2!=0)return false; //very good condition🎈

        int i=1, j=k-1;

        while(i < j){
            if(rem[i]!=rem[j])return false;
            i++;j--;
        }

        if(i==j && rem[i]%2 ==1)return false;
        return true;
    }
}

