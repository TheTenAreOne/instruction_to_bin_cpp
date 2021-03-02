#include "Syntax_Verifier.h"
#include <iostream>
Syntax_Verifier::Syntax_Verifier( ){
    inst_type_index = 0;
}

bool Syntax_Verifier::verify( std::string full_inst ){

    std::string inst;
    std::string rs;
    std::string rt;
    std::string rd;
    std::string immediate;
    std::string address;
    int fullInstIndex = 0;
    int i;

    //Reads the instruction ex add
    //It will stop if the next char is $ or an space
    while( full_inst[ fullInstIndex ] != '$' && full_inst[ fullInstIndex ] != ' ' ){
        inst += full_inst[ fullInstIndex++ ];
    }
    //If the instruction has spaces, they will be deleted
    if( full_inst[ fullInstIndex ] == ' ' ){
        fullInstIndex++;
    }

    if( verifyInst( inst ) == false ){
        return false;
    }

    if( inst_type[ inst_type_index ] == 1 ){
        //Reads the first register (rd)
        //It will stop if the next char is $ or an space
        while( full_inst[ fullInstIndex ] != ',' && full_inst[ fullInstIndex ] != ' ' && full_inst[ fullInstIndex ] != '\0' && full_inst[ fullInstIndex ] != '\n'){
            rd += full_inst[ fullInstIndex++ ];
        }
        //If the instruction has spaces, they will be deleted
        while( full_inst[ fullInstIndex ] == ' '){
            fullInstIndex++; //add $s1,$s2  ,$s3
        }

        //If comma not found after register, invalid syntax ex: add $s1  $s2,$s3
        if( full_inst[ fullInstIndex ] != ',' ){
            return false;
        }
        fullInstIndex++;

        //If the instruction has spaces, they will be deleted
        while( full_inst[ fullInstIndex ] == ' '){
            fullInstIndex++; //add $s1,$s2  ,$s3
        }

        //Reads the second register (rs)
        //It will stop if the next char is $ or an space
        while( full_inst[ fullInstIndex ] != ',' && full_inst[ fullInstIndex ] != ' ' && full_inst[ fullInstIndex ] != '\0' && full_inst[ fullInstIndex ] != '\n'){
            rs += full_inst[ fullInstIndex++ ];
        }
        //If the instruction has spaces, they will be deleted
        while( full_inst[ fullInstIndex ] == ' '){
            fullInstIndex++;
        }

        //If comma not found after register, invalid syntax
        if( full_inst[ fullInstIndex ] != ',' ){
            return false;
        }
        fullInstIndex++;
        
        //If the instruction has spaces, they will be deleted
        while( full_inst[ fullInstIndex ] == ' '){
            fullInstIndex++; //add $s1,$s2  ,$s3
        }

        //Reads the third register (rt)
        //It will stop if the next char is $ or an space
        while( full_inst[ fullInstIndex ] != ',' && full_inst[ fullInstIndex ] != ' ' && full_inst[ fullInstIndex ] != '\0' && full_inst[ fullInstIndex ] != '\n' ){
            rt += full_inst[ fullInstIndex++ ];
        }
    }else if( inst_type[ inst_type_index ] == 2 ){
        //Reads the first register (rt)
        //It will stop if the next char is $ or an space
        while( full_inst[ fullInstIndex ] != ',' && full_inst[ fullInstIndex ] != ' ' && full_inst[ fullInstIndex ] != '\0' && full_inst[ fullInstIndex ] != '\n'){
            rt += full_inst[ fullInstIndex++ ];
        }
        //If the instruction has spaces, they will be deleted
        while( full_inst[ fullInstIndex ] == ' ' ){
            fullInstIndex++;
        }

        //If comma not found after register, invalid syntax
        if( full_inst[ fullInstIndex ] != ',' ){
            return false;
        }
        fullInstIndex++;
        //If the instruction has spaces, they will be deleted
        while( full_inst[ fullInstIndex ] == ' ' ){
            fullInstIndex++;
        }
        //Reads the second register (rs)
        //It will stop if the next char is $ or an space
        while( full_inst[ fullInstIndex ] != ',' && full_inst[ fullInstIndex ] != ' ' && full_inst[ fullInstIndex ] != '\0' && full_inst[ fullInstIndex ] != '\n'){
            rs += full_inst[ fullInstIndex++ ];
        }
        //If the instruction has spaces, they will be deleted
        while( full_inst[ fullInstIndex ] == ' ' ){
            fullInstIndex++;
        }

        //If comma not found after register, invalid syntax
        if( full_inst[ fullInstIndex ] != ',' ){
            return false;
        }
        fullInstIndex++;
        //If the instruction has spaces, they will be deleted
        while( full_inst[ fullInstIndex ] == ' ' ){
            fullInstIndex++;
        }
        //Reads the immediate
        //It will stop if the next char is $ or an space
        while( full_inst[ fullInstIndex ] != ',' && full_inst[ fullInstIndex ] != ' ' && full_inst[ fullInstIndex ] != '\0' && full_inst[ fullInstIndex ] != '\n' ){
            immediate += full_inst[ fullInstIndex++ ];
        }

        //If immediate is missing, invalid syntax
        if( immediate[ 0 ] == '\0' ){
            return false;
        }

        //If immediate has char different from numbers, invalid syntax
        i = 0;
        while( immediate[ i ] != '\0' && immediate[ i ] != '\n' ){
            if( immediate[ i ] != '0' && immediate[ i ] != '1' && immediate[ i ] != '2' && immediate[ i ] != '3' && immediate[ i ] != '4' && immediate[ i ] != '5' && immediate[ i ] != '6' && immediate[ i ] != '7' && immediate[ i ] != '8' && immediate[ i ] != '9' ){
                return false;
            }
            i++;
        }
        
    }else if( inst_type[ inst_type_index ] == 3 ){
        //Reads the address
        //It will stop if the next char is $ or an space
        while( full_inst[ fullInstIndex ] != ' ' && full_inst[ fullInstIndex ] != '\0' && full_inst[ fullInstIndex ] != '\n'){
            address += full_inst[ fullInstIndex++ ];
        }
        //If immediate has char different from numbers or x, invalid syntax
        i = 0;
        while( address[ i ] != '\0' && address[ i ] != '\n' ){
            if( address[ i ] != '0' && address[ i ] != '1' && address[ i ] != '2' && address[ i ] != '3' && address[ i ] != '4' && address[ i ] != '5' && address[ i ] != '6' && address[ i ] != '7' && address[ i ] != '8' && address[ i ] != '9' && address[ i ] != 'x' ){
                return false;
            }
            i++;
        }
    }
    inst_type_index++;
    return true;
}

