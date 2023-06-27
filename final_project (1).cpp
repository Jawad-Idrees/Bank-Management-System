#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
//#include <windows.h>
//#include<ctime>
//#include<random>
//#include<cmath>
#include <limits>
#include <queue>
#include <limits.h>
#include <windows.h>

using namespace std;


struct bst_node {
	int account_number;
    string customer_name;
    string password;
    string customer_CNIC;
    int customer_age;
    string customer_phone_number;
    string customer_email;
    double account_balance;

    bst_node *right;
    bst_node *left;
};
bst_node *root = NULL;

void bst_insert (int a, string b, string c, string d, int e, string f, string g, double h) {
	bst_node *n = new bst_node;

    n -> account_number = a;
    n -> customer_name = b;
    n -> password = c;
    n -> customer_CNIC = d;
    n -> customer_age = e;
    n -> customer_phone_number = f;
    n -> customer_email = g;
    n -> account_balance = h;

    n -> right = NULL;
    n -> left = NULL;

    if (root == NULL) {
        root = n;
    }
    else {
        bst_node *p = root;
        bst_node *q;
        while (p != NULL) {
            q = p;
            if ((n -> account_number) > (q -> account_number)) {
                p = p -> right;
            }
            else {
                p = p -> left;
            }
        }
        if ((n -> account_number) > (q -> account_number)) {
            q -> right = n;
        }
        else {
            q -> left = n;
        }
    }


}

void preorder (bst_node* root) {
    if (root == NULL)
        return;

    cout << "\t" << root->account_number << "\t\t" << root->customer_name << "\t" << root->customer_CNIC << "\t" << root->customer_age << "\t"
	<< root->customer_phone_number << "\t\t" << root->customer_email << "\t" << root->account_balance << endl;
    preorder( root -> left );
    preorder( root -> right );
}





//int random_generator(){
// srand(time(0));
//
//    return ((1234*rand())^4)%100000;
//}


struct employee_node {
	int employee_id;
    string employee_name;
    string employee_CNIC;
    string employee_email;
    string employee_phone_number;
    string job_title;

    employee_node *right;
    employee_node *left;
};
employee_node *root2 = NULL;

void employee_insert (int a, string b, string c, string d, string e, string f) {
	employee_node *n = new employee_node;

    n -> employee_id = a;
    n -> employee_name = b;
    n -> employee_CNIC = c;
    n -> employee_email = d;
    n -> employee_phone_number = e;
    n -> job_title = f;

    n -> right = NULL;
    n -> left = NULL;

    if (root2 == NULL) {
        root2 = n;
    }
    else {
        employee_node *p = root2;
        employee_node *q;
        while (p != NULL) {
            q = p;
            if ((n -> employee_id) > (q -> employee_id)) {
                p = p -> right;
            }
            else {
                p = p -> left;
            }
        }
        if ((n -> employee_id) > (q -> employee_id)) {
            q -> right = n;
        }
        else {
            q -> left = n;
        }
    }


}

void preorder_employee (employee_node* root) {
    if (root == NULL)
        return;

    cout << "\t" << root->employee_id << "\t" << root->employee_name << "\t" << root->employee_CNIC << "\t" << root->employee_email << "\t"
	<< root->employee_phone_number << "\t\t" << root->job_title << endl;

    preorder_employee( root -> left );
    preorder_employee( root -> right );
}



struct list_node {
	string from;
	string to;
	string withdrawal;
	string deposition;
	string transaction;
	list_node* next;
};
list_node* head2 = NULL;


void insert ( string a, string b, string c, string d, string e ) {
    list_node *n = new list_node;
    n -> from = a;
    n -> to = b;
    n -> withdrawal = c;
    n -> deposition = d;
    n -> transaction = e;
    n -> next = NULL;
    if (head2 == NULL) {
        head2 = n;
    }
    else {
        list_node *temp = head2;
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = n;
    }
}

void display () {
	cout << "\n\tFrom\tTo\tDeposition\tWithdrawal\tTransaction" << endl;
    list_node *temp = head2;
    while (temp != NULL) {
        cout << "\t" << temp -> from << "\t" << temp -> to << "\t" << temp -> deposition << "\t\t" << temp -> withdrawal  << "\t\t"
		<< temp -> transaction << endl;
        temp = temp -> next;
    }
}



