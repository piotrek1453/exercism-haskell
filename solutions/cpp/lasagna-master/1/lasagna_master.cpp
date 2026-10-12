#include "lasagna_master.h"
#include <algorithm>

namespace lasagna_master {

    int preparationTime(const std::vector<std::string>& layers, int avgPreparationTimePerLayer) {
        return avgPreparationTimePerLayer * layers.size();
    }

    amount quantities(const std::vector<std::string>& layers) {
        auto noodleLayersCount = std::count(layers.begin(), layers.end(), "noodles");
        auto noodleLayersSauce = std::count(layers.begin(), layers.end(), "sauce");
        amount result;
        result.noodles = noodleLayersCount * 50;
        result.sauce = noodleLayersSauce * 0.2;
        return result;
    }

    void addSecretIngredient(std::vector<std::string>& myRecipe, const std::vector<std::string>& friendsRecipe) {
        auto it = std::find(myRecipe.begin(), myRecipe.end(), "?");
        if(it != myRecipe.cend()) {
            *it = friendsRecipe.back();
        }
    }

    void addSecretIngredient(std::vector<std::string>& myRecipe, const std::string& secretIngredient) {
        auto it = std::find(myRecipe.begin(), myRecipe.end(), "?");
        if(it != myRecipe.end()) {
            *it = secretIngredient;
        }
    }

    std::vector<double> scaleRecipe(const std::vector<double>& quantities, int portions) {
        std::vector<double> scaledQuantities(quantities.size());

        std::transform(quantities.begin(),
                       quantities.end(),
                       scaledQuantities.begin(),
                       [portions](double q){ return q * (portions / 2.0); });
        
        return scaledQuantities;
    }

}  // namespace lasagna_master
