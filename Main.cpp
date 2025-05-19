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
	if (functions.contains(day))
	{
		std::cout << "Day {" << day << "} has not been implemented within this program\n";

		/* Returns early */
		return -1;
	}
	
	/* Verifies data file exists */
	std::filesystem::path data = argv[2];
	if (std::filesystem::exists(data))
	{
		std::cout << "Could not find filepath: {" << std::filesystem::absolute(data) << "}";

		/* Returns early */
		return -1;
	}

	/* Calls the correct function */
	try
	{
		std::cout << "Result of [" << day << "]" << functions[day]("");
	}

	/* Catches all errors thrown from program */
	catch (...)
	{
		/* Throws a breakpoint if there is a debugger */
		if (IsDebuggerPresent())
			{ __debugbreak(); }

		/* Else returns early */
		return -1;
	}

	return 0;
}
