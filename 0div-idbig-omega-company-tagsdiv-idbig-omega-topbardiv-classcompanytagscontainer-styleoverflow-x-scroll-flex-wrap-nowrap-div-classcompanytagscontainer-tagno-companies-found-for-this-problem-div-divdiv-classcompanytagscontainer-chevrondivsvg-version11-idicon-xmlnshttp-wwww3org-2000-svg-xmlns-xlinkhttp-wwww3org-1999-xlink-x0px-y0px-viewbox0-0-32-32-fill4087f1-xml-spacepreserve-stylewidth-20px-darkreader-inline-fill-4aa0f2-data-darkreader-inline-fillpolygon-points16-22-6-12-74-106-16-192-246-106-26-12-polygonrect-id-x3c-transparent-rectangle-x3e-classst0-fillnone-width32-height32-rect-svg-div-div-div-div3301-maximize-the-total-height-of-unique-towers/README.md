<h2><a href="https://leetcode.com/problems/maximize-the-total-height-of-unique-towers/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>3301. Maximize the Total Height of Unique Towers</a></h2><h3>Medium</h3><hr><div><p>You are given an array <code>maximumHeight</code>, where <code>maximumHeight[i]</code> denotes the <strong>maximum</strong> height the <code>i<sup>th</sup></code> tower can be assigned.</p>

<p>Your task is to assign a height to each tower so that:</p>

<ol>
	<li>The height of the <code>i<sup>th</sup></code> tower is a positive integer and does not exceed <code>maximumHeight[i]</code>.</li>
	<li>No two towers have the same height.</li>
</ol>

<p>Return the <strong>maximum</strong> possible total sum of the tower heights. If it's not possible to assign heights, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> maximumHeight<span class="example-io"> = [2,3,4,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">10</span></p>

<p><strong>Explanation:</strong></p>

<p>We can assign heights in the following way: <code>[1, 2, 4, 3]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> maximumHeight<span class="example-io"> = [15,10]</span></p>

<p><strong>Output:</strong> <span class="example-io">25</span></p>

<p><strong>Explanation:</strong></p>

<p>We can assign heights in the following way: <code>[15, 10]</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> maximumHeight<span class="example-io"> = [2,2,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>

<p><strong>Explanation:</strong></p>

<p>It's impossible to assign positive heights to each index so that no two towers have the same height.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= maximumHeight.length&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= maximumHeight[i] &lt;= 10<sup>9</sup></code></li>
</ul>
</div>