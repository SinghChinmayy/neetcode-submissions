class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int days = temperatures.size();
        vector<int> result(days, 0);
        if (temperatures.size() == 1) return result;
        //    monotonously decreasing stack
        // pair[val,index]
        stack<pair<int, int>> st;
        st.push({temperatures[0], 0});
        for (int i = 1; i < days; i++) {
            if (!st.empty() && temperatures[i] > st.top().first) {
                pair<int, int> t1 = st.top();
                st.pop();
                int diff = i - t1.second;
                result[t1.second] = diff;

                while (!st.empty() && temperatures[i] > st.top().first) {
                    pair<int, int> t2 = st.top();
                    st.pop();
                    int diff = i - t2.second;
                    result[t2.second] = diff;
                }

                st.push({temperatures[i], i});
            }
            if (temperatures[i] <= st.top().first) {
                st.push({temperatures[i], i});
            }
        }
        return result;
    }
};
