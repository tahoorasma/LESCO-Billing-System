#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
#include<ctime>

using namespace std;
string dateNtime;

void appendToFile()
//this function adds details for a new customer and append it to the CustomersInfo file
{
    int customerCode;
    string name;
    string cnic;
    string address;
    string phone;
    string customerType;
    string meterType;
	cout << endl << " -----------------------ENTER DETAILS FOR A NEW CUSTOMER-------------------------" << endl << endl;
    ofstream sfout("CustomersInfosample.txt",ios::out);			//sample file contains record of recently added customer
	ofstream fout("CustomersInfo.txt",ios::app);				//CustomersInfo contains record of all the customers 
	ifstream Myfile;
    int code1, code2, randomCode, sampleCode, sampleCode1;
	string uscnic,usname,usaddress,usphone,uscustomerType,usmeterType;
	int code,randomNumber;
	//the code below generates the random ID for every customer
	randomNumber=1000*(rand()%10);
    if (randomNumber==0)
    randomNumber=1000;
    code=randomNumber;
    randomNumber=100*(rand()%10);
    if (randomNumber==0)
    randomNumber=100;
	code=code+randomNumber;
	randomNumber=10*(rand()%10);
    if (randomNumber==0)
    randomNumber=10;
    code=code+randomNumber;
    randomNumber=rand()%10;
    if (randomNumber==0)
    randomNumber=1;
    code=code+randomNumber;
    customerCode=code;
    code2=customerCode;
    Myfile.open("CustomersInfo.txt");
    /*the code below checks if the randomly generated ID is already 
	a customer's ID or not if yes it generates a new ID until the
	system generates a new and different ID*/
    if (Myfile.is_open()){
	while (!Myfile.eof()){
	Myfile>>code1>>uscnic>>usname>>usaddress>>usphone>>uscustomerType>>usmeterType;
	if (code1==code2)		//If two employees have same code it breaks and generates new ID
	break;}
	if (code1==code2){
		while (!0){
        customerCode=(customerCode*(rand()%10));
        if (customerCode==0)
        customerCode=1000;
        randomCode=customerCode/1000;
        if (randomCode>=10)
        customerCode=customerCode/10;
        sampleCode=customerCode;
		while (!Myfile.eof()){
		Myfile>>sampleCode1>>uscnic>>usname>>usaddress>>usphone>>uscustomerType>>usmeterType;
		if (sampleCode==sampleCode1)
		break;}
		if (sampleCode!=sampleCode1)
		break;}}
	Myfile.close();
	}
	//end of code for generating customer's ID 
    cout << "Customer ID: " << customerCode << endl;
    fout<<customerCode<<' ';	//fout write the customer's info in CustomersInfo file
    sfout<<customerCode<<' ';	//sfout write the customer's info in CustomerInfosample file
	int cnicDigitCount,threeCnicCount=0;
	string a,b,c,searchCnic,nadraCnic;
	bool numberCheck,thirteen,nadraCnicCheck;
	ifstream cnicIn,nadra;
	while(!0){					//loop runs until the correct cnic is not entered
	nadra.open("NADRADB.txt");	//nadra file contains cnic of every customer
    cout << "Enter Customer CNIC: ";
    cin >> cnic;
	for (int i=0; cnic[i]!='\0'; i++){
	if (cnic[i]<48 || cnic[i]>57){         //check for correct cnic input (digits/numbers only)
	numberCheck=false;
	cout<<"Enter valid data."<<endl;
	break;}
	else
	numberCheck=true;}
	cnicDigitCount=0;
	for (int i=0; cnic[i]!='\0'; i++)	   //count the number of digits in a cnic
	cnicDigitCount++;
	if (cnicDigitCount!=13){
	thirteen=false;
	cout<<"CNIC should be 13-digit."<<endl;}
	else 
	thirteen=true;
	if (nadra.is_open()){				  //check if the cnic is registered in nadra file or not
	while (!nadra.eof()){
	nadra>>nadraCnic>>b>>c;
	if (cnic==nadraCnic){
	nadraCnicCheck=true;
	break;}
	else
	nadraCnicCheck=false;}
	nadra.close();}
	if (numberCheck==true && thirteen==true && nadraCnicCheck==false)
	cout<<"No match found for this CNIC in NADRADB file."<<endl;
	if (numberCheck==true && thirteen==true && nadraCnicCheck==true)
	break;}
	cnicIn.open("CustomersInfo.txt");
	if(cnicIn.is_open()){
	while(!cnicIn.eof()){
	cnicIn>>a>>searchCnic>>a>>a>>a>>a>>a;
	if (cnic==searchCnic)
	threeCnicCount++;
	if (threeCnicCount>3){				  //check if meters are more than three
	cout<<"Not allowed! You can only have at most three meters for the same CNIC."<<endl;
	cout << "Enter Customer CNIC: ";	  //again ask for cnic if user enter a cnic which has been used for 3 meters already
	while(!0){
    cin >> cnic;
	for (int i=0; cnic[i]!='\0'; i++){
	if (cnic[i]<48 || cnic[i]>57){						
	numberCheck=false;
	cout<<"Enter valid data."<<endl;
	break;}
	else
	numberCheck=true;}
	cnicDigitCount=0;
	for (int i=0; cnic[i]!='\0'; i++)
	cnicDigitCount++;
	if (cnicDigitCount!=13){
	thirteen=false;
	cout<<"CNIC should be 13-digit."<<endl;}
	else 
	thirteen=true;
	if (numberCheck==true && thirteen==true)
	break;}
	break;}}
	cnicIn.close();}
	else
	cout<<"File not found."<<endl;
    fout<<cnic<<' ';
    sfout<<cnic<<' ';
    cout << "Enter name: ";
    cin >> name;
    fout<<name<<' ';
    sfout<<name<<' ';
    cout << "Enter address: ";
    cin >> address;
    fout<<address<<' ';
    sfout<<address<<' ';
	int phDigitCount;
	bool phNumberCheck,eleven;
	while(!0){								//loop runs until a correct phone number is not entered
    cout << "Enter phone number: ";
    cin >> phone;
	for (int i=0; phone[i]!='\0'; i++){
	if (phone[i]<48 || phone[i]>57){		//check for correct phone number input (digits/numbers only)
	phNumberCheck=false;
	cout<<"Enter valid data."<<endl;
	break;}
	else
	phNumberCheck=true;}
	phDigitCount=0;
	for (int i=0; phone[i]!='\0'; i++)		//count number of digits in a phone number
	phDigitCount++;
	if (phDigitCount!=11){
	eleven=false;
	cout<<"Phone number should be 11-digit."<<endl;}
	else 
	eleven=true;
	if (phNumberCheck==true && eleven==true)
	break;}
    fout<<phone<<' ';
    sfout<<phone<<' ';
    cout << "Enter customer type (domestic or commertial): ";
	while(!0){								//loop runs until correct customer type is not entered
    cin >> customerType;             		//customer type should be either 'domestic' or 'commertial' only
	if (customerType=="domestic" || customerType=="commertial")
	break;
	else{
	cout<<"Please enter either 'domestic' or 'commertial'"<<endl;
	cout<<"Enter customer type: ";}}
    fout<<customerType<<' ';
    sfout<<customerType<<' ';
    cout << "Enter meter type (single or three phase): ";
	while(!0){								//loop runs until correct meter type is not entered
    cin >> meterType;             			//meter type should be either 'single' or 'three' only
	if (meterType=="single" || meterType=="three")
	break;
	else{
	cout<<"Please enter either 'single' or 'three'"<<endl;
	cout<<"Enter meter type: ";}}
    fout<<meterType<<' '<<endl;
    sfout<<meterType<<' '<<endl;
    sfout.close();
    cout << "\nRecord added sucessfully.\n";
    //providing ID as a username and cnic as password to the customer for billing and ypdating tariff
	cout << "Your username is: " << customerCode << "\nYour password is: " << cnic << endl << endl;
}
void displayCustomerRecord()				
//function for displaying recently added record of customer
{
    ifstream fin("customersInfosample.txt",ios::in); //reading and displaying the recently added info from sample file
	string displayID, displayCnic, displayName, displayAddress, displayPhone, displayCustType, displayMeterType;
	fin>>displayID>>displayCnic>>displayName>>displayAddress>>displayPhone>>displayCustType>>displayMeterType;
	cout<<"Name: "<<displayName<<endl;
	cout<<"Cnic: "<<displayCnic<<endl;
	cout<<"Address: "<<displayAddress<<endl;
	cout<<"Phone No.: "<<displayPhone<<endl;
	cout<<"Customer Type: "<<displayCustType<<endl;
	cout<<"Meter Type: "<<displayMeterType<<endl;
	fin.close();
}
void searchForRecord()
//function for searching and displaying customer's info for the ID entered by user
{
	string userName;
    string userCnic;
    string userAddress;
    string userPhone;
    string userCustType;
    string userMeterType;
	string search, search1;
	ifstream MyfileRecord;
	MyfileRecord.open("customersInfo.txt");
	cout<<"Enter user ID or username: ";
	cin>>search;
	if (MyfileRecord.is_open()){
	while (!MyfileRecord.eof()){			   //first searching the ID in customersInfo file
	MyfileRecord>>search1>>userCnic>>userName>>userAddress>>userPhone>>userCustType>>userMeterType;
	if (search1==search)              
	break;}
	if (search1!=search)			           //if the customer id is not found in the customersInfo file
	cout<<"Sorry, no record found for ID: "<<search<<endl;
	else{									   //if the ID is found it displays the customer's info 
	cout<<"\nShowing record of: "<<search<<endl;
    cout << "\nName: " << userName << "\nCNIC: " << userCnic << "\nPhone No.: " << userPhone <<endl;
	cout << "Address: " << userAddress << "\nCustomer Type: " << userCustType << "\nMeter Type: " << userMeterType << endl;}
	MyfileRecord.close();
	}
	else
	cout<<"Could not open file."<<endl;
}
void appendBill()
//function for add a new bill for any customer
{
    float bill;
    int regular, peak, dday, dmonth, dyear;
    string month;
	cout << endl << " -------------------------ENTER DETAILS FOR A NEW BILL---------------------------" << endl << endl;
	ofstream sfout("BillingInfosample.txt",ios::out); 	//sample file contains record of recently added bill
	ofstream fout("BillingInfo.txt",ios::app);			//BillingInfo contains info about the bill of all customers
	ifstream MyfileBill;
    int code1, code2, randomCode, sampleCode, sampleCode1;
	float tax, taxCost;
	bool correctPWcheck=false;
	string month1,regular1,peak1,dday1,dmonth1,dyear1,status;
	string search,search1,passWordnic,uscnic,usname,usaddress,usphone,uscustomerType,usmeterType,CT,MT,NAME;
	//the code below inserts a new row for a new bill of a customer in BillingInfo file
	while(!0){				 //loop runs until a correct ID or password(cnic) is not entered
	MyfileBill.open("customersInfo.txt");
	cout<<"Enter user ID: "; //first search for ID in file
	cin>>search;
	if (MyfileBill.is_open()){    				
	while (!MyfileBill.eof()){
	MyfileBill>>search1>>uscnic>>usname>>usaddress>>usphone>>uscustomerType>>usmeterType;
	if (search1==search){
	correctPWcheck=true;
	break;}}
	if (search1!=search){
	cout<<"Sorry, No RECORD found for ID: "<<search<<endl;
	correctPWcheck=false;}
	else{
	correctPWcheck=true;
	cout<<"Enter password: ";	//verifying password
	cin>>passWordnic;
	if (passWordnic==uscnic){
	correctPWcheck=true;
	CT=uscustomerType;
	MT=usmeterType;
	NAME=usname;
	}
	else{
	cout<<"Wrong password"<<endl;
	correctPWcheck=false;}
	MyfileBill.close();}}
	else
	cout<<"File is not open."<<endl;
	if (correctPWcheck)
	break;}
    fout<<search<<' ';			//appending new bill info in the BillingInfo file
    sfout<<search<<' ';			//adding info in the BillingInfosample file
    fout<<NAME<<' ';
    sfout<<NAME<<' ';
    cout << "Enter billing month: ";
    cin >> month;
    fout <<month<<' ';
    sfout<<month<<' ';
    cout << "Enter regular meter reading: ";
    cin >> regular;
    fout <<regular<<' ';
    sfout<<regular<<' ';
    cout << "Enter peak meter reading: ";
    cin >> peak;
    fout <<peak<<' ';
    sfout<<peak<<' ';
    cout << "Enter Due Date (dd/mm/yyyy)\n";
    cout<<"Date: ";
    cin >> dday;
    fout <<dday<<' ';
    sfout<<dday<<' ';
    cout<<"Month: ";
	cin >> dmonth;
    fout <<dmonth<<' ';
    sfout<<dmonth<<' ';
    cout<<"Year: ";
	cin >> dyear;
    fout <<dyear<<' ';
    sfout<<dyear<<' ';
    //the code below calculates the total bill after reading per unit rates from tariffTaxInfo file
    string phase;
    int loopControl;
	float regUnitPrice, PeakHourPrice, taxPercentage, fixCharges, totalCost;
    MyfileBill.open("tariffTaxInfo.txt");
	if (MyfileBill.is_open()){
	if (CT=="domestic" && MT=="single")
	loopControl=1;
	else if (CT=="domestic" && MT=="three")
	loopControl=2;
	else if (CT=="commertial" && MT=="single")
	loopControl=3;
	else if (CT=="commertial" && MT=="three")
	loopControl=4;
	for (int i=0; i<loopControl; i++)
    MyfileBill>>phase>>regUnitPrice>>PeakHourPrice>>taxPercentage>>fixCharges; //reading prices from tariffTaxInfo file
    MyfileBill.close();}
    totalCost=regUnitPrice*fixCharges;
    tax=totalCost*(taxPercentage/100);
    bill=totalCost+tax;
    status = "unpaid";	//the billing status is set to "unpaid" by default, it updates after the user pay the bill
    fout<<taxPercentage<<' '<<tax<<' '<<totalCost<<' '<<bill<<' '<<status<<endl;
    sfout<<taxPercentage<<' '<<tax<<' '<<totalCost<<' '<<bill<<' '<<status<<endl;
    sfout.close();
    cout << "Record added sucessfully.\n\n";
	//end of code for adding new billing details for a customer
}
void displayBillInfo()
//function for displaying recently added details of billing for any customer
{
	ifstream file;
    file.open("BillingInfo.TXT", ios::binary | ios::in);
    ifstream fin("BillingInfosample.txt",ios::in); //reading and displaying the recently added info from sample file
    int regular,cost;
	string code, name, month, peak, tax, taxCost, dday, dmonth, dyear, bill, status;
	fin>>code>>name>>month>>regular>>peak>>dday>>dmonth>>dyear>>tax>>taxCost>>cost>>bill>>status;
    cout << "Customer ID: " << code <<endl;
    cout << "Customer Name: " << name <<endl;
    cout << "Billing Month: " << month <<endl;
	cout << "Regular Units: " << regular <<endl;
	cout << "Peak Hour units: " << peak <<endl;
    cout << "Total cost: " << cost <<" rupees"<<endl;
    cout << "Tax: " << taxCost <<" ("<<tax<<"% tax included)"<<endl;
    cout << "Total Bill: " << bill <<" rupees"<<endl;
    cout << "Due Date: " << dday << "/" << dmonth << "/" << dyear <<endl;
    cout << "Billing Status: " << status <<endl;
	fin.close();
    file.close();
}
void searchForRecordinbillinginfo()
//function for searching bill of any customer by giving ID
{
    ifstream fin("BillingInfo.txt",ios::in);
    int regular,cost;
	string search, code, name, month, peak, tax, taxCost, dday, dmonth, dyear, bill, status;
	cout<<"Enter user ID: ";
	cin>>search;
	if (fin.is_open()){ 	//first searching for the entered ID in the BillingInfo file
	while (!fin.eof()){
	fin>>code>>name>>month>>regular>>peak>>dday>>dmonth>>dyear>>tax>>taxCost>>cost>>bill>>status;
	if (code==search)
	break;}
	if (code!=search)
	cout<<"Sorry, No record found."<<endl;
	else{					//if ID is found it displays the info
	cout<<"\nShowing record of: "<<search<<endl;
    cout << "Customer Name: " << name <<endl;
    cout << "Billing Month: " << month <<endl;
	cout << "Regular Units: " << regular <<endl;
	cout << "Peak Hour units: " << peak <<endl;
    cout << "Total cost: " << cost <<" rupees"<<endl;
    cout << "Tax: " << taxCost <<" ("<<tax<<"% tax included)"<<endl;
    cout << "Total Bill: " << bill <<" rupees"<<endl;
    cout << "Due Date: " << dday << "/" << dmonth << "/" << dyear <<endl;
    cout << "Billing Status: " << status <<endl;}
	fin.close();
	}
	else
	cout<<"Could not open file."<<endl;   
}
void payBill()
//function for paying the bill and updating the billing status in BillingInfo file
{
    time_t tt;             //argument for time
    struct tm*ti;          //variable to store return value of localtime()
    time(&tt);             //applying time
    ti=localtime(&tt);     //using localtime()
    bool billCheck=false, CorrectPwCheck=false;
    ifstream fin;
    ofstream fout;
    int regular,cost;
	string passWordnic, search, code, extracode, name, month, peak, tax, taxCost, dday, dmonth, dyear, bill, status;
	string search1, uscnic, usname, usaddress, usphone, uscustomerType, usmeterType;
	/*the code below searches for ID in the file first and then 
	ask the user to pay the bill after that it updates the 
	status from "unpaid" to "paid", if the bill has already
	been paid it shows when it was paid*/
	fin.open("BillingInfo.txt",ios::in);
	cout<<"Enter user ID: ";
	cin>>search;
	if (fin.is_open()){
	while (!fin.eof()){ 	//searching for ID in BillingInfo to get the customer's billing details
	fin>>code>>name>>month>>regular>>peak>>dday>>dmonth>>dyear>>tax>>taxCost>>cost>>bill>>status;
	if (code==search)
	break;}
	if (code!=search)
	cout<<"Sorry, No record found."<<endl;
	fin.close();}
	else
	cout<<"Could not open file."<<endl;
	ifstream Myfile;
	Myfile.open("customersInfo.txt");
	if (Myfile.is_open()){
	while (!Myfile.eof()){	//searching for ID in CustomersInfo to get customer's details
	Myfile>>search1>>uscnic>>usname>>usaddress>>usphone>>uscustomerType>>usmeterType;
	if (search1==search)
	break;}
	if (search1==search){
	while(!0){				//loop runs until correct password(cnic) is not entered
	cout<<"Enter password: ";
	cin>>passWordnic;
	if (passWordnic==uscnic){
	CorrectPwCheck=true;
	billCheck=true;}
	else{
	cout<<"Wrong password"<<endl;
	CorrectPwCheck=false;}
	if(CorrectPwCheck)
	break;}}
	Myfile.close();}
	else
	cout<<"Could not open file."<<endl;
	char ch;
	if(billCheck){
	if (status=="unpaid"){  	//asks the user to pay the bill
	cout<<"Your total bill is "<<bill<<" rupees"<<endl;
	cout<<"Press 'p' to pay the bill"<<endl;
	cin>>ch;
	if (ch=='p' || ch=='P');
	else{
	cout<<"Enter 'p' to pay the bill"<<endl;
	cin>>ch;}	
	extracode="abc";
	fin.open("BillingInfo.txt",ios::in);
	fout.open("TemporaryBillingInfo.txt",ios::out); //temp file to store all the data and overwrites the update in it
	if (fin.is_open()){
	while (!fin.eof()){
	fin>>code>>name>>month>>regular>>peak>>dday>>dmonth>>dyear>>tax>>taxCost>>cost>>bill>>status;
	if (extracode==code)
	break;
	fout<<code<<' '<<name<<' '<<month<<' '<<regular<<' '<<peak<<' ';
	extracode=code;
	fout<<dday<<' '<<dmonth<<' '<<dyear<<' '<<tax<<' '<<taxCost<<' '<<cost<<' '<<bill<<' ';
	if (code==search){
	status="paid";}
	fout<<status<<endl;}
	fout.close();
	fin.close();}
	else
	cout<<"File not found."<<endl;
	extracode="abc";
	fin.open("TemporaryBillingInfo.txt",ios::in);	//file contains the updated BillingInfo file
	fout.open("BillingInfo.txt",ios::out);			//deleting the file and making a new with update(s)
	if (fin.is_open()){
	while (!fin.eof()){
	fin>>code>>name>>month>>regular>>peak>>dday>>dmonth>>dyear>>tax>>taxCost>>cost>>bill>>status;
	if (extracode==code)
	break;
	fout<<code<<' '<<name<<' '<<month<<' '<<regular<<' '<<peak<<' ';
	extracode=code;
	fout<<dday<<' '<<dmonth<<' '<<dyear<<' '<<tax<<' '<<taxCost<<' '<<cost<<' '<<bill<<' '<<status<<endl;}
	fout.close();
	fin.close();}
	else
	cout<<"File not found."<<endl;
	remove("TemporaryBillingInfo.txt");
	cout<<"Bill paid."<<endl;
	cout<<"Bill paid on: "<<asctime(ti)<<endl;
	ofstream file("TimeAndDate.txt",ios::out|ios::app);
	dateNtime=asctime(ti);
	file<<search<<' '<<dateNtime<<endl;
	file.close();}
	else if (status=="paid"){
	cout<<"Your bill has already been paid."<<endl;
    string s,dy,mo,dt,tm,yr;
	ifstream File("TimeAndDate.txt",ios::in); //this file contains the day,month,date,time and year when the bill was paid
	while(!File.eof()){
	File>>s>>dy>>mo>>dt>>tm>>yr;
	if(s==search)
	break;}
	cout<<"Bill was paid on: "<<dy<<" "<<mo<<" "<<dt<<" "<<tm<<" "<<yr<<endl;
	File.close();}}
}
void viewBill()
//function for searching and displaying bill of any customer
{
	bool billCheck=false,correctPwCheck=false;
	ifstream fin;
	fin.open("BillingInfo.txt",ios::in);
    int regular,cost;
    string cd,dy,mo,dt,tm,yr;
	string passWordnic, search, code, name, month, peak, tax, taxCost, dday, dmonth, dyear, bill, status;
	string search1, uscnic, usname, usaddress, usphone, uscustomerType, usmeterType;
	cout<<"Enter user ID: ";
	cin>>search;
	if (fin.is_open()){
	while (!fin.eof()){
	fin>>code>>name>>month>>regular>>peak>>dday>>dmonth>>dyear>>tax>>taxCost>>cost>>bill>>status;
	if (code==search)
	break;}
	if (code!=search)
	cout<<"Sorry, No record found."<<endl;
	fin.close();}
	else
	cout<<"Could not open file."<<endl;
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
	Myfile.close();}
	else
	cout<<"Could not open file."<<endl;
	if(billCheck){
    cout << "\t\t==================================================\n";
    cout << "\t\t\t\t  ELECTRICITY BILL\n";
    cout << "\t\t==================================================\n\n";
    cout << "\t\t--------------------------------------------------\n";
    cout << "\t\t||\tCUSTOMER ID     :" << search                        << "\t\t\t||\n";
    cout << "\t\t||\tNAME            :" << name                          << "\t\t\t||\n";
    cout << "\t\t||\tADDRESS         :" << usaddress                     << "\t\t\t||\n";
    cout << "\t\t||\tPHONE NUMBER    :" << usphone                       << "\t\t||\n";
    cout << "\t\t||\tCUSTOMER TYPE   :" << uscustomerType                << "\t\t||\n";
    cout << "\t\t||\tMETER TYPE      :" << usmeterType                   << "\t\t\t||\n";
    cout << "\t\t||\t------------------------------\t\t||\n";
    cout << "\t\t||\tBILLING MONTH   :" << month                         << "    \t\t||\n";
    cout << "\t\t||\tREGULAR UNITS   :" << regular                       << "\t\t\t||\n";
    cout << "\t\t||\tPEAK HOUR UNITS :" << peak                          << "\t\t\t||\n";
    cout << "\t\t||\tTOTAL COST      :" << cost<<" rupees"               << "\t\t||\n";
    cout << "\t\t||\tTAX             :" << taxCost                       << "\t\t\t||\n";
    cout << "\t\t||\t("<<tax<<"% tax included)"                          << "\t\t\t||\n";
    cout << "\t\t||\tTOTAL BILL      :" << bill<<" rupees"               << "\t\t||\n";
    cout << "\t\t||\tDUE DATE        :" << dday<<"/"<<dmonth<<"/"<<dyear << "\t\t||\n";
    cout << "\t\t||\tSTATUS          :" << status                        << "\t\t\t||\n";
    if (status=="paid"){
	ifstream File("TimeAndDate.txt",ios::in);
	while(!File.eof()){
	File>>cd>>dy>>mo>>dt>>tm>>yr;
	if (cd==search)
	break;}
	cout << "\t\t||\tBill paid on:" << dy<<' '<<mo<<' '<<dt<<' '<<tm<<' '<<yr<<"\t||\n";
	File.close();}
    cout << "\t\t--------------------------------------------------\n";
    cout << "\t\t--------------------------------------------------\n";}
}
void paidAndUnpaidBills()
//function for displaying paid and unpaid bills to employees
{	
	char ch;
	int paid=0, unpaid=0;
	string compareCode="abc", compareP, compareunP;
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
	cout<<endl;
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
	cout<<"Could not open file."<<endl;}
}
void billinginfo()
//function for appending, displaying, viewing or paying bill or paid/unpaid bills
{
    char ch;
    bool BillingWhile=true;
    do
    {
    int n;
	cout << endl << " -----------------------------------BILLING--------------------------------------" << endl << endl;
    cout << "\t\t\t------------------------------------------\n";
	cout << "\t\t\t||\t1.ADD NEW BILL INFO\t\t||\n";
	cout << "\t\t\t||\t2.DISPLAY BILL INFO\t\t||\n";
	cout << "\t\t\t||\t3.VIEW A BILL      \t\t||\n";
	cout << "\t\t\t||\t4.PAY BILL         \t\t||\n";
	cout << "\t\t\t||\t5.VIEW PAID AND UNPAID BILLS\t||\n";
	cout << "\t\t\t------------------------------------------\n";
        while (!0){
		cout << "Make a choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            appendBill();
            break;
        case 2:
            displayBillInfo();
            break;
        case 3:
            viewBill();
            break;
        case 4:
            payBill();
            break;
        case 5:
        	paidAndUnpaidBills();
        	break;
        default:
        	BillingWhile=false;
            cout << "Invalid Choice\n";
        }
		if (BillingWhile)
		break;}
        cout << "\nDo you want to continue ?(enter y) : ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}
void UpdateTariffInfo()
//function for updating any info in tariffTaxInfo file
{
	int loopControl, n;
	string update, ctype, mtype, phase, regUnitPrice, PeakHourPrice, taxPercentage, fixCharges;
	string nregUnitPrice, nPeakHourPrice, ntaxPercentage, nfixCharges;
	ifstream fin;
	ofstream fout, sfout;
	fin.open("TariffTaxInfo.txt",ios::in);			//file contains tariff/tax info
	fout.open("TemporaryTariffTaxInfo.txt");		//temp file to store the TariffTaxInfo file and overwrite the update
	sfout.open("TariffTaxInfoSample.txt");			//file contains the info about update
	/*the code below first asks for the customer type and 
	meter type and then give 4 options to update in the
	file and then updates it*/
	cout<<"Enter Customer Type: ";
	cin>>ctype;
	cout<<"Enter Meter Type: ";
	cin>>mtype;
	sfout<<ctype<<' '<<mtype<<' ';
	if (ctype=="domestic" && mtype=="single")
	loopControl=1;
	else if (ctype=="domestic" && mtype=="three")
	loopControl=2;
	else if (ctype=="commertial" && mtype=="single")
	loopControl=3;
	else if (ctype=="commertial" && mtype=="three")
	loopControl=4;
    cout<<"What do you want to update? "<<endl;
    cout<<"1. Regular Unit Price\n2. Peak Hour Unit Price\n3. Tax percentage\n4. Fixed Charges"<<endl;
    cout<<"Choose from 1 to 4: ";
    cin>>n;
    if (n<1 || n>4){
    cout<<"Choose from 1 to 4: ";
    cin>>n;}
    int count=0;
	if (fin.is_open()){
	while (!fin.eof()){
    fin>>phase>>regUnitPrice>>PeakHourPrice>>taxPercentage>>fixCharges;
    count++;
    fout<<phase<<' ';
    if (count==loopControl){
    if (n==1){
    update="RegularUnitPrice";
    cout<<"Enter new price for regular units: ";
    cin>>nregUnitPrice;
    fout<<nregUnitPrice<<' '<<PeakHourPrice<<' '<<taxPercentage<<' '<<fixCharges<<endl;
	sfout<<regUnitPrice<<' '<<nregUnitPrice<<' ';
	loopControl=0;}
	else if (n==2){
    update="PeakHourUnitPrice";
    cout<<"Enter new price for peak hour units: ";
    cin>>nPeakHourPrice;
    fout<<regUnitPrice<<' '<<nPeakHourPrice<<' '<<taxPercentage<<' '<<fixCharges<<endl;
	sfout<<PeakHourPrice<<' '<<nPeakHourPrice<<' ';
	loopControl=0;}
	else if (n==3){
    update="TaxPercentage";
    cout<<"Enter new percentage for tax: ";
    cin>>ntaxPercentage;
    fout<<regUnitPrice<<' '<<PeakHourPrice<<' '<<ntaxPercentage<<' '<<fixCharges<<endl;
	sfout<<taxPercentage<<' '<<ntaxPercentage<<' ';
	loopControl=0;}
	else if (n==4){
    update="FixedCharges";
    cout<<"Enter new fixed charges: ";
    cin>>nfixCharges;
    fout<<regUnitPrice<<' '<<PeakHourPrice<<' '<<taxPercentage<<' '<<nfixCharges<<endl;
	sfout<<fixCharges<<' '<<nfixCharges<<' ';
	loopControl=0;}}
	else
	fout<<regUnitPrice<<' '<<PeakHourPrice<<' '<<taxPercentage<<' '<<fixCharges<<endl;
	}
	fin.close();}
	else 
	cout<<"File not found."<<endl;
    sfout<<update<<endl;
    int i=0;
    ofstream file;
	fin.open("TemporaryTariffTaxInfo.txt",ios::in); 	//file contains updated TarifftaxInfo file
	file.open("TariffTaxInfo.txt",ios::out);			//deleting and making a new file with uodate(s)
	if (fin.is_open()){
	while (!fin.eof()){
    fin>>phase>>regUnitPrice>>PeakHourPrice>>taxPercentage>>fixCharges;
	file<<phase<<' '<<regUnitPrice<<' '<<PeakHourPrice<<' '<<taxPercentage<<' '<<fixCharges<<endl;
    i++;
    if (i==4)
    break;}
	fin.close();}
	else
	cout<<"File not found."<<endl;
	remove("TemporaryTariffTaxInfo.txt");				//deleting the temporary file
    cout<<"TariffTaxInfo file has been updated."<<endl;
}
void displayUpdate()
//function dislays what has been updated in TariffTaxInfo file
{
	string ctype,mtype,pre,post,update;
	ifstream fin("TariffTaxInfoSample.txt");
	fin>>ctype>>mtype>>pre>>post>>update;
	cout<<update<<" for "<<ctype<<" "<<mtype<<" phase customers has been updated from "<<pre<<" to "<<post<<endl;
}
void showTariffFile()
//displays the whole TariffTaxInfo file
{
	int i=0;
	string type,phase,regUnitPrice,PeakHourPrice,taxPercentage,fixCharges;
	cout<<"CUTSOMER TYPE\tPHASE\tREGULAR UNIT PRICE\tPEAK HOUR UNIT PRICE\tPERCENTAGE OF TAX     FIXED CHARGES"<<endl;
	ifstream fin("TariffTaxInfo.txt");
	if (fin.is_open()){
	while (!fin.eof()){
    fin>>phase>>regUnitPrice>>PeakHourPrice>>taxPercentage>>fixCharges;
    if (i==0 || i==1)
    type="domestic";
    else
    type="commertial";
	cout<<type<<"\t"<<phase<<"\t\t"<<regUnitPrice<<"\t\t\t"<<PeakHourPrice<<"\t\t\t"<<taxPercentage<<"\t\t   "<<fixCharges<<endl;
	i++;
	if(i==4)
	break;}
	fin.close();}
}
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
void viewAllExpiryDates()
//function for all expiry dates with user cnic
{
	string cnic,issueDate,expiryDate,compareNic;
	ifstream fin;
	fin.open("NADRADB.txt");
	if (fin.is_open()){
	cout<<endl;
	cout<<"Showing all CNICs and their Expiry dates respectively"<<endl;
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
}
void closeExpiryDates()
//function for viewing cnic(s) whose expiry date is close
{
	
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
}
void updateCnicExpiryDate()
//function for updating the cnic's expiry date
{
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
	cout<<endl;
	cout<<"Customer's ID: "<<id<<endl;
	cout<<"Name: "<<name<<endl;
	cout<<"CNIC: "<<CNIC<<endl;
	cout<<"Issue Date: "<<issueDate<<endl;
	cout<<"Expiry Date: "<<expiryDate<<endl;
	prevDate=expiryDate;
	myfile.close();}
	else
	cout<<"Could not open file."<<endl;
	cout<<endl;
	cout<<"Do you want to update expiry date?(enter y): ";
	cin>>ch;
	cout<<endl;
	if (ch=='y'||ch=='Y'){
	string compareNic="abc";
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
	compareNic=CNIC;
	i>>CNIC>>issueDate>>expiryDate;
	if (CNIC==compareNic)
	break;
	else
	o<<CNIC<<' '<<issueDate<<' '<<expiryDate<<endl;}
	cout<<"Your expiry date has been updated successfully!"<<endl;
	cout<<"It was previously "<<prevDate;
	cout<<" and has been changed to "<<dt<<'/'<<mo<<'/'<<yr<<" now."<<endl;
	remove("TemporaryNADRADB.txt");
	i.close();}
	else
	cout<<"Could not open file."<<endl;}}
}
void cnicExpiry()
//function for viewing and updating cnic expry dates
{
	char ch;
	bool TariffWhile=true;
    do
    {
    int n;
	cout << endl << " -------------------------------UPDATING CNIC EXPIRY----------------------------------" << endl << endl;
    cout << "\t\t\t----------------------------------\n";
	cout << "\t\t\t||   1.VIEW ALL EXPIRY DATES  \t||\n";
	cout << "\t\t\t||   2.VIEW CLOSE EXPIRY DATES\t||\n";
	cout << "\t\t\t||   3.UPDATE CNIC EXPIRY DATE\t||\n";
	cout << "\t\t\t----------------------------------\n";
        while(!0){
		cout<<"Make a choice: ";
		cin>>n;
        switch (n)
        {
        case 1:
            viewAllExpiryDates();
            break;
        case 2:
            closeExpiryDates();
            break;
        case 3:
        	updateCnicExpiryDate();
            break;
        default:
        	TariffWhile=false;
            cout << "Invalid Choice\n";
        }
    	if (TariffWhile)
    	break;}
        cout << "\nDo you want to continue ?(enter y) : ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');   
}
void updateTariff()
//function for updating tariffTaxInfo file, displaying update or displaying the whole file
{
	char ch;
	bool TariffWhile=true;
    do
    {
    int n;
	cout << endl << " -------------------------------UPDATING TARIFF----------------------------------" << endl << endl;
    cout << "\t\t\t----------------------------------\n";
	cout << "\t\t\t||    1.UPDATE INFO        \t||\n";
	cout << "\t\t\t||    2.DISPLAY INFO       \t||\n";
	cout << "\t\t\t||    3.DISPLAY TARIFF FILE\t||\n";
	cout << "\t\t\t----------------------------------\n";
        while(!0){
		cout<<"Make a choice: ";
		cin>>n;
        switch (n)
        {
        case 1:
            UpdateTariffInfo();
            break;
        case 2:
            displayUpdate();
            break;
        case 3:
            showTariffFile();
            break;
        default:
        	TariffWhile=false;
            cout << "Invalid Choice\n";
        }
    	if (TariffWhile)
    	break;}
        cout << "\nDo you want to continue ?(enter y) : ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');   
}
void employee()
//function to add a new customer, searching customer's info, billing info or updating a tariff
{
    char ch;
    bool EmployeeWhile=true;
    do
    {
    int n;
	cout << endl << " --------------------------------EMPLOYEE PORTAL---------------------------------" << endl << endl;
    cout << "\t\t\t----------------------------------\n";
    cout << "\t\t\t||   1.ADD A CUSTOMER     \t||\n";
	cout << "\t\t\t||   2.DISPLAY            \t||\n";
	cout << "\t\t\t||   3.SEARCH             \t||\n";
	cout << "\t\t\t||   4.CNIC EXPIRY DATES  \t||\n";
	cout << "\t\t\t||   5.BILLING INFO       \t||\n";
	cout << "\t\t\t||   6.UPDATE A TARIFF    \t||\n";
    cout << "\t\t\t----------------------------------\n";
        while(!0){
		cout << "Make a choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            appendToFile();
            break;
        case 2:
            displayCustomerRecord();
            break;
        case 3:
            searchForRecord();
            break;
        case 4:
        	cnicExpiry();
			break;
        case 5:
            billinginfo();
            break;
        case 6:
        	updateTariff();
        	break;
        default:
            EmployeeWhile=false;
			cout << "Invalid Choice\n";
        }
    if (EmployeeWhile)
    break;}
        cout<<endl;

        cout << "Do you want to continue from employee portal? (enter y) ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}
void employeesUsernameAndPassword()
//function for providing username and password to recently added customer
{
	float username;
	string password;
	ifstream fin("record.txt", ios::in);
	ofstream fout("EmployeesData.txt", ios::app);
	fin>>username>>password;
	fout<<username<<' '<<password<<endl;
}
void changePassword()
//function to change password of already registered ID
{
	float username;
	string pw, pw1, pw2;
	bool check,PwCheck,confirmPw;
	bool idcheck;
	int searchid, searchid1, srchid, extrasearch=1;
	string pwcnic, newpw, pwnic;
	ifstream infile;
	ofstream outfile;
	infile.open("EmployeesData.txt");
	outfile.open("TemporaryEmployeesData.txt"); 	//temp file for storing EmployeedData and overwriting the update(s)
	cout<<"CHANGE PASSWORD"<<endl;      				
	cout<<"Enter username: ";
	cin>>searchid;
	if (infile.is_open()){
	while (!infile.eof()){
	infile>>searchid1>>pwcnic;
	if (extrasearch==searchid1)
	break;
	outfile<<searchid1;
	extrasearch=searchid1;
	if (searchid1==searchid){
	check=true;
	while(!0){
	cout<<"Enter current password: ";
	cin>>pw;
	if (check==true && pw==pwcnic){
	PwCheck=true;
	cout<<"Enter a new password: ";
	cin>>pw1;
	while(!0){
	cout<<"Confirm password: ";
	cin>>pw2;
	if (pw1==pw2){
	confirmPw=true;
	newpw=pw1;
	outfile<<' '<<newpw<<endl;
	cout<<"Password has been updated!"<<endl;
	remove("EmployeesData.txt");
	idcheck=true;}
	else{
	cout<<"Enter the same password."<<endl;
	confirmPw=false;}
	if(confirmPw)
	break;}}
	else{
	cout<<"Wrong password."<<endl;
	PwCheck=false;}
	if (PwCheck==true)
	break;}
	}
	else{
	outfile<<' '<<pwcnic<<endl;}}
	if (!idcheck)
	cout<<"Sorry, No record found for ID: "<<searchid<<endl;	
	infile.close();
	}
	else
	cout<<"File not found."<<endl;
	extrasearch=1;
	ifstream ifile;
	ofstream ofile;
	ifile.open("TemporaryEmployeesData.txt"); //temp file contains updates EmployeesData file
	ofile.open("EmployeesData.txt");		  //deleting and making a new file with update(s)
	if (ifile.is_open()){
	while (!ifile.eof()){
	ifile>>srchid>>pwnic;
	if (extrasearch==srchid)
	break;
	ofile<<srchid<<" "<<pwnic<<endl;
	extrasearch=srchid;
	}
	ifile.close();
	}
	else
	cout<<"File not found."<<endl;
	remove("TemporaryEmployeesData.txt");     //deleting the temp file
}
int main()
{
    int uID;
	string pass;
    int choice;
    char key;
    //the code below generates a random 4-digit ID for the user
    int randomNumber, randomID;
	randomNumber=1000*(rand()%10);
    if (randomNumber==0)
    randomNumber=1000;
    uID=randomNumber;
    randomNumber=100*(rand()%10);
    if (randomNumber==0)
    randomNumber=100;
	uID=uID+randomNumber;
	randomNumber=10*(rand()%10);
    if (randomNumber==0)
    randomNumber=10;
    uID=uID+randomNumber;
    randomNumber=rand()%10;
    if (randomNumber==0)
    randomNumber=1;
    uID=uID+randomNumber;
    //end of code for generating a random 4-digit ID
	cout << " ---------------------------------------------------------------------------------" << endl;
    cout << "                         #       #####   ######   #####  ######                   " << endl;
    cout << "                        #       #       #        #      #    #                    " << endl;
    cout << "                       #       ####    ######   #      #    #                     " << endl;
    cout << "                      #       #            #   #      #    #                      " << endl;
    cout << "                     ######  #####   ######   #####  ######                       " << endl;
    cout << " ---------------------------------------------------------------------------------" << endl;
    cout << "\t\t==================================================\n";
    cout << "\t\t\t  LAHORE ELECTRIC SUPPLY COMPANY  \n";
    cout << "\t\t==================================================\n\n";
    cout << "\t\t\t----------------------------------\n";
    cout << "\t\t\t||\t  EMPLOYEE PORTAL   \t||\n";
    cout << "\t\t\t||\t    1.Register      \t||\n";
    cout << "\t\t\t||\t    2.Login         \t||\n";
    cout << "\t\t\t||\t    3.Exit          \t||\n";
    cout << "\t\t\t----------------------------------\n";
    ofstream output;
    ifstream input("record.txt"); 	//a sample file for storing recently registered customer
	ifstream Myfile;
	ifstream fin;
    char ch;
	string ID,PW,lgID,lgpass;
	int srch, srch1, sampleuID, sampleID;
	bool idCheck,lgCheck,LoginWhile;
	string usernic;
    while (!0){
    cout << " Enter your choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    cout << endl << " ------------------------------REGISTERATION PORTAL------------------------------" << endl << endl;
		Myfile.open("EmployeesData.txt");
		if (Myfile.is_open()){
        output.open("record.txt");
        cout << "User ID: ";
		srch=uID;
		while (!Myfile.eof()){
		Myfile>>srch1>>usernic;
		if (srch1==srch)
		break;}
		if (srch1==srch){
		while (!0){
        uID=(uID*(rand()%10));
        if (uID==0)
        uID=1000;
        randomID=uID/1000;
        if (randomID>10)
        uID=uID/10;
        sampleuID=uID;
		while (!Myfile.eof()){
		Myfile>>sampleID>>usernic;
		if (sampleuID==sampleID)
		break;}
		if (sampleuID!=sampleID)
		break;}}
		cout << uID << endl;
        cout << "Set a password: ";
        cin >> pass;
        output << uID << " " << pass << endl;
        output.close();
		Myfile.close();
		}
		else{
		output.open("record.txt");
		cout << "User ID: " << uID << endl;
        cout << "Set a password: ";
        cin >> pass;
        output << uID << " " << pass << endl;
        output.close();
		}
        cout << "Registration completed!" << endl << endl ;
        cout << "Your username is: " << uID << "\nYour password is: " << pass << endl << endl;
        cout << "(RUN AGAIN TO CHANGE PASSWORD OF THE REGISTERED ACCOUNT ... THANKS)"<<endl;
        cout << "Press C to change password of any previously registered ID or press any key to continue. ";
        cin >> key;
        if (key=='c' || key=='C')
        	changePassword();
        else
        	employeesUsernameAndPassword();
		cout << "Press any key to continue to login and E to exit  ";
		cin >> key;
		if (key=='e' || key=='E'){
    	cout << "\n--------------------------------\n";
        cout << "APPLICATION TERMINATED \nEXIT successful\n";
        LoginWhile=true;
        break;}
    case 2:
        if (!fin)
        cout << "Error creating file!";
	cout << endl << " ----------------------------------LOGIN PORTAL----------------------------------" << endl << endl;
    while(!0){
    	fin.open("EmployeesData.txt");
		cout << "Enter ID:";
        cin >> lgID;
        cout << "Enter Password:";
        cin >> lgpass;
	if (fin.is_open()){
	while (!fin.eof()){
	fin>>ID>>PW;
	if (ID==lgID){
	idCheck=true;
	break;}}
	if (ID!=lgID){
	idCheck=false;
	cout<<"Sorry, No record found for ID: "<<lgID<<endl;}
	else{
		if (lgID==ID && lgpass==PW){
        cout << "Login successful!" << endl;
        cout << endl;
        lgCheck=true;
        employee();}
        else{
        lgCheck=false;
        cout << "Login failed!\nWrong password." << endl;
        }}
	fin.close();}
	else
	cout<<"Could not open file."<<endl;
        input.close();
	if (idCheck==true && lgCheck==true){
    LoginWhile=true;
	break;}}
    case 3:
    	cout << "\n--------------------------------\n";
        cout << "APPLICATION TERMINATED\nEXIT successful\n";
        LoginWhile=true;
        break;
        default:
        LoginWhile=false;
        cout << " Invalid Choice\n";
    }
    if (LoginWhile==true)
    break;}   
    return 0;
}
