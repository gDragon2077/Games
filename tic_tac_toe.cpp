/// Game "Tic Tac Toe" made by Satnoianu Dragos-Gabriel
/// November 2024 - Data Structure - Lab 4
/// All right reserved 2024

#include <iostream>

/// Block all devices used linux and macOS
#ifdef __linux__
#error "This game are made only for windows platforms!"
#endif // __linux__

#ifdef _WIN32
#include <windows.h>
#include <time.h>
#endif

char table[3][3];
bool comp_first = false;
int movesMade = 0, totalGames = 0, winPlayer = 0;

void table_init() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			table[i][j] = ' ';
		}
	}
}

void console_clean() {
	system("CLS");
}

void console_sleep(int x) {
	Sleep(x);
}

void how_to_play() {
	std::cout << "Welcome to my tic tac toe game!\n"
		<< "You must enter a number for the line and then for the column that must be between 1 and 3!\n";
	std::cout << "Do you understand to play ? Y/N\n";
	char user_prefer;
	std::cin >> user_prefer;
	if (user_prefer == 'Y' || user_prefer == 'y') {
		console_clean();
		std::cout << "Perfect! Get Started!\n";
		console_sleep(1000);
	}
	else {
		console_clean();
		std::cerr << "Hmmmmmm! Are you OK ? ... Answer: NO! Let's start anyway!\n";
		console_sleep(1000);
	}
	console_clean();
	std::cout << "Do you want to start? Y/N\n";
	std::cin >> user_prefer;
	if (user_prefer == 'Y' || user_prefer == 'y') {
		console_clean();
		comp_first = false;
		std::cout << "OK! Get Started!\n";
	}
	else {
		console_clean();
		comp_first = true;
		std::cout << "OK! Get Started!\n";
	}
}

void print_table() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j != 2) {
				std::cout << ' ' << table[i][j] << ' ' << '|';
			}
			else {
				std::cout << ' ' << table[i][j] << ' ';
			}
		}
		if (i != 2) std::cout << "\n---+---+---\n";
	}
}

void player_turn() {
	int row = 0, col = 0;
	std::cout << "\nYour move, player. You won't defeat me!";
	std::cout << "\nEnter row (1-3) and column (1-3): ";
	std::cin >> row >> col;

	while (row < 1 || row > 3 || col < 1 || col > 3 || table[row - 1][col - 1] != ' ') {
		std::cout << "\nThat is an invalid move. Try again.\n";
		std::cout << "\nEnter row (1-3) and column (1-3): ";
		std::cin >> row >> col;
	}

	table[row - 1][col - 1] = 'X';
	movesMade++;
}

bool game_won() {
	for (int i = 0; i < 3; i++) {
		if (table[i][0] != ' ' && table[i][0] == table[i][1] && table[i][1] == table[i][2]) return true;
		if (table[0][i] != ' ' && table[0][i] == table[1][i] && table[1][i] == table[2][i]) return true;
	}
	if (table[0][0] != ' ' && table[0][0] == table[1][1] && table[1][1] == table[2][2]) return true;
	if (table[0][2] != ' ' && table[0][2] == table[1][1] && table[1][1] == table[2][0]) return true;

	return false;
}

bool possible_win(char player) {
	for (int i = 0; i < 3; i++) {
		if ((table[i][0] == player && table[i][1] == player && table[i][2] == ' ') ||
			(table[i][0] == player && table[i][1] == ' ' && table[i][2] == player) ||
			(table[i][0] == ' ' && table[i][1] == player && table[i][2] == player)) return true;

		if ((table[0][i] == player && table[1][i] == player && table[2][i] == ' ') ||
			(table[0][i] == player && table[1][i] == ' ' && table[2][i] == player) ||
			(table[0][i] == ' ' && table[1][i] == player && table[2][i] == player)) return true;
	}
	if ((table[0][0] == player && table[1][1] == player && table[2][2] == ' ') ||
		(table[0][0] == player && table[1][1] == ' ' && table[2][2] == player) ||
		(table[0][0] == ' ' && table[1][1] == player && table[2][2] == player)) return true;

	if ((table[0][2] == player && table[1][1] == player && table[2][0] == ' ') ||
		(table[0][2] == player && table[1][1] == ' ' && table[2][0] == player) ||
		(table[0][2] == ' ' && table[1][1] == player && table[2][0] == player)) return true;

	return false;
}

