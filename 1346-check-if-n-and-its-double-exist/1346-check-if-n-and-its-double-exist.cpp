class Solution {
private:bool binaysearch(vector<int>& arr,int element)
{
    int s=0;
    int e=arr.size()-1;
    int k=element*2;
    if(k==0)
        return false;
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
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
                count++;
            if(count>=2)
                return true;
        }
        for(int i=0;i<arr.size();i++)
        {
            bool res=binaysearch(arr,arr[i]);
            if(res)
            {
                return true;
            }
        }
        return false;
        
        
    }
};