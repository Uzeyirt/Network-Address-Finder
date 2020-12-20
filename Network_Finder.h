#include<iostream>

#include "Address.h"

using namespace std;

class Network_Finder 
{
private:
	
	Address *IP_Addresses;
	
	Address *Network_Masks;
	
	Address *Network_Addresses;

	int array_size;

public:

	Network_Finder() 
	{
		int size;

		cout << "Please Enter a size for arrays:";

		cin >> size;

		array_size = size;

		IP_Addresses = new Address[array_size];
		
		Network_Masks = new Address[array_size];
		
		Network_Addresses = new Address[array_size];
	
		int c = 0;
		
		for (c = 0; c < array_size; c++) 
		{
			
			cout << "For IP address" << " " << c + 1 << endl;
			
			cin >> IP_Addresses[c];

			cout << endl;

			cout << "For Network mask" << " " << c + 1 << endl;

			cin >> Network_Masks[c];
		
			
		}

		Calculate_Network_Addresses();


	}
	Network_Finder(const Network_Finder& std)
	{
		array_size = std.array_size;
		
		IP_Addresses = new Address[array_size];

		Network_Masks = new Address[array_size];

		Network_Addresses = new Address[array_size];
		
		
		int c = 0;

		for (c = 0; c < array_size; c++)

		{

			this->IP_Addresses[c] = std.IP_Addresses[c];

			this->Network_Masks[c] = std.Network_Masks[c];

			this->Network_Addresses[c] = std.Network_Addresses[c];

		}
	}
	Network_Finder& operator=(const Network_Finder& std)  // i understand that you require an assignment function in part to step 5.
	{
		if (this == &std) 
		{
		
			return *this;

		}
		array_size = std.array_size;
		
		IP_Addresses = new Address[array_size];

		Network_Masks = new Address[array_size];

		Network_Addresses = new Address[array_size];

		int c = 0;

		for (c = 0; c < array_size; c++)

		{

			this->IP_Addresses[c] = std.IP_Addresses[c];

			this->Network_Masks[c] = std.Network_Masks[c];

			this->Network_Addresses[c] = std.Network_Addresses[c];

		}
		return *this;
	}
	~Network_Finder() 
	{
	
		delete[] IP_Addresses;
		
		delete[] Network_Masks;
		
		delete[] Network_Addresses;
	
	}
	
	
	
	
	
	void Calculate_Network_Addresses() 
	{
	
		int c = 0;

		for (c = 0; c < array_size; c++) 
		{
		
			Network_Addresses[c] = IP_Addresses[c] * Network_Masks[c];
			
			Network_Addresses[c].binary_to_decimal();
		
		}
		


	}

	void Print_Network_Finder() 
	
	{
		int c = 0;
		
		cout << "Array1 ->" << endl;

		for (c = 0; c < array_size; c++)
		{
			cout << IP_Addresses[c];
			cout << endl;
			
		
		}
	
		cout << "Array2 ->" << endl;
		for (c = 0; c < array_size; c++)
		{
			
			cout << Network_Masks[c];
			
			cout << endl;


		}
		cout << "Array3 ->" << endl;
		for (c = 0; c < array_size; c++)
		{
			
			cout << Network_Addresses[c];
			
			cout << endl;


		}
	}

};