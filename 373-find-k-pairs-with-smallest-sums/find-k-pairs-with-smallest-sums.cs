using System;
using System.Collections.Generic;

public class Solution {
    public IList<IList<int>> KSmallestPairs(int[] nums1, int[] nums2, int k) {
        var result = new List<IList<int>>();
        if (nums1.Length == 0 || nums2.Length == 0 || k == 0) return result;

        // Min-Heap stores: {sum, indexInNums1, indexInNums2}
        // We prioritize based on the sum (the first element of the tuple)
        var minHeap = new PriorityQueue<(int i, int j), int>();

        // Step 1: Initialize heap with (nums1[i], nums2[0])
        // We only need to go up to k or nums1.Length
        for (int i = 0; i < Math.Min(nums1.Length, k); i++) {
            minHeap.Enqueue((i, 0), nums1[i] + nums2[0]);
        }

        // Step 2: Extract k times
        while (k > 0 && minHeap.Count > 0) {
            var (i, j) = minHeap.Dequeue();
            result.Add(new List<int> { nums1[i], nums2[j] });
            k--;

            // Step 3: If there's a next element in nums2 for the current nums1[i]
            if (j + 1 < nums2.Length) {
                minHeap.Enqueue((i, j + 1), nums1[i] + nums2[j + 1]);
            }
        }

        return result;
    }
}