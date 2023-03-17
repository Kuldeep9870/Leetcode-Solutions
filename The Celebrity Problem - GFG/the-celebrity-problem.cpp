//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // step 1;push in stack 
        stack<int> s;
        for(int i=0;i<n;i++)
        s.push(i);
        
        //step2: geta and b then compare
        int a,b;
        while(s.size()>1){
            a=s.top();
            s.pop();
            
            b=s.top();
            s.pop();
            
            if(M[a][b]==1)
            s.push(b);
            else
            s.push(a);
        }
        int ans=s.top();
        //step 3:verify
        int zerocount=0;
        bool rowcheck=false;
        for(int i=0;i<n;i++)
        if(M[ans][i]==0)
        zerocount++;
        
        if(zerocount==n)
        rowcheck=true;
        
        int onecount=0;
        bool colcheck=false;
        for(int i=0;i<n;i++)
        if(M[i][ans]==1)
        onecount++;
        
        if(onecount==n-1)
        colcheck=true;
        
        if(rowcheck && colcheck)
        return ans;
        else
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends