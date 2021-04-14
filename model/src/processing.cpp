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
    torch::jit::script::Module module;
    try{
        module = torch::jit::load(argv[1]);
    }
    catch (const c10::Error& e){
        std::cerr << "error loading the model\n";
        return -1;
    }
    std::cout << "ok" << std::endl;
    std::vector<torch::jit::IValue> inputs;
    auto input_tensor = torch::ones({1,3,416,416});
    inputs.push_back(input_tensor);
    auto out = module.forward(inputs);
    std::cout << out << std::endl;
    return 0;
}
