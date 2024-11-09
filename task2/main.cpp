#include "iostream"
#include "set"
#include "vector"
#include "stack"

int main()
{
	int InputQty, EnteringNumber;
	std::cout << "IN[]: " << std::endl;
	std::cin >> InputQty;
	std::set <int> RemoveNotUniq;
	std::stack<int> ReversSorting;
	std::vector<int> SortForOut;

	for (int i = 0; i < InputQty; i++)
	{
		std::cin >> EnteringNumber;
		RemoveNotUniq.insert(EnteringNumber);
	}

	for (auto it : RemoveNotUniq)
	{
		ReversSorting.push(it);
	}

	std::cout << "OUT[]: " << std::endl;
	for (;!ReversSorting.empty();)
	{
		SortForOut.push_back(ReversSorting.top());
		ReversSorting.pop();
	}

	for (int i = 0; i < SortForOut.size(); i++)
	{
		std::cout << SortForOut[i] << std::endl;
	}

	return 62;
}