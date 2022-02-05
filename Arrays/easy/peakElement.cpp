
//https://practice.geeksforgeeks.org/problems/peak-element/1

//An element is called a peak element if its value is not smaller than the value of its adjacent elements(if they exists).
//Given an array arr[] of size N, find the index of any one of its peak elements.
//Note: The generated output will always be 1 if the index that you return is correct. Otherwise output will be 0.

//Example 1:
//
//Input:
//N = 3
//arr[] = {1,2,3}
//Output: 1
//Explanation: index 2 is 3.
//It is the peak element as it is
//greater than its neighbour 2.

//Example 2:
//
//Input:
//N = 2
//arr[] = {3,4}
//Output: 1
//Explanation: 4 (at index 1) is the
//peak element as it is greater than
//its only neighbour element 3.
//
//
//Your Task:
//You don't have to read input or print anything. Complete the function peakElement() which takes the array arr[] and its size N as input parameters and return the index of any one of its peak elements.
//
//Can you solve the problem in expected time complexity?
//
//
//
//Expected Time Complexity: O(log N)
//Expected Auxiliary Space: O(1)
//
//
//Constraints:
//1 ≤ N ≤ 105

//using Binary Search

//   int left = 0;
//      int right = n - 1;
//      while(left < right){
//          int mid = left + (right - left)/2;
//          if(arr[mid] < arr[mid + 1]){
//              left = mid + 1;
//          }else{
//              right = mid;
//          }
//      }
//      return left;

----------------------------------------------------------------------------------

//  Time Complexity O(logn) 
//  if(n==1){
//            return 0;
//        }
//
//        int i=0,j=n-1;
//        while(i<=j){
//            int mid = i+ (j-i)/2;
//            if(mid>0&&mid<n-1){
//                if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]){
//                    return mid;
//                }else if(arr[mid-1]>=arr[mid])
//                    j= mid-1;
//                else
//                    i = mid+1;
//            }
//            else if(mid==0){
//                if(arr[0]>arr[1]){
//                    return 0;
//                }
//                else
//                    return 1;
//            }
//            else if(mid==n-1){
//                if(arr[mid]>arr[n-2])
//                    return n-1;
//                else
//                    return n-2;
//            }
//
//        }