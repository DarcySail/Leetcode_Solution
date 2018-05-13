int maxProfit(vector<int>& prices)
{
    if(prices.size() == 0)  return 0;
    int max = 0;

    int min_value = prices[0];
    for(int i = 1; i < prices.size(); ++i)
        if(min_value > prices[i])
            min_value = prices[i];
        else
            max = max > prices[i] - min_value ? max : prices[i] - min_value;
    return max;
}