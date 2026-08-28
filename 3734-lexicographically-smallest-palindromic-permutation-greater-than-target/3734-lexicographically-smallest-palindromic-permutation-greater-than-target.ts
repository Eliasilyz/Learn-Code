function lexPalindromicPermutation(s: string, target: string): string {
    const n = s.length;
    const counts = new Array(26).fill(0);
    for (const ch of s) counts[ch.charCodeAt(0) - 97]++;

    let oddCount = 0;
    let oddChar = -1;
    for (let c = 0; c < 26; c++) {
        if (counts[c] % 2 === 1) { oddCount++; oddChar = c; }
    }
    if (n % 2 === 0) {
        if (oddCount !== 0) return "";
    } else {
        if (oddCount !== 1) return "";
    }

    const half = Math.floor(n / 2);
    const hasMid = n % 2 === 1;
    const midChar = hasMid ? String.fromCharCode(97 + oddChar) : "";

    const pMultiset = new Array(26).fill(0);
    for (let c = 0; c < 26; c++) pMultiset[c] = Math.floor(counts[c] / 2);

    const A = target.slice(0, half);

    function buildSorted(cnt: number[]): string {
        let res = "";
        for (let c = 0; c < 26; c++) {
            if (cnt[c] > 0) res += String.fromCharCode(97 + c).repeat(cnt[c]);
        }
        return res;
    }

    // prefixFreq[i] = frequency counts of A[0..i-1]
    const prefixFreq: number[][] = [];
    {
        const cur = new Array(26).fill(0);
        prefixFreq.push(cur.slice());
        for (let i = 0; i < half; i++) {
            cur[A.charCodeAt(i) - 97]++;
            prefixFreq.push(cur.slice());
        }
    }

    for (let i = half; i >= 0; i--) {
        const needed = prefixFreq[i];
        let ok = true;
        for (let c = 0; c < 26; c++) {
            if (needed[c] > pMultiset[c]) { ok = false; break; }
        }
        if (!ok) continue;

        if (i === half) {
            const revA = A.split('').reverse().join('');
            const candidate = A + midChar + revA;
            if (candidate > target) return candidate;
            // else fall through to try smaller i
        } else {
            const remaining = new Array(26);
            for (let c = 0; c < 26; c++) remaining[c] = pMultiset[c] - needed[c];
            const targetCharCode = A.charCodeAt(i) - 97;
            let chosen = -1;
            for (let c = targetCharCode + 1; c < 26; c++) {
                if (remaining[c] > 0) { chosen = c; break; }
            }
            if (chosen === -1) continue;
            remaining[chosen]--;
            const P = A.slice(0, i) + String.fromCharCode(97 + chosen) + buildSorted(remaining);
            const revP = P.split('').reverse().join('');
            const T = P + midChar + revP;
            return T;
        }
    }

    return "";
}