<h2><a href="https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05); --darkreader-inline-bgcolor: rgba(0, 8, 26, 0.05);" data-darkreader-inline-bgcolor=""><div>Rupeek</div><div class="companyTagsContainer--tagOccurence">1</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1545. Find Kth Bit in Nth Binary String</a></h2><h3>Medium</h3><hr><div><p>Given two positive integers <code>n</code> and <code>k</code>, the binary string <code>S<sub>n</sub></code> is formed as follows:</p>

<ul>
	<li><code>S<sub>1</sub> = "0"</code></li>
	<li><code>S<sub>i</sub> = S<sub>i - 1</sub> + "1" + reverse(invert(S<sub>i - 1</sub>))</code> for <code>i &gt; 1</code></li>
</ul>

<p>Where <code>+</code> denotes the concatenation operation, <code>reverse(x)</code> returns the reversed string <code>x</code>, and <code>invert(x)</code> inverts all the bits in <code>x</code> (<code>0</code> changes to <code>1</code> and <code>1</code> changes to <code>0</code>).</p>

<p>For example, the first four strings in the above sequence are:</p>

<ul>
	<li><code>S<sub>1 </sub>= "0"</code></li>
	<li><code>S<sub>2 </sub>= "0<strong>1</strong>1"</code></li>
	<li><code>S<sub>3 </sub>= "011<strong>1</strong>001"</code></li>
	<li><code>S<sub>4</sub> = "0111001<strong>1</strong>0110001"</code></li>
</ul>

<p>Return <em>the</em> <code>k<sup>th</sup></code> <em>bit</em> <em>in</em> <code>S<sub>n</sub></code>. It is guaranteed that <code>k</code> is valid for the given <code>n</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 3, k = 1
<strong>Output:</strong> "0"
<strong>Explanation:</strong> S<sub>3</sub> is "<strong><u>0</u></strong>111001".
The 1<sup>st</sup> bit is "0".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 4, k = 11
<strong>Output:</strong> "1"
<strong>Explanation:</strong> S<sub>4</sub> is "0111001101<strong><u>1</u></strong>0001".
The 11<sup>th</sup> bit is "1".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>1 &lt;= k &lt;= 2<sup>n</sup> - 1</code></li>
</ul>
</div>