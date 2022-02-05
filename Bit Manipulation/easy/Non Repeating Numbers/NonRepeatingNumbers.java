package Array;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

//https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1

//Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers.
//
//
//Example 1:
//
//Input:
//N = 2
//arr[] = {1, 2, 3, 2, 1, 4}
//Output:
//3 4
//Explanation:
//3 and 4 occur exactly once.
//
//Example 2:
//
//Input:
//N = 1
//arr[] = {2, 1, 3, 2}
//Output:
//1 3
//Explanation:
//1 3 occur exactly once.
//
//
//Your Task:
//You do not need to read or print anything. Your task is to complete the function singleNumber() which takes the array as input parameter and returns a list of two numbers which occur exactly once in the array. The list must be in ascending order.
//
//
//Expected Time Complexity: O(N)
//Expected Space Complexity: O(1)
//
//
//Constraints:
//1 <= length of array <= 106
//1 <= Elements in array <= 5 * 106

public class NonRepeatingNumbers {
    public static int[] singlenumBit(int[] nums){
        int ans[]=new int[2];
        int xor=nums[0];

        for (int i=1;i<nums.length;i++){
            xor ^= nums[i];
        }

        int rightMostBitPos=0;

        while ( (xor &  (1 << rightMostBitPos)) != (1 << rightMostBitPos) ){
                rightMostBitPos++;
        }

        int num1=xor;

        for (int i=0;i<nums.length;i++){
            if((nums[i] &  (1 << rightMostBitPos)) == (1 << rightMostBitPos)){
                num1^=nums[i];
            }
        }

        int num2=num1^xor;

        ans[0]=Math.min(num1,num2);
        ans[1]=Math.max(num1,num2);
        return ans;
    }
    public static int[] singleNumber(int[] nums)
    {
        // Code here
        Map<Integer,Integer> mp=new HashMap<>();
        int onlyTwo[]=new int[2];
        int j=0;
        for(int i=0;i<nums.length;i++){
            if(mp.containsKey(nums[i])){
                mp.put(nums[i], mp.get(nums[i])+1);
            }
            else mp.put(nums[i], 1);
        }

        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            if(entry.getValue()==1){
                onlyTwo[j] = entry.getKey();
                j++;
            }
        }
        Arrays.sort(onlyTwo);
        return onlyTwo;
    }

    public static void main(String[] args) {
        int nums[]={18, 24, 24, 21, 10 ,29, 8, 10 ,29, 18};
        int a[]=new int[2];
//        a=singleNumber(nums);
        a=singlenumBit(nums);
        for (int i:a){
            System.out.println(i);
        }

    }
}

