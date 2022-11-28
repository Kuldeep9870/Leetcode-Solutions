class Solution {
public:
    int thirdMax(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        vector<int> arr;
        int size=0;
        for(auto i:m)
        {
            int element=i.first;
            arr.push_back(element);
            size++;
        }
        if(size==1)
            return arr[0];
        else if(size==2)
            return arr[1];
        else
            return arr[size-3];
    }
};