#include <iostream>

using namespace std;

void drawField(short f[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (f[i][j] == 0) cout << " ";
            else if (f[i][j] == 1) cout << "X";
            else cout << "O";
            if (j != 2) cout << " ┃ ";
            else cout << "\n";
        }
        if (i != 2) cout << "━━╋━━━╋━━\n";
    }
}

void makeTurn(short wt, short f[3][3]) {
    short a,b;
    bool inputIsGood = false;
    do {
        cin >> a >> b;
        if (a > 3 || a < 1 || b > 3 || b < 1) cout << "Первое число - строка, \nвторое число - столбец \nоба числа от 1 до 3.";
        else inputIsGood = true;
    } while (!inputIsGood);
}

bool gameEnded(short f[3][3]) {

    return false;
}


// 0 - НИЧЕГО, 1 - крестик, 2 - бублик
int main() {
    short field[3][3] = {{}};
    bool shutdown = false;
    short whoseTurn = 1;
    do {
        drawField(field);
        cout << "Сделайте ход";
        if (whoseTurn == 1) cout << " (X): ";
        else cout << " (O): ";
        makeTurn(whoseTurn, field);
        
    } while (!shutdown);
    
    

    
}