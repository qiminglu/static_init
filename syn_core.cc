
#include <iostream>
#include <vector>
#include <array>

struct ExecSpace
{
	int value;
	std::array<int, 3> aint;
	std::vector<int> vint;

	ExecSpace() = default;

	static ExecSpace& get_instance()
	{
		static ExecSpace space = {};
		return space;
	}

};

int init_space(std::string name)
{
	auto& ins = ExecSpace::get_instance();

	ins.value = 3;
	std::cout << "value = " << ins.value << "\n";

	ins.aint[1] = 2;
	std::cout << "aint = " << ins.aint[1] << "\n";

	ins.vint.push_back(2);
	std::cout << "vint = " << ins.vint.size() << "\n";

	return 1;
}

int res = init_space("space");

void print_init()
{
	std::cout << "init result = " << res << "\n";
}

