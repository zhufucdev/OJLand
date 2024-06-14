#include <iostream>
#include <queue>

using namespace std;
int v[100][100];

class Point {
public:
    int x, y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

queue<Point> myqueue;

int least_instructions(int x, int y, int X, int Y, int N, int M) {
    int move[4][2] = {{1,  0},
                      {-1, 0},
                      {0,  1},
                      {0,  -1}};


    myqueue.emplace(x, y);
    v[x][y] = -1;
    int length = 0;

    while (!myqueue.empty()) {
        auto size = myqueue.size();
        for (int i = 0; i < size; i++) {
            Point front = myqueue.front();
            myqueue.pop();

            if (front.x == X && front.y == Y) {
                return length;
            }

            for (auto &j: move) {
                int newX = front.x + j[0];
                int newY = front.y + j[1];

                if (newX > 0 && newX <= N && newY > 0 && newY <= M && v[newX][newY] == 0) {
                    myqueue.emplace(newX, newY);
                    v[newX][newY] = -1;
                }
            }
        }
        length++;
    }

    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> v[i][j];
        }
    }
    int x, y, X, Y;
    cin >> x >> y >> X >> Y;
    int len = least_instructions(x, y, X, Y, N, M);
    cout << len;
}