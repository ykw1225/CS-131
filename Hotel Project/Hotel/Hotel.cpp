
//David Humphreys
//Josh Christensen
//Kit Wong
//Ayaka Takada
//Hotel Program

/*This is a sample Hotel Operation Program. Upon conpletion the program will 
give hotel staff the ability to make reservations, check guests in and out,
and view important hotel information(i.e. clean/dirty rooms and a guest listing)*/


// I just update the newest version I modified. I re-organized by using some function and cleaning up some bug there.
// I added file input/output in Guestlisting. (Ayaka) I am not testing how it works yet.
// it may be better to have function do mostly just simpler jobs, not have each menu be a function to itself
//I added input and output file function in 4, Guestlisting. I believe we haven't learned how to add data without overwriting. 
//So now I just can add data at the time and will be overwritten. (Ayaka)
// 7/28 01:36 AM >>>>>Just orgainized some stuff and fixed some bugs.
// 8/06 08:27 PM >>>>>Made an other menu selection about controlling the information of rooms.
// 8/06 8:33 Very cool. I had some similar stuff going in visual studio, but I'm going to see if I can't turn some of your stuff into functions to resuse
//8/6 09:00PM In Room Condition (choice 6), I added array. Also I added exit(0). So the user can terminate the programm after putting or checking room conditions. (Ayaka)
// 8/06 09:38 PM >>>>>Just checked the whole program if there are any bugs. I think the part that Ayaka made and the part that I made can combine together because it is similar.
// 8/12 10:26 PM >>>>Just add some new function with pointer.(KIT)

#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;
int leapyear(int,int);
void InvalidValue(int*,int,int);
void InvalidValue(float*,int,int);
void InvalidValue(double*,int,int);
void initialize(string [9][10]);
void set_d_r(int,int,int*,int*);
void checkOutDate(int, int, int, int, int*, int*, int*, int*, int*, int=0);
int convert_calendar_to_integer(int, int, int); //prototype, for date adjuster function(discription at function header)
void RoomNumberInitial(int **,int,int);
int **FreeMemo(int,int);
int *FreeMemo(int);
void case1();
void case2();
void case3();
void case4();
void case5();
void case6();
void case7();

const unsigned int rangeVal_month = 12;


//~~~  Main Function Start~~~//
int main()
{
        int menu_selection;
        do
        {
                //Menu Selection
                cout << "\n-----Hotel Menu-----\n\n"
                        << "1. Arrivals\n"
                        << "2. Departures\n"
                        << "3. Temp Room Hold\n"
                        << "4. Guest Listing\n"
                        << "5. New Reservation\n"
                        << "6. Room Condition\n" 
                        <<"7. Information Controler\n"
                        << "8. Quit\n" 
                        << "\nEnter Option #: ";
                cin >> menu_selection;
                
                //Just change to switch(Kit)
                switch (menu_selection)
                {
                case 1: case1();
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
                case 7: case7();
                        break;
                case 8:;
            break;
                default: cout << "Invalid number!!!!!!!!!!!!!!!\n\n";
                }
        }while (menu_selection != 8);
        cout <<"Good bye!\n\n";
        system("PAUSE");
        return 0;
}

void initialize(string a[9][10]) //This function for initialize the information as NONE
{
        for(int i=0;i<9;i++)
                for(int j=0;j<10;j++)
                        a[i][j]="NONE";
}

int leapyear(int year, int range)     // I separated a new function that check the leap year from the set_d_r function for make it shorter.
{
        if (year%4 == 0 && year%100 == 0 && year%400 == 0) 
                range = 29;
        else if (year%4 == 0 && year%100 == 0 && year%400 != 0) 
                range = 28;
        else if (year%4 == 0 && year%100 != 0)
                range = 29;
        else  
                range = 28;
        return range;
}

