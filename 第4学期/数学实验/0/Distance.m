function D = Distance(citys)

n = size(citys, 1);
D = zeros(n, n);
for i = 1: n
    for j = i + 1: n  %第i个城市与其后的其他城市之间的距离，会形成一个上半角矩阵。
            D(i, j) = sqrt((citys(i, 1) - citys(j, 1))^2 + (citys(i, 2) - citys(j, 2))^2);
            D(j, i) = D(i, j);
    end
    D(i, i) = 1e-4;       %对角线的值为0，但由于后面的启发因子要取倒数，因此用一个很小数代替0
end
end