/*
 * Creates set of size N having having index [1, N]
 */
class DSU {
    int N;
    int[] sets;

    DSU(int N) {
        this.N = N;
        sets = new int[N + 1];
        for(int i = 1; i <= N; i++) {
            sets[i] = i;
        }
    }

    public int union(int u, int v) {
        int set1 = getSet(u);
        int set2 = getSet(v);
        if(set1 != set2) {
            sets[set1] = set2;
        }
        return set2;
    }

    public int getSet(int u) {
        return sets[u] = sets[u] == u ? u : getSet(sets[u]);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("DSU(").append(N).append("): [");
        sb.append(Arrays.stream(sets).mapToObj(Integer::toString).collect(Collectors.joining(",")));
        sb.append("]");
        return sb.toString();
    }
}
