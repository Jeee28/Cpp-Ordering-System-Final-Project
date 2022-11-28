/*
    ito po ang mga libraries na ginamit po para sa program po na ito
*/
#include <iostream>
#include <iomanip>
#include <string.h>
#include <windows.h>
#include <conio.h>
using namespace std;

// ito para maka pag-change color
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

// ito ay maximum size
const int maxsize = 100;

// ito po ay array declation
string _fullname[maxsize] = {};
string _takoyaki_Order[maxsize] = {};
string _order_Payment[maxsize] = {};
double _order_Price[maxsize] = {};
double _order_Total_Price[maxsize] = {};
double _order_Pieces[maxsize] = {};
double _order_Quantity[maxsize] = {};
double _payment[maxsize] = {};
double _payment_change[maxsize] = {};

// global variable for option
int option, quantity, pieces;

// ito po ay menu function declaration
void menu();
void viewrecord();
void paymentreceipt();
void exit();
void loadingBar();

int main()
{
    system("cls");
    loadingBar();
    do
    {
        /*
            ito po ang OPTION menu choices
            [1] GO TO MENUS
            [2] VIEW RECORD
            [3] PAYMENT & RECEIPT
            [4] EXIT
        */

        system("cls");
        cout << setw(50);
        SetConsoleTextAttribute(h, 11);
        cout << "WELECOME TO MY KIKI TAKOYAKI";
        cout << "\n===============================================================================\n";
        SetConsoleTextAttribute(h, 7);
        cout << "[1] GO TO MENUS\n";
        cout << "[2] VIEW RECORD\n";
        cout << "[3] PAYMENT & RECEIPT\n";
        cout << "[4] EXIT\n";
        cout << "ENTER OPTION: ";
        cin >> option;

        // ito po ang OPTION menu ng menu method
        if (option == 1)
        {
            system("cls");
            loadingBar();
            menu();
        }

        // ito po ang OPTION MENU ng viewrecord method
        else if (option == 2)
        {
            system("cls");
            loadingBar();
            system("cls");
            SetConsoleTextAttribute(h, 11);
            cout << setw(60);
            cout << "LIST OF PERSON WHO ORDERED";
            SetConsoleTextAttribute(h, 7);
            cout << "\n==============================================================================================================\n";
            viewrecord();
        }

        // ito po ang OPTION menu ng paymentreceipt method
        else if (option == 3)
        {
            system("cls");
            loadingBar();
            system("cls");
            paymentreceipt();
        }

        // ito po ang OPTION menu ng exit method
        else if (option == 4)
        {
            system("cls");
            loadingBar();
            system("cls");
            exit();
        }

        // ito po ay error message na kung saan kapag
        // mali po ang input OPTION mag bibigay po sya
        // ng error message
        else
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\n"
                 << setw(45)
                 << "INVALID OPTION INPUT\n";
            SetConsoleTextAttribute(h, 7);
            cout << "\nPLEASE ENTER ANY KEY TO CONTINUE...";
            _getch();
            cin.clear();           // clear the previous input
            cin.ignore(123, '\n'); // discard the previous input
        }

    } while (option != 4);
    return 0;
}

