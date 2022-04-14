#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[50+1], b[50+1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    int step = 0;
    int max = 0;
    int lastDelta = 0;

    for (int i=1; i <= n ; i++)
    {
        int delta = b[i] - a[i];

        if (delta == 0 && lastDelta == 0)
            continue;

        if (lastDelta == 0)
        {
            lastDelta = delta / abs(delta);
            max = abs(delta);
            continue;
        }

        if (delta == 0)
        {
            step = step + max;
            max = abs(delta);
            lastDelta = 0;
        }
        else
        {
            if ( (lastDelta*delta) < 0 )
            {
                step = step + max;
                lastDelta =  delta/abs(delta);
                max = abs(delta);
            }
            else
            {
                if ( abs(delta) > max)
                {
                    max = abs(delta);
                }
            }
        }


    }

    if (max != 0)
        step = step + max;

    cout << step;


    return 0;
}
