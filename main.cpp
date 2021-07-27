#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Globala konstanter:

// Tips: Använd de globala konstanterna ANTAL_BOKSTAVER och ANTAL_SPRAK
// istället för värdena 26 och 4 i programmet.
const int ANTAL_BOKSTAVER = 26;  //A-Z
const int ANTAL_SPRAK = 4;

// 2d-arrayen TOLK_HJALP innehåller bokstavsfrekvensen i %
// för fyra språk. TOLK_HJALP[0][0] är frekvensen av
// bokstaven a för engelska. TOLK_HJALP[0][25] är frekvensen av
// bokstaven z för engelska.
// Arrayen är en GLOBAL KONSTANT och skall alltså ej skickas
// som parameter till den funktion som behöver den.
const double TOLK_HJALP[ANTAL_SPRAK][ANTAL_BOKSTAVER]=
       {{8.27,1.48,2.94,4.03,11.78,2.22,1.72,6.77, //engelska
         7.39,0.12,0.81,3.76,2.85,6.71,7.79,1.54,
         0.05,5.95,6.69,9.07,2.66,1.13,2.14,0.19,
         1.89,0.03},
        {7.97,1.40,3.55,3.79,16.89,1.02,1.00,0.75, //franska
         7.08,0.38,0.04,5.51,2.82,8.11,5.19,2.78,
         1.01,6.69,8.35,7.22,6.09,1.35,0.02,0.54,
         0.30,0.15},
        {9.50,1.11,1.53,5.30,8.94,1.74,3.57,3.94,  //svenska
         3.98,0.89,3.26,4.93,3.41,8.46,5.01,1.77,
         0.00,6.73,5.56,9.20,1.94,2.42,0.00,0.05,
         0.45,0.00},
        {5.12,1.95,3.57,5.07,16.87,1.35,3.00,5.79, //tyska
         8.63,0.19,1.14,3.68,3.12,10.64,1.74,0.42,
         0.01,6.30,6.99,5.19,3.92,0.77,1.79,0.01,
         0.69,1.24}};

// Globala variabler är ej tillåtna

//--------------------------------------------------------
// Funktionsdeklarationer:

// Deklarationer av dina egna funktioner
// Använd exakt de funktionsnamn som finns nedan

void berakna_histogram_abs(const string inm, int arr[ANTAL_BOKSTAVER]);

void abs_till_rel(int arr[ANTAL_BOKSTAVER], int langd, double frekArr[ANTAL_BOKSTAVER]);

void plotta_histogram_rel(double frekArr[ANTAL_BOKSTAVER]);

void tolkning(double frekArr[ANTAL_BOKSTAVER]);

string namn_pa_fil(string inlast_fil, string filnamn);

string inlasning(string filnamn, string filtext);

//--------------------------------------------------------
// Huvudprogram:

int main()
{
    string fil_in, namn_fil, ny_fil, text;
    int alphabet[ANTAL_BOKSTAVER] = {0};
    double frekvensArr[ANTAL_BOKSTAVER] = {0};
    int langd = 0;

    ny_fil = namn_pa_fil(fil_in, namn_fil);

    text = inlasning(ny_fil, text);

    langd = text.length();

    berakna_histogram_abs(text, alphabet);

    abs_till_rel(alphabet, langd, frekvensArr);

    plotta_histogram_rel(frekvensArr);

    tolkning(frekvensArr);

  return 0;
}

//--------------------------------------------------------
void berakna_histogram_abs(const string inm, int arr[ANTAL_BOKSTAVER]){

    int i, j = 0;

    while (inm[i] != '\0'){
        if (inm[i] >= 'a' && inm[i] <= 'z'){
            j = inm[i] - 'a';
            ++arr[j];
        }
        if (inm[i] >= 'A' && inm[i] <= 'Z'){
            j = inm[i] - 'A';
            ++arr[j];
        }
        i++;
    }
}
void abs_till_rel(int arr[ANTAL_BOKSTAVER], int langd, double frekArr[ANTAL_BOKSTAVER]){
//Function to calculate the relative frequency of letters in a string.
    for (int i = 0; i < ANTAL_BOKSTAVER; i++){

    frekArr[i] = arr[i]; //Writes over the input from the user to a new array.

    frekArr[i] = frekArr[i] * 200 / langd; //Calculates the relative frequency
    //*200 since 1% should be represented by two (2) *.
    }
}
void plotta_histogram_rel(double frekArr[ANTAL_BOKSTAVER]){

    int j = 0;
    for (int i = 0; i < ANTAL_BOKSTAVER; i++){
    cout << char(i + 'A') << " : ";
//Creates a histograg, horizontal, with A-Z.

        if(frekArr[i] > 0){
        for ( j = 0; j < frekArr[i]; j++){
        cout << "*";
        }
        cout << endl;
        }
//If the index in frekArr is NOT empty, loop through the index [i] times and
//write double the amount of *.
        else {
            cout << " " << endl;
//Else, leave it empty.
        }
}
}

void tolkning(double frekArr[ANTAL_BOKSTAVER]){

    double skillnad1, skillnad2, skillnad3, skillnad4;
    double sum1, sum2, sum3, sum4 = 0.0;

    for (int i = 0; i < ANTAL_BOKSTAVER; i++){

        skillnad1 = TOLK_HJALP[0][i] - frekArr[i];
        sum1 = sum1 + skillnad1 * skillnad1;
    }
    cout << "Likheten engelska = " << sum1 << endl;

     for (int i = 0; i < ANTAL_BOKSTAVER; i++){

        skillnad2 = TOLK_HJALP[1][i] - frekArr[i];
        sum2 = sum2 + skillnad2 * skillnad2;
    }
    cout << "Likheten franska = " << sum2 << endl;

     for (int i = 0; i < ANTAL_BOKSTAVER; i++){

        skillnad3 = TOLK_HJALP[2][i] - frekArr[i];
        sum3 = sum3 + skillnad3 * skillnad3;
    }
    cout << "Likheten svenska = " << sum3 << endl;

     for (int i = 0; i < ANTAL_BOKSTAVER; i++){

        skillnad4 = TOLK_HJALP[3][i] - frekArr[i];
        sum4 = sum4 + skillnad4 * skillnad4;
    }
    cout << "Likheten tyska = " << sum4 << endl;

    if (sum1 < sum2 && sum1 < sum3 && sum1 < sum4){
        cout << "Engelska är mest troliga språket!" << endl;
    }
    else if (sum2 < sum1 && sum2 < sum3 && sum2 < sum4){
        cout << "Franska är mest troliga språket!" << endl;
    }
    else if (sum3 < sum1 && sum3 < sum2 && sum3 < sum4){
        cout << "Svenska är mest troliga språket!" << endl;
    }
    else{
        cout << "Tyska är mest troliga språket!" << endl;
    }

}

string namn_pa_fil(string inlast_fil, string filnamn){

    cout << "Skriv in ett filnamn: " << endl;
    getline(cin, filnamn);

    int pos = filnamn.find(".txt");
    string fd = filnamn;

    if (pos != string::npos){
        inlast_fil = filnamn.append("");
    }
    else if(pos = string::npos){
        inlast_fil = filnamn.append(".txt");
    }

    cout << inlast_fil << endl;
    return inlast_fil;

}
string inlasning(string filnamn, string filtext){

    string rad;

    ifstream infil(filnamn.c_str());

    if (!infil.is_open()){
        cout << "Filen gick inte att öppna!" << endl;
        exit(EXIT_FAILURE);
    }
    if (infil){
    while(!infil.eof())filtext.push_back(infil.get());
    }
    cout << filtext << '\n';
    return filtext;
    }




