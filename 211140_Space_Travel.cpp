#include "list_header.h"

using namespace std;
void Register();

int c_date[]={16, 03, 2023};
int month[]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int c_id=200001;
int a_id=100001;


class Planet
{
public:
    string Name;
    int p_ID;
    long long x, y, z;

    Planet(string name, int id, int a, int b, int c)
    {
        Name = name;
        p_ID = id;
        x=a;
        y=b;
        z=c;
    }
};

class Tickets
{

    long long price;

public:
    Planet *source;
    Planet *destination;
    int date[3];
    int id;
    int space_id;
    int c_id;
    

    Tickets(Planet *s, Planet *d, int da, int m, int y, int p, int cid)
    {
        source = s;
        destination = d;
        date[0]=da;
        date[1]=m;
        date[2]=y;
        price = p;
        c_id =cid;
        space_id=-1;
    }

    void renew_price(int p){
     price=p;
    }
};

class Traveller
{

    int traveller_Id;

public:
    string name, gender;
    string age;
    string contact_no;
 
    

    int get_Id()
    {
        return this->traveller_Id;
    }

    void set_Id(int ID)
    {

        traveller_Id = ID;
    }

    void getName()
    {
        cout << "Name: " << name << endl;
    }

    void getId()
    {
        cout << "Id: " << name << endl;
    }



    void update()
    {

        int next;
        int exit=0;
        
        int no_change;
        while(exit!=1){
            cout << "Press 1 to update your name" << endl;
        cout << "Press 2 to update your age" << endl;
        cout << "Press 3 to update your gender" << endl;
        cout << "Press 4 to update your contact no." << endl;
        cout << "Press 5 to Exit" << endl;
       cin>>next;
        switch (next)
        {
        case 1:
            cout << "Currently stored Name: " << name << endl;
            cout << "Press 1 if no change required" << endl;
            cout << "Press 0 to change name" << endl;

            cin >> no_change;

            switch(no_change){
             case 0: cout << "Enter new name" << endl;
                cin >> name;
                break;

            case 1: break;
            default: cout<<"INVALID INPUT"<<endl; exit=1; break;
            }

            break;
        case 3:
            cout << "Currently stored gender: " << gender << endl;
            cout << "Press 1 if no change required" << endl;
            cout << "Press 0 to change gender" <<  endl;
             cin >> no_change;
             switch(no_change){
             case 0: 
             cout << "Enter new gender" << endl;
            cin >> gender;
                break;

            case 1: break;
            default: cout<<"INVALID INPUT"<<endl; exit=1; break;
            }

          break;

        case 2:
            cout << "Currently stored age: " << age << endl;
            cout << "Press 1 if no change required" << endl;
            cout << "Press 0 to change gender" << endl;

            cin >> no_change;

             switch(no_change){
             case 0: 
             cout << "Enter new age" << endl;
            cin >> age;
                break;

            case 1: break;
            default: cout<<"INVALID INPUT"<<endl; exit=1; break;
            }
          break;

        case 4:
            cout << "Currently stored contact No.: " << contact_no << endl;
            cout << "Press 1 if no change required" << endl;
            cout << "Press 0 to change contact No." << endl;
            cin >> no_change;

             switch(no_change){
             case 0: 
            cout << "Enter new contact No." << endl;
                cin >> gender;
                break;

            case 1: break;
            default: cout<<"INVALID INPUT"<<endl; exit=1; break;
            }
           break;

        case 5:
        exit=1;
            break;

        default:
            cout << "Please Enter a valid input" << endl;break;
            
        }
        if (exit ) break;
        cout<<"If no further changes, press 1, else 0"<<endl;
        cin>>exit;
        }
        cout << "Thank you for using our services" << endl;
    }
    
};

class Passenger : public Traveller
{

public:

    std::map<int, Tickets *> past_bookings;
    static int P_count;
    int ticket_count;
    Passenger(string n, string g, string a, string p)
    {
        name=n;
        gender=g;
        age=a;
        contact_no=p;
        ticket_count = 0;
        P_count++;
        set_Id(P_count);
        cout << fixed << setprecision(6) << setfill('0');
        cout << "Your ID is " << setw(6) << get_Id() << endl;
        cout << "Please remember in order to login." << endl;
    }

