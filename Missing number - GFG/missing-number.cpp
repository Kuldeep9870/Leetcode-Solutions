//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int missingNumber(int a[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i=0, n;
		cin>>n;
		int a[n+5];
		for(i=0;i<n-1;i++)
			cin>>a[i];
			
		cout<<missingNumber(a, n)<<endl;
	}
}
// } Driver Code Ends


int missingNumber(int A[], int N)
{
    // Your code goes here
    /*
    //summation method
    
    int sum=N*(N+1)/2;
    int cal=0;
    for(int i=0;i<N-1;i++)
        cal=cal+A[i];
        
    return sum-cal;
    */
    
    //XOR approach
    
    int xor1=0;
    int xor2=0;
    
    for(int i=0 ;i<N-1;i++){
        xor1=xor1^A[i];
        
        
        //xor 1 to n-1
        xor2=xor2^(i+1);
    }
    
    //xor n int xor2
    xor2=xor2^N;
    
    return xor1^xor2;
    
}