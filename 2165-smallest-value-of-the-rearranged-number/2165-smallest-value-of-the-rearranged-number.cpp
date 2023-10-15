bool small(int a,int b){
        return to_string(a)+to_string(b)<to_string(b)+to_string(a);
}
bool large(int a,int b){
        return to_string(a)+to_string(b)>to_string(b)+to_string(a);
}

class Solution {
public:
    long long largest(vector<int>& nums) {
        sort(nums.begin(),nums.end(),large);
        
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans*10 +nums[i];
        }
        
        
        
        return ans;
    }
    long long smallest(vector<int>& digit) {
        sort(digit.begin(),digit.end(),small);

        //count zeros in start of digit
        int count=0;
        for(int i:digit){
            if(i==0)
                count++;
            else
                break;
        }
        
        if(count==digit.size())
            return 0;
        
        //answer formation
        long long ans=digit[count];
        ans=ans*pow(10,count);
        for(int i=count+1;i<digit.size();i++){
            ans=ans*10 +digit[i];
        }
        
        return ans;
    }
    long long smallestNumber(long long num) {
        vector<int> digit;
        long long n=num;
        bool negative=false;
        if(num<0){
            negative=true;
            n=-1*n;
        }
        
        while(n>0){
            int r=n%10;
            digit.push_back(r);
            n/=10;
        }
        // for(int i:digit)
        //     cout<<i<<" ";
        
        if(negative){
            return -1*largest(digit);
        }
        
        return smallest(digit);
        
        
    }
};