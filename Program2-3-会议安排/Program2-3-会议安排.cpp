// Program2-3-会议安排.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;

struct Meeting {
	int Id;
	int Begin;
	int End;
	bool Compatiable(Meeting next) {
		return next.Begin >= End || Begin >> next.End;
	}
} meetings[1024];
int n = 0;
bool comp(Meeting left, Meeting right) {
	if (left.End == right.End)
	{
		return left.Begin > right.Begin;
	}
	return left.End < right.End;
}

int main()
{
	n = 10;
	cout << "会议总数 n:" << n << endl;
	meetings[0].Id=1;meetings[0].Begin = 3; meetings[0].End = 6;
	meetings[1].Id=2;meetings[1].Begin = 1; meetings[1].End = 4;
	meetings[2].Id=3;meetings[2].Begin = 5; meetings[2].End = 7;
	meetings[3].Id=4;meetings[3].Begin = 2; meetings[3].End = 5;
	meetings[4].Id=5;meetings[4].Begin = 5; meetings[4].End = 9;
	meetings[5].Id=6;meetings[5].Begin = 3; meetings[5].End = 8;
	meetings[6].Id=7;meetings[6].Begin = 8; meetings[6].End = 11;
	meetings[7].Id=8;meetings[7].Begin = 6; meetings[7].End = 10;
	meetings[8].Id=9;meetings[8].Begin = 8; meetings[8].End = 12;
	meetings[9].Id=10;meetings[9].Begin = 12; meetings[9].End = 14;
	cout << "所有的会议开始和结束时间，空格分隔" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "第" << meetings[i].Id << "个会议，开始:" << meetings[i].Begin << "-结束:" << meetings[i].End << endl;
	}
	
	sort(meetings, meetings + n, comp);
	Meeting last = meetings[0];
	cout << "选择第" << last.Id << "个会议" << endl;
	for (int i = 1; i < n; i++)
	{
		if (last.Compatiable(meetings[i]))
		{
			last = meetings[i];
			cout << "选择第" << last.Id << "个会议" << endl;
		}
	}

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
