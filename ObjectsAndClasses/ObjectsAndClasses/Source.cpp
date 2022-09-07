using namespace std;

#include <iostream>
#include "Cup.h"

int main()
{
	cout << "Hello world!" << endl;
	Cup ericsMug("wood pattern", 250, true, false, "wood and metal", 150, "americano");
	Cup backupMug("white", 200, true, false, "styrofoam", 0);

	ericsMug.setContents("Coffee");

	
	backupMug.setContents("coke zero");

	cout << "Eric's mug has " << ericsMug.getContents() << endl;
	bool expectedResult = false;

	int expectedCurrentVolume = 200;
	bool actualResult = backupMug.fillCup(10000);
	int actualCurrentVolume = backupMug.getCurrentVolumeOfContentsInMilliliters();

	if (expectedResult != actualResult) {
		cout << "ERROR something didn't match with result" << endl;
	}

	if (expectedCurrentVolume != actualCurrentVolume) {
		cout << "Volume doesn't match expected" << endl;
	}

}