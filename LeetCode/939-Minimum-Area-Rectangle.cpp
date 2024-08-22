class Solution {
public:
    unordered_map<int, unordered_set<int>> hashMap;
    int minAreaRect(vector<vector<int>>& points) {
        for (auto& p: points){
            hashMap[p[0]].insert(p[1]);
        }
        int n = points.size();
        int min_area = 0;
        for (int i=0; i < n-1; i++){
            for (int j=i+1; j < n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x1 != x2 && y1 != y2){
                    if (hashMap[x1].count(y2) && hashMap[x2].count(y1)) {
                        int area = abs(x1 - x2) * abs(y1 - y2);
                        if (min_area == 0) {min_area = area;}
                        else {min_area = min(min_area, area);}
                    }
                }
            }
        }
        return min_area;

    }
};
