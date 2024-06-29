#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<string.h>


class BankManagementData {
      int accNo;
      char name[25];
	  char Fname[25];
	  char cnic[25];
	  char P_no[25];
	  char email[25];
	  float amount;
	  float newAmount, currentAmount;

      std::fstream accountfile, depositeFile, depositHistoryFile;

      public:
      int search;
   
      void createAccount(void);

      void depositeCash(void);
      void withdrawAmount(void);
      void checkInfo(void);

};

int main(){
    
    BankManagementData BankManagementData;
    char choice;

    std::cout<<"\n\n\n\t\t......:::Abel's Bank:::......";
	std::cout<<"\n\t\t:: press 1 to Login  Account :: ";
	std::cout<<"\n\t\t:: press 2 to Create Account ::";
	std::cout<<"\n\t\t:: press 0 to Exit           ::";
	std::cout<<"\n\t\t:: ......................... ::\n\t\t\t\t";
	std::cin>>choice;



    switch(choice){
        case 1:
           std::cout<<"Please enter your account"<<std::endl;
           std::cin>>BankManagementData.search;
           while (1){
            std::cout<<"\n\n\n\t\t.......:::Abel's Bank:::.......";
            std::cout<<"\n\t\t:: press 1 to Deposit  Amount  :: ";
            std::cout<<"\n\t\t:: press 2 to Withdraw Amount  ::";
            std::cout<<"\n\t\t:: press 3 to Check    Info    ::";
            std::cout<<"\n\t\t:: press 0 to Exit     Menu    ::";
            std::cout<<"\n\t\t:: ........................... ::\n\t\t\t\t";
            std::cin>>choice;

            switch(choice)
            {
                case '1':
                BankManagementData.depositeCash();
                break;

                case '2':
                BankManagementData.withdrawAmount();
                break;

                case '3':
                BankManagementData.checkInfo();
                break;

                default:
                std::cout<<"\nInvalid Choice"<<std::endl;
                system("pause");
            }
           }
           break;
           
       case '2':
            BankManagementData.createAccount();
            break;
        case '0':
            system("exit");
            break;
        default :
            std::cout<<"\n Invalid choice...! ";
        break;

    }
   
};


void BankManagementData::createAccount(){

    srand(time(0));
    accNo = rand()*rand();

    std::cout<<"Enter Your name :: ";
	std::cin>>name;
	
	std::cout<<"Enter Your Father name :: ";
	std::cin>>Fname;

	std::cout<<"Enter Your cnic :: ";
	std::cin>>cnic;
	
	std::cout<<"Enter Your phone no. :: ";
	std::cin>>P_no;
	
	std::cout<<"Enter Your email :: ";
	std::cin>>email;
	
	std::cout<<"Enter Your amount :: ";
	std::cin>>amount;
	
	std::cout<<std::endl<<accNo<<" This is your account number... \n";
	std::cout<<"Please save it \n\n";

    accountfile.open("accountFile.txt",std::ios::out|std::ios::app);
    accountfile<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<cnic<<"\t"<<P_no<<"\t"<<email<<std::endl;
    accountfile.close();
    
};

void BankManagementData::depositeCash(){
    std::cout<<"Enter amount to deposit"<<std::endl;
    std::cin>>newAmount;
    depositeFile.open("depositeFile.txt",std::ios::out|std::ios::app);
    depositHistoryFile.open("depositeFile.txt",std::ios::out|std::ios::app);
    depositHistoryFile<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<P_no<<"\t"<<email<<"\t"<<newAmount<<std::endl;
    
    while(!depositeFile.eof()){
        if(accNo == search){
            std::cout<<"Existing amount...."<<currentAmount<<std::endl;
            currentAmount+=newAmount;
            std::cout<<"Updated amount....."<<currentAmount<<std::endl;
            depositeFile<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<P_no<<"\t"<<email<<"\t"<<newAmount<<std::endl;
        }
    }

    depositeFile.close();
    depositHistoryFile.close();

};

void BankManagementData::withdrawAmount(){
    
	std::cout<<"Enter amount to withdraw :: ";
	std::cin>>newAmount;

	depositeFile.open("depositFile.txt",std::ios::in);
	depositHistoryFile.open("depositHistoryFile.txt",std::ios::out|std::ios::app);
	depositHistoryFile>>accNo>>name>>Fname>>cnic>>P_no>>email>>newAmount;
	
	 while(!depositeFile.eof()){
        if(accNo == search){
            std::cout<<"Existing amount...."<<currentAmount<<std::endl;
            currentAmount+=newAmount;
            std::cout<<"Updated amount....."<<currentAmount<<std::endl;
            depositeFile<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<P_no<<"\t"<<email<<"\t"<<newAmount<<std::endl;
        }
    }
	
	depositeFile.close();
    depositHistoryFile.close();
}
// Defination of checkInfo function
void BankManagementData:: checkInfo(){
    
	
	depositeFile.open("depositeFile.txt",std::ios::in);
	if(!depositeFile){
		std::cout<<"File opening error !";
	};
	while(!depositeFile.eof()){
		if(accNo==search){
            std::cout<<"\n---------------------------\n";
            std::cout<<std::endl<<"\t::: account Number ::: ";
            std::cout<<"\t   "<<accNo<<std::endl;
            std::cout<<"\t::: User Name      ::: ";
            std::cout<<"\t   "<<name<<"\n";
            std::cout<<"\t::: Father Name    ::: ";
            std::cout<<"\t   "<<Fname<<"\n";
            std::cout<<"\t::: CNIC number    ::: ";
            std::cout<<"\t   "<<cnic<<"\n";
            std::cout<<"\t::: Phone Number   ::: ";
            std::cout<<"\t   "<<P_no<<"\n";
            std::cout<<"\t::: Email          ::: ";
            std::cout<<"\t   "<<email<<"\n";
            std::cout<<"\t::: Current amount ::: ";
            std::cout<<"\t   "<<amount<<std::endl;
            std::cout<<"\n---------------------------\n\n";
		
	    }
	};
	
	depositeFile.close();
}