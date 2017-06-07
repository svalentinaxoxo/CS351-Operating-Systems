/*********************************************************************************************
*Shelby Laquitara
*03/05/2017
*linuxtime.cpp
*
* This program displays time information about the system. 
*********************************************************************************************/
#include <iostream>  //contains prototypes for standard input and output functions
#include <fstream>   //contains function prototypes that perform input from files and output to files
#include <string>    //contains definition of string class
#include <iomanip>   //stream manipulators that format streams of data
#include <math.h>    //math functions
#include <unistd.h>  //null pointer definition 
#include <stdio.h>   // print f, null
#include <stdlib.h>  // used for strtod

using namespace std;

void readFile(double* about);                       //function prototype for getTime 
void work();                                       //funtion prototype for work 
void calcTime(double* startTime, double* endTime); //function prototype for calcTime 

int main(void) //main method 
{
	cout.setf(ios::fixed);		//allows floating point number without extra 0's
	cout.setf(ios::showpoint);	//shows the decimal point
	cout.precision(2);		//sets the precision

	cout << "\nHere is the begining totaltime and begining Idletime: " << endl; //prints out the sentence 
	double sTime[2];		//array for start time 
	readFile(sTime);		//used to get the start time

	work();	//calling the work function 

	cout << "\nHere is the ending totaltime and ending Idletime: " << endl;	//prints out the sentence
	double eTime[2];		//array for the end time 
	readFile(eTime);		//used to get the end time
	
	cout <<"\nHere are the results of the calculations: " << endl;
        calcTime(sTime, eTime);	 	//calling the calcTime function with starttime and endtime parameters
} // end main

void readFile(double* about) //function that reads time from /proc/uptime
{
	ifstream utime ("/proc/uptime");	 		//opens the /proc/uptime file 
	char ubuffer[22];					//character buffer
	char* pEnd;						//converts string to double
	string file, upTime, idleTime;  			//declaring variables

	utime.getline(ubuffer, 22);				//gets the uptime
	utime.close();						//closes the Uptime file 

	file = ubuffer;						//gets the file as a string
	upTime = file.substr(0,file.find_first_of(" ",0));	//gets the uptime
	idleTime = file.erase(0,file.find_first_of(" ",0));	//gets the idletime

	about[0] = strtod(upTime.c_str(),&pEnd);		//converts string for uptime
	about[1] = strtod(idleTime.c_str(),&pEnd);		//converts string idletime

	cout << "totaltime = " << upTime << endl;		//prints the uptime
	cout << "idletime = " << idleTime << endl;		//prints the idletime
} //end getTime function

void work() //function to do some work function provided 
{
	double i, j, e;		//declaring variable i and j					
	double x = 3.0;		//declaring variable x and setting it to 3.0
	double y = 2.0;		//declaring variable y and setting it to 2.0
	
	cout <<"\nPutting some work into the system: " << endl;	//prints the sentence 

	for (i = 0; i < 5; i++)			//for loop for i 
	{
		for (j = 0; j < 400000; j++)	//for loop for j
		{
			e = pow(x, y);		//math function for powers, x raised to the power of y 
		} //end inner for loop

		cout << "Loop of work cycle " << i << "\n"; //prints the loop of work for i 
		sleep(1);
	} //end for loop
} // end work funtion 

void calcTime(double* startTime, double* endTime) //function to calculate and print time
{
	//declaring variables and assigning them to calculations
	double programTotalTime = (endTime[0] - startTime[0]); 		//calculating the total run time 
	double programIdleTime = (endTime[1] - startTime[1]);		//calculating the total idle time 	
	double programWorkTime = (programTotalTime - programIdleTime);	//calculating the total CPU work time
	double percentage = (programWorkTime/programTotalTime)*100;	//calculating the percentage of CPU usage

	cout << "The Program total run time = " << programTotalTime << endl;	 //prints the total run time
	cout << "The Program idle time = " << programIdleTime << endl;		 //prints the total Idle time
	cout << "The total program working time  = " << programWorkTime << endl; //prints the total CPU work time
	//prints the percentage of CPU usage
	cout << "The total Percentage of time that the CPU was busy = " << percentage << "%" <<  endl; 
} //end calcTime function
 
