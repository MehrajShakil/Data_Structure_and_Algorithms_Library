// Digit DP
// Count how many numbers are there between A and B inclusive which sum of digits is equal to S
#define BIT_LENGTH_32 32
#define BIT_LENGTH_64 64
#define MAX_SUM 200

i64 dp[BIT_LENGTH_64][MAX_SUM];
bool visited[BIT_LENGTH_64][MAX_SUM];
i64 A, B;
int S;

i64 solveUtil(int depth, int sum) {
    if(depth == 0) {
        return (i64) (sum == 0);
    }
    if(visited[depth][sum]) {
        return dp[depth][sum];
    }
    visited[depth][sum] = true;

    i64 ret = 0LL;
    for(int i = 0; i <= 9; ++i) {
        if(sum - i >= 0) {
            ret += solveUtil(depth - 1, sum - i);
        }
    }
    return dp[depth][sum] = ret;
}

i64 solve(i64 N) {
    char buffer[BIT_LENGTH_64];
    sprintf(buffer, LLD, N);
    int len = strlen(buffer);
    int sum = S;
    int depth = len;
    i64 ret = 0LL;
    for(int i = 0; i < len; ++i) {
        int digit = buffer[i] - '0';
        for(int d = 0; d < digit; ++d) {
            if(sum - d >= 0) {
                ret += solveUtil(depth - 1, sum - d);
            }
        }
        depth--;
        sum -= digit;
    }
    return ret;
}

// solve(B  + 1) - solve(A);

