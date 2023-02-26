#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;
string Names[200], Gender[200], Country[200], signedAs[200],orderArtist[200], orderSize[200],orderType[200],orderTheme[200], Age[200];
string City[200], Address[200], userNames[200], passwords[200], Artists[50], paintingTypes[20], paintingThemes[20], paintingSize[10];
int UserID[200], Number, TypeCount=0, ArtistCount=0, ThemeCount=0, SizeCount=0, orderCount=0,orderID[200],userCount=0;
float paintingPrice[10];
void printHeader();
void initialize();
string printFirstMenu();

void printRegistrationHeader();
void SignedAsMenu();
void storeInformation(string userName, string password, string name, string gender, string age, string country, string city, string address);
bool checkUsername(string userName);
string validatePassword(string password);
string validateGender(string gender);
string validateAge(string age);


void printLoginHeader();
bool checkLogin(string isUsername, string isPassword, string isAdmin);

void printAdminMenu();
void printCustomerMenu();
void AdminChoice1(string artist);
void AdminChoice2(string artist);
void AdminChoice3(string type);
void AdminChoice4(string theme);
void AdminChoice5(string theme);
void AdminChoice6Add(string size, float price);
void AdminChoice6Remove(string size);
string printSizeMenu();
void AdminChoice7();
void AdminChoice8();
void AdminChoice9(int ID , string name, string type, string theme, string size);
void CustomerChoice1();
void CustomerChoice2(string artist, string type , string theme, string size);
void CustomerChoice3(string artist, string type , string theme, string size);
void CustomerChoice4();
void CustomerChoice5();
void CustomerChoice6();
void CustomerChoice7();
float CustomerChoice8(string size);
float CustomerChoice9();
string getField (string field, int num);
void readDataFromFiles();
void storeInFiles();
void storeInUserFile();

