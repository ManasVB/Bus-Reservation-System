#ifndef BUS_RESERVATION_H_INCLUDED
#define BUS_RESERVATION_H_INCLUDED

#include<fstream>
#include<iomanip>
#include<Vector>
#include<cstdio>
#include<cstring>

/* The project contains four classes: Admin, Bus, Useracc and Ticket.
 * Admin class has admin username and password.
 * Bus class has all the, bus attributes like bus number, destinations,
 * status, fare, date and,time of departure and arrival, number of halts, etc.
 * The bus class contains a 2d array which gives the representation of seats,
 * at the time of checking availablity and making reservations. Different buses,
 * will have different arrays.
 * Useracc class contains the details of user. Username, password and name of
 * the user.
 * Ticket class has all its data members which are needed to be printed on the
 * ticket.
 */

int a[3][10];int cnter = 0;
class Admin{
private:
    string username = "Bus123";
    string password = "travels123";
    friend class Bus;
}A;

class Bus{
private:
	string no;
	string dep,arrv,type;
	string ddate,adate;
	int halt; string delay[2];
	int stops;string status;  short resstatus;
	string dest[10];
	string atime[10]; string dtime[10]; string atime1[10]; string dtime1[10];
	double fare[10];
	string resv[3][10];

public:
	bool aenter(string user,string pass){ bool n1 = (user==A.username && pass==A.password); return n1;}
	void add(string bn);
	void disp();
	string modify(string b);
	bool searchh(string _from,string _to,string _depdate);
	void reserv();
	bool addsear(string s);
	bool makeres(short sn);
	bool seatcheck(short sn);
	bool restatus()
	{
	    if(resstatus==1){cout<<endl<<endl<<"Bookings are Open"<<endl<<endl; return true;}
	    if(resstatus==2){cout<<endl<<endl<<"Bookings are Closed"<<endl<<endl; return false;}
	    if(resstatus==3){cout<<endl<<endl<<"Bookings are Closed Temporarily"<<endl<<endl; return false;}
	}
	bool statusbus()
	{
	    if(status=="Yet to start"||status== "No Delay"||status=="Delayed") return true;
	    if(status=="Reached"){cout<<endl<<endl<<"           The Bus has already reached it's destination."<<endl<<endl; return false;}
	    if(status== "Canceled"){cout<<endl<<endl<<"         This Bus is Canceled!"<<endl<<endl;return false;}
	}
	double finalfare(string sfrom,string sto);

	string busnum(){return no;} int numstops(){return stops;}
	string *numdest(){return dest;} string *num_est_arr(){return atime;} string *num_est_dep(){return dtime;}
	string namereturn(short sn);

	bool delete1(string num){bool n = num==no; return n;}

};

class Useracc{
private:
	string fname,lname;
	string usern;
	string passw,repassw;

public:
	void addname(string ch);
	bool addsearch(string s){
	bool n1 = s == usern;

	return n1;
	}
	bool search1(string s){
	bool n1 = usern ==s;
	return n1;}

	bool addsearc(string s);
	void disp(){ cout<<fname<<" "<<lname<<" "<<usern<<endl;}
	void flname(){cout<<fname<<" "<<lname<<endl;}
	string Fname(){return fname;} string Lname(){return lname;}

}U2;


bool check(string idi);
vector<string> :: iterator itr,itr1;
vector<double> :: iterator itr2;


class Ticket
{
private :
	string  busnum;
	int stopsnum;
	string desti[10];
	string estiarrv[10] ;
	string estidep[10] ;
	string  nameseat;
	short seat; double fare;
	string from;
	string to;
	string depdate;

public:
	void add(string _busnum,int _stopsnum,string *_desti,string *_estiarrv,string *_estidep,string _nameseat,short _seat,string _from,string _to,string _depdate,double _fare);
	void disp(){
	    cout<<busnum<<endl<<stopsnum<<endl<<seat<<"   "<<nameseat<<endl;}

	string Busnum(){return busnum;}
	string From(){return from;} string To(){return to;} string Depdate(){return depdate;}
	int Stopsnum(){return stopsnum;}
	short Seat(){return seat;}
	string Nameseat(){return nameseat;}
	string *Desti(){return desti;} string *Estiarrv(){return estiarrv;} string *Estidep(){return estidep;}
	double Fare(){return fare;}
}T;



#endif // BUS_RESERVATION_H_INCLUDED
