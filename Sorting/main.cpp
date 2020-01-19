#include <iostream>

template <class T> int len(T& arr)
{
    return (int)sizeof(arr) / sizeof(arr[0]);
}

void sort(int arr[], int low, int high)
{
    if ((high - low) <= 0)
    {
        return;
    }

    int i = low;
    int j = high;
    int marker = arr[high];

    while (i < j)
    {
        while (arr[i] <= marker && i < j) i++;
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        while (arr[j] >= marker && i < j) j--;
        if (i < j)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    sort(arr, low, i - 1);
    sort(arr, i + 1, high);
}

int main ()
{
    int arr[10]{2, 3, 10, 1, 4, 7, 6, 9, 8, 5};
    sort(arr, 0, len(arr) - 1);
    for (int i = 0; i < len(arr); i++)
    {
        std::cout << arr[i] << " ";
    }
}