main(){
    string isLogin, AdminChoice, CustomerChoice,CustomerEnd="0",AdminEnd="0",userName,password,isAdmin,isPassword,name,gender,age,country,city,address, isGender, isAge,artist,type,theme,size,isSize;
    bool match=false, found;
    int ID;
    float price;
    
    initialize();
    readDataFromFiles();

    for(int i=0; i<200; i++){
        match=false;
        storeInFiles();
        while(match==false){
            printHeader();
            isLogin = printFirstMenu();
            if(isLogin=="2"){
                match=true;
                printHeader();
                printRegistrationHeader();
            
                cout << "\t\t\t\t\t"<< "  Enter A Username: ";
                cin >> userName;
                cout << "\t\t\t\t\t"<<"  Enter A Password of 8 Characters: ";
                cin >> password;
                found=checkUsername(userName);
                if(found==true){
                    cout << endl << endl<< "\t\t\t\t\t" <<"  USERNAME ALREADY EXISTS"<< endl;
                    getch();
                    match=false;
                }
                else{
                
                    isPassword=validatePassword(password);
                    SignedAsMenu();
                    printHeader();
                    printRegistrationHeader();
                    cout << "\t\t\t\t\t"<<"  Enter Your Full Name: ";
                    cin.ignore();
                    getline(cin,name);
                    cout <<"\t\t\t\t\t"<< "  Enter Your Gender (Male or Female): ";
                    cin >> gender;
                    isGender=validateGender(gender);
                    cout << "\t\t\t\t\t"<<"  Enter Your Age: ";
                    cin >> age;
                    isAge=validateAge(age);
                    cout << "\t\t\t\t\t"<<"  Enter Your Country: ";
                    cin >> country;
                    cout << "\t\t\t\t\t"<<"  Enter Your City: ";
                    cin >> city;
                    cout <<"\t\t\t\t\t"<< "  Enter Your Address: ";
                    cin.ignore();
                    getline(cin,address);
                    storeInformation(userName, password,name, isGender, isAge, country,city,address);
                    isAdmin="";
                    userCount++;

                }
               
            }
           else if(isLogin=="1"){
                match=true;
                printHeader();
                printLoginHeader();
                cout << "\t\t\t\t\t"<< "  Enter Your Username: ";
                cin >> userName;
                cout << "\t\t\t\t\t"<<"  Enter Your Password: ";
                cin >> password;
                cout << "\t\t\t\t\t"<<"  Login As admin or customer: ";
                cin >> isAdmin;
                found= checkLogin(userName, password,isAdmin);

                if(found==false){
                    match=false;
                    cout << endl << endl<<"\t\t\t\t\t"<<"  INVALID ENTRY"<< endl <<endl;
                    cout << " Press any key to go back: ";
                    isAdmin="";
                    getch();
                }
            }
            else
            {
                cout << "INVALID ENTRY";
                getch();
            }
        }
        if(isAdmin=="Admin" || isAdmin=="admin" || isAdmin=="ADMIN"){
            AdminEnd="0";
          while(AdminEnd!="10"){
                printHeader();
                printAdminMenu();
                cout << "PLEASE ENTER YOUR CHOICE: ";
                cin >>AdminChoice;
                if(AdminChoice=="1"){
                    printHeader();
                    cout << "    Enter The Name Of Artist You want To Add: ";
                    cin.ignore();
                    getline(cin,artist);
                    AdminChoice1(artist);
                }
               else if(AdminChoice=="2"){
                    printHeader();
                    cout << "    Enter The Name Of Artist You want To Remove: ";
                    cin.ignore();
                    getline(cin,artist);
                    AdminChoice2(artist);
                }
               else if(AdminChoice=="3"){
                    printHeader();
                    cout << "    Enter The type Of Painting You Want To Add: ";
                    cin.ignore();
                    getline(cin,type);
                    AdminChoice3(type);
                }
               else if(AdminChoice=="4"){
                    printHeader();
                    cout << " Enter The Name of Theme You Want To Add: ";
                    cin.ignore();
                    getline(cin,theme);
                    AdminChoice4(theme);
                }
               else if(AdminChoice=="5"){
                    printHeader();
                    cout << "    Enter The Name Of Theme You want To Remove:";
                    cin >> theme;
                    AdminChoice5(theme);
                }
               else if(AdminChoice=="6"){
                    printHeader();
                    isSize= printSizeMenu();
                    if(isSize=="1"){
                        cout <<"    Enter The New Size:";
                        cin >> size;
                        cout <<"    Enter Its Price: ";
                        cin >> price;
                        AdminChoice6Add(size, price);
                    }
                    else if(isSize=="2"){
                        cout <<"    Enter The Size you want to remove: ";
                        cin >> size;
                        AdminChoice6Remove(size);
                    }
                    
                }
              else if(AdminChoice=="7"){
                    printHeader();
                    AdminChoice7();
                }
                else if(AdminChoice=="8"){
                    printHeader();
                    AdminChoice8();
                }
                else if(AdminChoice=="9"){
                    printHeader();
                    cout <<"    Enter order ID:";
                    cin >> ID;
                    cout <<"    Enter Artist Name: ";
                    cin >> name;
                    cout <<"    Enter Painting Type: ";
                    cin >>type;
                    cout <<"    Enter Painting Theme: ";
                    cin >>theme;
                    cout <<"    Enter Painting Size: ";
                    cin >>size;
                    AdminChoice9(ID,name,type, theme,size);
                }
                else if(AdminChoice=="10"){
                    AdminEnd="10";
                }
                else{
                    cout << "INVALID ENTRY";
                    getch();
                }
            }

        }
        else if(isAdmin=="Customer" || isAdmin=="CUSTOMER" || isAdmin=="customer"){
            CustomerEnd="0";
            while(CustomerEnd!="10"){
               system("cls");
               printHeader();
               printCustomerMenu();
               cout << "PLEASE ENTER YOUR CHOICE: ";
               cin >> CustomerChoice;
                if(CustomerChoice=="1"){
                    printHeader();
                    CustomerChoice1();
                }
                else if(CustomerChoice=="2"){
                    printHeader();
                    cout << "    Enter The Artist Name Of The Painting You Want To Add To Your Cart: ";
                    getline(cin, artist);
                    cout << "    Enter The Type Of The Painting You Want To Add To Your Cart: ";
                    cin >> type;
                    cout << "    Enter The Theme Of The Painting You Want To Add To Your Cart: ";
                    cin >> theme;
                    cout << "    Enter The Size Of The Painting You Want To Add To Your Cart: ";
                    getline(cin, size);
                    CustomerChoice2(artist, type, theme, size);
                }
                else if(CustomerChoice=="3"){
                    printHeader();
                    cout << "    Enter The Artist Name Of The Painting You Want To Remove From Your Cart: ";
                    cin.ignore();
                    getline(cin, artist);
                    cout << "    Enter The Type Of The Painting You Want To Remove From Your Cart: ";
                    cin >> type;
                    cout << "    Enter The Theme Of The Painting You Want To Remove From Your Cart: ";
                    cin >> theme;
                    cout << "    Enter The Size Of The Painting You Want To Remove From Your Cart: ";
                    cin >>size;
                    CustomerChoice3(artist, type,theme, size);
                }
                else if(CustomerChoice=="4"){
                    printHeader();
                    CustomerChoice4();
                }
                else if(CustomerChoice=="5"){
                    printHeader();
                    CustomerChoice5();
                }
                else if(CustomerChoice=="6"){
                    printHeader();
                    CustomerChoice6();
                }
                else if(CustomerChoice=="7"){
                    printHeader();
                    CustomerChoice7();
                }
                else if(CustomerChoice=="8"){
                    printHeader();
                    cout << "Enter The Size Of The Painting : ";
                    cin >> size;
                    price =CustomerChoice8(size);
                    if(price==0){
                        cout << "Size Does Not exist"<<endl;
                    }
                    else{
                        cout <<" Painting Price: $" << price;
                    }
                    getch();
                }
                else if(CustomerChoice=="9"){
                    printHeader();
                    price=CustomerChoice9();
                    cout << " TOTAL PAYABLE AMOUNT IS: " << price ;
                    getch();
                    break;
                }
                else if(CustomerChoice=="10"){
                    CustomerEnd="10";
                }
                else{
                    cout << "INVALID ENTRY";
                    getch();
                }

            }
        }
        

    }
}
void printHeader(){
    system("cls");
    cout << "************************************************************************************************************************" << endl;
    cout << "***********************************************ART GALLERY MANAGEMENT SYSTEM********************************************"<< endl ;
    cout << "************************************************************************************************************************" <<endl << endl;
}
void SignedAsMenu(){// Funtion that stores weather the user registered as customer or admin
    system("cls");
    printHeader();
    string choice;
    bool match=false;
    cout << "                                                   ******SELECT******                                                   " << endl;
    cout << "                                    *********************      ********************"<< endl;
    cout << "                                1-  *       ADMIN       *   2- *     CUSTOMER     *"<< endl;
    cout << "                                    *********************      ********************" << endl <<endl;
    while(match==false){
        cout << "                                                   Enter Your Choice: ";
        cin >> choice;
        if(choice=="1"){
            signedAs[userCount]="admin";
            match=true;
        }
        else if(choice=="2"){
            signedAs[userCount]="customer";
            match=true;
        
        }
        else{
           cout << "INVALID ENTRY" <<endl;
           getch();
        }
    }

}
string printFirstMenu(){
    string choice;
    cout << "                                              **********WELCOME**********                                     " << endl<<endl;
    cout << "                                    *********************      *********************"<< endl;
    cout << "                                1-  *       LOGIN       *   2- *      REGISTER     *"<< endl;
    cout << "                                    *********************      *********************" << endl <<endl;
    cout << "                                                   Enter Your Choice: ";
    cin >> choice;
    return choice;
    
}
void printAdminMenu(){
    cout << "                                               ************ADMIN************"<<endl<<endl;
    cout << "********************OPTIONS********************" << endl;
    cout << "1-  Add An Artist" << endl;
    cout << "2-  Remove A specific Artist" <<endl;
    cout << "3-  Add A Type Of Painting" << endl;
    cout << "4-  Add A Themes Of Paintings" << endl;
    cout << "5-  Remove A Theme Of Painting " << endl;
    cout << "6-  Update Available Size And price Of Paintings"<<endl;
    cout << "7-  View List Of Customers And Their Details" << endl;
    cout << "8-  View List Of Pending Orders" << endl;
    cout << "9-  Remove A Pending Order From The List "<< endl;
    cout << "10- Log Out" << endl<<endl;
    cout << "***********************************************" << endl;
    cout << "***********************************************" << endl<<endl;

    

}
void printCustomerMenu(){
    cout << "                                             ************CUSTOMERS************"<<endl <<endl;
    cout << "*************************OPTIONS*************************" << endl;
    cout << "1-  View Your Cart" << endl;
    cout << "2-  Add A Painting To Cart" << endl;
    cout << "3-  Remove A Painting From Cart" << endl;
    cout << "4-  View List Of Artists" << endl;
    cout << "5-  View Avaiable Types Of Paintings" << endl;
    cout << "6-  View Available Size Of Pintings" << endl;
    cout << "7-  View Available Themes Of Paintings" <<endl;
    cout << "8-  View Price Of A Specific Painting"<< endl;
    cout << "9-  Checkout" << endl;
    cout << "10- Log Out" << endl <<endl;
    cout << "*********************************************************" << endl;
    cout << "*********************************************************" << endl << endl;

}

void storeInformation(string userName, string password, string name, string gender, string age, string country, string city, string address){// Function to Register a user

    userNames[userCount]=userName;
    passwords[userCount]=password;
    Names[userCount]=name;
    Gender[userCount]=gender;
    Age[userCount]=age;
    Country[userCount]=country;
    City[userCount]=city;
    Address[userCount]=address;
   
    cout << "                                               ASSIGNED USER ID: "<< UserID[userCount] << endl << endl ;
    cout << "PRESS ANY KEY TO CONTINUE: ";
    getch();
    system("cls");
    
}
void printRegistrationHeader(){
    cout << "\t\t\t\t\t"<<"  **************************************"<< endl;
    cout << "\t\t\t\t\t"<<"  |#|           Registration         |#|"<< endl;
    cout << "\t\t\t\t\t"<<"  **************************************" << endl << endl;
}
bool checkUsername(string username){
    bool match=false;
    for(int i=0;i<200;i++){
        if(userNames[i]==username){
            match=true;
            break;
        }
    
    }
    return match;
}
string validatePassword(string password){
    int length;
    bool correct =false;
    while(correct==false){
        length=password.length();
        if(length==8){
            correct=true;
             
        }
       else{
            cout << "INVALID"<<endl;
            cout << "\t\t\t\t\t"<<"  Enter A Password of 8 Characters: ";
            cin >> password;;
        }
    }
    return password;

}
string validateGender(string gender){
    bool match=false;
    while(match==false){
    if((gender!="male") && (gender!="Male") && (gender!="Female") && (gender!="female")){
        cout << " INVALID ENTRY" <<endl;
        cout <<"\t\t\t\t\t"<< "  Enter Your Gender (Male or Female): ";
        cin >> gender;
    }
    else{
        match=true;
    }
    }
    return gender;
    

}
string validateAge(string age){
    bool match=false;
    int length;
    while(match==false){
        length=age.length();
        for(int i=0; i<length; i++){// To validate that Age is entered in digits
            if(age[i]<48 || age[i]>57){
               match=false;
               cout << " INVALID ENTRY"<<endl;
               cout << "\t\t\t\t\t"<<"  Enter Your Age: ";
               cin >> age;
               break; 
               
            }
            else{
                match=true;
            }
        }
    
    }
    return age;

}
void printLoginHeader(){
    cout <<"\t\t\t\t\t"<< "  **************************************"<< endl;
    cout << "\t\t\t\t\t"<<"  |#|        LOGIN INFORMATION       |#|"<< endl;
    cout << "\t\t\t\t\t"<<"  **************************************" << endl << endl;
}
bool checkLogin(string isUsername, string isPassword, string isAdmin){
    bool match=false;
    if(isAdmin=="Admin" || isAdmin=="admin" || isAdmin=="ADMIN"){
        isAdmin="admin";
    }
    else if(isAdmin=="Customer" || isAdmin=="CUSTOMER" || isAdmin=="customer"){
        isAdmin="customer";
    }
    for(int x=0; x<userCount;x++){
        if(isUsername== userNames[x] && isPassword==passwords[x] && isAdmin==signedAs[x]){
            match=true;
            Number=UserID[x];
            break;
        }

    }
    return match;

}
void initialize(){
    for(int z=0; z<200; z++){
        UserID[z]=z+1;
        orderID[z]=-1;
    }
    for(int z=0; z<50; z++){
        Artists[z]="none";
    }
    for(int z=0; z<20; z++){
        paintingTypes[z]="none";
        paintingThemes[z]="none";
    }
    for(int z=0; z<10; z++){
        paintingSize[z]="none";
        paintingPrice[z]=0;
    }
    


}
void AdminChoice1(string artist){
    bool match=false;
    for(int z=0; z<50;z++){// to check if Artist already exists
        if(Artists[z]==artist){
            match==true;
            cout << "ARTIST ALREADY EXISTS";
            getch();
            break;
        }
    }
    if(ArtistCount==50 && match==false){
        cout << "Maximum 50 Artists Can Be Entered, Space Is Full";
    }
    for(int i=0; i<50; i++){//To make sure no other record of Artists is being overwrited
        if(Artists[i]=="none" && match==false){
            Artists[i]=artist;
            ArtistCount++;
            break;
        }
    }

}
void AdminChoice2(string artist){
    bool match=false;
    for(int i=0; i<50; i++){// To check if the name entered exists in the array or not
        if(Artists[i]==artist){
            Artists[i]="none";
            match=true;
            ArtistCount--;
        }
    }
    if(match==false){
        cout <<" Artist Was Not Found";
        getch();
            
    }

}
void AdminChoice3(string type){
    bool match=false;
    for(int z=0; z<20;z++){//To check if the type entered already exists in the array or not
        if(paintingTypes[z]==type){
            match==true;
            cout << "TYPE ALREADY EXISTS";
            getch();
            break;
        }
    }
    if(TypeCount==20 && match==false){
        cout << "Maximum 20 Types Can Be Entered, Space Is Full";
        getch();
    }
    else{
        for(int i=0; i<20; i++){//To make sure no other record of Types is being overwrited
            if(paintingTypes[i]=="none" && match==false){
                paintingTypes[i]=type;
                TypeCount++;
                break;
            }
        }
    }
}
void AdminChoice4(string newTheme){
 bool match=false;
    for(int z=0; z<20;z++){//To check if the Theme entered already exists in the array or not
        if(paintingThemes[z]==newTheme){
            match=true;
            cout << "THEME ALREADY EXISTS";
            getch();
            break;
        }
    }
    if(ThemeCount==20 && match==false){
        cout << "Maximum 20 Themes Can Be Entered, Space Is Full";
        getch();
    }
    else{
        for(int i=0; i<20; i++){//To make sure no other record of Theme is being overwrited
            if(paintingThemes[i]=="none" && match==false){
                paintingThemes[i]=newTheme;
                ThemeCount++;
                break;
            }
        }
    }
    
}
void AdminChoice5(string removeTheme){
    bool match=false;
    for(int i=0; i<20; i++){// To check if the theme entered exists in the array or not
        if(paintingThemes[i]==removeTheme){
            match=true;
            paintingThemes[i]="none";
            break;
        }
    }
    if(match==false){
        cout <<" Theme Was Not Found";
        getch();
            
    }
}
string printSizeMenu(){
    bool match=false;
    string choice;
    cout <<"*******OPTIONS*******"<<endl;
    cout <<" 1- Add A Size"<<endl;
    cout <<" 2- Remove A Size "<<endl<<endl;
    cout <<" ENTER YOUR CHOICE:"<<endl<<endl;
    cin >> choice;
    return choice;
    while(match==false){
        if(choice=="1" || choice=="2" ){
            match= true;
        }
        if(match==false){
            cout <<" ENTER YOUR CHOICE:";
            cin >> choice;
        }
    }

}
void AdminChoice6Add(string size, float price){
    bool match;
    for(int z=0; z<10;z++){//To check if the Size entered already exists in the array or not
        if(paintingSize[z]==size){
            match==true;
            cout << "SIZE ALREADY EXISTS";
            getch();
            break;
        }
    }
    if(SizeCount==10 && match==false){
        cout << "Maximum 10 Sizes Can Be Entered, Space Is Full";
        getch();
    }
    else{
        for(int i=0; i<10; i++){//To make sure no other record of Size is being overwrited
            if(paintingSize[i]=="none" && match==false){
                paintingSize[i]=size;
                paintingPrice[i]=price;
                SizeCount++;
                break;
            }
        }
    }
    

}
void AdminChoice6Remove(string size){
    bool match=false;
    for(int i=0; i<10; i++){// To check if the Size entered exists in the array or not
            if(paintingSize[i]==size){
                match=true;
                paintingSize[i]="none";
                paintingPrice[i]=0;
                break;
            }
        }
        if(match==false){
        cout <<" Size Was Not Found";
        getch();
            
    }
}

void AdminChoice7(){
    for(int i=0; i<200; i++){// To Show the list of all the customers and their details
        if(signedAs[i]=="customer"){
        cout << "  USER ID: " << UserID[i]<<endl;
        cout << "  NAME: " <<Names[i]<< endl;
        cout << "  GENDER: "<< Gender[i]<< endl;
        cout << "  AGE: "<< Age[i]<<endl;
        cout << "  CITY: " << City[i]<<endl;
        cout << "  COUNTRY: " << Country[i]<<endl;
        cout << "  ADDRESS: " << Address[i]<<endl <<endl;
        }
    }
    getch();
}
void AdminChoice8(){
    int num;
    cout << "**********PENDING ORDERS**********" << endl << endl;
    for(int z=0; z<orderCount; z++){// To view List of all the orders placed and details
        num=orderID[z]-1;
        cout << "  User ID: " << orderID[z]<<endl;
        cout << "  NAME: " <<Names[num]<< endl;
        cout << "  CITY: "<< City[num] <<endl;
        cout << "  COUNTRY: " << Country[num]<<endl;
        cout << "  ADDRESS: " << Address[num]<<endl;
        cout << "  PAINTING: " << endl;
        cout << "  ARTIST: " << Artists[num] <<endl;
        cout << "  TYPE: " << paintingTypes[num];
        cout << "  SIZE: " << paintingSize[num];
        cout << "  THEME: "<< paintingThemes[num] << endl <<endl;
    }
    getch();
}
void AdminChoice9(int ID , string name, string type, string theme, string size){
    bool match=false;
    for(int i=0; i<200; i++){// To remove the wanted record from the pending order list
        if(orderID[i]==ID && orderArtist[i]==name && orderType[i]==type &&  orderTheme[i]==theme && orderSize[i]==size ){
            orderID[i]=-1;
            orderType[i]="none";
            orderTheme[i]="none";
            orderArtist[i]="none";
            orderSize[i]="none";
            orderCount--;
            match=true;
            cout <<endl <<endl<< "Done!";
            break;

        }
    }
    if(match==false){
        cout <<endl << endl<< " Record Does Not Exist";
    }
    getch();


}
void CustomerChoice1(){
    cout << "                                                ***********CART***********"<<endl<<endl;
    for(int i=0; i<200; i++){// To view the cart of the current logged in customer
        if(orderID[i]==Number){
           cout << "     **PAINTING**"<<endl;
           cout << " Artist: " << orderArtist[i]<< endl;
           cout << " Type: " <<orderType[i] <<endl;
           cout << " Theme: "<< orderTheme[i] <<endl;
           cout << " Size: " << orderSize[i] <<endl<<endl;

        }
    }
    getch();
}
void CustomerChoice2(string artist, string type , string theme, string size){

    orderID[orderCount]=Number;// orderID contains the UserID of the person(used as a link)
    orderArtist[orderCount]=artist;
    orderType[orderCount]=type;
    orderTheme[orderCount]=theme;
    orderSize[orderCount]=size;
    orderCount++;
    

}
void CustomerChoice3(string artist, string type , string theme, string size){
    for(int i=0; i<orderCount; i++){// To Remove a order from the cart
        if(orderID[i]==Number && orderArtist[i]==artist && orderType[i]==type &&  orderTheme[i]==theme && orderSize[i]==size ){
            orderID[i]=-1;
            orderType[i]="none";
            orderTheme[i]="none";
            orderArtist[i]="none";
            orderSize[i]="none";
            orderCount--;

        }
    }

}
void CustomerChoice4(){
    bool match=false;
    cout << "********ARTISTS********"<<endl<<endl;
    for(int i=0; i<50; i++){// To view all the list of artists
        if(Artists[i]!="none"){
            match=true;
            cout <<"   " <<  Artists[i] << endl <<endl;
        }

    }
    if(match==false){
        cout << "NO ARTISTS FOUND";
    }
    cout <<endl <<endl<<  "Press Any Key To go back: ";
    getch();

}
void CustomerChoice5(){
    bool match=false;
    cout << "********PAINTING TYPES********"<< endl <<endl;
    for(int i=0; i<20; i++){// To view list of all the Painting types
        if(paintingTypes[i]!="none"){
            match=true;
            cout << paintingTypes[i] << endl<< endl;
        }

    }
    if(match==false){
        cout << "NO TYPES FOUND";
    }
    cout <<endl <<endl<<  "Press Any Key To go back: ";
    getch();

}
void CustomerChoice7(){
    bool match=false;
    cout << "********PAINTING THEMES********"<<endl<<endl;
    for(int i=0; i<20; i++){// To view list of all the Painting Themes
        if(paintingThemes[i]!="none"){
            match=true;
            cout << paintingThemes[i] << endl<<endl;
        }

    }
    if(match==false){
        cout << "NO THEMES FOUND";
    }
    cout <<endl <<endl<<  "Press Any Key To go back: ";
    getch();

}
void CustomerChoice6(){
    bool match=false;
    cout << "********PAINTING SIZES********"<<endl<<endl;
    for(int i=0; i<10; i++){// To view list of all the Painting Sizes
        if(paintingSize[i]!="none"){
            match=true;
            cout << paintingSize[i] << endl<< endl;
        }
    }
    if(match==false){
        cout << "NO SIZES FOUND";
    }
    cout <<endl <<endl<<  "Press Any Key To go back: ";
    getch();
}
float CustomerChoice8(string size){
    float price;
    bool match=false;
    for(int i=0; i<10; i++){// To view price of a specific painting, which depends on its size
        if(paintingSize[i]==size){
            match=true;
            price= paintingPrice[i];
            break;
        }
        
    }
    if(match==false){
        price=0;
        
    }
    return price;
    getch();

}
float CustomerChoice9(){
    float sum=0;
    for(int i=0 ; i<200; i++){// To checkout and show the total amount
        if(orderID[i]==Number){
            for(int z=0; z<200; z++){
                if(orderSize[i]==paintingSize[z]){
                    sum=sum+paintingPrice[z];

                }

            }
            

        }
    }
    return sum;
    getch();

}
void readDataFromFiles(){
    string line,ID;
    fstream file;
    file.open("User_Credentials.txt",ios::in);
    while(!file.eof()){
        getline(file,line);
        userNames[userCount]=getField(line,1);
        passwords[userCount]=getField(line,2);;
        signedAs[userCount]=getField(line,3);
        Names[userCount]=getField(line,4);
        Gender[userCount]=getField(line,5);
        Age[userCount]=getField(line,6);
        Country[userCount]=getField(line,7);
        City[userCount]=getField(line,8);
        Address[userCount]=getField(line,9);
        ID= getField(line,10);
        istringstream(ID) >> UserID[userCount];
        userCount++;

    }
    file.close();
    file.open("Artists.txt",ios::in);
    while(!file.eof()){
        getline(file,line);
        Artists[ArtistCount]=line;
        ArtistCount++;
    }
    file.close();
    file.open("Types.txt",ios::in);
    while(!file.eof()){
        getline(file,line);
        paintingTypes[TypeCount]=line;
        TypeCount++;
    }
    file.close();
    file.open("Themes.txt",ios::in);
    while(!file.eof()){
        getline(file,line);
        paintingThemes[ThemeCount]=line;
        ThemeCount++;
    }
    file.close();
    file.open("Sizes.txt",ios::in);
    while(!file.eof()){
        getline(file,line);
        paintingSize[SizeCount]=getField(line,1);
        ID = getField(line,2);
        istringstream(ID) >>paintingPrice[SizeCount];
        SizeCount++;
        
    }
    file.close();
    file.open("Orders.txt",ios::in);
    while(!file.eof()){
        getline(file,line);
        ID =getField(line,1);
        istringstream(ID) >>orderID[orderCount];
        orderArtist[orderCount]=getField(line,2);
        orderType[orderCount]=getField(line,3);
        orderTheme[orderCount]=getField(line,4);
        orderSize[orderCount]=getField(line,5);
        orderCount++;    
    }
    file.close();

}
string getField (string field, int num){
    int commaCount=1;
    string word="";
    for(int i=0; i<field.length();i++){
        if(field[i]==','){
            commaCount++;
            
        }
        else if(commaCount==num){
            word=word+field[i];

        }
    }
    return word;


}

