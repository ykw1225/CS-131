
//David Humphreys
//Josh Christensen
//Kit Wong
//Ayaka Takada
//July 7th 2014
//Hotel Program
/*This is a sample Hotel Operation Program. Upon conpletion the program will 
give hotel staff the ability to make reservations, check guests in and out,
and view important hotel information(i.e. clean/dirty rooms and a guest listing)*/

// Verified Working Build -- 10:46PM 7/21 ---> removed unused code, cleaned some parts of code

#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<cstdlib>
using namespace std;
void set_d_r(int &, int &);
void case1();
void case2();
void case3();
void case4();
void case5();
void case6();

const unsigned int rangeVal_month = 12;



//~~~  Main Function Start~~~//
int main()
{
	int menu_selection;

	do
	{
		//Menu Selection
		cout << "-----Hotel Menu-----\n\n"
			<< "1. Arrivals\n"
			<< "2. Departures\n"
			<< "3. Temp Room Hold\n"
			<< "4. Guest Listing\n"
			<< "5. New Reservation\n"
			<< "6. Room Condition\n" 
			<< "7. Quit\n" 
			<< "\nEnter Option #: ";
		cin >> menu_selection;
		cout << "\n" << endl;

		//If-else-if cases.//Just change to switch(Kit)
		if(menu_selection==1) case1();
			break;
		case 2: case2();
			break;
		case 3: case3();
			break;
		case 4: case4();
			break;
		case 5: case5();
			break;
		case 6: case6();
			break;
		default:
			cout << "\nInvalid number.\n";
		} while (menu_selection != 7);

		cout <<"Good bye!\n";
		
		system("PAUSE");
		return 0;
	}
}



void set_d_r(int &month, int &year) //this is a function that can set the range of day depend on the month........
{
	static int rangeVal_day, rangeVal_nights;

	if (month == 4 || month == 6 || month == 9 || month == 11) //if current month is 4/6/9/11
	{
		rangeVal_day = 30; //sign the date range of current month as 30
		rangeVal_nights = 31; //sign the date range of next month as 31
	}
	else if (month == 3 || month == 5 || month == 8 || month == 10) //if current month is 3/5/8/10
	{
		rangeVal_day = 31; //current month
		rangeVal_nights = 30; //next month
	}
	else if (month == 7 || month == 12 ) //if current month is 7/12
	{
		rangeVal_day = 31; //current month
		rangeVal_nights = 31; //next month
	}
	else if (month ==1)
	{
		rangeVal_day = 31; //current month
		//next month
		if (year%4 == 0 && year%100 == 0 && year%400 == 0) 
			rangeVal_nights = 29;
		else if (year%4 == 0 && year%100 == 0 && year%400 != 0) 
			rangeVal_nights = 28;
		else if (year%4 == 0 && year%100 != 0)
			rangeVal_nights = 29;
		else      
			rangeVal_nights = 28; // year%4 != 0*/
	}
	else //checkOut_month_calc == 2
	{
		//current month
		if (year%4 == 0 && year%100 == 0 && year%400 == 0)
			rangeVal_day = 29;
		else if (year%4 == 0 && year%100 == 0 && year%400 != 0)
			rangeVal_day = 28;
		else if (year%4 == 0 && year%100 != 0)
			rangeVal_day = 29;
		else // year%4 != 0*/
			rangeVal_day = 28; 
		//next month
		rangeVal_nights = 31; 
	}
}

void case1()
{
	int submenu_selection;
	/*------ BEGIN ARRIVALS ----- */
	cout << "---------ARRIVALS--------\n\n" << endl; 
	cout << "Please select from one of the following options:\n\n1) Confirm arrival\n2) Cancel arrival\n\nYour choice: "; // Arrivals Selection Menu
	cin >> submenu_selection;

	while(submenu_selection != 1 && submenu_selection != 2) // Handles bad user input
	{
		cout << "ERROR: Invalid input. Please select a numeric value from the menu.\n\n";
		cout << "Please select from one of the following options:\n\n1) Confirm arrival\n2) Cancel arrival\n\nYour choice: ";
		cin >> submenu_selection;
	}
	if( submenu_selection == 1) // Confirmation screen for guest arriving at hotel
	{
		int submenu_1a_selection;
		cout << "ARRIVALS > CONFIRM ARRIVAL\n\n"
			<<"Select confirmation method:\n"
			<<"1) Reservation ID\n2) Guest Last Name\n3)Reservation Start Date\n4) Reservation Date End\n\n"
			<<"Your selection: ";
		cin >> submenu_1a_selection;
		while(submenu_1a_selection < 1 && submenu_1a_selection > 4) // bad menu input handling
		{
			cout << "ERROR: Invalid input. Please select a numeric value from the menu.\n\n";
			cout << "ARRIVALS > CONFIRM ARRIVAL\n\n"
				<<"Select confirmation method:\n"
				<<"1) Reservation ID\n2) Guest Last Name\n3)Reservation Start Date\n4) Reservation Date End\n\n"
				<<"Your selection: ";
		}

		/* BEGIN ARRIVAL CONFIRMATION MENU*/

		//menu options 1-4
		//grab data from arrays based on input type
		//check status of isRoomClean, trigger alert if false, make up excuse to tell impatient guest, consider hiring new housekeeping staff
		//if isRoomClean is true, confirm arrival, housekeeping staff retains employment security

		/* END ARRIVAL CONFIRMATION MENU*/
	}
	system ("pause");
}

