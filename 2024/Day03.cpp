#include <AdventOfCode.h>

static bool IsNum(const char c)
{
	return c >= '0' && c <= '9';
}

static int instances = 0;

static int IsValidMul(const std::string& contents, size_t start)
{
	/* Checks for valid start */
	if (contents[start] == 'm' && contents[start + 1] == 'u' && contents[start + 2] == 'l' && contents[start + 3] == '(')
	{
		size_t startNumIndex = start + 4;
		size_t curntNumIndex = start + 4;

		/* Finds the first digit and returns if not valid */
		while (IsNum(contents[curntNumIndex]))
			{ curntNumIndex++; }

		if (startNumIndex == curntNumIndex)
			{ return 0; }

		int lhs = std::stoi(contents.substr(startNumIndex, curntNumIndex - startNumIndex));

		/* Checks for the comma */
		if (contents[curntNumIndex] != ',')
			{ return 0; }

		/* Finds the second digit and returns if not valid */
		startNumIndex = ++curntNumIndex;

		while (IsNum(contents[curntNumIndex]))
			{ curntNumIndex++; }

		if (startNumIndex == curntNumIndex)
			{ return 0; }

		int rhs = std::stoi(contents.substr(startNumIndex, curntNumIndex - startNumIndex));

		/* Checks for closing bracket */
		if (contents[curntNumIndex] != ')')
			{ return 0; }

		return lhs * rhs;
	}

	return 0;
}

static int Part1(const std::string& contents)
{
	/* Loops over the string and finds all instances of mul(x, y) and adds their result */
	int result = 0;
	for (int i = 0; i < contents.size() - 8; i++)
		{ result = result + IsValidMul(contents, i); }

	return result;
}

static int Part2(const std::string& contents)
{
	/* Loops over the string and finds all instances of mul(x, y) and adds their result */
	/* Enables on "do()" and disables on "don't(). Starts enabled */
	int result = 0;
	bool enabled = true;

	for (int i = 0; i < contents.size() - 8; i++)
	{
		/* Checks if it should be enabled or not */
		if (contents.substr(i, 4) == std::string("do()"))
			{ enabled = true; }

		if (contents.substr(i, 7) == std::string("don't()"))
			{ enabled = false; }

		/* Only adds if it is enabled */
		if (enabled)
			{ result = result + IsValidMul(contents, i); }
	}

	return result;
}

Result AOC24::Day3(const std::string& contents)
{
	/* NO MANIPULATION OF DATA YAYYYYYYYYYYY */
	return { Part1(contents), Part2(contents) };
}
