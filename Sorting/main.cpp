#include <iostream>

void bubbleSort(int arr[], int length)
{
    if (length <= 1)
        return;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertSort(int arr[], int length)
{
    if (length <= 1)
        return;
        
    for (int i = 1; i < length; i++)
    {
        // must compare starting from the last/newest one
        for (int j = i; j > 0; j--) 
        {
            if(arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

void quickSort(int arr[], int low, int high)
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
    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}

int main ()
{
    int arr[10]{2, 3, 10, 1, 4, 7, 6, 9, 8, 5};

    // cannot be called inside a function to return the length
    // array as parameter is a reference which means it is an integer long
    // it has to be calc in the area where it is defined
    int len = (int)sizeof(arr) / sizeof(arr[0]);

    // quickSort(arr, 0, len(arr) - 1);
    // bubbleSort(arr, len);
    insertSort(arr, len);

    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
}