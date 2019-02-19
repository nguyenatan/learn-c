#include <bits/stdc++.h>

using namespace std;

struct point {
    int value;
    double x, y;
    double distance;
};

int kNearestNeighbor(point arr[], int n, int k, point p)
{
    for (int i = 0; i < n; ++i)
        arr[i].distance = sqrt(pow(arr[i].x-p.x, 2) + pow(arr[i].y-p.y, 2));

    for (int i = 0; i < n-1; ++i)
        for (int j = i+1; j < n; ++j) {
            if (arr[i].distance > arr[j].distance)
                swap(arr[i], arr[j]);
        }

    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < k; ++i) {
        if (arr[i].value == 0)
            ++count1;
        else
            ++count2;
    }

    if (count1 > count2) return 0;

    return 1;
}

int main()
{
    int n = 6;
    point arr[n];

    arr[0].value = 0;
    arr[0].x = 1;
    arr[0].y = 2;

    arr[1].value = 1;
    arr[1].x = 2;
    arr[1].y = 1;

    arr[2].value = 0;
    arr[2].x = 3;
    arr[2].y = 2;

    arr[3].value = 1;
    arr[3].x = 2;
    arr[3].y = 3;

    arr[4].value = 0;
    arr[4].x = 3;
    arr[4].y = 4;

    arr[5].value = 1;
    arr[5].x = 4;
    arr[5].y = 3;

    point p;
    p.x = 1;
    p.y = 1;

    int result = kNearestNeighbor(arr, n, 3, p);
    cout << result << endl;

    return 0;
}
