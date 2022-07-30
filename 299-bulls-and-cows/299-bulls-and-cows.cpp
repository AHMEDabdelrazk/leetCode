class Solution {
public:
    string getHint(string secret, string guess)
{
	string hint;

	int bull_num = 0;
	int cow_num = 0;
	std::unordered_map<char, int> remain_secret;
	std::list<char> cow_candidates;

	int i = 0;
	while (i < secret.length() || i < guess.length())
	{
		if (i < secret.length() && i < guess.length())
		{
			if (secret[i] == guess[i])
			{
				++bull_num;
			}
			else
			{
				remain_secret[secret[i]]++;
				cow_candidates.push_back(guess[i]);
			}
		}
		else if (i < secret.length())
		{
			remain_secret[secret[i]]++;
		}
		else
		{
			cow_candidates.push_back(guess[i]);
		}
		++i;
	 }

	for (std::list<char>::iterator it = cow_candidates.begin(); it != cow_candidates.end(); it++)
	{
		if (remain_secret[*it] > 0)
		{
			++cow_num;
			remain_secret[*it]--;
		}
	}
	hint = std::to_string(bull_num) + "A" + std::to_string(cow_num) + "B";

	return hint;
}
};