package archive.ds;

public class SegmentTree {
    public int N;
    public int[] arr;

    SegmentTree(int N) {
        this.N = N;
        this.arr = new int[2 * N];
    }

    void build() {
        for(int i = N - 1; i > 0; i--) {
            int lChild = i << 1, rChild = i << 1 | 1;
            arr[i] = Math.max(arr[lChild], arr[rChild]);
        }
    }
}
//    SegmentTree st = new SegmentTree(N);
//    int[] A = st.arr;
//    for(int i = 0; i < N; i++) {
//        A[i + N] = sc.nextInt();
//        }
//        st.build();
