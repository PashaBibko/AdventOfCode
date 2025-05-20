#include <AdventOfCode.h>

static char SearchGrid(const std::vector<std::string>& grid, size_t x, size_t y)
{
	/* Stops read access violations by not reading outside of the grid */
	if (x < 0 || y < 0 || x >= grid.size() || y >= grid[x].size())
		{ return '\0'; }
	
	return grid[x][y];
}

static int Part1(const std::vector<std::string>& grid)
{
	/* Checks for instances of XMAS in the grid with caridnal and diagional directions */
	int count = 0;
	for (size_t x = 0; x < grid.size(); x++)
	{
		for (size_t y = 0; y < grid[x].size(); y++)
		{
			/* Checks current char is an X */
			if (SearchGrid(grid, x, y) != 'X')
				{ continue; }

			/* Checks cardinal directions */

			count = count + (SearchGrid(grid, x - 1, y) == 'M' && SearchGrid(grid, x - 2, y) == 'A' && SearchGrid(grid, x - 3, y) == 'S');
			count = count + (SearchGrid(grid, x + 1, y) == 'M' && SearchGrid(grid, x + 2, y) == 'A' && SearchGrid(grid, x + 3, y) == 'S');
			count = count + (SearchGrid(grid, x, y - 1) == 'M' && SearchGrid(grid, x, y - 2) == 'A' && SearchGrid(grid, x, y - 3) == 'S');
			count = count + (SearchGrid(grid, x, y + 1) == 'M' && SearchGrid(grid, x, y + 2) == 'A' && SearchGrid(grid, x, y + 3) == 'S');

			/* Checks diagonal directions */

			count = count + (SearchGrid(grid, x - 1, y - 1) == 'M' && SearchGrid(grid, x - 2, y - 2) == 'A' && SearchGrid(grid, x - 3, y - 3) == 'S');
			count = count + (SearchGrid(grid, x + 1, y - 1) == 'M' && SearchGrid(grid, x + 2, y - 2) == 'A' && SearchGrid(grid, x + 3, y - 3) == 'S');
			count = count + (SearchGrid(grid, x - 1, y + 1) == 'M' && SearchGrid(grid, x - 2, y + 2) == 'A' && SearchGrid(grid, x - 3, y + 3) == 'S');
			count = count + (SearchGrid(grid, x + 1, y + 1) == 'M' && SearchGrid(grid, x + 2, y + 2) == 'A' && SearchGrid(grid, x + 3, y + 3) == 'S');
		}
	}

	return count;
}

static int Part2(const std::vector<std::string>& grid)
{
	/* Checks for instances of X-MAS in the grid with cardinal directions */
	int count = 0;
	for (size_t x = 0; x < grid.size(); x++)
	{
		for (size_t y = 0; y < grid[x].size(); y++)
		{
			/* Checks if it is at the center of a possible X */
			if (SearchGrid(grid, x, y) != 'A')
				{ continue; }

			/* Finds if there are two instances of MAS diagonally with the A */
			int diagonals = 0;

			diagonals = diagonals + (SearchGrid(grid, x - 1, y - 1) == 'M' && SearchGrid(grid, x + 1, y + 1) == 'S');
			diagonals = diagonals + (SearchGrid(grid, x + 1, y - 1) == 'M' && SearchGrid(grid, x - 1, y + 1) == 'S');
			diagonals = diagonals + (SearchGrid(grid, x - 1, y + 1) == 'M' && SearchGrid(grid, x + 1, y - 1) == 'S');
			diagonals = diagonals + (SearchGrid(grid, x + 1, y + 1) == 'M' && SearchGrid(grid, x - 1, y - 1) == 'S');

			count = count + (diagonals == 2);
		}
	}

	return count;
}

Result AOC24::Day4(const std::string& contents)
{
	/* Transfers the data into a grid */
	std::vector<std::string> grid;

	std::string line;
	std::istringstream stream(contents);

	while (std::getline(stream, line))
		{ grid.emplace_back(line); }
	
	/* Calculates and returns the results */
	return { Part1(grid), Part2(grid) };
}
