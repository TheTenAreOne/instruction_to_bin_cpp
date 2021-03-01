#ifndef TYPE_I
#define TYPE_I
#include <string>

class Type_I{
    private:
        std::string opcode;
        std::string rs;
        std::string rt;
        std::string immediate;
    public:
        Type_I();
        Type_I( std::string full_inst ); //full_inst is full instruction, ex: addi $s1,$0,4
        void convertir( std::string full_inst ); //Main function (all other functions all called from this one)
        void findRegister( std::string reg, int regId ); //Converts register into binary ex: $s1 = 10001 ; regId = 1 for rs and 2 for rt
        void findOpcode( std::string inst ); //Finds the opcode for a specific instruction
        void decToBinary( int dec ); //Converts the decimal to binary recursively
        //Getters
        std::string getOpcode( );
        std::string getRs( );
        std::string getRt( );
        std::string getImmediate( );
};

Type_I::Type_I(){
}

Type_I::Type_I( std::string full_inst ){
    convertir( full_inst );
    return;
}


void Type_I::convertir( std::string full_inst ){
    std::string inst;
    std::string rs;
    std::string rt;
    std::string immediate;
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

    //Reads the first register (rt)
    //It will stop if the next char is $ or an space
    while( full_inst[ fullInstIndex ] != ',' && full_inst[ fullInstIndex ] != ' ' && full_inst[ fullInstIndex ] != '\0' && full_inst[ fullInstIndex ] != '\n'){
        rt += full_inst[ fullInstIndex++ ];
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

    //Reads the immediate
    //It will stop if the next char is $ or an space
    while( full_inst[ fullInstIndex ] != ',' && full_inst[ fullInstIndex ] != ' ' && full_inst[ fullInstIndex ] != '\0' && full_inst[ fullInstIndex ] != '\n' ){
        immediate += full_inst[ fullInstIndex++ ];
    } 

    //gives this->rs a binary value
    findRegister( rs, 1 );
    //gives this->rt a binary value
    findRegister( rt, 2 );

    findOpcode( inst );
}


void Type_I::findRegister( std::string reg, int regId ){
    
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
    }else{
        this->rt = binReg;
    }
    return;
}

void Type_I::findOpcode( std::string inst ){
 
    if( inst == "addi" ){

        this->opcode = "001000";

    }else if( inst == "addiu" ){
        
        this->opcode = "001001";

    }else if( inst == "andi" ){
        
        this->opcode = "001100";

    }else if( inst == "beq" ){
        
        this->opcode = "000100";

    }else if( inst == "bne" ){
        
        this->opcode = "000101";

    }else if( inst == "lbu" ){
        
        this->opcode = "100100";

    }else if( inst == "lhu" ){
        
        this->opcode = "100101";

    }else if( inst == "ll" ){
        
        this->opcode = "110000";

    }else if( inst == "lui" ){
        
        this->opcode = "001111";

    }else if( inst == "lw" ){
        
        this->opcode = "100011";

    }else if( inst == "ori" ){
        
        this->opcode = "001101";

    }else if( inst == "slti" ){
        
        this->opcode = "001010";

    }else if( inst == "sltiu" ){
        
        this->opcode = "001011";

    }else if( inst == "sb" ){
        
        this->opcode = "101000";

    }else if( inst == "sc" ){
        
        this->opcode = "111000";

    }else if( inst == "sh" ){
        
        this->opcode = "101001";

    }else if( inst == "sw" ){
        
        this->opcode = "101011";

    }else if( inst == "lwc1" ){
        
        this->opcode = "110001";

    }else if( inst == "ldc1" ){
        
        this->opcode = "110101";

    }else if( inst == "swc1" ){
        
        this->opcode = "111001";

    }else if( inst == "sdc1" ){
        
        this->opcode = "111101";

    }

    return;
}

void Type_I::decToBinary( int dec ){
    if( dec / 2 != 0 ){
        decToBinary( dec / 2 );
    }
    this->immediate += dec % 2;
    return;
}


//========== Getters =========================================

std::string Type_I::getOpcode( ){
    return this->opcode;
}

std::string Type_I::getRs( ){
    return this->rs;
}

std::string Type_I::getRt( ){
    return this->rt;
}

std::string Type_I::getImmediate( ){
    return this->immediate;
}

#endif