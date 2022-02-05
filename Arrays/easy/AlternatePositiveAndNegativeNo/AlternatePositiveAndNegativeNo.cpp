
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

//most simple and common way to slove this question without using any stl ;

    void rearrange(int arr[], int n) {
    // code here
    int P[n],N[n];
    int j=0,k=0;
    for(int i =0;i<n;i++)
    {
    if(arr[i]>=0)
    {
    P[j]=arr[i];
    j++;
    }
    else
    {
    N[k]=arr[i];
    k++;
    }
    }
    int q=0,s=0,p=0,i=0;
    while(i<n)
    {
    if((i%2==0 && q<j) || p==1){
    arr[i]=P[q];
    q++;
    i++;}
    else {
    if(s>=k){
    p=1;
    continue;
    }
    arr[i]=N[s];
    s++;
    i++;
    }

    }
    }

//----------------------------------------------------------------------------------
    void rearrange(int arr[], int n) {
    // code here
    vector<int> pos;
    vector<int> neg;
    int i=0,j=0,k=0;
    int s1=pos.size();
    int s2=neg.size();
    for(int i=0;i<n;i++){
    if(arr[i]>=0){
    pos.push_back(arr[i]);
    }else{
    neg.push_back(arr[i]);
    }
    }
    while(i<s1 && j<s2)
    {
    arr[k++]=pos[i++];
    arr[k++]=neg[j++];
    }
    while(i<s1){
    arr[k++]=pos[i++];
    }
    while(j<s2){
    arr[k++]=neg[j++];
    }
    }

//-------------------------------------------------------------------------------------------------------------

class Solution
{
public:
void rearrange(int arr[], int n)
{
    vector<int> neg;
    vector<int> pos;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] < 0)
        {
            neg.push_back(arr[i]);
        }
        else
        {
            pos.push_back(arr[i]);
        }
    }

    int negIndex = 0;
    int posIndex = 0;
    int arrIndex = 0;

    while(arrIndex < n and posIndex < pos.size() and negIndex < neg.size())
    {
        if(arrIndex % 2 == 0)
        {
            arr[arrIndex++] = pos[posIndex++];
        }
        else
        {
            arr[arrIndex++] = neg[negIndex++];
        }
    }

    while(arrIndex < n and posIndex < pos.size())
    {
        arr[arrIndex++] = pos[posIndex++];
    }

    while(arrIndex < n and negIndex < neg.size())
    {
        arr[arrIndex++] = neg[negIndex++];
    }
}
};
