#ifndef SYNTAX_VERIFIER
#define SYNTAX_VERIFIER
#include <list>
#include <string>
const int MAX_INST_TYPE_SIZE = 500;

class Syntax_Verifier{
    private:
        int inst_type[ MAX_INST_TYPE_SIZE ];
        int inst_type_index = 0; //current list index
    public:
        Syntax_Verifier();//Full instruction to be verified, ex: add $s1,$s2,$s3
        bool verify( std::string full_inst ); //Main function (all other functions are called from this one)
        bool verifyInst( std::string inst ); //Checks if inst exists as a valid instruction and sets type // Returns true if valid, false otherwise
        //Getters
        int getInst_Type( int pos ); //Pos is the index for array inst_type
};

#endif