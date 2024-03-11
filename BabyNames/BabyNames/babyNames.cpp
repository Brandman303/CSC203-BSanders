#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Rank {
	int bRank12;
	int gRank12;
	int bRank22;
	int gRank22;

	Rank() : bRank12(-1), gRank12(-1), bRank22(-2), gRank22(-2) {}

	Rank(int boyRank12, int girlRank12, int boyRank22, int girlRank22) :
		bRank12(boyRank12), gRank12(girlRank12), bRank22(boyRank22), gRank22(girlRank22) {}
};

void getRanks(const string& fileName, map<string, Rank>& nameRanks, bool isboy, int year);

int main() {
	map<string, Rank> nameRanks;
	string name;
	string notRanked = "is not ranked among the top names in ";

	//Absolute path below only works on my specific system.
	getRanks("C:/Users/User/Downloads/babynames2012.txt", nameRanks, true, 2012); // 2012 boy names
	getRanks("C:/Users/User/Downloads/babynames2012.txt", nameRanks, false, 2012); // 2012 girl names
	getRanks("C:/Users/User/Downloads/babynames2022.txt", nameRanks, true, 2022); // 2022 boy names
	getRanks("C:/Users/User/Downloads/babynames2022.txt", nameRanks, false, 2022); // 2022 girl names
	
	ofstream outFile("compareNames.txt");
	if (!outFile.is_open()) {
		cerr << "Unable to write to compareNames.txt" << endl;
		return 1;
	}
	//this is the headder for each collumn
	outFile << std::left << std::setw(20) << "NAME"
		<< setw(15) << "2012 BOY RANK"
		<< setw(15) << "2012 GIRL RANK"
		<< setw(15) << "2022 BOY RANK"
		<< setw(15) << "2022 GIRL RANK" << endl;

	for (const auto& entry : nameRanks) {
		outFile << left << setw(20) << entry.first
			<< setw(15) << (entry.second.bRank12 > 0 ? to_string(entry.second.bRank12) : "-")
			<< setw(15) << (entry.second.gRank12 > 0 ? to_string(entry.second.gRank12) : "-")
			<< setw(15) << (entry.second.bRank22 > 0 ? to_string(entry.second.bRank22) : "-")
			<< setw(15) << (entry.second.gRank22 > 0 ? to_string(entry.second.gRank22) : "-")
			<< endl;
	}

	outFile.close();

	cout << "Enter a name: ";
	cin >> name;
	
	if (nameRanks.find(name) != nameRanks.end()) {
		const Rank& rank = nameRanks[name];
		if (rank.bRank12 > 0) {
			cout << name << " is ranked " << rank.bRank12 << " in popularity among boys in 2012 ";
		}
		else {
			cout << notRanked << "popularity among boys in 2012 ";
		}
		if (rank.bRank22 > 0) {
			cout << "and " << rank.bRank22 << " in popularity among boys in 2022." << endl;
		}
		else {
			cout << " and " << notRanked << "popularity among boys in 2022. ";
		}
		cout << endl;
		if (rank.gRank12 > 0) {
			cout << name << " is ranked " << rank.gRank12 << " in popularity among girls in 2012 ";
		}
		else {
			cout << name << " " << notRanked << "popularity among girls in 2012 ";
		}
		if (rank.gRank22 > 0) {
			cout << "and " << rank.gRank22 << " in popularity among girls in 2022" << endl;
		}
		else {
			cout << "and " << notRanked << "popularity among girls in 2022 ";
		}

	}
	else {
		cout << name << " is not ranked among the top names in 2012 or 2022." << endl;
	}
}

void getRanks(const string& fileName, map<string, Rank>& nameRanks, bool isBoy, int year) {
	ifstream file(fileName);
	if (!file.is_open()) {
		cerr << "Unable to open file: " << fileName << endl;
		return;
	}

	int rank;
	string boyName;
	string girlName;
	while (file >> rank >> boyName >> girlName) {
		if (isBoy) {
			if (year == 2012) {
				nameRanks[boyName].bRank12 = rank;
			}
			else if (year == 2022) {
				nameRanks[boyName].bRank22 = rank;
			}
		}
		else {
			if (year == 2012) {
				nameRanks[girlName].gRank12 = rank;
			}
			else if (year == 2022) {
				nameRanks[girlName].gRank22 = rank;
			}
		}
	}
	file.close();
}
