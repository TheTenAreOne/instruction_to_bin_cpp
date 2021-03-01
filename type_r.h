#ifndef TYPE_R
#define TYPE_R

#include <string>
class Type_R{
    private:
        std::string opcode;
        std::string rs;
        std::string rt;
        std::string rd;
        std::string shamt;
        std::string funct;
    public:
        Type_R();
        Type_R( std::string full_inst ); //full_inst is full instruction ex: add $s1,$s2,$s3
        void convertir( std::string full_inst ); //Main function (all other functions all called from this one)
        void findRegister( std::string reg, int regId ); //Converts register into binary ex: $s1 = 10001 ; regId = 1 for rs, 2 for rt and 3 for rd
};

Type_R::Type_R(){
}

Type_R::Type_R( std::string full_inst ){
    convertir( full_inst );
    return;
}

void Type_R::convertir( std::string full_inst ){
    std::string inst;
    std::string rs;
    std::string rt;
    std::string rd;
    int stringIndex = 0;
    int fullInstIndex = 0;

    //Reads the instruction ex add
    //It will stop if the next char is $ or an space
    while( full_inst[ fullInstIndex ] != '$' && full_inst[ fullInstIndex ] != ' ' ){
        inst += full_inst[ fullInstIndex++ ];
    }
    //If the instruction has spaces, they will be deleted
    if( full_inst[ fullInstIndex ] == ' ' ){
        fullInstIndex++;
    }

    //Reads the first register (rd)
    //It will stop if the next char is $ or an space
    while( full_inst[ fullInstIndex ] != ',' && full_inst[ fullInstIndex ] != ' ' && full_inst[ fullInstIndex ] != '\0' && full_inst[ fullInstIndex ] != '\n'){
        rd += full_inst[ fullInstIndex++ ];
    }
    //If the instruction has spaces, they will be deleted
    while( full_inst[ fullInstIndex ] == ' ' || full_inst[ fullInstIndex ] == ',' ){
        fullInstIndex++;
    }

    //Reads the second register (rs)
    //It will stop if the next char is $ or an space
    while( full_inst[ fullInstIndex ] != ',' && full_inst[ fullInstIndex ] != ' ' && full_inst[ fullInstIndex ] != '\0' && full_inst[ fullInstIndex ] != '\n'){
        rs += full_inst[ fullInstIndex++ ];
    }
    //If the instruction has spaces, they will be deleted
    while( full_inst[ fullInstIndex ] == ' ' || full_inst[ fullInstIndex ] == ',' ){
        fullInstIndex++;
    }

    //Reads the third register (rt)
    //It will stop if the next char is $ or an space
    while( full_inst[ fullInstIndex ] != ',' && full_inst[ fullInstIndex ] != ' ' && full_inst[ fullInstIndex ] != '\0' && full_inst[ fullInstIndex ] != '\n' ){
        rt += full_inst[ fullInstIndex++ ];
    }

    this->opcode = "000000"; //All R types have opcode = 00000 (6 zeroes)

}

void Type_R::findRegister( std::string reg, int regId ){
    
    std::string binReg; //register in binary

    if( reg == "$zero" || "$0" ){
        
        binReg = "00000";       //0

    }else if( reg == "$at" ){

        binReg = "00001";       //1

    }else if( reg == "$v0" ){

        binReg = "00010";       //2

    }else if( reg == "$v1" ){

        binReg = "00011";       //3

    }else if( reg == "$a0" ){

        binReg = "00100";       //4

    }else if( reg == "$a1" ){

        binReg = "00101";       //5

    }else if( reg == "$a2" ){

        binReg = "00110";       //6

    }else if( reg == "$a3" ){

        binReg = "00111";       //7

    }else if( reg == "$t0" ){

        binReg = "01000";       //8

    }else if( reg == "$t1" ){

        binReg = "01001";       //9

    }else if( reg == "$t2" ){

        binReg = "01010";       //10

    }else if( reg == "$t3" ){

        binReg = "01011";       //11

    }else if( reg == "$t4" ){

        binReg = "01100";       //12

    }else if( reg == "$t5" ){

        binReg = "01101";       //13

    }else if( reg == "$t6" ){

        binReg = "01110";       //14

    }else if( reg == "$t7" ){

        binReg = "01111";       //15

    }else if( reg == "$s0" ){

        binReg = "10000";       //16

    }else if( reg == "$s1" ){

        binReg = "10001";       //17

    }else if( reg == "$s2" ){

        binReg = "10010";       //18

    }else if( reg == "$s3" ){

        binReg = "10011";       //19

    }else if( reg == "$s4" ){

        binReg = "10100";       //20

    }else if( reg == "$s5" ){

        binReg = "10101";       //21

    }else if( reg == "$s6" ){

        binReg = "10110";       //22

    }else if( reg == "$s7" ){

        binReg = "10111";       //23

    }else if( reg == "$t8" ){

        binReg = "11000";       //24

    }else if( reg == "$t9" ){

        binReg = "11001";       //25

    }else if( reg == "$k0" ){

        binReg = "11010";       //26

    }else if( reg == "$k1" ){

        binReg = "11011";       //27

    }else if( reg == "$gp" ){

        binReg = "11100";       //28

    }else if( reg == "$sp" ){

        binReg = "11101";       //29

    }else if( reg == "$fp" ){

        binReg = "11110";       //30

    }else if( reg == "$ra" ){

        binReg = "11111";       //31

    }

    if( regId == 1 ){
        this->rs = binReg;
    }else if( regId == 2 ){
        this->rt = binReg;
    }else{
        this->rd = binReg;
    }

    return;
}

#endif

