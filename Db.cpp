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
        std::string writeRow(std::vector<std::string> row){
            std::string outFileString="";
            for(int i=0;i<row.size();i++){
                auto data = row[i];
                if(i < row.size()-1){
                    outFileString+=data+",";
                } else {
                    outFileString+=data+"\n";
                }
            }
            return outFileString;
        }
        void writeTable(std::string tableName, std::vector<std::string> headers, std::vector<std::vector<std::string>> rows){
            std::ofstream outfile(tableName+".txt");
            if (outfile.is_open()) { 
                std::string outFileString = "";
                outFileString+=writeRow(headers);
                for(const auto row: rows){
                    outFileString+=writeRow(row);
                }
                outfile << outFileString << std::endl;
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
    std::vector<std::string> headers = {"one", "two", "three", "four"};
    std::vector<std::string> row1 = {"oneA", "twoB", "threeC", "fourD"};
    std::vector<std::string> row2 = {"oneE", "twoF", "threeG", "fourH"};
    std::vector<std::vector<std::string>> rows;
    rows.push_back(row1);
    rows.push_back(row2);
    dB.writeTable("testDBTable", headers, rows);
    return 0;
}

