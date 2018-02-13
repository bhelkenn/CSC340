#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void rootMenu();
int userSelectionInput();
int userSelectionValidation(int&);
void selectionFlowControl(const int&);
string userFilenameInput();
string userCategoryInput();
void displayFileContents(const string&);
bool fileExists(const string&);
void writeToFile(const string&, const string&);

const int READ_FILE = 1;
const int WRITE_TO_FILE = 2;
const int EXIT_PROGRAM = 0;

int main() {
  rootMenu();
  
  return 0;
}

void rootMenu() {
  cout << "\nSELECT AN OPTION:" << endl;
  cout << "1. Read from File" << endl;
  cout << "2. Write to a File" << endl;
  cout << "0. EXIT" << endl;
  
  selectionFlowControl(userSelectionInput());
}

int userSelectionInput() {
  int selection = 0;
  cin >> selection;
  
  selection = userSelectionValidation(selection);
  
  return selection;
}

int userSelectionValidation(int& selection) {
  while (selection < EXIT_PROGRAM || selection > WRITE_TO_FILE) {
    cout << "INCORRECT VALUE!" << endl;
    cout << "Try again: ";
    cin >> selection;
  }
  
  return selection;
}

void selectionFlowControl(const int& selection) {
  switch (selection) {
    case EXIT_PROGRAM:
      exit(EXIT_PROGRAM);
      break;
    case READ_FILE:
      displayFileContents(userFilenameInput());
      break;
    case WRITE_TO_FILE:
      writeToFile(userFilenameInput(), userCategoryInput());
      break;
    default:
      exit(-1); //something clearly went wrong in flow control if this executes
  }
  
  rootMenu();
}

string userFilenameInput() {
  int month, year;
  cout << "Enter month then year: ";
  cin >> month >> year;
  
  string fileName = to_string(year) + '_' + to_string(month);
  
  return fileName;
}

void displayFileContents(const string& fileName) {
  fstream file;
  if (fileExists(fileName)) {
    file.open(fileName);
    cout << "------ FILE " << fileName << " BEGIN ------";
    while (!file.eof()) {
      string line;
      getline(file, line);
      cout << line << endl;
    }
    cout << "------- FILE " << fileName << " END -------" << endl;
    file.close();
  }
  else {
    cout << "File " << fileName << " failed to open." << endl;
  }
}

string userCategoryInput() {
  cout << "Enter a category and a value: ";
  string category;
  double value;
  cin >> category >> value;
  
  string inputInfo = category + ' ' + to_string(value);
  return inputInfo;
}

bool fileExists(const string& fileName) {
  fstream file(fileName);
  return file.good();
}

void writeToFile(const string& fileName, const string& inputInfo) {
  fstream file;
  file.open(fileName, ios::out | ios::app);
  file << '\n' << inputInfo;
  
  file.close();
}
