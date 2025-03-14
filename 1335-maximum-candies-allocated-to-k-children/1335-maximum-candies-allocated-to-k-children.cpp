class Solution {
    #define ll long long 
public:
    bool canAssign(ll &mid,vector<int>&candies,ll &k){
        ll count =0;
        for(ll ele : candies){
            if(ele>=mid){
                count+=ele/mid;
            }
        }
        return count>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        ll lo=1;
        ll n=candies.size();
        ll hi= *max_element(candies.begin(),candies.end());
        ll ans=0;
        while(lo<=hi){
            ll mid=lo+((hi-lo)/2);
            if(canAssign(mid,candies,k)){
                ans=mid;
                lo=mid+1;
            }else {
                hi=mid-1;
            }
        }
        return ans;
    }
};