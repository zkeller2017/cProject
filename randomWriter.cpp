/*
Constructs a paragraph of text based on another text that it takes in.
Right now



*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 
#include<vector>
using namespace std;

/*
Checks to make sure that the whole story contains only valid characters
*/
string processLine(string line)
{
	string newLine = "";

	for(int i = 0; i < line.length(); i++)
	{
		
		char c =  line.at(i);
	
		int ascii = c - 0;
		
		
		if (ascii >= 32 && ascii <= 125) 
		{
			newLine = newLine + c;
		}
		else
		{
			newLine = newLine + " ";
		}

	}
	return newLine;

}

/*
	Lets the user select a text to process and coverts it into a string
*/
string getStory () {
    string line;
    string story;
    string text;
    /*
    int index;
    vector <string> textVector;
    textVector.push_back("theBrokenRoad.txt");
    textVector.push_back("warAndPeace.txt");
    textVector.push_back("mobyDick.txt");
    textVector.push_back("macbeth.txt");
    textVector.push_back("treasureIsland.txt");
    textVector.push_back("theIliad.txt");
    cout << "Type the number of one of the following texts: 1: The Broken Road, 2:  War And Peace, 3: Moby Dick, 4: Macbeth, 5: Treasure Island, 6: The Iliad";
    cout << "\n";
	cout << "text choice number: ";
    cin >> index;
    text = textVector.at(index);
    cout << "hello";
    */
    ifstream myfile ("warAndPeace.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            story += processLine(line);
        }
        myfile.close();
    }
    
    else cout << "Unable to open file";
	return story;
	//std::replace(story.begin(), story.end(), '\n', ' ');
}

/*
	Returns the seed length, as given by the user
*/
int getSeedLength() {
	int seedLength;
	cout << "How long do you want the seed to be? ";
	cout << "\n";
	cout << "seed length: ";
	cin >> seedLength;
	return seedLength;
}

/*
	Returns the output Length, as given by the user
*/	
int getOutputLength() {
	int outputLength;
	cout << "How long do you want the output to be? ";
	cout << "\n";
	cout << "output length: ";
	cin >> outputLength;
	return outputLength;
}

/*
	Runs the program, iterates and populate a string to be outputted
*/
int main () {
	string f = "";
	srand(time(0));
	int seedLength = getSeedLength();
	int outputLength = getOutputLength();
	string story = getStory();
	
	int randSpot;
	randSpot = rand() % story.length();
	// starts after a space
	/*
	while (story.substr(randSpot, 1).compare(" ") != 0)
	{
		randSpot = randSpot + 1;
	}
	//so that it doesn't hit the end of the string
	if (randSpot > outputLength + seedLength)
	{
		randSpot = randSpot - outputLength - seedLength;
	}
	*/
	string seed = story.substr(randSpot, seedLength);
	//cout << "seed is: " << seed;
	//cout << "\n";
	string possFollowing = "";
	string outputText = "";
	int randNext = 0;
	int index = 0;
	//  and outputText.substr(outputText.length() -1, 1).compare(" ") != 0
	cout << outputLength;
	while (index < outputLength)
	{
		//f += "seed: ";
		//f += seed;
		//f += "\n";
		possFollowing = "";
		for (int k = 0; k < story.length() - seedLength - 1 ; k++)
		{
			if (story.substr(k, seedLength) == seed)
			{
				possFollowing += story.substr(k + seedLength, 1);
				//cout << story.substr(k, seedLength) << "\n";
			}
		}
		randNext = rand() % possFollowing.length();
		outputText += possFollowing.substr(randNext, 1);
		seed = seed.substr(1,seed.length()-1) + possFollowing.substr(randNext, 1);
		index = index + 1;
	}
	//f += outputText;
	cout << outputText;
	cout << "\n";

}

