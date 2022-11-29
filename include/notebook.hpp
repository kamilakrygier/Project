#ifndef NOTEBOOK_HPP
#define NOTEBOOK_HPP

class YourChoices
{
  public:
    void choices();

};

class Notebook
{
  private:
    int choose_;
    std::string name_;
    std::string note_;
    std::string listOfFiles_;
    int result_;
    int modifications_;
    std::string filename_;
    std::string line_;
    std::string deleteline_;
    std::fstream myFile;
  public:
    Notebook(int choose);
    void menu();
    void actions();  
};

class Checklist
{
  private:
    std::vector <std::string> toDoList_;
    int number_;
    std::string task_;
    std::string name_;
    std::string filename_;
    int element_;
  public:
    Checklist(std::vector <std::string> toDoList);
    void actions();
};
#endif