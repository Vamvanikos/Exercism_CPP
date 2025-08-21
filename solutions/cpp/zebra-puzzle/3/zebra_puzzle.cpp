#include "zebra_puzzle.h"
#include <vector>
#include <algorithm>

namespace zebra_puzzle {

using namespace std;

Solution solve() {
    string water_drinker, zebra_owner;
    bool found = false;
    
    vector<string> colors = {"red", "green", "ivory", "yellow", "blue"};
    vector<string> nationalities = {"Englishman", "Spaniard", "Ukrainian", "Norwegian", "Japanese"};
    vector<string> pets = {"dog", "snail", "fox", "horse", "zebra"};
    vector<string> drinks = {"coffee", "tea", "milk", "orange juice", "water"};
    vector<string> hobbies = {"dancing", "painting", "reading", "football", "chess"};

    vector<int> idx = {0, 1, 2, 3, 4};

    do { // colors permutation
        // Constraint: Green immediately right of Ivory
        auto green_pos = find(colors.begin(), colors.end(), "green") - colors.begin();
        auto ivory_pos = find(colors.begin(), colors.end(), "ivory") - colors.begin();
        if (green_pos != ivory_pos + 1) continue;

        do { // nationalities permutation
            // Constraint: Norwegian lives in first house
            if (nationalities[0] != "Norwegian") continue;
            // Constraint: Englishman lives in red house
            auto red_pos = find(colors.begin(), colors.end(), "red") - colors.begin();
            auto eng_pos = find(nationalities.begin(), nationalities.end(), "Englishman") - nationalities.begin();
            if (red_pos != eng_pos) continue;

            // Constraint: Norwegian lives next to blue house
            auto blue_pos = find(colors.begin(), colors.end(), "blue") - colors.begin();
            if (abs(blue_pos - 0) != 1) continue;

            do { // drinks permutation
                // Constraint: Middle house drinks milk
                if (drinks[2] != "milk") continue;
                // Constraint: Ukrainian drinks tea
                auto ukr_pos = find(nationalities.begin(), nationalities.end(), "Ukrainian") - nationalities.begin();
                auto tea_pos = find(drinks.begin(), drinks.end(), "tea") - drinks.begin();
                if (ukr_pos != tea_pos) continue;
                // Constraint: Green house drinks coffee
                if (drinks[green_pos] != "coffee") continue;

                do { // pets permutation
                    // Constraint: Spaniard owns dog
                    auto span_pos = find(nationalities.begin(), nationalities.end(), "Spaniard") - nationalities.begin();
                    auto dog_pos = find(pets.begin(), pets.end(), "dog") - pets.begin();
                    if (span_pos != dog_pos) continue;

                    do { // hobbies permutation
                        // Constraint: Snail owner likes dancing
                        auto snail_pos = find(pets.begin(), pets.end(), "snail") - pets.begin();
                        auto dance_pos = find(hobbies.begin(), hobbies.end(), "dancing") - hobbies.begin();
                        if (snail_pos != dance_pos) continue;

                        // Constraint: Yellow house -> painting
                        auto yellow_pos = find(colors.begin(), colors.end(), "yellow") - colors.begin();
                        if (hobbies[yellow_pos] != "painting") continue;

                        // Constraint: Football hobby drinks orange juice
                        auto foot_pos = find(hobbies.begin(), hobbies.end(), "football") - hobbies.begin();
                        if (drinks[foot_pos] != "orange juice") continue;

                        // Constraint: Japanese plays chess
                        auto jap_pos = find(nationalities.begin(), nationalities.end(), "Japanese") - nationalities.begin();
                        auto chess_pos = find(hobbies.begin(), hobbies.end(), "chess") - hobbies.begin();
                        if (jap_pos != chess_pos) continue;

                        // Constraint: Reader lives next to fox owner
                        auto read_pos = find(hobbies.begin(), hobbies.end(), "reading") - hobbies.begin();
                        auto fox_pos = find(pets.begin(), pets.end(), "fox") - pets.begin();
                        if (abs(read_pos - fox_pos) != 1) continue;

                        // Constraint: Painter lives next to horse owner
                        auto paint_pos = find(hobbies.begin(), hobbies.end(), "painting") - hobbies.begin();
                        auto horse_pos = find(pets.begin(), pets.end(), "horse") - pets.begin();
                        if (abs(paint_pos - horse_pos) != 1) continue;

                        // All constraints satisfied!
                        for (int i = 0; i < 5; ++i) {
                            if (drinks[i] == "water") water_drinker = nationalities[i];
                            if (pets[i] == "zebra") zebra_owner = nationalities[i];
                        }
                        found = true;
                        break;

                    } while (next_permutation(hobbies.begin(), hobbies.end()));
                    if (found) break;
                } while (next_permutation(pets.begin(), pets.end()));
                if (found) break;
            } while (next_permutation(drinks.begin(), drinks.end()));
            if (found) break;
        } while (next_permutation(nationalities.begin(), nationalities.end()));
        if (found) break;
    } while (next_permutation(colors.begin(), colors.end()));

    return {water_drinker, zebra_owner};
}

} // namespace zebra_puzzle
