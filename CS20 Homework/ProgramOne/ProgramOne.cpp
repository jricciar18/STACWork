/*
    Name: Johndominic Ricciardi
    Date: 9/27/24
    Program: Plane Seating Chart
*/
#include <iostream>
#include <vector>

using namespace std;

void displaySeatingChart(const vector<vector<int>>& seats, int rows, int cols) {
    cout << "   ";
    for (char seatLetter = 'A'; seatLetter < 'A' + cols; seatLetter++) {
        cout << seatLetter << " ";
    }
    cout << endl;

    for (int i = 0; i < rows; i++) {
        cout << i + 1 << "  ";
        for (int j = 0; j < cols; j++) {
            cout << (seats[i][j] == 0 ? "0 " : "X ");
        }
        cout << endl;
    }
    cout << "0: Available  X: Unavailable\n";
}

bool assignSeat(vector<vector<int>>& seats, int row, int col, vector<string>& assignedSeats) {
    if (seats[row][col] == 0) { // Seat is available
        seats[row][col] = 1; // Mark as assigned
        char seatLetter = 'A' + col;
        assignedSeats.push_back(to_string(row + 1) + seatLetter);
        return true;
    }
    return false; // Seat is already taken
}

int countAvailableSeats(const vector<vector<int>>& seats) {
    int count = 0;
    for (const auto& row : seats) {
        for (int seat : row) {
            if (seat == 0) count++;
        }
    }
    return count;
}

int main()
{
    int rows, cols;

    cout << "How many rows in the plane? ";
    cin >> rows;
    cout << "Hoe many seats per row? ";
    cin >> cols;

    // Validate number of seats
    if (cols <= 0 || rows <= 0) {
        cout << "Number of rows and seats must be positive integers.\n";
        return 0;
    }

    vector<vector<int>> seats(rows, vector<int>(cols, 0)); // 0: available
    vector<string> assignedSeats;

    // Display initial seating chart
    displaySeatingChart(seats, rows, cols);

    while (true) {
        cout << "Enter row number (1-" << rows << ") and seat letter (A-" << char('A' + cols - 1) << ") (or 0 0 to stop): ";
        int row;
        char seatLetter;
        cin >> row >> seatLetter;

        if (row == 0 && seatLetter == '0') break; // Exit condition

        // Validate input
        if (row < 1 || row > rows || seatLetter < 'A' || seatLetter >= 'A' + cols) {
            cout << "Invalid input. Please try again.\n";
            continue;
        }

    int col = seatLetter - 'A'; // Convert seat letter to column index

        // Attempt to assign the seat
        if (assignSeat(seats, row - 1, col, assignedSeats)) {
            cout << "Seat " << row << seatLetter << " assigned successfully.\n";
        } else {
            cout << "Seat " << row << seatLetter << " is already taken. Please choose another seat.\n";
        }

        // Display updated seating chart
        displaySeatingChart(seats, rows, cols);
    }

    // Display final results
    displaySeatingChart(seats, rows, cols);
    int availableSeats = countAvailableSeats(seats);
    cout << availableSeats << " Seats are still available\n";
    cout << "Order assigned: ";
    for (const string& seat : assignedSeats) {
        cout << seat << ", ";
    }
    if (!assignedSeats.empty()) {
        cout << "\b\b "; // Remove last comma and space
    }
    cout << endl;

    return 0;
}
