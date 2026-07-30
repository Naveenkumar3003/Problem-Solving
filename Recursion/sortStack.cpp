class Solution {
  public:
    void sortedInsert(stack<int> &st,int val){
        if(st.empty() || st.top()<=val){
            st.push(val);
            return;
        }
        int data=st.top();
        st.pop();
        sortedInsert(st,val);
        st.push(data);
    }
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int val=st.top();
        st.pop();
        sortStack(st);
        sortedInsert(st,val);
    }
};
