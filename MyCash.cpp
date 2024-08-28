#include<bits\stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std;
string supto;
bool logg_in()
{  
    string user_name;string password;
    string us,pw,mob,NI,Acc;
    cout<<"Enter your User Name"<<endl;
    cin>>user_name;
    fstream read1(user_name +".txt",ios::in);
     if (!read1.is_open())
    {
    cout << "This Username is Not Found" << std::endl;
        return false;
    }
    supto=user_name;
    cout<<"Enter your password"<<endl;
    cin>>password;
    getline(read1,us);
    getline(read1,pw);
    if(us==user_name && pw==password)
    {
        return true;
    }
    else 
    {
        return false;
    }  
}
bool check_password()
{  string  password;
string us,pw;
    cout<<"Enter your password"<<endl;
    cin>>password;
    ifstream read(supto +".txt");
    getline(read,us);
    getline(read,pw);
    if( pw==password)
    {
        return true;
    }
    else 
    {
        return false;
     }  
};
class Home
{   public:
    int random;int enter_persona=0;
    string name;int balance; 
    string acccount_nmbr;int money;
    private:
   void CashOut();void cash_in();
   void Sendmoney();
   void Mobile_Recharge();
   void  Payment();int make_password_strong(string s);
   void Bill_pay();
   void Mycash();
   void pin_Recet();
   void Sin_up();int human_varification();
   void log_in();void change_password();
    void check_number();int check_number_oper(string a,int b);
    void cash_save();void getloan();void read_lenden();
    void OTP();int check_mail(string w);void store_Lenden(int a,string s);
    void initialize();int check_username(string love);
    public:
    void display_home();
};
void Home::initialize()
{
    fstream File;
    File.open(supto +".txt",ios::in);

        string a1, a2, a3, a4, a5;
        int a6;
        File >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
        File.close();
         money = a6;
        
}
void Home::store_Lenden(int a,string s)
{
 fstream file;
 file.open(supto+"1.txt",ios::app);
 time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  file<<"You have  "<<s<<" Money::"<<a<<" TK::-----:::  Time and Date::"<<asctime(timeinfo);
  file.close();
}
void Home::read_lenden() {
    string a;int d=1;
    ifstream file;  
    file.open(supto + "1.txt");

    cout << "Your Len-den is:" << endl;
    string s;

    while (file >> s)
     {  
        cout <<" ::"<< s << " ";
         if(s=="2023") {cout<<endl;}
    }
    file.close();
    cout<<endl;
    display_home();
}

int Home::human_varification()
{   srand(time(0));
    int a=rand()%10;
    int b=rand()%10;bool operat=rand()%2==1;
    if(operat)
    {
    int sum=a+b;int res;
    cout<<"Calculate Sum to prove you're a human"<<endl;
    cout<<a<<" +  "<<b<<endl;
    cin>>res;
    if(res==sum)
    {
         cout<<"Welcome to SuptoCash:"<<endl;  return 1;
    }
    else return 0;
    }
    else 
    {
         int dif=a-b;int res;
    cout<<"Calculate Difference to prove you're a human"<<endl;
    cout<<a<<" -  "<<b<<endl;
    cin>>res;
    if(res==dif)
    {
        cout<<"Welcome to SuptoCash:"<<endl;  return 1;
    }
    else return 0;
    }
}
int Home::check_number_oper(string a,int s)
{char arr[a.length()];
   if(s==16){if(a.length()==16) {return 1;}else {cout<<"You have entered :: "<<a.length()<<"  Digit.That is not coorect"<<endl;}return 0;}
   if(a.length()==11 )
    { 
       for(int i=0;i<a.length();i++)
     {
         arr[i]=a[i];
     }
    if(s==0){if(arr[0]=='0' && arr[1]=='1') return 1;}
    else if(s==1){if(arr[0]=='0' && arr[1]=='1' &&(arr[2]=='7'|| arr[2]=='3')) return 1;else return 0;}
    else if (s==2) {if(arr[0]=='0' && arr[1]=='1' && (arr[2]=='9'|| arr[2]=='4')) return 1;else return 0;}
    else if(s==3) {if(arr[0]=='0' && arr[1]=='1' && arr[2]=='8') return 1;else return 0;}
    else if(s==4) {if(arr[0]=='0' && arr[1]=='1' && arr[2]=='6') return 1;else return 0;}
    } 
  else{ cout<<"You entered a invalid phone number"<<endl;return 0;}
  return 0;
}