    void Display_All()
    {
        std::map<int, Tickets *>::iterator it = past_bookings.begin();
        while (it != past_bookings.end())

        {
            cout<<"Customer name: "<<this->name<<endl;
            cout <<"Ticket Id: "<< it->first <<endl;
            cout<< "Source Planet: " <<it->second->source->Name<<endl;
             cout<<"Destination Planet " << it->second->destination->Name <<endl;
            cout<< "Date of travel " << (it->second->date[0])<<"."<<it->second->date[1] <<"."<<it->second->date[2]<< endl;
            if (it->second->space_id!=-1){
            
                cout<<"Space id: "<<it->second->space_id<<endl;
                

            }
            else {
                cout<<"Your spacecraft is yet to be determined"<<endl;
            }
             
            
            it++;

        }
    }

    void Display_single(int c_ID)
    {
        Tickets *it = past_bookings[c_ID];
         cout<<"Customer name: "<<this->name<<endl;
        cout <<"Ticket Id: " <<c_ID <<endl;
        cout<< "Source Planet: " << it->source->Name << endl;
        cout<<"Destination Planet " << it->destination->Name <<endl;
        cout<< "Date of travel " << it->date[0]<<"." <<it->date[1]<<"."<<it->date[2]<< endl;
         if (it->space_id!=-1){
                cout<<"Space id: "<<it->space_id<<endl;
            }
            else {
                cout<<"Your spacecraft is yet to be determined, "<<endl;
            }
            //  cout<<A.get_commander(it->space_id)<<endl;
            // cout<<A.get_astronaut(it->space_id)<<endl;
    }

    int Add_Ticket(Tickets *t)
    {
        ticket_count++;
        past_bookings.insert({ticket_count, t});
        return ticket_count;
    }
};

int Passenger::P_count = 0;

class Astronaut : public Traveller
{
    int experience;
     
public:

    static int A_count;
    int scheduled;
  
   
     Astronaut(string n, string g, string a, string p)
    {
        name=n;
        gender=g;
        age=a;
        contact_no=p;
        scheduled=1;
        A_count++;
        experience=0;
        set_Id(A_count);
        cout << "Your ID is " << setw(6) << get_Id() << endl;
        cout << "Please remember in order to login." << endl;
    }


    void set_experience(int a){
          this->experience=a;
    }

    

};

int Astronaut::A_count = 100000;

class Commander : public Traveller
{
    int experience;
    int authority;

public:
    
   int scheduled;
    static int C_count;
  
    Commander(string n, string g, string a, string p)
    {
        name=n;
        gender=g;
        age=a;
        contact_no=p;
        C_count++;
        scheduled=0;
        set_Id(C_count);
       authority=10;
        cout << "Your ID is " << setw(6) << get_Id() << endl;
        cout << "Please remember in order to login." << endl;
    }

    void set_authority(int a){
          authority=a;
    }

};

int Commander::C_count = 200000;

class Space_Travel
{
    public:
    static int count;
    vector<Passenger *> passengers;
    int A;
    int C;
    int space_id;
    Planet *source;
    Planet *destination;
    int* travel_date;
    int p_count;

    Space_Travel(){
        A=0;
        C=0;
       count++;
       space_id=count;
        p_count=2;
    }

    


};

int Space_Travel::count=0;

class unlisted_bookings{
    public:
 Passenger* p;
int* travel_date;
 Planet*source;
 Planet*destination;
 int t_id;

 
 
};

class Admin
{

    std::map<int, Passenger *> reg_list_P;
    std::map<int, Astronaut *> reg_list_A;
    std::map<int, Commander *> reg_list_C;
    std::map<int, Planet *> reg_list_Pl;
    vector<Space_Travel*> Trips;
    vector<unlisted_bookings*> bookings;
   

public:

   
   void delete_unlisted(int id, int t_id){
     
     vector<unlisted_bookings*> :: iterator it;

     it= bookings.begin();
     while(it!=bookings.end()){
        if ((*it)->p->get_Id()==id && (*it)->p->past_bookings.find(t_id)!= (*it)->p->past_bookings.end()){
            bookings.erase(it);
        }
        it++;
     }

      

   } 

