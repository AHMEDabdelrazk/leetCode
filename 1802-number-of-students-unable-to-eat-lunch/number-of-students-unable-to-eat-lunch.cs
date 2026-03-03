public class Solution {
    public int CountStudents(int[] students, int[] sandwiches) {
        int circularCount = 0;
        int squareCount = 0;

        // Step 1: Count student preferences
        foreach (int s in students) {
            if (s == 0) circularCount++;
            else squareCount++;
        }

        // Step 2: Try to serve each sandwich in order
        foreach (int sandwich in sandwiches) {
            if (sandwich == 0) {
                if (circularCount > 0) circularCount--;
                else break; // No one wants the circular sandwich at the top
            } else {
                if (squareCount > 0) squareCount--;
                else break; // No one wants the square sandwich at the top
            }
        }

        // The remaining students are those who couldn't eat
        return circularCount + squareCount;
    }
}