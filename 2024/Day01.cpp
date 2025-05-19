#include <AdventOfCode.h>

static int Part1(const std::vector<int>& lhs, const std::vector<int>& rhs)
{
	/* Loops over and adds the difference to the result */
	int result = 0;
	for (int i = 0; i < lhs.size(); i++)
	{
		result = result + std::abs(lhs[i] - rhs[i]);
	}

	return result;
}

static int Part2(const std::vector<int>& lhs, const std::vector<int>& rhs)
{
	/* Counts occurences in the right list */
	std::unordered_map<int, int> occurences;
	for (const auto& item : rhs)
		{ occurences[item]++; }

	/* For each item in the left list adds it to the result times by it's occurences in the right */
	int result = 0;
	for (const auto& item : lhs)
	{
		if (occurences.contains(item))
			{ result = result + (item * occurences[item]); }
	}

	return result;
}

Result AOC24::Day1(const std::string& contents)
{
	/* Parses the data into vectors lhs and rhs */
	std::vector<int> lhs, rhs;

	std::string line;
	std::istringstream stream(contents);

	while (std::getline(stream, line))
	{
		size_t pos = line.find(' ');

		std::string first = line.substr(0, pos);
		std::string second = line.substr(pos + 1);

		lhs.emplace_back(std::stoi(first));
		rhs.emplace_back(std::stoi(second));
	}

	/* Sorts the data as both parts require it */
	std::sort(lhs.begin(), lhs.end());
	std::sort(rhs.begin(), rhs.end());

	/* Calculates the result and returns it */
	return { Part1(lhs, rhs), Part2(lhs, rhs) };
}
