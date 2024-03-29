//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int s, int e)
    {
        if(s>=e)
            return;
        
        // partition
        int p = partition(arr, s, e);
    
        quickSort(arr, s, p-1);     // left half
        quickSort(arr, p+1, e);     // right half
    }
    
    public:
    int partition (int arr[], int s, int e)
    {
        int pivotIndex = s;
        int pivot = arr[s];
    
        int cnt = 0;
        for(int i=s+1; i<=e; i++){
            if(arr[i] < pivot)
                cnt++;
        }
    
        int correctIndex = s + cnt;
        swap(arr[pivotIndex], arr[correctIndex]);
        pivotIndex = correctIndex;
    
        int i=s, j=e;
        while(i<correctIndex && j>correctIndex){
            while(arr[i] < pivot)
                i++;
            while(arr[j] >= pivot)
                j--;
            if(i<correctIndex && j>correctIndex)
                swap(arr[i++], arr[j--]);
        }
    
        return correctIndex;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends