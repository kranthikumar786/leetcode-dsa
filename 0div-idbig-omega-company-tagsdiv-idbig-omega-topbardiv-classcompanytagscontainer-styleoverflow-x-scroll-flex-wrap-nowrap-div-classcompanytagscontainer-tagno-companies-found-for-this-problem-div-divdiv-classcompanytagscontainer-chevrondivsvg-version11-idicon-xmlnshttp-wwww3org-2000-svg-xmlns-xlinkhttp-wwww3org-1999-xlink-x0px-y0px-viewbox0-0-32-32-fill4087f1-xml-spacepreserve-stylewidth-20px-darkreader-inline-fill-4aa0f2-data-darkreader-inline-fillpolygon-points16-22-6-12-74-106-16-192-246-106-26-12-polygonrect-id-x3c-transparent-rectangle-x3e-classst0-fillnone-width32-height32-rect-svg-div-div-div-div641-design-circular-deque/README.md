<h2><a href="https://leetcode.com/problems/design-circular-deque/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>641. Design Circular Deque</a></h2><h3>Medium</h3><hr><div><p>Design your implementation of the circular double-ended queue (deque).</p>

<p>Implement the <code>MyCircularDeque</code> class:</p>

<ul>
	<li><code>MyCircularDeque(int k)</code> Initializes the deque with a maximum size of <code>k</code>.</li>
	<li><code>boolean insertFront()</code> Adds an item at the front of Deque. Returns <code>true</code> if the operation is successful, or <code>false</code> otherwise.</li>
	<li><code>boolean insertLast()</code> Adds an item at the rear of Deque. Returns <code>true</code> if the operation is successful, or <code>false</code> otherwise.</li>
	<li><code>boolean deleteFront()</code> Deletes an item from the front of Deque. Returns <code>true</code> if the operation is successful, or <code>false</code> otherwise.</li>
	<li><code>boolean deleteLast()</code> Deletes an item from the rear of Deque. Returns <code>true</code> if the operation is successful, or <code>false</code> otherwise.</li>
	<li><code>int getFront()</code> Returns the front item from the Deque. Returns <code>-1</code> if the deque is empty.</li>
	<li><code>int getRear()</code> Returns the last item from Deque. Returns <code>-1</code> if the deque is empty.</li>
	<li><code>boolean isEmpty()</code> Returns <code>true</code> if the deque is empty, or <code>false</code> otherwise.</li>
	<li><code>boolean isFull()</code> Returns <code>true</code> if the deque is full, or <code>false</code> otherwise.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input</strong>
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
<strong>Output</strong>
[null, true, true, true, false, 2, true, true, true, 4]

<strong>Explanation</strong>
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 1000</code></li>
	<li><code>0 &lt;= value &lt;= 1000</code></li>
	<li>At most <code>2000</code> calls will be made to <code>insertFront</code>, <code>insertLast</code>, <code>deleteFront</code>, <code>deleteLast</code>, <code>getFront</code>, <code>getRear</code>, <code>isEmpty</code>, <code>isFull</code>.</li>
</ul>
</div>