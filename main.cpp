#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
 #include <algorithm>
#include "Accident_log.cpp"
using namespace std;

void displayAccidentData(vector<Accident>&ACCIDENT)
{
    int wDate = 12, wDamage = 8, wCause = 25, wUnits = 6, wInjuries = 10, wMonths = 8, wSeverity = 10, wLocation = 12;

    cout << left
         << setw(wDate) << "DATE"
         << setw(wDamage) << "DAMAGE"
         << setw(wCause) << "CAUSE"
         << setw(wUnits) << "UNITS"
         << setw(wInjuries) << "INJURIES"
         << setw(wMonths) << "MONTHS"
         << setw(wSeverity) << "SEVERITY"
         << setw(wLocation) << "LOCATION"
         << "\n";

    cout << string(wDate + wDamage + wCause + wUnits + wInjuries + wMonths + wSeverity + wLocation, '-') << "\n";

    // Data
    for (const auto &a : ACCIDENT)
    {
        cout << left
             << setw(wDate) << a.crash_date
             << setw(wDamage) << a.damage
             << setw(wCause) << a.cause
             << setw(wUnits) << a.num_units
             << setw(wInjuries) << a.injuries
             << setw(wMonths) << a.crash_month
             << setw(wSeverity) << a.severity
             << setw(wLocation) << a.location
             << "\n";
    }
}

int calculateSeverity(const Accident &a) {
    int damageScore = 0;
    if (a.damage == "Low" || a.damage == "Minor")
        damageScore = 1;
    else if (a.damage == "Medium")
        damageScore = 2;
    else if (a.damage == "High")
        damageScore = 3;

    double severity = (damageScore * 0.4) +
                      (min(a.injuries, 5) * 0.4) +
                      (min(a.num_units, 5) * 0.2);

    int finalSeverity = (int)(severity + 0.5); // round to nearest
    if (finalSeverity < 1) finalSeverity = 1;
    if (finalSeverity > 5) finalSeverity = 5;

    return finalSeverity;
}

void addAccidentlog(vector<Accident>&ACCIDENT){
    Accident a;

    cout<<"\nEnter crash-date(DD-MM-YYY):";
    cin>>a.crash_date;
    cout<<"\nEnter damage:";
    cin>>a.damage;
    cin.ignore();
    cout<<"\nEnter cause:";
    getline(cin,a.cause);
    cout<<"\nEnter number of units involved:";
    cin>>a.num_units;
    cout<<"\nEnter number of injuries:";
    cin>>a.injuries;
    cout<<"\nEnter crash-month:";
    cin>>a.crash_month;
    
    cout<<"\nEnter crash location(caps):";
    cin>>a.location;

    a.severity = calculateSeverity(a);

    //insert record according to the decreasing order of severity 
    /*
    auto it = ACCIDENT.begin();
    while (it != ACCIDENT.end() && it->severity >= a.severity) {
        ++it;
    }
    ACCIDENT.insert(it, a);
    */
    
   ACCIDENT.push_back(a);
   cout<<"\n\t\t\tdata added successfully !! \n\n";
    

}

void sortAccordingToSeverity(){
       sort(ACCIDENT.begin(), ACCIDENT.end(), [](const Accident &x, const Accident &y) {
        return x.severity > y.severity; // descending order
    });

    cout<<"\n\t\t\t\t\tRecords sorted succesfully !";

}

void sortAccordingToLocation(){
       sort(ACCIDENT.begin(), ACCIDENT.end(), [](const Accident &x, const Accident &y) {
        return x.location < y.location; // descending order
    });

   

}

void BinarysearchByLocation(){
    string location;
    cout<<"enter location to be searched: ";
    cin>>location;
    sortAccordingToLocation();
     int wDate = 12, wDamage = 8, wCause = 25, wUnits = 6, wInjuries = 10, wMonths = 8, wSeverity = 10, wLocation = 12;

    cout << left
         << setw(wDate) << "DATE"
         << setw(wDamage) << "DAMAGE"
         << setw(wCause) << "CAUSE"
         << setw(wUnits) << "UNITS"
         << setw(wInjuries) << "INJURIES"
         << setw(wMonths) << "MONTHS"
         << setw(wSeverity) << "SEVERITY"
         << setw(wLocation) << "LOCATION"
         << "\n";

    cout << string(wDate + wDamage + wCause + wUnits + wInjuries + wMonths + wSeverity + wLocation, '-') << "\n";

    //lower bound return the iterator to tha value >= of the target value, so afte we get the iterator we need to check 
    //if the value is == location or
    
    auto it = lower_bound(ACCIDENT.begin(), ACCIDENT.end(), location,[](const Accident &a, const string &loc) {
        return a.location < loc;
    });

    if (it != ACCIDENT.end() && it->location == location){
        auto start = it;
        while(it != ACCIDENT.end() && it->location == location) {
            cout << left
             << setw(wDate) <<it->crash_date
             << setw(wDamage) <<it->damage
             << setw(wCause) <<it->cause
             << setw(wUnits) <<it->num_units
             << setw(wInjuries) <<it->injuries
             << setw(wMonths) <<it->crash_month
             << setw(wSeverity) <<it->severity
             << setw(wLocation) <<it->location
             << "\n";
                ++it;
}

    }else
        cout << "No accident found at this location.";

}


