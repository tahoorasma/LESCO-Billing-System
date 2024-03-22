#include<iostream>
#include<fstream>
using namespace std;
int main(){
	char ch;
	string search,id,cnic,nic,CNIC,name,address,phNumber,ctype,mtype,issueDate,expiryDate,prevDate,dt,mo,yr;
	bool idCheck=false, nicCheck=false;
	ifstream fin;
	fin.open("customersInfo.txt");
	cout<<"Enter customer ID: ";
	cin>>search;
	if (fin.is_open()){
	while (!fin.eof()){
	fin>>id>>nic>>name>>address>>phNumber>>ctype>>mtype;
	if (search==id){
	idCheck=true;
	break;}}
	if (search!=id){
	idCheck=false;
	cout<<"Sorry, no record found for ID: "<<search<<endl;}
	if (idCheck){
	while(!0){
	cout<<"Enter CNIC: ";
	cin>>cnic;
	if (cnic!=nic){
	nicCheck=false;
	cout<<"You entered a wrong CNIC."<<endl;}
	else if (cnic==nic)
	nicCheck=true;
	if (nicCheck)
	break;}}
	fin.close();}
	else
	cout<<"Could not open file."<<endl;
	if (idCheck && nicCheck){
	ifstream myfile;
	myfile.open("NADRADB.txt");
	if (myfile.is_open()){
	while (!myfile.eof()){
	myfile>>CNIC>>issueDate>>expiryDate;
	if(CNIC==cnic)
	break;}
	cout<<"Customer's ID: "<<id<<endl;
	cout<<"Name: "<<name<<endl;
	cout<<"CNIC: "<<CNIC<<endl;
	cout<<"Issue Date: "<<issueDate<<endl;
	cout<<"Expiry Date: "<<expiryDate<<endl;
	prevDate=expiryDate;
	myfile.close();}
	else
	cout<<"Could not open file."<<endl;}
	cout<<endl;
	cout<<"Do you want to update expiry date?(enter y): ";
	cin>>ch;
	cout<<endl;
	if (ch=='y'||ch=='Y'){
	ifstream in;
	ofstream out;
	in.open("NADRADB.txt");
	out.open("TemporaryNADRADB.txt");
	if (in.is_open()){
	while(!in.eof()){
	in>>CNIC>>issueDate>>expiryDate;
	if (CNIC==cnic){
	cout<<"Enter new expiry date(dd/mm/yyyy)"<<endl;
	cout<<"Date: ";
	cin>>dt;
	cout<<"Month: ";
	cin>>mo;
	cout<<"Year: ";
	cin>>yr;
	out<<CNIC<<' '<<issueDate<<' '<<dt<<'/'<<mo<<'/'<<yr<<endl;}
	else
	out<<CNIC<<' '<<issueDate<<' '<<expiryDate<<endl;}
	in.close();}
	else
	cout<<"Could not open file."<<endl;
	ifstream i;
	ofstream o;
	i.open("TemporaryNADRADB.txt");
	o.open("NADRADB.txt");
	if (i.is_open()){
	while(!i.eof()){
	i>>CNIC>>issueDate>>expiryDate;
	if (CNIC==" ")
	break;
	o<<CNIC<<' '<<issueDate<<' '<<expiryDate<<endl;}
	cout<<"Your expiry date has been updated successfully!"<<endl;
	cout<<"It was previously "<<prevDate;
	cout<<" and has been changed to "<<dt<<'/'<<mo<<'/'<<yr<<" now."<<endl;
	remove("TemporaryNADRADB.txt");
	i.close();}
	else
	cout<<"Could not open file."<<endl;}
	return 0;
}