    void delete_passenger(int s, int id){
    
     vector<Space_Travel*>::iterator it;
     int found=0;
     it=Trips.begin();
     while(it!=Trips.end()){

        if ((*it)->space_id==s){
        for (auto i= (*it)->passengers.begin(); i!=(*it)->passengers.end(); i++){
            if ((*i)->get_Id()==id) { ((*it)->passengers.erase(i));
            found=1;
            (*it)->p_count--;
            return; 
            }
        }
        
        if(found==0) {cout<<"\nInvalid Request Passenger"<<endl; return ;}
        }
        it++;
     }
     if (it==Trips.end()) cout<<"Invalid Space Id"<<endl;

    }
    int Check_Trip(Planet *s, Planet *d, int* date, Passenger*p, int id)
    {
        int mode=0;
        vector<Space_Travel*>::iterator it;
        it=Trips.begin();
        while(it!=Trips.end()){
            if ((*it)->source==s && (*it)->destination==d && (*it)->travel_date==date && (*it)->p_count<10){
                (*it)->p_count++;
                (*it)->passengers.push_back(p);
                Tickets* t;
               t=p->past_bookings[id];
               t->space_id=(*it)->space_id;

                mode=2;
                break;
            }

            it++;
        }
        if (mode==0){
            vector<unlisted_bookings*>::iterator it;

             it=bookings.begin();
             while(it!=bookings.end()){
                 if ((*it)->source==s && (*it)->destination==d && (*it)->travel_date==date ) {
                    Space_Travel* t= new Space_Travel();
                
                     
                    t->C=c_id;
                    c_id++;
                    t->C=a_id;
                    a_id++;
                    t->passengers.push_back(p);
                    t->passengers.push_back((*it)->p);
                    t->source=s;
                    t->destination=d;
                    t->travel_date=date;
                    (*it)->p->past_bookings[(*it)->t_id]->space_id=t->space_id;
                    p->past_bookings[id]->space_id=t->space_id;
                    mode=1;     
                    add_trip(t);
                    bookings.erase(it);
                 }
             }

             if (mode==0){
                unlisted_bookings* u= new unlisted_bookings;
                u->source=s;
                u->destination=d;
                u->p=p;
                u->t_id=id;
                u->travel_date=date;
                bookings.push_back(u);
             }
        

        }

return mode;
        

    }

   int get_commander(int id){
        vector<Space_Travel*> ::iterator it= Trips.begin();
        while(it!=Trips.end()){
            if ((*it)->space_id==id) return (*it)->C;
        }

       return -1;
        
    }

    int get_astronaut(int id){

        vector<Space_Travel*> ::iterator it= Trips.begin();
        while(it!=Trips.end()){
            if ((*it)->space_id==id) return (*it)->A;
        }

       return -1;

    }

    void add_trip(Space_Travel* s){

        Trips.push_back(s);

    }

    
   void display_c_details(int ID){
    Commander* it= reg_list_C[ID];

    if (it!=NULL){
             cout << "Name : " << it->name << endl;
            cout << "Age : " << it->age << endl;
            cout << "Gender : " << it->gender << endl;
            cout << "Contact No. " << it->contact_no << endl;
         }

         else{
             reg_list_C.erase(ID);
            cout << "Invalid user" << endl;
         }
   }

     int available_A(){
        
       std::map<int, Astronaut *> ::iterator it=reg_list_A.begin();
       while(it!=reg_list_A.end()){
        if (it->second->scheduled==0) {
            it->second->scheduled=1;
            return it->second->get_Id();
        }
       }

       return -1;

      

     }

    int available_C(){

        std::map<int, Commander *> ::iterator it=reg_list_C.begin();
       while(it!=reg_list_C.end()){
        if (it->second->scheduled==0) {
            it->second->scheduled=1;
            return it->second->get_Id();
        }
       }
       return -1;

     }
        
     

