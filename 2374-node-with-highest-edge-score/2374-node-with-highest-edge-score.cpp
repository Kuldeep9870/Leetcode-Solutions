class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<long long int> score(n);
        long long maxScore=-1;
        int pos=-1;
        for(int i=0;i<n;i++){
            score[edges[i]]+=i;
        }
        for(int i=0;i<n;i++){
            if(score[i]>maxScore){
                maxScore=score[i];
                pos=i;
            }
        }
        return pos;
       
    }
};