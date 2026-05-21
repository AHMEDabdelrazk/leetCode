/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number}
 */
var longestCommonPrefix = function(arr1, arr2) {
    const prefix = new Set();
    for (let a of arr1) {
        while (a > 0) {
            if (prefix.has(a))
                break;
            prefix.add(a);
            a = Math.floor(a / 10);
        }
    }
    let res = 0;
    for (let b of arr2) {
        while (b > res) {
            if (prefix.has(b)) {
                res = b;
                break;
            }
            b = Math.floor(b / 10);
        }
    }
    return res ? String(res).length : 0;
};