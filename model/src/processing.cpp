//
// Created by lordmoskalt on 4/13/21.
//
#include <vector>
#include <string>
#include <iostream>
#include "torch/torch.h"
#include "torch/script.h"
#include <memory>
#include "cmath"
#include "ctime"


#define BUFF_SIZE 307200

std::vector<std::string> predict(char* buffer);


int main(int argc, const char* argv[]){
    if(argc !=2){
        std::cerr << "usage: processing <path-to-exported-script-model>\n";
        return -1;
    }
    srand(time(NULL));
    torch::Tensor a;
    char* array = new char[BUFF_SIZE];
    for(size_t i = 0; i < BUFF_SIZE; i++){
        array[i] = (char)rand()%90 + 10;
    }
    int64_t* int_array = new int64_t[BUFF_SIZE];
    for(size_t i = 0; i < BUFF_SIZE; ++i){
        int_array[i] = (int64_t)array[i];
    }
    auto options = torch::TensorOptions().dtype(torch::kFloat64);
    torch::Tensor tharray = torch::from_blob(int_array, {1,1,416,416}, options);
    torch::jit::script::Module module;
    try{
        module = torch::jit::load(argv[1]);
    }
    catch (const c10::Error& e){
        std::cerr << "error loading the model\n";
        return -1;
    }
    std::cout << "ok" << std::endl;
    return 0;
}
