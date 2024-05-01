#include <bits/stdc++.h>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

void printJobSequence(Job job[], int n) {
    int i,j,total_profit=0;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(job[i].profit < job[j].profit){
                swap(job[i].id,job[j].id);
                swap(job[i].profit,job[j].profit);
                swap(job[i].deadline,job[j].deadline);
            }
        }
    }
    int schedule[n];
    bool slot[n];

    for (i = 0; i < n; i++){
        slot[i] = false;
    }
        
    for (i = 0; i < n; i++) {
        for (j = min(n, job[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                schedule[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    cout << "Job Sequence: ";
    for (i = 0; i < n; i++) {
        if (slot[i]){
            cout << job[schedule[i]].id << " ";
            total_profit += job[schedule[i]].profit;
        }
    }
    cout<<endl;
    cout << "Total Profit: "<<total_profit<<endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    
    Job job[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Enter job ID, deadline, and profit for each job no:" <<i+1<< endl;
        cin >> job[i].id;
        cin >> job[i].deadline;
        cin >> job[i].profit;
    }

    printJobSequence(job, n);

    return 0;
}
