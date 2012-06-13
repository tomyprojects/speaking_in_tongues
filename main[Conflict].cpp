#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
    int i[] = {1,2,3,4,5};

    cout << inner_product(i,i+2,i+2,0);
    return 0;
}
