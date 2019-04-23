class Solution {
    public String removeOuterParentheses(String S) {
        Stack<Character> stk = new Stack<Character>();
        StringBuilder sb = new StringBuilder();
        char[] charray = S.toCharArray();
        int opened = 0;
        for(char c: charray) {
            if(c == '(') {
                opened++;
                if(opened > 1) {
                    sb.append('(');
                }
            }
            else {
                opened--;
                if(opened > 0) {
                    sb.append(')');
                }
            }
        }
        return sb.toString();
    }
}