void Home::OTP()
{    srand(time(0));
     random=rand();
     cout<<"Your 1 time OTP is ::"<<random<<endl;
}
void Home::cash_save()
{ 
string st1,st2,st3,st4,st5,pw,pw2;int st6;
fstream File;
File.open(supto +".txt",ios::in);
File>>st1>>st2>>st3>>st4>>st5>>st6;
File.close();
File.open(supto +".txt",ios::out);
st6=money;
File<<st1<<endl<<st2<<endl<<st3<<endl<<st4<<endl<<st5<<endl<<st6;
File.close();
}


 void Home:: change_password()
{  
     string st1,st2,st3,st4,st5,pw,pw2;int st6;
    ifstream  fileIn;
    fileIn.open(supto +".txt");
    cout<<"Enter previous password"<<endl;
    cin>>pw;
    fileIn>>st1>>st2>>st3>>st4>>st5>>st6;
    if(pw==st2)
    { 
        cout<<"Enter new password"<<endl;
        cin>>pw2;
        fileIn.close();
        ofstream fileOut(supto + ".txt");
         fileOut << st1 << '\n' << pw2 << '\n' << st3 << '\n' << st4 << '\n' <<st5 << '\n'<<st6;
          fileOut.close();
        cout<<"You've successfully changes your password"<<endl;
    }
    else 
    {
        cout<<"Sorry your password is not matched"<<endl;
    }
    cout<<"1::Home               "<<"    "<<"2::Log out"<<endl;int a;
    cin>>a;
    if(a==1){display_home();}  else if(a==2) {exit(0);}
}

void Home::cash_in()
{  
int a;int daa;
 cout<<"Enter your ammount"<<endl;
cin>>a;string d="Cash In";
bool lll=check_password();
if(lll==true) 
   {
    OTP();
    cout<<"Enter Your OTP"<<endl;
    cin>>daa;if(daa==random)
    {
    money=a+money;
    cout<<"Successfully you have cash in  money"<<"::"<<a<<" TK"<<endl;
    cash_save();
    store_Lenden(a,d);
    }
    else {cout<<"You have enter wrong OTP"<<endl;}
    display_home();
    }
    else 
    {
        cout<<"Sorry you've entered wrong password"<<endl;
        display_home();
    }
}

void Home::CashOut()
{
 int a;
 cout<<"How many money you wanto cashout"<<endl;
 cin>>a;string e="Cash Out";
 bool l4=check_password();
if(l4==true)
   {
    money=money-a;
    cout<<"Successfully you have Cash Out"<<"::"<<a<<" TK"<<endl;
    cash_save();
    store_Lenden(a,e);
    display_home();
    }
    else 
    {
        cout<<"Sorry you've entered wrong password"<<endl;
        display_home();
    }
}

