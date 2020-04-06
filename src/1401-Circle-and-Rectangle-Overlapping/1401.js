var checkOverlap = function(r, xc, yc, x1, y1, x2, y2) {
    let x = (x1 + x2) / 2, y = (y1 + y2) / 2;
    let h = [x2 - x, y2 - y];
    let v = [Math.abs(x - xc), Math.abs(y - yc)];
    let u = [Math.max(v[0] - h[0], 0), Math.max(v[1] - h[1], 0)];
    return r * r >= u[0] * u[0] + u[1] * u[1]; 
};