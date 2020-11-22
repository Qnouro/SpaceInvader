#pragma once


class Grid{
    private:
        uint_fast8_t m_grid_cols;
        uint_fast8_t m_grid_lines;

    public:
        Grid(uint_fast8_t grid_cols, uint_fast8_t grid_lines);

        uint_fast8_t getCols();

        void setCols(uint_fast8_t grid_cols);

        uint_fast8_t getLines();

        void setLines(uint_fast8_t grid_lines);

        void draw();
};