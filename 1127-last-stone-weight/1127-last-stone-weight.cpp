class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int n=stones.size(); 
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        while(pq.size()>0){
        if(pq.size()==1) return pq.top();
        int n=pq.top();
        pq.pop();
        int m=pq.top();
        pq.pop();
        if(n!=m){ 
        pq.push(n-m);
        }
        }
        return 0;
    }
};