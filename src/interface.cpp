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
    m.doc() = "Module d'extension C++ pour calculs statistiques cumulatifs.";

    m.def("cum_médiane", &interface_cum_médiane, R"pbdoc(
    Calcule la médiane cumulative d'un tableau NumPy.

    L'algorithme utilise un ensemble trié pour maintenir les valeurs et 
    calculer la médiane à chaque nouvelle insertion.

    Parameters
    ----------
    numpy_array_de_doubles : numpy.ndarray
        Un tableau 1D de type float64 contenant les données d'entrée dont les valeurs du tableau doivent être uniques.

    Returns
    -------
    numpy.ndarray
        Un tableau de type float64 contenant la médiane calculée 
        à chaque étape.

    Raises
    ------
    RuntimeError
        Si le tableau contient des données répétées (doublons).

    Examples
    --------
    >>> import cum_ext_module
    >>> import numpy as np
    >>> data = np.array([2.0, 3.0, 0.0, 1.0, 5.0])
    >>> cum_ext_module.cum_médiane(data)
    array([2.0, 2.5, 2.0, 1.5, 2.0])
    )pbdoc");
}

