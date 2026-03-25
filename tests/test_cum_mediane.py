"""
Tests unitaires pour le module cum_ext_module.
Ce module contient les tests de validation pour le calcul de la médiane 
cumulative implémenté en C++.
"""
import numpy as np
import pytest
import cum_ext_module

def test_erreurs_données_répétées():
    """Vérifie la gestion des erreurs pour les données dupliquées.

    S'assure que l'extension C++ détecte les doublons et lève 
    l'exception appropriée.

    Raises
    ------
    RuntimeError
        Si des données répétées sont détectées (attendu ici).
    """

    data = np.array([1.0, 2.0, 2.0, 3.0], dtype=np.float64)
    with pytest.raises(RuntimeError, match="Duplicate data detected!"):
        cum_ext_module.cum_médiane(data)

def test_tableau_vide():
    """
    Vérifie la validation de la taille du tableau d'entrée.

    S'assure que l'interface lève une erreur explicite lorsqu'un tableau 
    vide est fourni. Un tableau vide n'a pas de médiane.

    Raises
    ------
    ValueError
        Si le tableau fourni a une taille de zéro.
    """
    data = np.array([], dtype=np.float64)
    with pytest.raises(ValueError, match="Le tableau d'entrée ne peut pas être vide."):
        cum_ext_module.cum_médiane(data)


def test_données():
    """Vérifie le calcul de la médiane cumulative

    Teste le module avec le jeu de données de référence vu en cours ([2, 3, 0, 1, 5])
    pour confirmer que les résultats correspondent aux valeurs théoriques.

    Returns
    -------
    None
        La fonction lève une AssertionError via NumPy si le test échoue.
    
    """
    
    data = np.array([2.0, 3.0, 0.0, 1.0, 5.0], dtype=np.float64)

    sortie_attendue = np.array([2.0, 2.5, 2.0, 1.5, 2.0], dtype=np.float64)

    résultat = cum_ext_module.cum_médiane(data)

    np.testing.assert_array_equal(résultat, sortie_attendue) 
