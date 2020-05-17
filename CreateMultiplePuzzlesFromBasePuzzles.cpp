/*To create multiple distinct puzzles from a single base puzzle by doing stuff like rotating every row of the matrix by 3 positions, etc.*/ 

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstdlib>

#include <vector>
#include <algorithm>

#include <fstream>

#include<string.h>
#include<random>

using namespace std;

vector<string> alreadyEnteredPuzzles;

int checkIfAlreadyPresent(string str)
{
	//ifstream fin;
	//vector<string> alreadyEnteredPuzzles;
	//string line;
	
	/*
	fin.open("/home/s/Sudoku_generator/Generated_Puzzles/MultiplePuzzles.txt");
	while (fin)
	{
		getline(fin, line);
		alreadyEnteredPuzzles.push_back(line);
	}
	*/
	int flag = -1;
	if (find(alreadyEnteredPuzzles.begin(), alreadyEnteredPuzzles.end(), str) != alreadyEnteredPuzzles.end())
	{
		flag = 1;
	}
	else
	{
		flag = 0;
	}
	/*
	for (int i=0; i<alreadyEnteredPuzzles.size();i++)
	{
		if (alreadyEnteredBasePuzzles[i].compare(line) == 0)
		{
			
			flag = 1;
			return flag;
			break;
		}
	}
	*/
	//fin.close();
	return flag;
}

void addPuzzle(string str)
{
	int flag = -1;
	ofstream fout;
	
	flag = checkIfAlreadyPresent(str);
	if (flag == 1)
	{
		//don't add
		cout<<"Whoa! The puzzle already exists! What are the odds!";		
	}
	else
	{
		alreadyEnteredPuzzles.push_back(str);
		fout.open("/home/s/Sudoku_generator/Generated_Puzzles/MultiplePuzzles.txt", ios::app);
		fout<<str<<endl;
		flag = 0;
	}
	fout.close();
}

string toRight(string str)
{cout<<"Inside the toRight(string) function..."<<endl;
	int start = 0;
	int size = 9;
	string finalStr = "";
	cout<<str<<endl;
	for (int j=0; j<9; j++)
	{cout<<"D4"<<endl;
		string row;
		row = str.substr(start, size);
		rotate(row.begin(), row.begin()+3, row.end());
		finalStr.append(row);
		start = start + size;
	}
	addPuzzle(finalStr);
	cout<<"D7"<<endl;
	return finalStr;
}

string toLeft(string str)
{
	int start = 0;
	int size = 9;
	string finalStr = "";
	for (int j=0; j<9; j++)
	{
		string row;
		row = str.substr(start, size);
		rotate(row.rbegin(), row.rbegin()+3, row.rend());
		finalStr.append(row);
		start = start + size;
	}
	addPuzzle(finalStr);
	return finalStr;
}

string up(string str)
{
	//implement this function...
	int mat[10][10];
	int count = 0;
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			char temp = str[count];
			int actualDigit = temp - '0';
			mat[j][i] = actualDigit;
			count++;
		}
	}
	string line = "";
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			string temp = to_string(mat[i][j]);
			//fout<<mat[i][j];
			line.append(temp);
		}
	}
	
	int start = 0;
	int size = 9;
	string finalStr = "";
	for (int j=0; j<9; j++)
	{
		string row;
		row = line.substr(start, size);
		rotate(row.begin(), row.begin()+3, row.end());
		finalStr.append(row);
		start = start + size;
	}
	addPuzzle(finalStr);
	return finalStr;
}

string down(string str)
{
	//implement this function...
	int mat[10][10];
	int count = 0;
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			char temp = str[count];
			int actualDigit = temp - '0';
			mat[j][i] = actualDigit;
			count++;
		}
	}
	string line = "";
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			string temp = to_string(mat[i][j]);
			//fout<<mat[i][j];
			line.append(temp);
		}
	}
	
	int start = 0;
	int size = 9;
	string finalStr = "";
	for (int j=0; j<9; j++)
	{
		string row;
		row = line.substr(start, size);
		rotate(row.rbegin(), row.rbegin()+3, row.rend());
		finalStr.append(row);
		start = start + size;
	}
	addPuzzle(finalStr);
	return finalStr;
}


