package Array;

import java.util.ArrayList;

//https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1

//Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
//Note: Array should start with positive number.
//
//
//Example 1:
//
//Input:
//N = 9
//Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
//Output:
//9 -2 4 -1 5 -5 0 -3 2
//
//Example 2:
//
//Input:
//N = 10
//Arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
//Output:
//5 -5 2 -2 4 -8 7 1 8 0
//
//
//Your Task:
//You don't need to read input or print anything. Your task is to complete the function rearrange() which takes the array of integers arr[] and n as parameters. You need to modify the array itself.
//
//Expected Time Complexity: O(N)
//Expected Auxiliary Space: O(N)
//
//
//Constraints:
//1 ≤ N ≤ 107
//-106 ≤ Arr[i] ≤ 107

public class AlternaterPosAndNegNO {
    public static void main(String[] args) {
        int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
        int n = 10;
        ArrayList<Integer> neg = new ArrayList<Integer>();
        ArrayList<Integer> pos = new ArrayList<Integer>();

        for (int i = 0; i < n; i++) {

            if (arr[i] < 0)
                neg.add(arr[i]);
            else
                pos.add(arr[i]);
        }

        int i = 0, j = 0, k = 0;
        while (i <neg.size() && j < pos.size()) {
            arr[k] = pos.get(j);
            k++;
            j++;
            arr[k] = neg.get(i);
            k++;
            i++;
        }
        while (j < pos.size())
        {
            arr[k] = pos.get(j);
            k++;
            j++;
        }

        while (i < neg.size())
        {
            arr[k] = neg.get(i);
            k++;
            i++;}
    }
}





