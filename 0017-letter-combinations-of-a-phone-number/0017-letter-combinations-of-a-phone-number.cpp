class Solution {
private:
    void solve(string digits,string mapping[],int index,string output,vector<string>& ans)
    {
        if(index>=digits.length())
        {
            ans.push_back(output);
            return;
        }
        
        int number=digits[index]-'0';
        string value=mapping[number];
        
        for(int i=0;i<value.length();i++)
        {
            output.push_back(value[i]);
            solve(digits,mapping,index+1,output,ans);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index=0;
        string output;
        vector<string> ans;
        if(digits.length()==0)
            return ans;
        
        solve(digits,mapping,index,output,ans);
        
        return ans;
        
        
        
    }
};