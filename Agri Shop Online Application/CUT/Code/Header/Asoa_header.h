#ifndef ASOA_HEADER_H
#define ASOA_HEADER_H
#define MAX 20


typedef struct farmerDetails
{
        char farmerName[30];
        long int phoneno;
        long long int farmerAadhar;
        int choice;
	int code;
	char category[20];
	char item[4][10];
	int price[4];
	int quantity[4];
        char password[15];
	struct farmerDetails *next;
}ft;


typedef struct farmTemp
{
        char farmerName[30];
        long int phoneno;
        long long int farmerAadhar;
        int choice;
	int code;
	char category[20];
	char item[4][10];
	int price[4];
	int quantity[4];
        char password[15];
        
}ftt;

typedef struct cust_details
{
        char customerName[30];
        long long int customerAadhar;
	long long int phoneno;
	char address[30];
        struct cust_details *next1;
}ct;
typedef struct cust_temp
{
        char customerName[30];
        long long int customerAadhar;
	long long int phoneno;
        char address[30];
}ctt;
typedef struct transaction
{
	long long int farmAadhar;
	long long int custAadhar;
        char product[3][10];
	int quantity2[3];
	int amount[3];
	int cost[3];
	int total_cost;
	int num;
	int qty;
	struct transaction *next2;
}pt;
typedef struct transaction_temp
{
	long long int farmAadhar;
	long long int custAadhar;
        char product[3][10];
	int quantity2[3];
	int amount[3];
	int cost[3];
	int total_cost;
	int num;
	int qty;
}ptt;

ft *start, *new, *ptr, *prev,*last;
ct *start1,*new1,*ptr1,*prev1,*last1;
pt *start2,*new2,*ptr2,*prev2,*last2;

int farmer_menu();
int customer_menu();
int reports_menu();
//functions for farmer menu
int farmer_registration();
int edit_farmer_details();
int show_farmer();

//functions for customer menu
int registration();
int do_transaction();
int edit_customer_details();
int show_customer_details();

//function for admin file maintenance
int delete_farmer_data();
int delete_customer_data();
//functions for report
int farmer_report();
int consolidated_transaction_report();

//files for farmer and customer

int farmer_list();
int list_farmer();
int customer_list();
int list_customer();
int transaction_list();
int list_transaction();

int validate_name(char *);
int validate_aadhar(long long int);
int validate_phoneno(long long int);
int validate_password(char *);
#endif 
