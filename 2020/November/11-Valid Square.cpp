class Solution {
    public:
    int square_distance(vector<int>& a, vector<int>& b) {

        int x = a[0] - b[0], y = a[1] - b[1];

        return x * x + y * y;

    }

    bool valid_triangle(vector<int>& p1, vector<int>& p2, vector<int>& p3) {

        vector<int> v = { square_distance(p1, p2), square_distance(p1, p3), square_distance(p3, p2) };

        sort(v.begin(), v.end());

        return v[0] && v[0] == v[1] && v[0] + v[1] == v[2];
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

        return valid_triangle(p1, p2, p3) && valid_triangle(p4, p2, p3) && valid_triangle(p1, p2, p4);
    }

};
