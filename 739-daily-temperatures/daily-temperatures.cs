public class Solution {
    public int[] NextGreaterElement(int[] arr) {
        int n = arr.Length;
        int[] result = new int[n];
        
        Array.Fill(result, -1);
        
        Stack<int> st = new Stack<int>(); // store indices

        for (int i = 0; i < n; i++) {
            while (st.Count > 0 && arr[st.Peek()] < arr[i]) {
                result[st.Pop()] = i;
            }
            st.Push(i);
        }
        
        return result;
    }
    public int[] DailyTemperatures(int[] temperatures) {
        var mono = NextGreaterElement(temperatures);
        int n = temperatures.Length;
        for(int i=0;i<n;i++){
            if(mono[i] == -1) mono[i] = 0;
            else{ mono[i] = mono[i] - i; }
        }
        return mono;
    }
}