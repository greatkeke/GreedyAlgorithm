// Program2-1-最优装载问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int limit = 30;
	int gross = 0;
	int current = 0;
	int quantity = 0;
	cout << "请输入载重量 limit 及古董总数 gross:" << endl;
	cin >> limit >> gross;
	int antique[1024];
	cout << "请输入每个古董的重量，用空格分开：" << endl;
	for (int i = 0; i < gross; i++)
	{
		cin >> antique[i];
	}
	cout << antique << endl;
	cout << (antique + gross) << endl;
	sort(antique, antique + gross);
	for (int i = 0; i < gross; i++)
	{
		int tmp = current + antique[i];
		if (tmp <= limit)
		{
			current = tmp;
			quantity += 1;
			continue;
		}
		break;
	}
	cout << "可装载的古董最大数量为: ";
	cout << quantity << endl;
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
