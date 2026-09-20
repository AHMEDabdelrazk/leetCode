public class Solution {
    public int ReverseDegree(string s) {
        char[] arr = s.ToCharArray();
        int res = 0;
        for(int i=0;i<arr.Length;i++){
            res += ( (i+1) * ( 26 - (arr[i]-'a') ) )  ;
            //Console.WriteLine( res );
        }
        return res;
    }
}