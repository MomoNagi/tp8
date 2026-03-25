from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

ext_modules = [
    Pybind11Extension(
        "cum_ext_module",
        ["src/interface.cpp","src/cum_médiane.cpp"]
    ),
]

setup(
    name="cum_ext_module",
    author="Manh Hung Le",
    author_email="manh.hung.le@usherbrooke.ca",
    description="TP8",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
    python_requires=">=3.9",
)
