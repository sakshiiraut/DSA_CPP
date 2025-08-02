class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
             mp[nums[i]]++;
        }
        vector<pair<int, int>> v; // changed vector<int> to vector<pair<int,int>>
        for (auto it : mp) {
            v.push_back({it.second, it.first}); // {frequency, element}
        }

        // Sort in descending order of frequency
        sort(v.begin(), v.end(), greater<pair<int, int>>()); // corrected sort direction and order

        // Extract top k elements
        vector<int> ans; // you forgot to declare this
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].second); // push element (not frequency)
        }
      return ans;
    }
};