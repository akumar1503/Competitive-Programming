    private static class Mex {
       private int curMex = 0;
       private SortedSet<Integer> seen;

       Mex() {
            seen = new TreeSet<>();
       }

       public void clear() {
           curMex = 0;
           seen = new TreeSet<>();
       }

       public void add(int n) {
           if(n < curMex) return;
           seen.add(n);
           if(curMex == n) {
               while (!seen.isEmpty() && curMex == seen.first()) {
                   seen.remove(curMex);
                   curMex++;
               }
           }
       }

       public int value() {
           return curMex;
       }
    }
