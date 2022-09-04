
#include<string>
#include<iomanip>
#include <iostream>
using namespace std;
class Student_Name {
private:
	string NAME;
public:
	Student_Name(){}
	Student_Name(string name) {

		int counter=0,s,i;
		s = name.size();
		for (i = 0;i < s;i++)
		{
			if (name[i] == ' ')
			{
				counter++;
			}
		}
		if (counter >= 2) {
			NAME = name;
		}
		else if (counter == 0) {
			NAME = name +' '+ name+' ' + name;
		}
		else if (counter == 1) {
			NAME = name + ' ' + Find_Last_Word(name);
		}
	}
	string Find_Last_Word(string s) {
		string Last_Word;
		int i = s.length() - 1;
		while (s[i] != ' ')
			i--;
		for (int k = i + 1;k < s.length();k++)
			Last_Word += s[k];
		return Last_Word;
	}
	void Print_Name() {
		int N=1,k=0;
		for (int i = 0;i < NAME.length();i++) {
			if (NAME[i] == ' '||(i==NAME.length()-1)) {
				cout << N << ") ";
				for (int j = k;j < i;j++) {
					cout << NAME[j];
					if (j == i-1)
						cout << NAME[j+1];
				}
				cout << endl;
				N++;
				k = i + 1;
			}
		}
		cout << endl;
	}
	void Replace_Names(int R, int T) {
		if (R <= Number_Of_Names() && T <= Number_Of_Names()) {
			int s, b, o1=0, o2=0, p1=0, p2=0,dO,dB,f=0,r1=0,r2=0,c=0;
			string o, p, copy = NAME;
			s = min(R, T);
			b = max(R, T);
			cout << "True" << endl;
			if (s == 1) {
				o1 = 0;
				for (int i = 0;NAME[i] != ' ';i++) {
					o2 = i ;
				}
			}

			else if(s!=1) {
				int g = 1;
				for (int i = 0;i < NAME.length()&&g<=s;i++)
				{
					if (NAME[i] == ' ') {
						if ((g == s - 1)&&o1==0) {
							o1 = i + 1;
						}
						else if (g == s) {
							o2 = i - 1;
						}
						g++;
					}
				}
			}
			for (int i = o1;i <= o2;i++)
				o += NAME[i];
			if (Number_Of_Names() == b) {
				p2 = NAME.length()-1;
				p1 = p2;
				while (NAME[p1] != ' ')
					p1--;
				p1++;
			}
			else if (Number_Of_Names() != b) {
				int g = 1;
				for (int i = 0;i < NAME.length() && g <= b;i++)
				{
					if (NAME[i] == ' ') {
						if ((g == b - 1) && p1 == 0) {
							p1 = i + 1;
						}
						else if (g == b) {
							p2 = i - 1;
						}
						g++;
					}
				}
			}
			for (int i = p1;i <= p2;i++)
				p += NAME[i];
			dO = o2 - o1 + 1;
			dB = p2 - p1 + 1;
			for (int i = 0,j=0;i <= NAME.length();i++,j++) {
				if (i == o1 && (r1 == 0)) {
					while (f < dB) {
						copy[c] = p[f];
						f++;
						c++;
					}
					if (p1 - o2 == 1)
						copy[f] = ' ';
					f = 0;
					r1 = 1;
				}
				else if ((i == p1) && (r2 == 0)) {
					while (f < dO) {
						copy[c] = o[f];
						f++;
						c++;
					}
					r2 = 1;
					f = 0;
				}
				else if (i < o1) {
					copy[c] = NAME[i];
					c++;
				}
				else if (i > o1 && i < p1 && i>o2) {
					copy[c] = NAME[i];
					c++;
				}
				else if (i > p2) {
					copy[c] = NAME[i];
					c++;
				}

			}
			NAME = copy;
		}
		else
			cout << "False" << endl;
	}
	int Number_Of_Names() {
		int N=1;
		for (int i = 0;i < NAME.length();i++) {
			if (NAME[i] == ' ')
				N++;
		}
		return N;
	}
};

int main()
{
	// TEST CASE 1
	Student_Name test_1("Al-moutasem Hamdi Ali Mahmoud Atieh");
	// We Will Replace First Name With Last Name
	test_1.Replace_Names(1, 4);
	test_1.Print_Name();

	// TEST CASE 2
	Student_Name test_2("ali mohamed ahmed samy sherif elzorkany");
	// Now We Will Replace first name with a name from middle
	test_2.Replace_Names(3, 1);
	test_2.Print_Name();

	// TEST CASE 3
	Student_Name test_3("sherif hany mohamed shawky elsayed");
	// Now we will replace first two consecutive names
	test_3.Replace_Names(2, 3);
	test_3.Print_Name();

	// TEST CASE 4
	Student_Name test_4("Ahmed samy mohamed ahmed khairy");
    // Now lets replace last two consecutive names
	test_4.Replace_Names(5, 4);
	test_4.Print_Name();

	// TEST CASE 5
	Student_Name test_5("mohamed khaled ahmed eltohamy");
	// Now lets replace last name with a middle one
	test_5.Replace_Names(2, 4);
	test_5.Print_Name();

	// 'out of range' TEST CASE
	Student_Name Out_Of_Range("salma tarek ahmed");
    // Now lets try to replace an out of range name
	Out_Of_Range.Replace_Names(4, 5);
	// Names will be printed as it is 'No replacement!'
	Out_Of_Range.Print_Name();
}

