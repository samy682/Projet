#ifndef DIRECTION_H
#define DIRECTION_H


class direction
{
    public:
        direction():d_x{1},d_y{0} {}
        direction(int x, int y):d_x{x},d_y{y} {}

        int x();
        int y();

        void inversion();// inversion de d_x avec d_y
        void inversionNegative();

        direction retournement();//inversion NORD/SUD et OUEST/EST

        bool operator==(const direction& dir);
        bool operator!=(const direction& dir);
    private:
        int d_x,d_y;

};

#endif
