#include<iostream>
#include<string>

using namespace std;

/*functie de adaugare a unui element intr-un vector
alocat dinamic*/
float* adaugareElement(float* vector, int dimensiune, float element)
{
	if(vector != nullptr && dimensiune > 0)
	{
		float* buffer = new float [dimensiune + 1];
		for(int i = 0; i < dimensiune; i++)
		{
			buffer [i] = vector [i];
		}
		buffer [dimensiune] = element;
		delete [] vector;
		return buffer;
	}
	return nullptr;
}

int main()
{
	int v[9];
	cout << "Dimendiune vector: " << sizeof(v) / sizeof(int) << endl;

	/*vector alocat dinamic cu 10 lemente*/
	int dimensiune = 10;
	float* vec = new float [dimensiune];
	for(int i = 0; i < dimensiune; i++)
	{
		vec [i] = i + rand() % 50;
	}

	for(int i = 0; i < dimensiune; i++)
	{
		cout << vec [i] << " ";
	}
	cout << endl;

	vec = adaugareElement(vec, dimensiune, 99);
	for(int i = 0; i < dimensiune; i++)
	{
		cout << vec [i] << " ";
	}
	cout << endl << endl;;
	delete [] vec;

	/*vector de caracatere*/
	char buffer [20];
	strcpy_s(buffer, 7, "Mircea");
	cout << buffer << endl;

	/*cate caractere sunt pana la \0*/
	cout << strlen(buffer) << endl;

	/*numar de caractere*/
	cout << sizeof(buffer) << endl;

	const char* const nume = "Vasile";
	/*vector de caractere alocat dinamic*/
	char* sirDinamic = new char [strlen(nume) + 1];
	strcpy_s(sirDinamic, strlen(nume) + 1, nume);
	cout << sirDinamic << endl << endl;

	cout << ((strcmp(buffer, sirDinamic) == 0) ? "Sunt egale " : "Nu sunt egale") << endl;


	string s1 = "Ionescu ";
	string s2 = "Popescu";

	cout << s1.length()<<"\n" << endl;

	/*concatenare*/
	string concatenare = s1 + s2;
	cout << concatenare << endl;

	/*transformare din string in char*/
	const char* transf = s2.c_str();
	cout << transf << endl;

	/*compare stringuri*/
	if(s1 == s2)
	{
		cout << "Stringurile sunt lafel!\n";
	}
	else
	{
		cout << "Stringurile sunt diferite!\n";
	}
	

	delete [] sirDinamic;

	cout << endl;


	/*matrice alocata static cu 2 linii si 3 coloane*/
	float matrice [2][3];
	cout << "Nr linii: " << sizeof(matrice) / sizeof(matrice [0]) << endl;
	cout << "Nr. elemente: " << sizeof(matrice) / sizeof(float) << endl;

	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			matrice [i][j] = i * 2+ rand()%50;
		}
	}

	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << matrice [i][j] << " ";
		}
		cout  << endl;
	}

	cout << "\n\n" << endl;

	/*Matrice alocata dinamic cu 2 linii si 3 coloane*/
	int nrLinii = 2;
	int nrColoane = 3;

	float** matrice2 = new float* [nrLinii];
	for(int i = 0; i < nrLinii; i++)
	{
		matrice2 [i] = new float [nrColoane];
	}
	int numar = 10;
	for(int i = 0; i< nrLinii; i++)
	{
		for(int j = 0; j < nrColoane; j++)
		{
			matrice2 [i][j] = numar * rand()%45;
		}
	}

	for(int i = 0; i < nrLinii; i++)
	{
		for(int j = 0; j < nrColoane; j++)
		{
			cout << matrice2 [i][j] << " ";
		}
		cout << endl;
	}

	/*dezalocare matrice alocata dinamic*/
	for(int i = 0; i < nrLinii; i++)
	{
		delete [] matrice2 [i];
	}
	delete[] matrice2;
}