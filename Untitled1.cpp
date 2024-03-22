#include<iostream>
#include<fstream>
using namespace std;
int main(){
	int paid=0, unpaid=0;
	ifstream read;
	string search, password, Id, pw;
	bool idCheck=false, correctPwCheck=false, loginCheck=false;
	cout<<"Enter user ID: ";
	cin>>search;
	read.open("EmployeesData.txt",ios::in);
	if (read.is_open()){
	while(!read.eof()){
	read>>Id>>pw;
	if (search==Id){
	idCheck=true;
	break;}
	if (search!=Id){
	cout<<"Sorry, no record found for ID: "<<Id<<endl;
	idCheck=false;}
	if (idCheck){
	while(!0){
	cout<<"Enter password: ";
	cin>>password;
	if (password==pw){
	correctPwCheck=true;
	loginCheck=true;}
	else{
	cout<<"Login failed.\nWrong password"<<endl;
	correctPwCheck=false;
	loginCheck=false;}
	if(correctPwCheck){
	cout<<"Login successful!"<<endl;
	loginCheck=true;
	break;}}}}
	read.close();}
	else
	cout<<"Could not open file."<<endl;
	if (loginCheck){
	ifstream fin;
	fin.open("BillingInfo.txt",ios::in);
    int regular,cost;
	string code, name, month, peak, dday, dmonth, dyear, tax, taxCost, bill, status;
	if (fin.is_open()){
	while (!fin.eof()){
	fin>>code>>name>>month>>regular>>peak>>dday>>dmonth>>dyear>>tax>>taxCost>>cost>>bill>>status;
	if (status=="paid")
	paid++;
	if (status=="unpaid")
	unpaid++;}
	cout<<"Amount of paid bills: "<<paid<<endl;
	cout<<"Amount of unpaid bills: "<<unpaid<<endl;
	fin.close();}}/*
	ifstream Myfile;
	Myfile.open("customersInfo.txt");
	if (Myfile.is_open()){
	while (!Myfile.eof()){
	Myfile>>search1>>uscnic>>usname>>usaddress>>usphone>>uscustomerType>>usmeterType;
	if (search1==search)
	break;}
	if (search1==search){
	while(!0){
	cout<<"Enter password: ";
	cin>>passWordnic;
	if (passWordnic==uscnic){
	correctPwCheck=true;
	billCheck=true;}
	else{
	cout<<"Wrong password"<<endl;
	correctPwCheck=false;}
	if(correctPwCheck)
	break;}}
	Myfile.close();}*/
	return 0;
}
