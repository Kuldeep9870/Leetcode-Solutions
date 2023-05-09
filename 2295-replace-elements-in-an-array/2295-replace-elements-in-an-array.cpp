class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
       unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        for(int i=0;i<operations.size();i++){
            int exist=operations[i][0];
            int replace=operations[i][1];
            int pos=m[exist];
            
            //updation
            nums[pos]=replace;
            m.erase(exist);
            m[replace]=pos;
        }
        return nums;
    }
};