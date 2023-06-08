#include <iostream>
#include "Solution.h"

int Solution::fib(int n) {//509. 斐波那契数(e)
	if (n <= 1)
		return n;//边界条件
	vector<int>dp(n + 1);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int Solution::climbStairs(int n) {//70. 爬楼梯(e)
	if (n <= 1)
		return n;//dp[0]没有意义，楼梯从第一阶台阶开始爬
	vector<int> dp(n + 1);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int Solution::minCostClimbingStairs(vector<int>& cost){//746. 使用最小花费爬楼梯(e)
	vector<int>dp(cost.size() + 1);//dp[i]的含义是，跨上第i阶台阶所需的最小花费
	dp[0] = 0;
	dp[1] = 0;//前两步都是不需要花费的
	for (int i = 2; i <= cost.size(); i++) {
		dp[i] = min((cost[i - 1] + dp[i - 1]), (cost[i - 2] + dp[i - 2]));
	}
	return dp[cost.size()];
}

int Solution::uniquePaths(int m, int n){//62. 不同路径(m)
	vector<vector<int>>dp(m, vector<int>(n, 0));//dp[i][j]的含义是，从出发点到位置(i,j)的路径数量
	for (int i = 0; i < m; i++) {//列初始化
		dp[i][0] = 1;
	}
	for (int j = 0; j < n; j++) {//行初始化
		dp[0][j] = 1;
	}
	for (int i = 1; i < m; i++) {//从左到右
		for (int j = 1; j < n; j++) {//从上往下遍历
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}

int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
	int m = obstacleGrid.size();//行数
	int n = obstacleGrid[0].size();//列数
	if ((obstacleGrid[0][0] == 1) || (obstacleGrid[m - 1][n - 1] == 1)) {//起点或者终点有障碍，直接返回
		return 0;
	}
	vector<vector<int>>dp(m, vector<int>(n, 0));//dp[i][j]的含义是，从出发点到位置(i,j)的路径数量
	for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {//列初始化
		dp[i][0] = 1;
	}
	for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) {//行初始化
		dp[0][j] = 1;
	}
	for (int i = 1; i < m; i++) {//从左到右
		for (int j = 1; j < n; j++) {//从上往下遍历
			if (obstacleGrid[i][j] == 1)
				continue;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}

int main() {
	Solution solution;
	//cout << solution.fib(4) << endl;

	//cout << solution.climbStairs(3) << endl;

	//vector<int> cost = { 1,100,1,1,1,100,1,1,100,1 };
	//cout << solution.minCostClimbingStairs(cost) << endl;

	//cout << solution.uniquePaths(7, 3) << endl;
	vector<vector<int>>obstacleGrid = { {0, 0, 0},{0, 1, 0},{0, 0, 0} };
	cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;
}
