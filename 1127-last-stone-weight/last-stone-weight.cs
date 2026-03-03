using System;
using System.Collections.Generic;

public class Solution {
    public int LastStoneWeight(int[] stones) {
        // We use a Max-Heap by passing a comparer that reverses the order
        // This ensures the heaviest stones are at the top
        PriorityQueue<int, int> maxHeap = new PriorityQueue<int, int>(Comparer<int>.Create((a, b) => b.CompareTo(a)));

        // Step 1: Add all stones to the heap
        foreach (int stone in stones) {
            maxHeap.Enqueue(stone, stone);
        }

        // Step 2: Smash stones until 0 or 1 stone remains
        while (maxHeap.Count > 1) {
            int y = maxHeap.Dequeue(); // Heaviest
            int x = maxHeap.Dequeue(); // Second heaviest

            if (x != y) {
                int remaining = y - x;
                maxHeap.Enqueue(remaining, remaining);
            }
        }

        // Step 3: Return the result
        return maxHeap.Count == 0 ? 0 : maxHeap.Peek();
    }
}