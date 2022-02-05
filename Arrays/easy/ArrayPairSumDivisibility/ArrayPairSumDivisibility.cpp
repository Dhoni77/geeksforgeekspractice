
//https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1#

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

bool canPair(vector<int> a, int k) {
       map<int,int>m;
       int n=a.size();
       for(int i=0;i<n;i++){
           m[a[i]%k]++;
       }
       for(int i=0;i<n;i++){
           int r=a[i]%k;
           if(r==0){
               if(m[0]&1)return 0;
           }
           else if(m[r]!=m[k-r])return 0;
       }
       return 1;

   }