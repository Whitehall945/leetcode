#include <iostream>
#include "Solution.h"

int Solution::fib(int n) {//509. 쳲�������(e)
	if (n <= 1)
		return n;//�߽�����
	vector<int>dp(n + 1);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int Solution::climbStairs(int n) {//70. ��¥��(e)
	if (n <= 1)
		return n;//dp[0]û�����壬¥�ݴӵ�һ��̨�׿�ʼ��
	vector<int> dp(n + 1);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int Solution::minCostClimbingStairs(vector<int>& cost){//746. ʹ����С������¥��(e)
	vector<int>dp(cost.size() + 1);//dp[i]�ĺ����ǣ����ϵ�i��̨���������С����
	dp[0] = 0;
	dp[1] = 0;//ǰ�������ǲ���Ҫ���ѵ�
	for (int i = 2; i <= cost.size(); i++) {
		dp[i] = min((cost[i - 1] + dp[i - 1]), (cost[i - 2] + dp[i - 2]));
	}
	return dp[cost.size()];
}

int Solution::uniquePaths(int m, int n){//62. ��ͬ·��(m)
	vector<vector<int>>dp(m, vector<int>(n, 0));//dp[i][j]�ĺ����ǣ��ӳ����㵽λ��(i,j)��·������
	for (int i = 0; i < m; i++) {//�г�ʼ��
		dp[i][0] = 1;
	}
	for (int j = 0; j < n; j++) {//�г�ʼ��
		dp[0][j] = 1;
	}
	for (int i = 1; i < m; i++) {//������
		for (int j = 1; j < n; j++) {//�������±���
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}

int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
	int m = obstacleGrid.size();//����
	int n = obstacleGrid[0].size();//����
	if ((obstacleGrid[0][0] == 1) || (obstacleGrid[m - 1][n - 1] == 1)) {//�������յ����ϰ���ֱ�ӷ���
		return 0;
	}
	vector<vector<int>>dp(m, vector<int>(n, 0));//dp[i][j]�ĺ����ǣ��ӳ����㵽λ��(i,j)��·������
	for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {//�г�ʼ��
		dp[i][0] = 1;
	}
	for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) {//�г�ʼ��
		dp[0][j] = 1;
	}
	for (int i = 1; i < m; i++) {//������
		for (int j = 1; j < n; j++) {//�������±���
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
