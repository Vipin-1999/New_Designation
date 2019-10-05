#include "Designation.h"

using namespace std;

int main()      {
    Designation d;
//    d.VectorInit();
    d.Add("Janitor");
    cout << d.Validate("Janitor") << endl;
    cout << d.Validate("Ceo") << endl;
    return 0;
}
