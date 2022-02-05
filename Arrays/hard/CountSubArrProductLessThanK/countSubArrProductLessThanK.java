package Array.hard;

//https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1

//Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number k.
//
//Example 1:
//
//Input :
//n = 4, k = 10
//a[] = {1, 2, 3, 4}
//Output :
//7
//Explanation:
//The contiguous subarrays are {1}, {2}, {3}, {4}
//{1, 2}, {1, 2, 3} and {2, 3} whose count is 7.

//Example 2:
//
//Input:
//n = 7 , k = 100
//a[] = {1, 9, 2, 8, 6, 4, 3}
//Output:
//16
//
//
//
//Your Task:
//You don't need to read input or print anything. Your task is to complete the function countSubArrayProductLessThanK()
// which takes the array a[], its size n and an integer k as inputs and returns the count of required subarrays.
//
//
//
//Expected Time Complexity: O(n)
//Expected Auxiliary Space: O(1)
//
//
//
//Constraints:
//1<=n<=10^5
//1<=k<=10^15
//1<=a[i]<=10^5


public class countSubArrProductLessThanK {
    public  static int countSubArrayProductLessThanK(long a[], long n, long k)
    {
        int j=0,ans=0;
        long p=1;
        for(int i=0;i<n;i++){
            p*=a[i];
            while(j<n && p>=k){
                p/=a[j];
                j++;
            }
            ans+=(i-j+1);
        }
        return ans;
    }

    public  static int countSubArrayProductLessThank(long a[], long n, long k){
        long p=1;
        int ans=0;
        for (int start=0,end=0;end<n;end++){
            p*=a[end];

            while (start<n && p>=k){
                p/=a[start++];
            }

            if (p<k){
                int window=(end-start)+1;
                ans+=window;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        long arr[] = {1, 2, 3, 4};
        int k=10;
        countSubArrayProductLessThank(arr, 4, k);
    }
}

