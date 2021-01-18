#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <chrono>
#include <random>
#include <algorithm> 
#include <fstream>
#include <iomanip>  

using namespace std;
using namespace std::chrono;
class QSort
{
public:
    
    int a[100];
    int n = sizeof(a) / sizeof(*a);
    long long int counter = 0;
    long long int comp = 0;
    int b, suma = 0,suma2 = 0;
    unsigned int seed;
    int temp;
    int x;
    QSort()
    {
        x = 0;
    }
    void RArray(int b, int a[], int n, long long int& comp, int w)
    {
        int temp;
        cout << "Pries:" << endl;
        for (int i = 0; i < n; i++)
        {
            
            seed = steady_clock::now().time_since_epoch().count();
            default_random_engine engine(seed);
            uniform_int_distribution<int> distr(1000, 9999);
            b = distr(engine);
            a[i] = b;
            cout << a[i] << " ";

        }
        cout << endl;
        auto start = high_resolution_clock::now();
        quickSort(a, 0, n - 1,counter,comp);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Kiek uztruko: " << endl;
        cout << (double)duration.count() / 1000 << endl;
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    int median3(int a[], int left, int right, long long int& counter, long long int &comp)//Uses median of three partitioning technique
    {
        int center = (left + right) / 2;
        if (a[center] < a[left])
        {

            comp++;
            swap(&a[left], &a[center], counter);
        }
        if (a[right] < a[left])
        {
            comp++;
           swap(&a[left], &a[right], counter);
        }
        if (a[right] < a[center])
        {
          comp++;
          swap(&a[center], &a[right], counter);
        }
        swap(&a[center], &a[right - 1], counter);//since the largest is already in the right.
        return a[right - 1];
    }
    void swap(int* x, int* y, long long int &counter)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
        counter++;
        return;
    }
    int partition(int arr[], int low, int high, long long int &counter, long long int &comp)
    {
        int pivot = arr[low];
           // median3(arr, low, high, counter, comp);
        int p1 = low + 1, i, temp;
        for (i = low + 1; i <= high; i++)
        {
            comp++;
            if (arr[i] < pivot)
            {
                if (i != p1)
                {
                    temp = arr[p1];
                    arr[p1] = arr[i];
                    arr[i] = temp;
                    counter++;
                }    p1++;
            }
        }
        arr[low] = arr[p1 - 1];
        arr[p1 - 1] = pivot;
        counter++;
        return p1 - 1;
    }
    /* The main function that implements QuickSort
    arr[] --> Array to be sorted,
    low --> Starting index,
    high --> Ending index */
    void quickSort(int arr[], int low, int high, long long int &counter, long long int &comp)
    {
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now
            at right place */
            int pi = partition(arr, low, high,counter,comp);

            // Separately sort elements before  
            // partition and after partition  
            quickSort(arr, low, pi - 1,counter,comp);
            quickSort(arr, pi + 1, high,counter,comp);
        }
    }
    bool MainMenu()
    {
       
        int choose;
        cout << "Pasirinkite:" << endl;
        cout << "1) Quicksort" << endl;
        cout << "2) Iseiti" << endl;
        cin >> choose;
        switch (choose)
        {
        case 1:
            
            for (int i = 0; i < 5; i++)
            {
                cout << "Bandymas Nr - " << i + 1 << endl;
                RArray(b, a, 100, comp, 1);
                cout << "Palyginimu sk: " << " - " << comp << endl;
                cout << "Sukeitimu sk:" << " - " << counter << endl;
                suma = suma + comp;
                suma2 = suma2 + counter;
                comp = 0;
                counter = 0;
            }
            cout << "Palyginimu vidurkis - " << suma/5 << endl;
            cout << "Sukeitimu vidurkis - " << suma2/5 << endl;
          
            
            return true;
        case 2:
            return false;
        default:
            return true;
        }
    }
    ~QSort()
    {
    }
};
int main()
{
    
    QSort obj;
    bool showMenu = true;
    while (showMenu)
    {
        showMenu = obj.MainMenu();
    }
    return 0;
}