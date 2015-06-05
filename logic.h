#pragma once
#ifndef LOGIC_H
#define LOGIC_H
#include <array>
#include <bitset>



class Logic {
    template <class T, size_t N> using array = std::array<T, N>;
    template <size_t N> using bitset = std::bitset<N>;

public:
    using Field = array<bitset<100>, 100>;

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
