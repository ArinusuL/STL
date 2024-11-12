#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct problem
{
    std::string id;
    std::string speciality;
};

struct doctor
{
    std::string id;
    std::string speciality;
};

int main()
{

    ifstream inFile("input.txt");

    int no_problems, no_doctors;

    inFile >> no_problems;

    std::vector <problem> problems(no_problems);
    for (int i = 0; i < no_problems; i++)
    {
        inFile >> problems[i].id;
        inFile >> problems[i].speciality;

    }

    inFile >> no_doctors;
    std::vector <doctor>  doctors(no_doctors);
    for (int i = 0; i < no_doctors; i++)
    {
        doctor doc;

        inFile >> doc.id;
        inFile >> doc.speciality;

        doctors.push_back(doc);
    }

    for (auto problem : problems) {
        bool accepted = false;
        for (auto doctor : doctors) {
            if (problem.speciality == doctor.speciality) {
                accepted = true;
                break;
            }
        }
        if (accepted) {
            std::cout << problem.id << " Acceptat" << std::endl;
        }
        else {
            std::cout << problem.id << " Respins" << std::endl;
        }

    }
    return 0;
}