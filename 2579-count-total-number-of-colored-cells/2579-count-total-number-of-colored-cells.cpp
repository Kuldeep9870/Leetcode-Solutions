class Solution {
public:
    long long coloredCells(int n) {
        long long num=1LL*n;
        long long ans=1+num*(num-1)*2;
        return ans;
    }
};


/* Approach
1 + 4*1 + 4*2 + .. + 4*(n-1)
= 1 + 4 * (1 + 2 + .. + n-1)
= 1 + 4 * (n * (n-1) / 2)
= 1 + n * (n-1) * 2

*/