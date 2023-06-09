#pragma once
#include<vector>
#include<string>
using namespace std;
class Solution{
public:
	int fib(int n);//509. 斐波那契数(e)
	int climbStairs(int n);//70. 爬楼梯(e)
	int minCostClimbingStairs(vector<int>& cost);//746. 使用最小花费爬楼梯(e)
	int uniquePaths(int m, int n);//62. 不同路径(m)
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);//63. 不同路径 II(m)
	int integerBreak(int n);//343. 整数拆分(m)
	int numTrees(int n);//96. 不同的二叉搜索树(m)
};