bool IsPositivei(int no)
{
    bool y=true;
    if(no<0)
    {

        cout<<"\tYou've Entered a Negative Number. Please Enter a Positive Number.\n";

        y=false;
    }
    return y;
}


int Checkint( )
{
	//cout << "\t";
    int a;
    cin>>a;

    while (!(cin.good()))
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout <<"\tSorry! You can only enter an Integer. \n\t";
        cin>>a;
    }
    if(!(IsPositivei(a)))
    {
      return Checkint();
    }
    return a;
}



void change (int x) {

	bst_node* temp = root;
	bst_node* temp2;

	if (temp -> account_number == x) {
		temp2 = temp;
	}
	else {
		bst_node* p = root;
		bst_node* q;
		while (p != NULL && p->account_number!=x) {
			q=p;
			if (q->account_number > x) {
				p = p->left;
			}
			else
				p =p->right;
		}
		if (p==NULL) {
			cout << "\tAccount does not exists.\n";
			return;
		}
		else
			temp2 = p;
	}




	int choice;
	cout << "\tYou can only change the following: \n\t\t 1. Password\n\t\t 2. Email\n\t\t 3. Phone Number\n\n\tEnter your choice: ";
	cin>>choice;
	switch(choice) {
		case 1: {
			string str;
			cout << "\tEnter the new password: ";
			cin>>str;
			temp -> password = str;
			break;
		}
		case 2:{
			string str;
			cout << "\tEnter the new email: ";
			cin>>str;
			temp -> customer_email = str;
			break;
		}
		case 3:{
			string str;
			cout << "\tEnter the new phone number: ";
			cin>>str;
			temp -> customer_phone_number = str;
			break;
		}
	}
    cout << "\tThe concerned information is changed.\n";
    cout << endl << "\t---------------------------------------------------------------------------------\n";

}


