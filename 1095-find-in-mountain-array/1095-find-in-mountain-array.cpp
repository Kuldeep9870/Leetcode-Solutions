/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        //find peak element
        int s=0;
        int n=mountainArr.length()-1;
        int e=n;
        while(s<e)
        {
            int mid=s+(e-s)/2;
            int midelement=mountainArr.get(mid);
            int midnext=mountainArr.get(mid+1);
            if(midelement<midnext)
            {
                s=mid+1;
            }
            else
            {
                e=mid;
            }
        }
        int peak = s;
        
        
        //find element in increasing 
        s=0;
        e=peak;
        while(s<=e){
            int mid=s+(e-s)/2;
            int midelement=mountainArr.get(mid);
            if(midelement==target)
                return mid;
            else if(midelement<target)
                s=mid+1;
            else
                e=mid-1;
        }
        
        //find element in decreasing
        s=peak+1;
        e=n;
        
        while(s<=e){
            int mid=s+(e-s)/2;
            cout<<mid;
            int midelement=mountainArr.get(mid);
            if(midelement==target)
                return mid;
            else if(midelement<target)
                 e=mid-1;
            else
                s=mid+1;
               
        }
        
        return -1;
    }
};