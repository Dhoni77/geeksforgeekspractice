//https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1

//N = 10, K = 5
//arr[] = {5, -2, 5, -4, 5, -12, 5, 5, 5, 20}
//Output:
//68

//Explanation:
//Here  we have k=5 so we turn -2, -4, -12 to
//2, 4, and 12 respectively. Since we have
//performed 3 operations so k is now 2. To get
//maximum sum of array we can turn positive
//turned 2 into negative and then positive
//again so k is 0. Now sum is
//5+5+4+5+12+5+5+5+20+2 = 68


//long long int maximizeSum(long long int a[], int n, int k)
//   {
//       // Your code goes here
//       long long int b=0;
//       sort(a,a+n);
//       for(int i=0;i<n;i++){
//           if(a[i]<0 && k>0){
//               a[i]=-a[i];k--;
//           }
//           b+=a[i];
//       }
//       if(k==0 || k%2==0){
//           return b;
//       }
//       else {
//           sort(a,a+n);
//           b-=(2*a[0]);
//       }
//       return b;
//   }

//------------------------------------------------------------------------------------------------------------------------------
//Greedy Method:


//We convert all -ve to +ve which we can done using first sorting arr.
//
//If we have k operation more than number -ve element
//
//and k remainded after converting -ve to +ve is odd then we only make least +ve element to -ve.(Note: sort again to get least)
// long long int maximizeSum(long long int arr[], int n, int k)
//    {
//        sort(arr,arr+n);
//        int i=0;
//        while(arr[i]<0 && k>0){
//            arr[i]=0-arr[i];
//            k--;
//            i++;
//        }
//
//
//         if(k>0 && k%2){
//             sort(arr,arr+n);
//             arr[0]=0-arr[0];
//        }
//
//
//        long long int sum=0;
//        for(int i=0;i<n;i++){
//            sum+=arr[i];
//        }
//
//        return sum;
//    }
