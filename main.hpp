#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int writeFile(const string& filename) {
    ofstream ofs(filename);
    if (!ofs) {
        cout << "File Open Error\n";
        exit(0);
    }

    int N;
    cout << "Enter Number of Employees: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        int ID;
        string name;
        string department;
        double salary;

        cout << "\nEntering details for Employee " << (i + 1) << endl;

        cout << "Enter Employee ID: ";
        cin >> ID;

        cin.ignore();

        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Department Name: ";
        getline(cin, department);

        cout << "Enter Salary: ";
        cin >> salary;

        ofs << ID << "\t" << name << "\t" << department << "\t" << salary << "\n";
    }

    cout << "Employee record written to " << filename << endl;
    ofs.close();
    return N;
}

int readFile(const string& filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cout << "File Open Error\n";
        return 0;
    }

    int count = 0;
    string line;
    cout << "\nEmployee Records:\n";
    while (getline(ifs, line)) {
        cout << line << endl;
        count++;
    }

    ifs.close();
    return count;
}
