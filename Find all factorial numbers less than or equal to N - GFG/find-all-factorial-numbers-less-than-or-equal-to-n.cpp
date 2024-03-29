//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void factorial(long long n,long long num,long long N,vector<long long>&ans){
        if(n>N){
            return;
        }
        if(n<=N){
            ans.push_back(n);
        }
        factorial(n*num,num+1,N,ans);
    }
    vector<long long> factorialNumbers(long long N)
    {
        // Write Your Code here
        vector<long long> ans;
        if(1<=N)
        ans.push_back(1);
        
        factorial(1*2,3,N,ans);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for(auto num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends