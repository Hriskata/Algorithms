#include <iostream>
#include <stack>
#include <vector>

void StackMergeSort(std::vector<int> arr)
	{
		int arr_index = 0;
		int size = arr.size();

		std::vector<int> rezult;
		std::stack<int> temp;

		while (size  != arr_index)
		{
			int temp_value = arr.at(arr_index);

			if (rezult.size() == 0)
			{
				rezult.push_back(temp_value);
				arr_index++;
			}
		
			if (rezult.size() == 1 && temp.size() == 0)
			{
				if (arr.at(arr_index) < rezult.back())
				{
					temp.push(rezult.back());
					rezult.pop_back();
					rezult.push_back(arr.at(arr_index));
					arr_index++;
				}
				else {
					temp.push(arr.at(arr_index));
					arr_index++;
				}
			}
			else if (temp_value < rezult.back())
			{
				while (rezult.size() !=0 && temp_value < rezult.back())
				{
					temp.push(rezult.back());
					rezult.pop_back();
				}
				rezult.push_back(temp_value);
				arr_index++;
			}
			else if (temp_value <= temp.top())
			{
				rezult.push_back(temp_value);
				arr_index++;
			}
			else {
				while (temp.size() != 0 && temp.top() < temp_value)
				{
					rezult.push_back(temp.top());
					temp.pop();
				}
				temp.push(temp_value);
				arr_index++;
			}
		}

		while (temp.size() != 0)
		{
			rezult.push_back(temp.top());
			temp.pop();
		}

		for (int i = 0; i < size; i++)
		{
			std::cout << rezult.at(i)<<" ";
		}
	} 

int main()
{
	std::vector<int> arr = { 10, 5, 7, 15, 1, 6, 10, 35};
	//std::vector<int> arr = { 1,2,3,4,5,6,7,8};
	StackMergeSort(arr);
}
