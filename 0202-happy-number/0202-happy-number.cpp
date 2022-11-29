class Solution {
private:
    int squaresum(int n)
    {
        int sum=0;
        while(n>0)
        {
            int d=n%10;
            n=n/10;
            sum=sum+d*d;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        bool loop=true;
        while(loop)
        {
            int sum=squaresum(n);
            if(sum!=7 && sum>1 && sum<=9)
            {
                return false;
            }
            else if(sum==1 || sum==7)
            {
                loop=false;
            }
            n=sum;
        }
        return true;
    }
};