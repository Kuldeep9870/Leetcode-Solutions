//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countNumbers(int n) {
        // code here
        int count=0;
        while(n>0)
        {
            int num=n;
            bool check=false;
            while(num>0)
            {
                int d=num%10;
                if(d==1 || d==2||d==3||d==5||d==4)
                check=true;
                else
                check=false;
                
                if(check==false)
                break;
                
                
                num=num/10;
            }
            if(check==true)
            count++;
            
            n--;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countNumbers(n);
        cout << ans << "\n";
    }
    return 0;
}


// } Driver Code Ends