void set_d_r(int month, int year, int *rangDay, int *rangNights) //this is a function that can set the range of day depend on the month........
{
        if (month == 4 || month == 6 || month == 9 || month == 11) //if current month is 4/6/9/11
        {
                *rangDay = 30; //sign the date range of current month as 30
                *rangNights = 31; //sign the date range of next month as 31
        }
        else if (month == 3 || month == 5 || month == 8 || month == 10) //if current month is 3/5/8/10
        {
                *rangDay = 31; //current month
                *rangNights = 30; //next month
        }
        else if (month == 7 || month == 12 ) //if current month is 7/12
        {
                *rangDay = 31; //current month
                *rangNights = 31; //next month
        }
        else if (month == 1)
        {
                *rangDay = 31; //current month
                *rangNights = leapyear(year,*rangNights);  //next month
        }
        else //checkOut_month_calc == 2
        {
                *rangDay = leapyear(year,*rangDay); //current month
                *rangNights = 31;  //next month
        }
}

void checkOutDate(int inday, int daycal, int moncal, int yearcal, int * rangDay, int * rangNight, int *outday, int *outmon, int *outyear, int nights)
{
    // This is the checkout date calculator
        int dd_rem, mrangeVal_monthem;
        daycal = inday + nights;
        while (daycal > *rangDay)
        {
                moncal += 1;
                dd_rem = daycal-*rangDay;
                daycal = dd_rem;
                while (moncal > rangeVal_month)
                {
                        mrangeVal_monthem = moncal - rangeVal_month;
                        moncal = mrangeVal_monthem;
                        yearcal += 1;
                }
                set_d_r(moncal,yearcal,rangDay,rangNight);
        }
        *outday = daycal;
        *outmon = moncal;
        *outyear = yearcal;
}

void case1()   //Menu Selection 1
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

void case2()   //Menu Selection 2
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

void case3()   //Menu Selection 3
{
        unsigned int holdRoomNum;
        // "Temp Room Hold"
        cout << "Enter room number for temporary hold: ";
        cin >> holdRoomNum;
        cout << "Temporary hold placed.\n\n";
        system ("pause");
}

void case4()   ////Menu Selection 4
{
        // "Guest Listing" -- Will hold guest information for later use, needs arrays
        // Hi Ayaka, I rewrite some parts of your fuction that shows error, and helps you to make it go back to main menu.
        ofstream fout;
        ifstream fin;
        string str, name;
        int guestlist,guestroomnumber;
        char choice;
        do
        {
                cout << "\n-----Guest Listing Menu-----\n\n"
                        << "1. Check Guest List\n"
                        << "2. Add Guest List\n"
                        << "3. Go Back to Main Menu\n"
                        << "\nEnter Option #: ";
                cin >> guestlist;
                cout << endl;
                if (guestlist == 1) //open guestlist file
                {
                        fin.open("guestlist.txt"); //Open file. File name is just random. I thought the file should be existing file, and add.
                        while(fin>>str) cout<<str<<",\n"<<endl;
                        fin.close();
                        cout << endl;
                }
                else if (guestlist == 2) //Write file 
                {
                        fout.open("guestlist.txt");
                        do
                        {
                                cout << "\nEnter guest names. \n";
                                cin >> name;
                                cout<< "\nEnter room number. \n";
                                cin>>guestroomnumber;
                                fout << name << "\t"<<guestroomnumber<<endl; //Input guests
                                cout << "\nKeep adding?(Y/N): ";  // Asking for adding more name.
                                cin >> choice;
                        }while (choice == 'Y' || choice == 'y');
                        fout.close(); //Close the file.
                }
                else if (guestlist == 3);
                else cout << "Invalid number!!!!!!!!!!!!!!!\n\n";
        } while (guestlist !=3);
        system ("pause");
}

