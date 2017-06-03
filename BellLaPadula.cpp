#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

//Included Files
#include "ReferenceMonitor.h"

using namespace std;

//Function Prototypes
void addSubjObj(Reference*);
int checkInt(string);

int main()
{
	//Variables
	Reference refMon;
	Instruction instruct;
	string input, buffer;
	vector<string> tokens;
	
	addSubjObj(&refMon);
	
	//Read each line in file
	while(getline(cin, input))
	{
		stringstream ss(input);
		
		while(ss >> buffer)
			tokens.push_back(buffer);
		
		//for(int i = 0; i < tokens.size(); i++)
		//	cout << i << ": " << tokens[i] << endl;
		
		if(tokens[0] == "read" || tokens[0] == "write")
		{
			//Parse input string
			instruct.operation = tokens[0];
			
			if(tokens[0] == "read")
			{
				if(tokens.size() == 3)
				{
					instruct.subject = tokens[1];
					instruct.object = tokens[2];
					
					if(!refMon.processInstruct(instruct))
						cout << "Bad Instruction : " << input << endl;
				}
				else
					cout << "Bad Instruction : " << input << endl;
			}
			else if(tokens[0] == "write")
			{
				if(tokens.size() == 4)
				{
					instruct.subject = tokens[1];
					instruct.object = tokens[2];
					
					if(checkInt(tokens[3])) 
					{
						instruct.value = stoi(tokens[3]);

						if(!refMon.processInstruct(instruct))
							cout << "Bad Instruction : " << input << endl;
					}
					else
						cout << "Bad Instruction : " << input << endl;
				}
				else
					cout << "Bad Instruction : " << input << endl;
			}
			else
				cout << "Bad Instruction : " << input << endl;
		}
		else
			cout << "Bad Instruction : " << input << endl;

		tokens.clear();
		buffer = "";
	} //End while loop
	
	return 0;
}

void addSubjObj(Reference *refMon)
{
	refMon->createSubject("adam", "LOW");
	refMon->createSubject("james", "MEDIUM");
	refMon->createSubject("tim", "HIGH");
	refMon->createSubject("sara", "LOW");
	refMon->createSubject("kristy", "MEDIUM");
	refMon->createSubject("liz", "HIGH");
	
	refMon->createObject("aobj", "LOW");
	refMon->createObject("jobj", "MEDIUM");
	refMon->createObject("tobj", "HIGH");
	refMon->createObject("sobj", "LOW");
	refMon->createObject("kobj", "MEDIUM");
	refMon->createObject("lobj", "HIGH");
}
	
//Checks each character and determines if it's a number
int checkInt(string number)
{
	for(int i = 0; i < number.length(); i++)
		if(!isdigit(number[i]))
			return 0;
	
	return 1;
}
