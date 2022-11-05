#include <iostream>
#include <string>
#include <vector>

using namespace std;

//-------------------Template Metaprogramming Here--------------------------//
//----sequence of consecutive numbers between N1 and N2 inclusive-----------//
template <int N1, int N2, int ... Tail>
// template constant (recursion body)
constexpr auto num_v = num_v<N1, N2-1, N2, Tail ...>;

template<int N1, int ...Tail>
// template constant (recursion base) - partial specialization of the num_v constant
constexpr auto num_v<N1, N1, Tail ...> = {N1, Tail ...}; // auto will be std::initializer_list
//--------------------------------------------------------------------------//

class Numbers {
private:
    std::vector<int> v;
public:
    Numbers(initializer_list<int> list): v(list){} // used to initialize v
    void printNumbers() {
        for (auto e : v) {
             cout << e << " ";
        }
    }
};

int main() {
    Numbers n[]  =  {num_v<1, 5>, num_v<3, 6>, num_v<7, 8>}; // all the sequances num_v will be calculated in compile time
    for (auto e : n) {
        e.printNumbers();
        cout << endl;
    }
    return 0;
}