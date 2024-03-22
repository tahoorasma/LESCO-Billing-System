#include<iostream>
#include<fstream>
using namespace std;
bool expiryInNext30Days(string expiryDate)
//function for checking expiry in next 30 days
{
	bool check;
	int date;
	char month[2];
	char year[3];
	int compareDate;
	month[0]=expiryDate[3];
	month[1]=expiryDate[4];
	month[2]=expiryDate[5];
	year[0]=expiryDate[6];
	year[1]=expiryDate[7];
	year[2]=expiryDate[8];
	year[3]=expiryDate[9];
	ofstream o;
	o.open("dt.txt");
	o<<expiryDate[0]<<expiryDate[1]<<endl;
	o.close();
	ifstream i;
	i.open("dt.txt");
	i>>date;
	int dt;
	string mo,yr,nextMo;
	ifstream fin;
	ofstream fout;
	fout.open("Date.txt");
	fout<<__DATE__<<endl;
	fout.close();
	fin.open("date.txt");
	fin>>mo>>dt>>yr;
	if (mo=="Jan"){
	mo="01";
	nextMo="02";}
	else if (mo=="Feb"){
	mo="02";
	nextMo="03";}
	else if (mo=="Mar"){
	mo="03";
	nextMo="04";}
	else if (mo=="Apr"){
	mo="04";
	nextMo="05";}
	else if (mo=="May"){
	mo="05";
	nextMo="06";}
	else if (mo=="Jun"){
	mo="06";
	nextMo="07";}
	else if (mo=="Jul"){
	mo="07";
	nextMo="08";}
	else if (mo=="Aug"){
	mo="08";
	nextMo="09";}
	else if (mo=="Sep"){
	mo="09";
	nextMo="10";}
	else if (mo=="Oct"){
	mo="10";
	nextMo="11";}
	else if (mo=="Nov"){
	mo="11";
	nextMo="12";}
	else if (mo=="Dec"){
	mo="12";
	nextMo="01";}
	if (yr==year){
	compareDate=dt;
	for (int i=0; i<30; i++){
	compareDate=compareDate+1;
	if (compareDate>30)
	compareDate=1;
	if (date>dt && date==compareDate && (month[0]==mo[0] && month[1]==mo[1])){
	check=true;
	break;}
	else if (date<=dt && date==compareDate && (month[0]==nextMo[0] && month[1]==nextMo[1])){
	check=true;
	break;}
	else
	check=false;}
	if (check)
	return true;
	else
	return false;}
	else
	return false;
}
int main(){
	string cnic,issueDate,expiryDate,compareNic;
	ifstream fin;
	fin.open("NADRADB.txt");
	if (fin.is_open()){
	cout<<endl;
	cout<<"Showing report of customers whose CNIC is about to expire in next 30 days"<<endl;
	while (!fin.eof()){
	compareNic=cnic;
	fin>>cnic>>issueDate>>expiryDate;
	if (cnic==compareNic)
	break;
	if (expiryInNext30Days(expiryDate)){
	char ch;
	string id,nic,name,address,ph,ctype,mtype;
	ifstream in;
	in.open("CustomersInfo.txt");
	if (in.is_open()){
	while(!in.eof()){
	in>>id>>nic>>name>>address>>ph>>ctype>>mtype;
	if(cnic==nic)
	break;}
	in.close();}
	else
	cout<<"Could not open file."<<endl;
	cout<<"    CNIC   \tEXPIRY DATE"<<endl;
	cout<<cnic<<'\t'<<expiryDate<<endl;
	if (cnic==nic){
	cout<<"Do you want to view customer's detail?(enter y) ";
	cin>>ch;
	if(ch=='y'||ch=='Y'){
	cout<<endl;
	cout<<"Customer ID: "<<id<<endl;
	cout<<"Name: "<<name<<endl;
	cout<<"Address: "<<address<<endl;
	cout<<"Phone number: "<<ph<<endl;
	cout<<"Customer Type: "<<ctype<<endl;
	cout<<"Meter Type: "<<mtype<<endl;
	cout<<endl;
	}}
	else if(cnic!=nic)
	cout<<"No customer found for this cnic."<<endl;}}
	fin.close();}
	else
	cout<<"Could not open file."<<endl;
	return 0;
}
