#include<bits/stdc++.h>
using namespace std; 

struct Item {
    int value, weight;
};

bool cmp(Item a, Item b){
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;

    return r1 > r2;
}

double fractionKnap(int capacity, vector<Item> items){

    sort(items.begin(), items.end(), cmp);
    
    double totalValue = 0.0;

    for(auto &it : items){
        if(capacity >= it.weight){
            capacity -= it.weight;
            totalValue += it.value;
        }else{
            double fraction = (double)capacity/it.weight;
            totalValue += it.value * fraction;
            break;
        }
    }
    return totalValue;
}

int main(){
    int n, capacity;
    cout<<"Enter number of items: ";
    cin>>n;

    vector<Item> items(n);
    cout<<"Enter value and weight of each item:\n";
    for(int i = 0; i<n; i++)
        cin>> items[i].value >> items[i].weight;

    cout<<"Enter knapsack capacity: ";
    cin>>capacity;

    cout<<"Maximum value: "<< fractionKnap(capacity, items);
    return 0;
}

// Enter number of items: 3
// Enter value and weight of each item:
// 60 10
// 30 40
// 120 50
// Enter knapsack capacity: 50
// Maximum value: 156