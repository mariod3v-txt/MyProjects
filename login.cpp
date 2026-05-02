#include <bits/stdc++.h> // Includes most standard libraries (not recommended for production)
#include <fstream>       // Used for file input/output
#include <windows.h>     // Used for Sleep() and system("cls") (Windows only)

using namespace std;

// Displays the main menu
void apresentation(){
	cout << endl;
	cout << "     ======================" << endl;
	cout << "     |    LOGIN SYSTEM    |" << endl;
	cout << "     ======================" << endl;
	cout << "     |------WELCOME!------|" << endl;
	cout << "     ======================" << endl;
	cout << "       1 - Login" << endl;
	cout << "       2 - Register" << endl;
	cout << "       3 - Close" << endl;
}

// Handles user registration
void registerr(){
	string user, password;

	cout << "New User: ";
	cin >> user; // Reads username input

	cout << "New Password: ";
	cin >> password; // Reads password input

	// Opens file in append mode (adds new data at the end)
	ofstream archive("users.txt", ios::app);

	// Stores username and password in the file
	// WARNING: Password is stored in plain text (security issue)
	archive << user << " " << password << endl;

	archive.close(); // Closes the file

	cout << "Registration successful!";

	Sleep(3000);     // Waits for 3 seconds
	system("cls");   // Clears the console (Windows only)
}

// Handles user login
void login(){
	string user, password;
	string u, s;     // Variables to read stored data
	bool find = false;

	cout << endl;

	cout << "     Username: ";
	cin >> user; // Reads username input

	cout << "     Password: ";
	cin >> password; // Reads password input

	// Opens file for reading
	ifstream archive("users.txt");

	// Iterates through all stored users
	while(archive >> u >> s){
		// Checks if credentials match
		if(u == user && s == password){
			find = true;
			break;
		}
	}

	archive.close(); // Closes the file

	// Displays result of login attempt
	if(find){
		cout << "Login successful!" << endl;
	}
	else{
		cout << "Incorrect username or password!" << endl;
	}

	Sleep(3000);
	system("cls");
}

// Main program loop
int main(){
	int id;

	while(1){ // Infinite loop for menu
		apresentation();

		cout << "       Select: ";
		cin >> id;

		system("cls"); // Clears screen after input

		if (id == 1){
			login(); // Calls login function
		}
		else if (id == 2){
			registerr(); // Calls registration function
		}
		else{
			break; // Exits the program
		}
	}	

	return 0;
}