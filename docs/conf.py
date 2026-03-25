import os
import sys
sys.path.insert(0, os.path.abspath('..'))

project = 'cum_ext_module'
copyright = '2026, Manh Hung LE'
author = 'Manh Hung LE'

extensions = [
    "sphinx.ext.autodoc",
    "sphinx.ext.intersphinx",
    "sphinx.ext.autosummary",
    "sphinx.ext.napoleon",
    "sphinx_rtd_theme",
]

html_theme = "sphinx_rtd_theme"