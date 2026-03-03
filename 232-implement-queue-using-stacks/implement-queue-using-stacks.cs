public class MyQueue {
    private Stack<int> stackPush;
    private Stack<int> stackPop;

    public MyQueue() {
        stackPush = new Stack<int>();
        stackPop = new Stack<int>();
    }
    
    public void Push(int x) {
        stackPush.Push(x);
    }
    
    public int Pop() {
        ShiftStacks();
        return stackPop.Pop();
    }
    
    public int Peek() {
        ShiftStacks();
        return stackPop.Peek();
    }
    
    public bool Empty() {
        return stackPush.Count == 0 && stackPop.Count == 0;
    }

    // Helper method to move elements from Push stack to Pop stack
    private void ShiftStacks() {
        // Only move elements if the Pop stack is empty
        if (stackPop.Count == 0) {
            while (stackPush.Count > 0) {
                stackPop.Push(stackPush.Pop());
            }
        }
    }
}