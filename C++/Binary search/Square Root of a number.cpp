int floorSqrt(int n) {
    int start = 0, end = n;
    int mid = 0;

    while (start <= end) {
        mid = (start + end) / 2;

        if ((mid * mid) == n) {
            return mid;
        } else if ((mid * mid) < n) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    // If the loop exits without finding the exact square root,
    // return the floor value of the last mid.
    return end;
}