    void display_a_details(int ID){
         Astronaut* it= reg_list_A[ID];
         
         if (it!=NULL){
             cout << "Name : " << it->name << endl;
            cout << "Age : " << it->age << endl;
            cout << "Gender : " << it->gender << endl;
            cout << "Contact No. " << it->contact_no << endl;
         }

         else{
             reg_list_A.erase(ID);
            cout << "Invalid user" << endl;
         }
    }

    void display_p_details(int ID)
    {
        Passenger *it = reg_list_P[ID];

        if (it != NULL)
        {
            cout << "Name : " << it->name << endl;
            cout << "Age : " << it->age << endl;
            cout << "Gender : " << it->gender << endl;
            cout << "Contact No. " << it->contact_no << endl;
        }

        else
        {
            reg_list_P.erase(ID);
            cout << "Invalid user" << endl;
        }
    }
    void reg_P(Passenger *new_p, int id)
    {
        reg_list_P.insert({id, new_p});
    }

    void reg_A(Astronaut *new_a, int id)
    {
        reg_list_A.insert({id, new_a});
    }

    void reg_C(Commander *new_c, int id)
    {
        reg_list_C.insert({id, new_c});
    }
    void reg_Pl(Planet *p, int id)
    {

        reg_list_Pl.insert({id, p});
    }
    Passenger *find_p(int ID)
    {
        std::map<int, Passenger *>::iterator it = reg_list_P.begin();

        while (it != reg_list_P.end())
        {
            if (it->first == ID)
                break;
            it++;
        }
        if (it == reg_list_P.end())
            return NULL;
        return it->second;
    }

    Astronaut* find_a(int ID){
         Astronaut* it= reg_list_A[ID];
          if (it==NULL){
             reg_list_A.erase(ID);
             return NULL;
          }
          return it;
    }

    Commander* find_c(int ID){
          
          Commander* it= reg_list_C[ID];
          if (it==NULL){
             reg_list_C.erase(ID);
             return NULL;
          }
          return it;
    }


    Planet *choose_planet()
    {
        int p_no;
        std::map<int, Planet *>::iterator it = reg_list_Pl.begin();
        while (it != reg_list_Pl.end())
        {
            cout << it->first << " " << it->second->Name << endl;
            it++;
        }

        cout << "Please enter the corresponding planet key" << endl;
        cin >> p_no;
        if (reg_list_Pl[p_no] != NULL)
            return reg_list_Pl[p_no];
        else
        {
            reg_list_Pl.erase(p_no);
            return NULL;
        }
    }
};
Admin A;
void View_Details(int verify_no)
{

    int role;
    role = verify_no / 100000;
    cout<<role<<endl;
    int op;

   
    switch (role)
    {
    case 0:
        A.display_p_details(verify_no);
        break; 
    case 1:
        A.display_a_details(verify_no);
       break;

    case 2: 
        A.display_c_details(verify_no);
        break;

    default:;
        break;
    }
}

long long c_days(int*d){
 long long days=0;
  days= d[2]*365+ d[1];

  for (int i=0; i<12; i++){
        days+=month[i];
    }



 return days;
}


int valid(int* d){
    
    if (d[2]-c_date[2]>10) return 0;
    if (d[2]-c_date[2]<0) return 0;
    if (d[2]==c_date[2]){
        if (d[1]< c_date[1]) return 0;
        if (d[0]<c_date[0] && d[1]==c_date[1]) return 0;
    }
    return 1;

}

long long int set_distance(long long a, long long b, long long c, long long d, long long e,  long long f ){
    long long q;
    long long x, y, z;
    x=a-d;
    y=b-e;
    z=c-f;
    x= pow(x, 2);
    y=pow(y, 2);
    z=pow(z, 2);
    q= x+y+z;
    q=sqrt(q);
    return q;
}

int set_price(int*date, int d){
       
    int p;
    int m;
    m= (date[2]-c_date[2])*12+ (date[1]-c_date[1])+1;
    p= (1500*d)/m;

    return p;

}