int miniDist(int distance[], bool Tset[]) // finding minimum distance
{
    int minimum=INT_MAX,ind;

    for(int k=0;k<6;k++)
    {
        if(Tset[k]==false && distance[k]<=minimum)
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}

void DijkstraAlgo(int graph[6][6],int src) {
    int distance[6];
    bool Tset[6];

    for(int k = 0; k<6; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;
    }
    distance[src] = 0;

    for(int k = 0; k<6; k++)
    {
        int m=miniDist(distance,Tset);
        Tset[m]=true;
        for(int k = 0; k<6; k++)
        {
            if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }
    cout<<"\n\tBranch\t\tDistance from user"<<endl;
    for(int k = 0; k<6; k++)
    {
        char str=65+k;
        cout<<"\t"<<str<<"\t\t"<<distance[k]<<" km"<<endl;
    }
    cout << endl << "\t---------------------------------------------------------------------------------\n";
}

void admin_options () {
	 bool flag = false;
	   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (!flag) {

    	int choice = 0;

    	cout<<"\n\t1. Print customer information. "<<endl;
        cout<<"\t2. Print employee information. "<<endl;
       	cout<<"\t3. View Branch activity. "<<endl;
       	cout<<"\t4. Change customer's personal information. "<<endl;
       	cout<<"\t5. Branch information. "<<endl;
       	cout << "\t0. Exit " << endl;
       	cout<< "\tSelect an option:";

		//cin>>choice;
		choice = Checkint();


		if (choice == 0) {
			flag = true;
		}

		else if (choice == 1) {
            cout << endl << "\t---------------------------------------------------------------------------------\n";
			cout << "\tAccount Number\tName\tCNIC\tAge\tPhone Number\tE-mail\t\tBalance\n";
			preorder(root);
            cout << endl << "\t---------------------------------------------------------------------------------\n";
		}
		else if (choice == 2) {
			cout << endl;
            cout << endl << "\t---------------------------------------------------------------------------------\n";
			cout << "\tID\tName\tCNIC\tE-mail\t\tPhone Number\tJob Title" << endl;
			preorder_employee(root2);
            cout << endl << "\t---------------------------------------------------------------------------------\n";
		}
		else if (choice == 3) {
            cout << endl << "\t---------------------------------------------------------------------------------\n";
			display();
        	cout << endl << "\t---------------------------------------------------------------------------------\n";
		}
		else if (choice == 4) {
			cout << endl;
			cout << "\tEnter the account number: ";
			int x;
			x = Checkint();
			//cin>>x;
			change(x);
		}
		else if (choice == 5) {

                cout << endl << "\t---------------------------------------------------------------------------------\n";
                cout << "\n\tThere are a total of six branches (0->5):";
                cout << "\n\tEnter the branch of which you want to find the shortest distance of: ";
                int branch;
                cin>>branch;

                int graph[6][6]={
                {0, 1, 2, 0, 0, 0},
                {1, 0, 0, 5, 1, 0},
                {2, 0, 0, 2, 3, 0},
                {0, 5, 2, 0, 2, 2},
                {0, 1, 3, 2, 0, 1},
                {0, 0, 0, 2, 1, 0}};
                DijkstraAlgo(graph,branch);


		}
		else {
			cout << " \tInvalid choice.\n\tEnter the correct option: ";
		}

	}
}


void admin_login(){
	int admin_id; string password; int a=0; int b;
	while(true){

	cout<<"\n\tEnter your Admin ID: ";
	cin>>admin_id;
	cout<<"\tEnter your password: ";
	cin>>password;

	if(admin_id==123 ) {
		if(password=="123") {
			cout<<"\tLogin successful"<<endl;
			cout << endl << "\t---------------------------------------------------------------------------------\n";
			a=1;
			break;

		}
		else cout<<"\tIncorrect password!"<<endl;
	}
	else {
		cout<<"\tIncorrect Admin ID!"<<endl;
		cout<<"\tEnter: "<<endl;
		cout<<"\t1. To Retry"<<endl;
		cout<<"\tEnter any other digit to exit: ";
		cin>>b;
		if(b==1) continue;
		else break;
	}

	}


     if(a==0) return;
     else;
    // Call module for admin functions
    admin_options();

}




void customer_signup(){string name; string CNIC; string email;int age;  long ph_no; int acc_num; int balance;string password;
	cout<<"\tEnter your name: "<<endl;
	cin>>name;
	cout<<"\tEnter your CNIC: "<<endl;
	cin>>CNIC;
	cout<<"\tEnter your Email: "<<endl;
	cin>>email;
	cout<<"\tEnter your Phone number: "<<endl;
	cin>>ph_no;
	cout<<"\tEnter your age: "<<endl;
	cin>>age;
	cout<<"\tEnter your account opening balance: "<<endl;
	cin>>balance;
	cout<<"\tSet a password for your account: "<<endl;
	cin>>password;
	//acc_num=random_generator();
	acc_num=1111;
	cout<<"\tSuccessfully Registered!\n\n "<<endl;
	cout<<"\tYour Account Number is: "<< acc_num;



	// Call for insert() function


}



bool search(bst_node* root, int acc, string pass) {
	if(root==NULL) return false;
	else if(acc<root->account_number)
	 return search(root->left,acc,pass);
	else if(acc>root->account_number)
	return search(root->right,acc,pass);
	else{
	// acc matches account number of current root. Time to match password
		if(pass==root->password)
		// Account number and password both matched
		return true;
		else
		// Incorrect password
		return false;
	}

}


bst_node* s (bst_node*root, int x) {
	bst_node* temp;
	if (root == NULL) {
		cout << "The account does not exists.\n";
	}
	else if (x < root -> account_number) {
		root->left = s(root->left, x);
	}
	else if (x > root -> account_number) {
		root->right = s(root->right, x);
	}
	else {
		temp = root;
	}
	return temp;
}


void view (bst_node* root) {
	cout << endl << "\tAccount Number: " << root->account_number << "\n\tName: " << root->customer_name << "\n\tCNIC: " << root->customer_CNIC <<
			"\n\tAge: " << root->customer_age << "\n\tPhone Number: "	<< root->customer_phone_number << "\n\tE-mail: " << root->customer_email <<
			 "\n\tAccount Balance: $" << root->account_balance << endl;
}



void gasBill(){
    cout<<"\tEnter your Account Number"<<endl;
    int AccountNumber;
    cin>>AccountNumber;
    bst_node* currentNode = s(root, AccountNumber);
    if(currentNode == NULL){
        cout<<"\tWrong Account Number"<<endl;
        return;
    }
    cout<<"\tHow Much is your bill: "<<endl;
    int amount;
    cin>>amount;
    if(currentNode ->account_balance > amount){
        currentNode->account_balance -= amount;
        cout<<"\tGas bill was paid successfully. "<<endl;
        return;
    }else{
        cout<<"\tYou do not have sufficient Balance. "<<endl;
    }
}
void electricityBill(){
    cout<<"\tEnter your Account Number: "<<endl;
    int AccountNumber;
    cin>>AccountNumber;
    bst_node* currentNode = s(root, AccountNumber);
    if(currentNode == NULL){
        cout<<"\tWrong Account Number. "<<endl;
        return;
    }
    cout<<"\tHow Much is your bill: "<<endl;
    int amount;
    cin>>amount;
    if(currentNode ->account_balance > amount){
        currentNode->account_balance -= amount;
        cout<<"\tYou successfully paid the Electricity bill. "<<endl;
        return;
    }else{
        cout<<"\tYou do not have sufficient Balance. "<<endl;
    }
}
void phoneBill(){
    cout<<"\tEnter your Account Number: "<<endl;
    int AccountNumber;
    cin>>AccountNumber;
    bst_node* currentNode = s(root, AccountNumber);
    if(currentNode == NULL){
        cout<<"\tWrong Account Number. "<<endl;
        return;
    }
    cout<<"\tHow Much is your bill: "<<endl;
    int amount;
    cin>>amount;
    if(currentNode ->account_balance > amount){
        currentNode->account_balance -= amount;
        cout<<"\tYou successfully paid the Phone bill. "<<endl;
        return;
    }else{
        cout<<"\tYou do not have sufficient Balance. "<<endl;
    }
}
void ptclBill(){
    cout<<"\tEnter your Account Number: "<<endl;
    int AccountNumber;
    cin>>AccountNumber;
    bst_node* currentNode = s(root, AccountNumber);
    if(currentNode == NULL){
        cout<<"\tWrong Account Number. "<<endl;
        return;
    }
    cout<<"\tHow Much is your bill: "<<endl;
    int amount;
    cin>>amount;
    if(currentNode ->account_balance > amount){
        currentNode->account_balance -= amount;
        cout<<"\tYou successfully paid the PTCL bill. "<<endl;
        return;
    }else{
        cout<<"\tYou do not have sufficient Balance. "<<endl;
    }
}




void billPay(){
    cout<<"\n\t1. Gas Bill\n"
    "\t2. Electricity Bill\n"
    "\t3. Phone Bill\n"
    "\t4. PTCL Bill"<<endl;
    int option;
    cout << "\tEnter your option: ";
    cin>>option;
    switch (option){
    case 1:
        gasBill();
        break;
    case 2:
       electricityBill();
        break;
    case 3:
        phoneBill();
        break;
    case 4:
        ptclBill();
        break;
    default:
        cout<<"\tWrong Input"<<endl;
        break;
    }
}


void feePay(){
    cout<<"\tEnter your Account Number"<<endl;
    int AccountNumber;
    cin>>AccountNumber;
    bst_node* currentNode = s(root, AccountNumber);
    if(currentNode == NULL){
        cout<<"\tWrong Account Number"<<endl;
        return;
    }
    cout<<"\tHow Much is your Fee"<<endl;
    int amount;
    cin>>amount;
    if(currentNode ->account_balance > amount){
        currentNode->account_balance -= amount;
        cout<<"\tFee was paid successfully. "<<endl;
        return;
    }else{
        cout<<"\tYou do not have sufficient Balance."<<endl;
    }
}
void moneyTransfer(){
    cout<<"\tEnter your Account Number: "<<endl;
    int AccountNumber;
    cin>>AccountNumber;
    bst_node* ownAccount = s(root, AccountNumber);
    if(ownAccount == NULL){
        cout<<"\tWrong Account Number. "<<endl;
        return;
    }
    cout<<"\tEnter Recevier Account: "<<endl;
    int accountReceiver;
    cin>>accountReceiver;
    bst_node* receiverAccount = s(root, accountReceiver);
    if(receiverAccount == NULL){
        cout<<"Wrong Account Number. "<<endl;
        return;
    }
    cout<<"\tEnter the amount: "<<endl;
    int amount;
    cin>>amount;
    if(ownAccount ->account_balance > amount){
        ownAccount->account_balance -= amount;
        receiverAccount->account_balance += amount;
        cout<<"\tSuccessfully Transfer Money. "<<amount<<endl;
        return;
    }else{
        cout<<"\tYou do not have sufficient Balance. "<<endl;
    }
}
void depositMoney(){
    cout<<"\tEnter your Account Number: "<<endl;
    int AccountNumber;
    cin>>AccountNumber;
    bst_node* ownAccount = s(root, AccountNumber);
    if(ownAccount == NULL){
        cout<<"\tWrong Account Number. "<<endl;
        return;
    }
    cout<<"How much money would you like to transfer: "<<endl;
    int amount;
    ownAccount->account_balance += amount;
    cout<<"\tDeposition was successful. "<<endl;
}
void withdrawMoney(){
    cout<<"\tEnter your Account Number: "<<endl;
    int AccountNumber;
    cin>>AccountNumber;
    bst_node* ownAccount = s(root, AccountNumber);
    if(ownAccount == NULL){
        cout<<"\tWrong Account Number. "<<endl;
        return;
    }
    cout<<"\tEnter the amount: "<<endl;
    int amount;
    cin>>amount;
    if(ownAccount ->account_balance > amount){
        ownAccount->account_balance -= amount;
        cout<<"\tWithdrawal was successful. "<<endl;
        return;
    }else{
        cout<<"\tYou have no sufficient Balance. "<<endl;
    }
}


void customer_functions (int acc) {

	bool f = false;
	while (!f) {

		cout << "\n\tCustomer Menu\n";
		cout<<"\t1. View Your Data\n"
    	"\t2. Bill pay\n"
	    "\t3. Fee Pay\n"
    	"\t4. Money Tranfer\n"
    	"\t5. Deposit Money\n"
    	"\t6. WithDraw Money"<<endl;
    	cout << "\tEnter 0 to exit\n";
    	cout << "\n\tEnter your option: ";
    	int option = 0;

		bool flag = false;
		while (!flag) {
			cin>>option;
			if (option==1||option==2||option==3||option==4||option==5||option==6||option==0) {
				flag = true;
			}
			if (flag == false)
				cout << "\tEnter a valid choice: ";
		}

		if (option == 0) {
			f=true;
		}

		else if (option == 1) {
			bst_node* temp = s(root, acc);
			cout << "\t-------------------------\n";
			view(temp);
			cout << "\n\t-------------------------\n";
		}
		else if (option == 2) {
			billPay();
		}
		else if (option == 3) {
		feePay();
		}
		else if (option == 4) {
			moneyTransfer();
		}
		else if (option == 5) {
			depositMoney();
		}
		else if (option == 6) {
			withdrawMoney();
		}

	}


}


void customer_login(){
	int a = 0;
	int acc;
	while(true){
		 string password; int b;

		cout<<"\n\tEnter your Account Number: ";
		cin>>acc;
		cout<<"\tEnter your password: ";
		cin>>password;
		bool login=search(root, acc, password);

	if(login) {
		cout<<"\tLogin successful"<<endl;
		cout << endl << "\t---------------------------------------------------------------------------------\n";
		a=1;
		break;
	}
	else
		{
		cout<<"\tIncorrect Account Number or Password!\n"<<endl;
		int b;
		cout<<"\tEnter: "<<endl;
		cout<<"\t1. To Retry"<<endl;
		cout<<"\tEnter any other digit to exit"<<endl;
		cin>>b;
	if(b==1)
		continue;
	else
		break;
	}
	}
     if(a==0) return;
     else
     	customer_functions(acc);
    // Call module for cutomer functions

}


void sign_up (){
	  bst_node * newNode = new bst_node();
    newNode->account_number = 1111;
    //newNode->account_number = random_generator();
    std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cout<<"\n\tEnter Customer Name: ";
    getline(cin,newNode->customer_name);
    cout<<"\tEnter PassWord for Account: ";
    getline(cin,newNode->password);
    cout<<"\tEnter Customer CNIC: ";
    getline(cin,newNode->customer_CNIC);
    cout<<"\tEnter Customer Age: ";

    cin>>newNode->customer_age;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<"\tEnter Customer Phone Number: ";
    getline(cin,newNode->customer_phone_number);
    cout<<"\tEnter Customer Email: ";
    getline(cin,newNode->customer_email);

    cout << "\tEnter the amount you want to deposit(A minimum of 100 Rs): ";
	bool flag = false;
	while (!flag) {
		int amount;
    	cin>>amount;
    	if (amount>=100) {
    		newNode->account_balance = amount;
            flag = true;
		}
		else {
			cout<<"\tYou Enter Wrong Amount."<<endl;
            cout<<"\tEnter Right Amount: ";
		}
	}


    bst_insert(newNode->account_number,newNode->customer_name,newNode->password,
    newNode->customer_CNIC,newNode->customer_age,newNode->customer_phone_number,
    newNode->customer_email,newNode->account_balance);
    cout << "\tYour account has been created.\n";
    int x = newNode->account_number;
    //customer_functions(newNode->account_number);

}




void customer_option() {
	int a;
	cout << endl << "\t---------------------------------------------------------------------------------\n";
	//cout<<"\n\tEnter"<<endl;
	cout<<"\n\t1. For Login "<<endl;
	cout<<"\t2. For Sign up"<<endl;
	cout << "\tSelect an option: ";

	bool flag = false;
	while (!flag) {
		cin>>a;
		if (a==1||a==2) {
			flag = true;
		}
		if (flag==false)
			cout << "\tEnter a valid choice: ";
	}
	if(a==1)
		customer_login();
	else if (a==2)
		sign_up();


}


int main () {

    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, 11);


	ifstream fin;
    fin.open("demo.csv");
    string line, word;
    vector<string> lineData;
    int lines = 0;

    while(!fin.eof()){
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,',')){
            lineData.push_back(word);
        }

        stringstream s1(lineData[0]);
        int account_number;
        s1>>account_number;

        stringstream s2(lineData[4]);
        int age;
        s2>>age;

        stringstream s3(lineData[7]);
        double balance;
        s3>>balance;

        if(lines!=0)
        {
        	bst_insert(account_number, lineData[1], lineData[2], lineData[3], age, lineData[5], lineData[6], balance);
        }

        lineData.clear();
        lines++;
    }





    ifstream fin2;
    fin2.open("employee.csv");
    string line2, word2;
    vector<string> lineData2;
    int lines2 = 0;

    while(!fin2.eof()){
        getline(fin2,line2);
        stringstream s(line2);
        while(getline(s,word2,',')){
            lineData2.push_back(word2);
        }

        stringstream ss(lineData2[0]);
        int id;
        ss>>id;

        if(lines2!=0)
        {
        	employee_insert(id, lineData2[1], lineData2[2], lineData2[3], lineData2[4], lineData2[5]);
        }

        lineData2.clear();
        lines2++;
    }


    ifstream fin3;
    fin3.open("bank_activity.csv");
    string line3, word3;
    vector<string> lineData3;
    int lines3 = 0;

    while(!fin3.eof()){
        getline(fin3,line3);
        stringstream s3(line3);
        while(getline(s3,word3,',')){
            lineData3.push_back(word3);
        }

        if(lines3!=0)
        {
        	insert(lineData3[0], lineData3[1], lineData3[2], lineData3[3], lineData3[4]);
        }

        lineData3.clear();
        lines3++;
    }


	cout<<"\n\t\t\t************************************\n";
    cout<<" \t\t\t\tBANK MANAGEMENT SYSTEM \n";
    cout<<"\t\t\t************************************\n";


	int choice;
	do {
		cout<<" \n\tEnter: "<<endl;
		cout<<" \t1. Admin"<<endl;
		cout<<" \t2. Customer"<<endl;
		cout << "\tPress 0 to exit!" << endl << "\t--> ";
		//cin >> choice;

		choice = Checkint();
		switch (choice) {
			case 1:
				admin_login();
				break;
			case 2:
				customer_option();
				break;
			default:
				cout << "\tPlease enter from among the choices!\n";
		}
	}
	while(choice!=0);









	return 0;
}


