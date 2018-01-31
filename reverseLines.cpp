// File        : reverseLines1.cpp
// Author      : John Carvajal
// Description : This program will read in a file passed in as a command line argument,
//	    	 store a line in a string, reverse the contents of the string,
//               and then print the modified string. It will then loop
//               this process until all lines of the file have been 
//		 read and reversed. 
// Usage       : Pass the file name in with the command line argument

#include <iostream>
#include <fstream>
#include <string>

void reverseString(std::string &str);

int main(int argc,char** argv)
{
	std::cout << "Program has started.\n";

	//check to see if command line argument is valid
	if (argc < 1)
	{
		std::cout << "Error: No command line argument provided\n";
	}
	else
	{
		//try to open the file
		std::string fileName;
		fileName = argv[1];
		std::ifstream inFile(fileName.c_str());
		if(!inFile)
		{
			std::cout << "Error: Unable to open file named " << fileName << std::endl;
			return -1;
		}

		std::cout << "File name is: " << fileName << std::endl << std::endl;

		//read in lines and perform operation
		std::string str;
		while(getline(inFile, str))
		{
			std::cout << "original line is:\n" << str << std::endl;
			reverseString(str);
			std::cout << "reversed line is:" << str << std::endl << std::endl;
		}
		inFile.close();
		std::cout << "Program has ended.\n";
	}
	return 0;
}

void reverseString(std::string &str)
{
	int n = str.length();

	//swap characters
	for (int i=0; i < n/2; i++)
	{
		std::swap(str[i], str[n-i-1]);
	}
}

