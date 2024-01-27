class SparseTable {
    // Using 1-based indexing
    int N, M = 30;
    int[][] a;

    SparseTable(int N) {
        this.N = N;
        this.a = new int[M][N + 1];
    }

    public void buildMax(int[] b) {
        System.arraycopy(b, 1, a[0], 1, N);
        for(int j = 1; j < M; j++) {
            for(int i = 1; i + (1 << j) - 1 <= N; i++) {
                a[j][i] = Math.max(a[j - 1][i], a[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    public int getMax(int l, int r) {
        int max = Integer.MIN_VALUE;
        for(int j = M - 1; j >= 0; j--) {
            if(l + (1 << j) - 1 <= r) {
                max = Math.max(a[j][l], max);
                l += (1 << j);
            }
        }
        return max;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[")
                .append(this.getClass().getName())
                .append("]:\n");

        for(int j = 0; j < M; j++)
            for(int i = 1; i <= N; i++)
                sb.append(a[j][i]).append(i == N ? "\n" : " ");

        return sb.toString();
    }
}
