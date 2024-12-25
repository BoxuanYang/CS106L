#include <datatype.h>

template<typename T>
class tensor{
    public:
      // Constructor
      tensor(std::vector<int> shape, type::backend_type backend);

      // return the size of the tensor
      int64_t size();

      // return the shape of the tensor
      std::vector<int> get_shape();

      // return true if tensor is on GPU
      bool on_gpu();

      // return data given by index, index must be of length size
      T get_data(std::vector<int> index);

      // set data given by index, index must be of length size
      void set_data(std::vector<int> index, T data);

      // initialize everything to be 0
      void init_data();

    private:
      int64_t size = 0;
      type::backend_type backend;
      std::vector<int> shape;
      T* buffer;
}