
#include <pybind11/pybind11.h>
#include <iostream>

namespace py = pybind11;
using namespace py::literals;

PYBIND11_MODULE(pylsexpr, m)
{
    m.def("print", [](){ std::cout << "hello pylsexpr\n"; });
}
