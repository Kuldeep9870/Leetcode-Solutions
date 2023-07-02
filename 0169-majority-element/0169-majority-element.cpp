class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int vote=0;
        int candidate=-1;
        
        for(int i=0;i<n;i++){
            if(vote==0){
                vote=1;
                candidate=nums[i];
            }
            else if(candidate==nums[i])
                vote++;
            else
                vote--;
        }
        
        //counting
        int count=0;
        for(int i=0;i<n;i++){
            if(candidate==nums[i])
                count++;
        }
        
        if(count>n/2)
            return candidate;
        
        return -1;
    }
};