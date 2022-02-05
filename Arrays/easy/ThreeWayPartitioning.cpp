Three Way Partitioning
https://practice.geeksforgeeks.org/problems/three-way-partitioning/1

Example 1:

Input:
n = 5
A[] = {1, 2, 3, 3, 4}
[a, b] = [1, 2]
Output: 1
Explanation: One possible arrangement is:
{1, 2, 3, 3, 4}. If you return a valid
arrangement, output will be 1.


Example 2:

Input:
n = 3
A[] = {1, 2, 3}
[a, b] = [1, 3]
Output: 1
Explanation: One possible arrangement
is: {1, 2, 3}. If you return a valid
arrangement, output will be 1.

-----------------------------------------------------------------
        void threeWayPartition(vector<int>& arr,int a, int b)
        {
        // code here
        int n=arr.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high)
        {
        if(a>arr[mid])
        {
        swap(arr[mid],arr[low]);
        mid++;
        low++;
        }
        else if(arr[mid]>b)
        {
        swap(arr[mid],arr[high]);
        high--;
        }
        else
        {
        mid++;
        }
        }

        }

---------------------------------------------------------------
DNF SORT | T.C=0(N) S.C=0(1)
int i=0,l=0,h=array.size()-1;

       while(i<=h)
       {
           if(array[i]<a)swap(array[i++],array[l++]);
           else if(array[i]>b)swap(array[i],array[h--]);
           else i++;
       }

---------------------------------------------------------------
Simple O(n) Solution

 void threeWayPartition(vector<int>& array,int a, int b)
   {
       int l=0;
       int r=array.size()-1;
       for(int i=0;i<=r;i++){
           if(array[i]<a) swap(array[i],array[l++]);
           else if(array[i]>b) swap(array[i--],array[r--]);
       }
   }