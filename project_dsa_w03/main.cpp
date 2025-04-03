#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
void heapify(int* a, int n, int i)
{
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left<n && a[left]>a[max])
    {
        max = left;
    }
    if (right<n && a[right]>a[max])
    {
        max = right;
    }
    if (max != i)
    {
        swap(a[i], a[max]);
        heapify(a, n, max);
    }

}
void heapsort(int* a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
void insertionsort(int* a, int n) {
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void selectionsort(int* a, int n){
    for (int i=0; i<n-1; i++)
    {
        int min=i;
        for (int j=i+1; j<n; j++)
        {
            if (a[j]<a[min])
            min=j;
        }
        swap(a[i], a[min]);
    }
}

void bubblesort(int* a, int n){
    for (int i=1; i<n; i++)
    {
        for (int j=n-1; j>=i; j--)
        {
            if (a[j-1]>a[j])
            swap(a[j-1],a[j]);
        }
    }
}

void read_input_file(int* &a, int &n,const char *name){
    FILE* f;
    fopen_s(&f, name, "r");
    if (f!=NULL)
    {
        fscanf_s(f, "%d", &n);
        a=new int[n];
        for (int i=0; i<n; i++)
        fscanf_s(f,"%d", &a[i]);
    }
    else
    {
        cout<<"Not open file input.txt\n";
    }
    fclose(f);
}

void write_output_file(int* a, int n,const char* name){
    FILE* f;
    fopen_s(&f, name, "w");
    if (f!=NULL)
    {
        fprintf(f,"%d\n", n);
        for (int i=0; i<n; i++)
        fprintf(f,"%d ", a[i]);
    }
    else
    {
        cout<<"Not open file output.txt"<<endl;
    }
    fclose(f);
}

void parse_arguments(int argc, char* argv[], char*& algorithm, char*& input_file, char*& output_file) {
    for (int i = 1; i < argc; i++) {
        char* arg = argv[i];

        if (strcmp(arg, "-a") == 0 && i + 1 < argc) {
            algorithm = argv[++i];
        } else if (strcmp(arg, "-i") == 0 && i + 1 < argc) {
            input_file = argv[++i];
        } else if (strcmp(arg, "-o") == 0 && i + 1 < argc) {
            output_file = argv[++i];
        }
    }
}

void shakerSort(int* a, int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        // Di chuyển từ trái sang phải
        for (int i = left; i < right; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
            }
        }
        right--;

        // Di chuyển từ phải sang trái
        for (int i = right; i > left; i--) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
            }
        }
        left++;
    }
}

int main(int argc, char* argv[]){
    int* a, n;

    char* algorithm = nullptr;
    char* input_file = nullptr;
    char* output_file = nullptr;

    parse_arguments(argc, argv, algorithm, input_file, output_file);

    read_input_file(a, n, "input.txt");
    if (algorithm != nullptr && strcmp(algorithm, "selection-sort") == 0) 
    {
        selectionsort(a, n);
    } 
    else if (algorithm!=NULL && strcmp(algorithm, "bubble-sort")==0)
    {
        bubblesort(a, n);
    }
        else if (algorithm!=NULL && strcmp(algorithm, "insertion-sort")==0)
    {
        insertionsort(a, n);
    }
            else if (algorithm!=NULL && strcmp(algorithm, "heap-sort")==0)
    {
        heapsort(a, n);
    }
                
    else
    {
        cout << "Algorithm not specified or not recognized!" << endl;  
    }
    write_output_file(a, n, "output.txt");
    delete[]a;
    return 0;
}
