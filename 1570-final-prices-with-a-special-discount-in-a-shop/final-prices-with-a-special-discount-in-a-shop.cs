public class Solution {
    public int[] FinalPrices(int[] prices) {
        // We use a stack to store the indices of the prices
        Stack<int> stack = new Stack<int>();
        
        for (int i = 0; i < prices.Length; i++) {
            // While the stack isn't empty and the current price is 
            // less than or equal to the price at the index on top of the stack
            while (stack.Count > 0 && prices[i] <= prices[stack.Peek()]) {
                int indexToDiscount = stack.Pop();
                prices[indexToDiscount] -= prices[i];
            }
            // Push current index onto the stack
            stack.Push(i);
        }
        
        return prices;
    }
}