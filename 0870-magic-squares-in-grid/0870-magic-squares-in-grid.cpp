class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {

        // brute force
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                int sum = 0;
                bool flag = true;

                // checking distinct elements
                vector<int> freq(10, 0);
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        int num = grid[k][l];
                        if (num < 1 || num > 9 || freq[num] > 0) {
                            flag = false;
                            break;
                        }
                        freq[num]++;
                    }
                    if (!flag)
                        break;
                }
                if (!flag)
                    continue;

                // Calculating the sum
                for (int l = j; l < j + 3; l++) {
                    sum += grid[i][l];
                }

                // Checking rows
                for (int k = i; k < i + 3; k++) {
                    int sum1 = 0;
                    for (int l = j; l < j + 3; l++) {
                        sum1 += grid[k][l];
                    }
                    if (sum1 != sum) {
                        flag = false;
                        break;
                    }
                }

                // Checking columns
                for (int l = j; l < j + 3; l++) {
                    int sum1 = 0;
                    for (int k = i; k < i + 3; k++) {
                        sum1 += grid[k][l];
                    }
                    if (sum1 != sum) {
                        flag = false;
                        break;
                    }
                }

                // Checking first diagonal
                int sum1 = 0;
                for (int k = 0; k < 3; k++) {
                    sum1 += grid[i + k][j + k];
                }
                if (sum1 != sum) {
                    flag = false;
                }

                // Checking second diagonal
                sum1 = 0;
                for (int k = 0; k < 3; k++) {
                    sum1 += grid[i + k][j + 2 - k];
                }
                if (sum1 != sum) {
                    flag = false;
                }

                if (flag)
                    count++;
            }
        }
        return count;
    }
};