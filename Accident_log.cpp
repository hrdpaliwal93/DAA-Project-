#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include<string>
#include "Accident_log.h"
using namespace std;

vector<Accident>ACCIDENT;

void readfromCSV(vector<Accident> &ACCIDENT, string filename)
{
    ifstream file(filename);
    if (!file.is_open()){
        cout << "Error in opening file" << filename<<endl; return ;}
    string line;
    getline(file, line); //by default delimiter is a new line 
    //take stream -> store the stream --> move to next stream 
    Accident a;

    while (getline(file, line))
    {
        stringstream ss(line);
        string temp;

        getline(ss, a.crash_date, ',');
        getline(ss, a.damage, ',');
        getline(ss, a.cause, ',');

        getline(ss, temp, ',');
        a.num_units = stoi(temp);
        getline(ss, temp, ',');
        a.injuries = stoi(temp);
        getline(ss, temp, ',');
        a.crash_month = stoi(temp);
        getline(ss, temp, ',');
        a.severity = stoi(temp);
        getline(ss, a.location, ',');

         ACCIDENT.push_back(a);
    }

   
}

