    public void swap(int[] buf, int p1, int p2) {
        int temp = buf[p1];
        buf[p1] = buf[p2];
        buf[p2] = temp;
    }


    /*
    * Min Heap
    * */
    class Heap {
        int n = 0;
        int[] data;

        Heap(int n) {
            this.n = n;
            this.data = new int[n];
        }

        /*
         * Shifts last element to correct position.
         * */
        void heapify() {
            int lastPos = n - 1;
            if(lastPos == 0) return;

            int childInd = lastPos;
            while(childInd != 0) {
                int parentInd = (childInd - 1) / 2;
                int leftChild = parentInd * 2 + 1;
                int rightChild = parentInd * 2 + 2;
                if(leftChild <= lastPos && data[parentInd] > data[leftChild]) {
                    swap(data, parentInd, leftChild);
                }
                if(rightChild <= lastPos && data[parentInd] > data[rightChild]) {
                    swap(data, parentInd, rightChild);
                }
                childInd = parentInd;
            }
        }

        /*
        * Shifts root element to correct position.
        * */
        public void heapifyDown() {
            int parentInd = 0;
            int leftChildInd;
            int rightChildInd;

            while(parentInd < n) {
                int newParentInd = parentInd;
                leftChildInd = 2 * parentInd + 1;
                rightChildInd = 2 * parentInd + 2;

                if(leftChildInd < n && data[parentInd] > data[leftChildInd]) {
                    swap(data, parentInd, leftChildInd);
                    parentInd = leftChildInd;
                }
                else if(rightChildInd < n && data[parentInd] > data[rightChildInd]) {
                    swap(data, parentInd, rightChildInd);
                    parentInd = rightChildInd;
                }

                if(parentInd == newParentInd) {
                    break;
                }
            }
        }

    }
