vector<int> Solution::flip(string A) {
    int n = A.size();

    int currSum = 0, maxSum = 0;
    int start = 0;
    int bestL = -1, bestR = -1;

    for (int i = 0; i < n; i++) {
        int val = (A[i] == '0') ? 1 : -1;

        currSum += val;

        if (currSum > maxSum) {
            maxSum = currSum;
            bestL = start;
            bestR = i;
        }

        if (currSum < 0) {
            currSum = 0;
            start = i + 1;
        }
    }

    if (bestL == -1)
        return {};

    return {bestL + 1, bestR + 1};   
}
