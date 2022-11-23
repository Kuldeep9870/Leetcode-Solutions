class Solution {
private:bool binaysearch(vector<int>& arr,int k)
{
    int s=0;
    int e=arr.size()-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==k)
        {
            return 1;
        }
        else if(arr[mid]<k)
        {
            s=mid+1;
        }
        else
            e=mid-1;
    }
    return false;
}
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        bool loop=true;
        while(loop)
        {
            bool res=binaysearch(nums,original);
            if(res==false)
            {
                loop=false;
            }
            else
                original=original*2;
            
        }
        return original;
        
    }
};