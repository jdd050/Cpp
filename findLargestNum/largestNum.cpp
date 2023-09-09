#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main()
{
	// file read, num as str, int vector
	std::ifstream numbers("numbers.txt");
	std::string num;
	std::vector<int> numVector;

	
	// get numbers
	while (getline(numbers, num)) 
	{
		numVector.push_back(stoi(num));
	}

	// find maximum
	auto maxNum = numVector[0];
	for (int i = 0; i < numVector.size(); i++) 
	{
		if (maxNum < numVector[i]) 
		{
			maxNum = numVector[i];
		}
	}

	// show maximum
	std::cout << "Maximum number in dataset is: " << maxNum << std::endl;

}