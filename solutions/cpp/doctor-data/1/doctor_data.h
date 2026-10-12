#include <string>

namespace star_map {
    enum class System{
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}

namespace heaven {
    class Vessel {
        public:
            Vessel(std::string name, int generation, star_map::System system = star_map::System::Sol);

            Vessel replicate(std::string new_name);

            void make_buster();

            bool shoot_buster();

            std::string name{};
            int generation {};
            int busters {};
            star_map::System current_system{};
    };
    
    std::string get_older_bob(const Vessel& vessel1, const Vessel& vessel2);

    bool in_the_same_system(const Vessel& vessel1, const Vessel& vessel2);
}