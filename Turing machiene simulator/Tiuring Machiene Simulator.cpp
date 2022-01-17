#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <iomanip>
#include <conio.h>

using namespace std;

struct eilute 
{
	string b1; //Dabartine busena
	char r1; //Zenklas
	char r2; // Zenklas kuris pakeis r1
	char d; // puse i kuria bus zengiama
	string b2; //I kuria busena bus pereinama
};

vector<eilute> Vect; // sukuriamas tuščias eilute tipo vektorius

int main()
{
	string pavadinimas;
	cout << "Failo pavadinimas: ";
	cin >> pavadinimas;
	cout << "Jeigu norite iseiti is programos spauskite esc mygtuka" << endl;
	pavadinimas = pavadinimas + ".txt";
	ifstream doc;
	doc.open(pavadinimas);

	string juosta;
	int pos;

	if (!doc) 
	{
		cout << "Tokio failo nera.";
		return 0;
	}
	else
	{

		doc >> juosta >> pos;

		eilute temp; // sukuriama pagalbinė struktūra

		while (!doc.eof()) 
		{
			doc >> temp.b1;
			doc >> temp.r1;
			doc >> temp.r2;
			doc >> temp.d;
			doc >> temp.b2;
			Vect.push_back(temp);
		}
		doc.close();
	}
	pos=pos-1;
	string db = "0"; // pradine busena (dabartine busena)
	bool veikimas = true;

	char ch;

	while (veikimas == true)
	{
		if (_kbhit()) // begalinio ciklo sustabdymas
		{
			ch = _getch();
			if (int(ch) == 27) // esc mygtukas
			{
				cout << "Begalinis ciklas sustabdytas su esc mygtuku." << endl;
				return 0;
			}
				
		}

		for (int i = 0; i < Vect.size() - 1; i++)
		{
			veikimas = false;
			if (Vect[i].b1 == db && Vect[i].r1 == juosta[pos])
			{
				juosta[pos] = Vect[i].r2;
				if (Vect[i].d == 'L' && pos == 0)
				{
					cout << endl;
					cout << "Pasiekta juostos pabaiga" << endl;
					return 0;
				}
				else if (Vect[i].d == 'R') pos++;
				else if (Vect[i].d == 'L') pos--;
				else
				{
					cout << endl;
					cout << setw(2) << i << setw(3) << Vect[i].b1 << setw(2) << Vect[i].r1 << setw(2) << Vect[i].r2 << "--->" << setw(2) << Vect[i].d << "<----" << setw(2) << Vect[i].b2 << "Sintaksine klaida. Privaloma naudoti R arba L" << endl;
					return 0;
				}
				db = Vect[i].b2;
				//cout << setw(2) << i << setw(3) << Vect[i].b1 << setw(2) << Vect[i].r1 << setw(2) << Vect[i].r2 << 
					//setw(2) << Vect[i].d << setw(2) << Vect[i].b2 << endl;

				cout << juosta << endl;

				veikimas = true;
				break;
			}	
		}
	if (veikimas == false)
		{
		cout << endl;
		cout << "Progroma sustabdyta. Nerasta busena ( " << db << " ) su simboliu ( " << juosta[pos] << " )" << endl;
		}
		
	}
	
	return 0;
}