void case5()   //Menu Selection 5
{
        static int Zip, Phone, CC_Number, Street_Address, City, State, arrivalConfirm, departureConfirm, DayID = 0,room_req;
        static const double price_per_room_per_night = 155.55, deposit = 300;
        static double tax, total, price_notax;
        static char Last_Name[50], First_Name[50], Title[10];
        static int room_num, confirm_num, floor, door_num;
        static const int nights_r = 0,  rooms = 1, floor_M = 10, floor_m = 0, door_num_d = 10;
        static bool isLeap, isLeap_calc, isRequest;
        srand((unsigned int)time(NULL));//just used for creating a random number
        confirm_num = rand() % 99999999;
        static int nights, checkIn_month, checkIn_day, checkIn_year, checkOut_month, checkOut_day, checkOut_year, checkOut_day_calc, dd_rem, checkOut_month_calc, mrangeVal_monthem, checkOut_year_calc, rangeVal_day, rangeVal_nights; 
        //"in" means check in, "r" means range, "out" means check out, "nights" means how many nights they will stay, "rem" means remain
        
        /*------------- Begin New Reservation (Option 5) ----------------*/

        cout << "\n----New Reservation Screen----\n" << endl;
        cout << "Title (Mr, Mrs, Ms, Dr, etc): " << endl;
        cin >> Title;
        cout << "\n" << endl;
        cout << "Last Name: " << endl;
        cin >> Last_Name;
        cout << "\n" << endl;
        cout << "Enter checkin date. (mm dd yyyy): " << endl; //check in date input (sepreate by space)
        cin >> checkIn_month >> checkIn_day >> checkIn_year;   //storage date sepreatly into three variables
        cout << "\n" << endl;
        checkOut_month_calc = checkIn_month;
        checkOut_year_calc = checkIn_year;
        set_d_r(checkOut_month_calc,checkOut_year_calc,&rangeVal_day,&rangeVal_nights);//this is the day range setting fuction 
        while (checkIn_month*checkIn_day==0 || checkIn_month>rangeVal_month || checkIn_day>rangeVal_day)   //check if there is any error of input
        {
                cout << "Wrong date input! Enter again. (mm dd yyyy): " << endl;
                cin >> checkIn_month >> checkIn_day >> checkIn_year;
                checkOut_month_calc = checkIn_month;
                checkOut_year_calc = checkIn_year;
                cout << "\n" << endl;
                set_d_r(checkOut_month_calc,checkOut_year_calc,&rangeVal_day,&rangeVal_nights); //this is the day range setting fuction 
        }
        cout << "How many nights will you be staying: " << endl;
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
                cout << "Please enter desired floor. [1-9]: " << endl; 
                cin >> floor;
                cout << "\n" << endl;
                while (floor >= floor_M || floor <= floor_m)
                {
                        cout << "The number you entered is not from 1 to 9. Please Enter again: " << endl;
                        cin >> floor;
                        cout << "\n" << endl;
                }
                cout << "Please enter desired room number. [0-9]: " << endl;
                cin >> door_num;
                cout << "\n" << endl;
                while (door_num >= door_num_d)
                {
                        cout << "The number you entered is not from 0 to 9. Please Enter again: " << endl;
                        cin >> door_num;
                        cout << "\n" << endl;
                }
                room_num = floor * 100 + door_num;
                cout << "Room #: " << room_num;
        }
        else
        {
                isRequest = 0;
                floor = rand() % 9 + 1;
                door_num = rand() % 9;
                room_num = floor * 100 + door_num;
                cout << "Room #: " << room_num;
        }
        /*Calculation for price*/
        price_notax = price_per_room_per_night * nights * rooms;
        tax = price_notax * 0.095;
        total = price_notax + tax + deposit;
        //this is the checkout date calculator
        checkOutDate(checkIn_day, checkOut_day_calc, checkOut_month_calc, checkOut_year_calc, &rangeVal_day, &rangeVal_nights, &checkOut_day, &checkOut_month, &checkOut_year, nights);
        /*Place holder for room availability checker logic*/
        cout << "\n" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Room ";
        cout << setw(4) << setfill('0') << room_num;
        cout << " reserved for " << Title << ". " << Last_Name << endl; //Reservation confirmation
        cout << "-----------------------------------" << endl;
        cout << "Check in: " << checkIn_month << " / " << checkIn_day << " / " << checkIn_year << endl;//show checkin date
        cout << "Check out: " << checkOut_month << " / " << checkOut_day << " / " << checkOut_year << endl; // show checkout date
        cout << "\nStay " << nights << " nights." << endl;
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
        cout << "\nConfirmation #: ";
        cout << setw(8) << setfill('0') << confirm_num << endl;
        cout << "-----------------------------------" << endl;
        cout << "\n\n";
        /*------------- End New Reservation (Option 5) ----------------*/
        system ("pause");
}


