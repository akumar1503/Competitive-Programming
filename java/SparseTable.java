class SparseTable {
    // Using 1-based indexing
    // Store values
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


class SparseTableMinMax {
    // Using 1-based indexing.
    // Stores and returns indices of min and max elements.
    int N, M = 30;
    int[] A;
    int[][] stArrayMax;
    int[][] stArrayMin;

    SparseTable(int N) {
        this.N = N;
        this.stArrayMax = new int[M][N + 1];
        this.stArrayMin = new int[M][N + 1];
    }

    public void build(int[] a) {
        this.A = a;
//        System.arraycopy(a, 1, stArrayMax[0], 1, N);
//        System.arraycopy(a, 1, stArrayMax[0], 1, N);
        for(int i = 1; i <= N; i++) stArrayMax[0][i] = i;
        for(int i = 1; i <= N; i++) stArrayMin[0][i] = i;

        for(int j = 1; j < M; j++) {
            for(int i = 1; i + (1 << j) - 1 <= N; i++) {
                int p1Start = i;
                int p2Start = i + (1 << (j - 1));

                // max
                stArrayMax[j][i] = stArrayMax[j - 1][i]; //Math.max(stArrayMax[j - 1][p1Start], stArrayMax[j - 1][p2Start]);
                if(A[stArrayMax[j - 1][p2Start]] > A[stArrayMax[j][i]]) {
                    stArrayMax[j][i] = stArrayMax[j - 1][p2Start];
                }
                // min
                stArrayMin[j][i] = stArrayMin[j - 1][i]; //Math.max(stArrayMin[j - 1][p1Start], stArrayMin[j - 1][p2Start]);
                if(A[stArrayMin[j - 1][p2Start]] < A[stArrayMin[j][i]]) {
                    stArrayMin[j][i] = stArrayMin[j - 1][p2Start];
                }
            }
        }
    }

    public int getMax(int l, int r) {
        int max = Integer.MIN_VALUE;
        for(int j = M - 1; j >= 0; j--) {
            if(l + (1 << j) - 1 <= r) {
                max = Math.max(stArrayMax[j][l], max);
                l += (1 << j);
            }
        }
        return max;
    }
    public Pair<Integer, Integer> getValueAt(int l, int r) {
        int maxAt = l;
        int minAt = l;
        for(int j = M - 1; j >= 0; j--) {
            int at = l + (1 << j) - 1;
            if(at <= r) {
                // max
                if(A[stArrayMax[j][l]] > A[maxAt]) {
                    maxAt = stArrayMax[j][l];
                }
                // min
                if(A[stArrayMin[j][l]] < A[minAt]) {
                    minAt = stArrayMin[j][l];
                }
                l += (1 << j);
            }
        }
        return new Pair<>(maxAt, minAt);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[")
                .append(this.getClass().getName())
                .append("]:\n");

        for(int j = 0; j < M; j++)
            for(int i = 1; i <= N; i++)
                sb.append(stArrayMax[j][i]).append(i == N ? "\n" : " ");

        return sb.toString();
    }
}


static class Pair<T1, T2> {
    public T1 f;
    public T2 s;
    Pair(T1 f, T2 s) {
        this.f = f;
        this.s = s;
    }
}
