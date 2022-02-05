//Stickler Thief

        int FindMaxSum(int arr[], int n)
        {
        // Your code here
        if(n==1) return arr[0];
        else if(n==2) return max(arr[0],arr[1]);

        int dp[n];
        dp[0]=arr[0];
        dp[1]=arr[1];
        dp[2]=arr[0]+arr[2];
        int ans=max(dp[1],dp[2]);
        for(int i=3; i<n; i++){
        dp[i]=arr[i]+max(dp[i-2],dp[i-3]);
        ans=max(ans,dp[i]);
        }
        return ans;
        }