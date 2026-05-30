/**
 * @param {number[][]} queries
 * @return {boolean[]}
 */
var getResults = function(queries) {
    let max_x = 0;
    for (let i = 0; i < queries.length; i++) {
        if (queries[i][1] > max_x) {
            max_x = queries[i][1];
        }
    }
    
    const MAX = max_x + 5;
    
    // Using TypedArrays for better performance and memory management
    const max_gap = new Int32Array(4 * MAX);
    const max_obs = new Int32Array(4 * MAX).fill(-1);
    const min_obs = new Int32Array(4 * MAX).fill(MAX + 1);
    
    function update(node, l, r, idx, gap, is_obs) {
        if (l === r) {
            if (is_obs) {
                max_gap[node] = gap;
                max_obs[node] = idx;
                min_obs[node] = idx;
            } else {
                max_gap[node] = 0;
                max_obs[node] = -1;
                min_obs[node] = MAX + 1;
            }
            return;
        }
        const mid = (l + r) >> 1;
        if (idx <= mid) {
            update(node * 2, l, mid, idx, gap, is_obs);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, gap, is_obs);
        }
        
        max_gap[node] = Math.max(max_gap[node * 2], max_gap[node * 2 + 1]);
        max_obs[node] = Math.max(max_obs[node * 2], max_obs[node * 2 + 1]);
        min_obs[node] = Math.min(min_obs[node * 2], min_obs[node * 2 + 1]);
    }
    
    function query_max_obs(node, l, r, ql, qr) {
        if (ql > r || qr < l) return -1;
        if (ql <= l && r <= qr) return max_obs[node];
        const mid = (l + r) >> 1;
        return Math.max(
            query_max_obs(node * 2, l, mid, ql, qr),
            query_max_obs(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }
    
    function query_min_obs(node, l, r, ql, qr) {
        if (ql > r || qr < l) return MAX + 1;
        if (ql <= l && r <= qr) return min_obs[node];
        const mid = (l + r) >> 1;
        return Math.min(
            query_min_obs(node * 2, l, mid, ql, qr),
            query_min_obs(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }
    
    function query_max_gap(node, l, r, ql, qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return max_gap[node];
        const mid = (l + r) >> 1;
        return Math.max(
            query_max_gap(node * 2, l, mid, ql, qr),
            query_max_gap(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }
    
    // Initial obstacle at origin
    update(1, 0, MAX, 0, 0, true);
    
    const results = [];
    
    for (let i = 0; i < queries.length; i++) {
        const q = queries[i];
        
        if (q[0] === 1) { 
            const x = q[1];
            const prev = query_max_obs(1, 0, MAX, 0, x);
            const next = query_min_obs(1, 0, MAX, x + 1, MAX);
            
            update(1, 0, MAX, x, x - prev, true);
            
            if (next <= MAX) {
                update(1, 0, MAX, next, next - x, true);
            }
        } else {
            const x = q[1];
            const sz = q[2];
            const prev = query_max_obs(1, 0, MAX, 0, x);
            
            const mx_gap = query_max_gap(1, 0, MAX, 0, prev);
            const edge_gap = x - prev;
            
            if (mx_gap >= sz || edge_gap >= sz) {
                results.push(true);
            } else {
                results.push(false);
            }
        }
    }
    
    return results;
};