//Harjotustyö, hotellin varausjärjestelmä
//Janika Hartikainen, 25TIETOA

//Different libraries we're using for the project:
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <random>
#include <fstream>
#include <ctime>
#include <cstdlib>

//Using std (standard) namespace:
using namespace std;

// Standard room:
struct Room {
	bool isRoomReserved = false;
	string bookerName;
	int reservationNumber;
};

//Checking which rooms are free:
bool isRoomFree(Room rooms[], int index) {
	return !rooms[index].isRoomReserved;
}

//Creating the prototypes for different functions:
void makeReservation(Room rooms[], int roomAmount, int pricePerNight);
void findReservation(Room rooms[], int totalRooms);
void deleteReservation(Room rooms[], int totalRooms);
void exitProgram(Room rooms[], int totalRooms);

//Creating our menu:
int main() {

	//Main menu
	while (true) {
		int menuNumber;

		//The menu
		std::cout << "Hotel menu" << endl;
		std::cout << "" << endl;
		std::cout << "1. Make a new reservation." << endl;
		std::cout << "2. Find already existing reservations." << endl;
		std::cout << "3. Delete existing reservations." << endl;
		std::cout << "4. Exit the program" << endl;
		std::cout << "" << endl;

		//Randomizing the amount of rooms between 30-70 and the prize per night
		srand(time(0));
		Room maxRooms;
		int roomAmount, pricePerNight;
		for (int x = 1; x < 2; x++) {

			roomAmount = 30 + (rand() % (70 - 30));
			std::cout << "The total amount of rooms is: " << roomAmount << endl;

			pricePerNight = 80 + (rand() % (100 - 80));
			std::cout << "The price per night is: " << pricePerNight << " EUR" << endl;

		}

		std::vector<Room> rooms(roomAmount);


		//Choosing what action from menu to do:
		while (true) {
			std::cout << "Type the number of the action you want to do: " << endl;

			if (!(cin >> menuNumber)) {
				std::cout << "Invalid input, enter only numbers." << endl;

				if (menuNumber < 1 || menuNumber >4); {
					std::cout << "Invalid input, enter numbers between 1-4" << endl;
				}
			}

			//Using functions based on menu choices
			switch (menuNumber) {
			
			case 1:
				std::cout << "You chose to make a new reservation." << endl;
				makeReservation(rooms.data(), roomAmount, pricePerNight);
				break;

			case 2:
				std::cout << "You chose to look at your reservation." << endl;
				findReservation(rooms.data(), roomAmount);
				break;

			case 3:
				std::cout << "You chose to delete reservation." << endl;
				deleteReservation(rooms.data(), roomAmount);
				break;

			case 4:
				std::cout << "You chose to exit the program" << endl;
				return 0;

			}

		}

	}
}

//First function, creating reservation:
	void makeReservation(Room rooms[], int roomAmount, int pricePernight) {
	vector <int> freeRooms;
	for (int x = 0; x < roomAmount; x++) {
		if (isRoomFree(rooms, x)) {
			freeRooms.push_back(x);
		}
	}

	int index = freeRooms[rand() % freeRooms.size()];
	Room& i = rooms[index];
	std::cout << "Your room number is: " << index + 1 << endl;

		
		string ibookerName;

		std::cout << "Please enter your name: " << endl;
		cin >> ibookerName;

		i.reservationNumber = rand() % 90000 + 10000;
		i.isRoomReserved = true;
	

	std::cout << "Reservation made." << endl;
	std::cout << "Reservation name: " << ibookerName << endl;
	std::cout << "Reservation number: " << i.reservationNumber << endl;
	std::cout << "Room number: " << index + 1 << endl;

}

//Second function, searching reservations made before
	void findReservation(Room rooms[], int totalRooms) {
	string ibookerName;
	std::cout << "Enter the name you made the reservation with: " << endl;
	cin >> ibookerName;

	int reservationFound = 0;
	for (int y = 0; y < totalRooms; y++) {
		if (rooms[y].isRoomReserved && rooms[y].bookerName == ibookerName) {
			std::cout << "One resevation found with the name: " << ibookerName << endl;
			std::cout << "Reservation number found with the name provided: " << rooms[y].reservationNumber << endl;

		}
	}
	if (reservationFound == 0) {
		std::cout << "No reservations found with that name." << endl;
	}
}


//Third function, deleting existing reservations
	void deleteReservation(Room rooms[], int totalRooms) {
	int inumber;
	
	std::cout << "Enter your reservation number: " << endl;
	cin >> inumber;

	for (int y = 0; y < totalRooms; y++) {
		if (rooms[y].isRoomReserved && rooms[y].reservationNumber == inumber) {
			std::cout << "Reservation was found with " << inumber << endl;
			std::cout << "Name: " << rooms[y].bookerName << endl;

			rooms[y].reservationNumber = 0;
			rooms[y].bookerName = "";
			rooms[y].isRoomReserved = false;

			std::cout << "Your reservation is cancelled" << endl;
		}
	}
}
