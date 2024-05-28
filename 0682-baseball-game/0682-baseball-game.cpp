class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        
        int n=operations.size();
        for(int i=0;i<n;i++){
            if(operations[i]=="+"){
                int val1=s.top();
                s.pop();
                int val2=s.top();
                s.pop();
                s.push(val2);
                s.push(val1);
                s.push(val1+val2);
            }
            else if(operations[i]=="D"){
                int val=s.top();
                s.push(2*val);
            }
            else if(operations[i]=="C"){
                s.pop();
            }
            else{
                int val = stoi(operations[i]);
                s.push(val);
            }
        }
        int total=0;
        while(!s.empty()){
            total+=s.top();
            s.pop();
        }
        return total;
    }
};