void case6()   //Menu Selection 6
{
      // "Room Condition" -- will be a list of all the rooms and weather they are clean or not
        int userInput;
      int choice, floor, room, choiceForCondition;
        string condition[9][10];
        char InputCondition, DoAgain;
        do
        {
                        cout << "***Room Condition***" << endl;
                        cout << "Enter the room number you want to check or"
                                << " the room condition you want to write down.\n";
                        do
                        {
                                cout << "Floor(1-9): ";
                                cin >> floor;
                                if (floor<0 || floor>9)
                                        cout << "Invalid number. Enter correct room number.";
                        } while (floor<0 || floor>9);

                        do
                        {
                                cout << "Room(0-9): ";
                                cin >> room;
                                if (room<0 || room>9)
                                        cout << "Invalid number. Enter correct room number.";
                        } while(room<0 || room>9);

                cout << "---Room Condition---\n";
                cout << "The condition of the room you entered is "
                        << condition[floor-1][room] << endl;

                cout << "Do you want to put the room condition?(y/n): ";
                cin >> InputCondition;
                if (InputCondition == 'y' || InputCondition == 'Y')
                {
                        cout << "Enter the room condition: ";
                        getline(cin, condition[floor-1][room]);
                }
                cout << "Do you want to see another room?(y/n): ";
                cin >> DoAgain;
        } while (DoAgain == 'y' || DoAgain == 'Y');

}

void RoomNumberInitial(int **x,int rowsize,int colsize)
{
        for(int i=0;i<rowsize;i++)
        {
                for(int j=0;j<colsize;j++)
                {
                        x[i][j]=(i+1)*100+(j);
                }
        }
}

int **FreeMemo(int rowsize,int colsize)
{
        int **x;
        x=new int*[rowsize];
        for(int i=0;i<rowsize;i++)
                x[i]=new int[colsize];
        return x;
}

int *FreeMemo(int colsize)
{
        int *x;
        x=new int[colsize];
        return x;
}

