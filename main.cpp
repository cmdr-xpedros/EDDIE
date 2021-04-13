/*********************************************
  EDDIE - Elite Dangerous Data Info Extractor
  Extracts readable data from ED journal files.
  CMDR XPEDROS, 04/2021
**********************************************/

#include "stdafx.h"
#include "EdJournalObject.h"

//using namespace std;

int main(int argc, char *argv[])
{
    // read a JSON file
    std::ifstream fInput(argv[1]);

    if(!fInput) {
        std::cout << "Cannot open input file.\n";
        return 1;
    }

    std::string lsLine;
    EdJournalObject jEdJournalLine;
    //Process all lines from a file
    while (std::getline(fInput, lsLine))
    {
        jEdJournalLine.Set(lsLine);
        // Access the values
        std::string sItem = jEdJournalLine.ReceiveText();

        // Print the values
        if(!sItem.empty())
            std::cout << sItem << std::endl;
    }
    return 0;
}
