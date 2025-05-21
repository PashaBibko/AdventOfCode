#include <AdventOfCode.h>

int main(int argc, char** argv)
{
	/* Verifies correct ammount of args */
	if (argc != 3)
	{
		std::cout << "Invalid use of program. Correct use:\n";
		std::cout << "\tProgram [Year - Day] [Data file]\n";
		std::cout << "\nFor example:\n";
		std::cout << "\tAdventOfCode.exe 24-01 AOC-24-01.txt\n";

		/* Returns early */
		return -1;
	}

	/* Finds if the current day has been implemented */
	std::string day = argv[1]; /* Index 0 is reserved for program name */
	if (functions.contains(day) == false)
	{
		std::cout << "Day {" << day << "} has not been implemented within this program\n";

		/* Returns early */
		return -1;
	}
	
	/* Verifies data file exists */
	std::filesystem::path data = argv[2];
	if (std::filesystem::exists(data) == false)
	{
		std::cout << "Could not find filepath: {" << std::filesystem::absolute(data) << "}";

		/* Returns early */
		return -1;
	}

	/* Calls the correct function */
	const Result res = functions[day](ReadFileToString(data));
	std::cout << "Result of [" << day << "]: [" << res.Part1 << ", " << res.Part2 << "]\n";

	return 0;
}
