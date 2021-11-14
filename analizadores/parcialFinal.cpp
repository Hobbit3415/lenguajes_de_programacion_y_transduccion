#include <iostream>
#include <regex>

using namespace std;

int main()
{

    regex reg("man");
    if (regex_search("Here is my man.", reg))
        cout << "matched" << endl;
    else
        cout << "not matched" << endl;

    return 0;
}