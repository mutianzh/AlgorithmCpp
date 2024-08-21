class Solution {
public:

    double myPow(double x, int n) {
        if (n == 0) {return 1;}
        int quotient = n / 2;
        int rem = n % 2;
        double res = myPow(x, quotient);
        if (rem == 0) {
            return res * res;
        } else {
            if (rem < 0){return res * res * (1/x);}
            else {return res * res * x;}
        }
    }
};
