class Solution {
public:
    vector<int> mergeArray(vector<int>& nums1, vector<int>& nums2){
        vector<int> sorted;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                sorted.push_back(nums1[i]);
                i++;
            }
            else{
                sorted.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            sorted.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            sorted.push_back(nums2[j]);
            j++;
        }
        return sorted;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted;
        sorted=mergeArray(nums1,nums2);
        double median;
        int n=sorted.size();
        if(n%2!=0){
            int pos=n/2;
            median=double(sorted[pos]);
        }
        else{
            int pos=n/2;
            median=double(sorted[pos]+sorted[pos-1])/2;;
        }
        return median;
    }
};