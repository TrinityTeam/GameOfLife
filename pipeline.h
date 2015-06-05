#pragma once
#ifndef PIPELINE_H
#define PIPELINE_H
#include <array>

struct Matrix {
    template <typename T, size_t N>
        using array = std::array<T, N>;

    array<array<float, 4>, 4> m;
};


class Pipeline {
public:
    Pipeline();

    void setWorldPosition(float x, float y, float z);

    const Matrix& getTransformation();

private:
    float worldPosition[3];
    Matrix transformation;

};

#endif // PIPELINE_H
