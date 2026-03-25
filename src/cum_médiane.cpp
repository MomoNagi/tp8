#include <set>
#include <iterator>
#include "cum_médiane.h"

int cum_médiane
(const double* donnees_ptr, const int taille, double* sortie_ptr){
    std::set<double> unique_values;
    for (int idx = 0; idx < taille; ++idx){
        double value = donnees_ptr[idx];

        if (unique_values.find(value) != unique_values.end()) {
            return ERROR_DONNÉES_RÉPÉTÉES;
        }
        
        unique_values.insert(value);

        int n = unique_values.size();
        std::set<double>::iterator iterator = unique_values.begin();

        if (n % 2 == 1){
            // Comme n est impair, alors la médiane est l'élément au milieu
            std::advance(iterator, n / 2);
            sortie_ptr[idx] = *iterator;
        }
        else{
            // Cela veut dire que n est pair, la médiane est donc la moyenne des deux éléments au milieu
            std::advance(iterator, (n / 2) - 1);
            double val1 = *iterator; // on récupère la valeur inférieure
            std::advance(iterator, 1);
            double val2 = *iterator; // on récupère la valeur supérieure
            sortie_ptr[idx] = (val1 + val2) / 2.0;
        }
    }   
    return SUCCESS;
}