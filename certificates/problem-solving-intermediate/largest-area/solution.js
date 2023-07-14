class Node {
    constructor(l, r) {
        this.l = l;
        this.r = r;
        this.lc = null;
        this.rc = null;
        this.val = r - l;
    }

    split(x) {

        if (x == this.l || x == this.r) {
            return;
        }

        if (this.lc) {
            if (x < this.lc.r) {
                this.lc.split(x);
            } else {
                this.rc.split(x);
            }
            this.val = Math.max(this.lc.val, this.rc.val);
        } else {
            this.lc = new Node(this.l, x);
            this.rc = new Node(x, this.r);
            this.val = Math.max(x - this.l, this.r - x);
        }
    }
}

function getMaxArea(w, h, isVertical, distance) {
    const w_root = new Node(0, w);
    const h_root = new Node(0, h);
    const ans = [];
    for (let i = 0; i < isVertical.length; i++) {
        const d = distance[i];
        if (isVertical[i]) {
            w_root.split(d);
        } else {
            h_root.split(d);
        }
        ans.push(w_root.val * h_root.val);
    }
    return ans;
}