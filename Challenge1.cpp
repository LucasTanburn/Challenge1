#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

string processLine(string line)
{
	bool quote = false; //Assume it is not in quotation marks at the beginning 
	
	string printline;
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == '\"') quote = !quote; //Everything inside "" counts as a quote
		if (line[i] != '\"') //Dont output ""
		{
			if (quote) printline += line[i]; //If it is a quote take the line exactly as it is
			else 
			{
				if (isspace(line[i])) printline += '\n'; //A space outside "" creates a new line
				else printline += line[i]; //If it is not a space then add it to the output
			}
		}
	}
	return printline;
}


int main(int argc, char *argv[])
{
	ifstream inputfile;
	string line;
	int sepcount = 0;
	
	string filepath;
	char sep = '-'; //Set default seperator as '-'
	
	if (argc == 4)
	{
		int i = 1;
		for (; i < 2; i++) if (strcmp(argv[i],"-d") == 0) break; //Find -d flag
		if (argv[i+1][1])
		{
			cout << "Input a single character seperator" << endl;
			return -1;
		} //Return error if anything larger than a character was used for a seperator
		sep = argv[i+1][0];
		if (i == 1) filepath = argv[3];
		if (i == 2) filepath = argv[1]; //Find file path depending on -d position
	}
	else if (argc == 2) filepath = argv[1]; //If no -d flag then just take filepath
	else
	{
		cout << "Include file path and optional seperator marked by -d" << endl;
		return -1;
	} //Tell the user what input is expected if they enter incorrect information
	
	
	inputfile.open(filepath.c_str());
	if (inputfile.fail())
	{
		cout << "Could not open file " << filepath << endl;
		return -1;
	} //Tell user path name was incorrect or that another error occured with opening the file
	while (!inputfile.eof())
	{
		getline(inputfile,line);
		sepcount = line.length(); //Keep the seperator line roughly the same length as the original input line
		
		cout << line << endl; //Neatness
		for (; sepcount > 0; sepcount--, cout << sep); //Output the correct number of seperators
		cout << endl;
		cout << processLine(line); //Process the line into desired form
		cout << endl;
		if (!inputfile.eof()) cout << endl; //Add an extra line between outputs if it is not the end of the file
		
		line.clear();
	}
}