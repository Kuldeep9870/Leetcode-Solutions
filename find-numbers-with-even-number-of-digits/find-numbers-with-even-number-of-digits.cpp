class Solution {
    int Nodigit(int n)
    {
        int digit=0;
        while(n>0)
            {
                digit++;
                n=n/10;
            }
        return digit;
    }
public:
    int findNumbers(vector<int>& nums) {
        
        int i=0;
        int count=0;
        
        
        while(i<nums.size())
        {
        int digit=Nodigit(nums[i]);
            
        if(digit%2==0)
            count++;
            
        i++;
        }
        return count;
        
    }
};