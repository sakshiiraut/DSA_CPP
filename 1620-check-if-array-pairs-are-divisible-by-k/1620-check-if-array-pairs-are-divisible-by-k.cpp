class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
         int n=arr.size();
         unordered_map<int,int>mp;
         for(int i=0;i<n;i++){
            arr[i]=((arr[i]%k)+k)%k;
         }
         for(int i=0;i<n;i++){
            mp[arr[i]]++;
         }
         for(auto it:mp){
            if(it.first==0){
                if((it.second%2)!=0) return false;
            }
            else { 
            int t=k-it.first;
            if(mp.find(t)==mp.end()) return false;
            if(mp[it.first]!=mp[t]) return false;}
         }
         return true;
    }
};