bool Syntax_Verifier::verifyInst( std::string inst ){
    if( inst == "add" || inst == "addu" || inst == "and" || inst == "jr" || inst == "nor" || inst == "or" || inst == "slt" || inst == "sltu" || inst == "sll" || inst == "srl" || inst == "sub" || inst == "subu" || inst == "mfhi" || inst == "mflo" || inst == "mult" || inst == "multu" || inst == "sra"){
        this->inst_type[ inst_type_index ] = 1;
        return true;
    }else if( inst == "addi" || inst == "addiu" || inst == "andi" || inst == "beq" || inst == "bne" || inst == "lbu" || inst == "lhu" || inst == "ll" || inst == "lui" || inst == "lw" || inst == "ori" || inst == "slti" || inst == "sltiu" || inst == "sb" || inst == "sc" || inst == "sh" || inst == "sw" || inst == "lwc1" || inst == "ldc1" || inst == "swc1" || inst == "sdc1" ){
        this->inst_type[ inst_type_index ] = 2;
        return true;
    }else if( inst == "j" || inst == "jal" ){
        this->inst_type[ inst_type_index ] = 3;
        return true;
    }else{
        return false;
    }
}

int Syntax_Verifier::getInst_Type( int pos ){
    if( pos >= 0 && pos < inst_type_index ){
        return inst_type[ pos ];
    }
    return -1;
}