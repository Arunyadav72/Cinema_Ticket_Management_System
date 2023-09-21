#include<iostream>
#include<string>
using namespace std;

class Booking{

    public: 
        int Floor1[100];
        int Floor2[75];
        int Floor3[50];
        int Floor4[25];
        string Movie_name[3];
        int Movie_price[3];
        string Movie_Time[3];

        void Set_Movie_Details(){
            this->Movie_name[0] = "GADAR";
            this->Movie_price[0] = 100;
            this->Movie_Time[0] = "10Am-12PM";

            this->Movie_name[1] = "JAWAN";
            this->Movie_price[1] = 150;
            this->Movie_Time[1] = "1pm - 3pm";

            this->Movie_name[2] = "CHUP!";
            this->Movie_price[2] = 200;
            this->Movie_Time[2] = "7pm - 10pm";
        }
        void All_seat_zero(int Floor_seat[]){
            for(int i=0; i<sizeof(Floor1) /  sizeof(int); i++){
                Floor_seat[i] = 0;
            }
            
        }

        void Ticket_booking(int seat[], int size, int);
        void View_Movie_Details(string movieName[], int price[], string time[], int size);
        void View_available_seat(int available_seat[], int Total_seat, int);
        void Update_Movie_Details(int number_of);
        void View_user_Ticket(int seat_num, string movie_name, string date_name, int Floor);

};

int main(){
    Booking book;
    book.All_seat_zero(book.Floor1); // Seat Not Booked Means Zero
    book.All_seat_zero(book.Floor2);
    book.All_seat_zero(book.Floor3);
    book.All_seat_zero(book.Floor4);
    book.Set_Movie_Details();

    int choice_point;
    while(1){
        system("cls");
        cout<<"\t\t\t\t\tWELCOME TO MIRAJ CINEMA"<<endl;
        cout<<"\t\t\t\t+-------------------------------------+"<<endl;
        cout<<"\t\t\t\t*   1. Ticket booking...              +"<<endl;
        cout<<"\t\t\t\t*   2. View Movie Details...          +"<<endl;
        cout<<"\t\t\t\t*   3. View available seat..          +"<<endl; 
        cout<<"\t\t\t\t*   4. Update Movie Details..         +"<<endl;
        cout<<"\t\t\t\t*   5. Exit..                         +"<<endl;
        cout<<"\t\t\t\t+-------------------------------------+"<<endl;
        cout<<"\t\t\t\tenter your choice : ";
        cin>>choice_point;

        switch(choice_point){
            case 1:  // Invoked seat booking Method...
                cout<<"\n+---------------------------------------------------------------------------------------------------------------+"<<endl;
                cout<<"\t\t\t Please choose floor option......"<<endl;
                cout<<"\t\t\t 1. Floor";
                cout<<"\t\t   2. Floor"<<endl;
                cout<<"\t\t\t 3. Floor";
                cout<<"\t\t   4. Floor"<<endl;
                cout<<"\t\t\t+-------------------------------------+"<<endl;
                int floor_choice;
                cout<<"\t\t\tenter your choice : "; //!Floor choice statement line.
                cin>>floor_choice;
            
                system("cls");
                if(floor_choice == 1){ // First Floor seat booking..
                    book.Ticket_booking(book.Floor1, sizeof(book.Floor1) / sizeof(int), 1);
                }
                else if(floor_choice == 2){ // Second Floor seat booking..
                    book.Ticket_booking(book.Floor2, sizeof(book.Floor2) / sizeof(int), 2);
                }
                else if (floor_choice== 3){ // Third Floor seat booking..
                    book.Ticket_booking(book.Floor3, sizeof(book.Floor3) / sizeof(int), 3);
                }
                else{ // Fourth Floor seat booking..
                    book.Ticket_booking(book.Floor4, sizeof(book.Floor4) / sizeof(int), 4);
                }
            system("pause");
            break;

            case 2: 
            system("cls"); //Show Movie Details..
                cout<<"\t\t\t\t\t\tView Movie Details..."<<endl;
                cout<<"\t\t\t\t\t+-----------------------------------+"<<endl<<endl;
                book.View_Movie_Details(book.Movie_name, book.Movie_price, book.Movie_Time, sizeof(book.Movie_name)/sizeof(book.Movie_name[0]));
            system("pause");
            break;

            case 3:  // Invoked View available Ticket Mehtod.
                cout<<"\n+---------------------------------------------------------------------------------------------------------------+"<<endl;
                cout<<"\t\t\t Please choose floor option......"<<endl;
                cout<<"\t\t\t 1. Floor";
                cout<<"\t\t   2. Floor"<<endl;
                cout<<"\t\t\t 3. Floor";
                cout<<"\t\t   4. Floor"<<endl;
                cout<<"\t\t\t+-------------------------------------+"<<endl;
            
                int choice;
                cout<<"\t\t\tenter your choice : ";
                cin>>choice;
                system("cls");

                cout<<"\t\t\t\t\t\tDisplay available seat.."<<endl;
                cout<<"\t\t\t\t\t+-----------------------------------+"<<endl;
                
                if(choice == 1){
                    //FIRST FLOOR SEAT NUMBER BOOKING STATUS.....
                    book.View_available_seat(book.Floor1, sizeof(book.Floor1)/sizeof(int), 1);
                }
                else if(choice ==2){
                    //SECOND FLOOR SEAT NUMBER BOOKING STATUS....
                    book.View_available_seat(book.Floor2, sizeof(book.Floor2)/sizeof(int), 2);
                }
                else if(choice == 3){
                    //THIRD FLOOR SEAT NUMBER BOOKING STATUS....
                    book.View_available_seat(book.Floor3, sizeof(book.Floor3)/sizeof(int), 3);
                }
                else{
                    //FOURTH FLOOR SEAT NUMBER BOOKING STATUS....
                    book.View_available_seat(book.Floor4, sizeof(book.Floor4)/sizeof(int), 4);
                }
            system("pause");
            break;

            case 4:  //Update Movie Details...
            system("cls");
            cout<<"\t\t\t\t\t\tUpdate Movie Details..."<<endl;
            cout<<"\t\t\t\t\t+-----------------------------------+"<<endl<<endl;
                book.View_Movie_Details(book.Movie_name, book.Movie_price, book.Movie_Time, sizeof(book.Movie_name)/sizeof(book.Movie_name[0]));

                int no_of;
                cout<<"Which movie number do you want to update? : ";
                cin>>no_of;
                book.Update_Movie_Details(no_of);
            system("pause");
            break;

            case 5:
            cout<<"\t\t\t\t";
            exit(0);
            break;

            default:
            cout<<"\t\t\t\tYour choice is wrong. Please! try again..."<<endl;
            cout<<"\t\t\t\t";
            system("pause");
        }
    }
    return 0;
}

