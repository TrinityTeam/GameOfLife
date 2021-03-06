#include "logic.h"
#include <time.h>
#include <assert.h>



Logic::Logic() {
    field[0] = {1, 1, 1, 0};
    field[1] = {0, 1, 1, 1};
    field[2] = {1, 1, 1, 0};

    /*field[0][0] = 1;
    field[99][99] = 1;
    field[0][99] = 1;
    field[99][0] = 1;*/

}



void Logic::setField(const Field& field) {
    this->field = field;
}



void Logic::randomizeField() {
    srand(clock());
    for(short c = 0; c < 100; c++) {
        for(short i = 0; i < 100; i++) {
            field[c][i] = rand()%2;
        }
    }
}



void Logic::updateField() {
    char adjastent[100][100];

    for(short c = 0; c < 100; c++) {
        for(short i = 0; i < 100; i++) {
            adjastent[c][i] = getAdjastentCellsNum(c , i);
        }
    }

    for(short c = 0; c < 100; c++) {
        for(short i = 0; i < 100; i++) {
            if(field[c][i] == Dead and
               adjastent[c][i] == 3) {
                field[c][i] = Live;
            }
        }
    }

    for(short c = 0; c < 100; c++) {
        for(short i = 0; i < 100; i++) {
            if(field[c][i] == Live and
               (adjastent[c][i] < 2 or
                adjastent[c][i] > 3)) {
                field[c][i] = Dead;
            }
        }
    }
}



const Logic::Field& Logic::getField() const {
    return field;
}



char Logic::getAdjastentCellsNum(char x, char y) const {
    assert(x < 100 and x > -1 and
           y < 100 and y > -1);
    char live_cells = 0;

    if(field[x][y] != 0) live_cells--;

    if(x != 0 and y != 0 and
       x != 99 and y != 99) {
        for(short c = -1; c < 2; c++)
            for(short i = -1; i < 2; i++)
                if(field[x+c][y+i] != 0)
                    live_cells++;
    } else {
        for(short c = -1; c < 2; c++) {
            for(short i = -1; i < 2; i++) {
                char checked_x = c+x;
                char checked_y = i+y;
                if(checked_x == -1) checked_x = 99;
                if(checked_y== -1) checked_y = 99;
                if(checked_x == 100) checked_x = 0;
                if(checked_y == 100) checked_y = 0;

                if(field[checked_x][checked_y] != 0)
                        live_cells++;
            }
        }
    }
    return live_cells;
}
