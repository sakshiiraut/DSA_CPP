class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        int maxNum=0;
        for(auto t:m){
            if(t.first==t.second) maxNum=max(maxNum,t.first);
        }
        int count= (maxNum==0)?-1:maxNum;
        return count;
    }
};