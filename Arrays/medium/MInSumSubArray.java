package Array.medium;

public class MInSumSubArray {

  static   int minSubArr(int arr[], int target){
        int i=0,j=0, sum=0, min=Integer.MAX_VALUE;
        if (arr.length==0)return 0;
        while (j<arr.length){
            sum+=arr[j++];
            while (sum >= target){
                min=Math.min(min, j-i);
                sum-=arr[i++];
            }
        }
        return min;
    }

    public static void main(String[] args) {
        int arr[]={1,2,3,4,5};
        int target=11;
        System.out.println(minSubArr(arr, target));
    }

}

//https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems

//For those trying to figure out how is it O(n):
//Here we have defined 2 var i & j,
//
//In case of O(n^2) for each outer loop, inner loop runs some n or m number of times to make it O(nm), that means, as soon as the outer loop finishes one iteration, inner loop resets itself.
//In case of O(n2), as in this case, we are not resetting the inner inner variable i, it's just incrementing each time. It is like 2 loops one after another and both runs n number of time.
//For finding the length of current sub-array (j-1):
//If you have 2 pointer i and j with j >= i and you want to figure out the length of the subarray:
//
//len = j-i+1
//but here we have only
//
//len = j-i
//This is because, we have already incremented j by 1 position but not i, so no need to add 1.