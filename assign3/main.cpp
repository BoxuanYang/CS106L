#include "class.h"
#include <vector>
// #include "datatype.h"

/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

/* #### Please don't change this line! #### */
int run_autograder();

int main() {
  // STUDENT TODO: Construct an instance of your class!
  std::vector<int> shape = {3, 5};
  type::backend_type backend = type::backend_type::CPU;

  tensor<int> my_tensor(shape, backend);

  my_tensor.init_data();

  for(int i = 0; i < my_tensor.get_size(); i++){
    printf("%d ", my_tensor.get_data(i));
  }



  /* #### Please don't change this line! #### */
  return run_autograder();
}

/* #### Please don't change this line! #### */
#include "utils.hpp"