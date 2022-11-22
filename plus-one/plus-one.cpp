class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int i=n-1;
        bool loop=true;
        while(loop && i>=0)
        {
            digits[i]=digits[i]+1;
            if(i==0 && digits[i]>=10)
            {
                digits[i]%=10;
                digits.insert(digits.begin(),1);
                i--;
            }
            else if(digits[i]>=10)
            {
                digits[i]%=10;
                loop=true;
                i--;
            }
            else
                loop=false;
        }
        return digits;
        
        
    }
};