#include <iostream>
#include <cstring>

struct Doctor
{
    enum Gender
    {
        MALE = 1,
        FEMALE = 2

    };
    char nameFirst[32];
    char nameSecond[32];
    int workYears;
    char nameHospital[32];
    Gender gender;
    void printDoctorDetails()
    {
        std::cout << nameFirst << " " << nameSecond << " is a ";
        if (gender == 1)
        {
            std::cout << "male doctor that" << std::endl;
        }
        else
        {
            std::cout << "female doctor that" << std::endl;
        }
        std::cout << "Works in " << nameHospital << " for a total of " << workYears << " years" << std::endl;
    }
    void createDoctor()
    {
        int userInput;
        std::cout << "Enter first name (32 symbols long)" << std::endl;
        std::cin.getline(nameFirst, 32);
        std::cout << "Enter family name (32 symbols long)" << std::endl;
        std::cin.getline(nameSecond, 32);
        std::cout << "Enter Hospital name (32 symbols long)" << std::endl;
        std::cin.getline(nameHospital, 32);
        std::cout << "Years of practice" << std::endl;
        std::cin >> workYears;

        std::cout << "Enter gender (1-Male, 2-Female)" << std::endl;
        std::cin >> userInput;
        gender = getGender(userInput);
        std::cin.ignore();
    }
    Gender getGender(int input)
    {
        switch (input)
        {
        case 1:
            return MALE;
        case 2:
            return FEMALE;
        }
    }
    void setFamilyName()
    {
        std::cout << "Enter family name (32 symbols long)" << std::endl;
        char *newSecondName = new char[32];
        std::cin.getline(newSecondName, 32);
        strcpy(nameSecond, newSecondName);
        delete[] newSecondName;
    }
    void setHospitalName()
    {
        std::cout << "Enter Hospital name (32 symbols long)" << std::endl;
        std::cin.getline(nameHospital, 32);
        char *newHospitalName = new char[32];
        std::cin.getline(newHospitalName, 32);
        strcpy(nameHospital, newHospitalName);
        delete[] newHospitalName;
    }
};
int main()
{
    Doctor doctor;
    Doctor temp;
    Doctor doctors[10];
    doctor.createDoctor();
    doctor.printDoctorDetails();
    std::cout << doctor.gender;
    doctor.printDoctorDetails();
    for (int i = 0; i < 10; i++)
    {
        doctor.createDoctor();
        doctors[i] = doctor;
    }
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (doctors[i].workYears < doctors[j].workYears)
            {
                temp = doctors[i];
                doctors[i] = doctors[j];
                doctors[j] = temp;
            }
        }
    }
}
