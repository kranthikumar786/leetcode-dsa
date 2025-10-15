class LRUCache {
    class Node{
         int key;
         int value;
         Node prev;
         Node next;
         Node(int key,int value){
             this.key = key;
              this.value = value; 
         }
        }
        private final int capacity;
        private Map<Integer,Node>map;
        private Node head; //Most recently used ;
        private Node tail ; // Least recently used 
  
    public LRUCache(int capacity) {
        this.capacity = capacity;
        map = new HashMap<>();
        head = new Node(-1,-1); // dummy head;
        tail = new Node(-1,-1); // dummy tail
        head.next = tail;
        tail.prev = head;
    }
    private void moveToHead(Node node){
        removeNode(node);
        addNodeAfterHead(node);
    }
    // Remove a node from the DLL
    private void removeNode(Node node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
    // Add  a node right after head

    private void addNodeAfterHead(Node node){
        node.next = head.next;
        node.prev = head;
        head.next.prev = node;
        head.next = node;
    }
    // Remove the tail node (least recently Used)
    private Node removeTail(){
        Node node = tail.prev;
        removeNode(node);
        return node;
    }
    // get the value by the key
    public int get(int key) {
       if(!map.containsKey(key)) return -1;
       Node node = map.get(key);
       moveToHead(node);
       return node.value; 
    }
    // put key-value pair
    public void put(int key, int value) {
        if(map.containsKey(key)){
            Node node = map.get(key);
            node.value = value;
            moveToHead(node);
        }else{
            Node newNode = new Node(key,value);
            map.put(key,newNode);
            addNodeAfterHead(newNode);
             if(map.size() > capacity) {
                Node tailNode = removeTail();
                map.remove(tailNode.key);
             }
        }
    }

}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */