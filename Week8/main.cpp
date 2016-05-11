#include <iostream>
#include <vector>

void Generator(std::vector<int> arrays, std::vector<int> values,std::vector<std::vector<int>>& destination)
{
	if (arrays.size()<=0)
	{
		destination.push_back(values);
		return;
	}
	for (int j = 0; j < arrays.size(); j++)
	{
		int temp = arrays[j];
		values.push_back(arrays[j]);
		arrays.erase(arrays.begin() + j);
		Generator(arrays, values,destination);
		arrays.insert(arrays.begin() + j, temp);
		values.pop_back();
	}
}

int main(int argc, char** argv)
{	
	int size = 3;
	std::vector<int> arrays;
	std::vector<int> values;
	std::vector<std::vector<int>> destination;
	for (int i = 0; i < size; i++)
	{
		arrays.push_back(i + 1);
	}
	Generator(arrays,values, destination);
	return 0;
}