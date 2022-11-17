//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int getSum(int a[], int n) {
        // Your code goes here
        int sum=0;
        int i=0,j=n-1;
        while(i<=j)
        {
            sum=sum+a[i];
            if(i!=j)
            sum=sum+a[j];
            
            i++;j--;
        }
        return sum;
        
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
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.getSum(a, n) << endl;
    }

    return 0;
}
// } Driver Code Ends