// Sort vector based on date
int dateToInt(const string &date) {
    if (date.size() != 10) return 0; // basic validation

    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));

    return year * 10000 + month * 100 + day;
}

void sortAccordingToDate(){
    
    sort(ACCIDENT.begin(), ACCIDENT.end(), [](const Accident &a, const Accident &b) {
        return dateToInt(a.crash_date) < dateToInt(b.crash_date);
    });
}

void BinarysearchByDate(){
    sortAccordingToDate();
    string targetDate;
    cout<<"Enter date to be searched: ";
    cin>>targetDate;

    int targetValue = dateToInt(targetDate);

    
    auto it = lower_bound(ACCIDENT.begin(), ACCIDENT.end(), targetValue,[](const Accident &a, int target) {
                              return dateToInt(a.crash_date) < target;
                          });



    // Display header
    int wDate = 12, wDamage = 8, wCause = 25, wUnits = 6, wInjuries = 10, wMonths = 8, wSeverity = 10, wLocation = 12;
    cout << left
         << setw(wDate) << "DATE"
         << setw(wDamage) << "DAMAGE"
         << setw(wCause) << "CAUSE"
         << setw(wUnits) << "UNITS"
         << setw(wInjuries) << "INJURIES"
         << setw(wMonths) << "MONTHS"
         << setw(wSeverity) << "SEVERITY"
         << setw(wLocation) << "LOCATION"
         << "\n";
    cout << string(wDate + wDamage + wCause + wUnits + wInjuries + wMonths + wSeverity + wLocation, '-') << "\n";


    // If not found
    if (it == ACCIDENT.end() || dateToInt(it->crash_date) != targetValue) {
        cout << "\nNo accidents found on " << targetDate << ".\n";
        return;
    }


    // Print all matching records
    while (it != ACCIDENT.end() && dateToInt(it->crash_date) == targetValue) {
        cout << left
             << setw(wDate) << it->crash_date
             << setw(wDamage) << it->damage
             << setw(wCause) << it->cause
             << setw(wUnits) << it->num_units
             << setw(wInjuries) << it->injuries
             << setw(wMonths) << it->crash_month
             << setw(wSeverity) << it->severity
             << setw(wLocation) << it->location
             << "\n";
        ++it;
    }
    


}



void displayTrend(const vector<int>& data, const vector<string>& labels, string title) {
    cout << "\n=== " << title << " ===\n";
    for (size_t i = 0; i < data.size(); ++i) {
        cout << labels[i] << " | ";
        for (int j = 0; j < data[i]; ++j)
            cout << '#';  // ASCII bar
        cout << " (" << data[i] << ")\n";
    }
    cout << "============================\n";
}

void showMonthlyTrend() {
    vector<int> countByMonth(12, 0);

    for (auto &a : ACCIDENT) {
        if (a.crash_month >= 1 && a.crash_month <= 12)
            countByMonth[a.crash_month - 1]++;
    }

    vector<string> months = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    displayTrend(countByMonth, months, "Accidents Per Month");
}
void showSeverityTrend() {
    vector<int> countBySeverity(5, 0);

    for (auto &a : ACCIDENT) {
        if (a.severity >= 1 && a.severity <= 5)
            countBySeverity[a.severity - 1]++;
    }

    vector<string> levels = {"1 (Minor)", "2 (Low)", "3 (Moderate)", "4 (High)", "5 (Fatal)"};
    displayTrend(countBySeverity, levels, "Accidents by Severity Level");
}

void accidentTrendChart(){
    cout << "\t\t\t1 to show monthly trends" << endl;
    cout << "\t\t\t2 to show severity trends" << endl;
    int choice;
    cout << "\t\t\tenter you choice: ";
    cin >> choice;
       
    switch (choice)
    {
    case 1:
        showMonthlyTrend();
        break;
    case 2:
        showSeverityTrend();
        break;
    default:
        cout<<"Try again!";
    }
}


int main()
{

    bool check = true;
    readfromCSV(ACCIDENT, "accidents.csv");
    cout << "\t\t\t\t\t\tTraffic Accident Data Analyzer!" << endl;
    while (check)

    {   
        cout<<"\n"<<string(130,'*')<<"\n\n";
        cout << "\t\t\t\t\t\tWelcome to the project !" << endl;
        cout<<"\t\t\t\t\t\t"<<string(24,'-')<<'\n';
        cout << "\n\t\t\t1 to add a new accident log" << endl;
        cout << "\n\t\t\t2 to display all accident log" << endl;
        cout << "\n\t\t\t3 to sort logs based on severity " << endl;
        cout << "\n\t\t\t4 to search a record by date" << endl;
        cout << "\n\t\t\t5 to search a log by location" << endl;
        cout << "\n\t\t\t6 to get accident trend chart" << endl;
        cout << "\n\t\t\t7 to exit" << endl;
        int choice;
        cout << "\n\t\t\tenter you choice: ";
        cin >> choice;
       
        switch (choice)
        {
        case 1:
            addAccidentlog(ACCIDENT);
            break;
        case 2:
            displayAccidentData(ACCIDENT);
            break;
        case 3:
        sortAccordingToSeverity();
        break;

        case 4:
        BinarysearchByDate();
        break;

        case 5:
        BinarysearchByLocation();
        break;

        case 6:
        accidentTrendChart();
        break;
        case 7:
            check = false;
            break;
        default:
        cout<<"Incorrect choice, Try again !";
        }
        
    }
    return 0;
}