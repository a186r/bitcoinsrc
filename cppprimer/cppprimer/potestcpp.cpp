//program options Demo
//可以给程序配上不同的参数使程序完成不同的功能，
//boost中的program options就是用来处理命令行传入的参数的模块，使得程序更加的简洁高效
#include <boost/program_options.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
	using namespace boost::program_options;
	options_description desc("Command line options");
	//定义描述选项：（选项全称，缩写），（参数类型->默认值），（描述）
	desc.add_options()
		("help,h", "print help message")
		("person,p",value<string>()->default_value("world"),"person name")
		("file,f",value<vector<string>>(),"input file name");

	variables_map vm;//存储传入的参数
	store(parse_command_line(argc, argv, desc), vm);//根据描述选项解析参数
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

/* ubuntu 16.04 LTS 编译
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