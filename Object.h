#include <cstdlib>
#include <iostream>

using namespace std;

class Object
{
	private:
		string name;
		int value;
		
	public:
		Object();
		string getName();
		void setName(string);
		int getValue();
		void setValue(int);
};

Object::Object()
{
	name = "";
	value = 0;
}

string Object::getName() { return name; };
int Object::getValue() { return value; };
void Object::setName(string nameIn) { name = nameIn; };
void Object::setValue(int valueIn) { value = valueIn; };

