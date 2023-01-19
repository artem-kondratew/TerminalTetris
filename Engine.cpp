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


Engine::Engine(): Matrix(22, 10) {
    X = Zones::X + 1;
    Y = Zones::Y + 3;
    for (int row = 20; row < rows; row++)
        for (int col = 0; col < cols; col++) {
            data[row][col] = 1;
        }
    Field_pointer = this;
}


std::vector<int> T_vector = {0, 0, 0, 1, 1, 1 ,0, 1, 0};
Figure T_figure(T_vector, 3, 3);

std::vector<int> Q_vector = {1, 1, 1, 1};
Figure Q_figure(Q_vector, 2, 2, 1);

std::vector<int> I_vector = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0};
Figure I_figure(I_vector, 4, 4);

std::vector<int> Z_vector = {1, 1, 0, 0, 1, 1, 0, 0, 0};
Figure Z_figure(Z_vector, 3, 3);

std::vector<int> S_vector = {0, 1, 1, 1, 1, 0, 0, 0, 0};
Figure S_figure(S_vector, 3, 3);

std::vector<int> J_vector = {1, 0, 0, 1, 1, 1, 0, 0, 0};
Figure J_figure(J_vector, 3, 3);

std::vector<int> L_vector = {0, 0, 1, 1, 1, 1, 0, 0, 0};
Figure L_figure(L_vector, 3, 3);


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


void Engine::writeBits() {
    int shift = 0;
    if (figure.deltaY < 0) {
        shift = -figure.deltaY;
    }
    for (int row = figure.deltaY + shift; row < figure.deltaY + figure.rows; row++)
        for (int col = figure.deltaX; col < figure.deltaX + figure.cols; col++)
            if (figure.data[row-figure.deltaY][(col-figure.deltaX)] == 1) {
                data[row][col] = 1;
            }
}


int Engine::compareBits() {
    int shift = 0;
    if (figure.deltaY < 0) {
        shift = -figure.deltaY;
    }
    for (int row = figure.deltaY + shift; row < figure.deltaY + figure.rows; row++) {
        for (int col = figure.deltaX; col < figure.deltaX + figure.cols; col++) {
            if (data[row][col] + figure.data[row-figure.deltaY][col-figure.deltaX] == 2) {
                return 1;
            }
        }
    }
    return 0;
}


void Engine::refreshField() {
    for (int row = 0; row < rows - 2; row++)
        for (int col = 0; col < cols; col++) {
            move(Y + row, X + col * 2);
            (data[row][col] == 1) ? printw("[]") : printw("  ");

        }
    refresh();
}


int Engine::fillChecker() {
    int fill_level = 0;
    int buffer;
    for (int row = rows - 3; row >= 0; row--) {
        buffer = 0;
        for (int col = 0; col < cols; col++)
            if (data[row][col] == 1) {
                buffer = 1;
            }
        if (buffer == 1) {
            fill_level++;
        }
    }

    return (fill_level == 20) ? 1 : 0;
}

/*
void Engine::keyHandler(int s) {
}*/

void Engine::keyHandler(int key) {
    Engine Field = *Field_pointer;


}


void Engine::Gaming() {
    Engine Field;
    int create_flag = 1;
    int collision_flag;
    auto start_timer = std::chrono::system_clock::now();
    double k = 1.0;

    while (true) {
        if (create_flag == 1) {
            int random_number = generateRandomNumber();
            Field.figure = chooseNext(random_number);
            create_flag = 0;
            Field.figure.deltaX = (Zones::width - Field.figure.cols) / 2;
            Field.figure.deltaY = -Field.figure.getRows();
            k -= 0.01;
        }

        Field.figure.findBorders();
        move(20, 10);
        printw("%d %d", Field.figure.left_border, Field.figure.right_border);

        int key = getch();

        if (key == KEY_UP) {
            Field.figure.rotateLeft();
            Field.refreshField();
        }
        if (key == KEY_DOWN) {
            Field.figure.rotateRight();
            Field.refreshField();
        }
        if (key == KEY_LEFT) {
            Field.figure.moveFigure(-1);
            Field.refreshField();
        }
        if (key == KEY_RIGHT) {
            Field.figure.moveFigure(1);
            Field.refreshField();
        }

        Field.figure.X0 = Field.X + Field.figure.deltaX * 2;
        Field.figure.Y0 = Field.Y + Field.figure.deltaY;

        collision_flag = Field.compareBits();

        if (collision_flag == 1) {
            Field.figure.Y0--;
            Field.figure.deltaY--;
            Field.writeBits();
            create_flag = 1;
            //Tetris::increaseScore();
            Field.refreshField();
            continue;
        }

        //Field.refreshField();
        Field.figure.erase(Field.figure.X0, Field.figure.Y0 - 1, 3 + Field.figure.deltaY);
        Field.figure.paint(Field.figure.X0, Field.figure.Y0, 4 + Field.figure.deltaY);
        //refresh();

        auto end_timer = std::chrono::system_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(end_timer - start_timer).count() > int(1000 * k)) {
            Field.figure.deltaY++;
            start_timer = std::chrono::system_clock::now();
        }
    }
}
