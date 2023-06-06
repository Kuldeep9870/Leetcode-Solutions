class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            vector<int> arr;
            for(int j=l[i];j<=r[i];j++){
                arr.push_back(nums[j]);
            }
            
            //checking for arithmetic progression
            sort(arr.begin(),arr.end());
            int d=arr[1]-arr[0];
            bool flag=true;
            for(int k=1;k<arr.size()-1;k++){
                if(d!=(arr[k+1]-arr[k])){
                    flag=false;
                    break;
                }
            }
            ans.push_back(flag);
            arr.clear();
        }
        return ans;
    }
};