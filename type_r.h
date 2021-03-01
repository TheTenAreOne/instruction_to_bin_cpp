#ifndef TYPE_R
#define TYPE_R
#include <string>
#include <iostream>
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
        void findFunct( std::string inst ); //Finds the funct value for the specific instruction
        //Getters
        std::string getOpcode( );
        std::string getRs( );
        std::string getRt( );
        std::string getRd( );
        std::string getShamt( );
        std::string getFunct( );
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

    //gives this->rs a binary value
    findRegister( rs, 1 );
    //gives this->rt a binary value
    findRegister( rt, 2 );
    //gives this->rd a binary value
    findRegister( rd, 3 );



    //In sll, srl and sra, rt is the shamdt
    //Also in sll, srl and sra, rt and rd are = 00000
    //Note that rs,rt and rd are different from the mips ref data
    if( inst == "sll" || inst == "srl" || inst == "sra" ){
        this->shamt = rt;
        this->rt = "00000";
        this->rd = "00000";
    }else{
        this->shamt = "000000";
    }

    findFunct( inst );
}

void Type_R::findRegister( std::string reg, int regId ){
    
    std::string binReg; //register in binary

    if( reg == "$zero" || reg == "$0" ){
        
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

void Type_R::findFunct( std::string inst ){
    
    if( inst == "add" ){

        this->funct = "100000";

    }else if( inst == "addu" ){

        this->funct = "100001";

    }else if( inst == "and" ){

        this->funct = "100100";
        
    }else if( inst == "jr" ){

        this->funct = "001000";
        
    }else if( inst == "nor" ){

        this->funct = "100111";
        
    }else if( inst == "or" ){

        this->funct = "100101";
        
    }else if( inst == "slt" ){

        this->funct = "101010";
        
    }else if( inst == "sltu" ){

        this->funct = "101011";
        
    }else if( inst == "sll" ){

        this->funct = "000000";
        
    }else if( inst == "srl" ){

        this->funct = "000010";
        
    }else if( inst == "sub" ){

        this->funct = "100010";
        
    }else if( inst == "subu" ){

        this->funct = "100011";
        
    }else if( inst == "mfhi" ){

        this->funct = "010000";
        
    }else if( inst == "mflo" ){

        this->funct = "010010";
        
    }else if( inst == "mfc0" ){

        this->funct = "000000";
        
    }else if( inst == "mult" ){

        this->funct = "011000";
        
    }else if( inst == "multu" ){

        this->funct = "011001";
        
    }else if( inst == "sra" ){

        this->funct = "000011";
        
    }

    return;
}

//========== Getters =========================================

std::string Type_R::getOpcode( ){
    return this->opcode;
}

std::string Type_R::getRs( ){
    return this->rs;
}

std::string Type_R::getRt( ){
    return this->rt;
}

std::string Type_R::getRd( ){
    return this->rd;
}

std::string Type_R::getShamt( ){
    return this->shamt;
}

std::string Type_R::getFunct( ){
    return this->funct;
}


#endif

