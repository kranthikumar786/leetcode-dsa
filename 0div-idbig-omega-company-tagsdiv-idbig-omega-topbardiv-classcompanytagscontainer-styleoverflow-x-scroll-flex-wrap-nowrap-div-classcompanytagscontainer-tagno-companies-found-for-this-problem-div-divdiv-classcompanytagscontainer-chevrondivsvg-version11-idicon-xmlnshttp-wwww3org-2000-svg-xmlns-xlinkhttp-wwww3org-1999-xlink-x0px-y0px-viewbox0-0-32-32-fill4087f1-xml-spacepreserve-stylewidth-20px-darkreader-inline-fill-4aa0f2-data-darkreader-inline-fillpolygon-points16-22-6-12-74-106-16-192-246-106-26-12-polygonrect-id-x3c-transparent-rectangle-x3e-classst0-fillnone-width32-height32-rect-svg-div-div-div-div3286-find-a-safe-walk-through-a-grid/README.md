<h2><a href="https://leetcode.com/problems/find-a-safe-walk-through-a-grid/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>3286. Find a Safe Walk Through a Grid</a></h2><h3>Medium</h3><hr><div><p>You are given an <code>m x n</code> binary matrix <code>grid</code> and an integer <code>health</code>.</p>

<p>You start on the upper-left corner <code>(0, 0)</code> and would like to get to the lower-right corner <code>(m - 1, n - 1)</code>.</p>

<p>You can move up, down, left, or right from one cell to another adjacent cell as long as your health <em>remains</em> <strong>positive</strong>.</p>

<p>Cells <code>(i, j)</code> with <code>grid[i][j] = 1</code> are considered <strong>unsafe</strong> and reduce your health by 1.</p>

<p>Return <code>true</code> if you can reach the final cell with a health value of 1 or more, and <code>false</code> otherwise.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<p>The final cell can be reached safely by walking along the gray cells below.</p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/08/04/3868_examples_1drawio.png" style="width: 301px; height: 121px;"></div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong></p>

<p>A minimum of 4 health points is needed to reach the final cell safely.</p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/08/04/3868_examples_2drawio.png" style="width: 361px; height: 161px;"></div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<p>The final cell can be reached safely by walking along the gray cells below.</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/08/04/3868_examples_3drawio.png" style="width: 181px; height: 121px;"></p>

<p>Any path that does not go through the cell <code>(1, 1)</code> is unsafe since your health will drop to 0 when reaching the final cell.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code><font face="monospace">2 &lt;= m * n</font></code></li>
	<li><code>1 &lt;= health &lt;= m + n</code></li>
	<li><code>grid[i][j]</code> is either 0 or 1.</li>
</ul>
</div>