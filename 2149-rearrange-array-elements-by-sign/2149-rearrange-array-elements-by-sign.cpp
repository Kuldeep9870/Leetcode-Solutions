class Solution {
public:
    // APPROACH 2 : BETTER APPROACH
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int pos=0;
        int neg=1;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                ans[pos]=nums[i];
                pos=pos+2;
            }
            else{
                ans[neg]=nums[i];
                neg=neg+2;
            }
        }
        return ans;
    }
};

 //APPROACH 1 : BRUTE FORCE

// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int> pos;
//         vector<int> neg;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             if(nums[i]>=0)
//                 pos.push_back(nums[i]);
//             else
//                 neg.push_back(nums[i]);
//         }
//         for(int i=0;i<nums.size()/2;i++){
//             //for pos
//             nums[2*i]=pos[i];
//             //for negative
//             nums[2*i+1]=neg[i];
//         }
//         return nums;
//     }
// };