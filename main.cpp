//Taranaki Faamatuainu
//CWID: 886134659

#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
template <typename T> class Item{
public:
T name;
T expiration;
T category;
int quantity;
Item(T n, T e, T c, int q){
name = n;
expiration = e;
category = c;
quantity = q;
}
};
template<typename T> class Inventory{ 

//Vector: 
std::vector<Item<T>> grocery;

//-----------------------------------------------------------------where I coded (Below)
public:
//usercode here:
void addNewItem(Item<T> food){ 
  //step 1: check if food is already in the vector
  bool founditem = false; 
  for(Item<T> chip : grocery){
  
    if(food.name == chip.name){
       founditem = true; // checks the entire list 
    }
  }
if(founditem == true){
  std::cout << "Item is already present in inventory" << std::endl; 
}
  else{
    grocery.push_back(food);
  }
}
  //step 2: If it is in then print "Item is already present"
  //step 3: If not you add it to the list
void increaseQuantity(T itemname, int foodadder){
  for(Item<T>& food : grocery){
//step 1: Find the name of the food that the function is going to change the quanity 
  if(food.name == itemname){
    food.quantity += foodadder;
  }
  }
}
void updateItem(T name, T expiration, T category, int quantity){
 for(Item<T>& food : grocery){
//step 1: Find the name of the food that the function is going to change the quanity 
  if(food.name == name){
    food.quantity = quantity;
    food.name = name;
    food.expiration = expiration; 
    food.category = category; 
  }
  }
} 
void removeItem(T name){
  bool itemfound = false; 
  for(int i=0; i< grocery.size();i++){
    if(name == grocery[i].name){
     itemfound = true; 
      //delete item from vector
      grocery.erase(grocery.begin()+i);
    }
  }
  if(itemfound == true){
    throw "Item not found";
  }
}
// member fucntion: Total (Calculates the total)
void Total(){
    int Aquantity = 0; 
  for(Item<T>& food : grocery){
    Aquantity += food.quantity; 
  }
 std::cout << Aquantity << std::endl;
}
  //member function: Search 
void searchItem(T name){
  bool founditem = false;
   for(int i=0; i< grocery.size();i++){
    if(name == grocery[i].name){
     founditem = true;  // checks the entire list 
  std::cout << "Name:" << grocery[i].name << std::endl; 
  std::cout << "Quantity:" << grocery[i].quantity << std::endl; 
  std::cout << "Expiration:" << grocery[i].expiration << std::endl; 
  std::cout << "Category:" << grocery[i].category << std::endl; 
    }
  }
  if(founditem == false){
    throw "Item not found!!";
}
}
// Write Your code
void displayItems(){
std::cout<<"-------Inventory-------"<<std::endl;
std::cout<<std::left<<std::setw(20)<<"Name"<<std::setw(15)<<"Expiration"<<std::setw
(15)<<"Quantity"<<std::setw(10)<<"Category"<<std::endl;
for(int i=0; i<grocery.size();i++){
std::cout<<std::left <<
std::setw(20)<<grocery[i].name<<std::setw(15)<<grocery[i].expiration<<std::setw(15)<<grocery[i].quantity<<std::setw(15)<<grocery[i].category<<std::endl;
}
}
};
//------------------------------------------------------------------where I coded (Above) ^
template<typename T>class Appointment{
public:
T c_name;
T ap_date;
T ap_time;
T CWID;
Appointment(T n, T d, T t, T cw){
c_name = n;
ap_date = d;
ap_time = t;
CWID = cw;
}
};
template<typename T> 
  class AppointmentSystem{
//-------------------------------------------------------------------where I coded (Below)
public:
std::vector<Appointment<T>> appointment;
//void Schedule 
  void schedule(Appointment<T> AP){
    bool foundCWID = false; 
  for (Appointment<T> id : appointment) {
  
    if((id).CWID == AP.CWID){
       foundCWID = true; // checks the entire list 
    }
  }
if(foundCWID == true){
  std::cout << "You have already scheduled an appointment!!!" << std::endl; 
}
  else{
    appointment.push_back(AP);
  }
  }
  //void Total_Appointments 
  void Total_appointments(T date, T time){
    int Getquantity = 0; 
    for(Appointment<T>& AP : appointment){
      if((AP.ap_date == date) && (AP.ap_time == time)){
        Getquantity += 1;
      }
    }
    std::cout << "Number of appointments:" << Getquantity << std::endl;
  }
  //void Removerecent 
void removeRecent(){
  appointment.pop_back();
}
//-----------------------------------------------------------------where I coded (Above)
void display() {
std::cout<<"-------Appointments-------"<<std::endl;
std::cout<<std::left<<std::setw(20)<<"Name"<<std::setw(15)<<"Date"<<std::setw(15)<<
"Time"<<std::setw(15)<<"CWID"<<std::endl;
for(int i=0; i<appointment.size();i++){
std::cout<<std::left <<
std::setw(20)<<appointment[i].c_name<<std::setw(15)<<appointment[i].ap_date<<std::setw(15)<<appointment[i].ap_time<<std::setw(15)<<appointment[i].CWID<<std::endl;
}
}
};
int main(){
//Remove comments and run following test cases
Inventory<std::string> i1;
Item<std::string> I1("Protien Bar","05/09/2023","Snacks",4);
i1.addNewItem(I1);
Item<std::string> I2("Milk","05/12/2023","Regular",2);
i1.addNewItem(I2);
Item<std::string> I3("Cerels","09/12/2023","Snacks",5);
i1.addNewItem(I3);
i1.displayItems();
i1.updateItem("Milk","09/24/2023","Regular",3);
i1.displayItems();
i1.increaseQuantity("Cerels",10);
i1.displayItems();
try{
i1.updateItem("bar","09/12/2023","Snacks",3);
}
catch(const char* msg){
std::cout <<msg << std::endl;
}
i1.displayItems();
i1.updateItem("Cerels","09/27/2023","Regular",4);
i1.displayItems();
i1.Total();
try{
i1.removeItem("Bread");
}
catch(const char* msg){
std::cout<<msg<<std::endl;
}
try{
i1.removeItem("Milk");
}
catch(const char* msg){
std::cout<<msg<<std::endl;
}
i1.displayItems();
try{
i1.searchItem("Cerels");
}
catch(const char* msg){
std::cout<<msg<<std::endl;
}
Appointment<std::string> a1("John Bob","09/12/2023","9:30AM","889456723");
Appointment<std::string> a2("Jim Lee","09/12/2023","10:30AM","883476923");
Appointment<std::string> a3("Chris Lynn","09/12/2023","12:00PM","879455714");
Appointment<std::string> a4("Arnav Shah","09/12/2023","12:00PM","879459583");
AppointmentSystem<std::string> s1; 
s1.schedule(a1);
s1.schedule(a2);
s1.schedule(a3);
s1.schedule(a4);
s1.display();
s1.Total_appointments("09/12/2023","12:00PM");
Appointment<std::string> a5("Chris Lynn","09/12/2023","12:00PM","879455714");
s1.schedule(a4);
s1.removeRecent();
s1.display();


  return 0;
}
