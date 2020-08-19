Object Oriented Programming and Design Project:
Bus Reservation System

•	Project Overview:
This Project is mostly based on the object oriented programming and file handling. The portal that is provided consists of 4 options to login. 1] As an administrator. 2] As a visitor. 3] As a User and 4] More
1.	Administrator: 
This login is used to add the information of new buses that are allotted for certain journey. The admin can also modify the details of any bus and delete details. [The username is Bus123 and password is travels123 to login.]
2.	Visitor: 
Visitor login enables the options to display all the buses that are available, search a particular bus and show availability of seats in a particular bus. This option helps to create a new user account by entering username [different for different users], password and name. Creating a User account is necessary to make reservations.
3.	User Account:
After creating a new account in the option 2, user needs to enter username and password to access the account. Once all the details are entered various options are available for the user. User can display all buses, search and also check availability of various buses. Also reservations can be made by selecting the seat number and entering the name of the passenger. After the seats are reserved, ticket can be printed. 
4.	More:
In this option Bus charter/ bus hire is available. A visitor can also hire a bus. Details are required to be added.





•	How does the Program work?

1.	Administrator:
For making a new bus available administrator has to add details for the bus. The details include bus number, source, destination, departure and arrival dates date their time, halts, fare for each stop in between if any and status of the bus and reservation status. These details will get updated in the Bus.dat file. . [The username is Bus123 and password is travels123 to login.]
Each bus has 5 status. 1] Yet to start. 2] No delay. 3] Delayed. 4] Reached and 5] Cancelled.
Adding a new bus requires a bus number. This bus number cannot be same as any previous entered bus numbers provided status of the bus is the first three. If status is reached or cancelled then previous bus number can be added. The program ensures that this care is taken.

2.	Visitor:
Create an account in this option. Also one can search and check seat availability of bus by providing the destinations and departure dates.

3.	User:
If account is not created please create one in option 2. In this option user can search and check availability of bus just like a visitor. But user can book and print tickets in this option. To book a ticket select make reservations choice and provide details like destinations and departure date. If buses are available on that date user will get the information along with their status and timings.
For buses administrator controls the reservation status. If reservation status says booking is open then and then only the user can book seats. Also the bus status should not be cancelled or reached.  Administrator can close the booking option by making reservation status as Bookings Closed.
Once a seat is booked proceed to print the tickets. A ticket.txt file will be saved on your system.

4.	More:
Bus hiring available. Just fill out the bus hire form and in the administrator login the admin will get these details.

