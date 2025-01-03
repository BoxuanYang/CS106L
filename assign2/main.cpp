/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

#include "utils.h"

std::string kYourName = "Boxuan Yang";
/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.

  std::set<std::string> applicants;

  std::ifstream file(filename);
  std::string line;
  while(std::getline(file, line)){
    applicants.insert(line);
  }

  file.close();
  return applicants;
  
}

/*
Helper function: Given a name of type std::string, return the initial of the name
*/
std::string get_initial(const std::string name){
  std::string initial = "";
  initial.push_back(name[0]);

  for(size_t i = 1; i < name.size(); i++){
    if(name[i - 1] == ' '){
      initial.push_back(name[i]);
      break;
    }
  }



  return initial;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> queue;

  std::string initial = get_initial(name);
  std::cout << "My intial: " << initial << std::endl;

  for(const auto &student : students){
    std::string student_initial = get_initial(student);

    //std::cout << "Student initial: " << student_initial << std::endl;

    if(student_initial == initial){
      queue.push(&student);
    }
  }



  return queue;
}



/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.

  if(matches.empty()){
    printf("NO STUDENT FOUND.\n");
    std::string strr = "NO MATCHES FOUND.";
    return strr;
  }

  const std::string *match = matches.front();

  matches.pop();
  return *match;
}

/* #### Please don't modify this call to the autograder! #### */
int main() { 
  return run_autograder(); 
}
