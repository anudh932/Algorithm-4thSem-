#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int profit;  // Changed from value to profit for consistency
    int weight;
    double ratio; // Added ratio member to store profit-to-weight ratio
};

// Comparison function to sort items by their value-to-weight ratio
bool cmp(Item a, Item b)
{
    return a.ratio > b.ratio; // Sort in descending order
}

double frac_knapsack(vector<Item>& items, int capacity)
{
    // Calculate the profit-to-weight ratio for each item
    for(int i = 0; i < items.size(); i++)
    {
        items[i].ratio = (double)items[i].profit / items[i].weight; // Ensure floating-point division
    }

    // Sort items based on the ratio
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;
    int currentWeight = 0;

    // Iterate through the sorted items
    for(int i = 0; i < items.size(); i++)
    {
        if(currentWeight + items[i].weight <= capacity)
        {
            currentWeight += items[i].weight;
            totalValue += items[i].profit; // Use profit instead of value
        }
        else
        {
            int rem_capacity = capacity - currentWeight;
            totalValue += items[i].profit * ((double)rem_capacity / items[i].weight); // Fraction of the item
            break; // Exit the loop as the knapsack is full
        }
    }
    return totalValue; // Return the total value of the knapsack
}

int main()
{
    int n, capacity;
    cin >> n; // Number of items
    cin >> capacity; // Capacity of the knapsack

    vector<Item> items(n);
    for(int i = 0; i < n; i++)
    {
        cin >> items[i].profit >> items[i].weight; // Input profit and weight
    }

    cout << frac_knapsack(items, capacity); // Output the maximum value
    return 0;
}
