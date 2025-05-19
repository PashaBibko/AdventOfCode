#include <AdventOfCode.h>

static bool IsRowValid(const std::vector<int>& row)
{
	/* Loops over the row */
	bool inc = row[0] < row[1];
	for (size_t i = 0; i < row.size() - 1; i++)
	{
		/* Checks the current pair follow the seemingly random criteria */
		if ((std::abs(row[i] - row[i + 1]) >= 4) || (row[i] == row[i + 1]) || (inc != row[i] < row[i + 1]))
			{ return false; }
	}

	return true;
}

static int Part1(const std::vector<std::vector<int>>& data)
{
	/* Loops over all of the rows and tracks how many are valid */
	int result = 0;
	for (const std::vector<int>& row : data)
		{ result = result + IsRowValid(row); }

	return result;
}

static int Part2(const std::vector<std::vector<int>>& data)
{
	/* Loops over the rows and see's if each row can be valid by removing one item */
	int result = 0;
	for (const std::vector<int>& row : data)
	{
		bool valid = false;

		for (int i = 0; i < row.size(); i++)
		{
			/* Creates a duplicate without the current index item */
			std::vector<int> r = row;
			r.erase(r.begin() + i);

			valid = IsRowValid(r) || valid;
		}

		result = result + (int)valid;
	}

	return result;
}

Result AOC24::Day2(const std::string& contents)
{
	/* Parses the data into a vector for each line */
	std::vector<std::vector<int>> data;

	std::string line;
	std::istringstream stream(contents);

	while (std::getline(stream, line))
	{
		std::vector<int>& current = data.emplace_back();

		size_t last = 0;
		size_t pos = line.find_first_of(' ');
		while (last != std::string::npos)
		{
			std::string num = line.substr(last, pos - last);
			current.emplace_back(std::stoi(num));

			last = pos;
			pos = line.find_first_of(' ', last + 1);
		}
	}

	/* Calculates the result and returns it*/
	return { Part1(data), Part2(data) };
}
