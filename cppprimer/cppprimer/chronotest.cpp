//Chrono是Boost库中用于实践处理的库，主要包含三个概念，时间段，时间点和时钟
#include <iostream>
#include "boost\chrono.hpp"
using namespace std;


//durations表示一段时间间隔
typedef boost::chrono::hours hours;
typedef boost::chrono::minutes minutes;
typedef boost::chrono::seconds seconds;
typedef boost::chrono::milliseconds milliseconds;
typedef boost::chrono::microseconds microseconds;
typedef boost::chrono::nanoseconds nonaseconds;

//clock 表示当前时间，不断的变化
typedef boost::chrono::system_clock system_clock;
typedef boost::chrono::steady_clock steady_clock;
typedef boost::chrono::high_resolution_clock high_resolution_clock;

//time point表示某一个具体的时间点
typedef system_clock::time_point sys_ty;

int main() {
	hours h1(1);
	minutes m1(1);
	minutes m2 = h1 + m1;//只能转化为更小的单位
	cout << m2 << endl;//61 minutes

	hours h2 = boost::chrono::duration_cast<hours>(h1 + m1);//强制转换
	cout << h2 << endl;//1 hour

	cout << system_clock::now() << endl;
	return 0;
}