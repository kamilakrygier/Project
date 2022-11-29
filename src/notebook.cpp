#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include "notebook.hpp"

  void YourChoices::choices()
  {  
    std::cout << "MENU:" << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << "1 - add a new note" << std::endl;
    std::cout << "2 - view all your notes and modife them" << std::endl;
    std::cout << "3 - create and modife to-do-list" << std::endl;
    std::cout << "0 - exit notebook" << std::endl;
    std::cout << " " << std::endl;
  }

  Notebook::Notebook(int choose) : choose_(choose)
  {}

  void Notebook::menu()
  {
    std::cout << "These are your available operations: " << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "1 - You can read a note" << std::endl;
    std::cout << "2 - You can add something to a note" << std::endl;
    std::cout << "3 - You can remove a note" << std::endl;
    std::cout << "4 - You can remove one line from a note" << std::endl;
    std::cout << "0 - You can exit to menu" << std::endl;
  }

  void Notebook::actions()
  {
    switch(choose_)
    {    
      case 1:
      {
        
        std::cout << "Enter the name of the note: ";
        std::cin >> name_;

        filename_ += name_ + ".txt";
        
        std::ofstream myFile(filename_);

        std::cout << "Write your note: " << std::endl;

        std::cin.ignore();
        
        std::getline (std::cin, note_);
        
        myFile << note_ << "\n";
  
        myFile.close();

        if (!myFile)
        {
          std::cout << " " << std::endl;
          std::cout << "Note not created" << std::endl;
          std::cout << "You're going back to MENU" << std::endl;
        }
        else
        {
          std::cout << " " << std::endl;
          std::cout << "Note created successfully" << std::endl;
          std::cout << "You're going back to MENU" << std::endl;
        }
        break;
      }
       case 2:
       {
          std::cout << " " << std::endl;
          menu();
          std::cout << " " << std::endl;

          do
          {
            std::cout << "Press number You would like to enter: ";
            std::cin >> modifications_;
            std::cout << " " << std::endl;
            
            if (modifications_ == 0)
            {
              std::cout << "You're going back to menu" << std::endl;
              std::cout << " " << std::endl;
              break;
            }

            std::cout << "Enter the name of note You would like to modificate: ";
            std::cin >> name_;
            std::cout << " " << std::endl;
            filename_ = name_ + ".txt";
              
            if (modifications_ == 1)
            {
              myFile.open(filename_, std::ios::in);
              if (myFile.is_open())
              { 
                std::string temp; 
                while (getline(myFile, temp))
                {
                  std::cout << temp << '\n';
                }
                myFile.close();
                std::cout << " " << std::endl;
             
              }
            }
            
            else if (modifications_ == 2)
            {
              myFile.open(filename_, std::ios::app); 
              if(myFile.is_open())
              {
                std::cout << "Add text to your note: ";
                std::cin.ignore();
                std::getline (std::cin, note_);
                myFile << note_ << "\n";
                std::cout << "Note added" << std::endl;
                myFile.close();
              }
              std::cout << " " << std::endl;
              
            }
              
            else if (modifications_ == 3)
            {
              char const* f = filename_.c_str();
              result_ = std::remove(f);
 
              if (result_ != 0) 
              {
                std::cout << "Note deletion failed" << std::endl;
              }
              else 
              {
                std::cout << "Note deleted successfully" << std::endl;
              }
              std::cout << " " << std::endl;
            } 

            else if (modifications_ == 4)
            {
              myFile.open(filename_);
              std::ofstream temp;
              temp.open("temp.txt");
              
              std::cout << "Which line do you want to remove?" << std::endl;
              std::cin.ignore();
              std::getline(std::cin, deleteline_);

              while (getline(myFile, line_))
              {
                  if (line_ != deleteline_)
                  {
                    temp << line_ << std::endl;
                  }
              }
              
              temp.close();
              myFile.close();

              char const* f = filename_.c_str();
              std::remove(f);
              std::rename("temp.txt", f);
              
              std::cout << " " << std::endl;
              std::cout << "Line is removed" << std::endl;
              std::cout << " " << std::endl;
            }

            else
            {
              std::cout << "You choose wrong number, please try again or exit from notebook" << std::endl;
            }
          }
          while (modifications_ != 0);
         
      } 
    }
  }

  Checklist::Checklist(std::vector <std::string> toDoList) : toDoList_(toDoList)
  {}
  void menu()
  {
    std::cout << "Here are operations You can perform: " << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "1 - You can create your to-do-list"<< std::endl;
    std::cout << "2 - You can view all your tasks" << std::endl;
    std::cout << "3 - You can add task to your list" << std::endl;
    std::cout << "4 - You can remove done task from your list" << std::endl;
    std::cout << "5 - You can save your list as note" << std::endl;
    std::cout << "0 - You can exit to menu" << std::endl;
  }
  void Checklist::actions()
  {
    menu();
    std::cout << " " << std::endl;

    do
    {
      std::cout << "Press number You would like to enter: ";
      std::cin >> number_;
      std::cout << " " << std::endl;
      
      switch(number_)
      {
        case 1:
        {
            std::cout << "Enter a name from your to-do-list: ";
            std::cin >> name_;
            std::cout << " " << std::endl;

            int temp = 0;
          
            std::cout << "Enter how many tasks would You like to add: " << std::endl;
            std::cin >> temp;
            std::cout << " " << std::endl;
          
            for (int i = 0; i < temp; i++)
            {
              std::cout << "Enter your " << i+1 << " task: ";
              std::cin.ignore();
              std::getline(std::cin, task_);
              toDoList_.push_back(task_);
            }
            std::cout << " " << std::endl;
            break;
        }

        case 2:
        {
          std::cout << "To-Do-List:  " << name_ << "  " << std::endl;
          for (int i = 0; i < toDoList_.size(); i++)
          {
            std::cout << " " << std::endl;
            std::cout << i+1 << ": " << toDoList_[i] << std::endl;
          }
          std::cout << " " << std::endl;
          break;
        }

        case 3:
        {
          std::cout << "Enter how many new task would You like to add: ";
          int temp = 0;
          std::cin >> temp;
          std::cout << " " << std::endl;
          
          for (int i = 0; i < temp; i++)
            {
              std::cout << "Enter your " << i+1 << " new task: ";
              std::cin.ignore();
              std::getline(std::cin, task_);
              toDoList_.push_back(task_);
            }
            std::cout << " " << std::endl;
            break;
        }

        case 4:
        {
          std::cout << "Enter an elemeny You would like to remove from your list: ";
          std::cin >> element_;
          toDoList_.erase(toDoList_.begin() + (element_-1));
          std::cout << " " << std::endl;
          break;
        }

        case 5:
        {
          filename_ = name_ + ".txt";
          std::ofstream myFile(filename_);
          for (const auto& it : toDoList_) myFile << it << "\n";
          
          if (!myFile)
          {
            std::cout << "Note not created" << std::endl;
          }
          else
          {
            std::cout << "Note created successfully" << std::endl;
          }
          std::cout << " " << std::endl;
          break;
        }

        default:
        {
          if (number_ != 0)
          {
            std::cout << "Sorry, You choose the wrong number, pleaste try again" << std::endl;
            std::cout << " " << std::endl;
          }
        }
        
      }
    }
    while (number_ != 0);
    {
      std::cout << "You're going back to menu" << std::endl;
      std::cout << " " << std::endl;
    }
  }

int main()
{
  std::cout << "Welcome to your notebook!" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "Here you can add all your most important information - add notes and create checklist!" << std::endl;
  
  int choose;

  std::vector <std::string> toDoList;

  YourChoices yourChoices;

  do
  {
    std::cout << " " << std::endl;
    yourChoices.choices();
    
    std::cout << " " << std::endl;
    std::cout << "Press number You would like to enter: ";
    
    std::cin >> choose;
    std::cout << " " << std::endl;
  
     Notebook notebook = Notebook(choose);

    if(choose == 1 || choose == 2)
    {
      notebook.actions();
    }
    else if(choose == 3)
    {
      Checklist checklist = Checklist(toDoList);
      checklist.actions();
      
    }
    else if (choose != 0)
    {
      std::cout << "You entered the wrong number, try again" << std::endl;
    }
  }
  while (choose != 0);
  {
    std::cout << "Thank You for using notebook" << std::endl;
  }  
  return 0;
}