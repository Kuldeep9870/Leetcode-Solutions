//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

int getceil(int arr[], int n, int x){
	int s=0;
	int e=n-1;
	int ans=-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]==x){
			return x;
		}
		else if(arr[mid]>x){
			ans=arr[mid];
			e=mid-1;
		}
		else
			s=mid+1;
	}
	return ans;
}
int getfloor(int arr[], int n, int x){
	int s=0;
	int e=n-1;
	int ans=-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]==x){
			return x;
		}
		else if(arr[mid]<x){
			ans=arr[mid];
			s=mid+1;
		}
		else
			e=mid-1;
	}
	return ans;
}
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    sort(arr,arr+n);
    return {getfloor(arr,n,x),getceil(arr,n,x)};
    
}