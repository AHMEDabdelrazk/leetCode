class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        std::tuple<int, int, int> mods(0,0,0); 

        // Count stones by remainder modulo 3
        for (int x : stones) {
            //constexpr int r = x % 3;
            std::get<0>(mods) += x % 3 == 0, std::get<1>(mods) += x % 3 == 1, std::get<2>(mods) += x % 3 == 2;
        }

        // If the number of 0-mod-3 stones is even,
        // Alice needs at least one 1 and one 2.
        //////////// examble:
        // alice choose the 1 or 2 
        // so bob will forced to choose from from 0
        // then alice choose from 0 and the last 0 will be to alice
        // then bob will choose 2 and lose but what if bob choose 1 ????
        // => NOTE: when it's come to only 1s and 2s whoever start wins
        if (std::get<0>(mods) % 2 == 0) {
            return std::get<1>(mods) > 0 && std::get<2>(mods) > 0;
        }

        // If the number of 0-mod-3 stones is odd,
        // Alice wins only if the counts of 1 and 2
        // differ by more than 2.
        return abs(std::get<1>(mods) - std::get<2>(mods)) > 2;
    }
};