class Solution {
private:
    int digitsum(int n)
    {
        int sum=0;
        while(n>0)
        {
            int d=n%10;
            n=n/10;
            sum=sum+d;
        }
        return sum;
    }
public:
    int addDigits(int num) {
        bool loop=true;
        int sum;
        while(loop)
        {
            sum=digitsum(num);
            if(sum<=9)
            {
                loop=false;
            }
            else
            {
                num=sum;
            }
        }
        return sum;
        
    }
};