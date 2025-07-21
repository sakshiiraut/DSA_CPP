class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
       
       vector<int>ans(n,0);
       stack<int>st;
    
       for(int i=n-1;i>=0;i--){
        int count = 0;
        while(!st.empty() && heights[i]>st.top()) {
        st.pop();
        count++;
        }
        if(st.size()!=0) count++;
        
        ans[i]=count;
        st.push(heights[i]);
       }  
      
       return ans;
    }
};