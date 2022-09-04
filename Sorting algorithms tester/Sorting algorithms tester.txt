#include<string>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<random>
#include<chrono>
using namespace std;
using namespace std::chrono;

class Sorter
{
public:
	Sorter() {}
	virtual void Sort(int* arr, int size) { cout << "no\n"; }
	virtual void Reversed_Sort(int* arr, int size) { cout << "no\n"; }

};
class SelectionSorter :public Sorter
{
public:

	void Sort(int* arr, int size) {
		int i, key, j;
		for (i = 1; i < size; i++)
		{
			key = arr[i];
			j = i - 1;

			while (j >= 0 && arr[j] > key)
			{
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
	}
	void Reversed_Sort(int* arr, int size) {
		int i, key, j;
		for (i = 1; i < size; i++)
		{
			key = arr[i];
			j = i - 1;

			while (j >= 0 && arr[j] < key)
			{
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
	}
};
class QuickSorter :public Sorter
{
	int Partitioning(int a[], int low, int high) {
		int j, i = low - 1, pivot = a[high];
		for (j = low; j < high; j++)
		{
			if (a[j] < pivot) {
				i++;
				swap(a[j], a[i]);
			}
		}
		swap(a[high], a[i + 1]);
		return i + 1;

	}


	void Quick_Sort(int* a, int l, int h)
	{
		while (l < h)
		{
			int piv = Partitioning(a, l, h);
			if (piv - l < h - piv)
			{
				Quick_Sort(a, l, piv - 1);
				l = piv + 1;
			}
			else
			{
				Quick_Sort(a, piv + 1, h);
				h = piv - 1;
			}
		}
	}
	/*{
		if (l < h) {
			int piv = partitioning(a, l, h);
			quickSort(a, l, piv - 1);
			quickSort(a, piv + 1, h);
		}
	}*/

public:

	void Sort(int* a, int n) {
		int l = 0, h = n - 1;
		Quick_Sort(a, l, h);
	}


};


class Test_Bed {
private:
	int* array;
public:
	//friend class Sorter;
	friend class SelectionSorter;
	friend class QuickSorter;
	Test_Bed() {};
	int * Generate_Random_List(int min, int max, int size) {
		array = new int[size];
		for (int i = 0; i < size; ++i) {
			array[i] = rand() % max;

		}

		return this->array;
	}
	int * Generate_Reversed_Ordered_List(int min, int max, int size) {
		array = new int[size];
		for (int i = 0; i < size; ++i) {
			array[i] = rand() % max;
		}
		SelectionSorter s;
		s.Reversed_Sort(array,size);

		return this->array;
	}
	void Run_Once(int sorter,int array[], int size) {
		if (sorter==1) {
			SelectionSorter s;
			auto start = high_resolution_clock::now();
			s.Sort(array, size);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << duration.count();
		}

		else if (sorter==2) {
			QuickSorter q;
			auto start = high_resolution_clock::now();
			q.Sort(array, size);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << duration.count();

		}

	}
	int Run_And_Average(int Sorter,int Type,int Min,int Max,int Size,int Sets_Num ) {

		int s=0,d=0,f=Size,j=0,k=0;
		int* array;
		if (Sorter == 1) {

			SelectionSorter s;
			if (Type == 1) {
				for (int i = 0;i < Sets_Num;i++) {
					array = new int[Size];
					array = Generate_Random_List(Min, Max, Size);
					auto start = high_resolution_clock::now();
					s.Sort(array, Size);
					delete []array;
					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<microseconds>(stop - start);
					d += duration.count();
					f+=Size;
				}
				k = to_string(Size).length();
				cout << Size;
				for (int i = k;i < 10;i++)
					cout << " ";
				cout << (d / Sets_Num) << endl;
				return (d / Sets_Num);
			}
			else if (Type == 2) {

				for (int i = 0;i < Sets_Num;i++) {
					array = new int[Size];
					array = Generate_Reversed_Ordered_List(Min, Max, Size);
					auto start = high_resolution_clock::now();
					s.Sort(array, Size);
					delete[]array;
					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<microseconds>(stop - start);
					d += duration.count();
					f += Size;
				}
				k = to_string(Size).length();
				cout << Size;
				for (int i = k;i < 10;i++)
					cout << " ";
				cout <<   (d / Sets_Num) << endl;
				return (d / Sets_Num);

			}
		}

		else if (Sorter == 2) {

			QuickSorter q;
			if (Type == 1) {



					for (int i = 0;i < Sets_Num;i++) {
						array = new int[Size];
						array = Generate_Random_List(Min, Max, Size);
						auto start = high_resolution_clock::now();
						q.Sort(array, Size);
						delete[]array;
						auto stop = high_resolution_clock::now();
						auto duration = duration_cast<microseconds>(stop - start);
						d += duration.count();

						f += Size;
					}
					k = to_string(Size).length();
					cout << Size;
					for (int i = k;i < 10;i++)
						cout << " ";
					cout << (d / Sets_Num) << endl;
					return (d / Sets_Num);


			}
			else if (Type == 2) {

				for (int i = 0;i < Sets_Num;i++) {
					array = new int[Size];
					array = Generate_Reversed_Ordered_List(Min, Max, Size);
					auto start = high_resolution_clock::now();
					q.Sort(array, Size);
					delete[]array;
					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<microseconds>(stop - start);
					d += duration.count();
					f += Size;
				}
				k = to_string(Size).length();
				cout << Size;
				for (int i = k;i < 10;i++)
					cout << " ";
				cout << (d / Sets_Num) << endl;
				return (d / Sets_Num);
			}
		}
	}
	void RunExperient(int Sorter,int Type,int  Min,int Max,int Min_Val,int Max_Val,int Sets_Num,int Step) {
		if (Sorter == 1&&Type==1) {
			cout << "Selection Sort" << endl;
			cout << "~~~~~~~~~~~~~~" << endl;
			cout << "Random Sets" << endl;
			cout << "~~~~~~~~~~~" << endl;
			cout << "(Size)   " << "(Average Time)" << endl;
			cout << "~~~~~~   "<<  "~~~~~~~~~~~~~~" << endl;
			Run_And_Average(Sorter, Type, Min, Max, Min_Val, Sets_Num);
			for (int i = Min_Val + Step;i <= Max_Val;i += Step) {
				Run_And_Average(Sorter, Type, Min, Max, i, Sets_Num);
			}
		}
		else if (Sorter == 1 && Type == 2) {
			cout << "Selection Sort" << endl;
			cout << "~~~~~~~~~~~~~~" << endl;
			cout << "Reverse Ordered Sets" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "(Size)   " << "(Average Time)" << endl;
			cout << "~~~~~~   " << "~~~~~~~~~~~~~~" << endl;
			Run_And_Average(Sorter, Type, Min, Max, Min_Val, Sets_Num);
			for (int i = Min_Val + Step;i <= Max_Val;i += Step) {
				Run_And_Average(Sorter, Type, Min, Max, i, Sets_Num);
			}
		}
		else if (Sorter == 2 && Type == 1) {
			cout << "Quick Sort" << endl;
			cout << "~~~~~~~~~~" << endl;
			cout << "Random Sets" << endl;
			cout << "~~~~~~~~~~~" << endl;
			cout << "(Size)   " << "(Average Time)" << endl;
			cout << "~~~~~~   " << "~~~~~~~~~~~~~~" << endl;
			Run_And_Average(Sorter, Type, Min, Max, Min_Val, Sets_Num);
			for (int i = Min_Val + Step;i <= Max_Val;i += Step) {
				Run_And_Average(Sorter, Type, Min, Max, i, Sets_Num);
			}
		}
		else if (Sorter == 2 && Type == 2) {
			cout << "Quick Sort" << endl;
			cout << "~~~~~~~~~~" << endl;
			cout << "Reverse Ordered Sets" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "(Size)   " << "(Average Time)" << endl;
			cout << "~~~~~~   " << "~~~~~~~~~~~~~~" << endl;
			Run_And_Average(Sorter, Type, Min, Max, Min_Val, Sets_Num);
			for (int i = Min_Val + Step;i <= Max_Val;i += Step) {
				Run_And_Average(Sorter, Type, Min, Max, i, Sets_Num);
			}
		}
		cout << "***********************************" << endl;
	}
	void printer(int size) {
		for (int i = 0;i < size;i++) {
			cout << array[i] << "  ";
		}
	}
};
int main()
{
	srand(time(NULL));
	Test_Bed t;
	QuickSorter q;
	q.Sort(t.Generate_Reversed_Ordered_List(1, 10000, 10000), 10000);
	// 1 means Selecion Sort // 2 means quick sort
	int sorter = 1;
	// 1 means random data // 2 means reverse ordered data
	int type = 1;
	t.RunExperient(sorter, type, 1, 10000, 5000, 35000, 5, 5000);
/****************************/
	sorter = 2;
	type = 1;
	t.RunExperient(sorter, type, 1, 10000, 5000, 35000, 5, 5000);
/****************************/
	sorter = 1;
	type = 2;
	t.RunExperient(sorter, type, 1, 10000, 5000, 35000, 5, 5000);
/****************************/
	sorter = 2;
	type = 2;
	t.RunExperient(sorter, type, 1, 10000, 5000, 35000, 5, 5000);
	return 0;
}






