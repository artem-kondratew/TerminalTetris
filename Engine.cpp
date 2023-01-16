//
// Created by user on 1/15/23.
//

#include "Engine.h"


// A function to return a seeded random number generator.
inline std::mt19937& generator() {
    // the generator will only be seeded once (per thread) since it's static
    static thread_local std::mt19937 gen(std::random_device{}());
    return gen;
}

// A function to generate integers in the range [min, max]
template<typename T, std::enable_if_t<std::is_integral_v<T>>* = nullptr>
T my_rand(T min, T max) {
    std::uniform_int_distribution<T> dist(min, max);
    return dist(generator());
}


int Engine::generateRandomNumber() {
    return my_rand(0, 6);
}


Engine::Engine(): Matrix(20, 10) {
    X = Zones::X + 1;
    Y = Zones::Y + 3;
    move(Y, X);
    printw("0");
    refresh();
}

Engine::~Engine() {
    X = NAN;
    Y = NAN;
}


std::vector<int> T_vector = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0};
Figure T_figure(T_vector);

std::vector<int> Q_vector = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0};
Figure Q_figure(Q_vector);

std::vector<int> I_vector = {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0};
Figure I_figure(I_vector);

std::vector<int> Z_vector = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0};
Figure Z_figure(Z_vector);

std::vector<int> S_vector = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0};
Figure S_figure(S_vector);

std::vector<int> J_vector = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0};
Figure J_figure(J_vector);

std::vector<int> L_vector = {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0};
Figure L_figure(L_vector);


Figure Engine::chooseNext(int random_number) {
    switch (random_number) {
        case 0:
            return T_figure;
        case 1:
            return Q_figure;
        case 2:
            return I_figure;
        case 3:
            return Z_figure;
        case 4:
            return S_figure;
        case 5:
            return J_figure;
        case 6:
            return L_figure;
        default:
            break;
    }
    return {};
}


void Engine::writeBits(const Figure& figure, int y_add) {
    int shift = 0;
    if (y_add < 0) {
        shift = -y_add;
    }
    for (int row = y_add + shift; row < y_add + 4; row++)
        for (int col = figure.deltaX; col < figure.deltaX + 8; col += 2)
            if (figure.data[row-y_add][(col-figure.deltaX)/2] == 1) {
                data[row][col] = 1;
            }
}


int Engine::compareBits(const Figure& figure, int y_add) {
    int shift = 0;
    if (y_add < 0) {
        shift = -y_add;
    }
    for (int row = y_add + shift; row < y_add + 4; row++) {
        for (int col = figure.deltaX; col < figure.deltaX + 8; col += 2) {
            if (data[row][col] + figure.data[row-y_add][(col-figure.deltaX)/2] == 2) {
                return 1;
            }
            move(row + Y, col + X);
            //printw("s");
            refresh();
        }
        //sleep(1);
    }
    return 0;
}


void Engine::Gaming(Engine Field) {
    Figure figure;
    int y_add = -4;
    int create_flag = 1;
    int collision_flag;
    int cnt = 0;
    auto start_timer = std::chrono::system_clock::now();

    while (true) {

        if (create_flag == 1) {
            int random_number = generateRandomNumber();
            figure = chooseNext(random_number);
            create_flag = 0;
            figure.deltaX = 6;
            figure.deltaY = y_add;
        }

        if (getch() == KEY_UP) {
            figure.rotateLeft();
            refresh();

        }

        if (getch() == KEY_DOWN) {
            figure.rotateRight();
            refresh();
        }

        figure.X0 = Field.X + figure.deltaX;
        figure.Y0 = Field.Y + y_add;

        collision_flag = Field.compareBits(figure, y_add);

        if (collision_flag == 1) {
            figure.Y0--;
            y_add--;
            figure.deltaY--;
            Field.writeBits(figure, y_add);
            create_flag = 1;
            y_add = -4;
            continue;
        }

        figure.erase(figure.X0, figure.Y0 - 1, 3 + y_add);
        figure.paint(figure.X0, figure.Y0, 4 + y_add);

        if (y_add == 16) {
            Field.writeBits(figure, y_add);
            create_flag = 1;
            y_add = -4;
        }

        auto end_timer = std::chrono::system_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(end_timer - start_timer).count() > 1000) {
            y_add++;
            figure.deltaY++;
            start_timer = std::chrono::system_clock::now();
        }
    }
}
