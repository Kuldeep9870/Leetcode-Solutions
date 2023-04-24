class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)
            return stones[0];
        priority_queue<int> pq;
        pq.push(0);
        for(auto i:stones){
            pq.push(i);
        }
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x!=y){
                pq.push(abs(y-x));
            }
        }
        cout<<pq.size()<<" ";
        return pq.top();
        
    }
};