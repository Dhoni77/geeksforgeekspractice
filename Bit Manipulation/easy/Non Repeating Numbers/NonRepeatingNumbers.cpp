//https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1

//Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers.
//
//
//Example 1:
//
//Input:
//N = 2
//arr[] = {1, 2, 3, 2, 1, 4}
//Output:
//3 4
//Explanation:
//3 and 4 occur exactly once.
//
//Example 2:
//
//Input:
//N = 1
//arr[] = {2, 1, 3, 2}
//Output:
//1 3
//Explanation:
//1 3 occur exactly once.
//
//
//Your Task:
//You do not need to read or print anything. Your task is to complete the function singleNumber() which takes the array as input parameter and returns a list of two numbers which occur exactly once in the array. The list must be in ascending order.
//
//
//Expected Time Complexity: O(N)
//Expected Space Complexity: O(1)
//
//
//Constraints:
//1 <= length of array <= 106
//1 <= Elements in array <= 5 * 106


  vector<int> singleNumber(vector<int> nums)
    {
        // Code here.
        int num = 0;
        for(int a : nums){
            num  = num ^ a;
        }
        int res = -1;
        int i = 0;
        while(num > 0){
            if(num % 2 == 1){
                res = i;break;
            }
            num/= 2;
            i++;
        }
        int n1 = 0;
        int n2 = 0;
        for(int a : nums){
            if((a >> i) & 1)
                n1 = n1 ^ a;
            else
                n2 = n2 ^ a;
        }
        vector<int> ret = {n1,n2};
        sort(ret.begin(),ret.end());
        return ret;
    }


//-----------------------------------------------------------------------------

Use this to find Right most set bit in O(1)
log2(x & ~(x-1))



vector<int> singleNumber(vector<int> nums)
{
    int res = 0;
    for (auto x : nums)
        res = res ^ x;  //Getting xor of all the values

    int n = res & ~(res - 1); //Rightmost set Bit

    int grp1 = 0, grp2 = 0;

    for (auto x : nums)
    {
        if ((n & x) != 0)
            grp1 = grp1 ^ x;
        else
            grp2 = grp2 ^ x;
    }

    vector<int> v;
    v.push_back(grp1);
    v.push_back(grp2);
    sort(v.begin(), v.end());
    return v;

}

//------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        int xorResult = nums[0];

        for(int i = 1; i < nums.size(); i++)
            xorResult ^= nums[i];

        int positionOfRightMost1 = 0;

        while((xorResult & (1 << positionOfRightMost1)) != (1 << positionOfRightMost1))
            positionOfRightMost1++;

        // now positionOfRightMost1 has a position of right most 1 in our result 'xorResult'
        // 1 bit in xorResult implies that both nums has opposite bit at this position.
        // Lets assume that num1 has setBit at this position while num2 has 0 bit.

        // now do the xor of all array elements with our xorResult who has setBit at
        // positionOfRightMost1. In this way, those elements are repeated will get vanished
        // and we will get our first num i.e, num1

        // now to get num2, just do the xor of num1 with our previous result 'xorResult'

        int num1 = xorResult;

        for(int i = 0; i < nums.size(); i++){
            if((nums[i] & (1 << positionOfRightMost1)) == (1 << positionOfRightMost1))
                num1 ^= nums[i];
        }

        int num2 = num1 ^ xorResult;

        vector <int> ans;

        ans.push_back(min(num1, num2));
        ans.push_back(max(num1, num2));

        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends