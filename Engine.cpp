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


int Engine::generateRandomNumber() {
    return my_rand(0, 6);
}


void Engine::FieldCleaner(int x, int y) {
    move(y, x);
    printw("        ");
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
}


void Engine::Gaming(Engine Field) {
    int y_add = -4;
    int create_flag = 1;
    Figure figure;

    while (true) {
        if (create_flag == 1) {
            int random_number = generateRandomNumber();
            figure = chooseNext(random_number);
            create_flag = 0;
        }

        if (y_add > 0) {
            Engine::FieldCleaner(Field.X + 6, Field.Y + y_add - 1);
        }
        figure.paintFigure(Field.X + 6, Field.Y + y_add, 4 + y_add);
        refresh();
        sleep(1);
        y_add++;

        if (y_add > 16) {
            create_flag = 1;
            y_add = -4;
        }
    }
}
