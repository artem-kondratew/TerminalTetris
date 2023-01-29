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


void Engine::setXY() {
    X = Zones::X + 1;
    Y = Zones::Y + 3;
}


Engine::Engine(): Matrix(22, 10) {
    setXY();
    for (int row = 20; row < rows; row++)
        for (int col = 0; col < cols; col++) {
            data[row][col] = 1;
        }
}


std::vector<int> T_vector = {0, 0, 0, 1, 1, 1 ,0, 1, 0};
Figure T_figure(T_vector, 3, 3, 0);

std::vector<int> Q_vector = {1, 1, 1, 1};
Figure Q_figure(Q_vector, 2, 2, 1, 1);

std::vector<int> I_vector = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0};
Figure I_figure(I_vector, 4, 4, 2);

std::vector<int> Z_vector = {1, 1, 0, 0, 1, 1, 0, 0, 0};
Figure Z_figure(Z_vector, 3, 3, 3);

std::vector<int> S_vector = {0, 1, 1, 1, 1, 0, 0, 0, 0};
Figure S_figure(S_vector, 3, 3, 4);

std::vector<int> J_vector = {1, 0, 0, 1, 1, 1, 0, 0, 0};
Figure J_figure(J_vector, 3, 3, 5);

std::vector<int> L_vector = {0, 0, 1, 1, 1, 1, 0, 0, 0};
Figure L_figure(L_vector, 3, 3, 6);


Figure Engine::chooseNextFigure(int random_number) {
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


void Engine::moveFigure(int step) {
    figure.findBorders();
    if (figure.deltaX + figure.left_border + step >= 0 && figure.deltaX + figure.right_border + step < 10) {
        figure.deltaX += step;
    }
    if (compareBits() == 1) {
        figure.deltaX -= step;
    }
}


void Engine::refreshField() {
    for (int row = 0; row < rows - 2; row++) {
        for (int col = 0; col < cols; col++) {
            move(Y + row, X + col * 2);
            if (data[row][col] == 1) {
                printw("[]");
            }
            else {
                if (0 <= row - figure.deltaY &&  row - figure.deltaY < figure.rows && 0 <= col - figure.deltaX && col - figure.deltaX < figure.cols) {
                    if (figure.data[row-figure.deltaY][col-figure.deltaX] == 0) {
                        printw("  ");
                    }
                }
                else {
                    printw("  ");
                }
            }
        }
    }
    refresh();
}


int Engine::fillCheck() {
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


int Engine::findx0(int random_number) {
    if (random_number == 2) {
        return Zones::next_X + 3 + (9 - next_figure.cols)/2;
    }
    return Zones::next_X + 3 + (10 - next_figure.cols)/2;
}


int Engine::findy0() {
    return Zones::next_Y - next_figure.findFullBottom();
}


void Engine::eraseNextFigure() {
    next_figure.dangerErase(findx0(next_figure.type_number), findy0());
}


void Engine::paintNextFigure() {
    next_figure.paint(findx0(next_figure.type_number), findy0(), figure.rows);
    refresh();
}


void Engine::generateNextFigure() {
    eraseNextFigure();
    figure = next_figure;
    int random_number = generateRandomNumber();
    next_figure = chooseNextFigure(random_number);
    paintNextFigure();
}


void Engine::dropFigure() {
    Tetris::increaseScore(1);
    figure.deltaY++;
}


void Engine::shiftField(int series_row) {
    for (int row = series_row; row >= 0; row--)
        for (int col = 0; col < cols; col++) {
            if (row > 0) {
                data[row][col] = data[row-1][col];
            }
            else {
                data[row][col] = 0;
            }
        }
    refresh();
}


void Engine::findSeries() {
    int series;
    int series_number = 0;
    int series_score = 0;
    for (int row = 0; row < rows - 2; row++) {
        series = 0;
        for (int col = 0; col < cols; col++) {
            if (data[row][col] == 1) {
                series++;
            }
        }
        if (series == 10) {
            series_number++;
            series_score += 100 * series_number;
            shiftField(row);
        }
    }
    Tetris::increaseScore(series_score);
}


void Engine::resizeHandler() {
    Engine::paintNextFigure();
}


void Engine::Gaming() {
    Engine Field;
    int create_flag = 1;
    int collision_flag;
    auto start_timer = std::chrono::system_clock::now();
    double k = 1.0;
    int paint_number;

    next_figure = chooseNextFigure(generateRandomNumber());

    while (true) {
        if (resize_flag == 1) {
            Field.setXY();
            resize_flag = 0;
        }

        if (create_flag == 1) {
            Field.generateNextFigure();
            figure.deltaX = (Zones::field_width - figure.cols) / 2;
            figure.deltaY = -figure.getRows() + figure.cutEmptyBottom();
            k -= 0.01;
            create_flag = 0;
        }

        int key = getch();

        if (key == KEY_ESC) {
            Tetris::pause();
        }
        if (key == KEY_UP) {
            figure.rotateLeft();
            Field.refreshField();
        }
        if (key == KEY_DOWN) {
            Field.dropFigure();
            Field.refreshField();
        }
        if (key == KEY_LEFT) {
            Field.moveFigure(-1);
            Field.refreshField();
        }
        if (key == KEY_RIGHT) {
            Field.moveFigure(1);
            Field.refreshField();
        }

        figure.X0 = Field.X + figure.deltaX * 2;
        figure.Y0 = Field.Y + figure.deltaY;

        collision_flag = Field.compareBits();

        if (collision_flag == 1) {
            figure.Y0--;
            figure.deltaY--;
            Field.writeBits();
            Field.refreshField();
            Field.findSeries();
            if (Field.fillCheck() == 1) {
                return;
            }
            create_flag = 1;
            continue;
        }

        paint_number = figure.rows + figure.deltaY;
        Field.refreshField();
        figure.paint(figure.X0, figure.Y0, paint_number);

        auto end_timer = std::chrono::system_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(end_timer - start_timer).count() > int(1000 * k)) {
            figure.deltaY++;
            start_timer = std::chrono::system_clock::now();
        }
    }
}
