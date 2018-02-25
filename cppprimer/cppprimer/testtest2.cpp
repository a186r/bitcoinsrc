#define BOOST_TEST_MODULE mytest
#include <boost/test/included/unit_test.hpp>
#include <iostream>

struct F {
	F() { std::cout << "setup" << '\n'; }
	~F() { std::cout << "teardown" << '\n'; }
};

BOOST_AUTO_TEST_SUITE(mytest)
// BOOST_FIXTURE_TEST_SUITE(mytest, F)�� Ҳ����ֱ��Ϊ��Suite�����е�Case������F������

//CASEִ��ǰ�ȵ���F(),ִ����֮�����~F()
BOOST_FIXTURE_TEST_CASE(test1, F) {
	BOOST_CHECK(true);
}

//test2����Ӱ��
BOOST_AUTO_TEST_CASE(test2) {
	typedef enum {red=8,blue,green=1,yellow,black}color;
	color c = green;
	BOOST_WARN(sizeof(green) > sizeof(char));
	BOOST_CHECK(c == 2);//BOOST_CHECK����ʧ�ܼ���ִ��
	BOOST_REQUIRE(yellow > red);//BOOST_REQUIRE����ʧ�ܼ���ִ�У�����ֹͣ
	BOOST_CHECK(black != 4);
}

BOOST_AUTO_TEST_SUITE_END()