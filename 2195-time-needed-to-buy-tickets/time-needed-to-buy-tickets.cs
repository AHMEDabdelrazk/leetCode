using System.Collections.Generic;

public class Solution {
    public int TimeRequiredToBuy(int[] tickets, int k) {
        int time = 0;
        Queue<int> queue = new Queue<int>();

        // Step 1: Fill the queue with indices 0 to n-1
        for (int i = 0; i < tickets.Length; i++) {
            queue.Enqueue(i);
        }

        // Step 2: Simulate the process
        while (queue.Count > 0) {
            time++;
            int personIndex = queue.Dequeue();
            
            // Person buys 1 ticket
            tickets[personIndex]--;

            // Check if it was person k and they are done
            if (personIndex == k && tickets[personIndex] == 0) {
                return time;
            }

            // If they still need more tickets, go to the back of the line
            if (tickets[personIndex] > 0) {
                queue.Enqueue(personIndex);
            }
        }

        return time;
    }
}