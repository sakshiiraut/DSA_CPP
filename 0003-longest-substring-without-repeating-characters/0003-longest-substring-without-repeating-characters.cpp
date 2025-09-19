class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     set<char>st;
     int left=0;
     int right=0;
     int maxlength=0;
     while(right<s.size()){
        if(st.find(s[right])==st.end()){
            st.insert(s[right]);
            maxlength=max(maxlength,right-left+1);
             right++;
        }else{
            st.erase(s[left]);
            left++;
        }
     }  
     return maxlength; 
    }
};