//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans=new int[2];
        bool miss=true,repeat=true;
        int count[n+1]={0};
        for(int i=0;i<n;i++)
        {
            count[arr[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(miss && count[i]==0)
            {
                ans[1]=i;
                miss=false;
            }
            if(repeat && count[i]==2)
            {
                ans[0]=i;
                repeat=false;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends