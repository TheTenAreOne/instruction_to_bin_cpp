#include "Type_R.h"
#include "Type_I.h"
#include "Type_J.h"
#include <iostream>
#include <string>

int main(){

    std::string inst = "jr $t1, $v0, $s3";
    std::string instI = "addi $s1, $0, 42";
    std::string instJ = "j 0x00400040";

    Type_R inst1( inst );
    Type_I inst2( instI );
    Type_J inst3( instJ );

    std::cout << inst1.getOpcode() << std::endl;
    std::cout << inst1.getRs() << std::endl;
    std::cout << inst1.getRt() << std::endl;
    std::cout << inst1.getRd() << std::endl;
    std::cout << inst1.getShamt() << std::endl;
    std::cout << inst1.getFunct() << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << inst2.getOpcode() << std::endl;
    std::cout << inst2.getRs() << std::endl;
    std::cout << inst2.getRt() << std::endl;
    std::cout << inst2.getImmediate() << std::endl;
    std::cout << "======================" << std::endl;
    std::cout << inst3.getOpcode() << std::endl;
    std::cout << inst3.getAddress() << std::endl;
    return 0;
}