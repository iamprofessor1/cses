// FFFFFFFFFF  TTTTTTTTTTTTTT
#include <bits/stdc++.h>
using namespace std;

// Time Complexity - > O(n(log(sum - mx)))=> O(n(log(sum)))
// if sum is not so high then use this
// otherwise use dp based solution
// Kaam cut ko baadne hai

// Maximum is small as possible
// ****** maximum of minimum ****/
// minimise the maximum sum 
// FFFF TTTTTTTTT
//  first true is answer
bool isfeasible(int arr[], int n, int k, int target)
{
    int req = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] > target)
        {
            req++;
            sum = arr[i];
        }
        else
        {
            sum += arr[i];
        }
    }
    return req <= k;
}
int allocate_minimum_number_of_pages(int arr[], int n, int k)
{
    int sum = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        mx = max(mx, arr[i]);
    }
    // low -> minium possible answer  jab sab baache akele akele padenge
    // high -> ek hi baaccha agar saare paage paadhe liye toh
    int low = mx, high = sum;
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // finding middle possible value

        // check karne agar itni max value liye toh kitne part mein divide hoga
        // agar kaam part mein huya toh target ko ghaatne ki kossis karnge
        // aur ghaatete kisko high ko
        // lekin save in possible answer
        // 3 se hmm logo 2 part mein nhi puch sakte
        // 2 se 3 part mein hum pahuch sakte by decreasing the value of high alteratively mid
        //  jab mid kaam toh jaade part mein divide kar paayenge

        if (isfeasible(arr, n, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {2, 4, 7, 3, 5};
    int n = sizeof(arr) / sizeof(n);
    cout << allocate_minimum_number_of_pages(arr, n, 3);
    return 0;
}
