#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct problem
{
    string id;
    string speciality;
    int durata;
};

struct doctor
{
    string id;
    string speciality;
    int timp_ramas = 8;
    vector<string> nr_probleme_rezolvate;
};

int main()
{

    ifstream inFile("input4_bonus.txt");

    int no_problems, no_doctors;

    inFile >> no_problems;
    vector <problem> problems(no_problems);

    for (auto it = problems.begin(); it != problems.end(); ++it) {
        inFile >> it->id >> it->speciality >> it->durata;
    }

    inFile >> no_doctors;
    vector <doctor>  doctors(no_doctors);
    for (auto it = doctors.begin(); it != doctors.end(); ++it) {
        inFile >> it->id >> it->speciality;
    }

    for (auto prob_it = problems.begin(); prob_it != problems.end(); ++prob_it) {
        bool accepted = false;
        for (auto doc_it = doctors.begin(); doc_it != doctors.end(); ++doc_it) {
            if (prob_it->speciality == doc_it->speciality && doc_it->timp_ramas >= prob_it->durata) {
                doc_it->timp_ramas -= prob_it->durata;
                doc_it->nr_probleme_rezolvate.push_back(prob_it->id);
                accepted = true;
                break;
            }

        }
    }

    for (auto it = doctors.begin(); it != doctors.end(); ++it) {
        cout << it->id << " " << it->nr_probleme_rezolvate.size() << " ";
        for (auto prob_it = it->nr_probleme_rezolvate.begin(); prob_it != it->nr_probleme_rezolvate.end(); ++prob_it) {
            cout << *prob_it << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}