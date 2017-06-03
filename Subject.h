#include <cstdlib>
#include <iostream>

using namespace std;

class Subject
{
	private:
		string name;
		int temp;
		
	public:
		Subject();
		string getName();
		void setName(string);
		int getTemp();
		void setTemp(int);
};

Subject::Subject()
{
	name = "";
	temp = 0;
}

string Subject::getName() { return name; };
int Subject::getTemp() { return temp; };
void Subject::setName(string nameIn) { name = nameIn; };
void Subject::setTemp(int tempIn) { temp = tempIn; };