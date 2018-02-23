#include <iostream>
#include "boost/signals2.hpp"
using namespace std;

void slot1() {
	cin.get();
	cout << "slot1 call" << endl;
}

void slot2() {
	cin.get();
	cout << "slot2 call" << endl;
}

int main() {
	boost::signals2::signal<void()> sig;//定义信号
	//信号关联插槽
	sig.connect(&slot1);
	sig.connect(*slot2);
	sig();//发出信号
	return 0;
}