class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int minEven=INT_MAX;
        int maxOdd=INT_MIN;
        for(auto it:mp){
           if (it.second % 2 == 1) {
                maxOdd = max(maxOdd, it.second);
            } else {
                minEven = min(minEven, it.second);
            }
        }
        return maxOdd-minEven;
    }
};