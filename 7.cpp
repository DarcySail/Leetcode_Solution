class Solution {
public:
	int reverse(int x)
	{
		const long long MAX = 2147483647;
		const long long MIN = (-2147483647 - 1);
		bool flag = x > 0 ? true : false;

		long long result = 0;
		long long longx = x;
		longx = flag ? longx : -longx;
		do{	
			int tmp = longx % 10;
			result *= 10;
			result += tmp;
		}while(longx /= 10);
		result = flag ? result : -result;
		if(result > MAX || result < MIN)
			return 0;
		return (int) result;
	}

};