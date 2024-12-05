<h2><a href="https://leetcode.com/problems/move-pieces-to-obtain-a-string/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2337. Move Pieces to Obtain a String</a></h2><h3>Medium</h3><hr><div><p>You are given two strings <code>start</code> and <code>target</code>, both of length <code>n</code>. Each string consists <strong>only</strong> of the characters <code>'L'</code>, <code>'R'</code>, and <code>'_'</code> where:</p>

<ul>
	<li>The characters <code>'L'</code> and <code>'R'</code> represent pieces, where a piece <code>'L'</code> can move to the <strong>left</strong> only if there is a <strong>blank</strong> space directly to its left, and a piece <code>'R'</code> can move to the <strong>right</strong> only if there is a <strong>blank</strong> space directly to its right.</li>
	<li>The character <code>'_'</code> represents a blank space that can be occupied by <strong>any</strong> of the <code>'L'</code> or <code>'R'</code> pieces.</li>
</ul>

<p>Return <code>true</code> <em>if it is possible to obtain the string</em> <code>target</code><em> by moving the pieces of the string </em><code>start</code><em> <strong>any</strong> number of times</em>. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> start = "_L__R__R_", target = "L______RR"
<strong>Output:</strong> true
<strong>Explanation:</strong> We can obtain the string target from start by doing the following moves:
- Move the first piece one step to the left, start becomes equal to "<strong>L</strong>___R__R_".
- Move the last piece one step to the right, start becomes equal to "L___R___<strong>R</strong>".
- Move the second piece three steps to the right, start becomes equal to "L______<strong>R</strong>R".
Since it is possible to get the string target from start, we return true.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> start = "R_L_", target = "__LR"
<strong>Output:</strong> false
<strong>Explanation:</strong> The 'R' piece in the string start can move one step to the right to obtain "_<strong>R</strong>L_".
After that, no pieces can move anymore, so it is impossible to obtain the string target from start.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> start = "_R", target = "R_"
<strong>Output:</strong> false
<strong>Explanation:</strong> The piece in the string start can move only to the right, so it is impossible to obtain the string target from start.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == start.length == target.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>start</code> and <code>target</code> consist of the characters <code>'L'</code>, <code>'R'</code>, and <code>'_'</code>.</li>
</ul>
</div>