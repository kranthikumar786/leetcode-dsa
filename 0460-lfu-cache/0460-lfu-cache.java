import java.util.*;

class LFUCache {

    // Doubly Linked List Node
    private class Node {
        int key;
        int value;
        int freq;
        Node prev;
        Node next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
        }
    }

    // Doubly Linked List for same frequency nodes
    private class DLinkedList {
        Node head;
        Node tail;
        int size;

        DLinkedList() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head.next = tail;
            tail.prev = head;
            size = 0;
        }

        void addNode(Node node) {
            node.next = head.next;
            node.prev = head;
            head.next.prev = node;
            head.next = node;
            size++;
        }

        void removeNode(Node node) {
            node.prev.next = node.next;
            node.next.prev = node.prev;
            size--;
        }

        Node removeLRU() {
            if (size == 0) return null;
            Node lru = tail.prev;
            removeNode(lru);
            return lru;
        }
    }

    private final int capacity;
    private int size;
    private int minFreq;

    private Map<Integer, Node> nodeMap;
    private Map<Integer, DLinkedList> freqMap;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        this.minFreq = 0;

        nodeMap = new HashMap<>();
        freqMap = new HashMap<>();
    }

    public int get(int key) {
        Node node = nodeMap.get(key);
        if (node == null) return -1;

        updateFreq(node);
        return node.value;
    }

    public void put(int key, int value) {
        if (capacity == 0) return;

        if (nodeMap.containsKey(key)) {
            Node node = nodeMap.get(key);
            node.value = value;
            updateFreq(node);
            return;
        }

        // Evict if full
        if (size >= capacity) {
            DLinkedList minList = freqMap.get(minFreq);
            Node toRemove = minList.removeLRU();
            nodeMap.remove(toRemove.key);
            size--;
        }

        // Add new node
        Node newNode = new Node(key, value);
        nodeMap.put(key, newNode);

        DLinkedList list = freqMap.getOrDefault(1, new DLinkedList());
        list.addNode(newNode);
        freqMap.put(1, list);

        minFreq = 1;
        size++;
    }

    private void updateFreq(Node node) {
        int oldFreq = node.freq;
        DLinkedList oldList = freqMap.get(oldFreq);

        oldList.removeNode(node);

        if (oldFreq == minFreq && oldList.size == 0) {
            minFreq++;
        }

        node.freq++;

        DLinkedList newList = freqMap.getOrDefault(node.freq, new DLinkedList());
        newList.addNode(node);
        freqMap.put(node.freq, newList);
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 
 class LFUCache {
     PriorityQueue<int[]>pq ;
     HashMap<Integer,Integer>cache ;
    public LFUCache(int capacity) {
        pq = new PriorityQueue<>((a,b)->{
             int fre = Integer.compare(a[0],b[0]);
             if(fre != 0){
                 return fre;
             }
            return Integer.compare(a[1],b[1]); 
        });
        cache = new HashMap<>(capacity);
    }
    public int get(int key) {
       Integer val = cache.get(key);
       if(val == null){
        return -1;
       }
       int[] cur = pq.get(key);
       cur[1]+=1;
       pq.add(cur); 
       return val;
    }
    public void put(int key, int value) {   
      
        if(cache.size() == capacity){
            pq.remove();
            cache.put(key,value);
            int pair1[] = pq.get(key);
            if(pare != null){
                pair1[1]+=1;
                pq.add(pair1);
            }else{
              pq.add(new int[]{value,1});  
            }  
        } else{
           cache.put(key,value);
           int pair[] = pq.get(key);
           if(pair != null){
                pair1[1]+=1;
                pq.add(pair1);
            }else{
              pq.add(new int[]{value,1});  
            } 
        }
    }
}

 */