void Home::Mobile_Recharge()
{
int a;int b;string number;
cout<<"Select opererator::"<<endl;
cout<<"1::Gp"<<"             "<<"2::Bangalink"<<endl;
cout<<"3::Robi"<<"      "<<"4::Airtel"<<endl;
cin>>a;
int  w;
if(a==1||a==2||a==3||a==4)
{ 
   cout<<"Enter number::"<<endl;
   cin>>number;
     w=check_number_oper(number,a);
     if(w==0){ cout<<"Your number don't match with operator"<<endl;Mobile_Recharge();}
     else
     {
    cout<<"Enter ammount"<<endl;
    cin>>b;
    string f="Mobile Reacharge::";
    bool l4=check_password();
if(l4==true)
   {
    money=money-b;
    cout<<"Successfully you have rechatged money "<<"::"<<b<<" TK"<<" ";
    cout<<"in this number ::"<<number<<endl;
    cash_save();
    store_Lenden(b,f);
    display_home();
    }
    else 
    {
        cout<<"Sorry you've entered wrong password"<<endl;
        display_home();
    }
}
}
}
void Home ::Payment()
{   int a;int otp;
    cout<<"Enter payment money"<<endl;
    cin>>a;string c="Make Payment::";
    bool As=check_password();
if(As==true)
   {
      OTP();
      cout<<"Enter your OTP"<<endl;
      cin>>otp;
     if(otp==random)
     {
    money=money-a;
     cout<<"Successfully You've payment"<<"::"<<a<<" TK"<<endl;
     cash_save();
     store_Lenden(a,c);
     display_home();
     } 
       else
       {
        cout<<"Sorry Your OTP is wrong"<<endl;
         display_home();
      }
    }
 else 
    {
        cout<<"Sorry you've entered wrong password"<<endl;
        display_home();
    }
}
void Home ::Sendmoney()
{   int a;int otp;
    cout<<"Enter ammount of money"<<endl;
    cin>>a;string k="Send Money:";
    bool l6=check_password();
if(l6==true)
   {
    OTP();
    cout<<"Enter your OTP"<<endl;
    cin>>otp;
    if(otp==random)
    {
    money=money-a;
    cout<<"Successfully You've send money"<<"::"<<a<<" TK"<<endl;
    cash_save();
    store_Lenden(a,k);
    display_home();
    } 
    else
    {
        cout<<"Sorry Your OTP is wrong"<<endl;
        display_home();
    }

    }
    else 
    {
        cout<<"Sorry you've entered wrong password"<<endl;
        display_home();
    }
}
int Home::make_password_strong(string s)
{
   char arr[s.length()];
   arr[s.length()]={'\0'};int uper=0;int lower=0;int special;int num;int st;
   if(s.length()<6)  {cout<<"Password Must be more than 6 word"<<endl; return 0;}
   for(int i=0;i<s.length();i++)
   {
         arr[i]=s[i];
         if(arr[i]>='a' && arr[i]<='z')
         {
            lower=1;
         }
         else if(arr[i]>='A' && arr[i]<='Z')
         {
          uper=1;
         }
         else if(arr[i]>='0'&& arr[i]<='9')
         {
            num=1;
         }
         else
         {
            special=1;
         }
   }
   int sum=lower+uper+num+special;
   if(sum==3) {cout<<"Your Password is medium-strrong."<<endl;return 1;}
   else if(sum==4) {cout<<"Your password is strong."<<endl;return 1;}
   else { cout<<"This password is so much weak."<<endl;return 0;}
}

int Home::check_username(string love)
{
     srand(time(0));
     int w=rand()%100;
   fstream read("username.txt",ios::in);
    for(int i=0;i<100;i++)
    {  string a;
        getline(read,a);
        if(a==love)
        {
            cout<<"This user name is already axist"<<endl;
            cout<<"Suggest Name::"<<love<<w<<endl;return 0;
        }
    }
    fstream file;
    file.open("username.txt",ios::app);
    file<<love<<endl;
    file.close();
    return 1;

}
void Home::getloan()
{ int ammount=0;string s="Emergency Loan";
    if(money>=100)
    {
        cout<<"Sorry you're unable to get loan"<<endl;
    }
    else
    {
        cout<<"Enter ammount in range of 500::to get emergency loan"<<endl;
        cin>>ammount;
        if(ammount<=500)
        {
        money=money+ammount;
        cash_save();
        store_Lenden(ammount,s);
        cout<<"You have get loan"<<ammount<<endl;
        }
        else
        {
            cout<<"You're unable to get loan"<<endl;

        }
    }
    display_home();
}
int Home::check_mail(string d)
{
char arr[d.length()];int count=0;
   arr[d.length()]={'\0'};
   for(int i=0;i<d.length();i++)
   { 
    arr[i]=d[i];
   }
   for(int i=0;i<d.length();i++)
   { 
     if( arr[i]=='@')
     {
          count++;
     }
     else if(arr[i]=='.')  count++;
   }
if(count==2) return 1;
else cout<<"You have enterted a invaild email address"<<endl;return 0;

}