// ito po ay menu function definition
/*
    dito po makikita ang mga OPTION menu para sa
    [1] GO TO MENUS
    [2] VIEW RECORD
    [3] PAYMENT & RECEIPT
    [4] EXIT
*/
void menu()
{
    cin.ignore();
    system("cls");
    string fullname;
    SetConsoleTextAttribute(h, 5);
    cout << "" << setw(55) << "PLEASE ENTER YOUR FULLNAME FIRST";
    cout << "\n===============================================================================\n";
    SetConsoleTextAttribute(h, 7);

    cout << "ENTER FULLNAME: ";
    getline(cin, fullname);

    cout << "\n\nPLEASE ENTER ANY KEY TO CONTINUE...";
    _getch();

    for (int i = 0; i < maxsize; i++)
    {
        if (_fullname[i] == "\0")
        {
            /*
                ito po ang OPTION MENUS ng TAKOYAKI
                gumamit din po ako ng goto
                para sa specific back po
            */
        jump:
            system("cls");
            loadingBar();
            system("cls");
            SetConsoleTextAttribute(h, 14);
            cout << setw(45) << "KIKI TAKOYAKI MENUS\n";
            cout << "==================================================================================\n";
            SetConsoleTextAttribute(h, 7);
            cout << setw(15) << "Flavors" << setw(15) << "4pcs" << setw(15) << "6pcs" << setw(17) << "8pcs\n";
            cout << "[1] Cheesy-Yaki"
                 << "\t\t"
                 << "(P35.00) |"
                 << "\t"
                 << "(P50.00) |"
                 << "\t"
                 << "(P65.00)\n";
            cout << "[2] Crab"
                 << "\t\t"
                 << "(P45.00) |"
                 << "\t"
                 << "(P65.00) |"
                 << "\t"
                 << "(P84.00)\n";
            cout << "[3] Octobits"
                 << "\t\t"
                 << "(P60.00) |"
                 << "\t"
                 << "(P80.00) |"
                 << "\t"
                 << "(P100.00)\n";
            cout << "[4] Squid"
                 << "\t\t"
                 << "(P45.00) |"
                 << "\t"
                 << "(P65.00) |"
                 << "\t"
                 << "(P84.00)\n\n";
            cout << "Ano po sa inyo? ";
            cin >> option;

            if (option == 1)
            {
                _takoyaki_Order[i] = "Cheesy-Yaki";
                cout << "Ilan piraso po? ";
                cin >> pieces;

                if (pieces == 4)
                {
                    cout << "Ilan order po? ";
                    cin >> quantity;
                    _order_Total_Price[i] = quantity * 35;
                    _order_Quantity[i] = quantity;
                    _order_Price[i] = 35;
                }
                else if (pieces == 6)
                {
                    cout << "Ilan order po? ";
                    cin >> quantity;
                    _order_Total_Price[i] = quantity * 50;
                    _order_Quantity[i] = quantity;
                    _order_Price[i] = 50;
                }
                else if (pieces == 8)
                {
                    cout << "Ilan order po? ";
                    cin >> quantity;
                    _order_Total_Price[i] = quantity * 65;
                    _order_Quantity[i] = quantity;
                    _order_Price[i] = 65;
                }
                else
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << setw(15);
                    cout << "\nINVALID INPUT PLEASE TRY AGAIN...\n";
                    SetConsoleTextAttribute(h, 7);
                    cout << "\n===============================================================================\n";
                    _getch();

                    cin.clear();           // clear the previous input
                    cin.ignore(123, '\n'); // discard the previous input
                    system("cls");
                    goto jump;
                }
            } // end of cheesy yaki option

            else if (option == 2)
            {
                _takoyaki_Order[i] = "Crab";
                cout << "Ilan piraso po? ";
                cin >> pieces;
                if (pieces == 4)
                {
                    cout << "Ilan order po? ";
                    cin >> quantity;
                    _order_Total_Price[i] = quantity * 45;
                    _order_Quantity[i] = quantity;
                    _order_Price[i] = 45;
                }
                else if (pieces == 6)
                {
                    cout << "Ilan order po? ";
                    cin >> quantity;
                    _order_Total_Price[i] = quantity * 65;
                    _order_Quantity[i] = quantity;
                    _order_Price[i] = 65;
                }
                else if (pieces == 8)
                {
                    cout << "Ilan order po? ";
                    cin >> quantity;
                    _order_Total_Price[i] = quantity * 84;
                    _order_Quantity[i] = quantity;
                    _order_Price[i] = 84;
                }
                else
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << setw(15);
                    cout << "\nINVALID INPUT PLEASE TRY AGAIN...\n";
                    SetConsoleTextAttribute(h, 7);
                    cout << "\n===============================================================================\n";
                    _getch();

                    cin.clear();           // clear the previous input
                    cin.ignore(123, '\n'); // discard the previous input
                    system("cls");
                    goto jump;
                }
            } // end of crab option

            else if (option == 3)
            {
                _takoyaki_Order[i] = "Octobits";
                cout << "Ilan piraso po? ";
                cin >> pieces;
                if (pieces == 4)
                {
                    cout << "Ilan order po? ";
                    cin >> quantity;
                    _order_Total_Price[i] = quantity * 60;
                    _order_Quantity[i] = quantity;
                    _order_Price[i] = 60;
                }
                else if (pieces == 6)
                {
                    cout << "Ilan order po? ";
                    cin >> quantity;
                    _order_Total_Price[i] = quantity * 80;
                    _order_Quantity[i] = quantity;
                    _order_Price[i] = 80;
                }
                else if (pieces == 8)
                {
                    cout << "Ilan order po? ";
                    cin >> quantity;
                    _order_Total_Price[i] = quantity * 100;
                    _order_Quantity[i] = quantity;
                    _order_Price[i] = 100;
                }
                else
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << setw(15);
                    cout << "\nINVALID INPUT PLEASE TRY AGAIN...\n";
                    SetConsoleTextAttribute(h, 7);
                    cout << "\n===============================================================================\n";
                    _getch();

                    cin.clear();           // clear the previous input
                    cin.ignore(123, '\n'); // discard the previous input
                    system("cls");
                    goto jump;
                }
            } // end of octobits option

            else if (option == 4)
            {
                _takoyaki_Order[i] = "Squid";
                cout << "Ilan piraso po? ";
                cin >> pieces;
                if (pieces == 4)
                {
                    cout << "Ilan order po? ";
                    cin >> quantity;
                    _order_Total_Price[i] = quantity * 45;
                    _order_Quantity[i] = quantity;
                    _order_Price[i] = 45;
                }
                else if (pieces == 6)
                {
                    cout << "Ilan order po? ";
                    cin >> quantity;
                    _order_Total_Price[i] = quantity * 65;
                    _order_Quantity[i] = quantity;
                    _order_Price[i] = 65;
                }
                else if (pieces == 8)
                {
                    cout << "Ilan order po? ";
                    cin >> quantity;
                    _order_Total_Price[i] = quantity * 84;
                    _order_Quantity[i] = quantity;
                    _order_Price[i] = 84;
                }
                else
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << setw(15);
                    cout << "\nINVALID INPUT PLEASE TRY AGAIN...\n";
                    SetConsoleTextAttribute(h, 7);
                    cout << "\n===============================================================================\n";
                    _getch();

                    cin.clear();           // clear the previous input
                    cin.ignore(123, '\n'); // discard the previous input
                    system("cls");
                    goto jump;
                }
            } // end of octobits option

            // else option menus
            else
            {
                SetConsoleTextAttribute(h, 4);
                cout << setw(15);
                cout << "\nINVALID INPUT PLEASE TRY AGAIN...\n";
                SetConsoleTextAttribute(h, 7);
                cout << "\n===============================================================================\n";
                _getch();

                cin.clear();           // clear the previous input
                cin.ignore(123, '\n'); // discard the previous input
                system("cls");
                goto jump;
            }

            _fullname[i] = fullname;
            _order_Pieces[i] = pieces;
            _order_Payment[i] = "NOT PAID";
            cout << "\nPRESS ANY KEY TO CONTINUE...";
            _getch();
            main();
            break; // ito po break is para pag add po sya ng record 1 record at a time
        }

        /*
            dito po ay kapag ang customer po ay meron na record
            mag bibigay po sya ng message na CUSTOMER IS ALREADY EXIST
        */
        else if (_fullname[i] == fullname)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\nCUSTOMER IS ALREADY EXIST PLEASE ENTER OTHER NAME";
            SetConsoleTextAttribute(h, 7);
            cout << "\n===============================================================================\n";
            cout << "PRESS ANY KEY TO CONTINUE...";
            _getch();
            menu();
            break;
        }
    }
}

