/**
 * @param {string[]} emails
 * @return {number}
 */
var numUniqueEmails = function(emails) {
    const visited = {};
    let ans = 0;
    
    emails.forEach(email => {
        const token = email.split("@");
        const local = token[0].split("+");
        
        let f = '';
        for(let i=0;i<local[0].length;i++) {
            if(local[0][i] != '.') {
                f += local[0][i];
            }
        }
        
        const nowEmail = f + '@' + token[1];
        if(!visited[nowEmail]) {
            visited[nowEmail] = 1;
            ans++;
        }
    })
    
    return ans;
};
