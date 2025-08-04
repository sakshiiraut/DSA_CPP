class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
       unordered_map<char,int>mp;
       int n=s.size();
       for(int i=0;i<n;i++){
        mp[s[i]]++;
       } 
       string str="";
       priority_queue<pair<char,int>>pq;
       for(auto it:mp){
        pq.push({it.first,it.second});
       }
       while(pq.size()>0){
        auto [ele,freq]=pq.top();
        pq.pop();
        int cnt = min(freq, repeatLimit);  
        for (int i = 0; i < cnt; i++) {
                str += ele;
         }
        freq -= cnt;
        if(freq>0){
            if (pq.empty()) break;
            auto [ele1,freq1]=pq.top();
             pq.pop();
            str+=ele1;
            freq1--;
           if (freq1 > 0) pq.push({ele1,freq1});
            pq.push({ele,freq});
        }        
         }
         return str;
       }
    };