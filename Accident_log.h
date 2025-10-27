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

/*
28-01-2023,High,Distracted driving,4,5,1,4,Mumbai
30-12-2023,Low,Distracted driving,3,1,12,1,Kolkata
26-06-2024,High,Drunk driving,2,3,6,2,Bangalore
16-04-2023,Medium,Drunk driving,2,1,4,4,Jaipur
16-01-2022,Low,Signal jumping,3,0,1,3,Mumbai
23-03-2024,Low,Rainy road,1,1,3,3,Chennai
22-03-2022,Low,Distracted driving,1,3,3,2,Jaipur
01-05-2024,High,Over-speeding,3,4,5,3,Chennai
28-05-2023,Medium,Distracted driving,1,0,5,3,Chennai
12-08-2023,Medium,Rainy road,1,1,8,3,Mumbai
27-07-2023,Low,Distracted driving,3,2,7,4,Delhi
17-10-2024,Low,Drunk driving,4,2,10,2,Bangalore
21-01-2023,Low,Distracted driving,1,1,1,3,Hyderabad
09-10-2023,High,Rainy road,4,0,10,4,Pune
17-01-2023,Medium,Over-speeding,2,4,1,1,Mumbai
27-10-2023,Medium,Rainy road,4,0,10,3,Bangalore
01-01-2022,High,Reckless overtaking,2,5,1,5,Chennai
27-03-2022,Medium,Rainy road,1,1,3,4,Jaipur
30-05-2022,High,Distracted driving,4,1,5,3,Jaipur
04-02-2024,High,Rainy road,3,4,2,2,Kolkata
08-06-2023,Low,Distracted driving,4,2,6,4,Mumbai
30-03-2023,Medium,Over-speeding,4,1,3,4,Bangalore
01-08-2023,High,Reckless overtaking,4,5,8,4,Jaipur
07-11-2024,High,Distracted driving,1,5,11,4,Pune
08-06-2022,Medium,Signal jumping,2,4,6,2,Bangalore
01-09-2024,Low,Distracted driving,2,2,9,4,Bangalore
02-04-2022,Medium,Signal jumping,3,0,4,1,Mumbai
07-12-2023,Low,Reckless overtaking,1,4,12,2,Mumbai
11-03-2023,Medium,Distracted driving,2,3,3,2,Pune
03-01-2024,Medium,Rainy road,1,4,1,2,Hyderabad
31-03-2022,Medium,Signal jumping,3,2,3,4,Delhi
11-04-2023,High,Reckless overtaking,4,4,4,1,Delhi
16-03-2022,Medium,Reckless overtaking,2,5,3,2,Bangalore
25-08-2024,High,Drunk driving,2,2,8,5,Jaipur
04-03-2023,Medium,Distracted driving,1,4,3,4,Pune
23-12-2024,Medium,Drunk driving,3,4,12,2,Mumbai
15-05-2023,High,Reckless overtaking,2,3,5,1,Pune
08-06-2022,Low,Signal jumping,4,3,6,2,Mumbai
31-07-2023,Medium,Over-speeding,4,5,7,3,Bangalore
29-08-2022,Low,Distracted driving,1,3,8,1,Pune
30-01-2023,Medium,Drunk driving,4,4,1,1,Jaipur
22-11-2024,High,Signal jumping,3,4,11,5,Delhi
16-07-2024,High,Distracted driving,1,3,7,2,Bangalore
19-05-2024,High,Over-speeding,1,4,5,2,Hyderabad
27-07-2022,Low,Signal jumping,3,5,7,1,Mumbai
02-02-2022,High,Signal jumping,4,2,2,3,Mumbai
14-10-2023,High,Signal jumping,2,2,10,5,Kolkata
23-10-2023,Low,Over-speeding,1,1,10,3,Jaipur
12-09-2022,Medium,Reckless overtaking,4,0,9,2,Kolkata
17-04-2022,Medium,Rainy road,3,0,4,2,Jaipur
21-01-2024,High,Over-speeding,2,4,1,4,Mumbai
06-10-2023,High,Distracted driving,2,3,10,1,Mumbai
16-08-2023,High,Distracted driving,3,2,8,5,Bangalore
07-09-2024,High,Reckless overtaking,2,5,9,4,Mumbai
03-08-2022,High,Reckless overtaking,2,4,8,4,Delhi
31-03-2024,Low,Distracted driving,4,4,3,2,Kolkata
04-11-2024,High,Distracted driving,2,2,11,3,Pune
19-04-2024,High,Reckless overtaking,4,4,4,4,Delhi
17-06-2022,High,Signal jumping,1,2,6,5,Mumbai
28-08-2024,Low,Drunk driving,2,3,8,4,Jaipur
01-02-2024,Low,Over-speeding,3,4,2,5,Hyderabad
21-01-2023,Medium,Distracted driving,3,2,1,3,Delhi
11-05-2024,Low,Over-speeding,3,4,5,4,Jaipur
12-06-2024,Low,Over-speeding,3,0,6,5,Pune
13-04-2024,Medium,Drunk driving,2,1,4,5,Mumbai
16-09-2022,High,Rainy road,3,1,9,2,Mumbai
15-06-2022,High,Drunk driving,2,1,6,5,Chennai
12-03-2022,Low,Rainy road,3,5,3,3,Hyderabad
10-11-2024,Low,Over-speeding,3,5,11,4,Hyderabad
06-03-2024,Medium,Drunk driving,2,5,3,3,Jaipur
26-01-2022,High,Over-speeding,1,4,1,4,Chennai
07-01-2022,High,Reckless overtaking,2,1,1,1,Bangalore
22-04-2023,Low,Distracted driving,4,3,4,2,Kolkata
06-01-2023,Low,Over-speeding,1,1,1,1,Delhi
04-05-2023,Low,Reckless overtaking,1,5,5,1,Delhi
25-07-2022,Low,Over-speeding,4,2,7,5,Delhi
14-01-2023,Low,Reckless overtaking,4,2,1,3,Chennai
02-07-2023,Low,Over-speeding,4,4,7,5,Hyderabad
12-12-2024,Medium,Rainy road,2,1,12,1,Pune
05-04-2024,Medium,Reckless overtaking,4,0,4,3,Delhi
24-05-2023,Low,Rainy road,2,3,5,4,Delhi
24-04-2022,High,Signal jumping,4,4,4,1,Hyderabad
14-11-2023,Low,Distracted driving,2,5,11,5,Mumbai
25-06-2024,High,Signal jumping,2,4,6,4,Delhi
26-12-2023,Low,Rainy road,3,2,12,2,Kolkata
31-05-2023,High,Rainy road,4,2,5,5,Pune
17-12-2024,Low,Signal jumping,4,1,12,3,Hyderabad
07-07-2022,High,Drunk driving,3,4,7,3,Pune
30-03-2024,Low,Drunk driving,4,2,3,2,Jaipur
12-12-2024,Medium,Reckless overtaking,4,4,12,5,Mumbai
29-12-2022,High,Distracted driving,1,1,12,5,Delhi

*/