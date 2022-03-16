#include <pybind11/embed.h> // everything needed for embedding
#include <iostream>
namespace py = pybind11;
using namespace std;

int main() {
    py::scoped_interpreter guard{}; // start the interpreter and keep it alive

    cout << "Pybind Version: " << "v2.9.1" << endl;

    py::exec("import torch;"
             "import platform;"
             "print ('Python Version: ' + platform.python_version());"
             "print ('Torch Version: ' + torch.__version__);"
             "");

}