#include <pybind11/embed.h> // everything needed for embedding
#include <iostream>
namespace py = pybind11;
using namespace std;

int main() {
    py::scoped_interpreter guard{}; // start the interpreter and keep it alive

    py::print("Hello, World!"); // use the Python API
    py::print(); // use the Python API

    //***
    //Load your desired module
    //***
    py::module_ hello= py::module_::import("hello");


    //***
    //Generate python variables holding your inputs
    //***
    py::list names;

    for (auto name:{"World", "Python", "C++"}){
        names.append(name);
    }

    //***
    //Run a function from your module
    //***
    hello.attr("hello")(names);

    cout << "The program has completed successfully" << endl;
    exit(0);
}