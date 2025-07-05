#include <iostream>

using namespace std;

constexpr unsigned char WATER = 178;

constexpr unsigned char NOSE_N = 203;
constexpr unsigned char FRONT_WING_CENTER_N = 206;
constexpr unsigned char FRONT_WING_LEFT_N = 205;
constexpr unsigned char FRONT_WING_LEFT_TIP_N = 201;
constexpr unsigned char FRONT_WING_RIGHT_N = 205;
constexpr unsigned char FRONT_WING_RIGHT_TIP_N = 187;
constexpr unsigned char BODY_N = 186;
constexpr unsigned char BACK_WING_CENTER_N = 202;
constexpr unsigned char BACK_WING_LEFT_TIP_N = 201;
constexpr unsigned char BACK_WING_RIGHT_TIP_N = 187;

constexpr unsigned char NOSE_S = 178;
constexpr unsigned char FRONT_WING_CENTER_S = 178;
constexpr unsigned char FRONT_WING_LEFT_S = 178;
constexpr unsigned char FRONT_WING_LEFT_TIP_S = 178;
constexpr unsigned char FRONT_WING_RIGHT_S = 178;
constexpr unsigned char FRONT_WING_RIGHT_TIP_S = 178;
constexpr unsigned char BODY_S = 178;
constexpr unsigned char BACK_WING_CENTER_S = 178;
constexpr unsigned char BACK_WING_LEFT_TIP_S = 178;
constexpr unsigned char BACK_WING_RIGHT_TIP_S = 178;

constexpr unsigned char NOSE_E = 178;
constexpr unsigned char FRONT_WING_CENTER_E = 178;
constexpr unsigned char FRONT_WING_LEFT_E = 178;
constexpr unsigned char FRONT_WING_LEFT_TIP_E = 178;
constexpr unsigned char FRONT_WING_RIGHT_E = 178;
constexpr unsigned char FRONT_WING_RIGHT_TIP_E = 178;
constexpr unsigned char BODY_E = 178;
constexpr unsigned char BACK_WING_CENTER_E = 178;
constexpr unsigned char BACK_WING_LEFT_TIP_E = 178;
constexpr unsigned char BACK_WING_RIGHT_TIP_E = 178;

constexpr unsigned char NOSE_W = 178;
constexpr unsigned char FRONT_WING_CENTER_W = 178;
constexpr unsigned char FRONT_WING_LEFT_W = 178;
constexpr unsigned char FRONT_WING_LEFT_TIP_W = 178;
constexpr unsigned char FRONT_WING_RIGHT_W = 178;
constexpr unsigned char FRONT_WING_RIGHT_TIP_W = 178;
constexpr unsigned char BODY_W = 178;
constexpr unsigned char BACK_WING_CENTER_W = 178;
constexpr unsigned char BACK_WING_LEFT_TIP_W = 178;
constexpr unsigned char BACK_WING_RIGHT_TIP_W = 178;

int planes_count = 0, ci, cj;
unsigned char p1[10][10], p2[10][10], c1[10][10], c2[10][10];
enum Mode { N, S, E, W };

void create_terrains() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            p1[i][j] = WATER;
            p2[i][j] = WATER;
            c1[i][j] = WATER;
            c2[i][j] = WATER;
        }
    }
};

bool validate_mode(const unsigned char terrain[10][10], const Mode mode, const int pos_x, const int pos_y) {
    switch (mode) {
        case N:
            if (pos_x - 1 < 0 || pos_x + 2 > 9 || pos_y - 2 < 0 || pos_y + 2 > 9) {
                return false;
            }

            if (
                terrain[pos_x][pos_y] != WATER ||
                terrain[pos_x - 1][pos_y] != WATER ||
                terrain[pos_x][pos_y - 1] != WATER ||
                terrain[pos_x][pos_y + 1] != WATER ||
                terrain[pos_x][pos_y - 2] != WATER ||
                terrain[pos_x][pos_y + 2] != WATER ||
                terrain[pos_x + 1][pos_y] != WATER ||
                terrain[pos_x + 2][pos_y - 1] != WATER ||
                terrain[pos_x + 2][pos_y] != WATER ||
                terrain[pos_x + 2][pos_y + 1] != WATER
            ) {
                return false;
            }

            return true;
        case S:
            return true;

        case E:
            return true;

        case W:
            return true;
    }
}

void show_terrain(const unsigned char(* p1)[10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << p1[i][j];
        }
        cout << endl;
    }
};

void place_plane(const Mode mode, const int pos_x, const int pos_y) {
    if (!validate_mode(p1, mode, pos_x, pos_y)) {
        cout << "Positioning of the plane was not possible because of overlapping or out of bounds." << endl;
        return;
    }

    switch (mode) {
        case N:
            p1[pos_x][pos_y] = FRONT_WING_CENTER_N;
            p1[pos_x - 1][pos_y] = NOSE_N;
            p1[pos_x][pos_y - 1] = FRONT_WING_LEFT_N;
            p1[pos_x][pos_y + 1] = FRONT_WING_RIGHT_N;
            p1[pos_x][pos_y - 2] = FRONT_WING_LEFT_TIP_N;
            p1[pos_x][pos_y + 2] = FRONT_WING_RIGHT_TIP_N;
            p1[pos_x + 1][pos_y] = BODY_N;
            p1[pos_x + 2][pos_y - 1] = BACK_WING_LEFT_TIP_N;
            p1[pos_x + 2][pos_y] = BACK_WING_CENTER_N;
            p1[pos_x + 2][pos_y + 1] = BACK_WING_RIGHT_TIP_N;

            break;

        case S:
            break;

        case E:
            break;

        case W:
            break;
    }

    show_terrain(p1);
};

void clear_screen() {
    cout << "\033[2J\033[1;1H";
}

int main() {
    create_terrains();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << p1[i][j];
        }
        cout << endl;
    }
    show_terrain(p1);

    while (planes_count < 3) {
        cout << "Enter direction of the plan (N,S,E,W): ";
        char input;
        int pos_x, pos_y;
        cin >> input;
        Mode mode;
        switch (input) {
            case 'N':
            case 'n':
                mode = Mode::N;

                break;

            case 'S':
            case 's':
                mode = Mode::S;

                break;

            case 'E':
            case 'e':
                mode = Mode::E;

                break;

            case 'W':
            case 'w':
                mode = Mode::W;

                break;

            default:
                cout << "Invalid mode provided." << endl;
                continue;
        }
        system("cls");
        cout << "Enter the horizontal position of the plane: ";
        cin >> pos_x;
        cout << endl;
        cout << "Enter the vertical position of the plane: ";
        cin >> pos_y;
        cout << endl;
        place_plane(mode, pos_x, pos_y);

        planes_count++;
        clear_screen();
    }

    return 0;
}
