struct Convex_hull {
    using i64 = long long;
  private:
    struct Point {
        i64 x, y;
        Point(i64 x, i64 y) : x(x), y(y) {}
        bool operator<(const Point& p) const {
            return x != p.x ? x < p.x : y < p.y;
        }
        Point operator+(const Point& p) const {
            return Point(x + p.x, y + p.y);
        }
        Point operator-(const Point& p) const {
            return Point(x - p.x, y - p.y);
        }
        friend ostream& operator<<(ostream& os, const Point& p) {
            os << p.x << " " << p.y;
            return os;
        }
    };
    i64 cross(const Point& a, const Point& b) {
        return a.x * b.y - a.y * b.x;
    }
  public:
    vector<Point> ps, hull;

    void add_point(i64 x, i64 y) {
        ps.emplace_back(x, y);
    }

    void query() {
        int _n = size(ps);
        if (_n == 1) {
            hull = ps;
            return;
        }
        vector<Point> res = ps;
        sort(res.begin(), res.end());
        vector<Point> up, dw;
        up.emplace_back(res[0]); dw.emplace_back(res[0]);
        up.emplace_back(res[1]); dw.emplace_back(res[1]);
        for (int i = 2; i < _n; i++) {
            while (size(up) >= 2 && cross(up[size(up) - 1]
                   - up[size(up) - 2], res[i] - up[size(up) - 1]) >= 0) {
                up.pop_back();
            }
            while (size(dw) >= 2 && cross(dw[size(dw) - 1]
                   - dw[size(dw) - 2], res[i] - dw[size(dw) - 1]) <= 0) {
                dw.pop_back();
            }
            up.emplace_back(res[i]);
            dw.emplace_back(res[i]);
        }
        hull = up;
        for (int i = size(dw) - 2; i > 0; i--) {
            hull.emplace_back(dw[i]);
        }
    }
};
