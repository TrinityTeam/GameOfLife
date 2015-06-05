#include "pipeline.h"

Pipeline::Pipeline() {
    worldPosition[0] = 0.0f;
    worldPosition[1] = 0.0f;
    worldPosition[2] = 0.0f;
}



void Pipeline::setWorldPosition(float x, float y, float z) {
    worldPosition[0] = x;
    worldPosition[1] = y;
    worldPosition[2] = z;
}



const Matrix& Pipeline::getTransformation() {
    transformation.m[0] = {1.0f, 0.0f, 0.0f, worldPosition[0]};
    transformation.m[1] = {0.0f, 1.0f, 0.0f, worldPosition[1]};
    transformation.m[2] = {0.0f, 0.0f, 1.0f, worldPosition[2]};
    transformation.m[3] = {0.0f, 0.0f, 0.0f, 1.0f};

    return transformation;
}