void storeInFiles(){
    fstream file;
     file.open("User_Credentials.txt",ios::out);
    for(int i=0; i<userCount; i++){
        file << userNames[i] <<",";
        file << passwords[i] <<",";
        file << signedAs[i] <<",";
        file << Names[i] <<",";
        file << Gender[i] <<",";
        file << Age[i] <<",";
        file << Country[i] <<",";
        file << City[i] <<",";
        file << Address[i] <<",";
        file << UserID[i]<<endl;
    }
    file.close();
    file.open("Artists.txt",ios::out);
    for(int i=0; i<ArtistCount; i++){
        file << Artists[i]<<endl;
    }
    file.close();
    file.open("Themes.txt",ios::out);
    for(int i=0; i<ThemeCount; i++){
        file << paintingThemes[i] << endl;
    }
    file.close();
    file.open("Types.txt",ios::out);
    for(int i=0; i<TypeCount; i++){
        file << paintingTypes[i] << endl;
    }
    file.close();
    file.open("Sizes.txt",ios::out);
    if(SizeCount!=0){
    for(int i=0; i<SizeCount; i++){
        file << paintingSize[i] <<",";
        file << paintingPrice[i]<<endl;
    }
    }
    file.close();
    file.open("Orders.txt",ios::out);
    if(orderCount!=0){
    for(int i=0; i<orderCount; i++){
        file << orderID[i] <<",";
        file << orderArtist[i] <<",";
        file << orderType[i] <<",";
        file << orderTheme[i] <<",";
        file << orderSize[i]<<endl;
    }
    }
    file.close();




    
}












