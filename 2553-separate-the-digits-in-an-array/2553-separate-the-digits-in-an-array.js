/**
 * @param {number[]} nums
 * @return {number[]}
 */
var separateDigits = function(nums) {
    let ans = [];

    for (let x of nums)
        for (let c of x.toString())
            ans.push(Number(c));

    return ans;
};