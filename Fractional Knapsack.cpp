#include<bits/stdc++.h>
using namespace std;

float fractional_knapsack(int n,int c,int weight[],int profit[]){
    int ratio[n],i,j;
    float total_profit = 0;
    for(i=0; i<n; i++){
        ratio[i] = (float)profit[i]/weight[i];
    }
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(ratio[i]<ratio[j]){
                swap(ratio[i],ratio[j]);
                swap(weight[i],weight[j]);
                swap(profit[i],profit[j]);
            }
        }
    }

    for(i=0; i<n && c!=0; i++){
        if(weight[i] <= c){
            c -= weight[i];
            total_profit += profit[i];
        }
        else{
            total_profit += (c * profit[i])/(float)weight[i] ;
            c = 0;
        }

    }
    return total_profit;
}

int main(){
    int c,n,i;
    cout<<"Enter number of items:";
    cin>>n;
    cout<<"Enter capacity of knapsack:";
    cin>>c;
    int profit[n],weight[n];
    for(i=0; i<n; i++){
        cout<<"Enter weight of item no "<<i+1<<":";
        cin>>weight[i];
        cout<<"Enter profit of item no "<<i+1<<":";
        cin>>profit[i];
    }
    cout<<"Maximum profit is: "<<fractional_knapsack(n,c,weight,profit);
}

/*
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<float, int>& a, pair<float, int>& b) {
    return a.first > b.first;
}

float fractional_knapsack(int n, int c, int weight[], int profit[]) {
    vector<pair<float, int>> ratio; // Using pair for keeping track of ratio and item index
    for (int i = 0; i < n; i++) {
        ratio.push_back({ (float)profit[i] / weight[i], i });
    }

    sort(ratio.begin(), ratio.end(), compare); // Sorting in non-increasing order of ratios

    float total_profit = 0;
    for (int i = 0; i < n && c > 0; i++) {
        int index = ratio[i].second; // Accessing original index of item
        if (weight[index] <= c) {
            total_profit += profit[index];
            c -= weight[index];
        }
        else {
            total_profit += (c / (float)weight[index]) * profit[index];
            c = 0;
        }
    }
    return total_profit;
}

int main() {
    int c, n, i;
    cout << "Enter number of items:";
    cin >> n;
    cout << "Enter capacity of knapsack:";
    cin >> c;
    int profit[n], weight[n];
    for (i = 0; i < n; i++) {
        cout << "Enter weight of item no " << i + 1 << ":";
        cin >> weight[i];
        cout << "Enter profit of item no " << i + 1 << ":";
        cin >> profit[i];
    }
    cout << "Maximum profit is: " << fractional_knapsack(n, c, weight, profit);
}

*/