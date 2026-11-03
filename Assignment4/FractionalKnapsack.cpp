#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Commodity
{
    string name;
    double quantity;
    double value;
    double ratio;
    char divisible;   
};

int main()
{
    int n;
    cin >> n;

    vector<Commodity> commodities(n);

    for(int i = 0; i < n; i++)
    {
        cin >> commodities[i].name;
        cin >> commodities[i].quantity;
        cin >> commodities[i].value;
        cin >> commodities[i].divisible;

        commodities[i].ratio =
            commodities[i].value / commodities[i].quantity;
    }

    double capacity;
    cin >> capacity;

    sort(commodities.begin(), commodities.end(),
         [](Commodity a, Commodity b)
         {
             return a.ratio > b.ratio;
         });

    double totalValue = 0;

    for(int i = 0; i < n; i++)
    {
        if(capacity == 0)
            break;

        if(commodities[i].divisible == 'D')
        {
            if(commodities[i].quantity <= capacity)
            {
                capacity -= commodities[i].quantity;
                totalValue += commodities[i].value;

                cout << "Taking 100% of "
                     << commodities[i].name << endl;
            }
            else
            {
                double fraction =
                    capacity / commodities[i].quantity;

                double takenQuantity = capacity;

                double gainedValue =
                    takenQuantity * commodities[i].ratio;

                totalValue += gainedValue;

                cout << "Taking "
                     << fraction * 100 << "% of "
                     << commodities[i].name << endl;

                capacity = 0;
            }
        }

        else
        {
            if(commodities[i].quantity <= capacity)
            {
                capacity -= commodities[i].quantity;
                totalValue += commodities[i].value;

                cout << "Taking 100% of "
                     << commodities[i].name
                     << " (Indivisible)" << endl;
            }
            else
            {
                cout << "Skipping "
                     << commodities[i].name
                     << " (Indivisible - not enough space)"
                     << endl;
            }
        }
    }

    cout << "\nMaximum Total Value = "
         << totalValue << endl;

    cout << "Remaining Capacity = "
         << capacity << " tons" << endl;

    return 0;
}