/**
 * @param {number[]} releaseTimes
 * @param {string} keysPressed
 * @return {character}
 */
var slowestKey = function(releaseTimes, keysPressed) {
    releaseTimes.unshift(0);
    const duration = {};
    let longest = -1, ans = '';
    
    for(let i=0;i<keysPressed.length;i++) {
        let releaseTime = releaseTimes[i+1] - releaseTimes[i]; 
        if(duration[keysPressed[i]] === undefined) {
            duration[keysPressed[i]] = releaseTime;
        } else {
            duration[keysPressed[i]] = Math.max(duration[keysPressed[i]], releaseTime);
        }
        
        if(longest < duration[keysPressed[i]]) {
            longest = duration[keysPressed[i]];
            ans = keysPressed[i];
        }
        else if(longest === duration[keysPressed[i]] && ans < keysPressed[i]) {
            ans = keysPressed[i];
        }
    }
    
    return ans;
};
