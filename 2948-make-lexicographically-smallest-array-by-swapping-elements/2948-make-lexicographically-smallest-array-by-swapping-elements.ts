function lexicographicallySmallestArray(nums: number[], limit: number): number[] {
    const n = nums.length;

    const arr = nums.map((value, index) => [value, index] as [number, number]);
    arr.sort((a, b) => a[0] - b[0]);

    const result = [...nums];

    let start = 0;

    for (let end = 1; end <= n; end++) {
        if (end === n || arr[end][0] - arr[end - 1][0] > limit) {
            const indices = arr
                .slice(start, end)
                .map(x => x[1])
                .sort((a, b) => a - b);

            for (let i = start; i < end; i++) {
                result[indices[i - start]] = arr[i][0];
            }

            start = end;
        }
    }

    return result;
}