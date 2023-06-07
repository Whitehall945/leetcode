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

int main() {
	Solution solution;
	//cout << solution.fib(4) << endl;

	//cout << solution.climbStairs(3) << endl;

	//vector<int> cost = { 1,100,1,1,1,100,1,1,100,1 };
	//cout << solution.minCostClimbingStairs(cost) << endl;


}
