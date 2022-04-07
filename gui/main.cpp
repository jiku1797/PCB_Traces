#include <QApplication>

#include <iostream>
#include <string>

#include "MainWindow.h"

void printInstruction() 
{ 
   const std::string instr = "INSTRUCTION\n"
      "* Assign new points points to a trace by"
      " left-clicking at the desired position.\n"
      "* Only valid (i.e. non-crossing) points"
      " are accepted.\n"
      "* Finish a trace by right-clicking" 
      " anywhere within the canvas.";

   std::cout << instr << '\n';
}

int main(int argc, char* argv[]) 
{ 
   QApplication app{argc, argv};
   PCB_MainWindow mw;
   mw.show();

   printInstruction();

   return app.exec();   
}