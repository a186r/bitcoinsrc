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
	boost::signals2::signal<void()> sig;//�����ź�
	//�źŹ������
	sig.connect(&slot1);
	sig.connect(*slot2);
	sig();//�����ź�
	return 0;
}