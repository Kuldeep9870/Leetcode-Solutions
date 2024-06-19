class Solution {
public:
    int reverse(int x) { 
        int ans=0;
        while(x!=0){
            int r=x%10;
            
            ans=ans*10+r;
            x/=10;
        }
        return ans;
    }
    bool isSameAfterReversals(int num) {
        
        int doubleRev=reverse(reverse(num));
        
        return (num==doubleRev?true :false);
    }
};