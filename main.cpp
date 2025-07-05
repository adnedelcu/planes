#include <iostream>

using namespace std;

#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BG_BLACK "\033[40m"            /* Backgroun Black */
#define BG_RED "\033[41m"              /* Backgroun Red */
#define BG_GREEN "\033[42m"            /* Backgroun Green */
#define BG_YELLOW "\033[43m"           /* Backgroun Yellow */
#define BG_BLUE "\033[44m"             /* Backgroun Blue */
#define BG_MAGENTA "\033[45m"          /* Backgroun Magenta */
#define BG_CYAN "\033[46m"             /* Backgroun Cyan */
#define BG_WHITE "\033[47m"            /* Backgroun White */
#define BOLD_BLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLD_RED "\033[1m\033[31m"     /* Bold Red */
#define BOLD_GREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLD_YELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLD_BLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLD_MAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLD_CYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLD_WHITE "\033[1m\033[37m"   /* Bold White */

/*
 ┤ ╡ ╖ ╕ ╣ ║ ╜
 ╛ ┐ └ ╞ ╩ ╦ ╠
 ═ ╬ ╨ ╥ ╙ ╘ ╒
 ┘ ┌
 */

/*
North       East
  ╥           ╖
╒═╬═╕       ┐ ║
  ║         ╞═╬╡
 ┌╨┐        ┘ ║
              ╜

South        West
 └╥┘         ╓
  ║          ║ ┌
╘═╬═╛       ╞╬═╡
  ╨          ║ └
             ╙
*/

/** Water component */
string WATER = "▓";

/** North orientation plane components */
string NOSE_N = "╥";
string FRONT_WING_CENTER_N = "╬";
string FRONT_WING_LEFT_N = "═";
string FRONT_WING_LEFT_TIP_N = "╒";
string FRONT_WING_RIGHT_N = "═";
string FRONT_WING_RIGHT_TIP_N = "╕";
string BODY_N = "║";
string BACK_WING_CENTER_N = "╨";
string BACK_WING_LEFT_TIP_N = "┌";
string BACK_WING_RIGHT_TIP_N = "┐";

/** South orientation plane components */
string NOSE_S = "╨";
string FRONT_WING_CENTER_S = "╬";
string FRONT_WING_LEFT_S = "═";
string FRONT_WING_LEFT_TIP_S = "╘";
string FRONT_WING_RIGHT_S = "═";
string FRONT_WING_RIGHT_TIP_S = "╛";
string BODY_S = "║";
string BACK_WING_CENTER_S = "╥";
string BACK_WING_LEFT_TIP_S = "└";
string BACK_WING_RIGHT_TIP_S = "┘";

/** East orientation plane components */
string NOSE_E = "╡";
string FRONT_WING_CENTER_E = "╬";
string FRONT_WING_LEFT_E = "║";
string FRONT_WING_LEFT_TIP_E = "╖";
string FRONT_WING_RIGHT_E = "║";
string FRONT_WING_RIGHT_TIP_E = "╜";
string BODY_E = "═";
string BACK_WING_CENTER_E = "╞";
string BACK_WING_LEFT_TIP_E = "┐";
string BACK_WING_RIGHT_TIP_E = "┘";

/** West orientation plane components */
string NOSE_W = "╞";
string FRONT_WING_CENTER_W = "╬";
string FRONT_WING_LEFT_W = "║";
string FRONT_WING_LEFT_TIP_W = "╙";
string FRONT_WING_RIGHT_W = "║";
string FRONT_WING_RIGHT_TIP_W = "╓";
string BODY_W = "═";
string BACK_WING_CENTER_W = "╡";
string BACK_WING_LEFT_TIP_W = "└";
string BACK_WING_RIGHT_TIP_W = "┌";

int planes_count = 0, ci, cj;
string p1[10][10], p2[10][10], c1[10][10], c2[10][10];
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

