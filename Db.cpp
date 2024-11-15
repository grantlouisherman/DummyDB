#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class DummyDatabase {
    public:
        DummyDatabase() {
            std::cout << "Constructor";
        };
        void init();
        void writeTable(){
            std::ofstream outfile("output.txt");
            if (outfile.is_open()) { 
                outfile << "Hello, world!" << std::endl;
                outfile.close();
                std::cout << "Data written to file successfully!" << std::endl;
            } else {
                std::cerr << "Error opening file!" << std::endl;
            }
        }
};

int main() {
    std::cout << "Working DB .....";
    DummyDatabase dB;
    dB.writeTable();
    return 0;
}