int main()
{
	ofstream fout;
	ifstream fin;
	ifstream fin2;
	string line = "";
	vector<string> alreadyEnteredBasePuzzles;
	
	fin.open("/home/s/Sudoku_generator/Generated_Puzzles/BasePuzzles.txt");
	while (fin)
	{
		getline(fin, line);
		if (line.compare("") != 0)
		{
			alreadyEnteredBasePuzzles.push_back(line);
		}
		cout<<"alreadyEnteredBasePuzzles.size(): "<<alreadyEnteredBasePuzzles.size()<<endl;
		cout<<"line: "<<line<<" ";
	}
	line = "";
	fin.close();
	
	
	/*so because of the following fin2 operations, we don't have to get all the puzzles from the MultiplesPuzzles.txt file in situations where we have to check if a string is already present like in the checkIfAlreadyPresent(string) function before adding...
	i.e., instead of using a while loop before every insertion with the help of the checkIfAlreadyPresent(string) function, we are now maintaining a global vector<string> containing all the puzzles in the MultiplePuzzles.txt file and we'll also add a new puzzle to this vector along with the MultiplePuzzles.txt file...*/
	fin2.open("/home/s/Sudoku_generator/Generated_Puzzles/MultiplePuzzles.txt");
	cout<<"D1"<<endl;
	int fin2Count = 0;
	while (fin2)
	{//cout<<"D3"<<endl;
		getline(fin2, line);
		if (line.compare("") != 0)
		{
			alreadyEnteredPuzzles.push_back(line);
			fin2Count++;
		}
	}
	cout<<"D2 fin2Count = "<<fin2Count<<endl;
	fin2.close();
	//for (int i=0; i<alreadyEnteredPuzzles.size(); i++)
	//	cout<<alreadyEnteredPuzzles[i]<<endl;
	
	
	for (int i=0; i<alreadyEnteredBasePuzzles.size(); i++)
	{
		string tempStrRight, tempStrLeft, tempStrLeftLeft, tempStrRightRight;
		string tempStrUp, tempStrDown, tempStrDownDown, tempStrUpUp;
		cout<<"D6"<<endl;
		addPuzzle(alreadyEnteredBasePuzzles[i]);
		tempStrRight = toRight(alreadyEnteredBasePuzzles[i]);	/*row-wise: shift each row to the right by 3 positions.*/
		tempStrLeft = toLeft(alreadyEnteredBasePuzzles[i]);	/*row-wise: shift each row to the left by 3 positions.*/
		tempStrLeftLeft = toLeft(tempStrLeft);
		tempStrRightRight = toRight(tempStrRight);
		/*these temp strings have undergone both the toRight and toLeft functions, so now you can use these strings also for the following functions along with the original alreadyEnteredBasePuzzles[i] string...*/
		/*in short, trying all the different permutations and combinations, maybe, write another program later to do this in a sophisticated manner.*/
		
		tempStrUp = up(alreadyEnteredBasePuzzles[i]);	/*column-wise: shift each cloumn upwards by 3 positions*/
		tempStrDown = down(alreadyEnteredBasePuzzles[i]);	/*column-wise: shift each cloumn downwards by 3 positions*/
		
		tempStrDownDown = down(tempStrDown);
		tempStrUpUp = up(tempStrUp);
		
		toRight(tempStrUp);
		toLeft(tempStrUp);
		toRight(tempStrDown);
		toLeft(tempStrDown);
		up(tempStrRight);
		up(tempStrLeft);
		down(tempStrRight);
		down(tempStrLeft);
		
	}
	return 0;
}

