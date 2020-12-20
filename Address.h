#ifndef Address_H
#define Address_H
#include <iostream>

using namespace std;


enum IP_Class  //i create an enum for IP class information for ease readability.
{
	
	Unknown=0,
	
	Class_A=1,
	
	Class_B=2,
	
	Class_C=3

};


class Address 
{

private:

	int Decimal_Representation[4];

	int Binary_Representation[32];

	IP_Class Class_Info;

	int Network_Mask[4]; //you want us creating this one.Although i dont need this array, i dont erase it.

public:
	
	Address() 
	{
	
		Class_Info = Unknown;
		
	}
	Address(int input_IP[4])
	{
	
		int c = 0;
		for (c = 0; c < 4; c++) 
		{
		
			Decimal_Representation[c] = input_IP[c];
		
		}

		Convert_decimal_to_binary(input_IP);
	
	
	
	}
	void Convert_decimal_to_binary(int input_for_convertion[]) // i need this function to keep main function code clear.

	{

		int c = 3;

		int x = 31;

		int input_for_convertion_[4];

		for (c = 0; c<4; c++) 
		
		{
		
			input_for_convertion_[c] = input_for_convertion[c];
		
		}

		for (c = 3; c >= 0; c--)

		{

			while (input_for_convertion_[c] > 1)

			{


				Binary_Representation[x] = input_for_convertion_[c] % 2;

				input_for_convertion_[c] /= 2;
	

				x--;


			}


			Binary_Representation[x] = input_for_convertion_[c];

			x--;


			

			while ((x + 1) % 8 != 0)

			{


				Binary_Representation[x] = 0;

				x--;


			}


		}
	}

	void operator~ () 

	{
	
		Find_Class();

		switch (Class_Info)
		
		{
		
		case Class_A:
		
			cout << "This IP belongs to Class A"  << endl;
			
			break;

		case Class_B:
		
			cout << "This IP belongs to Class B" << endl;
		
			break;
		
		case Class_C:
		
			cout << "This IP belongs to Class C" << endl;
		
			break;
		
		case Unknown:
		
			cout << "Class information has not been entered" << endl;
		
			break;

		}

	}

	void Find_Class() 

	{
	
		if (Binary_Representation[0] == 0) 
		
		{
		
			Class_Info = Class_A;
		
		}
		
		else if (Binary_Representation[1]==0) 
		
		{
	
			Class_Info = Class_B;
		
		}
		
		else 
	
		{		
		
			Class_Info = Class_C;
		
		}
	
	}
	Address operator+(Address a)
	{
		Address* p;
		p = new Address();
		int c = 0;
		for (c = 0; c < 32; c++) 
		{
		
			if ((this->Binary_Representation[c] == 1) || (a.Binary_Representation[c] == 1)) 
			{
			
				p->Binary_Representation[c] = 1;

			}
			else 
			{
			
				p->Binary_Representation[c] = 0;
			
			}
		
		}
		
		return *p;
		

	
	}
	Address operator* (Address a) 
	{
		Address* p;
		p = new Address();
		int c = 0;
		for (c = 0; c < 32; c++)
		{

			if ((this->Binary_Representation[c] == 1) && (a.Binary_Representation[c] == 1))
			{

				p->Binary_Representation[c] = 1;

			}
			else
			{

				p->Binary_Representation[c] = 0;

			}

		}

		return *p;


	
	}
	Address operator-(Address a) 
	
	{
		Address* p;
		p = new Address();
		int c = 0;
		for (c = 0; c < 32; c++)
		{

			if ((this->Binary_Representation[c] == 1) || (a.Binary_Representation[c] == 1))
			{

				p->Binary_Representation[c] = 0;

			}
			else
			{

				p->Binary_Representation[c] = 1;

			}

		}

		return *p;


	
	
	}
	Address operator/ (Address a) 
	
	{
		Address* p;
		p = new Address();
		int c = 0;
		for (c = 0; c < 32; c++)
		{

			if ((this->Binary_Representation[c] == 1) && (a.Binary_Representation[c] == 1))
			{

				p->Binary_Representation[c] = 0;

			}
			else
			{

				p->Binary_Representation[c] = 1;

			}

		}

		return *p;

	
	}
	Address operator%(Address a) 
	