void Home::Sin_up()
{     int a=   human_varification();
   if(a==1)
   {
   string user_name;string  password;string number;string NID;string email;int otp;
    cout<<"Enter your User name::"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cin>>user_name;
  int a=  check_username(user_name);
  if(a==0) {user_name='\0';cin>>user_name;}
    cout<<"Enter your password"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cin>>password;
    while(1)
    {
    int vut=   make_password_strong(password);
    if(vut==1) {break;}
    cout<<"Enter your password"<<endl;
    cout<<"------------------------------------------------"<<endl;
      cin>>password;
    }
    cout<<"Enter your mobile number"<<endl;
    cout<<"------------------------------------------------"<<endl;int aas=0;
     cin>>number;int k=  check_number_oper(number,aas);
     if(k==0)
     { cout<<"Enter your mobile number"<<endl;cin>>number;}
     cout<<"------------------------------------------------"<<endl;
     cout<<"Enter your NID"<<endl; aas=16;
     cout<<"------------------------------------------------"<<endl;
     cin>>NID;int rt=  check_number_oper(NID,aas);if(rt==0){cout<<"Enter your NID"<<endl;cin>>NID;}
     cout<<"------------------------------------------------"<<endl;
     cout<<"Enter your email"<<endl;
     cout<<"------------------------------------------------"<<endl;
     cin>>email;
     while(1)
    {
    int b= check_mail(email);
    if(b==1) {break;}
    cin>>email;
    }
     OTP();
     money=0;
       
    ofstream file;
    file.open(user_name +".txt");
    file<<user_name<<endl<<password<<endl<<number<<endl<<NID<<endl<<email<<endl<<money;
    file.close();
    cout<<"Enter your OTP"<<endl;
     cin>>otp;
     if(otp==random)
     {
    cout<<user_name<<"You've successfully Sin Up"<<endl;
     }
     else
     {
        cout<<"Sorry You have pressed wrong OTP"<<endl;
     }
    display_home();
   }
   else cout<<"You're not a human"<<endl;display_home();
}


void Home :: display_home()
{  
    printf("%c",4) ; cout<<"Welcome to   SuptoCash"; printf("%c",4);cout<<endl;
    printf("%c",4); cout<<"options:::"<<endl;
   for(int i=0;i<=30;i++)
   { printf("%c",3);
   }
   cout<<""<<endl;
   cout<<"1:: Sin Up"<<"              "<<" 2::Log in"<<endl;
   cout<<"3:: Cash in"<<"              "<<"4::Cash Out"<<endl;
   cout<<"5::Mobile Recharge  "<<"     "<<"6::Make Payment"<<endl;
   cout<<"7::Send Money"<<"            "<<"8::My Cash::"<<endl;        
   cout<<"9::Pin Reset"<<"             "<<"10::Lenden History"<<endl;
   cout<<"11:Log OuT"<<endl;
   cout<<"press [1-11]"<<endl;
   int a;
   cin>>a;
   if(a==1 || a==2 || enter_persona==1)
   {
     enter_persona=1;
     if(a==1){Sin_up();}else if(a==2){log_in();}
    else if(a==3){cash_in();}else if(a==4){CashOut();}
    else if(a==5){ Mobile_Recharge();}else if(a==6){Payment();}
    else if(a==7){Sendmoney();}
    else if(a==8){Mycash();}
    else if(a==9){change_password();}
    else if(a==10){read_lenden() ;}
    else if(a==11){exit(0);}
   } else {cout<<"Enter Invalid Kye"<<endl<<"Log in or sin_Up First"<<endl; display_home();}
} 
void Home ::log_in()
{ 
  int a=   human_varification();
  if(a==1)
  {
 bool supto1=logg_in();
   if(supto1==true)
   {
    OTP();
    int otp;
    cout<<"Enter Your OTP"<<endl;
    cin>>otp;
    if(otp==random)
    { 
        
    cout<<"You're successfully log in"<<endl;
      initialize();
    }
   }
   else 
   { 
   cout<<"Invalid log in"<<endl;
   }
   display_home();
  }
  else cout<<"You're not a human.Try Again"<<endl;display_home();
}
void Home ::Mycash()
{    
   cout<<supto<<":::"<<"Your Details are here::"<<endl;
    string st1,st2,st3,st4,st5;int st6;
    ifstream  fileIn;
    fileIn.open(supto +".txt");
    fileIn>>st1>>st2>>st3>>st4>>st5>>st6;
    cout<<"Customer name::"<<supto<<endl;;
    cout<<"Mobile Number::"<<st3<<endl;
    cout<<"NID           ::"<<st4<<endl;
    cout<<"Your email::"<<st5<<endl;
    int a;
    cout<<"1::Home"<<"      "<<"2::Pin Reset"<<endl;
    cout<<"3::Balance::    "<<"4::Get Emergency"<<endl;
    cout<<"5::Detele Account"<<endl;
    cin>>a;
    if(a==1){display_home();}  else if(a==2){change_password();}
    else if(a==3) {check_password();
        cout<<"Your current ammount is:::"<<st6<<endl;fileIn.close();display_home();}
        else if(a==4) {check_password();getloan();}
} 

int main()
  { 
    Home Suptoo;
    Suptoo.display_home();
  }
