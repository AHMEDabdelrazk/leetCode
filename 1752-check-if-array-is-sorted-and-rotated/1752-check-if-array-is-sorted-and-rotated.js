const check = function(nums) {
    let drops = 0;
    const len = nums.length;

    for (let i = 0; i < len; i++) {
        // Compare current element with the next one (wrapping around at the end)
        if (nums[i] > nums[(i + 1) % len]) {
            drops++;
        }
    }

    // It is valid if there is 0 drops (already sorted) or exactly 1 drop (rotated)
    return drops <= 1;
};