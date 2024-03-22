#include<iostream>
#include<fstream>
using namespace std;
int main(){
	/*bool
	int*/
	string cnic,issueDate,expiryDate,compareNic;
	ifstream fin;
	fin.open("NADRADB.txt");
	if (fin.is_open()){
	cout<<endl;
	cout<<"    CNIC   \tEXPIRY DATE"<<endl;
	while (!fin.eof()){
	compareNic=cnic;
	fin>>cnic>>issueDate>>expiryDate;
	if (cnic==compareNic)
	break;
	else
	cout<<cnic<<'\t'<<expiryDate<<endl;}
	fin.close();}
	else
	cout<<"Could not open file."<<endl;
	return 0;
}
	