void Booking::Ticket_booking(int seat[], int size, int Floor_num){ //Here Ticket booking statement..
    cout<<"\t\t\t\t\t\tTICKET BOOKING......."<<endl;
    cout<<"\t\t\t\t\t+-----------------------------------+"<<endl;

    //! Here seat choice option...
    int choice_seat;
    string choice_seen_date;
    string choice_movie;


    View_available_seat(seat, size, Floor_num); //Invoked available seat.
    
    cout<<"\nenter your choice seat number : ";
    cin>>choice_seat;

    if(choice_seat>=1 && choice_seat<=size && seat[choice_seat-1] == 0){
        //! Here movie choice option...
        cout<<"enter your movie choice : ";
        cin>>choice_movie;
        cout<<"enter the date : ";
        cin>>choice_seen_date;

        seat[choice_seat-1] = 1;
        cout<<"Your chooses seat successfully booked!"<<endl;
        system("pause");
        system("cls");
        //Display_Movie ticket..
        View_user_Ticket(choice_seat, choice_movie, choice_seen_date, Floor_num);
    }
    else{
        cout<<" seat "<<choice_seat<<" is already booked!";
    }
        
}

void Booking::View_user_Ticket(int seat_num, string movie_name, string date_name, int Floor){

    cout<<"........Miraj cinema ticket......."<<endl;
    cout<<"+---------------------------------+"<<endl;
    cout<<"+    Floor num  : "<<Floor<<endl;
    cout<<"+    Seat num   : "<<seat_num<<endl;
    cout<<"+    Movie name : "<<movie_name<<endl;
    cout<<"+    Date       : "<<date_name<<endl;
    cout<<"+---------------------------------+"<<endl;
}

void Booking::View_available_seat(int available_seat[], int Total_seat, int Floor_num){ //Show available seat

    cout<<Floor_num<<" FLOOR SEAT NUMBER BOOKING STATUS....\n"<<endl;

    for(int i=0;i<Total_seat; i++){

        if(i==10 || i==20 || i==30 || i==40 || i==50 || i==60 || i==70 || i==80 || i==90){
            cout<<endl;
        }

        if(available_seat[i]==0){
            cout<<"["<<i+1<<"A] \t";   //Avaiable seat..
        }  
        else{
            cout<<"["<<i+1<<"B] \t";  //cout<<"Booked! seat..
        }
    }
    cout<<endl<<endl;  
}

void Booking::Update_Movie_Details(int no){
    cout<<"\t\t"<<"enter new Movie name  : ";
    cin>>this->Movie_name[no-1];
    cout<<"\t\t"<<"enter new Movie price : ";
    cin>>this->Movie_price[no-1];
    cout<<"\t\t"<<"enter new Movie time  : ";
    cin>>this->Movie_Time[no-1];
    cout<<"\t\t";
}

void Booking::View_Movie_Details(string movieName[], int price[], string time[], int size){
    cout<<"\t\tNo. \t\tMovie Name \t\tMovie Price \t\t Movie Name"<<endl;
    for(int i=0; i<size; i++){
        cout<<"\t\t"<<i+1<<"\t\t"<<movieName[i]<<"\t\t\t "<<price[i]<<"\t\t\t "<<time[i]<<endl;
    }
    cout<<endl;
    cout<<"\t\t";
}