#include <iostream>
#include <fstream>
#include <limits> 

using namespace std;

int key;
char choice;
int backup;

int main()
{
	ifstream CheckKey("Key.txt");
	if (!CheckKey)
	{
		std::cout << "No Key found\n";
		cout << "Please enter Your Key:";
		cin >> key;
		std::cout << "\nCreating File for Key...\n";
		ofstream KeyFile("Key.txt");
		
		if (!KeyFile)
		{
			std::cerr << "Error Creating File";
		}
		
		std::cout << "Writing Key in File...\n";
		KeyFile << key;
		
		if (!KeyFile)
		{
			std::cerr << "Error Writing Key in File";
		}

		KeyFile.close();
	}
	else
	{
		ifstream KeyRead("Key.txt");
		if (!KeyRead)
		{
			std::cerr << "Can't read Key from File";
		}

		std::cout << "Key is loaded from Key.txt\n";
		std::cout << "\n";
		KeyRead >> key;
		KeyRead.close();

		do
		{
			std::cout << "Enter [e] if you want to close this Programm\n";
			std::cout << "Do you want do use this key?: " << key << " [y/n]";
			std::cin >> choice;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if (choice == 'e')
			{
				exit(1);
			}

			switch (choice)
			{
			case 'y':
				backup = 1;
				break;
			case 'n':
				backup = 0;
				std::cout << "\nEnter your new Key:";
				std::cin >> key;
				std::cout << "\n" << key << " is your new key\n";
				break;
			default:
				std::cout << "Please enter a valid option\n";
			}
		} while (backup != 1);

		std::cout << "Suscesfully loged in";
	} 
	return 0;
}