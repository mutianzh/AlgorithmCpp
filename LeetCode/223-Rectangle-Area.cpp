class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int overlapped_x = 0;
        int overlapped_y = 0;
        // x dim
        if (ax1 <= bx1 && bx1 <= ax2) {overlapped_x = min(ax2, bx2) - bx1;}
        if (bx1 <= ax1 && ax1 <= bx2) {overlapped_x = min(ax2, bx2) - ax1;}


        // y dim
        if (ay1 <= by1 && by1 <= ay2) {overlapped_y = min(ay2, by2) - by1;}
        if (by1 <= ay1 && ay1 <= by2) {overlapped_y = min(ay2, by2) - ay1;}

        int area = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - overlapped_x * overlapped_y;
        return area;
        
    }
};
