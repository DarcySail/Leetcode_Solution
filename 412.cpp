class Solution {
public:
vector<string> fizzBuzz(int n) 
{
	int _count = 1;
	vector<string> result;
	while(_count <= n)
	{
		if(_count % 3 == 0 && _count % 5 == 0)
			result.push_back("FizzBuzz");
		else if(_count % 3 == 0)
			result.push_back("Fizz");
		else if(_count % 5 == 0)
			result.push_back("Buzz");
		else
			result.push_back(to_string(_count));
		++_count;
	}
	return result;
}
};