void case2()
{
	/* ---------- BEGIN DEPARTURES ---------- */
	
	// This assumes that guest departures will always be happening on the day of as they leave,
	// and that we have no way of checking local system to get the date

	cout << "-------DEPARTURES------\n\n" << endl;
	cout << "Enter today's date: ";
	//date input and confirmation

	cout << "Enter room number: ";
	
	// Search arrays by room number
	// find where today's date >= check in date and <=checkout date
	// If today's date < checkout date, verify today's date, adjust charges
	// clear any "no maid please" flags for cleaning

	system ("pause");
}

void case3()
{
	unsigned int holdRoomNum;
	// "Temp Room Hold"
	cout << "Enter room number for temporary hold: ";
	cin >> holdRoomNum;
	cout << "Temporary hold placed.\n\n";
}

void case4()
{
	// "Guest Listing" -- Will hold guest information for later use, needs arrays
	cout << "***Guest Listing***\n\n";
}

void case5()
{
	int Zip, Phone, CC_Number, Street_Address, City, State, arrivalConfirm, departureConfirm, DayID = 0,room_req;
	const float price_per_room_per_night = 155.55, deposit = 500;
	float tax, total, price_notax;
	char Last_Name[50], First_Name[50], Title[10];
	unsigned int room_num, confirm_num, floor, door_num, nights_r = 0,  rooms = 1, floor_M = 21, floor_m = 0, door_num_d = 21;
	bool isLeap, isLeap_calc, isRequest;
	unsigned int seed = time(NULL);
	srand(seed);//just used for creating a random number
	confirm_num = rand() % 99999999;

	unsigned int nights, checkIn_month, checkIn_day, checkIn_year,  rangeVal_day, rangeVal_nights, rangeVal_feb, checkOut_month, checkOut_day, checkOut_year, checkOut_day_calc, dd_rem, checkOut_month_calc, mrangeVal_monthem, checkOut_year_calc;     
	//"in" means check in, "r" means range, "out" means check out, "nights" means how many nights they will stay, "rem" means remain

	/*------------- Begin New Reservation (Option 5) ----------------*/

	cout << "----New Reservation Screen----\n" << endl;
	cout << "Title (Mr, Mrs, Ms, Dr, etc): " << endl;
	cin >> Title;
	cout << "\n" << endl;
	cout << "Last Name: " << endl;
	cin >> Last_Name;
	cout << "\n" << endl;
	cout << "Enter checkin date. (checkOut_month_calc checkOut_day_calc yyyy): " << endl; //check in date input (sepreate by space)
	cin >> checkIn_month >> checkIn_day >> checkIn_year;   //storage date sepreatly into three variables
	cout << "\n" << endl;

	checkOut_month_calc = checkIn_month;
	checkOut_year_calc = checkIn_year;

	set_d_r(&checkOut_month_calc,&checkOut_year_calc);    //this is the day range setting fuction 

	while (checkIn_month*checkIn_day==0 || checkIn_month>rangeVal_month || checkIn_day>rangeVal_day)   //check if there is any error of input
	{
		cout << "Wrong date input! Enter again. (checkOut_month_calc checkOut_day_calc yyyy): " << endl;
		cin >> checkIn_month >> checkIn_day >> checkIn_year;
		checkOut_month_calc = checkIn_month;
		checkOut_year_calc = checkIn_year;
		cout << "\n" << endl;
		set_d_r(&checkOut_month_calc,&checkOut_year_calc);     //this is the day range setting fuction 
	}
	
	cout << "How many nights will be staying: " << endl;
	cin >> nights;
	cout << "\n" << endl;

	while (nights<=0)
	{
		cout << "Wrong input! Enter again: " << endl;
		cin >> nights;
		cout << "\n";
	}


	cout << "Specific Room Requeste:?\n1) Yes\n2) No\n\nYour Choice: ";
	cin >> room_req; // <--- handles customer request for specific room or VIP suite

	while (room_req != 1 && room_req != 2) // handles non-y/n user inputs
	{
		cout << "ERROR: Invalid input\n\nSpecific Room Requested?\n\n1) Yes\n2) No\n\nYour Choice: ";
		cin >> room_req;
	}

	if (room_req == 1)
	{
		isRequest = 1;
		cout << "Please enter desired floor. [1-20]: " << endl; 
		cin >> floor;
		cout << "\n" << endl;

		while (floor >= floor_M || floor <= floor_m)
		{
			cout << "The number you entered is not from 1 to 20. Please Enter again: " << endl;
			cin >> floor;
			cout << "\n" << endl;
		}

		cout << "Please enter desired room number. [0-20]: " << endl;
		cin >> door_num;
		cout << "\n" << endl;

		while (door_num >= door_num_d)
		{
			cout << "The number you entered is not from 0 to 20. Please Enter again: " << endl;
			cin >> door_num;
			cout << "\n" << endl;
		}

		room_num = floor * 100 + door_num;
		cout << "Room #: " << room_num;
	}

	else
	{
		isRequest = 0;
		floor = rand() % 20 + 1;
		door_num = rand() % 21;
		room_num = floor * 100 + door_num;
		cout << "Room #: " << room_num;
	}

	/* ---------- BEGIN DATE CONFLICT CHECKER ---------- */

	while (checkIn_month*checkIn_day==0 || checkIn_month>rangeVal_month || checkIn_day>rangeVal_day)   //check if there is any error of input
	{
		cout << "Wrong date input! Enter again. (checkOut_month_calc checkOut_day_calc yyyy): " << endl;
		cin >> checkIn_month >> checkIn_day >> checkIn_year;
		checkOut_month_calc = checkIn_month;
		checkOut_year_calc = checkIn_year;
		cout << "\n" << endl;
		set_d_r(&checkOut_month_calc,&checkOut_year_calc);     //this is the day range setting fuction 
	}

	cout << "How many nights will be staying: " << endl;
	cin >> nights;
	cout << "\n" << endl;

	while (nights<=0)
	{
		cout << "Wrong input! Enter again: " << endl;
		cin >> nights;
		cout << "\n" << endl;
	}


	/*Calculation for price*/

	price_notax = price_per_room_per_night * nights * rooms;
	tax = price_notax * 0.095;
	total = price_notax + tax + deposit;

	//this is the checkout date calculator

	checkOut_day_calc = checkIn_day + nights;
	while (checkOut_day_calc > rangeVal_day)
	{
		checkOut_month_calc += 1;
		dd_rem = checkOut_day_calc-rangeVal_day;
		checkOut_day_calc = dd_rem;
		while (checkOut_month_calc > rangeVal_month)
		{
			mrangeVal_monthem = checkOut_month_calc - rangeVal_month;
			checkOut_month_calc = mrangeVal_monthem;
			checkOut_year_calc += 1;
		}
		set_d_r(&checkOut_month_calc,&checkOut_year_calc);
	}
	checkOut_day = checkOut_day_calc;
	checkOut_month = checkOut_month_calc;
	checkOut_year = checkOut_year_calc; 


	/*Place holder for room availability checker logic*/

	cout << "\n" << endl;
	cout << "-----------------------------------" << endl;
	cout << "Room ";
	cout << setw(4) << setfill('0') << room_num;
	cout << " reserved for " << Title << ". " << Last_Name << endl; //Reservation confirmation
	cout << "-----------------------------------" << endl;
	cout << "Check in: " << checkIn_month << " / " << checkIn_day << " / " << checkIn_year << endl;    //show checkin date
	cout << "Check out: " << checkOut_month << " / " << checkOut_day << " / " << checkOut_year << endl;     // show checkout date
	cout << endl;
	cout << "Stay " << nights << " nights." << endl;
	cout << "-----------------------------------" << endl;
	cout << setfill(' ') << fixed << setprecision(2) << showpoint;
	cout << setw(20) << left << "Price of room: ";
	cout << right << price_notax << endl;
	cout << setw(20) << left << "Tax: ";
	cout << right << tax << endl;
	cout << setw(20) << left << "Deposit: ";
	cout << right << deposit << endl;
	cout << setw(20) << left << "Total: ";
	cout << right << total << endl;
	cout << endl;

	cout << "Confirmation #: ";
	cout << setw(8) << setfill('0') << confirm_num << endl;
	cout << "-----------------------------------" << endl;
	cout << "\n" << endl;
/*------------- End New Reservation (Option 5) ----------------*/
}

void case6()
{
	// "Room Condition" -- will be a list of all the rooms and weather they are clean or not
	cout << "***Room Condition***" << endl;
	cout <<" (here's just a printed example)" << endl;
	cout << "Room 100: Clean\n" << "Room 101: Clean\n" << "Room 102: Clean\n" << "Room 103: Clean\n" << "Room 104: Clean\n" << "Room 105: Clean\n" << "And so on...\n" << endl;
}