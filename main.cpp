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

void newDrawField(short f[3][3]) {
    char cf[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (f[i][j] == 0) cf[i][j] = ' ';
            else if (f[i][j] == 1) cf[i][j] = 'x';
            else cf[i][j] = 'o';
        }
    }
    cout << "   1   2   3 " << endl;
    cout << " ┏━━━┳━━━┳━━━┓" << endl;
    cout << "1┃ " << cf[0][0] << " ┃ "<< cf[0][1] <<" ┃ "<< cf[0][2] <<" ┃" << endl;
    cout << " ┣━━━╋━━━╋━━━┫" << endl;
    cout << "2┃ " << cf[1][0] << " ┃ "<< cf[1][1] <<" ┃ "<< cf[1][2] <<" ┃" << endl;
    cout << " ┣━━━╋━━━╋━━━┫" << endl;
    cout << "3┃ " << cf[2][0] << " ┃ "<< cf[2][1] <<" ┃ "<< cf[2][2] <<" ┃" << endl;
    cout << " ┗━━━┻━━━┻━━━┛" << endl;
}

void makeTurn(short wt, short f[3][3]) {
    short a,b;
    bool inputIsGood = false;
    do {
        cin >> a >> b;
        if (a > 3 || a < 1 || b > 3 || b < 1) cout << "Первое число - строка, \nвторое число - столбец \nоба числа от 1 до 3\nСделайте ход: ";
        else if (f[a-1][b-1] != 0 ) cout << "Клетка занята, выберите другую: ";
        else inputIsGood = true;
    } while (!inputIsGood);
    f[a-1][b-1] = wt;
    
}

short gameEnded(short f[3][3]) {
    // проверка диагоналей
    if (f[0][0]+f[1][1]+f[2][2] == 3) return 1;
    else if (f[0][0]+f[1][1]+f[2][2] == -3) return -1;
    else if (f[0][2]+f[1][1]+f[2][0] == 3) return 1;
    else if (f[0][2]+f[1][1]+f[2][0] == -3) return -1;

    // проверка столбцов
    else if (f[0][0]+f[1][0]+f[2][0] == 3) return 1;
    else if (f[0][1]+f[1][1]+f[2][1] == 3) return 1;
    else if (f[0][2]+f[1][2]+f[2][2] == 3) return 1;

    else if (f[0][0]+f[1][0]+f[2][0] == -3) return -1;
    else if (f[0][1]+f[1][1]+f[2][1] == -3) return -1;
    else if (f[0][2]+f[1][2]+f[2][2] == -3) return -1;

    // проверка строк 
    else if (f[0][0]+f[0][1]+f[0][2] == 3) return 1;
    else if (f[1][0]+f[1][1]+f[1][2] == 3) return 1;
    else if (f[2][0]+f[2][1]+f[2][2] == 3) return 1;

    else if (f[0][0]+f[0][1]+f[0][2] == -3) return -1;
    else if (f[1][0]+f[1][1]+f[1][2] == -3) return -1;
    else if (f[2][0]+f[2][1]+f[2][2] == -3) return -1;
    return 0;
}


// 0 - НИЧЕГО, 1 - крестик, -1 - бублик
int main() {
    short field[3][3] = {{}};
    bool shutdown = false;
    short whoseTurn = 1;
    do {
        newDrawField(field);
        cout << "Сделайте ход";
        if (whoseTurn == 1) cout << " (X): ";
        else cout << " (O): ";
        makeTurn(whoseTurn, field);
        cout << "\n\n";
        if (gameEnded(field) != 0) {
            newDrawField(field);
            cout << "Игра завершена. Победил (";
            if (whoseTurn == 1) cout << "X)\n";
            else cout << "O)\n";
            shutdown = true;
        }
        whoseTurn *= -1;
    } while (!shutdown);
}