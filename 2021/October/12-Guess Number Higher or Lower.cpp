/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    
    typedef long long ll;
    
    int guessNumber(int n) {
        int ans = 0;
        
        ll left = 0, right = 2147483647;
        while(left <= right) {
            ll mid = (left + right)/2;
            int now = guess(mid);
            if(!now) {
                ans = mid;
                break;
            } else if(now == -1) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};
