class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> temp;
        int rem=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                rem++;
                temp.push_back(arr[i]);
                temp.push_back(0);
            }
            else
                temp.push_back(arr[i]);
        }
        while(rem--)
        {
            temp.pop_back();
        }
        arr.clear();
        arr=temp;
        
    }
};