class Solution {
public:
    string largestGoodInteger(string num) {
        priority_queue<char>pq;
        for(int i=0;i<num.size()-2;i++){
            if(num[i]==num[i+1] && num[i]==num[i+2]) {
                pq.push(num[i]);
            }
        }
        if (pq.empty()) return "";
        string s="";
        for(int i=0;i<3;i++){
           s+=pq.top();
        }
        return s;
    }
};