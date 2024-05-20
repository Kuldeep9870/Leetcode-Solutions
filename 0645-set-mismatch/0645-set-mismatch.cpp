class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<bool> visit(n+1,false);
        int repeat,loss;
        
        for(int i=0;i<n;i++){
            if(visit[nums[i]]==true)
                repeat=nums[i];
            else
                visit[nums[i]]=true;
        }
         for(int i=1;i<n+1;i++){
            if(visit[i]==false)
                loss=i;
        }
        return {repeat,loss};
    }
};