void Book_Tickets()
{
    int next;
    Planet *s_planet;
    Planet *d_planet;
    int price;
    long long int d;
    
    // int price;
    int c_ID;
    int role;
    int confirm;
    int trip;
    Passenger *p;
    Commander * c;
    Astronaut* a;

    cout << "If you have not yet registered, kindly register first" << endl;
    cout << "To book tickets, Kindly press 1, else press 2" << endl;
    cin >> next;
    switch (next)
    {
    case 1:
        cout << "Please enter your registered ID " << endl;
        cin >> c_ID;
        role = c_ID / 100000;
        switch (role)
        {
        case 0:
            p = A.find_p(c_ID);
            if (p == NULL)
            {
                cout << "Invalid ID" << endl;
            }
            else
            {
                View_Details(c_ID);
                cout << "Press 1 if these details are yours, else press 0" << endl;
                cin >> confirm;
                if (confirm)
                {
                    confirm = 0;
                    cout << "Please choose your source planet" << endl;
                    s_planet = A.choose_planet();
                    cout << "Please choose your destination planet" << endl;
                    d_planet = A.choose_planet();
                    int t_date[3] ;
                    cout<<"Please enter date in dd_mm_yyyy format, underscore stands for space"<<endl;
                    cin>>t_date[0]>>t_date[1]>> t_date[2];
                    if (valid(t_date)){
                        d= set_distance(s_planet->x, s_planet->y, s_planet->z, d_planet->x, d_planet->y, d_planet->z);
                          price=set_price(t_date, d);
                    cout << "Source Planet: " << s_planet->p_ID << " " << s_planet->Name << endl;
                    cout << "Destination Planet: " << d_planet->p_ID << " " << d_planet->Name << endl;
                    cout << "Date of Travel: " << t_date[0]<<"."<<t_date[1]<<"."<<t_date[2] << endl;
                    cout << "Price: " <<price << endl;
                    cout << "Press 1 to confirm" << endl;
                    cin >> confirm;
                    if (confirm)
                    {
                        cout<<1<<endl;
                        Tickets *t = new Tickets(s_planet, d_planet, t_date[0],t_date[1], t_date[2], 1000, c_ID);
                        cout<<1<<endl;
                        int id=p->Add_Ticket(t);
                        cout<<1<<endl;
                        t->id=id;
                        cout<<1<<endl;
                        trip = A.Check_Trip(s_planet, d_planet, t_date, p, id);
                        cout<<1<<endl;
                        if (trip==1 || trip==2){
                            cout<<"Your Spacecraft had been determined. For more information check your ticket"<<endl;
                        }
                        
                        else {
                           cout<<"Your spacescraft is yet to be decided. For more information keep checking your ticket"<<endl;
                        }
                        cout << "Your bookings have been confirmed " << endl;
                        cout<<"Your ticket id is "<<t->id<<endl;
                        cout << "You can view your bookings through view tickets option in Menu" << endl;
                    }
                    else
                    {
                        ;
                    }
                    }
                    else{cout<<"Invalid input"<<endl; }
                }
                else
                {
                    cout << "Please start agin" << endl;
                }
            }
            break;

        default:
        cout<<"Invalis Input"<<endl;
            break;
        }
  break;
  case 2:
  cout<<"Thank you "<<endl;
  break;
    default:
        cout << "Inavlid input" << endl;
        ;
        break;
    }
}

void Delete_Tickets(){

    int ID, confirm;
    int con;
    int t_id;

    int choice, tid;
    cout << "Please enter your traveller_Id" << endl;
    cin >> ID;
    Passenger *p = A.find_p(ID);
    if (p == NULL)
        cout << "Invalid User" << endl;
    else{
         View_Details(ID);
        cout << "Press 1 if your details are being shown, else 0" << endl;
        cin >> confirm;
        if (confirm){
             cout<<"Plese enter the ticket id to delete"<<endl;
             cin>>t_id;
            //   p->Display_single(t_id);
               cout<<"Please press 1 to confirm to delete ticket, else press 0"<<endl;
              
            cin>>con;
            if (con)
             {Tickets*t=p->past_bookings[t_id];
             
             if (t->space_id!=-1){
                A.delete_passenger(t->space_id, p->get_Id());
             }
             else{
                A.delete_unlisted(p->get_Id(), t_id);
             }
              p->past_bookings.erase(t_id);
             delete(t);
             cout<<"Your ticket has been deleted"<<endl;
             }
        }
         else
        {
            cout << "Invalid Input" << endl;
        }
    }


}

