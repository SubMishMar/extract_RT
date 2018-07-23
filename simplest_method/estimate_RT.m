clear
clc

theta = 0:0.01:2*pi;
a = 5;
b = 5;
Xi = a*cos(theta);
Yi = b*sin(theta);
Zi = zeros(size(Xi));
XYZi = [Xi; Yi; Zi; ones(size(Xi))]; % q
figure(1)
plot3(XYZi(1, :), XYZi(2, :), XYZi(3, :));
hold on;
R = rotnx(75)*rotny(45)*rotnz(45);
T = [2; 3; -1];

XYZi = XYZi + 0.1*[randn(3, size(XYZi, 2));zeros(1, size(XYZi, 2))];
disp('Actual Transformation');
Trans = [R T; 0 0 0 1]
XYZj = Trans*XYZi; 

plot3(XYZj(1, :), XYZj(2, :), XYZj(3, :));
hold off;
grid;
axis equal

meanXYZi = mean(XYZi, 2);
meanXYZj = mean(XYZj, 2);

meanRemovedXYZi = XYZi(1:3, :) - meanXYZi(1:3, :);
meanRemovedXYZj = XYZj(1:3, :) - meanXYZj(1:3, :);

S = meanRemovedXYZi*meanRemovedXYZj';

[U, D, V] = svd(S);

midMat = diag(ones(1, size(V, 2)));
midMat(end, end) = det(V*U');

R = V*midMat*U';

t = meanXYZj(1:3,:) - R*meanXYZi(1:3, :);
disp('Estimated Transformation');
Trans_est = [R, t; 0 0 0 1]

disp('Product of Actual and inverse of Estimated Transformation');
product = Trans*inv(Trans_est)

