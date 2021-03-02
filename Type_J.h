#ifndef TYPE_J
#define TYPE_J
#include <string>
#include <bitset>
const int end_address = 9;// 0x00400010, 8 after the x

class Type_J{
    private:
        std::string opcode;
        std::string address;

    public:
        Type_J();
        Type_J( std::string full_inst ); //full_inst is full instruction, ex: addi $s1,$0,4
        void convertir( std::string full_inst ); //Main function (all other functions all called from this one)
        void findOpcode( std::string inst ); //Finds the opcode for a specific instruction
        void convertAddress( std::string address ); //converts the hex address to binary

        //Getters
        std::string getOpcode();
        std::string getAddress();

};

#endif