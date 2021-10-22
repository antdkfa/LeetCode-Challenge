/**
 * @param {string} s
 * @return {string}
 */
var frequencySort = function(s) {
    let ans = '';
    let used = {};
    for(let i=0;i<s.length;i++){
        if(used[s[i]]) {
            used[s[i]]++;
        } else {
            used[s[i]] = 1;
        }
    }
    
    let items = [];
    Object.keys(used).forEach(key => { 
        items.push({cnt: used[key], letter: key});                    
    })
    
    items.sort(function(a,b) {
        if(a.cnt<b.cnt) return 1;
        else return -1;
    });
    
    items.forEach(item => {
        for(let i=0;i<item.cnt;i++) ans += item.letter;
    })
    return ans;
}; 
