/**
 * @param {string} palindrome
 * @return {string}
 */
var breakPalindrome = function(palindrome) {
    let arr = palindrome.split('');
    if(arr.length === 1) {
        arr[0] = "";
    } else if(arr[0] != 'a') {
        arr[0] = 'a';
    } else {
        let idx = 0, cnt = 0;
        for(let i=0;i<arr.length;i++) {
            if(!idx && arr[i] != 'a') idx = i;
            if(arr[i] === 'a') cnt++;
        }
        
        if(arr.length -1 <= cnt) {
            arr[arr.length - 1] = 'b';
        } else {
            arr[idx] = 'a';
        }
    }
    
    arr = arr.join('');
    return arr;
};
