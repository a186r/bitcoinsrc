//program options Demo
//���Ը��������ϲ�ͬ�Ĳ���ʹ������ɲ�ͬ�Ĺ��ܣ�
//boost�е�program options�����������������д���Ĳ�����ģ�飬ʹ�ó�����ӵļ���Ч
#include <boost/program_options.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
	using namespace boost::program_options;
	options_description desc("Command line options");
	//��������ѡ���ѡ��ȫ�ƣ���д��������������->Ĭ��ֵ������������
	desc.add_options()
		("help,h", "print help message")
		("person,p",value<string>()->default_value("world"),"person name")
		("file,f",value<vector<string>>(),"input file name");

	variables_map vm;//�洢����Ĳ���
	store(parse_command_line(argc, argv, desc), vm);//��������ѡ���������
	notify(vm);

	if (vm.count("help")) {
		cout << desc << endl;
		return 0;
	}

	cout << "Hellp" << vm["person"].as<string>() << endl;

	if (vm.count("file")) {
		vector<string> files(vm["person"].as< vector <string> > ());
		cout << "Got" << files.size() << "files." << endl;
	}

	return 0;
}

/* ubuntu 16.04 LTS ����
	g++ exanple6.cpp -lbost_program_options

	./a.out
	Hello world

	./a.out -h
	Command line options:
	-h [--help]					print help message
	-p [--person] arg (=world)	person name
	-f [--file] arg				input file name
	
	./.out -p Splay
	Hellp Splay
	
*/