class Solution {
public:
    double myPow(double x, int n) {
        double ans=x;
        if(n<0)
        {
            ans=1/ans;
            n=abs(n);
        }
        if(pow(ans,n)>INT_MAX)
            return 0;
        
        ans=pow(ans,n);
        
        return ans;
        
    }
};