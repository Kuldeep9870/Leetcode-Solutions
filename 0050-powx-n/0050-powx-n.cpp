class Solution {
public:
    double power(double a,int b)
{
    if(b==0)
    return 1;

    if(b==1)
    return a;

    //recursive call
    double ans=power(a,b/2);

    if(b%2==0)
    return ans*ans;
    else
    return a*ans*ans;
    }


    double myPow(double x, int n) {
        if(n<0)
        {
            x=1/x;
            n=labs(n);
        }
        double ans=power(x,n);
        if(ans>INT_MAX)
            return 0;
        else
            return ans;
        
    }
};