void Update_Tickets(){
       
    int ID, confirm;
    int d[3];
    int dis, price;

    int choice, tid, s_id, k;
    cout << "Please enter your traveller_Id" << endl;
    cin >> ID;
    Passenger *p = A.find_p(ID);

    if (p == NULL)
        cout << "Invalid User" << endl;
    else{

        View_Details(ID);
        cout << "Please press 1 if your details are being shown, else press 0" << endl;
        cin >> confirm;
       
        if (confirm){
             cout<<"Please enter your ticket id"<<endl;
             cin>>tid;
             
             Tickets* t= p->past_bookings.find(tid)->second;
             if (t!=NULL){
             
           cout<<"Press 1 to change the source planet"<<endl;
           cout<<"Press 2 to change the destination planet"<<endl;
           cout<<"Press 3 to change the travel date"<<endl;
           cout<<"Press 4 to exit"<<endl;
           cin>>choice;
           switch(choice){
               case 1: 
                t->source=A.choose_planet();
               break;

               case 2: 
               t->destination=A.choose_planet();
               break;

               case 3: 
               cout<<"Please enter date in dd_mm_yyyy format , underscore stands for space"<<endl;
               cin>>d[0]>>d[1]>>d[2];
               t->date[0]=d[0];
               t->date[1]=d[1];
               t->date[2]=d[2];
               dis= set_distance(t->source->x, t->source->y, t->source->z, t->destination->x, t->destination->y, t->destination->z);
               price=set_price(t->date, dis);
               break;

               case 4: 
               cout<<"Invalid Input"<<endl;
               return;
             
           }
             if (t->space_id==-1) A.Check_Trip(t->source, t->destination, t->date, p, t->id);
             else{
                A.delete_passenger(t->space_id, p->get_Id());
                t->space_id=-1;
                A.Check_Trip(t->source, t->destination, t->date, p, t->id);
             }
        }
          else cout<<"Invalid ticket id"<<endl;
        }
      

    }
    
    


}

