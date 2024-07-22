#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Function to reverse the contents of a file and store it in a new file
void reverseFileContent(const std::string &inputFileName, const std::string &outputFileName) {
    
    // Open the input and output files
    std::ifstream inFile(inputFileName);
    std::ofstream outFile(outputFileName);

    // Checking if the files were opened successfully
    if (!inFile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }

    if (!outFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }

    // Reading input file content into a string
    std::string fileContent((std::istreambuf_iterator<char>(inFile)),
                             std::istreambuf_iterator<char>());

    // Reversing file content
    std::reverse(fileContent.begin(), fileContent.end());

    // Writing the reversed content to the output file
    outFile << fileContent;

    // Closing both files
    inFile.close();
    outFile.close();

    // Success message
    std::cout << "File content successfully reversed and stored in " << outputFileName << std::endl;
}

int main() {
    std::string userInput;
    std::ofstream outFile;

    // Opening file in append mode
    outFile.open("CSC450_CT5_mod5.txt", std::ios_base::app);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    // Prompting user to enter data
    std::cout << "Enter the data you want to append to the file: ";
    std::getline(std::cin, userInput);

    // Writing user input to the file
    outFile << userInput << std::endl;

    // Closing the file
    outFile.close();

    // Success message
    std::cout << "Data successfully appended to CSC450_CT5_mod5.txt" << std::endl;

    // Calling reverse file function
    reverseFileContent("CSC450_CT5_mod5.txt", "CSC450-mod5-reverse.txt");

    return 0;
}
