<h2><a href="https://leetcode.com/problems/determine-if-two-events-have-conflict/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2446. Determine if Two Events Have Conflict</a></h2><h3>Easy</h3><hr><div><p>You are given two arrays of strings that represent two inclusive events that happened <strong>on the same day</strong>, <code>event1</code> and <code>event2</code>, where:</p>

<ul>
	<li><code>event1 = [startTime<sub>1</sub>, endTime<sub>1</sub>]</code> and</li>
	<li><code>event2 = [startTime<sub>2</sub>, endTime<sub>2</sub>]</code>.</li>
</ul>

<p>Event times are valid 24 hours format in the form of <code>HH:MM</code>.</p>

<p>A <strong>conflict</strong> happens when two events have some non-empty intersection (i.e., some moment is common to both events).</p>

<p>Return <code>true</code><em> if there is a conflict between two events. Otherwise, return </em><code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
<strong>Output:</strong> true
<strong>Explanation:</strong> The two events intersect at time 2:00.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
<strong>Output:</strong> true
<strong>Explanation:</strong> The two events intersect starting from 01:20 to 02:00.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
<strong>Output:</strong> false
<strong>Explanation:</strong> The two events do not intersect.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>event1<code>.length == </code>event2<code>.length == 2.</code></li>
	<li><code>event1[i].length == event2[i].length == 5</code></li>
	<li><code>startTime<sub>1</sub> &lt;= endTime<sub>1</sub></code></li>
	<li><code>startTime<sub>2</sub> &lt;= endTime<sub>2</sub></code></li>
	<li>All the event times follow the <code>HH:MM</code> format.</li>
</ul>
</div>