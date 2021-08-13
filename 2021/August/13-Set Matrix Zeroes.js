/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    const n = matrix.length, m = matrix[0].length;
    var row = new Array(n).fill(0);
    var col = new Array(m).fill(0);
    
    for(var i=0;i<n;i++) {
        for(var j=0;j<m;j++){
            if(!matrix[i][j]) {
                row[i] = 1, col[j] = 1;
            }
        }
    }
    
    for(var i=0;i<n;i++){
        for(var j=0;j<m;j++){
            if(row[i] || col[j]) matrix[i][j] = 0;
        }
    }
};
