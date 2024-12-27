#include <iostream>
#include <fstream>

using namespace std;

class Shopping
{
private:
    int Product_code;
    float Product_price;
    float Discount;
    string Product_name;

public:
    void Menu();
    void Administrator();
    void Buyer();
    void Add();
    void Edit();
    void Rem();
    void List();
    void Receipt();
};

void Shopping ::Menu()
{
m:
    int choise;
    string email, password;
    cout << "\t\t\t\t\t+--------------------------------+\n";
    cout << "\t\t\t\t\t|                                |\n";
    cout << "\t\t\t\t\t|    Super Market Main Menu      |\n";
    cout << "\t\t\t\t\t|                                |\n";
    cout << "\t\t\t\t\t+--------------------------------+\n\n";
    cout << "\t\t\t\t\t+--------------------------------+\n";
    cout << "\t\t\t\t\t|   1) Administrotor             |\n";
    cout << "\t\t\t\t\t|                                |\n";
    cout << "\t\t\t\t\t|   2) Buyer                     |\n";
    cout << "\t\t\t\t\t|                                |\n";
    cout << "\t\t\t\t\t|   3) Exit                      |\n";
    cout << "\t\t\t\t\t|                                |\n";
    cout << "\t\t\t\t\t|                                |\n";

    cout << "\t\t\t\t\tPlease Select = ";
    cin >> choise;
    char ch;
    switch (choise)
    {
    case 1:
        cout << "\t\t\t Please Login \n";
        cout << "\t\t\t Enter The Email = ";
        cin >> email;
        cout << "\t\t\t Password = ";
        cin >> password;

        if (email == "omprakash123@.com" && password == "market123")
        {
            Administrator();
        }
        else
        {
            cout << "Cheak your password and login id \n\n";
        }
        break;
    case 2:
    {
        Buyer();
    }
    case 3:
    {
        exit(0);
    }

    default:
    {
        cout << "Please select from the given option ";
    }
    }
    goto m;
}
void Shopping ::Administrator()
{
m:
    int choise;
    cout << "\n\n\n\t\t\t| Administrator Menu |";
    cout << "\n\t\t\t____1) Add the product___________|";
    cout << "\n\t\t\t____2) Modify the prodct_________|";
    cout << "\n\t\t\t____3) Delete the product________|";
    cout << "\n\t\t\t____4) Break thre main menu______|";

    cout << "\n Please enter your choise = ";
    cin >> choise;

    switch (choise)
    {
    case 1:
        Add();
        break;
    case 2:
        Edit();
        break;
    case 3:
        Rem();
        break;
    case 4:
        Menu();

    default:
        cout << "Invaild Choise ";
    }
    goto m;
}
void Shopping ::Buyer()
{
m:
    int choise;
    cout << "\n\t\t\t Buyer       \n";
    cout << "\t\t\t___1) Buy the product ____\n";
    cout << "\t\t\t___2) Go back_____________\n";

    cout << "Enter your choise = ";
    cin >> choise;

    switch (choise)
    {
    case 1:
        Receipt();
        break;
    case 2:
        Menu();
        break;

    default:
        cout << "Invaild choise ";
    }
    goto m;
}
void Shopping ::Add()
{
m:
    fstream data;
    int c, token = 0;
    float p, d;
    string n;

    cout << "\n\n\t\t\t Add new product ";
    cout << "\n\n\tCode of the product = ";
    cin >> Product_code;
    cout << "\n\n\t Name of product = ";
    cin >> Product_name;
    cout << "\n\n\t price of product = ";
    cin >> Product_price;
    cout << "\n\n\t Discount of product = ";
    cin >> Discount;

    data.open("database.txt", ios ::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << Product_code << " " << Product_name << " " << Product_price << " " << Discount << "\n ";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == Product_code)
            {
                token++;
            }
            data >> c >> n >> p >> d;

            data.close();
        }
        if (token == 1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << Product_code << " " << Product_name << " " << Product_price << " " << Discount << "\n";
            data.close();
        }
    }
    cout << "\n\n\t\t Record insert ! ";
}
void Shopping ::Edit()
{
    fstream data, data1;
    int token = 0;
    int Product_key;
    int p, c, n, d;
    cout << "\n\n\t Delete Product ";
    cout << "\n\n\t Product code = ";
    cin >> Product_key;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File does not exit ";
    }
    else
    {
        data1.open("database.txt", ios::app | ios::out);
        data >> Product_code >> Product_name >> Product_price >> Discount;
        while (!data.eof())
        {

            if (Product_code == Product_key)
            {
                cout << "\n\t\t Product new code = ";
                cin >> c;
                cout << "\n\t\t Name of the product = ";
                cin >> n;
                cout << "\n\t\t Price = ";
                cin >> p;
                cout << "\n\t\t Discount = ";
                cin >> d;
                cout << "\n\n\t\t Record edited ";
                token++;
            }
            else
            {
                cout << Product_code << " " << Product_name << " "
                     << " " << Product_price << " " << Discount << "\n";
            }
            data >> Product_code >> Product_name >> Product_price >> Discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found sorry!";
        }
    }
}
void Shopping ::Rem()
{
    fstream data, data1;
    int Product_key;
    int token = 0;
    cout << "\n\n\t Delete Product ";
    cout << "\n\t\t Product Code";
    cin >> Product_key;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File is does not exit ";
    }
    else
    {
        data1.open("database.txt", ios::in | ios::out);
        data >> Product_code >> Product_name >> Product_price >> Discount;
        while (!data.eof())
        {
            if (Product_code == Product_key)
            {
                cout << "\n\t\t Product delete succesfully ";
                token++;
            }
            else
            {
                data << " " << Product_code << " " << Product_name << " " << Product_price << " " << Discount << "\n";
            }
            data >> Product_code >> Product_name >> Product_price >> Discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found";
        }
    }
}
void Shopping ::List()
{
    fstream data;
    data.open("database.txt", ios ::in);
    cout << "\n+---------------------------------------------------+\n";
    cout << "|   Product_No\t\tName\t\tPrice       |\n";
    cout << "+---------------------------------------------------+\n";
    data >> Product_code >> Product_name >> Product_price >> Discount;
    while (!data.eof())
    {
        cout << "\t" << Product_code << "\t\t" << Product_name << "\t\t" << Product_price << "\n";
        data >> Product_code >> Product_name >> Product_price >> Discount;
    }
    data.close();
}
void Shopping ::Receipt()
{
    fstream data;
    int arrc[100], arrq[100];
    char choise;
    int c = 0;
    float amount = 0, discount = 0, total = 0;

    cout << "\n\n\t\t\t RECEIPT  ";
    data.open("database.txt", ios ::in);
    if (!data)
    {
        cout << "\n\n Empty database ";
    }
    else
    {
        data.close();

        List();
        cout << "\n+------------------------+\n";
        cout << "| Please Place The Order |";
        cout << "\n+------------------------+\n";

        string cname,cno;
        cout<<"Enter the coustmer name = ";
        cin>>cname;
        
        do
        {
        m:
            cout << "\n\nEnter Product Code = ";
            cin >> arrc[c];
            cout << "\n\nEnter The Product Quantity = ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\nDuplicat Product Code. Please Try Again ! ";

                    goto m;
                }
            }
            c++;
            cout << "\n\n Do You Want To Buy Another Product ? If Yes then Press | Y | Else NO then Press | N | ";
            cin >> choise;
        } while (choise == 'y');
        cout << "\n\n____________________________________RECEIPT__________________________________________________";
        cout << "\nProduct No\tProduct Name\tProduct Quantity\tPrice\tAmount\tAmount with Discount\n";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> Product_code >> Product_name >> Product_price >> Discount;

            while (!data.eof())
            {       float Gst ;
                if (Product_code == arrc[i])
                {
                    amount = Product_price * arrq[i];
                    Discount = amount - (amount * (Discount / 100));
                    Gst = amount*(6/100);
                    total = total + Discount + Gst ;
                    
                    cout << "\n"
                         << Product_code << "\t\t" << Product_name << "\t\t" << arrq[i] << "\t\t\t" << Product_price << "\t" << amount << "\t\t" << Discount << "\n";
                }
                data >> Product_code >> Product_name >> Product_price >> Discount;
            }
            data.close();
        }

        cout << "\n\n+-----------------------------+--------------------------------------------------------------";
        cout << "\n| Total Amount = " << total << "\t\t|";
        cout << "\n+-------------------------------+";--
    }
}

int main()
{
    Shopping S;
    S.Menu();
    return 0;
}
