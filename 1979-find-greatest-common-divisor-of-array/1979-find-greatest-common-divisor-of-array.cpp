class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        
        for(auto i:nums){
            mini=min(mini,i);
            maxi=max(maxi,i);
        }
        while(mini!=0 && maxi!=0){
            if(maxi>=mini)
                maxi=maxi-mini;
            else
                mini=mini-maxi;
        }
        return max(maxi,mini);
    }
};