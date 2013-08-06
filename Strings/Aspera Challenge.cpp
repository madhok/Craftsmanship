public static void findLongestWord(String[] strs){
        Set<String> dict = new HashSet<String>();
        for(String s: strs) dict.add(s);
        Comparator<String> mycomp = new Comparator<String>(){
            @Override
            public int compare(String a, String b){
                if(a.length()<b.length()) return 1;
                else if(a.length() == b.length()) return 0;
                else return -1;
            }
        };
        Arrays.sort(strs, mycomp);
        for(String s: strs){
            dict.remove(s);
            if(dfs(dict,s))
                System.out.println(s);//this will print all words that can be combined from other
            dict.add(s);
        }
    }
    public static boolean dfs(Set<String> dict, String target){
        if(dict.contains(target)) return true;
        for(int i = 1;i<target.length();i++){
            if(dict.contains(target.substring(0,i))&&dfs(dict,target.substring(i)))
                return true;
        }
        return false;
    }
    //sol2:
    public static void findLongestWord(String[] strs){
        //longest to shortest
        Comparator<String> mycomp = new Comparator<String>(){
            @Override
            public int compare(String a, String b){
                if(a.length()<b.length()) return 1;
                else if(a.length() == b.length()) return 0;
                else return -1;
            }
        };
        Set<String> set = new HashSet<String>();
        for(String s: strs)
            set.add(s);
        Arrays.sort(strs, mycomp);
        for(int i =0; i< strs.length;i++){
            if(canSplit(strs[i], true, set)){
                System.out.println(strs[i]);
                //print out from longest to smallest combination of words
            }
        }
        
    }
    public static boolean canSplit(String s, Boolean isOriginal, Set<String> set){
        if(set.contains(s)&& !isOriginal) return true;
        for(int i =0;i<s.length();i++){
            String left = s.substring(0,i);
            String right = s.substring(i);
            if(set.contains(left)  && canSplit(right, false, set))
                return true;
        }
        return false;
    }
    public static void main(String[] args){
    String[] strs  ={"cat", "banana", "dog", "nana", "walk", "walker",
        "dogwalker","s", "catswalker","bigdogwalker","big","catanddog","and","bigcatbananadog"};
    findLongestWord(strs);
    }