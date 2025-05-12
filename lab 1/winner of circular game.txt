int findTheWinner(int n, int k) {
    int* circle = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        circle[i] = i + 1;
    }
    int cur_ind = 0;
    int size = n;

    while (size > 1) {
        int next_to_remove = (cur_ind + k - 1) % size;
        for (int i = next_to_remove; i < size - 1; ++i) {
            circle[i] = circle[i + 1];
        }
        size--;
        cur_ind = next_to_remove;
    }

    int winner = circle[0];
    free(circle);
    return winner;
}