class Solution {
public:
    int addDigits(int num) {
        while(10 <= num) {
            int next = 0;
            while(num) {
                next += num % 10;
                num /= 10;
            }
            num = next;
        }
        return num
    }
};
