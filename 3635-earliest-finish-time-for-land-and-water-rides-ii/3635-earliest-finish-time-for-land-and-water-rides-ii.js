const MAX = 300005;
const earliestFinishTime = (la, lb, wa, wb) => {
    let l = MAX, w = MAX, minL = MAX, minW = MAX;
    let n = la.length, m = wa.length;

    for (let i = 0; i < n; i++)
        l = Math.min(l, la[i] + lb[i]);

    for (let i = 0; i < m; i++) {
        w = Math.min(w, wa[i] + wb[i]);
        minL = Math.min(minL, Math.max(wa[i], l) + wb[i]);
    }

    for (let i = 0; i < n; i++)
        minW = Math.min(minW, Math.max(la[i], w) + lb[i]);

    return Math.min(minW, minL);
};