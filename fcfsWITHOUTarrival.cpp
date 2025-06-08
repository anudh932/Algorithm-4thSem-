#include <iostream>
#include <iomanip> // For formatted output

using namespace std;

int main() {

    // Variables declaration
    int n;                      // Number of processes
    int burst_time[20];         // Array to store burst time of each process
    int waiting_time[20];       // Array to store waiting time of each process
    int turnaround_time[20];    // Array to store turnaround time of each process
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // Get the number of processes from the user
    cout << "\nEnter the number of processes (maximum 20): ";
    cin >> n;

    // Input validation
    if (n <= 0 || n > 20) {
        cout << "Invalid number of processes. Please enter a value between 1 and 20." << endl;
        return 1;
    }

    // Get burst time for each process
    cout << "\nEnter the Burst Time for each process:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Process P" << i + 1 << ": ";
        cin >> burst_time[i];

        // Input validation for burst time
        if (burst_time[i] <= 0) {
            cout << "Burst time must be a positive integer. Please restart the program." << endl;
            return 1;
        }
    }

    // Calculate waiting time for each process
    waiting_time[0] = 0;    // First process has 0 waiting time

    for (int i = 1; i < n; i++) {
        waiting_time[i] = 0;
        // Add burst times of all previous processes
        for (int j = 0; j < i; j++) {
            waiting_time[i] += burst_time[j];
        }
    }

    // Calculate turnaround time for each process and total times
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    cout << "----------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];

        cout << "P" << i + 1 << "\t" << burst_time[i] << "\t\t"
             << waiting_time[i] << "\t\t" << turnaround_time[i] << endl;
    }

    return 0;
}
