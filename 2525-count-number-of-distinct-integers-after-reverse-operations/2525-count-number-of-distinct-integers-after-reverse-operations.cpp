class Solution {
public:
    int reverseDigit(int numb){
       int r=0;
       while(numb>0){
        r=r*10;
        r+=numb%10;
        numb=numb/10;
       }
       return r;
    } 
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            // if(s.find(nums[i])==s.end())s.insert(nums[i]);
            // int rev=reverseDigit(nums[i]);
            // if(s.find(rev)==s.end())s.insert(rev);
            s.insert(nums[i]);
            int rev=reverseDigit(nums[i]);
            s.insert(rev);
        }
        return s.size();
    }
};