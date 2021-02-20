#include <iostream>
#include <list>

// Note: 0 is open, 1 is wall, 2 is marked as visited.
bool DFS(int **ary, int w, int h, int cx, int cy, int ex, int ey) {
    // Setup the Base cases
    if (cx < 0 || cx >= w){ return false; } 
    if (cy < 0 || cy >= h){ return false; } 
    if (ary[cx][cy] == 2) { return false; }
    if (ary[cx][cy] == 1) { return false; }
    if (cx == ex && cy == ey) { return true; }

    // Now that cx and cy are valid and we may visit the current postion
    // 1. Mark the position
    ary[cx][cy] = 2;
    std::cout << "(" << cx << ", " << cy << ")\n";
    // 2. try going right
    if (DFS(ary, w, h, cx, cy + 1, ex, ey)) {
        return true;
    }
    // 3. try going down
    if (DFS(ary, w, h, cx + 1, cy, ex, ey)) {
        return true;
    }
    // 4. try going left
    if (DFS(ary, w, h, cx, cy - 1, ex, ey)) {
        return true;
    }
    // 5. try going up
    if (DFS(ary, w, h, cx - 1, cy, ex, ey)) {
        return true;
    }
    // 6. No solution found, return false;
    return false;
}

class Point {
    public:
        Point(int _x, int _y, int _steps) { x = _x; y = _y; steps = _steps;}
        int x, y, steps;
};

int BFS(int **ary, int w, int h, int sx, int sy, int ex, int ey) {
    std::list<Point> to_visit;
    to_visit.push_back(Point(sx, sy, 0));

    while (!to_visit.empty()) {
        // Get the next point in line (queue.)
        Point p = to_visit.front();
        to_visit.pop_front();
        std::cout << "(" << p.x << ", " << p.y << ")\n";
        // work with the point.
        // 1. First check if point is visited or a wall.
        if (ary[p.x][p.y] == 2) { continue; }
        if (ary[p.x][p.y] == 1) { continue; }
        if (p.x == ex && p.y == ey) { return p.steps; }
        // Mark the point
        ary[p.x][p.y] = 2;
        // ADD right, down, left, and up.
        if (p.y + 1 < h) {
            to_visit.push_back(Point(p.x, p.y + 1, p.steps + 1));
        }
        if (p.x + 1 < w) {
            to_visit.push_back(Point(p.x + 1, p.y, p.steps + 1));
        }
        if (p.y - 1 >= 0) {
            to_visit.push_back(Point(p.x, p.y - 1, p.steps + 1));
        }
        if (p.x - 1 >= 0) {
            to_visit.push_back(Point(p.x - 1, p.y, p.steps + 1));
        }
    }

    return -1;
}
