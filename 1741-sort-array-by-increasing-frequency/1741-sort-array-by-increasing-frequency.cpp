class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(auto it : mp){
            pq.push({it.second,-it.first});
        }
        vector<int>v;
        while(pq.size()>0){
            auto [f, Val] = pq.top(); 
            pq.pop();
            for(int i=0;i<f;i++){
                v.push_back(-Val);
            }
        }
        return v;
    }
};