//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {
        // code here
        int i=N-1;
        bool loop=true;
        while(loop && i>=0)
        {
            arr[i]=arr[i]+1;
            if(i==0 && arr[i]>=10)
            {
                arr[i]=arr[i]%10;
                arr.insert(arr.begin(),1);
                loop=false;
            }
            else if(arr[i]>=10)
            {
                arr[i]=arr[i]%10;
                loop=true;
                i--;
            }
            else
            loop=false;
        }
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends