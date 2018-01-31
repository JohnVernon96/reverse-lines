// File        : reverseLines1.cpp
// Author      : John Carvajal
// Description : This program will read in a file passed in as a command line argument,
//	    	 store a line in a string, reverse the contents of the string,
//               and then print the modified string. It will then loop
//               this process until all lines of the file have been 
//		 read and reversed. 
// Usage       : Pass the file name in with the command line argument


//includes
#include <iostream>
#include <fstream>
#include <string>

//function prototypes
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
		//create string named fileName
		std::string fileName;
		
		//store command line argument in fileName
		fileName = argv[1];
		
		//create ifstream object and pass it file name
		std::ifstream inFile(fileName.c_str());
		
		//error message if file name does not exist
		if(!inFile)
		{
			std::cout << "Error: Unable to open file named " << fileName << std::endl;
			return -1;
		}
		
                //print file name
		std::cout << "File name is: " << fileName << std::endl << std::endl;

		//read in lines and perform operation
		//make new string called str
		std::string str;
		
		//loop through reading all lines of data in the file
		while(getline(inFile, str))
		{
			std::cout << "original line is:\n" << str << std::endl;
			
			//method to reverse str;
			reverseString(str);
			
			//print modified str
			std::cout << "reversed line is:" << str << std::endl << std::endl;
		}
		
		//close file
		inFile.close();
		
		std::cout << "Program has ended.\n";
	}
	return 0;
}

//functions
void reverseString(std::string &str)
{
	int n = str.length();

	//swap characters
	for (int i=0; i < n/2; i++)
	{
		std::swap(str[i], str[n-i-1]);
	}
}
