#include "Type_J.h"
Type_J::Type_J(){
}

Type_J::Type_J( std::string full_inst ){
    convertir( full_inst );
    return;
}

void Type_J::convertir( std::string full_inst ){
    std::string inst;
    std::string address;
    int fullInstIndex = 0;

    //Reads the instruction ex add
    //It will stop if the next char a space
    while( full_inst[ fullInstIndex ] != '$' && full_inst[ fullInstIndex ] != ' ' ){
        inst += full_inst[ fullInstIndex++ ];
    }
   //If the instruction has spaces, they will be deleted
    while( full_inst[ fullInstIndex ] == ' ' ){
        fullInstIndex++;
    }

    //Reads the address
    //It will stop if the next char is $ or an space
    while( full_inst[ fullInstIndex ] != ' ' && full_inst[ fullInstIndex ] != '\0' && full_inst[ fullInstIndex ] != '\n'){
        address += full_inst[ fullInstIndex++ ];
    }

    findOpcode( inst ); //Finds the opcode for the specific instruction
    convertAddress( address ); //Converts string address to binary
}

//Finds opcode for j or jal
void Type_J::findOpcode( std::string inst ){

    if( inst == "j" ){

        this->opcode = "000010";

    }else if( inst == "jal" ){

        this->opcode = "000011";

    }

    return;
}

void Type_J::convertAddress( std::string address ){
    int decAtIndex, index;
    std::string charAtIndex;
    index = 0;
    while( address[ index ] != 'x'){
        index++;
    }
    index++;
    while( address[ index ] != ' ' && address[ index ] != '\0' && address[ index ] != '\n' ){
        charAtIndex = address[ index ];
        decAtIndex = std::stoi( charAtIndex );
        this->address += std::bitset<4>( decAtIndex ).to_string();
        index++;
    }

    return;
}

//========== Getters =========================================

std::string Type_J::getOpcode( ){
    return this->opcode;
}

std::string Type_J::getAddress( ){
    return this->address;
}