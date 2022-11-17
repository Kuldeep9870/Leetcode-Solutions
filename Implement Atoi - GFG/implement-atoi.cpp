//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int s=0;
        int num=0;
        bool neg=false;
        if(str[0]=='-')
        {
            neg=1;
            s=1;
        }
        for(int i=s;i<str.length();i++)
        {
            if(str[i]>='0' && str[i]<='9')
            {
                num=num*10+(str[i]-'0');
            }
            else
            return -1;
        }
        if(neg)
        {
            num=-1*num;
        }
        return num;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends