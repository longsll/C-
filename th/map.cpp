#include <iostream>
#include <map>
using namespace std;

int main() {
    map <int,int> m;
    m[3] = 5;
	m[4] = 9;
	m[1] = 7;
    for (map<int,int> :: iterator it = m.begin(); it != m.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
	
    return 0;
}