bool validate_mode(const string terrain[10][10], const Mode mode, const int pos_x, const int pos_y) {
    cout << "X: " << pos_x << " Y: " << pos_y << endl;
    switch (mode) {
        case N:
            /**
             * min and max limits
             * x = 0, y = 2
             * x = 0, y = 7
             * x = 6, y = 2
             * x = 6, y = 7
             */
            if (pos_x < 0 || pos_x > 6 || pos_y < 2 || pos_y > 7) {
                return false;
            }

            if (
                terrain[pos_x][pos_y] != WATER ||
                terrain[pos_x + 1][pos_y] != WATER ||
                terrain[pos_x + 1][pos_y - 1] != WATER ||
                terrain[pos_x + 1][pos_y + 1] != WATER ||
                terrain[pos_x + 1][pos_y - 2] != WATER ||
                terrain[pos_x + 1][pos_y + 2] != WATER ||
                terrain[pos_x + 2][pos_y] != WATER ||
                terrain[pos_x + 3][pos_y - 1] != WATER ||
                terrain[pos_x + 3][pos_y] != WATER ||
                terrain[pos_x + 3][pos_y + 1] != WATER
            ) {
                return false;
            }

            return true;

        case S:
            /**
             * min and max limits
             * x = 9, y = 7
             * x = 9, y = 2
             * x = 3, y = 7
             * x = 3, y = 2
             */
            if (pos_x < 3 || pos_x > 9 || pos_y < 2 || pos_y > 7) {
                return false;
            }

            if (
                terrain[pos_x][pos_y] != WATER ||
                terrain[pos_x - 1][pos_y] != WATER ||
                terrain[pos_x - 1][pos_y - 1] != WATER ||
                terrain[pos_x - 1][pos_y + 1] != WATER ||
                terrain[pos_x - 1][pos_y - 2] != WATER ||
                terrain[pos_x - 1][pos_y + 2] != WATER ||
                terrain[pos_x - 2][pos_y] != WATER ||
                terrain[pos_x - 3][pos_y - 1] != WATER ||
                terrain[pos_x - 3][pos_y] != WATER ||
                terrain[pos_x - 3][pos_y + 1] != WATER
            ) {
                return false;
            }

            return true;

        case E:
            /**
             * min and max limits
             * x = 2, y = 3
             * x = 2, y = 9
             * x = 7, y = 3
             * x = 7, y = 9
             */
            if (pos_x < 2 || pos_x > 7 || pos_y < 3 || pos_y > 9)
            {
                return false;
            }

            if (
                terrain[pos_x][pos_y] != WATER ||
                terrain[pos_x][pos_y - 1] != WATER ||
                terrain[pos_x - 1][pos_y - 1] != WATER ||
                terrain[pos_x + 1][pos_y - 1] != WATER ||
                terrain[pos_x - 2][pos_y - 1] != WATER ||
                terrain[pos_x + 2][pos_y - 1] != WATER ||
                terrain[pos_x][pos_y - 2] != WATER ||
                terrain[pos_x - 1][pos_y - 3] != WATER ||
                terrain[pos_x][pos_y - 3] != WATER ||
                terrain[pos_x + 1][pos_y - 3] != WATER
            ) {
                return false;
            }

            return true;

        case W:
            /**
             * min and max limits
             * x = 2, y = 0
             * x = 2, y = 6
             * x = 7, y = 0
             * x = 7, y = 6
             */
            if (pos_x < 2 || pos_x > 7 || pos_y < 0 || pos_y > 6)
            {
                return false;
            }

            if (
                terrain[pos_x][pos_y] != WATER ||
                terrain[pos_x][pos_y + 1] != WATER ||
                terrain[pos_x - 1][pos_y + 1] != WATER ||
                terrain[pos_x + 1][pos_y + 1] != WATER ||
                terrain[pos_x - 2][pos_y + 1] != WATER ||
                terrain[pos_x + 2][pos_y + 1] != WATER ||
                terrain[pos_x][pos_y + 2] != WATER ||
                terrain[pos_x - 1][pos_y + 3] != WATER ||
                terrain[pos_x][pos_y + 3] != WATER ||
                terrain[pos_x + 1][pos_y + 3] != WATER
            ) {
                return false;
            }

            return true;
    }
}

void show_terrain(const string(* p1)[10]) {
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            if (j == 0 && i == 0) {
                cout << " ";
                continue;
            }
            if (j == 0) {
                cout << (char)(i+64);
                continue;
            }
            if (i == 0) {
                cout << j;
                continue;
            }
            cout << BLUE;
            if (p1[i - 1][j - 1] != WATER) {
                cout << BG_BLUE << WHITE;
            }
            cout << p1[i - 1][j - 1];
            cout << RESET;
        }
        cout << endl;
    }
};

