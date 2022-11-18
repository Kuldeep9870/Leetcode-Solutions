//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve(string S,int index,vector<string> &ans )
	    {
	        //base case
	        if(index>=S.length())
	        {
	            ans.push_back(S);
	            return;
	        }
	        
	        for(int j=index;j<S.length();j++)
	        {
	            swap(S[index],S[j]);
	            
	            solve(S,index+1,ans);
	            
	            
	            //backtrack to correct and revert the string to original changed during repetive recursive call
	            swap(S[index],S[j]);
	        }
	    }
	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		   int index=0;
		   vector<string> ans;
		  solve(S,index,ans);
		  
		  
		  unordered_set<string> s;
		  for(auto i:ans)
		  {
		      s.insert(i);
		  }
		  ans.clear();
		  for(auto i:s)
		  {
		      ans.push_back(i);
		  }
		  sort(ans.begin(),ans.end());
		  return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends