
# [第二高的薪水](https://leetcode-cn.com/problems/second-highest-salary)

## 题目描述

<code>Employee</code> 表：
<div class="original__bRMd">
<div>
<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
id 是这个表的主键。
表的每一行包含员工的工资信息。
</pre>

<p>&nbsp;</p>

<p>编写一个 SQL 查询，获取并返回 <code>Employee</code>&nbsp;表中第二高的薪水 。如果不存在第二高的薪水，查询应该返回 <code>null</code> 。</p>

<p>查询结果如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Employee 表：
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
<strong>输出：</strong>
+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>
Employee 表：
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
+----+--------+
<strong>输出：</strong>
+---------------------+
| SecondHighestSalary |
+---------------------+
| null                |
+---------------------+
</pre>
</div>
</div>


## 题解

### mysql [🔗](second-highest-salary.mysql) 
```mysql
# Write your MySQL query statement below
select (select DISTINCT  Salary from Employee ORDER BY Salary DESC limit 1, 1) as SecondHighestSalary;
```


## 相关话题

- [数据库](../../tags/database.md) 


## 相似题目



## Links

- [Prev](../binary-search-tree-iterator/README.md) 
- [Next](../largest-number/README.md) 

