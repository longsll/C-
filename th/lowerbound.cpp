#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a[10] = {1,3,5,56,98};
	int ans = lower_bound(a, a + 5, 1000) - a;//开始，结束，要查找元素
	int sum = upper_bound(a, a + 5, 5) - a;
	cout << "第一个大于5的位置是" << sum << endl; //
	cout << "第一个大于等于5的位置是" << ans << endl; //2

	return 0;
}
