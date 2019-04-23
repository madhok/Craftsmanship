class Solution {
    public String toLowerCase(String str) {
        StringBuilder sb = new StringBuilder();
        char[] arr = str.toCharArray();
        for(char c : arr) {
            int val = (int) c;
            if(val >= 'A' && val <= 'Z') {
                val = val + ('a' -'A');
                char newch = (char) val;
                sb.append(newch);
            }
            else {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}