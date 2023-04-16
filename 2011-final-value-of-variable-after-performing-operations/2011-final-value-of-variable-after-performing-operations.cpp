class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(int i=0;i<operations.size();i++){
            string action=operations[i];
            if(action=="++X"||action=="X++")
                x++;
            else
                x--;
        }
        return x;
    }
};