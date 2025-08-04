class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      sort(people.begin(),people.end());  
      int n=people.size();
      int k=0;
      int count=0;
      while(k<n){
        int i=k;
         int sum=0;
         int personCount=0;
        while(i < n && personCount < 2 && sum+people[i]<=limit){
           sum+=people[i];
           i++;
           personCount++;
        }
        count++;
        if (i == k) i++; 
        k=i;
      }
      return count;
    }
};