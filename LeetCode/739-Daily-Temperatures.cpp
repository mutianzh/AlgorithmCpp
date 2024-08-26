class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> stk; // temp and index
        vector<int> res(n, 0);

        for (int i=0; i < n; i++){
            int item = temperatures[i];
            while (!stk.empty() && item > stk.top().first){
                pair<int, int> top_item = stk.top();
                stk.pop();
                res[top_item.second] = i - top_item.second;
            }
            stk.push({item, i});
        }
        return res;
    }
};
