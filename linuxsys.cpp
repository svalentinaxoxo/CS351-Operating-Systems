/***********************************************************************************
* Shelby Laquitara 
* 03/26/2017
* linuxsys.cpp
*
* This program gets and displays general and time information about the system.
***********************************************************************************/
#include <iostream>
#include <fstream> //file stream
#include <string> 

using namespace std;

void readFile(char *fileName, string about); //function prototype declaring readFile

int main() //main function
{

	readFile("/proc/uptime", "Uptime");                //calling readFile function to obtain Totaltime and Idletime 
	readFile("/proc/sys/kernel/hostname", "Hostname"); //calling readFile function to obtain hostname
	readFile("/proc/version", "Kernel Version");       //calling readFile function to obtain Kernel Version
	readFile("/proc/meminfo", "Memory");               //calling readFile function to obtain the amount of memory and free memory
	readFile("/proc/driver/rtc", "Time and Date");     //calling readFile function to obtain time and date

	return 0; //exit code
 
} //end main

void readFile(char *fileName, string file) //function to get general and time information
{
	
	ifstream infile; //ifstream constructor used to open the file
	infile.open(fileName); //open the file
	cout << file << " Information: \n"; //prints the file information heading
 
	string line, amount; //declaring variables 

	if(file=="Uptime") //if statement for uptime
	{
		infile >> amount;
		cout << "Uptime: " << amount  << "\n"; //print uptime
		infile >> amount;
		cout << "Idletime: " << amount  << "\n"; //print idletime
		cout << "\n"; // begin newline 
		return; //return the result
	}

	getline(infile,line); //getline overloader to get the information 
	cout << line; //print the line
	cout << "\n"; // begin a newline

	if(file == "Memory" || file  == "Time and Date") //if statment for memory and time and date
	{
		getline(infile,line); //getline overloader to get the infile info and read line of text into line.
		cout << line; //print the line
		cout << "\n"; //newline
	}

	infile.close(); //close the file
	cout << "\n"; //begin a newline

} //end readFile function 

