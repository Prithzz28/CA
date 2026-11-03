#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
    string id;
    int deadline;
    int payout;
};

int main()
{
    int n;
    cin >> n;

    vector<Job> jobs(n);

    for(int i = 0; i < n; i++)
    {
        cin >> jobs[i].id;
        cin >> jobs[i].deadline;
        cin >> jobs[i].payout;
    }

    int slots;
    cin >> slots;

    sort(jobs.begin(), jobs.end(), [](Job a, Job b)
    {
        return a.payout > b.payout;
    });

    vector<string> slot(slots + 1, "");

    int totalPayout = 0;

    for(int i = 0; i < n; i++)
    {
        int lastSlot = min(jobs[i].deadline, slots);

        for(int j = lastSlot; j >= 1; j--)
        {
            if(slot[j] == "")
            {
                slot[j] = jobs[i].id;
                totalPayout += jobs[i].payout;
                break;
            }
        }
    }

    cout << "Scheduled Jobs:" << endl;

    for(int i = 1; i <= slots; i++)
    {
        if(slot[i] != "")
        {
            cout << "Day " << i << " : " << slot[i] << endl;
        }
        else
        {
            cout << "Day " << i << " : Empty" << endl;
        }
    }

    cout << "Maximum Total Payout = " << totalPayout << endl;

    return 0;
}