	{
		Address* p;
		p = new Address();
		int c = 0;
		for (c = 0; c < 32; c++)
		{

			if (this->Binary_Representation[c] == a.Binary_Representation[c] )
			{

				p->Binary_Representation[c] = 0;

			}
			else
			{

				p->Binary_Representation[c] = 1;

			}

		}

		return *p;

	
	
	}
	Address operator^ (Address a) 
	
	{
		Address* p;
		p = new Address();
		int c = 0;
		for (c = 0; c < 32; c++)
		{

			if (this->Binary_Representation[c] == a.Binary_Representation[c])
			{

				p->Binary_Representation[c] = 1;

			}
			else
			{

				p->Binary_Representation[c] = 0;

			}

		}

		return *p;

	
	}


	void operator=(Address a) 
	{
	
		int c = 0;
		
		for (c = 0; c < 32; c++)
		{

			this->Binary_Representation[c] = a.Binary_Representation[c];

		}
		for (c = 0; c < 4; c++) 
		{
			this->Decimal_Representation[c] = a.Decimal_Representation[c];
		
		}
		
		this->Class_Info = a.Class_Info;

		for (c = 0; c < 4; c++)
		{
			this->Network_Mask[c] = a.Network_Mask[c];

		}


	}
	
	
	bool operator== (Address a) 
	{
		int c = 0;

		for (c = 0; c < 32; c++)
		{

			if (this->Binary_Representation[c] != a.Binary_Representation[c])
			{
				return false;
			}
		}
		return true;

	}
	bool operator!=(Address a) 
	
	{
	
		int c = 0;

		for (c = 0; c < 32; c++)
		{

			if (this->Binary_Representation[c] != a.Binary_Representation[c])
			{
				return true;
			}
		}
		return false;

	}
	
	void binary_to_decimal() 
	{
	
		Decimal_Representation[0] = Binary_Representation[0] * 128 + Binary_Representation[1] * 64 + Binary_Representation[2] * 32 + Binary_Representation[3] * 16 + Binary_Representation[4] * 8 + Binary_Representation[5] * 4 + Binary_Representation[6] * 2 + Binary_Representation[7] ;
		Decimal_Representation[1] = Binary_Representation[8] * 128+ Binary_Representation[9] * 64 + Binary_Representation[10] * 32 + Binary_Representation[11] * 16 + Binary_Representation[12] * 8 + Binary_Representation[13] * 4 + Binary_Representation[14] * 2 + Binary_Representation[15];
		Decimal_Representation[2] = Binary_Representation[16] * 128 + Binary_Representation[17] * 64 + Binary_Representation[18] * 32 + Binary_Representation[19] * 16 + Binary_Representation[20] * 8 + Binary_Representation[21] * 4 + Binary_Representation[22] * 2 + Binary_Representation[23];
		Decimal_Representation[3] = Binary_Representation[24] * 128 + Binary_Representation[25] * 64 + Binary_Representation[26] * 32 + Binary_Representation[27] * 16 + Binary_Representation[28] * 8 + Binary_Representation[29] * 4 + Binary_Representation[30] * 2 + Binary_Representation[31];

	
	
	}
	
	
	friend ostream& operator<< (ostream& os, Address a);

	friend istream& operator>> (istream& is, Address& a);





};


ostream& operator<< (ostream& os,Address a)
{
	int c;
	
	os << "Decimal:";
	for (c = 0; c < 4; c++)
	{

		os << a.Decimal_Representation[c];
		if (c != 3)
		{

			os << ".";

		}

	}
	
	os << endl;
	
	
	os << "Binary:";
	for (c = 0; c < 32; c++)
	{

		os << a.Binary_Representation[c];
		if ((c == 7) || (c == 15) || (c == 23))
		{

			os << ".";
		}
	}

	return os;
	


}    
istream& operator>> (istream& is,Address& a)

{
	cout << "please enter an address with format(%d.%d.%d.%d):";

	char input_[20];

	is >> input_;

	sscanf_s(input_, "%d.%d.%d.%d", &a.Decimal_Representation[0], &a.Decimal_Representation[1], &a.Decimal_Representation[2], &a.Decimal_Representation[3]);

	a.Convert_decimal_to_binary(a.Decimal_Representation);
	
	a.Find_Class();

	return is;
}


#endif \\ Address_H