/*
    ang viewrecord na method po ng ito ay para mag view ng
    mga customer na gusto umorder ng takoyaki
*/
void viewrecord()
{
    int recordList = 0;
    string payment_color;
    cout << "NO." << setw(15) << "FULLNAME" << setw(15) << "ORDER" << setw(15) << "PIECES" << setw(15) << "PRICE" << setw(15) << "QUANTITY" << setw(15) << "TOTAL PRICE" << setw(15) << "PAYMENT";
    cout << "\n==============================================================================================================\n";

    for (int i = 0; i < maxsize; i++)
    {
        if (_fullname[i] != "\0")
        {
            recordList++;
            payment_color = _order_Payment[i];
            // dito po ay kapag NOT PAID pa po sya ang kulay nya po is RED
            if (payment_color == "NOT PAID")
            {
                SetConsoleTextAttribute(h, 4);
            }
            // at dito naman po kapag PAID na po sya ang magiging kulay na po nya is GREEN
            else if (payment_color == "PAID")
            {
                SetConsoleTextAttribute(h, 2);
            }

            cout << recordList << setw(15) << _fullname[i] << setw(17) << _takoyaki_Order[i] << setw(15) << _order_Pieces[i] << setw(15) << _order_Price[i] << setw(15) << _order_Quantity[i] << setw(15) << _order_Total_Price[i] << setw(15) << payment_color;
            SetConsoleTextAttribute(h, 7);
            cout << "\n==============================================================================================================\n";
        }
    }

    /*
        ito naman po ay kapag wala po customer na
        nakarecord mag lalabas po sya ng
        NO RECORD FOUND
    */
    if (recordList == 0)
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\nNO RECORD FOUND\n";
        SetConsoleTextAttribute(h, 7);
        cout << "\n==============================================================================================================";
    }
    cout << "\n\nPLEASE ENTER ANY KEY TO GO BACK...";
    _getch();
    system("cls");
    loadingBar();
}

