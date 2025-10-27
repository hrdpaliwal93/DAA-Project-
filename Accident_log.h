#ifndef Accident_log_h
#define Accident_log_h

#include<vector>
#include <sstream>
#include <fstream>
#include<string>

using namespace std;

struct Accident
{
    string crash_date;
    string damage;
    string cause;
    int num_units;
    int injuries;
    int crash_month;
    int severity;
    string location;
};
    extern vector<Accident>ACCIDENT;
    void readfromCSV(vector<Accident> &ACCIDENT, string filename);



#endif