void View_Tickets()
{
    int ID, confirm;

    int choice, tid, s_id;
    int k;
    cout << "Please enter your traveller_Id" << endl;
    cin >> ID;
    Passenger *p = A.find_p(ID);
    if (p == NULL)
        cout << "Invalid User" << endl;
    else
    {
        View_Details(ID);
        cout << "Press 1  if your details are being shown, else 0" << endl;
        cin >> confirm;
        if (confirm)
        {
            cout << "To view all Bookings click 1 , to view a specific booking using ticket ID click 2 , 0 to exit" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
                p->Display_All();
                break;
            case 2:
                cout << "Enter the ticket_ID" << endl;
                cin >> tid;
                p->Display_single(tid);break;
            default: cout<<"Invalid Input"<<endl;
            }
            // cout<<"Press 1 to view astronaut and commander details for your spacecraft, else press 0"<<endl;
            // cin>>k;
            // switch(k){
            //     case 1: 
            //     cout<<"Please enter space id, if space id has been registered"<<endl;
            //     cin>>s_id;
            //     find_ca(s_id);
            //     break;

            //     default: ;
            //     break;
            // }
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
}

void Update_Details(int id){

     int role;
    role = id / 100000;
    int op;
    
   Passenger* p;
   Astronaut* a;
   Commander* c;
   
    switch (role)
    {
    case 0:
        p = A.find_p(id);
            p->update();
        break;
    case 1: a=A.find_a(id);
            a->update();
            break;

    case 2:
      c= A.find_c(id);
      c->update();
      break;
            
    default: 
        break;
    }
    
}

int Menu()
{
    cout << "___________________________________________________________________________" << endl;
    cout << "\t\t\t\t\t\t\tSpace Travel System" << endl;
    cout << "\t\t\t_____________________________________________________\n";
    cout << "\t\t\t\t\t\t\t\t Main Menu" << endl;

    int next;
    cout << "Press 1 to register as a new user" << endl;
    cout << "Press 2 to view or update traveller details" << endl;
    cout << "Press 3 to book tickets" << endl;
    cout << "Press 4 to view or delete or update existing tickets " << endl;
    cout << "Press 5 to Exit " << endl;

    cin >> next;
    int role;
    int ID;
    int op;
    int d;

    switch (next)
    {
    case 1:
        Register();
        break;

    case 2:
        cout << "Please enter your traveller_Id" << endl;
        cin >> ID;
         cout<<"Please Enter 1 if you want to view details"<<endl;
         cout<<"Please Enter 2 if you want to update details"<<endl;
         cin>>op;
         switch(op){
            case 1:  View_Details(ID); break;
            case 2:  Update_Details(ID); 
            break;
            default: cout<< "\n INVALID INPUT \n"<<endl;
            break;
        }
        break;

    case 3:
        Book_Tickets();
        break;

    case 4:
    cout<<"Press 1 to view tickets"<<endl;
    cout<<"Press 2 to delete tickets"<<endl;
    cout<<"Press 3 to update tickets"<<endl;
    cout<<"Press 4 to exit"<<endl;
    cin>>d;
    switch(d){
        case 1: View_Tickets(); break;
        case 2:Delete_Tickets(); break;
        case 3: Update_Tickets(); break;
        case 4: ; break;
        default : cout<< "\n INVALID INPUT \n"<<endl; break;
    }
       
        break;

    default:
    next=5;;
        break;
    }
    return next;
}

void Register()
{

  char role;
  string name, age, gender, contact_no;

    cout << "Press 1 to register" << endl;
    cout << "Press 2 to exit" << endl;
    cin >> role;

    if (role=='1')
    {
        
        cout << "Please Enter Your Name with no space" << endl;
        cin >> name;
        cout << "Please Enter Your gender" << endl;
        cin >> gender;
        cout << "Please Enter Your age" << endl;
        cin >> age;
        cout << "Please Enter Your Contact No." << endl;
        cin >> contact_no;
        Passenger *p = new Passenger(name, gender, age, contact_no);

        A.reg_P(p, p->get_Id());
        cout << "Thank you for Registering" << endl;
    }

    else if (role == '2')
    {
        ;
    }

    else
    {
        cout << "Inavlid Input" << endl;
    }
}

int main()
{
    Planet *p = new Planet("Moon", 1, 0, 0, 0);
    A.reg_Pl(p, p->p_ID);
    Planet *q = new Planet("Earth", 2, 1, 1, 1);
    A.reg_Pl(q, q->p_ID);
    Planet* r= new Planet("Mars", 3, 3, 4,6 );
    A.reg_Pl(r, r->p_ID);
    Commander* c1= new Commander("Mansi","female","45", "7985061372") ;
    A.reg_C(c1, c1->get_Id());
    Commander* c2= new Commander("Anand", "Male", "47", "1234567890");
    A.reg_C(c2, c2->get_Id());
    Commander* c3= new Commander("Mahesh", "Male", "45", "3457965074");
    A.reg_C(c3, c3->get_Id());
    Astronaut* a1= new Astronaut("Shubham", "male", "30", "8657342190");
    A.reg_A(a1, a1->get_Id());
    Astronaut* a2= new Astronaut("Aryan", "Male", "34", "7654890234");
     A.reg_A(a2, a2->get_Id());
    Astronaut* a3= new Astronaut("Shruti", "Female", "32", "8965478342");
     A.reg_A(a3, a3->get_Id());

    int input;
    while (1)
    {
        input = Menu();
        if (input == 5)
            break;
    }

    return 0;
}