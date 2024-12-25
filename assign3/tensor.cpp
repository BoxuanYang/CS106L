#include <iostream>
#include <vector>
#include <cassert>

template<typename T>
tensor::tensor(std::vector<int> shape, type::backend_type backend){
    // Check all elem in shape >= 0
    this->size = 1;
    for(int i = 0; i < shape.size(); i++){
        if(shape[i] < 0){
            std::cout << " Shape must be non-zero!" << std::endl;
            return;
        }
        this->size *= shape[i];
    }

    this->shape = copy(shape);
    this->backend = backend;

    T* buffer;

    // TODO: Implement this wrapper function for memory allocation
    mem_alloc(buffer, this->backend, this->size);
}


int64_t tensor::size(){
    return this->size;
}

      
std::vector<int> tensor::get_shape(){
    return this->shape;
}

bool tensor::on_gpu(){
    return this->backend == type::backend_type::GPU;
}

template<typename T>
T tensor::get_data(std::vector<int> index){
    assert(index >= 0 && index < this->size);

    return this->buffer[index];
}


template<typename T>      
void tensor::set_data(std::vector<int> index, T data){
    this->buffer[index] = data;
}


// Initialize everything in buffer to be 0      
void tensor::init_data(){
    for(int i = 0; i < this->size; i++){
        this->buffer[i] = 0;
    }
}

void mem_alloc()