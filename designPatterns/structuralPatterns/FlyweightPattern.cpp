/*
@Author @Source: https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns

Usage: The pattern for saving memory (basically) by sharing properties of objects.

*/

#include <iostream>
#include <string>
#include <vector>

#define NUMBER_OF_SAME_TYPE_CHARS 3

using namespace std;

class FlyweightCharacter;

class FlyweightCharacterAbstractBuilder {
	FlyweightCharacterAbstractBuilder() {}
	~FlyweightCharacterAbstractBuilder() {}
public:
	static vector<float> fontSizes; 
	static vector<string> fontNames; 

	static void setFontsAndNames();
	static FlyweightCharacter createFlyweightCharacter(unsigned short fontSizeIndex,
		unsigned short fontNameIndex,
		unsigned short positionInStream);
};

vector<float> FlyweightCharacterAbstractBuilder::fontSizes(NUMBER_OF_SAME_TYPE_CHARS);
vector<string> FlyweightCharacterAbstractBuilder::fontNames(NUMBER_OF_SAME_TYPE_CHARS);
void FlyweightCharacterAbstractBuilder::setFontsAndNames() {
	fontSizes[0] = 1.0;
	fontSizes[1] = 1.5;
	fontSizes[2] = 2.0;

	fontNames[0] = "first_font";
	fontNames[1] = "second_font";
	fontNames[2] = "third_font";
}

class FlyweightCharacter {
	unsigned short fontSizeIndex; // index instead of actual font size
	unsigned short fontNameIndex; // index instead of font name
	unsigned positionInStream;

public:

	FlyweightCharacter(unsigned short fontSizeIndex, unsigned short fontNameIndex, unsigned short positionInStream):
		fontSizeIndex(fontSizeIndex), fontNameIndex(fontNameIndex), positionInStream(positionInStream) {}
	void print() {
		cout << "Font Size: " << FlyweightCharacterAbstractBuilder::fontSizes[fontSizeIndex]
			<< ", font Name: " << FlyweightCharacterAbstractBuilder::fontNames[fontNameIndex]
			<< ", character stream position: " << positionInStream << endl;
	}
	~FlyweightCharacter() {}
};

FlyweightCharacter FlyweightCharacterAbstractBuilder::createFlyweightCharacter(unsigned short fontSizeIndex, unsigned short fontNameIndex, unsigned short positionInStream) {
	
  FlyweightCharacter fc(fontSizeIndex, fontNameIndex, positionInStream);

	return fc;
}

int main() {
	vector<FlyweightCharacter> chars;

	FlyweightCharacterAbstractBuilder::setFontsAndNames();
	unsigned short limit = NUMBER_OF_SAME_TYPE_CHARS;

	for (unsigned short i = 0; i < limit; i++) {
		chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(0, 0, i));
		chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(1, 1, i + 1 * limit));
		chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(2, 2, i + 2 * limit));
	}

	for (unsigned short i = 0; i < chars.size(); i++) {
		chars[i].print();
	}
	return 0;
}