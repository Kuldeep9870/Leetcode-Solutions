class Solution {
public:
    double average(vector<int>& salary) {
        int total=0;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<salary.size();i++){
            total+=salary[i];
            mini=min(mini,salary[i]);
            maxi=max(maxi,salary[i]);
        }
        total=total-mini-maxi;
        return double(total)/(salary.size()-2);
        
    }
};