// ito po ay ang bayadan ng mga order at dito po
// kasama na makikita ang resibo ng mga order ng program
void paymentreceipt()
{
    cin.ignore();
    int recordList = 0;
    string fullname;
    double payment, total_change = 0, balance = 0, amount_balance = 0;
    SetConsoleTextAttribute(h, 5);
    cout << "" << setw(55) << "PLEASE ENTER YOUR FULLNAME FIRST";
    cout << "\n===============================================================================\n";
    SetConsoleTextAttribute(h, 7);
    cout << "ENTER FULLNAME: ";
    getline(cin, fullname);

    cout << "\n\nPLEASE ENTER ANY KEY TO CONTINUE...";
    _getch();

    for (int i = 0; i < maxsize; i++)
    {
        if (_fullname[i] == fullname)
        {
            /**
                ito po ay kapag PAID na nag customer
                receipt nalang po ang lalabas
            **/
            if (_order_Payment[i] == "PAID")
            {
                system("cls");
                loadingBar();
                system("cls");
                recordList++;
                SetConsoleTextAttribute(h, 11);
                cout << "" << setw(25) << "RECEIPT\n";
                SetConsoleTextAttribute(h, 8);
                cout << "======================================\n";
                cout << "\nFULLNAME: " << setw(27) << _fullname[i] << "\n";
                cout << "ORDER: " << setw(30) << _takoyaki_Order[i] << "\n";
                cout << "PIECES: " << setw(29) << _order_Pieces[i] << "\n";
                cout << "PRICE: " << setw(30) << _order_Total_Price[i] << "\n";
                cout << "QUANTITY: " << setw(27) << _order_Quantity[i] << "\n\n";
                cout << "======================================\n";
                cout << "TOTAL PRICE IS: " << setw(21) << _order_Total_Price[i];
                cout << "\nINPUT PAYMENT:\t\t\t  " << _payment[i];

                cout << "\nYOUR TOTAL CHANGE IS " << setw(16) << _payment_change[i];
                SetConsoleTextAttribute(h, 2);
                cout << "\n\n"
                     << setw(25) << "YOU ARE ALREADY PAID \3";
                SetConsoleTextAttribute(h, 7);
            }
            /*
                ito po ay kapag nag customer a NOT PAID ay
                need nya po mag bayad
            */
            else if (_order_Payment[i] == "NOT PAID")
            {
                /*
                    gumamit din po ako ng goto para sa specific back po
                */
            PAYMENT:
                system("cls");
                loadingBar();
                system("cls");
                recordList++;
                SetConsoleTextAttribute(h, 11);
                cout << "" << setw(25) << "RECEIPT\n";
                SetConsoleTextAttribute(h, 8);
                cout << "======================================\n";
                cout << "\nFULLNAME: " << setw(27) << _fullname[i] << "\n";
                cout << "ORDER: " << setw(30) << _takoyaki_Order[i] << "\n";
                cout << "PIECES: " << setw(29) << _order_Pieces[i] << "\n";
                cout << "PRICE: " << setw(30) << _order_Total_Price[i] << "\n";
                cout << "QUANTITY: " << setw(27) << _order_Quantity[i] << "\n\n";
                cout << "======================================\n";
                cout << "TOTAL PRICE IS: " << setw(20) << _order_Total_Price[i];
                cout << "\nINPUT PAYMENT:\t\t\t ";
                cin >> payment;

                balance = balance + payment;
                if (balance >= _order_Total_Price[i])
                {
                    _payment[i] = balance;
                    _order_Payment[i] = "PAID";
                    total_change = balance - _order_Total_Price[i];
                    _payment_change[i] = total_change;
                    cout << "\nYOUR TOTAL CHANGE IS " << setw(16) << total_change;
                    SetConsoleTextAttribute(h, 2);
                    cout << "\n\n"
                         << setw(25) << "THANK YOU COME BACK AGAIN \3";
                    SetConsoleTextAttribute(h, 7);
                }
                else
                {
                    /*
                        ito po ang error message kapag kulang po ang
                        payment ni customer
                    */
                    cout << "\nINSUFFICIENT CASH PAYMENT! PLEASE ADD A CASH TO PAY\n";
                    amount_balance = _order_Total_Price[i] - balance;
                    cout << "YOUR INPUT PAYMENT CASH IS " << balance << " YOUR BALANCE NEED TO PAY IS " << amount_balance << "\n\n";
                    cout << "PLEASE PRESS ANY KEY TO CONTINUE...";
                    _getch();

                    loadingBar();
                    goto PAYMENT;
                }
            }
        }
    }

    /*
        ito naman po ay kapag wala po customer na
        nakarecord mag lalabas po sya ng
        NO RECORD FOUND
    */
    if (recordList == 0)
    {
        system("cls");
        loadingBar();
        system("cls");
        SetConsoleTextAttribute(h, 11);
        cout << "\n"
             << setw(25) << "RECEIPT\n";
        SetConsoleTextAttribute(h, 8);
        cout << "======================================\n";
        SetConsoleTextAttribute(h, 4);
        cout << "\nNO RECORD FOUND\n";
        SetConsoleTextAttribute(h, 7);
        cout << "\n======================================\n";
    }
    cout << "\n\nPLEASE ENTER ANY KEY TO GO BACK...";
    _getch();
    system("cls");
    loadingBar();
}

