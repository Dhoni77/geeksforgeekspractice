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


//2 pointers approach
int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        unsigned long long prod =1;
        int i=0,j=0,ans=0;
        while(i<n&&j<n){
            prod*=a[j];
            while(prod>=k&&i<j){
                prod/=a[i++];
            }
            if(prod<k)ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    
//-------------------------------------------------------------------------------------

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long runProd = 1, ans = 0, start = 0, end = 0;
        while(end < n) {
            runProd *= a[end];
            while(runProd >= k)
                runProd /= a[start++];
            ans += end - start + 1;
            end++;
        }
        return ans;
    }
};