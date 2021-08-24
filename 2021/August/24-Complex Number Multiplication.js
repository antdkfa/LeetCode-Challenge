/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var complexNumberMultiply = function(num1, num2) {
    const num1s = num1.split('+');
    const num2s = num2.split('+');
    console.log(num1s, num2s);
    let a=parseInt(num1s[0]), b=parseInt(num2s[0]), c='', d='';
    
    for(let i=0;i<num1s[1].length-1;i++) {
        c +=num1s[1][i];
    }
    
    for(let i=0;i<num2s[1].length-1;i++){
        d +=num2s[1][i];
    }
    
    c = parseInt(c), d = parseInt(d);
    return a*b-(c*d)+'+'+(a*d+b*c)+'i'; 
};
