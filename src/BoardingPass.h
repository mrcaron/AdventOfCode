#pragma once

namespace AdventOfCode2020
{
    class BoardingPass
    {
    private:
        /* data */
    public:
        BoardingPass(std::string);
        ~BoardingPass();

        int Row();
        int Column();
        int SeatId();
    };    
}