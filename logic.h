#pragma once
#ifndef LOGIC_H
#define LOGIC_H
#include <array>



class Logic {
    template <class T, size_t N> using array = std::array<T, N>;

public:
    using Field = array<array<char, 100>, 100>;
    enum State {Dead = 0, Live = 1};

    Logic();

    void setField(const Field& field);
    void randomizeField();
    void updateField();
    const Field& getField() const;

private:
    char getAdjastentCellsNum(char pos_x, char pos_y) const;

    Field field;

};

#endif // LOGIC_H
