#include <AdventOfCode.h>

static bool IsGroupValid(const std::unordered_map<int, std::unordered_set<int>>& reqs, const std::vector<int>& group)
{
	/* Loops over every item within the page */
	for (int i = 0; i < group.size(); i++)
	{
		/* Checks if any of the previous items have it as a requirement */
		/* If so the group is not valid */
		for (int j = 0; j != i; j++)
		{
			const std::unordered_set<int>& pageReqs = reqs.at(group[j]);

			if (pageReqs.contains(group[i]))
				{ return false; }
		}
	}

	return true;
}

static int Part1(const std::unordered_map<int, std::unordered_set<int>>& reqs, const std::vector<std::vector<int>>& pages)
{
	/* Works out how many pages follow the requirements */
	int result = 0;
	for (const auto& group : pages)
	{
		/* Adds the value in the middle to the result if valid */
		if (IsGroupValid(reqs, group))
			{ result = result + group.at(group.size() / 2); }
	}

	return result;
}

static int Part2(const std::unordered_map<int, std::unordered_set<int>>& reqs, const std::vector<std::vector<int>>& pages)
{
	return -1;
}

Result AOC24::Day5(const std::string& contents)
{
	/* Readies the data for parsing */
	std::istringstream stream(contents);
	std::string line;

	/* Parses the requirments for each page */
	std::unordered_map<int, std::unordered_set<int>> requirements = {};

	bool parsingFirstSection = true;
	while (std::getline(stream, line) && parsingFirstSection)
	{
		/* Stops when it hits the seperating line */
		if (line.length() == 1)
		{
			parsingFirstSection = false;
			continue;
		}

		int lhs = std::stoi(line.substr(0, 2));
		int rhs = std::stoi(line.substr(3, 2));

		requirements[rhs].insert(lhs);
	}

	/* Parses the page numbers */
	std::vector<std::vector<int>> pages;
	while (std::getline(stream, line))
	{
		std::vector<int>& current = pages.emplace_back();

		for (size_t i = 0; i < (line.length() + 2) / 3; i++)
			{ current.push_back(std::stoi(line.substr(i * 3, 2))); }
	}

	/* Calculates the result and returns it */
	return { Part1(requirements, pages), Part2(requirements, pages) };
}
