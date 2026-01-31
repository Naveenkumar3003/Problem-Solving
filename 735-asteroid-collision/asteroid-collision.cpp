class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int a : asteroids){
            bool alive=true;
            while(!st.empty() && st.top()>0 && a<0){
                if(abs(st.top())<abs(a)){
                    st.pop();
                }
                else if(abs(st.top())>abs(a)){
                    alive=false;
                    break;
                }
                else{
                    st.pop();
                    alive=false;
                    break;
                }
            }
            if(alive) st.push(a);
        }
        vector<int> result(st.size());
        for (int i = result.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};