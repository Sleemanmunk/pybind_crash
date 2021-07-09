#include <pybind11/embed.h> // everything needed for embedding
#include <iostream>
namespace py = pybind11;
using namespace std;

int main() {
    py::scoped_interpreter guard{}; // start the interpreter and keep it alive

    py::print("Hello, World!"); // use the Python API

    py::module_ hello= py::module_::import("hello");
    hello.attr("hello")();

    cout << "The program has completed successfully" << endl;
    exit(0);
}