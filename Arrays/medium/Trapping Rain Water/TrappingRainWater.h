//
// Created by Aldrin on 23-01-2022.
//

#ifndef GEEKSFORGEEKS_TRAPPINGRAINWATER_H
#define GEEKSFORGEEKS_TRAPPINGRAINWATER_H
#include "bits/stdc++.h"
using namespace std;
//https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#
class TrappingRainWater {
public:
    static int trapRWater(int arr[], int n){
        //TC: O(n^2)

        if(n<3)return 0;

        int res=0;
        for(int i=1;i<n-1;i++){

            int left=arr[i];
            for(int j=0;j<i;j++){
                left=max(left, arr[j]);
            }
            int right=arr[i];
            for(int j=i+1;j<n;j++){
                right=max(right, arr[j]);
            }

            res+=min(left, right)-arr[i];

        }

        return res;
    }

    static int trapWater(int arr[], int n){
        int lmax=0;
        int rmax=0;

        int low=0;
        int high=n-1;
        int ans=0;

        while(low<=high){

            if(arr[low]<arr[high]){
                if(arr[low]>lmax){
                    lmax=arr[low];
                } else ans+=lmax-arr[low];
                low++;
            }
            else{
                if(arr[high]>rmax){
                    rmax=arr[high];
                } else ans+=rmax-arr[high];
                high--;
            }
        }
        return ans;
    }
};


#endif //GEEKSFORGEEKS_TRAPPINGRAINWATER_H
