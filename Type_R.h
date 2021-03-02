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
        void findFunct( std::string inst ); //Finds the funct value for the specific instruction
        //Getters
        std::string getOpcode( );
        std::string getRs( );
        std::string getRt( );
        std::string getRd( );
        std::string getShamt( );
        std::string getFunct( );
};

#endif

