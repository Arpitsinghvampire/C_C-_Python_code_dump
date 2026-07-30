// path_with_minimum_effort.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;

// Returns all valid neighbours (up, down, left, right)
vector<pair<int, int>> get_neighbours(vector<vector<int>> &height_matrix,
                                      pair<int, int> current_node)
{
    vector<pair<int, int>> result;

    int current_x = current_node.first;
    int current_y = current_node.second;

    if (current_x - 1 >= 0)
        result.push_back({current_x - 1, current_y});

    if (current_x + 1 < height_matrix.size())
        result.push_back({current_x + 1, current_y});

    if (current_y - 1 >= 0)
        result.push_back({current_x, current_y - 1});

    if (current_y + 1 < height_matrix[0].size())
        result.push_back({current_x, current_y + 1});

    return result;
}

int min_path(vector<vector<int>> &height_matrix)
{
    int rows = height_matrix.size();
    int cols = height_matrix[0].size();

    vector<vector<int>> path_length(rows, vector<int>(cols, INT_MAX));
    path_length[0][0] = 0;

    // {effort, {row, col}}
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>
        pq;

    pq.push({0, {0, 0}});

    while (!pq.empty())
    {
        auto front = pq.top();
        pq.pop();

        int current_effort = front.first;
        int current_x = front.second.first;
        int current_y = front.second.second;

        // Ignore outdated entries
        if (current_effort > path_length[current_x][current_y])
            continue;

        // Destination reached
        if (current_x == rows - 1 && current_y == cols - 1)
            return current_effort;

        vector<pair<int, int>> neighbours =
            get_neighbours(height_matrix, {current_x, current_y});

        for (auto neighbour : neighbours)
        {
            int neighb_x = neighbour.first;
            int neighb_y = neighbour.second;

            int edgeEffort = abs(
                height_matrix[neighb_x][neighb_y] -
                height_matrix[current_x][current_y]);

            int newEffort = max(current_effort, edgeEffort);

            if (newEffort < path_length[neighb_x][neighb_y])
            {
                path_length[neighb_x][neighb_y] = newEffort;
                pq.push({newEffort, {neighb_x, neighb_y}});
            }
        }
    }

    return path_length[rows - 1][cols - 1];
}

int main()
{
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    cout << "Minimum Effort = " << min_path(heights) << endl;

    return 0;
}