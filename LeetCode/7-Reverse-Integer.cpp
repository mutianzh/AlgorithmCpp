class Solution {
public:
    int reverse(int x) {
        // const int MAX_INTEGER = pow(2, 32) - 1;
        // const int MIN_INTEGER = -pow(2, 32);
        const int MIN_INTEGER = -2147483648; // -2^31
        const int MAX_INTEGER = 2147483647;  // 2^31 - 1
        // if (x > pow(2, 32) - 1 || x < -pow(2, 32)) {return 0;}
        if (x < 10 && x > -10) {return x;}

        int res = 0;
        while (x != 0){
            int digit = x % 10;
            x /= 10;

            if (res > MAX_INTEGER / 10 || (res == MAX_INTEGER / 10 && digit > MAX_INTEGER % 10)){
                return 0;
            }

            if (res < MIN_INTEGER / 10 || (res == MIN_INTEGER / 10 && digit < MIN_INTEGER % 10)) {
                return 0;
            }


            res = res * 10 + digit;
            
        }
        return res;
    }
};
