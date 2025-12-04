class MedianFinder {
  
   //ArrayList<Integer>arr;
    PriorityQueue<Integer>minHeap;
   PriorityQueue<Integer>maxHeap ;
    public MedianFinder() {
     //   arr = new ArrayList<>();
     minHeap = new PriorityQueue<>();
     maxHeap = new PriorityQueue<>(Collections.reverseOrder());
    }
    public void addNum(int num) {
       //arr.add(num);
       //Collections.sort(arr);  
       maxHeap.add(num);
       minHeap.add(maxHeap.poll());
        while(minHeap.size() > maxHeap.size()){
            maxHeap.add(minHeap.poll());
        } 
    }
    public double findMedian() {
        if(maxHeap.size() > minHeap.size()) return maxHeap.peek()/1.0;
     return (maxHeap.peek() + minHeap.peek())/2.0;
    //    int n = arr.size();
    //    if(n%2 != 0){  
    //      return arr.get(n/2)/1.0;
    //     }
    //     return (arr.get(n/2-1) + arr.get(n/2))/2.0;  
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */