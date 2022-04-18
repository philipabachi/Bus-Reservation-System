#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

static int p = 0; //Static variables are variables that dont change their value throughout
                  //program execution
class a     // class name a    

{

  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
// Arrays to be used later
public:// public functions

  void Bus_Details(); // Function for storing bus details

  void booking(); // function for booking bus

  void empty();  // function for determining empty seats

  void Reserved_seats(); // function for displaying reserved seats in a bus

  void buses(); // function for displaying available buses

  void position(int i);  

}

bus[10];

void underline(char ch)

{

  for (int i=80;i>0;i--) // decoration loop

  cout<<ch;

}

void a::Bus_Details() // Bus details contained in class a

{

  cout<<"Enter bus no: ";

  cin>>bus[p].busn;

  cout<<"\nEnter Driver's name: ";

  cin>>bus[p].driver;

  cout<<"\nArrival time: ";

  cin>>bus[p].arrival;

  cout<<"\nDeparture: ";

  cin>>bus[p].depart;

  cout<<"\nFrom: \t\t\t";

  cin>>bus[p].from;

  cout<<"\nTo: \t\t\t";

  cin>>bus[p].to;

  bus[p].empty();

  p++;

}

void a::booking() // use of access resolution specifier

{

  int seat;

  char number[5];

  top: // goto label statements to be used

  cout<<"Bus no: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0) // strcmp(stringcompare compares two strings)

    break;

  }

  while(n<=p)

  {

    cout<<"\nSeat Number: ";

    cin>>seat;

    if(seat>32)

    {

      cout<<"\nThere are only 32 seats busesable in this bus.";

    }

    else

    {

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0) // strcmp compares the bus[n].seat
    //with "Empty" against 0 . if result is zero statements below is executed

      {

        cout<<"Enter passanger's name: ";

        cin>>bus[n].seat[seat/4][(seat%4)-1];

        break;

      }

    else

      cout<<"The seat no. is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"Enter correct bus no.\n";

      goto top;

    }

  }


void a::empty()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].seat[i][j], "Empty");// strcpy(string copy) copies the later string 
      // to the before string

    }

  }

}

void a::Reserved_seats()

{

  int n;

  char number[5];

  cout<<"Enter bus no: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break;

  }

while(n<=p)

{

  underline('*');// displays information inputted by the user

  cout<<"Bus no: \t"<<bus[n].busn

  <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"

  <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart

  <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<

  bus[n].to<<"\n";

  underline('*');

  bus[0].position(n);

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].seat[i][j],"Empty")!=0)

      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"Enter correct bus no: ";

}

void a::position(int l)

{

  int s=0;p=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].seat[i][j];

          p++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seat[i][j];

        }

      }

    }

  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;

  }

void a::buses()

{


  for(int n=0;n<p;n++)

  {

    underline('*');

    cout<<"Bus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver

    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"

    <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"

    <<bus[n].to<<"\n";

    underline('*');

    underline('_');

  }

}

int main() // main function

{

system("clear"); // executes clear system OS command

int w;

while(1)

{

    

  cout<<"\n\n\n\n\n";

  cout<<"\t\t\t1.Bus_Details\n\t\t\t"

  <<"2.Reservation\n\t\t\t"

  <<"3.Reserved_seats\n\t\t\t"

  <<"4.Buses. \n\t\t\t"

  <<"5.Exit";

  cout<<"\n\t\t\tEnter your choice:-> ";

  cin>>w;

  switch(w) // use of switch statement

  {

    case 1:  bus[p].Bus_Details();

      break;

    case 2:  bus[p].booking();

      break;

    case 3:  bus[0].Reserved_seats();

      break;

    case 4:  bus[0].buses();

      break;

    case 5:  exit(0);

  }

}

return 0;

}