void case7()   //Menu Selection 7
{
    static int **RoomNumber=FreeMemo(9,10);
    RoomNumberInitial(RoomNumber,9,10);
        string RoomCond[9][10],RoomHolder[9][10],RoomInDate[9][10],RoomOutDate[9][10],RoomPeople[9][10];
        int MenuSelect,FloorSelect,DoorSelect,RoomSelect,YNSR,SFR,YNINT;
        initialize(RoomCond);
        initialize(RoomHolder);
        initialize(RoomInDate);
        initialize(RoomOutDate);
        initialize(RoomPeople);
        do
        {
                cout<<"\nROOM CONDITION MENU"
                <<"\n____________________________________\n"
                <<"1. CHECK CONDITION\n"
                <<"2. EDIT CONDITION\n"
                <<"3. CLEAR ALL CONDITION\n"
                <<"4. ROOM INFORMATION LIST\n"
                <<"5. BACK\n\n"
                <<"ENTER SELECTION: ";
                cin>>MenuSelect;
                                InvalidValue(&MenuSelect,1,5);
                switch(MenuSelect)
                {
                case 1:
                        cout<<"\nSPECIFIC REQUIREMENT?\n[1]>>>Yes\n[2]>>>No\n";
                        cin>>YNSR;
                        InvalidValue(&YNSR,1,2);
                        if(YNSR==1)
                        {
                                cout<<"\nSPECIFIC [1]FLOOR, [2]DOOR# OR [3]ROOM: ";
                                cin>>SFR;
                                InvalidValue(&SFR,1,3);
                                if(SFR==1)
                                {
                                        cout<<"\nENTER FLOOR[1-10]: ";
                                        cin>>FloorSelect;
                                        InvalidValue(&FloorSelect,1,10);
                                        for(int i=0;i<10;i++)
                                        {
                                                cout<<"#"<<RoomNumber[FloorSelect-1][i]<<"["<<RoomCond[FloorSelect-1][i]<<"] ";
                                                cout<<endl;
                                        }
                                        system("pause");
                                }
                                else if(SFR==2)
                                {
                                        cout<<"\nENTER DOOR#[0-9]: ";
                                        cin>>DoorSelect;
                                        InvalidValue(&DoorSelect,0,9);
                                        for(int i=0;i<9;i++)
                                        {
                                                cout<<"#"<<RoomNumber[i][DoorSelect]<<"["<<RoomCond[i][DoorSelect]<<"] ";
                                                cout<<endl;
                                        }
                                        system("pause");
                                }
                                else if(SFR==3)
                                {
                                        cout<<"\nENTER FLOOR[1-10]: ";
                                        cin>>FloorSelect;
                                        InvalidValue(&FloorSelect,1,10);
                                        cout<<"\nENTER DOOR#[0-9]: ";
                                        cin>>DoorSelect;
                                        InvalidValue(&DoorSelect,0,9);
                                        cout<<"#"<<RoomNumber[FloorSelect-1][DoorSelect]<<"["<<RoomCond[FloorSelect-1][DoorSelect]<<"] ";
                                        system("pause");
                                }
                        }
                        else if(YNSR==2)
                        {
                                for(int i=0;i<9;i++)
                                {
                                        for(int j=0;j<10;j++)
                                        {
                                                cout<<"#"<<RoomNumber[i][j]<<"["<<RoomCond[i][j]<<"] ";
                                                cout<<endl;
                                        }
                                }
                                system("pause");
                        }
                        break;
                case 2:
                        cout<<"\nSPECIFIC REQUIREMENT?\n[1]>>>Yes\n[2]>>>No\n";
                        cin>>YNSR;
                        InvalidValue(&YNSR,1,2);
                        if(YNSR==1)
                        {
                                cout<<"\nSPECIFIC [1]FLOOR, [2]DOOR# OR [3]ROOM: ";
                                cin>>SFR;
                                InvalidValue(&SFR,1,3);
                                if(SFR==1)
                                {
                                        cout<<"\nENTER FLOOR[1-10]: ";
                                        cin>>FloorSelect;
                                        InvalidValue(&FloorSelect,1,10);
                                        cout<<"\n[R]-READY\t[U]-In USE\t[C]-IN CLEANING\t[O]-OUT OF USE\n";
                                        for(int i=0;i<10;i++)
                                        {
                                                cout<<"#"<<RoomNumber[FloorSelect-1][i]<<" :";
                                                cin>>RoomCond[FloorSelect-1][i];
                                        }
                                }
                                else if(SFR==2)
                                {
                                        cout<<"\nENTER DOOR#[0-9]: ";
                                        cin>>DoorSelect;
                                                while(DoorSelect<0||DoorSelect>10)
                                                {
                                                        cout<<"INVALID INPUT, ENTER AGAIN: ";
                                                        cin>>DoorSelect;
                                                }
                                                cout<<"\n[R]-READY\t[U]-In USE\t[C]-IN CLEANING\t[O]-OUT OF USE\n";
                                                for(int i=0;i<9;i++)
                                                {
                                                        cout<<"#"<<RoomNumber[i][DoorSelect]<<" :";
                                                        cin>>RoomCond[i][DoorSelect];
                                                }
                                }
                                else if(SFR==3)
                                {
                                        cout<<"\nENTER FLOOR[1-9]: ";
                                        cin>>FloorSelect;
                                        InvalidValue(&FloorSelect,1,9);
                                        cout<<"\nENTER DOOR#[0-9]: ";
                                        cin>>DoorSelect;
                                        InvalidValue(&DoorSelect,0,9);
                                        cout<<"\n[R]-READY\t[U]-In USE\t[C]-IN CLEANING\t[O]-OUT OF USE\n";
                                        cout<<"#"<<RoomNumber[FloorSelect-1][DoorSelect]<<" :";
                                        cin>>RoomCond[FloorSelect-1][DoorSelect];
                                }
                        }
                        else if(YNSR==2)
                        {
                                cout<<"\n[R]-READY\t[U]-In USE\t[C]-IN CLEANING\t[O]-OUT OF USE\n";
                                for(int i=0;i<9;i++)
                                {
                                        for(int j=0;j<10;j++)
                                        {
                                                cout<<"#"<<RoomNumber[i][j]<<" :";
                                                cin>>RoomCond[i][j];
                                        }
                                        cout<<endl;
                                }
                        }
                        break;
                case 3:
                        cout<<"\n!!!WARNING!!!YOU ARE CLEARNING ALL CONDITION OF ROOMS!!!\n"
                                <<"!!!ARE YOU SURE TO CLEARN?\n"
                                <<"[1]>>>YES\n"
                                <<"[2]>>>NO\n";
                        cin>>YNINT;
                        InvalidValue(&YNINT,1,2);
                        if(YNINT==1)
                        {
                                initialize(RoomCond);
                                initialize(RoomHolder);
                                initialize(RoomInDate);
                                initialize(RoomOutDate);
                                initialize(RoomPeople);
                        }
                        else;
                        break;
                case 4:
                        cout<<"\n[R]-READY\t[U]-In USE\t[C]-IN CLEANING\t[O]-OUT OF USE\n"
                                <<"ROOM# CONDITION NAME IN_DATE\tOUT_DATE\t#PEOPLE\n";
                        for(int i=0;i<9;i++)
                                {
                                        for(int j=0;j<10;j++)
                                        {
                                                cout<<"#"<<RoomNumber[i][j]<<"  ["<<RoomCond[i][j]<<"]\t"
                                                        <<RoomHolder[i][j]<<" "
                                                        <<RoomInDate[i][j]<<"\t"
                                                        <<RoomOutDate[i][j]<<"\t\t"
                                                        <<RoomPeople[i][j];
                                                cout<<endl;
                                        }
                                }
                        break;
                case 5:
                        break;
                default:;}
        }while(MenuSelect!=5);
        system("pause");
}

