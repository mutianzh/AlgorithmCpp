class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) {return false;}
        if (n == 1) {return true;}
        int quotient = n / 2;
        int remainder = n % 2;
        if (remainder == 0){return isPowerOfTwo(quotient);}
        else {return false;}

    }
};
