#ifndef TYPE_I
#define TYPE_I
#include <string>
#include <bitset>

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

#endif