#pragma once

/* Includes Windows API if on the correct system */
#ifdef _WIN32
	#define NOMINMAX
	#define WIN32_LEAN_AND_MEAN
	#include <Windows.h>

	/* Else alerts the user that their system is not supported */
#else
	#error "This code is only designed to work on windows"
#endif // _WIN32

/* Precompiled header to include all used std - libs */

#include <unordered_map>
#include <functional>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>

/* Util function to read a file to a string */
inline const std::string ReadFileToString(const std::filesystem::path& path)
{
	/* Opens the file in binary mode at the end for faster parsing */
	std::ifstream file(path, std::ios::binary | std::ios::ate);
	const std::streamsize len = file.tellg();
	file.seekg(0);

	/* Copies the file to a string */
	std::string contents(len, '\0');
	file.read(&contents[0], len);
	return contents;
}

/* AOC questions returns two ints */
struct Result
{
	int Part1 = -1;
	int Part2 = -1;
};

/* AOC 2024 functions */
namespace AOC24
{
	Result Day1(const std::string& contents);
}

/* Map of all of the functions */
inline std::unordered_map<std::string_view, std::function<Result(const std::string&)>> functions =
{
	{ "24-01", &AOC24::Day1 }
};
