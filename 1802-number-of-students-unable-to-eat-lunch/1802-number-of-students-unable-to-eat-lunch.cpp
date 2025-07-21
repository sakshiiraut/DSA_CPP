class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
       int n=students.size();
        queue<int>q;
        stack<int>st;
        int k=n-1;
         int count = 0; 
        for(int i=0;i<n;i++){
            q.push(students[i]);
            st.push(sandwiches[k]);
            k--;
        }
        while(!q.empty() && count < q.size()){
           if(q.front()==st.top()){
            q.pop();
            st.pop();
            count = 0;
        }else{
            q.push(q.front());
            q.pop();
            count++;
        }
        } 
        return q.size();
    } 
};