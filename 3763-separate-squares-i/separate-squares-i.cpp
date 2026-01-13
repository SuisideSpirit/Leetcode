class Solution {
public:
    int solve2(double y, double reqA, vector<vector<int>>& squares) {
        double area = 0.0;

        for (auto &s : squares) {
            double l = s[2];
            double Y = s[1];

            if (Y >= y) {
                area += l * l;
            } else if (Y + l > y) {
                area += l * (Y + l - y);
            }
        }

        const double EPS = 1e-7;
        if (fabs(area - reqA) < EPS) return 0;
        if (area > reqA) return 1;
        return -1;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double lower = 0.0, upper = 1e9;

        double Ra = 0.0;
        for (auto &s : squares) {
            double l = s[2];
            Ra += l * l;
        }
        Ra /= 2.0;

        while (upper - lower > 1e-6) {
            double mid = (lower + upper) / 2.0;
            int des = solve2(mid, Ra, squares);

            if (des <= 0)
                upper = mid;
            else
                lower = mid;
        }
        return lower;
    }
};