void win_block() {
	for (int i = 0; i < 3; i++) {
		if (table[i][0] == 'X' && table[i][1] == 'X' && table[i][2] == ' ') { table[i][2] = 'O'; return; }
		if (table[i][0] == 'X' && table[i][1] == ' ' && table[i][2] == 'X') { table[i][1] = 'O'; return; }
		if (table[i][0] == ' ' && table[i][1] == 'X' && table[i][2] == 'X') { table[i][0] = 'O'; return; }

		if (table[0][i] == 'X' && table[1][i] == 'X' && table[2][i] == ' ') { table[2][i] = 'O'; return; }
		if (table[0][i] == 'X' && table[1][i] == ' ' && table[2][i] == 'X') { table[1][i] = 'O'; return; }
		if (table[0][i] == ' ' && table[1][i] == 'X' && table[2][i] == 'X') { table[0][i] = 'O'; return; }
	}
	if (table[0][0] == 'X' && table[1][1] == 'X' && table[2][2] == ' ') { table[2][2] = 'O'; return; }
	if (table[0][0] == ' ' && table[1][1] == 'X' && table[2][2] == 'X') { table[0][0] = 'O'; return; }
	if (table[0][2] == 'X' && table[1][1] == 'X' && table[2][0] == ' ') { table[2][0] = 'O'; return; }
}

void best_move() {
	if (table[1][1] == ' ') table[1][1] = 'O';
	else if (table[0][0] == ' ') table[0][0] = 'O';
	else if (table[0][2] == ' ') table[0][2] = 'O';
	else if (table[2][0] == ' ') table[2][0] = 'O';
	else if (table[2][2] == ' ') table[2][2] = 'O';
}

void computer_turn() {
	if (game_won()) {
		std::cout << "\nGame over!!\n";
	}
	else if (possible_win('O')) {
		win_block();
	}
	else {
		best_move();
	}
	movesMade++;
}

void tic_tac_toe_game() {
	bool rePlay = true;
	how_to_play();
	table_init();
	while (rePlay) {
		totalGames++;
		if (comp_first) {
			while (movesMade < 9) {
				computer_turn();
				if (game_won()) {
					std::cout << "\nI win! You cannot defeat me! I am superior! \n";
					break;
				}
				if (movesMade != 8) {
					player_turn();
				}
				print_table();
				if (game_won()) {
					winPlayer++;
					std::cerr << "\nWhat !? This is impossible! I am superior!\n";
					break;
				}
			}
			if (!game_won()) std::cout << "\nIt is a draw. You cannot win, this game is futile =(\n";
		}
		else {
			while (movesMade < 9) {
				player_turn();
				if (game_won()) {
					std::cout << "\nThis is impossible! You got lucky!\n";
					break;
				}
				if (movesMade != 9) computer_turn();
				print_table();
				if (game_won()) {
					winPlayer++;
					std::cout << "\nI knew you couldn't win. Bow to your machine master\n";
					break;
				}
			}
			if (!game_won()) std::cout << "\nIt is a draw. You done better than expected.\n";
		}

		char replay = '\0';
		console_sleep(2000);
		std::cerr << "Rematch ? Y/N\n";
		std::cin >> replay;
		if (replay != 'Y' && replay != 'y') {
			rePlay = false;
			table_init();
			movesMade = 0;
		}
	}
	console_clean();
	std::cout << "It made me happy because you played with me! =)\n";
	std::cout << "STATS\nTotal Match Numbers: " << totalGames << "\nPC WINS: " << totalGames - winPlayer << "\nYour wins: " << winPlayer;
}

int main() {
	tic_tac_toe_game();
	return 0;
}