void place_plane(const Mode mode, const int pos_x, const int pos_y, bool should_show_terrain = true)
{
    switch (mode) {
        case N:
            p1[pos_x][pos_y] = NOSE_N;
            p1[pos_x + 1][pos_y] = FRONT_WING_CENTER_N;
            p1[pos_x + 1][pos_y - 1] = FRONT_WING_LEFT_N;
            p1[pos_x + 1][pos_y + 1] = FRONT_WING_RIGHT_N;
            p1[pos_x + 1][pos_y - 2] = FRONT_WING_LEFT_TIP_N;
            p1[pos_x + 1][pos_y + 2] = FRONT_WING_RIGHT_TIP_N;
            p1[pos_x + 2][pos_y] = BODY_N;
            p1[pos_x + 3][pos_y - 1] = BACK_WING_LEFT_TIP_N;
            p1[pos_x + 3][pos_y] = BACK_WING_CENTER_N;
            p1[pos_x + 3][pos_y + 1] = BACK_WING_RIGHT_TIP_N;

            break;

        case S:
            p1[pos_x][pos_y] = NOSE_S;
            p1[pos_x - 1][pos_y] = FRONT_WING_CENTER_S;
            p1[pos_x - 1][pos_y - 1] = FRONT_WING_LEFT_S;
            p1[pos_x - 1][pos_y + 1] = FRONT_WING_RIGHT_S;
            p1[pos_x - 1][pos_y - 2] = FRONT_WING_LEFT_TIP_S;
            p1[pos_x - 1][pos_y + 2] = FRONT_WING_RIGHT_TIP_S;
            p1[pos_x - 2][pos_y] = BODY_S;
            p1[pos_x - 3][pos_y - 1] = BACK_WING_LEFT_TIP_S;
            p1[pos_x - 3][pos_y] = BACK_WING_CENTER_S;
            p1[pos_x - 3][pos_y + 1] = BACK_WING_RIGHT_TIP_S;

            break;

        case E:
            p1[pos_x][pos_y] = NOSE_E;
            p1[pos_x][pos_y - 1] = FRONT_WING_CENTER_E;
            p1[pos_x - 1][pos_y - 1] = FRONT_WING_LEFT_E;
            p1[pos_x + 1][pos_y - 1] = FRONT_WING_RIGHT_E;
            p1[pos_x - 2][pos_y - 1] = FRONT_WING_LEFT_TIP_E;
            p1[pos_x + 2][pos_y - 1] = FRONT_WING_RIGHT_TIP_E;
            p1[pos_x][pos_y - 2] = BODY_E;
            p1[pos_x - 1][pos_y - 3] = BACK_WING_LEFT_TIP_E;
            p1[pos_x][pos_y - 3] = BACK_WING_CENTER_E;
            p1[pos_x + 1][pos_y - 3] = BACK_WING_RIGHT_TIP_E;

            break;

        case W:
            p1[pos_x][pos_y] = NOSE_W;
            p1[pos_x][pos_y + 1] = FRONT_WING_CENTER_W;
            p1[pos_x + 1][pos_y + 1] = FRONT_WING_LEFT_W;
            p1[pos_x - 1][pos_y + 1] = FRONT_WING_RIGHT_W;
            p1[pos_x + 2][pos_y + 1] = FRONT_WING_LEFT_TIP_W;
            p1[pos_x - 2][pos_y + 1] = FRONT_WING_RIGHT_TIP_W;
            p1[pos_x][pos_y + 2] = BODY_W;
            p1[pos_x + 1][pos_y + 3] = BACK_WING_LEFT_TIP_W;
            p1[pos_x][pos_y + 3] = BACK_WING_CENTER_W;
            p1[pos_x - 1][pos_y + 3] = BACK_WING_RIGHT_TIP_W;

            break;
    }

    cout << "Seems the position for this orientation works. Here's you current battlefield." << endl;
    if (should_show_terrain) {
        show_terrain(p1);
    }
};

void clear_screen() {
    cout << "\033[2J\033[1;1H";
}

int main() {
    create_terrains();
    show_terrain(p1);

    while (planes_count < 4) {
        cout << "Enter direction of the plan (N,S,E,W): ";
        char input, pos_x;
        int pos_y;
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
        cout << "Enter the vertical position of the plane (A - J): ";
        cin >> pos_x;
        cout << endl;
        cout << "Enter the horizontal position of the plane (1 - 10): ";
        cin >> pos_y;
        cout << endl;
        int hor_pos, ver_pos;
        if (pos_x - 64 >= 1 && pos_x - 64 <= 10) {
            hor_pos = pos_x - 65;
        }
        if (pos_x - 96 >= 1 && pos_x - 96 <= 10) {
            hor_pos = pos_x - 97;
        }
        if (pos_y >= 1 && pos_y <= 10) {
            ver_pos = pos_y - 1;
        }
        clear_screen();
        cout << "You chose orientation " << input << " and position " << pos_x << pos_y << ". Let's see if it can be placed." << endl;
        if (!validate_mode(p1, mode, hor_pos, ver_pos))
        {
            cout << "Positioning of the plane was not possible because of overlapping or out of bounds." << endl;
            show_terrain(p1);
            continue;
        }
        place_plane(mode, hor_pos, ver_pos);
        planes_count++;
    }

    cout << "Now that you have placed all your planes, let me place mine and then we can start the fight." << endl;

    planes_count = 0;
    while (planes_count < 3) {
        Mode mode = static_cast<Mode>(rand() % 3);
        int hor_pos = rand() % 7 + 1;
        int ver_pos = rand() % 7 + 1;
        if (validate_mode(c1, mode, hor_pos, ver_pos)) {
            continue;
        }
        // @TODO: fix placing computer plane
        // place_plane(mode, hor_pos, ver_pos);
        planes_count++;
    }

    cout << "Thanks for waiting. Now let's fight. Prepare to go down." << endl;

    return 0;
}
