class Solution {
public:
    int sumOfDigit(int n){
        int sum=0;
        while(n>0){
            int rem=n%10;
            sum+=rem;
            n=n/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        for(int i=1;i<=n;i++){
            int m=sumOfDigit(i);
            mp[m]++;
        }
         int s;
    int maxSize = 0;
        for (auto& p : mp) {
            maxSize = max(maxSize, p.second); // Find max group size
        }

        int count = 0;
        for (auto& p : mp) {
            if (p.second == maxSize) count++; // Count how many groups have the max size
        }

        return count;
    }
};