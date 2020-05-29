/*      Welcome to Bus reservation system. This is the portal for the system.
 * Four options are provided as soon as one opens the portal. The options
 * are administrator, visitor, user and more options.
 * Admin login enables you to add, modify, delete details of new buses. Also admin
 * can view the details of the users who have booked the seats of any bus. Admin also can view,
 * the details of the people who have used bus hire option.
 * Visitor login can be used to create an account and become an user of the portal. Visitor can,
 * view, search and check the availability of the buses.
 * User account has to be created from visitor login. Useracc class is used for creating an account.
 * After making reservations the user has to print tickets immediately otherwise the data is lost.
 * The printed ticket is stored as Ticket.txt in the user's system. The booking details are sent
 * to administrator. Ticket is printed based on Ticket class.
 * In the option number 4 of the portal bus hiring option is available. This option helps to hire
 * a bus by filling the bus hire form. These details are then sent to the admin.
 *        The bus status and reservation status are important as they decide whether reservation can be
 * made or not. If the reservation status is "Booking Open" and the bus status is neither "Reached nor
 * "Canceled" then and then only reservations can be made.
 * Bus numbers can be duplicated only if previous bus status is "Reached" or "Canceled".
 */
#include <iostream>
#include<String>
using namespace std;
#include "Bus_reservation.h"

int main()
{
    for(int i =0;i<3;i++)
        for(int j =0;j<10;j++)
            a[i][j] = ++cnter;
				fstream F1,F7;Useracc U;
				cout<<endl<<endl<<"                       "<<"Welcome to XYZ bus company"<<endl<<endl;
				cout<<"             Bus Hire : Bus Hire now available on our Portal."<<endl<<endl;
				cout<<"             10% Off on a-b-c-d route.          "<<endl<<endl;
				cout<<"             Facilities available: Charging Port,Wi-fi,Television."<<endl<<endl;

    char chmain;
    cout<<"Login the portal as: "<<endl<<" 1. Administrator"<<endl<<" 2. I do not have an account"<<endl<<" 3. My account"<<endl<<" 4. More:"<<endl;cin>>chmain;
	if(chmain=='1'){
	                    Bus B;
	                    string us,pa;bool n = 0; fstream file;
	                    while(n!=1){
                        cout<<"The username is Bus123 and password is travels123"<<endl;
	                    cout<<"Enter the Username."<<endl;cin>>us;cout<<"Enter the Password."<<endl;
	                    cin>>pa;

	                    n = B.aenter(us,pa);
	                    if(n==1) break;
	                    int n2; cout<<"1. Retry"<<endl<<"2. Exit"<<endl; cin >> n2;
	                    if(n2!=1) exit(0);}
	                    int n1,co1;

				        Bus P,P1;
				        fstream F1;fstream F2;string b1 ;  string line;
					        while(1){
                                    //Various tasks the admin can perform
					                cout<<endl<<"Select the option:"<<endl<<" 1 . Add:"<<endl<<" 2 . Display:"<<endl<<" 3 . Modify:"<<endl<<" 4 . Search:"<<endl<<" 5 . Show Availability:"<<endl<<" 6 . Delete Details:"<<endl<<" 7 . Bus Charter"<<endl<<" 8 . Booking Details:"<<endl<<"-1 . EXIT:"<<endl;
					                cin>>n1;char ch;  string from,to,depdate,checknm,_No; bool  nb2;

						        switch(n1){
					                        case 1 :
													cout<<"Give the Bus number:"<<"[Note: Provide the bus number as a single string without white spaces]"<<endl; cin>>checknm;
													F1.open("Bus.dat",ios::in|ios::binary);
													while(F1.read((char *)&P,sizeof(P))){
														bool n1 = P.addsear(checknm);
															if(n1==1){cout<<endl<<"This Bus number already exists. Please re-enter."<<endl;F1.close();goto here2;}
															}F1.close();
																F1.open("Bus.dat",ios::app|ios::binary);
																P.add(checknm);
																F1.write((char *)& P ,sizeof(P));
																F1.close();
																here2:
																break;

					                        case 2:
													cout<<"Display of the details of all buses"<<endl<<endl;
													F1.open("Bus.dat",ios::in|ios::binary);
													while(F1.read((char*)&P,sizeof(P)))
													P.disp();
													F1.close();
													break;


					                        case 3:
													cout<<"Enter the Bus Number of the Bus whose details are to be modified."<<endl; cin>>b1;
													F1.open("Bus.dat",ios::in|ios::binary);
													F2.open("temp.dat",ios::out|ios::binary);
													while(F1.read((char *)&P,sizeof(P))){
														string a1 = P.modify(b1);
															if(a1!="0"){
																F2.write((char *)&P,sizeof(P));
																}else{ F2.write((char *)&P,sizeof(P));}}
																F1.close();F2.close();
																remove("Bus.dat");rename("temp.dat","Bus.dat");
																break;


					                        case 4:
													cout<<endl<<"Leaving City: ";cin>>from; cout<<endl<<"Traveling to: ";cin>>to; cout<<endl<<"Departure date [dd/mm/yyyy] : "<<endl;cin>>depdate;
													cout<<endl<<endl; co1=0;
													F1.open("Bus.dat",ios::in|ios::binary);
													while(F1.read((char*)&P,sizeof(P))){
														bool n1 =  P.searchh(from,to,depdate);
															if(n1==true){ P.disp();co1++;}
															}   F1.close();
																if(co1==0)
																	cout<<endl<<"Sorry buses are not available from "<<from<<" to "<<to<<" on "<<depdate<<endl;
																	break;


					                        case 5:
													cout<<endl<<"Leaving City: ";cin>>from; cout<<endl<<"Traveling to: ";cin>>to; cout<<endl<<"Departure date [dd/mm/yyyy] : "<<endl;cin>>depdate;
													cout<<endl<<endl; co1=0;
													F1.open("Bus.dat",ios::in|ios::binary);
													while(F1.read((char*)&P,sizeof(P))){
														bool n1 =  P.searchh(from,to,depdate);
															if(n1==true){P.disp();P.reserv();co1++;}
															}   F1.close();
																if(co1==0)
																	cout<<endl<<"Sorry buses are not available from "<<from<<" to "<<to<<" on "<<depdate<<endl;
																	break;



					                        case 6:
				                                    cout<<endl<<"Enter the Bus number whose details you want to delete."<<endl; cin>>_No;
				                                    F2.open("Deletetemp.dat",ios::out|ios::binary);
				                                    F1.open("Bus.dat",ios::in|ios::binary);
				                                    while(F1.read((char *)&P,sizeof(P))){
					                                        bool n1 = P.delete1(_No);
					                                        if(n1==true);
					                                        else F2.write((char *)&P,sizeof(P));

					                                    }
						                                    F1.close();F2.close(); remove("Bus.dat"); rename("Deletetemp.dat","Bus.dat");
						                                    break;



					                   		 case 7 :
					                   		     cout<<"Here you will get the details of the person who has filled the bus hire form"<<endl<<endl;
				                                    file.open("BusHire.txt",ios::in);
					                                    while(!file.eof()){
															 while(getline(file,line)){
															  cout<<line<<endl;
					                                       	 }

							                                    }
						                                    file.close();
						                                    break;

                                             case 8:
                                                 cout<<"Here you will get the details of the user who has made reservations"<<endl<<endl;
                                                     file.open("Ticket.txt",ios::in);
					                                    while(!file.eof()){
															 while(getline(file,line)){
                                                              if(line == " Happy Journey!");
															 else cout<<line<<endl;
					                                       	 }
							                                    }
						                                    file.close();
						                                    break;

											case -1: exit(0);

										        }
										                    char yn2;
										                    cout<<"Do you want to continue [Y/N]?"<<endl; cin>>yn2;
										                    if(yn2=='n'||yn2=='N')break;
										        }
										}

	else if(chmain=='2'){
							int n1,co1;
							Bus P,P1;
							fstream F2;string b1 ;
							while(1){    //Various tasks the visitor can perform.
							cout<<endl<<"Select the option:"<<endl<<" 1 . Create an Account:"<<endl<<" 2 . Display:"<<endl<<" 3 . Search:"<<endl<<" 4 . Show Availability:"<<endl<<" 5 . Contact Us"<<endl<<"-1 . To EXIT"<<endl;
							cout<<endl<<"Note: Please create an account, to make reservations."<<endl;
							//cout<<"Note: Bus Hire available on our Portal. To hire a bus please create an account."<<endl;
							cin>>n1;char ch;  string from,to,depdate,checkchar; bool  nb2,nb;

							switch(n1){
										case 1 :
                                                cout<<"The Username should be string w/o spaces. Name is of two strings first and last name. Password is of string type."<<endl<<endl;
												cout<<"Enter the Username"<<endl; cin>>checkchar;
												F1.open("User.dat",ios::in|ios::binary);
												while(F1.read((char *)&U,sizeof(U))){
													bool n1 = U.addsearch(checkchar);
													if(n1==1){cout<<endl<<"This Username already exists. Please enter another one."<<endl;F1.close();goto here1;}
														}F1.close();
														F1.open("User.dat",ios::app|ios::binary);
														U.addname(checkchar);                 // If details are added true is returned and appended to the file
														F1.write((char *)&U,sizeof(U));
														F1.close();
														here1:
														break;

										case 2:
												cout<<"Display of the details of all buses"<<endl<<endl;
												F1.open("Bus.dat",ios::in|ios::binary);
												while(F1.read((char*)&P,sizeof(P)))
													P.disp();
													F1.close();
													break;

										case 3:
												cout<<endl<<"Leaving City: ";cin>>from; cout<<endl<<"Traveling to: ";cin>>to; cout<<endl<<"Departure date [dd/mm/yyyy] : "<<endl;cin>>depdate;
												cout<<endl<<endl; co1=0;
												F1.open("Bus.dat",ios::in|ios::binary);
												while(F1.read((char*)&P,sizeof(P))){
													bool n1 =  P.searchh(from,to,depdate);
														if(n1==true){ P.disp();co1++;}
														}   F1.close();
															if(co1==0)
																cout<<endl<<"Sorry buses are not available from "<<from<<" to "<<to<<" on "<<depdate<<endl;
																break;

										case 4:
												cout<<endl<<"Leaving City: ";cin>>from; cout<<endl<<"Traveling to: ";cin>>to; cout<<endl<<"Departure date [dd/mm/yyyy] : "<<endl;cin>>depdate;
												cout<<endl<<endl; co1=0;
												F1.open("Bus.dat",ios::in|ios::binary);
												while(F1.read((char*)&P,sizeof(P))){
													bool n1 =  P.searchh(from,to,depdate);
														if(n1==true){P.disp();P.reserv();co1++;}
														}   F1.close();
															if(co1==0)
																cout<<endl<<"Sorry buses are not available from "<<from<<" to "<<to<<" on "<<depdate<<endl;
																break;

										case 5:
									            cout<<"\t\t\t\t"<<" Customer Care:"<<endl<<endl;;
									            cout<<"#01. "<<"Book seats via telephone: "<<" 94xxx xxxxx"<<endl;
									            cout<<"#02. "<<"Complaints and Issues:    "<<" 98xxx xxxxx"<<"\t\t"<<"xyz@gmail.com"<<endl;



										case -1: exit(0);

							}
										char yn2;
										cout<<"Do you want to continue [Y/N]?"<<endl; cin>>yn2;
										if(yn2=='n'||yn2=='N')break;
							}

							}

	else if(chmain == '3'){
            cout<<"Ensure that the Username and Password are exactly the same as entered while creating the account."<<endl<<endl;
							fstream file; string line;
							bool _n; char res;
							string user1;string pass1; cout<<"Enter your Username."<<endl;cin>>user1;
							file.open("User.dat",ios::in|ios::binary);
							while(file.read((char *)&U,sizeof(U))){
								bool  n_ = U.search1(user1);
									if(n_==true){
									while(1){
										cout<<"Enter the Password."<<endl;cin>>pass1;_n =  U.addsearc(pass1);
											if(_n== false) cout<<"Incorrect Password."<<endl;
												if(_n== true) break;}
													cout<<"Welcome ";U.flname();goto usercase;}
													}
													file.close();
														cout<<"The Username that you have entered does not exist."<<endl;exit(0);
														usercase:
													cout<<endl;

							string Busnum,Nameseat,From1,To1,Depdate1,Fname,Lname;
							short Seat; string *Desti,*Estiarrv,*Estidep; int Stopsnum;double  Fare;
							int n1,co1;
							Bus P,P1;
							fstream F2;string b1 ;
							while(1){
								cout<<endl<<"Select the option:"<<endl<<" 1 . Display:"<<endl<<" 2 . Search:"<<endl<<" 3 . Make Reservations"<<endl<<" 4 . Print Tickets "<<endl<< " 5 . Contact Us"<<endl<< "-1 . To EXIT"<<endl;
								cin>>n1;char ch,yn1;  string from,to,depdate,checkchar; bool  nb2,nb,scheck;
									switch(n1){
												case 1:
														cout<<"Display of the details of all buses"<<endl<<endl;
														F1.open("Bus.dat",ios::in|ios::binary);
														while(F1.read((char*)&P,sizeof(P)))
														P.disp();
														F1.close();
														break;

												case 2:
														cout<<endl<<"Leaving City: ";cin>>from; cout<<endl<<"Traveling to: ";cin>>to; cout<<endl<<"Departure date [dd/mm/yyyy] : "<<endl;cin>>depdate;
														cout<<endl<<endl; co1=0;
														F1.open("Bus.dat",ios::in|ios::binary);
														while(F1.read((char*)&P,sizeof(P))){
															bool n1 =  P.searchh(from,to,depdate);
																if(n1==true){ P.disp();co1++;}
																}   F1.close();
																	if(co1==0)
																		cout<<endl<<"Sorry buses are not available from "<<from<<" to "<<to<<" on "<<depdate<<endl;
																		break;

												case 3:
												    //Reservations option. Let's the user book seats.
												    //Program asks user to enter from location, to location and departure date.
												    //And shows available buses throughout the day with the help of above details.
												char ynres; short resva[5];
												cout<<endl<<"Leaving City: ";cin>>from; cout<<endl<<"Traveling to: ";cin>>to; cout<<endl<<"Departure date [dd/mm/yyyy] : "<<endl;cin>>depdate;
												cout<<endl<<endl;co1=0;
												F1.open("Bus.dat",ios::in|ios::binary);
												while(F1.read((char*)&P,sizeof(P))){
												bool n1 =  P.searchh(from,to,depdate);
												if(n1==true){co1++;}}F1.close();
												if(co1==0){cout<<endl<<endl<<"Sorry Buses are not available from "<<from<<" to "<<to<<" on "<<depdate<<endl<<endl;break;}
												F1.open("Bus.dat",ios::in|ios::binary);
												F7.open("temp2.dat",ios::out|ios::binary);
												while(F1.read((char*)&P,sizeof(P))){
													bool n2 =  P.searchh(from,to,depdate);
														if(n2==false)
														{
														 F7.write((char *)&P,sizeof(P));
														}
														if(n2==true){
														            P.disp();P.reserv();
														            bool n2 = P.restatus();
														            bool n3 = P.statusbus();
														            if(n3==false){F7.write((char *)&P,sizeof(P));goto here3;}
														            if(n2==false){ cout<<"Sorry the Bus cannot be booked at this moment. "<<endl<<endl;F7.write((char *)&P,sizeof(P));goto here3;}
														        	cout<<endl<<"Select the option:"<<endl<<" 1 . Make a Booking:"<<endl<<" 2 . Do not make a reservation for this bus:"<<endl<<" 3 . Go back"<<endl; cin>>res;
																		if(res=='1'){
																					short seat;
																					cout<<"Please select a seat number."<<endl;cin>>seat;
																					scheck =  P.makeres(seat);
																					F7.write((char *)&P,sizeof(P));

																					double totalfare = P.finalfare(from,to);
																					cout<<endl<<"The Fare of this journey is: "<<totalfare<<endl;

																					cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;


																			        string  busnum = P.busnum(); int numstops = P.numstops(); string *desti = P.numdest();
                                                            				        string *estiarrv = P.num_est_arr();  string *estidep = P.num_est_dep();
																			      	string  nameseat = P.namereturn(seat);
																					T.add(busnum,numstops,desti,estiarrv,estidep,nameseat,seat,from,to,depdate,totalfare);
																					cout<<endl<<endl<<"Print the ticket once the reservation is done or else the data will be lost."<<endl<<endl;

																					}

														else if(res=='3'){exit(0);}

														else {
														      F7.write((char *)&P,sizeof(P));
														}
																here3:;
																	}
																					}
																					F1.close();F7.close();
																					remove("Bus.dat"); rename("temp2.dat","Bus.dat");
																					break;


												case 4:
                                                    // Make sure that this case is selected as soon as tickets are booked to print tickets.
                                                    // Otherwise the data will be lost.
														Busnum = T.Busnum();
														From1 = T.From();To1 = T.To();Depdate1 = T.Depdate();
														Nameseat  = T.Nameseat(); Seat = T.Seat();Fname = U.Fname();Lname = U.Lname();Stopsnum = T.Stopsnum();
														Desti = T.Desti();
														Estiarrv = T.Estiarrv() ;Estidep =  T.Estidep(); Fare = T.Fare();

														file.open("Ticket.txt",ios::app);
															file<<"Ticket Booked by:"<<Fname<<" "<<Lname<<endl;
															file<<setw(7)<<"Bus No."<<"\t\t\t"<<setw(9)<<"Departure"<<"\t\t\t"<<setw(9)<<"Arrival"<<"\t\t\t"<<setw(10)<<"Dept. Date"<<endl;
															file<<setw(7)<<Busnum<<"\t\t\t"<<setw(9)<<From1<<"\t\t\t"<<setw(9)<<To1<<"\t\t\t"<<setw(10)<<Depdate1<<endl<<endl;

															file<<setw(11)<<"Destination"<<"\t\t\t"<<setw(9)<<"Departure"<<"\t\t\t"<<setw(9)<<"Arrival"<<endl;
															for(int i=0;i<Stopsnum;i++){
															file<<setw(11)<<Desti[i]<<"\t\t\t"<<setw(9)<<Estiarrv[i]<<"\t\t\t"<<setw(9)<<Estidep[i]<<endl<<endl;}

															file<<setw(8)<<"Seat No."<<"\t\t\t\t"<<setw(8)<<"Name"<<endl;
															file<<setw(8)<<Seat<<"\t\t\t\t"<<setw(8)<<Nameseat<<endl<<endl;
															file<<endl<<"The total fare for the journey is "<<Fare<<"."<<endl;
															file<<" Happy Journey!"<<endl;
														file<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
														file.close();

														cout<<endl<<"Ticket is printed. Please check your system for Ticket.txt file"<<endl<<endl;
														break;

												case 5:

											            cout<<"\t\t\t\t"<<" Customer Care:"<<endl<<endl;;
											            cout<<"#01. "<<"Book seats via telephone: "<<" 94xxx xxxxx"<<endl;
											            cout<<"#02. "<<"Complaints and Issues:    "<<" 95xxx xxxxx"<<"\t\t"<<"xyz1@gmail.com"<<endl;
											            cout<<"#03. "<<"Queries and Doubts        "<<" 96xxx xxxxx"<<"\t\t"<<"xyz2@gmail.com"<<endl;
											            cout<<"#04. "<<"Payment Issues            "<<" 97xxx xxxxx"<<"\t\t"<<"xyz3@gmail.com"<<endl;
												case -1: exit(0);

												}
														char yn2;
														cout<<"Do you want to continue [Y/N]?"<<endl; cin>>yn2;
														if(yn2=='n'||yn2=='N')break;
														}
														}
	else if(chmain =='4'){
            //Bus hiring option. Fill out the bus hire form to hire a bus.
		fstream file2;
		short select,type,select2;string category,email,fname,lname,ph,source,dest,depdate,remarks,typebus;
		while(1)
				{

				cout<<endl<<"Select the option:"<<endl<<" 1 . Bus Charter:"<<endl<<" 2 . Contact Us:"<<endl<<"-1 . EXIT"<<endl; cin>>select;

					switch(select){

								case 1:

								    cout<<"                      Bus Hire Form:"<<endl;
								    cout<<"                      For inquiry"<<endl<<"      Main Office"<<endl<<"       Mr. XYZ"<<endl<<"Mobile No. 97xxx xxxxx"<<endl<<endl;

								    file2.open("BusHire.txt",ios::app);
									    cout<<"Select the Category:"<<endl<<" 1. Group Tour"<<endl<<" 2. Corporate Tour"<<endl<<" 3. Others"<<endl;cin>>select2;
									    if(select2==1) category="Group Tour"; else if(select2==2) category="Corporate Tour"; else {cout<<"Please state the category."<<endl;cin>>category; }
									    file2<<"Category: "<<category<<endl;
									    cout<<"Please enter a valid Email address."<<endl;cin>>email;file2<<"Email: "<<email<<endl;
									    cout<<"Please enter your Name."<<endl;cin>>fname>>lname;file2<<"Name: "<<fname<<" "<<lname<<endl;
									    cout<<"Please enter your Contact No."<<endl;cin>>ph;file2<<"Contact: "<<ph<<endl;
									    cout<<"Source City:"<<endl;cin>>source;file2<<"Source City: "<<source<<endl;
									    cout<<"Destination City:"<<endl;cin>>dest;file2<<"Destination City: "<<dest<<endl;
									    cout<<"Departure Date:"<<endl;cin>>depdate;file2<<"Dept. Date: "<<depdate<<endl;
									    while(1){
									    cout<<"Bus Type:"<<endl<<" 1. AC Coach"<<endl<<" 2. Non-AC Coach"<<endl<<" 3. Volvo"<<endl;cin>>type;
									    if(type==1){ typebus="AC Coach";break; }if(type==2) {typebus="Non-AC Coach";break;} if(type==3) {typebus="Volvo"; break;}
									    else cout<<endl<<"Enter a valid Type"<<endl;} file2<<"Bus Type: "<<typebus<<endl;
									    cout<<"Remarks: "<<endl;cin>>remarks;
									    file2<<"Remarks: "<<remarks<<endl;
								    file2<<"--------------------------------------------------------------------------------------------------------------------------"<<endl;
								    file2.close();

								    cout<<endl<<"We will contact you soon on the submitted contact details."<<endl<<endl;
								    break;


								case 2:
									cout<<"\t\t\t\t"<<" Customer Care:"<<endl<<endl;;
									cout<<"#01. "<<"Book seats via telephone: "<<" 94xxx xxxxx"<<endl;
									cout<<"#02. "<<"Complaints and Issues:    "<<" 98xxx xxxxx"<<"\t\t"<<"xyz@gmail.com"<<endl;
									break;

								default: exit(0);

								}
				}

						}

return 0;}


void Bus :: add(string bn){   //Add details of a new bus. If the number is previously assigned to any other bus then error will be shown unless,
                              //the status of previous bus is reached or canceled.


		for(int i=0;i<3;i++){                 //This is the 2d array representation of the bus seats. Total 30 seats are available.
			for(int j =0 ;j<10;j++){
				resv[i][j] =  "Empty ";

						}}
				no = bn;
				cout<<"Enter the start and end destinations respectively"<<endl; cin>>dep>>arrv;
				cout<<"Specify the type of bus. "<<"Type of buses available are AC, Non-AC, Volvo. Select from these."<<endl;cin>>type;
				cout<<"Enter the departure and arrival dates. ([dd/mm/yy] format)"<<endl;cin>>ddate>>adate;
				cout<<"Specify the number of halts through out the journey."<<endl;cin>>halt;

				cout<<"Select the reservation status"<<endl<<" 1. Bookings Open"<<endl<<" 2. Bookings closed"<<endl<<" 3. Bookings Temporarily closed"<<endl; cin>>resstatus;
				int opt;
				cout<<"Select the Bus Status"<<endl<<"1. Yet to start"<<endl<<"2. No Delay"<<endl<<"3. Delayed"<<endl<<"4. Reached"<<endl<<"5. Canceled"<<endl; cin>>opt;
					if(opt==1) status = "Yet to start"; else if(opt==2) status = "No Delay" ;

						else if(opt==3){ status = "Delayed";cout<<"Delay Time";cin>>delay[0]>>delay[1];}
							else if(opt==4) status = "Reached";else if(opt==5) status = "Canceled";

							short yn1;
							cout<<"Select the options:"<<endl<<"1.Non-stop type"<<endl<<"2.Transfer type"<<endl;cin>>yn1;
								if(yn1==2){
								cout<<"Enter the number of stops:"<<endl;cin>>stops;
								stops = stops + 2;
									} else if(yn1==1) stops = 2;
									string _dest,tdep,tarr;double _fare;

									cout<<"Enter the details of all destinations including start point and end point."<<endl;
										for(int i=0;i<stops;i++)
											{
											cout<<"Enter the destination"<<endl;cin>>_dest;
											cout<<endl<<"Enter the arrival and departure time:"<<endl;cin>>tarr>>tdep; cout<<"Enter the fare from start point"<<endl;cin>>_fare;
											dest[i] = _dest;atime[i] = tarr;dtime[i] = tdep;fare[i] = _fare;dtime1[i] = tdep; atime1[i] = tarr;}}

bool Bus :: addsear(string s){
    //function for checking if bus number has been used previously and if used previously ensuring their status is reached or canceled.
           bool n1 = (no==s && (status!="Reached")&&(status!="Canceled"));
			return n1;
			}


void Bus :: disp(){

    // Function for displaying all buses available.
        cout<<setw(10)<<"Bus Number:"<<"      "<<setw(10)<<"Departure"<<"      "<<setw(10)<<"Arrival"<<"      "<<setw(10)<<"Bus Type"<<"      "<<setw(10)<<"Dept. Date"<<"      "<<setw(10)<<"Arrv. Date"<<"      "<<setw(5)<<"Halts"<<endl<<endl;
        cout<<setw(10)<<no<<"      "<<setw(10)<<dep<<"      "<<setw(10)<<arrv<<"      "<<setw(10)<<type<<"      "<<setw(10)<<ddate<<"      "<<setw(10)<<adate<<"      "<<setw(2)<<halt<<endl;

       if(status == "Delayed") cout<<endl<<"Bus status: "<<"Delayed by  "<<delay[0]<<" hrs  "<<delay[1]<<" mins"<<endl<<endl;
       else cout<<endl<<"Bus status: "<<status<<endl<<endl;
        cout<<"More Information:"<<endl;
        cout<<setw(11)<<"Destination"<<"      "<<setw(20)<<"Expected Arrv. Time"<<"      "<<setw(20)<<"Expected Dept. Time"<<"      "<<setw(20)<<"Actual Arrv. Time"<<"      "<<setw(20)<<"Actual Dept. Time"<<"      "<<setw(11)<<"Fare[in Rs]"<<endl;
        for(int i = 0;i<stops;i++)
        {
            cout<<setw(11)<<dest[i]<<"      "<<setw(20)<<atime[i]<<"      "<<setw(20)<<dtime[i]<<"      "<<setw(20)<<atime1[i]<<"      "<<setw(20)<<dtime1[i]<<"      "<<setw(11)<<fare[i]<<endl;

        }
cout<<endl<<"Note: The fare from one destination to another is the difference between their fare from start destination."<<endl;

         cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;}

string Bus :: modify(string b){
            /* Function to modify the details of bus if any.
             * If the status of bus is modified to delayed you need to,
             * specify the amount of delay in hrs and mins and make changes,
             * in the timings accordingly.
             * Here reservation status can also be modified. This feature is
             * modified so that users cannot book tickets once Booking closed is
             * set.
             */
         string iid;  bool n3; if(no==b){

     	cout<<"Which is the detail that you want to modify?"<<endl<<endl;
		     while(1){
		            cout<<" 1. Bus Number"<<endl<<" 2. Status"<<endl<<" 3. Reservation status"<<endl/*<<" 4. Salary"<<endl<<*/<<"-1. Nothing"<<endl<<endl;
		     		short n1; cin>>n1;
					     switch(n1){

					        case 1: cout<<"You have chosen to modify the Bus Number."<<endl<<endl;
					                cout<<"Enter the new Bus Number."<<endl; cin>>no;
					                break;
                            case 3: cout<<"You have chosen to update the reservation status."<<endl<<endl;
                                    cout<<"Select the reservation status"<<endl<<" 1. Bookings Open"<<endl<<" 2. Bookings closed"<<endl<<" 3. Bookings Temporarily closed"<<endl; cin>>resstatus;
                                    break;

					        case 2: cout<<"You have chosen to modify the status."<<endl;
					                cout<<"Enter the status."<<endl;
					                 int opt;
                                    cout<<"Select the Bus Status"<<endl<<"1. Yet to start"<<endl<<"2. No Delay"<<endl<<"3. Delayed"<<endl<<"4. Reached"<<endl<<"5. Canceled"<<endl; cin>>opt;
                                    if(opt==1) status = "Yet to start";
                                    else if(opt==4) status = "Reached";
                                    else if(opt==3){ status = "Delayed";cout<<"Delay Time";cin>>delay[0]>>delay[1];
                                              string tarr1,tdep1;
                            for(int i=0;i<stops;i++)
                            {
                            cout<<endl<<"Enter the arrival and departure time:"<<endl;cin>>tarr1>>tdep1;
                                    dtime1[i] = tdep1;
                                    atime1[i] = tarr1;

                            }}

                            else if(opt==2){ status = "No Delay" ;

                for(int i=0;i<stops;i++)
                {
                        dtime1[i] = dtime[i];
                        atime1[i] = atime[i];}}

                            else if(opt==5){ status = "Canceled";

                for(int i=0;i<stops;i++)
                {
                        dtime1[i] = "N/A";
                        atime1[i] = "N/A";

                }}	break;
                    case -1: break;

                    default: cout<<endl<<"Enter a valid option:"<<endl<<endl;break;
					     }
								char yn; cout<<endl<<"Do you want to modify more details? Y/N"<<endl; cin>>yn;
								        if(yn=='n'||yn=='N')break;

								}return no;}
        return "0";}

bool Bus :: searchh(string _from,string _to,string _depdate){

    // Function to search details of the bus.

        if(status=="Canceled"){ return false;}
            for(int i=0;i<stops-1;i++){
                if(dest[i]==_from){
                    int i1 = i+1;
                    for(i1=0;i1<stops;i1++){
                        if(dest[i1]==_to){
                                if(ddate==_depdate)
                                    return true;}}}}

return false;

}
void Bus :: reserv(){

    // Function that gives the details of the bus sets whether they are empty or occupied.
    // 2d array representation of the seats.
      short counter = 0;

        for(int i=0;i<3;i++){
            for(int j =0 ;j<10;j++){
                cout<<setw(2)<<++counter<<" "<<resv[i][j]<<"     ";
            }
            cout<<endl<<endl;
        }
cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
cout<<endl<<endl;

}
bool Bus :: makeres(short sn)
{
        // Function used to book seats in the bus. Function checks if the seats are empty or not
        // If seats are occupied then error is shown.

        string name;
        for(int i = 0;i<3;i++){
        for(int j = 0;j<10;j++){
            if(sn==a[i][j]){


                        if(resv[i][j]=="Empty "){
                        cout<<endl<<"Please enter the name of the passenger."<<endl; cin>>name;
                        resv[i][j] = name;
                        return true;

                        }
                        else{ cout<<"This seat is already occupied."<<endl; return false;}
                        }}}
                        return false;}



string Bus :: namereturn(short sn)
{
        // After giving a seat number, name of the passenger who occupied the seats is returned.
    for(int i = 0;i<3;i++){
    for(int j = 0;j<10;j++){
        if(sn==a[i][j]){
                return resv[i][j];}}}


}

void Useracc ::addname(string ch){
    // To add details of the user after entering username
                usern = ch;
                cout<<"Enter your name:"<<endl; cin>>fname>>lname;
                while(1){
		        cout<<"Enter the Password"<<endl; cin>>passw;
		        cout<<"ReEnter the Password"<<endl; cin>>repassw;
		        if(passw==repassw) break;
		        cout<<endl<<"The entered passwords don't match. Please re-enter."<<endl;}}

bool Useracc :: addsearc(string s){
    //Function to check whether the password is correct after entering the username
           bool n1 = s == passw;
			return n1;
			}


double Bus :: finalfare(string sfrom,string sto){

    // As one can board the bus from various locations this function gives the fare total
    // of the journey from start point to end point.
        double minfare,maxfare,totfare;
        for(int i = 0;i<10;i++){
                if(dest[i] == sfrom)
                minfare = fare[i];}

        for(int i = 0;i<10;i++){
                if(dest[i] == sto)
                maxfare = fare[i];}

                totfare = maxfare - minfare;
                return totfare;
}


void Ticket::add(string _busnum,int _stopsnum,string *_desti,string *_estiarrv,string *_estidep,string _nameseat,short _seat,string _from,string _to,string _depdate,double _fare)
{

        // function used to initialize the data members of the class Ticket.
        busnum = _busnum;
        stopsnum = _stopsnum;
        for(int i = 0;i<_stopsnum;i++)
        {

            desti[i] = _desti[i]; estiarrv[i] = _estiarrv[i] ; estidep[i] = _estidep[i];
        }
        nameseat= _nameseat;
        seat = _seat;
        from = _from;
        to = _to;
        depdate = _depdate;
        fare = _fare;

}
