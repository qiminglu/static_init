
#include <pybind11/pybind11.h>

#include "lsexpr.h"

namespace py = pybind11;
using namespace py::literals;

PYBIND11_MODULE(pylsexpr, m)
{
    m.def("print", print);
}
