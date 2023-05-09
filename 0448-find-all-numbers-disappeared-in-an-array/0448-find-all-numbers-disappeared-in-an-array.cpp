class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> track(nums.size()+1,0);
        for(auto i:nums){
            track[i]=1;
        }
        vector<int> ans;
        for(int i=1;i<=nums.size();i++){
            if(track[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};