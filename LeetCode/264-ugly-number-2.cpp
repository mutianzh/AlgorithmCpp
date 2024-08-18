// Min heap solution
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> factors = {2, 3, 5};
        priority_queue <long, vector<long>, greater<long>> mheap;
        unordered_set<long> visited;

        mheap.push(1);
        visited.insert(1);

        long cur;
        long v;
        for (int i=0; i < n; i++) {
            cur = mheap.top();
            mheap.pop();
            for (int value: factors){
                v = cur * value;
                if (visited.find(v) == visited.end()){
                    mheap.push(v);
                    visited.insert(v);
                }

            }
        }
        return cur;
    }
};

// Three pointers solution
class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        vector<int> numbers = {1};
        for (int i=1; i<n; i++){
            int n2 = numbers[i2] * 2;
            int n3 = numbers[i3] * 3;
            int n5 = numbers[i5] * 5;
            int new_num = min(n2, min(n3, n5));
            numbers.push_back(new_num);
            if (new_num == n2) {i2++;}
            if (new_num == n3) {i3++;}
            if (new_num == n5) {i5++;}
        }
        return numbers[n-1];

    }