// ito po ay exit menu function definition
/*
    ang exit method po na ito ay para mag exit po ang
    program
*/
void exit()
{
    SetConsoleTextAttribute(h, 7);
    cout << "\n=================================================================================\n";
    cout << "|"
         << setw(80) << "|";
    cout << "\n|" << setw(52) << "THANK YOU AND COME BACK AGAIN ";
    SetConsoleTextAttribute(h, 4);
    cout << "\3" << setw(28);
    SetConsoleTextAttribute(h, 7);
    cout << "|\n";
    cout << "|"
         << setw(80) << "|";
    cout << "\n=================================================================================\n";
    _getch();
    exit(0);
}

void loadingBar()
{
    // 0 - black background,
    // A - Green Foreground
    SetConsoleTextAttribute(h, 2);

    // Initialize char for printing
    // loading bar
    char a = 177,
         b = 219;

    cout << "\n\n\n\n";
    cout << "\n\n\n\n\t\t\t\tLoading...\n\n";
    cout << "\t\t\t\t";

    // Print initial loading bar
    for (int i = 0; i < 26; i++)
    {
        cout << a;
    }

    // Set the cursor again starting
    // point of loading bar
    cout << "\r";
    cout << "\t\t\t\t";

    // Print loading bar progress
    for (int i = 0; i < 26; i++)
    {
        cout << b;

        // Sleep for 1 second
        Sleep(100);
    }
}