void InvalidValue(int *a,int min,int max)
{
        while(*a<min||*a>max)
        {
                cout<<"INVALID INPUT, ENTER AGAIN: ";
                cin>>*a;
        }
}

void InvalidValue(double *a,int min,int max)
{
        while(*a<min||*a>max)
        {
                cout<<"INVALID INPUT, ENTER AGAIN: ";
                cin>>*a;
        }
}

void InvalidValue(float *a,int min,int max)
{
        while(*a<min||*a>max)
        {
                cout<<"INVALID INPUT, ENTER AGAIN: ";
                cin>>*a;
        }
}

//all the indentation is messed up from pasting it in here, sorry

int convert_calendar_to_integer(int year, int month, int day)   //FUNCTION DISCRIPTION: this function takes a year, month, and day; and converts it to an integer number that represents that day
{
        int total_nights = 0, days_in_year, days_in_month;

        for(int y = 0; y<year;y++)//'y' counts up to 'year' adding all the days into variable, total_nights 
        {
                if(y%4==0 && (!(y%100==0)||y%400==0))//it is a leap year if year is divisable by 4 AND either not divisable by 100 or divisable by 400
                {
                        days_in_year = 366;//leap year add a day
                }
                else
                {
                        days_in_year = 365;// not leap year, just 365 days
                }
                total_nights += days_in_year;//add that year's total each iteration
        }

        for(int m = 1; m<month;m++)//'m' counts up to 'month' adding all the days into variable, total_nights 
		{

		}

                if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)//these months have 31 days
                {
                        days_in_month = 31;
                }
                else if(m==4||m==6||m==9||m==11)//these months have 30 days
                {
                        days_in_month = 30;
                }
                else if(m==2)//in feb, its 29 days on a leap year
                {
                        if(year%4==0 && (!(year%100==0)||year%400==0))
                        {
                                days_in_month = 29;//leap year
                        }
                        else
                        {
                                days_in_month = 28;//not leap year
                        }
                }
                else//we shouldn't land in this else statement ever if we use input validation
                {
                        cout << "ERROR: program ran else statement in months loop.";
                }
                total_nights += days_in_month;//and finally we add those days to our total_nights variable
        }
        return total_nights += day;//and the last 'days' part for the actual date gets added here
}
