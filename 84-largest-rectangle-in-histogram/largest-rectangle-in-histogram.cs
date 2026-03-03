public class Solution {
    public int LargestRectangleArea(int[] heights) {
        int n = heights.Length;
        int[] nextSmaller = new int[n];
        int[] prevSmaller = new int[n];
        
        Stack<int> st = new Stack<int>();

        // 1. Find Next Smaller Element (NSE)
        for (int i = 0; i < n; i++) {
            while (st.Count > 0 && heights[st.Peek()] > heights[i]) {
                nextSmaller[st.Pop()] = i;
            }
            st.Push(i);
        }
        while (st.Count > 0) nextSmaller[st.Pop()] = n; // If no smaller found, boundary is n

        st.Clear();

        // 2. Find Previous Smaller Element (PSE)
        for (int i = n - 1; i >= 0; i--) {
            while (st.Count > 0 && heights[st.Peek()] > heights[i]) {
                prevSmaller[st.Pop()] = i;
            }
            st.Push(i);
        }
        while (st.Count > 0) prevSmaller[st.Pop()] = -1; // If no smaller found, boundary is -1

        // 3. Calculate Maximum Area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            int currentArea = heights[i] * width;
            maxArea = Math.Max(maxArea, currentArea);
        }

        return maxArea;
    }
}