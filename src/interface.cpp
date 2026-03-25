#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include "cum_médiane.h"

namespace py = pybind11;

py::array_t<double> interface_cum_médiane(py::array_t<double> numpy_array_de_doubles) {

    py::buffer_info buf = numpy_array_de_doubles.request();

    auto result = py::array_t<double>(buf.size);
    py::buffer_info res_buf = result.request();

    double *donnees_ptr = static_cast<double *>(buf.ptr);
    double *sortie_ptr = static_cast<double *>(res_buf.ptr);
    int taille = static_cast<int> (buf.size);

    int status = cum_médiane(donnees_ptr, taille, sortie_ptr);

    if (status == ERROR_DONNÉES_RÉPÉTÉES) {
        throw std::runtime_error("Duplicate data detected!");
    }

    return result;

  }

PYBIND11_MODULE(cum_ext_module, m, py::mod_gil_not_used()) {
    m.def("cum_médiane", &interface_cum_médiane, "Calcule la médiane cumulative!");
}
