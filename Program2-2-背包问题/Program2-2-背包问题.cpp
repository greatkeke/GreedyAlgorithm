// Program2-2-背包问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include "Program2-2-背包问题.h"
using namespace std;

struct Treasure {
	double w;
	double v;
	double p;
} s[1024];

bool comp(Treasure left, Treasure right) 
{
	return left.p > right.p;
}

int main()
{
	cout << "阿里巴巴与四十大盗-背包问题" << endl;
	
	int n = 0;
	double sum = 0;
	cout << "请输入宝物数量 n 及毛驴的负载能力 m：" << endl;
	cin >> n >> sum;
	cout << "请输入每个宝物的重量和价值，用空格隔开：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i].w >> s[i].v;
		s[i].p = s[i].v / s[i].w;
	}

	sort(s, s + n, comp);

	double current = 0.0;
	double parceledValue = 0.0;
	for (int i = 0; i < n; i++)
	{
		double preSum = current + s[i].w;
		if (preSum <= sum)
		{
			parceledValue += s[i].v;
		}
		else
		{
			parceledValue += (preSum - sum) * s[i].p;
			break;
		}
	}
	cout << "能带走" << parceledValue << "元的宝物" << endl;
	
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
