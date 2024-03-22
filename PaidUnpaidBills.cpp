#include<iostream>
#include<fstream>
using namespace std;
int main(){
	char ch;
	int paid=0, unpaid=0;
	ifstream read;
	string search, password, Id, pw, compareCode="abc", compareP, compareunP;
	bool idCheck=false, correctPwCheck=false, loginCheck=false;
	cout<<"Enter user ID: ";
	cin>>search;
	read.open("EmployeesData.txt",ios::in);
	if (read.is_open()){
	while(!read.eof()){
	read>>Id>>pw;
	if (search==Id){
	idCheck=true;
	break;}}
	if (search!=Id){
	cout<<"Sorry, no record found for ID: "<<search<<endl;
	idCheck=false;}
	if (idCheck){
	while(!0){
	cout<<"Enter password: ";
	cin>>password;
	if (password==pw){
	correctPwCheck=true;
	loginCheck=true;}
	else{
	cout<<"Login failed!\nWrong password"<<endl;
	correctPwCheck=false;
	loginCheck=false;}
	if(correctPwCheck){
	cout<<"Login successful!"<<endl;
	loginCheck=true;
	break;}}}
	read.close();}
	else
	cout<<"Could not open file."<<endl;
	if (loginCheck){
	ifstream fin;
	ofstream fout,uout;
	fin.open("BillingInfo.txt",ios::in);
	fout.open("PaidBills.txt");
	uout.open("UnpaidBills.txt");
    int regular,cost;
	string code, name, month, peak, dday, dmonth, dyear, tax, taxCost, bill, status;
	if (fin.is_open()){
	while (!fin.eof()){
	compareCode=code;
	fin>>code>>name>>month>>regular>>peak>>dday>>dmonth>>dyear>>tax>>taxCost>>cost>>bill>>status;
	if (code==compareCode)
	break;
	else{
	if (status=="paid"){
	paid++;
	fout<<code<<' '<<name<<endl;}
	if (status=="unpaid"){
	unpaid++;
	uout<<code<<' '<<name<<endl;}}}
	cout<<"Amount of paid bills: "<<paid<<endl;
	cout<<"Amount of unpaid bills: "<<unpaid<<endl;
	fin.close();}
	cout<<endl;
	cout<<"Do you want to see the list of ID for paid and unpaid bills?(enter y): ";
	cin>>ch;
	cout<<endl;
	if (ch=='y'||ch=='Y'){
	ifstream P,unP;
	string code;
	P.open("PaidBills.txt");
	unP.open("UnpaidBills.txt");
	cout<<"Customers which have paid the bill"<<endl;
	cout<<" ID\t Name"<<endl;
	if (P.is_open()){
	while (!P.eof()){
	compareP=code;
	P>>code>>name;
	if (code==compareP)
	break;
	cout<<code<<'\t'<<name<<endl;}	
	P.close();}
	else
	cout<<"Could not open file."<<endl;
	cout<<endl;
	cout<<"Customers which have not paid the bill"<<endl;
	cout<<" ID\t Name"<<endl;
	if (unP.is_open()){
	while (!unP.eof()){
	compareunP=code;
	unP>>code>>name;
	if (code==compareunP)
	break;
	cout<<code<<'\t'<<name<<endl;}	
	unP.close();}
	else
	cout<<"Could not open file."<<endl;}}
	return 0;
}
