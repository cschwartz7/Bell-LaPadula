#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>

#include "Object.h"
#include "Subject.h"
#include "Instruction.h"

using namespace std;

struct subjLevels
{
	Subject subject;
	int level;
};

struct objLevels
{
	Object object;
	int level;
};

class Reference
{
	private:
		vector<subjLevels> mySubjects;
		vector<objLevels> myObjects;
		
	public:
		void createSubject(string, string);
		void createObject(string, string);
		int processInstruct(Instruction);
		void printState();
};

void Reference::createSubject(string name, string level)
{
	subjLevels sub;
	
	sub.subject.setName(name);
	
	if(level == "LOW")
		sub.level = 1;
	else if(level == "MEDIUM")
		sub.level = 2;
	else
		sub.level = 3;
	
	mySubjects.push_back(sub);
}

void Reference::createObject(string name, string level)
{
	objLevels obj;
	
	obj.object.setName(name);
	
	if(level == "LOW")
		obj.level = 1;
	else if(level == "MEDIUM")
		obj.level = 2;
	else
		obj.level = 3;
	
	myObjects.push_back(obj);
}

int Reference::processInstruct(Instruction instruct)
{
	int subFound = 0, objFound = 0;
	int subIndex, objIndex;
		
	//Tests to see if the subject read is in the system
	for(int i = 0; i < mySubjects.size(); i++)
	{
		if(mySubjects[i].subject.getName() == instruct.subject)
		{
			subFound = 1;
			subIndex = i;
			break;
		}
	}
	
	//Tests to see if the object read is in the system
	for(int j = 0; j < myObjects.size(); j++)
	{
		if(myObjects[j].object.getName() == instruct.object)
		{
			objFound = 1;
			objIndex = j;
			break;
		}
	}	
	
	if(subFound != 1 || objFound != 1)
		return 0;
	else
	{
		if(instruct.operation == "read")
		{
			if(mySubjects[subIndex].level >= myObjects[objIndex].level)
			{
				mySubjects[subIndex].subject.setTemp(myObjects[objIndex].object.getValue());	
				cout << "Access Granted\t: " << instruct.subject << " reads " << instruct.object << endl;
				printState();
			}
			else
				cout << "Access Denied\t: " << instruct.operation << " " << instruct.subject << " " << instruct.object << " " << instruct.value << endl;
		}
		else if(instruct.operation == "write")
		{	
			if(mySubjects[subIndex].level <= myObjects[objIndex].level)
			{				
				myObjects[objIndex].object.setValue(instruct.value);
				cout << "Access Granted\t: " << instruct.subject << " writes value " << instruct.value << " to " << instruct.object << endl;
				printState();
			}
			else
				cout << "Access Denied\t: " << instruct.operation << " " << instruct.subject << " " << instruct.object << " " << instruct.value << endl;
		}
	}
	
	return 1;
}

void Reference::printState()
{
	cout << "+------------------------The current state is-------------------------+" << endl;
	cout << "|" << setw(8) << "subject" << " |";
	
	for(int i = 0; i < mySubjects.size(); i++)
		cout << setw(8) << mySubjects[i].subject.getName() << " |";
	
	cout << endl;
	cout << "|" << setw(8) << "value" << " |";
	
	for(int i = 0; i < mySubjects.size(); i++)
		cout << setw(8) << mySubjects[i].subject.getTemp() << " |";
	
	cout << endl;
	cout << "+---------------------------------------------------------------------+" << endl;
	cout << "|" << setw(8) << "object" << " |";
	
	for(int i = 0; i < myObjects.size(); i++)
		cout << setw(8) << myObjects[i].object.getName() << " |";
	
	cout << endl;
	cout << "|" << setw(8) << "value" << " |";
	
	for(int i = 0; i < myObjects.size(); i++)
		cout << setw(8) << myObjects[i].object.getValue() << " |";
	
	cout << endl;
	cout << "+---------------------------------------------------------------------+" << endl;
}