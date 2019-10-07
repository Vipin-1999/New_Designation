#include "Designation.h"

using namespace std;
int i = 0;

/*void Designation :: VectorInit()      {
    std::string temp;
    int number;
    ifstream in;
	in.open("designation.txt", ios::binary);
    while (getline (in,temp))   {
        in >> temp;
        if(temp != " ")
            desList.push_back(temp);
    }
    in.close();
}

void Designation :: writetofile(std::string designation)       {
    ofstream out;
	out.open("designation.txt", ios::app);
    out << endl << designation;
    out.close();
}*/

bool Designation :: Validate(string designation)     {
    bool flag= std::regex_match(designation , std::regex("[A-Z]{1}[a-z]+"));
    if(flag)
        for(auto j = desList.begin(); j != desList.end(); ++j)
            if(*j == designation)   {
                return 1;
            }
            
    else if(!flag)
        throw invalid_argument("Invalid Designation");
    return 0;
}        

std::string Designation :: Random(int length, int number, int Min_Length, bool x)        {
    if((length < Min_Length) || (Min_Length*number >= length))
        throw std::invalid_argument("Invalid lengths");
    std::string Full_Designation;
    srand(time(0) + (i++));
    int gen;
    gen = rand() % (length/number) + Min_Length;
    if(gen > length)
        gen = length;
    if(x==1)        { 
        for(int k = 0; k < number; k++)       {
            Full_Designation+=Generate(gen)+" ";
            if(Full_Designation.length()+gen>=length)
                break;
        }
    }
    else        {
        for(int k = 0;k < number; k++)       {
            Full_Designation+=Generate_Invalid(gen)+" ";
            if(Full_Designation.length()>length)
                break;
        }
    }
    Full_Designation[Full_Designation.length()-1] = '\0'; 
    return Full_Designation;
}

std::string Designation :: Generate(size_t length)        {
    auto randchar = []() -> char        {
        const char charset[] =
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);            
        return charset[rand() % max_index];
    };
    std::string str(length,0);
    srand(time(0)+i++);
    std::generate_n( str.begin(), length, randchar );
    str[0]=str[0]-32;
    return str;
}

std::string Designation :: Generate_Invalid(size_t length)        {
    auto randchar = []() -> char        {
        const char charset[] =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-=+_!@#$%^&*(),.<>/?][{}/|`~";
        const size_t max_index = (sizeof(charset) - 1);            
        return charset[rand() % max_index];
    };
    std::string str(length,0);
    srand(time(0) + i++);
    std::generate_n(str.begin(), length,randchar );
    if(Validate(str))
        Generate_Invalid(length);
    return str;
}

void Designation :: Add(string designation)       {
/*    bool flag=1;
    string temp;
    ifstream in;
	in.open("designation.txt", ios::binary);
    while (getline (in,temp))   {
        if(temp == designation)     {
            flag = 0;
            break;
        }
    }
    in.close();
    if(flag == 1)       { */
        desList.push_back(designation);
//        writetofile(designation);
//    }
}

void Designation :: Remove(std::string designation)       {
    bool flag=1;
    for(auto j = desList.begin(); j != desList.end(); ++j)
        if(*j == designation)   {
            flag=0;
            desList.erase(j);
            break;
        }
    if(flag==1)
        cout << "Designation doesnt exist" << endl;
//    for(auto j = desList.begin(); j != desList.end(); ++j)
//        writetofile(*j);
}

void Designation :: Show()        {
    for(auto j = 0; j < desList.size(); ++j)
        cout << desList.at(j) << endl;
}
