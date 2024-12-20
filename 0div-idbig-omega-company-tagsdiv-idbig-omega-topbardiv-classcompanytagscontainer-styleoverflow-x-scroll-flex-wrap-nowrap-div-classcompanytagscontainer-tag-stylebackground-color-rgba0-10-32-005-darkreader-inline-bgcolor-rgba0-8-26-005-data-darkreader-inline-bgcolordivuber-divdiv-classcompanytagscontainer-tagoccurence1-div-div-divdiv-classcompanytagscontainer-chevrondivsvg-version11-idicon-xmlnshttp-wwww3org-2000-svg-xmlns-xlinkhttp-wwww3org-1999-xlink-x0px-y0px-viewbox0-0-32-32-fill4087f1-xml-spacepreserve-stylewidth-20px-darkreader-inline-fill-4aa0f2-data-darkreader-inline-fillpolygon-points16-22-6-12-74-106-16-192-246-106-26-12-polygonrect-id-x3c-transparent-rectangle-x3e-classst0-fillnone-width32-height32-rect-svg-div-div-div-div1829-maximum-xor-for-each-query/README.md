<h2><a href="https://leetcode.com/problems/maximum-xor-for-each-query/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05); --darkreader-inline-bgcolor: rgba(0, 8, 26, 0.05);" data-darkreader-inline-bgcolor=""><div>Uber</div><div class="companyTagsContainer--tagOccurence">1</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1829. Maximum XOR for Each Query</a></h2><h3>Medium</h3><hr><div><p>You are given a <strong>sorted</strong> array <code>nums</code> of <code>n</code> non-negative integers and an integer <code>maximumBit</code>. You want to perform the following query <code>n</code> <strong>times</strong>:</p>

<ol>
	<li>Find a non-negative integer <code>k &lt; 2<sup>maximumBit</sup></code> such that <code>nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k</code> is <strong>maximized</strong>. <code>k</code> is the answer to the <code>i<sup>th</sup></code> query.</li>
	<li>Remove the <strong>last </strong>element from the current array <code>nums</code>.</li>
</ol>

<p>Return <em>an array</em> <code>answer</code><em>, where </em><code>answer[i]</code><em> is the answer to the </em><code>i<sup>th</sup></code><em> query</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [0,1,1,3], maximumBit = 2
<strong>Output:</strong> [0,3,2,3]
<strong>Explanation</strong>: The queries are answered as follows:
1<sup>st</sup> query: nums = [0,1,1,3], k = 0 since 0 XOR 1 XOR 1 XOR 3 XOR 0 = 3.
2<sup>nd</sup> query: nums = [0,1,1], k = 3 since 0 XOR 1 XOR 1 XOR 3 = 3.
3<sup>rd</sup> query: nums = [0,1], k = 2 since 0 XOR 1 XOR 2 = 3.
4<sup>th</sup> query: nums = [0], k = 3 since 0 XOR 3 = 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,4,7], maximumBit = 3
<strong>Output:</strong> [5,2,6,5]
<strong>Explanation</strong>: The queries are answered as follows:
1<sup>st</sup> query: nums = [2,3,4,7], k = 5 since 2 XOR 3 XOR 4 XOR 7 XOR 5 = 7.
2<sup>nd</sup> query: nums = [2,3,4], k = 2 since 2 XOR 3 XOR 4 XOR 2 = 7.
3<sup>rd</sup> query: nums = [2,3], k = 6 since 2 XOR 3 XOR 6 = 7.
4<sup>th</sup> query: nums = [2], k = 5 since 2 XOR 5 = 7.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [0,1,2,2,5,7], maximumBit = 3
<strong>Output:</strong> [4,3,6,4,6,7]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>nums.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= maximumBit &lt;= 20</code></li>
	<li><code>0 &lt;= nums[i] &lt; 2<sup>maximumBit</sup></code></li>
	<li><code>nums</code>​​​ is sorted in <strong>ascending</strong> order.</li>
</ul>
</div>